/*
 * syslogd.c - syslogd implementation for windows
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

#include <ctype.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <winsock2.h>

#include <glib.h>

#include <syslog.h>
#include <syslogd.h>

static struct fifo *raw_message_queue = NULL;
static HANDLE fifo_semaphore = NULL;

/* cache for source hostnames */
struct hostname
{
    struct sockaddr_in addr;
    gchar *host;
    time_t top_age;  /* zero prevents aging */
};
static GList *hostnames = NULL;

#define HOSTNAME_LIFETIME 60 /* seconds */
/* FIXME: is this value correct? maybe we should make it configurable? */

static GIConv conversion_descriptor = (GIConv) -1;

char *str_month[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

/******************************************************************************
 * refrence_message
 *
 * increment reference count
 */
void reference_message( struct message* msg )
{
    TRACE_ENTER( "message=%p\n", msg );
    InterlockedIncrement( &msg->refcount );
}

/******************************************************************************
 * release_message
 *
 * decrement reference count and destroy message structure if it becomes zero
 */
void release_message( struct message* msg )
{
    TRACE_ENTER( "message=%p\n", msg );
    if( InterlockedDecrement( &msg->refcount ) )
    {
        TRACE_LEAVE( "done; still referenced\n" );
        return;
    }
    g_free( msg->sender );
    g_free( msg->timestamp );
    g_free( msg->hostname );
    g_free( msg->program );
    g_free( msg->message );
    g_free( msg );
    TRACE_LEAVE( "done\n" );
}

/******************************************************************************
 * convert_message_encoding
 */
static void convert_message_encoding( struct message* msg )
{
    gchar *converted_msg;

    TRACE_ENTER( "message=%p\n", msg );

    if( conversion_descriptor == (GIConv) -1 )
    {
        TRACE_LEAVE( "nothing to do\n" );
        return;
    }

    converted_msg = g_convert_with_iconv( msg->message, -1,
                                          conversion_descriptor, NULL, NULL, NULL );
    if( !converted_msg )
    {
        TRACE_LEAVE( "conversion error\n" );
        return;
    }

    g_free( msg->message );
    msg->message = converted_msg;

    TRACE_LEAVE( "done; %s\n", msg->message );
}

/******************************************************************************
 * filter_message
 *
 * return: TRUE - accepted message, FALSE - rejected message
 */
static gboolean filter_message( struct message* msg, struct filter* filter )
{
    gboolean ret = FALSE;

    TRACE_ENTER( "message=%p, filter=%s\n", msg, filter? filter->name : "NULL" );

    if( !filter )
        goto passed;

    /* check facility */
    if( !filter->facilities[ msg->facility ] )
        goto done;

    /* check priority */
    if( !filter->priorities[ msg->priority ] )
        goto done;

passed:
    /* message is passed through filter */
    ret = TRUE;

done:
    TRACE_LEAVE( "done; ret=%d\n", ret );
    return ret;
}

/******************************************************************************
 * mux_message
 *
 * filter and multiplex message to destinations;
 * release message
 */
static void mux_message( struct message* msg )
{
    GList *item;

    TRACE_ENTER( "message=%p\n", msg );

    convert_message_encoding( msg );

    for( item = logpaths; item; item = item->next )
    {
        struct logpath *logpath = item->data;

        if( logpath->source != msg->source )
            continue;

        if( !filter_message( msg, logpath->filter ) )
            continue;

        write_message( msg, logpath->destination );
    }

    release_message( msg );

    TRACE_LEAVE( "done\n" );
}

/******************************************************************************
 * get_hostname
 *
 * convert addr to string and return it
 */
static gchar* get_hostname( struct sockaddr_in* addr )
{
    gchar *ret;
    time_t current_time;
    GList *item;
    struct hostname *new_hostname;

    TRACE_ENTER( "%d.%d.%d.%d\n",
                 addr->sin_addr.S_un.S_un_b.s_b1, addr->sin_addr.S_un.S_un_b.s_b2,
                 addr->sin_addr.S_un.S_un_b.s_b3, addr->sin_addr.S_un.S_un_b.s_b4 );

    current_time = time(NULL);

    /* at first, try to find a cached entry */
    item = hostnames;
    while( item )
    {
        struct hostname *h = item->data;
        if( h->top_age && h->top_age < current_time )
        {
            GList *next_item = item->next;

            TRACE_2( "delete old entry %s\n", h->host );
            g_free( h->host );
            g_free( h );
            hostnames = g_list_delete_link( hostnames, item );
            item = next_item;
            continue;
        }
        if( h->addr.sin_addr.S_un.S_addr == addr->sin_addr.S_un.S_addr )
        {
            /* found in cache */
            ret = g_strdup( h->host );
            /* move entry to the beginning of the list */
            item->data = hostnames->data;
            hostnames->data = h;
            TRACE_LEAVE( "done; found cached entry: %s\n", ret );
            return ret;
        }
        item = item->next;
    }
    /* add new entry */
    new_hostname = g_malloc( sizeof(struct hostname) );
    memcpy( &new_hostname->addr, addr, sizeof(struct sockaddr_in) );
    if( use_dns )
    {
        struct hostent *he = gethostbyaddr( (char*) &addr->sin_addr.S_un.S_addr,
                                            sizeof(addr->sin_addr.S_un.S_addr), AF_INET );
        new_hostname->top_age = time(NULL) + HOSTNAME_LIFETIME;
        if( !he )
            goto use_addr;
        new_hostname->host = g_strdup( he->h_name );
    }
    else
    {
        new_hostname->top_age = 0;
use_addr:
        new_hostname->host = g_malloc( 16 );
        sprintf( new_hostname->host, "%d.%d.%d.%d",
                 addr->sin_addr.S_un.S_un_b.s_b1, addr->sin_addr.S_un.S_un_b.s_b2,
                 addr->sin_addr.S_un.S_un_b.s_b3, addr->sin_addr.S_un.S_un_b.s_b4 );
    }
    hostnames = g_list_prepend( hostnames, new_hostname );
    ret = g_strdup( new_hostname->host );
    TRACE_LEAVE( "done; ret=%s\n", ret );
    return ret;
}

/******************************************************************************
 * free_hostnames
 */
static void free_hostnames()
{
    GList *item;
    for( item = hostnames; item; item = item->next )
    {
        struct hostname *h = item->data;
        g_free( h->host );
        g_free( h );
    }
    g_list_free( hostnames );
    hostnames = NULL;
}

/******************************************************************************
 * parse_PRI
 *
 * parse PRI part of message;
 * set facility and priority;
 * return pointer to the next char after PRI
 */
static gchar* parse_PRI( gchar* msg, int* facility, int* priority )
{
    int i, pri;

    TRACE_ENTER( "\n" );

    if( *msg != '<' )
        goto no_pri;

    pri = 0;
    for( i = 1; i < 5; i++ )
    {
        if( msg[ i ] == '>' )
            break;
        if( !isdigit( msg[ i ] ) )
            goto no_pri;
        pri = (pri * 10) + (msg[ i ] - '0');
    }
    if( i == 5 )
        goto no_pri;
    if( i == 1 )
        /* FIXME: is this right? or "<>" is an unidentifiable PRI? */
        goto no_pri;

    msg += i + 1;

    if( pri > LOG_NFACILITIES * 8 + 7 )
    {
        TRACE_2( "Unidentifiable PRI %d\n", pri );
        *facility = LOG_USER;
        *priority = LOG_NOTICE;
    }
    else
    {
        TRACE_2( "PRI=%d\n", pri );
        *facility = LOG_FAC( pri );
        *priority = LOG_PRI( pri );
    }

    TRACE_LEAVE( "done; facility=%d, priority=%d\n", *facility, *priority );
    return msg;

no_pri:
    *facility = LOG_USER;
    *priority = LOG_NOTICE;
    TRACE_LEAVE( "done; message contains no PRI\n" );
    return msg;
}

/******************************************************************************
 * parse_timestamp
 *
 * parse TIMESTAMP part of message;
 * allocate string;
 * return pointer to the next char after TIMESTAMP
 */
static gchar* parse_timestamp( gchar* msg, gchar** timestamp )
{
    int i;
    SYSTEMTIME stm;

    TRACE_ENTER( "\n" );

    for( i = 0; i < 12; i++ )
        if( strncasecmp( msg, str_month[ i ], 3 ) == 0 )
            break;
    if( i == 12 )
        goto no_timestamp;
    stm.wMonth = i + 1;

    if( msg[3] != ' ' )
        goto no_timestamp;

    if( msg[4] != ' ' )
    {
        if( (!isdigit( msg[4] )) || (!isdigit( msg[5] )) )
            goto no_timestamp;
        stm.wDay = (msg[4] - '0') * 10 + (msg[5] - '0');
    }
    else
    {
        if( !isdigit( msg[5] ) )
            goto no_timestamp;
        stm.wDay = msg[5] - '0';
    }

    if( msg[6] != ' ' )
        goto no_timestamp;

    if( (!isdigit( msg[7] )) || (!isdigit( msg[8] )) || msg[9] != ':' )
        goto no_timestamp;
    stm.wHour = (msg[7] - '0') * 10 + (msg[8] - '0');

    if( (!isdigit( msg[10] )) || (!isdigit( msg[11] )) || msg[12] != ':' )
        goto no_timestamp;
    stm.wMinute = (msg[10] - '0') * 10 + (msg[11] - '0');

    if( (!isdigit( msg[13] )) || (!isdigit( msg[14] )) || msg[15] != ' ' )
        goto no_timestamp;
    stm.wSecond = (msg[13] - '0') * 10 + (msg[14] - '0');
    msg += 16;
    goto done;

no_timestamp:
    TRACE_2( "no timestamp\n" );
    GetLocalTime( &stm );

done:
    *timestamp = g_strdup_printf( "%s %2d %02d:%02d:%02d",
                                  str_month[ stm.wMonth - 1 ],
                                  stm.wDay, stm.wHour, stm.wMinute, stm.wSecond );
    TRACE_LEAVE( "done\n" );
    return msg;
}

/******************************************************************************
 * parse_raw_message
 *
 * parse raw message and make a new message;
 * destroy raw message
 */
static struct message* parse_raw_message( struct raw_message* raw_msg )
{
    struct message* msg;
    gchar *current_part, *next_part;

    TRACE_ENTER( "raw message=%p\n", raw_msg );

    /* allocate and initialize message structure */
    msg = g_malloc( sizeof(struct message) );
    msg->refcount = 1;
    msg->source = raw_msg->source;

    /* get sender's hostname */
    msg->sender = get_hostname( &raw_msg->sender_addr );

    current_part = raw_msg->msg;
    next_part = parse_PRI( current_part, &msg->facility, &msg->priority );

    current_part = next_part;
    next_part = parse_timestamp( current_part, &msg->timestamp );
    if( next_part == current_part )
    {
        /* no valid timestamp */
        TRACE_2( "no valid timestamp: msg=%s\n", current_part );
        msg->hostname = g_strdup( msg->sender );
        msg->message = g_strdup( current_part );
    }
    else
    {
        /* have valid timestamp, go ahead */
        current_part = next_part;
        while( isalnum( *next_part ) || *next_part == '-' || *next_part == '.' )
            next_part++;
        if( *next_part != ' ' )
        {
            /* invalid hostname */
            msg->hostname = g_strdup( msg->sender );
            msg->message = g_strdup( current_part );
            TRACE_2( "invalid hostname; set sender (%s); msg=%s\n", msg->hostname, msg->message );
        }
        else
        {
            msg->hostname = g_strndup( current_part, next_part - current_part );
            while( *next_part == ' ' && *next_part != 0 )
                next_part++;
            msg->message = g_strdup( next_part );
            TRACE_2( "hostname=%s; msg=%s\n", msg->hostname, msg->message );
        }
    }

    /* try to find program name */
    current_part = msg->message;
    next_part = current_part;
    while( *next_part != ' ' && *next_part != ':' && *next_part != '[' && *next_part != 0 )
        next_part++;
    if( *next_part == ' ' || *next_part == 0 )
        msg->program = g_strdup("");
    else
        msg->program = g_strndup( current_part, next_part - current_part );

    /* destroy raw message */
    g_free( raw_msg->msg );
    g_free( raw_msg );

    TRACE_LEAVE( "done; message=%p\n", msg );
    return msg;
}

/******************************************************************************
 * message_processor
 *
 * main function; extract raw messages from queue and parse them
 */
static unsigned __stdcall message_processor( void* arg )
{
    HANDLE wait_handles[2] = { fifo_semaphore, service_stop_event };

    TRACE_ENTER( "\n" );
    for(;;)
    {
        DWORD w;
        struct raw_message *raw_msg;

        w = WaitForMultipleObjects( 2, wait_handles, FALSE, INFINITE );
        if( WAIT_OBJECT_0 + 1 == w )
            /* shutdown */
            break;
        if( w != WAIT_OBJECT_0 )
        {
            ERR( "WaitForMultipleObjects() error %lu\n", GetLastError() );
            SetEvent( service_stop_event );
            break;
        }
        /* extract raw message from queue */
        raw_msg = fifo_pop( raw_message_queue );

        TRACE_2( "got message %p from queue\n", raw_msg );

        mux_message( parse_raw_message( raw_msg ) );
    }
    TRACE_LEAVE( "done\n" );
    return 0;
}

/******************************************************************************
 * main syslogd function
 *
 * global initialization; invoke listener
 */
void syslogd_main()
{
    HANDLE message_processor_thread = NULL;
    unsigned tid;

    TRACE_ENTER( "\n" );

    SetThreadPriority( GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL );

    if( !read_configuration() )
        goto done;

    if( !init_purger() )
        goto done;

    if( !init_listener() )
        goto done;

    purge_log_dirs();

    if( source_encoding && destination_encoding )
    {
        conversion_descriptor = g_iconv_open( destination_encoding, source_encoding );
        if( conversion_descriptor == (GIConv) -1 )
        {
            ERR( "Cannot convert messages from %s to %s\n",
                 source_encoding, destination_encoding );
        }
    }

    /* create message queue and semaphore;
     * avoid using Glib's asynchronous queues and threading support
     * because synchronization capabilities are very limited;
     */
    raw_message_queue = fifo_create();
    fifo_semaphore = CreateSemaphore( NULL, 0, LONG_MAX, NULL );
    if( !fifo_semaphore )
    {
        ERR( "Cannot create semaphore; error %lu\n", GetLastError() );
        goto done;
    }

    message_processor_thread = (HANDLE) _beginthreadex( NULL, 0, message_processor, NULL, 0, &tid );
    if( !message_processor_thread )
    {
        ERR( "Cannot create thread; error %lu\n", GetLastError() );
        goto done;
    }

    /* get messages from the listener */
    for(;;)
    {
        struct raw_message *raw_msg;

        switch( listener( &raw_msg ) )
        {
        case LSNR_ERROR:
        case LSNR_SHUTDOWN:
            goto done;

        case LSNR_GOT_MESSAGE:
            TRACE_2( "got message from %d.%d.%d.%d; source name %s; ptr=%p: %s\n",
                     raw_msg->sender_addr.sin_addr.S_un.S_un_b.s_b1,
                     raw_msg->sender_addr.sin_addr.S_un.S_un_b.s_b2,
                     raw_msg->sender_addr.sin_addr.S_un.S_un_b.s_b3,
                     raw_msg->sender_addr.sin_addr.S_un.S_un_b.s_b4,
                     raw_msg->source->name, raw_msg, raw_msg->msg );
            /* add raw message to queue */
            fifo_push( raw_message_queue, raw_msg );
            ReleaseSemaphore( fifo_semaphore, 1, NULL );
            break;
        }
    }

done:
    /* signal to all possibly running threads */
    SetEvent( service_stop_event );

    if( message_processor_thread )
    {
        /* wait for message processor shutdown */
        WaitForSingleObject( message_processor_thread, INFINITE );
        CloseHandle( message_processor_thread );
    }

    fini_writer();
    fini_purger();
    free_hostnames();

    if( raw_message_queue ) fifo_destroy( raw_message_queue );
    if( conversion_descriptor != (GIConv) -1 )
        g_iconv_close( conversion_descriptor );

    fini_listener();

    if( fifo_semaphore ) CloseHandle( fifo_semaphore );

    TRACE_LEAVE( "done\n" );
}
