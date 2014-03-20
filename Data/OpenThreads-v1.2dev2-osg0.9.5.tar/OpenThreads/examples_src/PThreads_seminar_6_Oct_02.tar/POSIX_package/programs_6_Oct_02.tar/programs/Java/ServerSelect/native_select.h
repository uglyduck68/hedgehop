/* Constants etc. Must be identical with same data in Java */
#define                 MESSAGE_SIZE 70
#define                 READ 0
#define                 WRITE 1
#define			CLIENT_OVERFLOW 2
#define			TRUE 1
#define			FALSE 0
#define DEBUG(arg)      {if (getenv("DEBUG")) arg;}


 /* String sent by & to client when done */
extern const char              *END_CLIENT_MSG;
 /* String sent by & to client when done */
extern const char              *NEW_CLIENT_MSG;
/* String used by Stopper thread to wake up Producer */
extern const char              *STOP_MSG;

/* The structures for clients, and requests */

typedef struct client_struct {
  int                   active;                 /* Is the socket valid? */
  int		        index;                  /* Location in clients[] */
  int                   socket;                 /* socket fd */
  char                  name[30];               /* "Client_123[T@23]" */
  int                   outstanding_requests;   /* No. unanswered */
  int                   finishing;	        /* "End" received */
  pthread_mutex_t       lock;
  pthread_cond_t        cv;
} client_t;


typedef struct request_struct {
  client_t              *client;
  char                  data[MESSAGE_SIZE]; /* "Client_7[T@4] Request: 4" */
  struct request_struct *next;
} request_t; 



/* Optional command line arguments (+ defaults) */
extern int		REQUESTED_TCP_PORT, ACTUAL_TCP_PORT,
  			MAX_PORT_RANGE;

/* Array of clients */
extern client_t         clients[];

extern int interrupter_pipe[];


/* Some function declarations */

client_t *new_client(int);
void *producer(void *);
request_t *get_request();
void *process_request(request_t *);
