/*
 * conf.c - syslogd implementation for windows, configuration reader
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

/* define SYSLOG_CONF_DIR where syslog.host should be
 */

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#include <glib.h>

#include <syslog.h>
#include <syslogd.h>

#ifndef SYSLOG_CONF_DIR
static char syslog_conf_dir[] = ".";
#else
static char syslog_conf_dir[] = SYSLOG_CONF_DIR;
#endif

/* options and their default values */
gboolean use_dns = TRUE;
gchar *source_encoding = NULL;
gchar *destination_encoding = NULL;
int mark_interval = 0;
gchar *mark_message = "-- MARK --";
int hold = 3;
gchar *logdir = NULL;

/* sources, destinations, filters and logpaths */
struct logpath_names
{
    gchar *source;
    gchar *filter;
    gchar *destination;
};

GList *sources = NULL;
GList *destinations = NULL;
GList *filters = NULL;
GList *logpaths = NULL;

GList *purger_dirs = NULL;

/* Glib markup wrapper data */
static gchar *encoding = NULL;
static gboolean prolog_expected = TRUE;
/* parser data */
static struct filter *current_filter = NULL;

/******************************************************************************
 * xml_start_element
 *
 * parse configuration elements
 */
static void xml_start_element (GMarkupParseContext *context,
                               const gchar         *element_name,
                               const gchar        **attribute_names,
                               const gchar        **attribute_values,
                               gpointer             user_data,
                               GError             **error)
{
    const gchar *aname, *aval;
    int line_number;

    prolog_expected = FALSE;

    g_markup_parse_context_get_position( context, &line_number, NULL );

    /* top-level elements */
    if( strcmp( element_name, "source" ) == 0 )
    {
        struct source *source = g_malloc( sizeof(struct source) );

        source->name = NULL;
        source->type = ST_UNDEFINED;
        memset( &source->udp, 0, sizeof(source->udp) );
        source->udp.sin_family = AF_INET;
        source->udp.sin_port = htons( SYSLOG_PORT );

        for( ; (aname = *attribute_names) != NULL; attribute_names++, attribute_values++ )
        {
            aval = *attribute_values;
            if( strcmp( aname, "name" ) == 0 )
                source->name = g_locale_from_utf8( aval, -1, NULL, NULL, NULL );
            else if( strcmp( aname, "type" ) == 0 )
            {
                if( strcmp( aval, "internal" ) == 0 )
                    source->type = ST_INTERNAL;
                else if( strcmp( aval, "udp" ) == 0 )
                    source->type = ST_UDP;
            }
            else if( strcmp( aname, "interface" ) == 0 )
            {
                struct hostent *he = gethostbyname( aval );
                if( !he )
                {
                    ERR( "Cannot resolve hostname %s; error %lu\n", aval, WSAGetLastError() );
                    g_free( source );
                    return;
                }
                memcpy( &source->udp.sin_addr.s_addr, he->h_addr, he->h_length );
            }
            else if( strcmp( aname, "port" ) == 0 )
                source->udp.sin_port = htons( strtoul( aval, NULL, 0 ) );
        }

        if( !source->name )
            ERR( "Undefined source name at line %d\n", line_number );
        if( ST_UNDEFINED == source->type )
            ERR( "Undefined source type at line %d\n", line_number );
        if( (!source->name) || ST_UNDEFINED == source->type )
        {
            g_free( source );
            return;
        }
        sources = g_list_append( sources, source );
    }
    else if( strcmp( element_name, "destination" ) == 0 )
    {
        struct destination *dest = g_malloc0( sizeof(struct destination) );

        for( ; (aname = *attribute_names) != NULL; attribute_names++, attribute_values++ )
        {
            aval = *attribute_values;
            if( strcmp( aname, "name" ) == 0 )
                dest->name = g_locale_from_utf8( aval, -1, NULL, NULL, NULL );
            else if( strcmp( aname, "file" ) == 0 )
                dest->file = normalize_pathname( aval );
            else if( strcmp( aname, "rotate" ) == 0 )
            {
                if( strcmp( aval, "daily" ) == 0 )
                    dest->rotate = RP_DAILY;
                else if( strcmp( aval, "weekly" ) == 0 )
                    dest->rotate = RP_WEEKLY;
                else if( strcmp( aval, "monthly" ) == 0 )
                    dest->rotate = RP_MONTHLY;
                else
                {
                    ERR( "Invalid rotation period at line %d\n", line_number );
                    dest->rotate = RP_INVALID;
                }
            }
            else if( strcmp( aname, "size" ) == 0 )
            {
                char *endptr;
                dest->size = strtoul( aval, &endptr, 0 );
                if( 'k' == *endptr )
                    dest->size *= 1024;
                else if( 'M' == *endptr )
                    dest->size *= 1024 * 1024;
            }
            else if( strcmp( aname, "backlogs" ) == 0 )
                dest->backlogs = strtoul( aval, NULL, 0 );
            else if( strcmp( aname, "ifempty" ) == 0 )
            {
                if( strcmp( aval, "yes" ) == 0 )
                    dest->ifempty = TRUE;
                else if( strcmp( aval, "no" ) == 0 )
                    dest->ifempty = FALSE;
                else
                {
                    dest->ifempty = TRUE;
                    ERR( "Invalid value \"%s\" of attribute \"%s\" at line %d; assumed \"yes\"\n",
                         aval, aname, line_number );
                }
            }
            else if( strcmp( aname, "olddir" ) == 0 )
                dest->olddir = normalize_pathname( aval );
            else if( strcmp( aname, "compresscmd" ) == 0 )
                dest->compresscmd = g_locale_from_utf8( aval, -1, NULL, NULL, NULL );
            else if( strcmp( aname, "compressoptions" ) == 0 )
                dest->compressoptions = g_locale_from_utf8( aval, -1, NULL, NULL, NULL );
        }
        if( !dest->name )
            ERR( "Undefined destination name at line %d\n", line_number );
        if( !dest->file )
            ERR( "Undefined destination file at line %d\n", line_number );
        if( (!dest->name) || (!dest->file) || RP_INVALID == dest->rotate )
        {
            if( dest->name ) g_free( dest->name );
            if( dest->file ) g_free( dest->file );
            if( dest->olddir ) g_free( dest->olddir );
            if( dest->compresscmd ) g_free( dest->compresscmd );
            if( dest->compressoptions ) g_free( dest->compressoptions );
            g_free( dest );
            return;
        }
        if( dest->compresscmd && !dest->compressoptions )
            dest->compressoptions = g_strdup( "$PATHNAME" );

        dest->file_writers = NULL;
        InitializeCriticalSection( &dest->cs_file_writers );

        destinations = g_list_append( destinations, dest );
    }
    else if( strcmp( element_name, "filter" ) == 0 )
    {
        current_filter = g_malloc0( sizeof(struct filter) );

        for( ; (aname = *attribute_names) != NULL; attribute_names++, attribute_values++ )
        {
            if( strcmp( aname, "name" ) == 0 )
                current_filter->name = g_locale_from_utf8( *attribute_values, -1, NULL, NULL, NULL );
        }
        if( !current_filter->name )
        {
            ERR( "Undefined filter name at line %d\n", line_number );
            g_free( current_filter );
            current_filter = NULL;
            return;
        }
    }
    else if( strcmp( element_name, "logpath" ) == 0 )
    {
        /* at first, fill logpaths list with logpath_names structures
           and replace them later with logpath structures after configuration has been read
         */
        struct logpath_names *logpath = g_malloc0( sizeof(struct logpath_names) );

        for( ; (aname = *attribute_names) != NULL; attribute_names++, attribute_values++ )
        {
            aval = *attribute_values;
            if( strcmp( aname, "source" ) == 0 )
                logpath->source = g_locale_from_utf8( aval, -1, NULL, NULL, NULL );
            else if( strcmp( aname, "filter" ) == 0 )
                logpath->filter = g_locale_from_utf8( aval, -1, NULL, NULL, NULL );
            else if( strcmp( aname, "destination" ) == 0 )
                logpath->destination = g_locale_from_utf8( aval, -1, NULL, NULL, NULL );
        }
        if( !logpath->source )
            ERR( "Undefined log path source at line %d\n", line_number );
        if( !logpath->destination )
            ERR( "Undefined log path destination at line %d\n", line_number );
        if( (!logpath->source) || (!logpath->destination) )
        {
            if( logpath->source ) g_free( logpath->source );
            if( logpath->filter ) g_free( logpath->filter );
            if( logpath->destination ) g_free( logpath->destination );
            g_free( logpath );
            return;
        }
        logpaths = g_list_append( logpaths, logpath );
    }
    else if( strcmp( element_name, "options" ) == 0 )
    {
        for( ; (aname = *attribute_names) != NULL; attribute_names++, attribute_values++ )
        {
            aval = *attribute_values;
            if( strcmp( aname, "dns" ) == 0 )
            {
                if( strcmp( aval, "yes" ) == 0 )
                    use_dns = TRUE;
                else if( strcmp( aval, "no" ) == 0 )
                    use_dns = FALSE;
                else
                    ERR( "Invalid value \"%s\" of attribute \"%s\" at line %d\n", aval, aname, line_number );
            }
            else if( strcmp( aname, "source_encoding" ) == 0 )
                source_encoding = g_strdup( aval );
            else if( strcmp( aname, "destination_encoding" ) == 0 )
                destination_encoding = g_strdup( aval );
            else if( strcmp( aname, "mark_interval" ) == 0 )
                mark_interval = strtoul( aval, NULL, 0 );
            else if( strcmp( aname, "mark_message" ) == 0 )
                mark_message = g_locale_from_utf8( aval, -1, NULL, NULL, NULL );
            else if( strcmp( aname, "hold" ) == 0 )
            {
                hold = strtoul( aval, NULL, 0 );
                if( hold < 1 )
                    hold = 1;
            }
            else if( strcmp( aname, "logdir" ) == 0 )
                logdir = normalize_pathname( aval );
        }
    }
    else if( strcmp( element_name, "purge" ) == 0 )
    {
        struct purger_dir *pdir = g_malloc0( sizeof(struct purger_dir) );

        for( ; (aname = *attribute_names) != NULL; attribute_names++, attribute_values++ )
        {
            aval = *attribute_values;
            if( strcmp( aname, "directory" ) == 0 )
                pdir->directory = normalize_pathname( aval );
            else if( strcmp( aname, "keep_days" ) == 0 )
                pdir->keep_days = strtoul( aval, NULL, 0 );
        }
        if( !pdir->directory )
            ERR( "Undefined purge directory at line %d\n", line_number );
        if( !pdir->keep_days )
            ERR( "Undefined keep_days parameter at line %d\n", line_number );
        if( (!pdir->directory) || (!pdir->keep_days) )
        {
            if( pdir->directory ) g_free( pdir->directory );
            g_free( pdir );
            return;
        }
        purger_dirs = g_list_append( purger_dirs, pdir );
    }
    else if( current_filter )
    {
        /* sub-elements of filter */
        int val = -2;

        if( strcmp( element_name, "facility" ) == 0 )
        {
            for( ; (aname = *attribute_names) != NULL; attribute_names++, attribute_values++ )
            {
                aval = *attribute_values;
                if( strcmp( aname, "value" ) == 0 )
                {
                    val = strtol( aval, NULL, 0 );
                    if( val < 0 || val >= LOG_NFACILITIES )
                    {
                        val = -1;
                        break;
                    }
                }
                else if( strcmp( aname, "name" ) == 0 )
                {
                    CODE *c;
                    for( c = facilitynames; c->c_name; c++ )
                        if( strcmp( aval, c->c_name ) == 0 )
                        {
                            val = LOG_FAC( c->c_val );
                            break;
                        }
                    if( !c->c_name )
                    {
                        val = -1;
                        break;
                    }
                }
            }
            if( -2 == val )
                ERR( "Undefined facility at line %d\n", line_number );
            else if( val != -1 )
                current_filter->facilities[ val ] = TRUE;
        }
        else if( strcmp( element_name, "priority" ) == 0 )
        {
            for( ; (aname = *attribute_names) != NULL; attribute_names++, attribute_values++ )
            {
                aval = *attribute_values;
                if( strcmp( aname, "value" ) == 0 )
                {
                    val = strtol( aval, NULL, 0 );
                    if( val < 0 || val >= 8 )
                    {
                        val = -1;
                        break;
                    }
                }
                else if( strcmp( aname, "name" ) == 0 )
                {
                    CODE *c;
                    for( c = prioritynames; c->c_name; c++ )
                        if( strcmp( aval, c->c_name ) == 0 )
                        {
                            val = LOG_PRI( c->c_val );
                            break;
                        }
                    if( !c->c_name )
                    {
                        val = -1;
                        break;
                    }
                }
            }
            if( -2 == val )
                ERR( "Undefined priority at line %d\n", line_number );
            else if( val != -1 )
                current_filter->priorities[ val ] = TRUE;
        }

        if( -1 == val )
            ERR( "Invalid value \"%s\" of attribute \"%s\" at line %d\n", aval, aname, line_number );
    }
}

