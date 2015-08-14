/*
 * writer.c - syslogd implementation for windows, message writer
 *
 * Created by Alexander Yaworsky
 *
 * Asynchronous i/o is not supported under win9x so we have to use
 * a separate thread for each file.
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
#include <errno.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include <glib.h>

#include <syslog.h>
#include <syslogd.h>

#define WRITER_KEEPALIVE_TIME 10000

struct file_writer
{
    struct destination *destination;
    gchar *file_name;
    struct fifo *message_queue;
    HANDLE fifo_semaphore;
    HANDLE shutdown_event;  /* manual-reset event */
    HANDLE fd;
    struct message *first_msg, *second_msg, *current_msg;
    int coalesce_count;
    time_t max_hold;
};

/* forward declarations */
static unsigned __stdcall writer_thread_proc( void* arg );

/******************************************************************************
 * compare_current_and_first_messages
 *
 * Auxiliary function for coalescer.
 * If messages aren't identical, reset coalescer.
 */
static gboolean compare_current_and_first_messages( struct file_writer* writer )
{
    TRACE_ENTER( "%p\n", writer );

    if( strcmp( writer->current_msg->hostname, writer->first_msg->hostname )
        || strcmp( writer->current_msg->message, writer->first_msg->message ) )
    {
        release_message( writer->first_msg );
        writer->first_msg = NULL;
        TRACE_LEAVE( "%p done; messages aren't identical\n", writer );
        return FALSE;
    }

    TRACE_LEAVE( "%p ok\n" );
    return TRUE;
}

/******************************************************************************
 * init_coalescer
 *
 * Should be called when we've got the first unique message.
 * Save message for subsequent comparsions and set max hold time.
 */
static void init_coalescer( struct file_writer* writer )
{
    writer->first_msg = writer->current_msg;
    reference_message( writer->first_msg );
    writer->max_hold = time(NULL) + hold;
    writer->coalesce_count = 1;
    TRACE_2( "%p max_hold=%ld\n", writer, writer->max_hold );
}

/******************************************************************************
 * coalesce
 *
 * coalesce messages;
 * If there are more than two sequential identical messages then we
 * should write first of them followed by message with the number of
 * subsequent messages.
 *
 * The caller always must process current_msg unless it is set NULL
 * when coalesced;
 * return: TRUE if messages are coalesced; FALSE if flushing is required
 */
static gboolean coalesce( struct file_writer* writer )
{
    time_t current_time;

    TRACE_ENTER( "%p\n", writer );

    switch( writer->coalesce_count )
    {
    case 0:
        /* the first message */
        init_coalescer( writer );
        return TRUE;

    case 1:
        /* the second message */
        TRACE_2( "%p second message\n", writer );
        if( !compare_current_and_first_messages( writer ) )
            return FALSE;
        writer->second_msg = writer->current_msg;
        writer->current_msg = NULL;
        writer->coalesce_count = 2;
        goto check_hold_time;

    case 2:
        /* the third message */
        TRACE_2( "%p third message\n", writer );
        if( !compare_current_and_first_messages( writer ) )
            /* leave the second message; it will be written by flush_coalescer */
            return FALSE;
        release_message( writer->second_msg );
        writer->second_msg = NULL;
        release_message( writer->current_msg );
        writer->current_msg = NULL;
        writer->coalesce_count = 3;
        goto check_hold_time;

    default:
        /* the fourth and subsequent messages */
        TRACE_2( "%p fourth+ message\n", writer );
        if( !compare_current_and_first_messages( writer ) )
            return FALSE;
        release_message( writer->current_msg );
        writer->current_msg = NULL;
        writer->coalesce_count++;
        TRACE_2( "%p coalesce_count=%d\n", writer, writer->coalesce_count );
        goto check_hold_time;
    }

check_hold_time:
    current_time = time(NULL);
    TRACE_2( "%p current_time=%ld\n", writer, current_time );
    if( writer->max_hold < current_time )
    {
        TRACE_LEAVE( "%p done; elapsed hold time\n", writer );
        return FALSE;
    }
    TRACE_LEAVE( "%p done\n", writer );
    return TRUE;
}

/******************************************************************************
 * write_message_to_logfile
 */
static void write_message_to_logfile( struct file_writer* writer, struct message** msg )
{
    gchar *buffer;
    DWORD written;

    if( INVALID_HANDLE_VALUE == writer->fd )
        return;
    TRACE_2( "%p: %s\n", writer, (*msg)->message );
    buffer = g_strconcat( (*msg)->timestamp, " ", (*msg)->hostname, " ", (*msg)->message, "\n", NULL );
    WriteFile( writer->fd, buffer, strlen( buffer ), &written, NULL );
    g_free( buffer );
    release_message( *msg );
    *msg = NULL;
}

/******************************************************************************
 * flush_coalescer
 */
