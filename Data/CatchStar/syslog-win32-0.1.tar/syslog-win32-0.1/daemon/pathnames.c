/*
 * pathnames.c - syslogd implementation for windows, miscellaneous functions
 *               operating with file names and paths
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
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include <glib.h>

#include <syslog.h>
#include <syslogd.h>

/******************************************************************************
 * make_absolute_log_pathname
 *
 * Make absolute pathname inside logdir.
 */
gchar* make_absolute_log_pathname( char* path_appendix )
{
    gchar *path, *ret;

    if( logdir && g_path_is_absolute( logdir ) )
        path = g_strdup( logdir );
    else
    {
        gchar *dir = g_path_get_dirname( __argv[0] );
        path = g_build_filename( dir, logdir, NULL );
        g_free( dir );
    }
    ret = g_build_filename( path, path_appendix, NULL );
    g_free( path );
    return ret;
}

/******************************************************************************
 * create_directories
 *
 * Create all the directories in pathname.
 */
void create_directories( gchar* pathname )
{
    gchar *p;
    gchar saved;

    TRACE_ENTER( "%s\n", pathname );
    p = (gchar*) g_path_skip_root( pathname );
    if( !p )
        p = pathname;
    for(;;)
    {
        while( *p != '\0' && *p != '/' && *p != '\\' )
            p++;
        if( *p == '\0' )
            break;
        saved = *p;
        *p = '\0';
        CreateDirectory( pathname, NULL );
        *p++ = saved;
    } 
    TRACE_LEAVE( "done\n" );
}

/******************************************************************************
 * normalize_pathname
 *
 * Remove . and .. from pathname.
 * Pathname should be in UTF-8 encoding.
 * Return NULL if pathname is invalid or normalized pathname
 * in locale encoding.
 */
gchar* normalize_pathname( const gchar* pathname )
{
    gchar *ret = g_locale_from_utf8( pathname, -1, NULL, NULL, NULL );
    gchar *first_element, *current_element, *next_element;

    TRACE_ENTER( "%s\n", ret );

    first_element = (gchar*) g_path_skip_root( ret );
    if( !first_element )
        first_element = ret;

    for( current_element = first_element; *current_element != '\0'; )
    {
        next_element = current_element;
        while( *next_element != '\0' && *next_element != '/' && *next_element != '\\' )
            next_element++;
        if( *next_element != '\0' )
            next_element++;  /* skip separator */

        if( current_element[0] != '.' )
            current_element = next_element;
        else
        {
            if( current_element[1] == '/'
                || current_element[1] == '\\' || current_element[1] == '\0' )
                /* /./ remove current element */
                memmove( current_element, next_element, strlen( next_element ) + 1 );
            else if( current_element[1] == '.'
                     && (current_element[2] == '/'
                         || current_element[2] == '\\' || current_element[2] == '\0') )
            {
                /* /../ find and remove previous element */
                gchar *prev_element = current_element - 2;
                if( prev_element < first_element )
                {
                    ERR( "Invalid pathname: %s\n", pathname );
                    g_free( ret );
                    ret = NULL;
                    break;
                }
                while( prev_element > first_element && *prev_element != '/' && *prev_element != '\\' )
                    prev_element--;
                if( prev_element > first_element )
                    prev_element++;  /* skip separator */
                memmove( prev_element, next_element, strlen( next_element ) + 1 );
                current_element = prev_element;
            }
            else
                current_element = next_element;
        }
    }
    TRACE_LEAVE( "ret=%s\n", ret? ret : "NULL" );
    return ret;
}
