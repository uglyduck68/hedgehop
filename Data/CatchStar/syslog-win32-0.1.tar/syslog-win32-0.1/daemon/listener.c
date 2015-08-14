/*
 * listener.c - syslogd implementation for windows, listener for UDP
 *              and "internal" sources
 *
 * Created by Alexander Yaworsky
 *
 * THIS SOFTWARE IS NOT COPYRIGHTED
 *
 * This source code is offered for use in the public domain. You may
 * use, modify or distribute it freely.
 *
 * This code is distributed in the hope that it will be useful but
 * WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 * DISCLAIMED. This includes but is not limited to warranties of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#include <stdio.h>
#include <winsock2.h>

#include <glib.h>

#include <syslog.h>
#include <syslogd.h>

static SOCKET *socket_array = NULL;
static int socket_count = 0;

static struct source **source_references = NULL;

static HANDLE *event_array = NULL;
static int event_count = 0;

/* message data */
static unsigned max_datagram_size = 1024;
static gchar *datagram_buffer = NULL;
static struct raw_message message;

static CRITICAL_SECTION cs_internal_message;
static HANDLE internal_message_accepted = NULL;
static gchar internal_message_buffer[ 1024 ];

/******************************************************************************
 * init_listener
 *
 * create sockets and synchronization objects including ones for "internal"
 * source
 */
gboolean init_listener()
{
    gboolean ret = FALSE;
    unsigned n;
    GList *item;
    int i;
    struct source *internal_src;

    TRACE_ENTER( "\n" );

    /* create critical section and event for the access serialization to internal message buffer
     */
    InitializeCriticalSection( &cs_internal_message );
    internal_message_accepted = CreateEvent( NULL, FALSE, FALSE, NULL );
    if( !internal_message_accepted )
    {
        ERR( "Cannot create event; error %lu\n", GetLastError() );
        goto done;
    }

    /* allocate memory for sockets and events;
     * the number of sockets is not greater than number of sources
     */
    n = g_list_length( sources );
    socket_array = g_malloc( n * sizeof(SOCKET) );

    /* number of source references is greater by one because of inclusion the event
     * for "internal" source
     * FIXME: how about multiple internal sources?
     */
    source_references = g_malloc( (n + 1) * sizeof(struct source*) );

    /* number of events is greater by two because of inclusion the event
     * for "internal" source and the service_stop_event
     */
    event_array = g_malloc( (n + 2) * sizeof(HANDLE) );

    /* create sockets */
    for( item = sources; item; item = item->next )
    {
        struct source *src = item->data;
        SOCKET sock;
        unsigned dgram_size;
        int size;

        if( src->type == ST_INTERNAL )
        {
            internal_src = src;
            continue;
        }

        if( src->type != ST_UDP )
            continue;

        sock = socket( AF_INET, SOCK_DGRAM, 0 );
        if( INVALID_SOCKET == sock )
        {
            ERR( "socket() error %lu\n", WSAGetLastError() );
            goto done;
        }

        if( bind( sock, (struct sockaddr*) &src->udp, sizeof(src->udp) ) )
        {
            ERR( "bind() error %lu\n", WSAGetLastError() );
            closesocket( sock );
            goto done;
        }

        size = sizeof(dgram_size);
        if( getsockopt( sock, SOL_SOCKET, SO_MAX_MSG_SIZE, (char*) &dgram_size, &size ) )
        {
            ERR( "getsockopt( SO_MAX_MSG_SIZE ) error %lu\n", WSAGetLastError() );
            closesocket( sock );
            goto done;
        }
        TRACE( "datagram size for %d.%d.%d.%d:%d is %u\n",
               src->udp.sin_addr.S_un.S_un_b.s_b1, src->udp.sin_addr.S_un.S_un_b.s_b2,
               src->udp.sin_addr.S_un.S_un_b.s_b3, src->udp.sin_addr.S_un.S_un_b.s_b4,
               ntohs( src->udp.sin_port ), dgram_size );
        if( dgram_size > max_datagram_size )
            max_datagram_size = dgram_size;

        source_references[ socket_count ] = src;
        socket_array[ socket_count++ ] = sock;
    }
    source_references[ socket_count ] = internal_src;

    /* create events;
     * service_stop_event is added to the array
     */
    while( event_count <= socket_count )
    {
        HANDLE evt = CreateEvent( NULL, FALSE, FALSE, NULL );
        if( !evt )
        {
            ERR( "Cannot create event; error %lu\n", GetLastError() );
            goto done;
        }
        event_array[ event_count++ ] = evt;
    }
    event_array[ event_count++ ] = service_stop_event;

    /* bind events to sockets */
    for( i = 0; i < socket_count; i++ )
    {
        if( WSAEventSelect( socket_array[ i ], event_array[ i ], FD_READ ) )
        {
            ERR( "WSAEventSelect() error %lu\n", WSAGetLastError() );
            goto done;
        }
    }

    /* allocate datagram buffer */
    datagram_buffer = g_malloc( max_datagram_size );

    ret = TRUE;

done:
    if( !ret )
        fini_listener();

    TRACE_LEAVE( "done; socket_count=%d, event_count=%d, max_datagram_size=%d, ret=%d\n",
                 socket_count, event_count, max_datagram_size, (int) ret );
    return ret;
}