static void flush_coalescer( struct file_writer* writer )
{
    if( writer->second_msg )
    {
        write_message_to_logfile( writer, &writer->second_msg );
        TRACE_2( "%p written second message\n", writer );
    }

    if( writer->coalesce_count > 2 )
    {
        SYSTEMTIME stm;
        char buffer[ 1024 ];
        int size;
        DWORD written;

        GetLocalTime( &stm );

        /* make informational message */
        size = snprintf( buffer, sizeof(buffer),
                         "%s %2d %02d:%02d:%02d %s syslog: last message repeated %d times\n",
                         str_month[ stm.wMonth - 1 ], stm.wDay, stm.wHour, stm.wMinute, stm.wSecond,
                         local_hostname,
                         writer->coalesce_count - 1 );
        WriteFile( writer->fd, buffer, size, &written, NULL );
        TRACE_2( "%p made informational message\n", writer );
    }

    writer->coalesce_count = 0;
    if( writer->first_msg )
    {
        release_message( writer->first_msg );
        writer->first_msg = NULL;
    }
    if( writer->current_msg )
    {
        /* we just got the first message and should initialize coalescer */
        init_coalescer( writer );
        write_message_to_logfile( writer, &writer->current_msg );
        TRACE_2( "%p written current message\n", writer );
    }
}

/******************************************************************************
 * destroy_file_writer
 */
static void destroy_file_writer( struct file_writer* writer )
{
    TRACE_ENTER( "%p\n", writer );
    if( writer->fifo_semaphore ) CloseHandle( writer->fifo_semaphore );
    if( writer->shutdown_event ) CloseHandle( writer->shutdown_event );
    fifo_destroy( writer->message_queue );
    g_free( writer->file_name );
    g_free( writer );
    TRACE_LEAVE( "done\n" );
}

/******************************************************************************
 * create_file_writer
 */
static struct file_writer* create_file_writer( gchar* file_name )
{
    struct file_writer *ret;
    unsigned writer_thread_id;
    HANDLE *writer_thread;

    TRACE_ENTER( "file_name=%s\n", file_name );
    ret = g_malloc0( sizeof(struct file_writer) );
    ret->file_name = g_strdup( file_name );
    ret->message_queue = fifo_create();
    ret->fifo_semaphore = CreateSemaphore( NULL, 0, LONG_MAX, NULL );
    if( !ret->fifo_semaphore )
    {
        ERR( "Cannot create semaphore; error %lu\n", GetLastError() );
        goto error;
    }
    ret->shutdown_event = CreateEvent( NULL, TRUE, FALSE, NULL );
    if( !ret->shutdown_event )
    {
        ERR( "Cannot create event; error %lu\n", GetLastError() );
        goto error;
    }
    writer_thread = (HANDLE) _beginthreadex( NULL, 0, writer_thread_proc, ret,
                                             0, &writer_thread_id );
    if( !writer_thread )
    {
        ERR( "Cannot create thread; error %lu\n", GetLastError() );
        goto error;
    }
    CloseHandle( writer_thread );
    TRACE_LEAVE( "done; ret=%p\n", ret );
    return ret;

error:
    destroy_file_writer( ret );
    TRACE_LEAVE( "error\n" );
    return NULL;
}

/******************************************************************************
 * detach_writer_from_destination
 */
static void detach_writer_from_destination( struct file_writer* writer )
{
    TRACE_ENTER( "%p\n", writer );
    if( !writer->destination )
    {
        TRACE_LEAVE( "done; already detached\n" );
        return;
    }
    EnterCriticalSection( &writer->destination->cs_file_writers );
    writer->destination->file_writers = g_list_remove( writer->destination->file_writers, writer );
    LeaveCriticalSection( &writer->destination->cs_file_writers );
    writer->destination = NULL;
    TRACE_LEAVE( "done\n" );
}

/******************************************************************************
 * writer_thread_proc
 *
 * Open file, extract messages from queue and write them to file.
 * If queue is empty long enough, close file and destroy itself.
 */
static unsigned __stdcall writer_thread_proc( void* arg )
{
    struct file_writer *writer = arg;
    HANDLE wait_objects[2] = { writer->fifo_semaphore, writer->shutdown_event };
    gchar *pathname;
 
    TRACE_ENTER( "writer=%p\n", writer );

    pathname = make_absolute_log_pathname( writer->file_name );
    create_directories( pathname );

    rotate_logfile( pathname, writer->destination );

    writer->fd = CreateFile( pathname, GENERIC_WRITE, FILE_SHARE_READ, NULL,
                             OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );
    if( INVALID_HANDLE_VALUE == writer->fd )
    {
        ERR( "CreateFile(%s) error %lu\n", pathname, GetLastError() );
        g_free( pathname );
        goto done;
    }

    /* there's a strange bug or feature in windows: if there was a file with the same
       name in the directory, a new file will inherit its creation time;
       because of this logs will be rotated each time;
       here is a workaround:
     */
    if( GetLastError() != ERROR_ALREADY_EXISTS )
    {
        FILETIME systime;
        GetSystemTimeAsFileTime( &systime );
        if( !SetFileTime( writer->fd, &systime, &systime, &systime ) )
            ERR( "SetFileTime error %lu\n", GetLastError() );
    }

    g_free( pathname );
    SetFilePointer( writer->fd, 0, NULL, FILE_END );

    for(;;)
    {
        DWORD w = WaitForMultipleObjects( 2, wait_objects, FALSE, WRITER_KEEPALIVE_TIME );
        if( WAIT_TIMEOUT == w )
        {
            /* prepare to suicide; at this point a new message may be put into queue;
               detach writer from destination and continue to write any pending messages */
            detach_writer_from_destination( writer );
            /* from now no new messages will be put into queue */
            SetEvent( writer->shutdown_event );
        }

        writer->current_msg = fifo_pop( writer->message_queue );
        if( !writer->current_msg )
        {
            /* shutdown */
            goto done;
        }

        if( coalesce( writer ) )
        {
            if( writer->current_msg )
            {
                write_message_to_logfile( writer, &writer->current_msg );
                TRACE_2( "%p written current message\n", writer );
            }
        }
        else
        {
            flush_coalescer( writer );
        }
    }
done:
    detach_writer_from_destination( writer );
    flush_coalescer( writer );
    if( writer->fd != INVALID_HANDLE_VALUE ) CloseHandle( writer->fd );
    destroy_file_writer( writer );

    purge_log_dirs();

    TRACE_LEAVE( "done\n" );
    return 0;
}

