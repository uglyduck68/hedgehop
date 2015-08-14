/*
 * syslogd.h - syslogd implementation for windows, common definitions
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

extern int verbosity_level;
extern void display_message( FILE* fd, char* file, int line, const char* func, char* fmt, ... );

#ifdef HAVE_DEBUG
#  define DO_TRACE( verbosity, fmt... ) \
       do { \
           if( verbosity <= verbosity_level ) \
               display_message( stderr, __FILE__, __LINE__, __FUNCTION__, fmt ); \
       } while(0)
#  define TRACE_2( fmt... ) DO_TRACE( 2, fmt )
#  define TRACE( fmt... ) DO_TRACE( 1, fmt )
#else
#  define TRACE_2( fmt... )
#  define TRACE( fmt... )
#endif
#define TRACE_ENTER TRACE_2
#define TRACE_LEAVE TRACE_2
#define ERR( fmt... ) display_message( stderr, __FILE__, __LINE__, __FUNCTION__, fmt )

extern HANDLE service_stop_event;

extern char local_hostname[];

extern char *str_month[];

extern void syslogd_main();

/* options and their default values */
extern gboolean use_dns;
extern gchar *source_encoding;
extern gchar *destination_encoding;
extern int mark_interval;
extern gchar *mark_message;
extern int hold;
extern gchar *logdir;

/* sources, destinations, filters and logpaths */
enum source_type
{
    ST_UNDEFINED,
    ST_INTERNAL,
    ST_UDP
};

struct source
{
    gchar *name;
    enum source_type type;
    struct sockaddr_in udp;
};

enum rotation_period
{
    RP_UNDEFINED = 0,
    RP_INVALID,
    RP_DAILY,
    RP_WEEKLY,
    RP_MONTHLY
};

struct destination
{
    gchar *name;
    gchar *file;
    GList *file_writers;
    CRITICAL_SECTION cs_file_writers;
    enum rotation_period rotate;
    int size;
    int backlogs;
    gboolean ifempty;
    gchar *olddir;
    gchar *compresscmd;
    gchar *compressoptions;
};

struct filter
{
    gchar *name;
    gboolean facilities[ LOG_NFACILITIES ];
    gboolean priorities[ 8 ];
};

struct logpath
{
    struct source *source;
    struct filter *filter;
    struct destination *destination;
};

extern GList *sources;
extern GList *destinations;
extern GList *filters;
extern GList *logpaths;

extern gboolean read_configuration();

/* queue */
struct fifo_item
{
    struct fifo_item *next;  /* queue is a single-linked list */
    void *payload;
};

struct fifo
{
    struct fifo_item *first;  /* first pushed item */
    struct fifo_item *last;   /* last pushed item */
};

extern struct fifo* fifo_create();
extern void fifo_destroy( struct fifo* queue );
extern void fifo_push( struct fifo* queue, void* data );
extern void* fifo_pop( struct fifo* queue );

/* listener */
enum listener_status
{
    LSNR_ERROR,
    LSNR_SHUTDOWN,
    LSNR_GOT_MESSAGE
};

struct raw_message
{
    gchar *msg;
    struct sockaddr_in sender_addr;
    struct source *source;
};

extern gboolean init_listener();
extern void fini_listener();
extern enum listener_status listener( struct raw_message** msg );
extern void log_internal( int pri, char* fmt, ... );

/* message */
struct message
{
    LONG refcount;
    struct source *source;
    gchar *sender;
    int facility;
    int priority;
    gchar *timestamp;
    gchar *hostname;
    gchar *program;
    gchar *message;
};

extern void reference_message( struct message* msg );
extern void release_message( struct message* msg );

/* writer */
extern void fini_writer();
extern void write_message( struct message* msg, struct destination* destination );

/* logrotate */
extern void rotate_logfile( const gchar* pathname, struct destination* destination );

/* purger */
struct purger_dir
{
    gchar *directory;
    int keep_days;
};

extern GList *purger_dirs;

extern gboolean init_purger();
extern void fini_purger();
extern void purge_log_dirs();

/* pathnames */
extern gchar* make_absolute_log_pathname( char* path_appendix );
extern void create_directories( gchar* pathname );
extern gchar* normalize_pathname( const gchar* pathname );

/* workaround for syslog.h: included with SYSLOG_NAMES in names.c */
typedef struct _code {
	char	*c_name;
	int	c_val;
} CODE;

extern CODE prioritynames[];
extern CODE facilitynames[];

extern char* get_priority_name( int pri );
extern char* get_facility_name( int pri );