/******************************************************************************
 * fini_listener
 */
void fini_listener()
{
    int i;

    TRACE_ENTER( "\n" );

    for( i = 0; i < socket_count; i++ )
        closesocket( socket_array[ i ] );
    g_free( socket_array );
    socket_array = NULL;
    socket_count = 0;

    g_free( source_references );
    source_references = NULL;

    /* note that the last event is the service_stop_event
     * and should not be destroyed
     */
    for( i = 0; i < event_count - 1; i++ )
        CloseHandle( event_array[ i ] );
    g_free( event_array );
    event_array = NULL;
    event_count = 0;

    g_free( datagram_buffer );
    datagram_buffer = NULL;

    if( internal_message_accepted )
    {
        CloseHandle( internal_message_accepted );
        internal_message_accepted = NULL;
    }
    DeleteCriticalSection( &cs_internal_message );
    TRACE_LEAVE( "done\n" );
}

/******************************************************************************
 * listener
 *
 * wait for a message; generate mark message;
 * allocates a new raw_message structure and assigns its pointer to *msg
 */
enum listener_status listener( struct raw_message** msg )
{
    enum listener_status ret = LSNR_ERROR;
    DWORD t, w;
    int r;
    int addrlen;

    TRACE_ENTER( "\n" );

    for(;;)
    {
        if( !mark_interval )
            t = INFINITE;
        else
            t = mark_interval * 1000;
        w = WaitForMultipleObjects( event_count, event_array, FALSE, t );
        if( WAIT_TIMEOUT == w )
        {
            /* issue mark message */
            log_internal( LOG_NOTICE, "%s", mark_message );
            continue;
        }
        if( WAIT_FAILED == w )
        {
            ERR( "Wait error %lu\n", GetLastError() );
            goto done;
        }
        if( w >= event_count )
        {
            ERR( "Unknown wait error\n" );
            goto done;
        }
        if( w == event_count - 1 )
        {
            /* shut down */
            ret = LSNR_SHUTDOWN;
            goto done;
        }
        if( w == event_count - 2 )
        {
            /* got "internal" message */
            message.source = source_references[ socket_count ];
            if( !message.source )
            {
                /* internal source is not defined, cannot handle message */
                SetEvent( internal_message_accepted );
                continue;
            }
            message.msg = g_strdup( internal_message_buffer );
            SetEvent( internal_message_accepted );
            memset( &message.sender_addr, 0, sizeof(message.sender_addr) );
            goto alloc_msg;
        }
        /* got UDP message, read it */
        addrlen = sizeof(message.sender_addr);
        r = recvfrom( socket_array[ w ], datagram_buffer, max_datagram_size,
                      0, (struct sockaddr*) &message.sender_addr, &addrlen );
        if( r < 0 )
        {
            ERR( "recvfrom() error %lu\n", WSAGetLastError() );
            goto done;
        }
        if( !r )
            continue;

        message.msg = g_strndup( datagram_buffer, r );
        message.source = source_references[ w ];

    alloc_msg:
        *msg = g_malloc( sizeof(struct raw_message) );
        memcpy( *msg, &message, sizeof(struct raw_message) );

        ret = LSNR_GOT_MESSAGE;
        goto done;
    }

done:
    TRACE_LEAVE( "done; ret=%d\n", (int) ret );
    return ret;
}

/******************************************************************************
 * log_internal
 *
 * generate internal log message
 */
void log_internal( int pri, char* fmt, ... )
{
    va_list args;
    SYSTEMTIME stm;
    int len;
    char *p;

    TRACE_ENTER( "\n" );
    EnterCriticalSection( &cs_internal_message );

    GetLocalTime( &stm );
    len = sprintf( internal_message_buffer, "<%d>%s %2d %02d:%02d:%02d %s syslog: ",
                   LOG_SYSLOG | pri,
                   str_month[ stm.wMonth - 1 ], stm.wDay, stm.wHour, stm.wMinute, stm.wSecond,
                   local_hostname );
    va_start( args, fmt );
    vsnprintf( internal_message_buffer + len, sizeof(internal_message_buffer) - len, fmt, args );
    va_end( args );
    p = strchr( internal_message_buffer, '\n' );
    if( p )
        *p = 0;
    p = strchr( internal_message_buffer, '\r' );
    if( p )
        *p = 0;

    SetEvent( event_array[ event_count - 2 ] );
    LeaveCriticalSection( &cs_internal_message );
    TRACE_LEAVE( "done\n" );
}