/******************************************************************************
 * make_file_name
 *
 * expand filename pattern (message->file)
 */
static void make_file_name( char* pattern, struct message* message, char* buffer )
{
    char *dest = buffer;
    SYSTEMTIME stm;

    GetLocalTime( &stm );
    for(;;)
    {
        char c = *pattern++;
        if( c != '%' )
        {
            *dest++ = c;
            if( '\0' == c )
                break;
            continue;
        }
        c = *pattern++;
        switch( c )
        {
        case 'Y': dest += sprintf( dest, "%u", stm.wYear ); break;
        case 'M': dest += sprintf( dest, "%02u", stm.wMonth ); break;
        case 'm': dest += sprintf( dest, "%u", stm.wMonth ); break;
        case 'D': dest += sprintf( dest, "%02u", stm.wDay ); break;
        case 'd': dest += sprintf( dest, "%u", stm.wDay ); break;
        case 'W': dest += sprintf( dest, "%u", stm.wDayOfWeek + 1 ); break;
        case 'F': dest += sprintf( dest, "%s", get_facility_name( message->facility ) ); break;
        case 'f': dest += sprintf( dest, "%d", message->facility ); break;
        case 'L': dest += sprintf( dest, "%s", get_priority_name( message->priority ) ); break;
        case 'l': dest += sprintf( dest, "%d", message->priority ); break;
        case 'H': dest += sprintf( dest, "%s", message->hostname ); break;
        case 'h': dest += sprintf( dest, "%s", message->sender ); break;
        case 'P': dest += sprintf( dest, "%s", message->program ); break;
        default: *dest++ = c; break;
        }
    }
    strlwr( buffer );
}

/******************************************************************************
 * write_message
 */
void write_message( struct message* msg, struct destination* destination )
{
    char file_name[ MAX_PATH ];
    GList *item;
    struct file_writer *writer;

    TRACE_ENTER( "msg=%p, destination=%s\n", msg, destination->name );
    make_file_name( destination->file, msg, file_name );
    EnterCriticalSection( &destination->cs_file_writers );
    /* find existing writer */
    for( writer = NULL, item = destination->file_writers; item; item = item->next )
        if( strcmp( ((struct file_writer*) (item->data))->file_name, file_name ) == 0 )
        {
            writer = item->data;
            break;
        }
    if( !writer )
    {
        /* create new writer */
        writer = create_file_writer( file_name );
        if( !writer )
            goto done;
        /* add writer to destination */
        destination->file_writers = g_list_append( destination->file_writers, writer );
        writer->destination = destination;
    }
    /* put message into queue */
    reference_message( msg );
    fifo_push( writer->message_queue, msg );
    ReleaseSemaphore( writer->fifo_semaphore, 1, NULL );

done:
    LeaveCriticalSection( &destination->cs_file_writers );
    TRACE_LEAVE( "done\n" );
}

/******************************************************************************
 * fini_writer
 */
void fini_writer()
{
    GList *dest_item;

    TRACE_ENTER( "\n" );
    /* setting shutdown event */
    for( dest_item = destinations; dest_item; dest_item = dest_item->next )
    {
        struct destination *destination = dest_item->data;
        GList *wr_item;

        EnterCriticalSection( &destination->cs_file_writers );
        for( wr_item = destination->file_writers; wr_item; wr_item = wr_item->next )
        {
            struct file_writer *writer = wr_item->data;
            SetEvent( writer->shutdown_event );
        }
        LeaveCriticalSection( &destination->cs_file_writers );
    }
    TRACE_2( "waiting for shutdown\n" );
    for(;;)
    {
        for( dest_item = destinations; dest_item; dest_item = dest_item->next )
            if( ((struct destination*) (dest_item->data))->file_writers )
                break;
        if( !dest_item )
            break;
        Sleep( 60 );
    }
    TRACE_LEAVE( "done\n" );
}