/******************************************************************************
 * xml_end_element
 */
static void xml_end_element (GMarkupParseContext *context,
                             const gchar         *element_name,
                             gpointer             user_data,
                             GError             **error)
{
    if( strcmp( element_name, "filter" ) == 0 )
    {
        if( current_filter )
        {
            /* append filter to the list */
            filters = g_list_append( filters, current_filter );
            current_filter = NULL;
        }
    }
}

/******************************************************************************
 * xml_passthrough
 *
 * look for encoding name
 */
static void xml_passthrough (GMarkupParseContext *context,
                             const gchar         *passthrough_text,
                             gsize                text_len,  
                             gpointer             user_data,
                             GError             **error)
{
    const gchar *startptr, *endptr;

    if( !prolog_expected )
        return;

    startptr = g_strstr_len( passthrough_text, text_len, "<?xml " );
    if( !startptr )
        return;

    startptr += 6;
    text_len -= startptr - passthrough_text;

    endptr = g_strstr_len( startptr, text_len, "?>" );
    if( !endptr )
        goto parsed;

    text_len = endptr - startptr;
    startptr = g_strstr_len( startptr, text_len, "encoding=\"" );
    if( !startptr )
        goto parsed;

    startptr += 10;

    endptr = strchr( startptr, '"' );
    if( !endptr )
        goto parsed;

    if( strncmp( startptr, "windows-", 8 ) == 0 )
    {
        gchar *p;

        startptr += 8;
        p = g_strndup( startptr, endptr - startptr );
        if( !p )
            goto parsed;
        encoding = g_strdup_printf( "CP%s", p );
        g_free( p );
    }
    else
        encoding = g_strndup( startptr, endptr - startptr );

parsed:
    prolog_expected = FALSE;
}

