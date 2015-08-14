/*
 * purger.c - syslogd implementation for windows, log dir purger
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
#include <windows.h>

#include <glib.h>

#include <syslog.h>
#include <syslogd.h>

static HANDLE purger_semaphore = NULL;

/******************************************************************************
 * recursive_purge
 *
 * auxiliary function for purge_log_dirs
 */
static void recursive_purge( gchar* pathname, LPFILETIME min_time )
{
    gchar *new_pathname;
    HANDLE find_handle;
    WIN32_FIND_DATA find_data;

    TRACE_ENTER( "%s\n", pathname );

    new_pathname = g_build_filename( pathname, "*", NULL );
    find_handle = FindFirstFile( new_pathname, &find_data );
    if( INVALID_HANDLE_VALUE == find_handle )
    {
        TRACE_2( "FindFirstFile(%s) error %lu\n", new_pathname, GetLastError() );
        g_free( new_pathname );
        TRACE_LEAVE( "it seems the path does not exist\n" );
        return;
    }
    g_free( new_pathname );
    do {
        if( (find_data.cFileName[0] == '.' && find_data.cFileName[1] == '\0')
            ||
            (find_data.cFileName[0] == '.'
             && find_data.cFileName[1] == '.' && find_data.cFileName[2] == '\0') )
            continue;

        new_pathname = g_build_filename( pathname, find_data.cFileName, NULL );
        if( find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
        {
            recursive_purge( new_pathname, min_time );
            if( RemoveDirectory( new_pathname ) )
            {
                TRACE( "removed %s\n", new_pathname );
            }
            else
            {
                TRACE( "failed to remove %s\n", new_pathname );
            }
        }
        else
        {
            if( CompareFileTime( min_time, &find_data.ftLastWriteTime ) > 0 )
            {
                if( DeleteFile( new_pathname ) )
                {
                    TRACE( "deleted %s\n", new_pathname );
                }
                else
                {
                    TRACE( "failed to delete %s\n", new_pathname );
                }
            }
        }
        g_free( new_pathname );
    } while( FindNextFile( find_handle, &find_data ) );
    FindClose( find_handle );

    TRACE_LEAVE( "done\n" );
}

/******************************************************************************
 * purge_log_dirs
 */
void purge_log_dirs()
{
    GList *item;

    TRACE_ENTER( "\n" );
    if( WaitForSingleObject( purger_semaphore, 0 ) != WAIT_OBJECT_0 )
    {
        TRACE_LEAVE( "done; another thread is active\n" );
        return;
    }
    for( item = purger_dirs; item; item = item->next )
    {
        struct purger_dir *p = item->data;
        gchar *pathname = make_absolute_log_pathname( p->directory );
        FILETIME min_time;
        long long min_time_64;

        GetSystemTimeAsFileTime( &min_time );
        min_time_64 = (((long long) min_time.dwHighDateTime) << 32) + (long long) min_time.dwLowDateTime;
        min_time_64 -= ((long long) p->keep_days) * ((long long) (24 * 3600)) * (long long) 10000000;
        min_time.dwHighDateTime = min_time_64 >> 32;
        min_time.dwLowDateTime = min_time_64;

        recursive_purge( pathname, &min_time );
        g_free( pathname );
    }
    ReleaseSemaphore( purger_semaphore, 1, NULL );
    TRACE_LEAVE( "done\n" );
}

/******************************************************************************
 * init_purger
 */
gboolean init_purger()
{
    gboolean ret = FALSE;

    TRACE_ENTER( "\n" );

    purger_semaphore = CreateSemaphore( NULL, 1, 1, NULL );
    if( !purger_semaphore )
    {
        ERR( "Cannot create semaphore; error %lu\n", GetLastError() );
        goto done;
    }
    ret = TRUE;

done:
    TRACE_LEAVE( "done; ret=%d\n", ret );
    return ret;
}

/******************************************************************************
 * fini_purger
 */
void fini_purger()
{
    TRACE_ENTER( "\n" );
    if( purger_semaphore ) CloseHandle( purger_semaphore );
    TRACE_LEAVE( "done\n" );
}
