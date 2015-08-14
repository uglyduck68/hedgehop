/*
 * logrotate.c - syslogd implementation for windows, log rotation
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

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <sys/stat.h>

#include <glib.h>

#include <syslog.h>
#include <syslogd.h>

/******************************************************************************
 * expand_options
 *
 * Substitute $PATHNAME and $FILENAME
 */
static gchar* expand_options( const gchar* compressoptions, const gchar* pathname )
{
    gchar *filename = g_path_get_basename( pathname );
    GString *str = g_string_new( compressoptions );
    gchar *substr_pathname;
    gchar *substr_filename;

    TRACE_ENTER( "\n" );
    do {
        substr_pathname = strstr( str->str, "$PATHNAME" );
        substr_filename = strstr( str->str, "$FILENAME" );

        if( substr_pathname )
        {
            int pos = substr_pathname - str->str;
            g_string_erase( str, pos, 9 );
            g_string_insert( str, pos, pathname );
        }

        if( substr_filename )
        {
            int pos = substr_filename - str->str;
            g_string_erase( str, pos, 9 );
            g_string_insert( str, pos, filename );
        }
    } while( substr_pathname || substr_filename );
    g_free( filename );
    TRACE_LEAVE( "return %s\n", str->str );
    return g_string_free( str, FALSE );
}

/******************************************************************************
 * compress_backlog
 *
 * Run external compression program.
 * Return TRUE if all right.
 */
static gboolean compress_backlog( const gchar* compresscmd, const gchar* compressoptions,
                                  const gchar* backlog )
{
    gboolean ret = FALSE;
    char command_pathname[ MAX_PATH ];
    LPTSTR command_filename;
    gchar *options;
    gchar *command_line;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD exit_code;

    TRACE_ENTER( "\n" );

    if( !SearchPath( NULL, compresscmd, ".exe",
                     sizeof(command_pathname), command_pathname, &command_filename ) )
    {
        ERR( "Command %s not found\n", compresscmd );
        TRACE_LEAVE( "error\n" );
        return FALSE;
    }

    options = expand_options( compressoptions, backlog );
    command_line = g_strconcat( command_pathname, " ", options, NULL );

    memset( &si, 0, sizeof(si ) );
    si.cb = sizeof(si);
    TRACE_2( "command_line=%s\n", command_line );
    if( !CreateProcess( NULL, command_line, NULL, NULL, FALSE,
                        DETACHED_PROCESS, NULL, NULL, &si, &pi ) )
        ERR( "Cannot create process %s; error %lu\n", command_line, GetLastError() );
    else
    {
        CloseHandle( pi.hThread );
        TRACE_2( "waiting for %s\n", command_line );
        WaitForSingleObject( pi.hProcess, INFINITE );
        if( !GetExitCodeProcess( pi.hProcess, &exit_code ) )
            exit_code = 1;
        CloseHandle( pi.hProcess );
        ret = 0 == exit_code;
    }

    g_free( command_line );
    g_free( options );

    TRACE_LEAVE( "ret=%d\n", ret );
    return ret;
}

/******************************************************************************
 * do_rotate
 *
 * All criteria for rotation are met, just do it.
 */
static void do_rotate( const gchar* pathname, struct destination* destination )
{
    int i;
    gchar *dest_pathname;
    gchar *backlog;

    TRACE_ENTER( "\n" );

    /* construct destination pathname for backlogs */
    if( destination->olddir )
    {
        gchar *filename = g_path_get_basename( pathname );

        if( g_path_is_absolute( destination->olddir ) )
            dest_pathname = g_build_filename( destination->olddir, filename, NULL );
        else
        {
            gchar *prefix = g_path_get_dirname( __argv[0] );
            dest_pathname = g_build_filename( prefix, destination->olddir, filename, NULL );
            g_free( prefix );
        }
        g_free( filename );
    }
    else
        dest_pathname = g_strdup( pathname );

    /* remove earliest backlog */
    backlog = g_strdup_printf( "%s.%d", dest_pathname, destination->backlogs );
    DeleteFile( backlog );
    g_free( backlog );

    /* rotate backlogs */
    for( i = destination->backlogs; i > 1; i-- )
    {
        gchar *old_backlog = g_strdup_printf( "%s.%d", dest_pathname, i - 1 );
        gchar *new_backlog = g_strdup_printf( "%s.%d", dest_pathname, i );
        TRACE_2( "Move %s to %s\n", old_backlog, new_backlog );
        if( !MoveFile( old_backlog, new_backlog ) )
        {
            /* most possible that old backlog file does not exist */
            TRACE_2( "Can't move %s to %s; error %lu\n", old_backlog, new_backlog, GetLastError() );
        }
        g_free( old_backlog );
        g_free( new_backlog );
    }

    backlog = g_strconcat( dest_pathname, ".1", NULL );

    /* move current log */
    TRACE_2( "Move %s to %s\n", pathname, backlog );
    if( !MoveFile( pathname, backlog ) )
        ERR( "Can't move %s to %s; error %lu\n", pathname, backlog, GetLastError() );

    /* compress new backlog */
    if( destination->compresscmd )
    {
        if( compress_backlog( destination->compresscmd, destination->compressoptions, backlog ) )
            /* remove original uncompressed file */
            DeleteFile( backlog );
    }

    g_free( backlog );
    g_free( dest_pathname );

    TRACE_LEAVE( "done\n" );
}

/******************************************************************************
 * rotate_logfile
 */
void rotate_logfile( const gchar* pathname, struct destination* destination )
{
    struct stat fst;
    gboolean rotated = FALSE;
    time_t current_time;
    struct tm *tm;

    TRACE_ENTER( "pathname=%s\n", pathname );

    if( 0 == destination->backlogs
        || (RP_UNDEFINED == destination->rotate && 0 == destination->size) )
    {
        TRACE_LEAVE( "no conditions for rotation\n" );
        return;
    }

    if( stat( pathname, &fst ) )
    {
        /* most possible that file does not exist */
        TRACE_2( "stat(%s) error %s\n", pathname, strerror( errno ) );
        goto done;
    }

    if( destination->size )
    {
        if( fst.st_size > destination->size )
        {
            do_rotate( pathname, destination );
            rotated = TRUE;
            goto done;
        }
        TRACE_2( "checked size: file=%d, max=%d\n", fst.st_size, destination->size );
    }

    current_time = time(NULL);
    tm = gmtime( &current_time );
    TRACE_2( "checking time: creation=%d, modification=%d\n", fst.st_ctime, fst.st_mtime );
    switch( destination->rotate )
    {
    case RP_DAILY:
        if( fst.st_mtime - (fst.st_ctime - fst.st_ctime % (24 * 3600)) > 24 * 3600 )
            break;
        goto done;
    case RP_WEEKLY:
    {
        int current_weekday = tm->tm_wday;
        if( current_weekday < gmtime( &fst.st_ctime )->tm_wday
            || fst.st_mtime - fst.st_ctime > 7 * 24 * 3600 )
            break;
        goto done;
    }
    case RP_MONTHLY:
    {
        int current_month = tm->tm_mon;
        if( current_month != gmtime( &fst.st_ctime )->tm_mon )
            break;
        goto done;
    }
    default:
        goto done;
    }

    if( fst.st_size || destination->ifempty )
    {
        do_rotate( pathname, destination );
        rotated = TRUE;
    }
    else
    {
        TRACE_2( "do not rotate empty file\n" );
    }

done:
    TRACE_LEAVE( "done; %s\n", rotated? "rotated" : "not rotated" );
}