/******************************************************************************
 * resolve_logpaths
 *
 * replace logpath_names structures
 */
static void resolve_logpaths()
{
    GList *paths = NULL;
    GList *path_item;
    struct logpath *logpath = NULL;

    for( path_item = logpaths; path_item; path_item = path_item->next )
    {
        struct logpath_names *names = path_item->data;
        GList *item;

        g_free( logpath );
        logpath = g_malloc( sizeof(struct logpath) );

        /* find source */
        for( item = sources; item; item = item->next )
        {
            struct source *s = item->data;
            if( strcmp( s->name, names->source ) == 0 )
                break;
        }
        if( !item )
        {
            ERR( "Undefined source \"%s\" in log path\n", names->source );
            continue;
        }
        logpath->source = item->data;

        /* find destination */
        for( item = destinations; item; item = item->next )
        {
            struct destination *d = item->data;
            if( strcmp( d->name, names->destination ) == 0 )
                break;
        }
        if( !item )
        {
            ERR( "Undefined destination \"%s\" in log path\n", names->destination );
            continue;
        }
        logpath->destination = item->data;

        /* find filter */
        if( !names->filter )
            logpath->filter = NULL;
        else
        {
            for( item = filters; item; item = item->next )
            {
                struct filter *f = item->data;
                if( strcmp( f->name, names->filter ) == 0 )
                    break;
            }
            if( item )
                logpath->filter = item->data;
            else
                logpath->filter = NULL;
        }
        /* add item to paths */
        paths = g_list_append( paths, logpath );
        logpath = NULL;
    }

    /* free list */
    for( path_item = logpaths; path_item; path_item = path_item->next )
    {
        struct logpath_names *names = path_item->data;
        g_free( names->source );
        g_free( names->destination );
        if( names->filter ) g_free( names->filter );
        g_free( names );
    }
    g_list_free( logpaths );

    /* set new list */
    logpaths = paths;
}

/******************************************************************************
 * dump_configuration
 */
static void dump_configuration()
{
#   ifdef HAVE_DEBUG

    GList *item;

    TRACE( "Sources:\n" );
    for( item = sources; item; item = item->next )
    {
        struct source *s = item->data;
        TRACE( "\tname=%s\ttype=%s\tinterface=%d:%d:%d:%d\tport=%d\n",
               s->name,
               (s->type == ST_INTERNAL)? "internal" : ((s->type == ST_UDP)? "udp" : "undefined"),
               s->udp.sin_addr.S_un.S_un_b.s_b1, s->udp.sin_addr.S_un.S_un_b.s_b2,
               s->udp.sin_addr.S_un.S_un_b.s_b3, s->udp.sin_addr.S_un.S_un_b.s_b4,
               ntohs( s->udp.sin_port ) );
    }
    TRACE( "Destinations:\n" );
    for( item = destinations; item; item = item->next )
    {
        struct destination *d = item->data;
        TRACE( "\tname=%s\tfile=%s\n"
               "\t\trotate=%s size=%d backlogs=%d ifempty=%s\n"
               "\t\tolddir=%s compresscmd=%s\n",
               d->name, d->file,
               (d->rotate == RP_DAILY)? "daily"
                   : (d->rotate == RP_WEEKLY)? "weekly"
                   : (d->rotate == RP_MONTHLY)? "monthly"
                   : "undefined",
               d->size, d->backlogs, d->ifempty? "yes" : "no",
               d->olddir? d->olddir : "NULL",
               d->compresscmd? d->compresscmd : "NULL" );
    }
    TRACE( "Filters:\n" );
    for( item = filters; item; item = item->next )
    {
        struct filter *f = item->data;
        int i;
        TRACE( "\tname=%s\n", f->name );
        TRACE( "\tfacilities:\n" );
        for( i = 0; i < LOG_NFACILITIES; i++ )
            if( f->facilities[i] )
                TRACE( "\t\t%s\n", get_facility_name( i ) );
        TRACE( "\tpriorities:\n" );
        for( i = 0; i < 8; i++ )
            if( f->priorities[i] )
                TRACE( "\t\t%s\n", get_priority_name( i ) );
    }
    TRACE( "Log paths:\n" );
    for( item = logpaths; item; item = item->next )
    {
        struct logpath *p = item->data;
        TRACE( "\tsource=%s\tfilter=%s\tdestination=%s\n",
               p->source->name, p->filter? p->filter->name : "NULL", p->destination->name );
    }
    TRACE( "Purge directories:\n" );
    for( item = purger_dirs; item; item = item->next )
    {
        struct purger_dir *p = item->data;
        TRACE( "\tdirectory=%s\tkeep_days=%d\n", p->directory, p->keep_days );
    }
    TRACE( "Options:\n" );
    TRACE( "\tuse_dns=%d\n", (int) use_dns );
    TRACE( "\tsource_encoding=%s\n", source_encoding? source_encoding : "NULL" );
    TRACE( "\tdestination_encoding=%s\n", destination_encoding? destination_encoding : "NULL" );
    TRACE( "\tmark_interval=%d\n", mark_interval );
    TRACE( "\tmark_message=%s\n", mark_message );
    TRACE( "\thold=%d\n", hold );
    TRACE( "\tlogdir=%s\n", logdir? logdir : "NULL" );

#   endif /* HAVE_DEBUG */
}

/******************************************************************************
 * read_configuration
 */
gboolean read_configuration()
{
    gboolean ret = FALSE;
    GMarkupParser parser = {
        xml_start_element,
        xml_end_element,
        NULL,
        xml_passthrough,
        NULL
    };
    gchar *pathname;
    FILE *fd = NULL;
    GMarkupParseContext *ctx = NULL;
    char buffer[256];
    GError *error = NULL;

    TRACE_ENTER( "\n" );

    if( '\\' == syslog_conf_dir[0] || '/' == syslog_conf_dir[0] || ':' == syslog_conf_dir[1] )
        /* absolute path */
        pathname = g_build_filename( syslog_conf_dir, "syslog.conf", NULL );
    else
        /* relative path */
        pathname = g_build_filename( g_path_get_dirname( __argv[0] ),
                                     syslog_conf_dir, "syslog.conf", NULL );
    fd = fopen( pathname, "r" );
    if( !fd )
    {
        ERR( "Cannot open configuration file %s: %s\n", pathname, strerror(errno) );
        goto done;
    }

    ctx = g_markup_parse_context_new( &parser, 0, NULL, NULL );
    if( !ctx )
    {
        ERR( "Failed g_markup_parse_context_new\n" );
        goto done;
    }

    while( fgets( buffer, sizeof(buffer), fd ) )
    {
        gchar *encoded = NULL;
        gchar *parser_input;
        gboolean r;

        /* wrapper for Glib's XML parser:
           determine encoding in xml_passthrough and convert data fed to the parser to UTF-8 */
        if( encoding )
        {
            encoded = g_convert( buffer, -1, "UTF-8", encoding, NULL, NULL, &error );
            if( !encoded )
                goto done;

            parser_input = encoded;
        }
        else
            parser_input = buffer;

        r = g_markup_parse_context_parse( ctx, parser_input, strlen( parser_input ), &error );
        if( encoded ) g_free( encoded );
        if( !r )
            goto done;
    }
    if( !feof( fd ) )
    {
        ERR( "Cannot read configuration file %s: %s\n", pathname, strerror(errno) );
        goto done;
    }

    resolve_logpaths();
    dump_configuration();
    if( !logdir )
    {
        ERR( "logdir is not defined\n" );
        goto done;
    }
    ret = TRUE;

done:
    if( error )
    {
        gchar *locale_msg = g_locale_from_utf8( error->message, -1, NULL, NULL, NULL );
        if( locale_msg )
        {
            ERR( "%s\n", locale_msg );
            g_free( locale_msg );
        }
        g_error_free( error );
    }
    if( ctx ) g_markup_parse_context_free( ctx );
    if( fd ) fclose( fd );
    g_free( pathname );

    TRACE_LEAVE( "done; ret=%d\n", (int) ret );
    return ret;
}
