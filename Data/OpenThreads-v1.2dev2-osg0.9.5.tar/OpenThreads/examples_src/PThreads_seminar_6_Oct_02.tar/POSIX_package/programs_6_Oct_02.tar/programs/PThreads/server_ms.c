/*                server_ms.c                */

/*
  A simple server program.  It sets up a TCP port for the client
  program to connect to.

  This version creates lots and lots of threads without bound.
  Maybe even too many threads (when the delay is long).  Scope
  is PROCESS local to emphasize how bad it can get.


cc -o server_ms server_ms.c -L. -R. -g -lpthread -lthread -pthread_extensions -lposix4 -lnsl -lsocket
*/


#define _POSIX_C_SOURCE 199506L 
/* Note that you need to define  __EXTENSIONS__ when using sockets. */
#define __EXTENSIONS__



#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <limits.h>
#include <errno.h>
#include "thread_extensions.h"

/* Constants etc. */
#define                 MESSAGE_SIZE 70


const int               MAX_FDS = OPEN_MAX-10;         /* Solaris constant */
 /* String sent by & to client when done */
const char              *END_CLIENT_MSG =
  "End\0                                                                   ";




/* The structures for clients, and requests */

typedef struct client_struct {

  int                   socket;                 /* socket fd */
  char                  name[30];               /* "Client_123[T@23]" */
  int                   outstanding_requests;   /* No. unanswered */

  pthread_mutex_t       lock;
  pthread_cond_t        cv;
} client_t;

typedef struct request_struct {
  client_t              *client;
  char                  data[MESSAGE_SIZE]; /* "Client_7[T@4] Request: 4" */
  struct request_struct *next;
} request_t; 




/* Optional command line arguments (+ defaults) */
int                     SLEEP = 100, SPIN= 0, N_CONSUMERS=10;
int			REQUESTED_TCP_PORT = 6500, ACTUAL_TCP_PORT,
  			MAX_PORT_RANGE=100;
int                     STOPPER_SLEEP=-1, KILLER_SLEEP=-1;




/* Other useful bits */
int                     PID;
pthread_attr_t          attr;
int                     port_socket;
int                     n_replies=0;











/* A List of REQUESTS with protection and related varaibles. */
request_t               *requests =     NULL;
int                     length =        0;
pthread_mutex_t         requests_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t          producer_cv =   PTHREAD_COND_INITIALIZER;
pthread_cond_t          consumer_cv =   PTHREAD_COND_INITIALIZER;



/* Some function declarations */

client_t *new_client(int);
void *producer(void *);
request_t *get_request(client_t *);
void *process_request(void *);


/* A bunch of simple helper functions */

void set_up_signal_mask() {
 sigset_t               s, s1, s2;
 static struct          sigaction action; 

/* Block everything first (in particular SIGPIPE) */
 sigfillset(&s);
 pthread_sigmask(SIG_BLOCK, &s, &s2);   
 sigemptyset(&s);                       
 sigaddset(&s, SIGUSR1);                /* For stopper() */
 sigaddset(&s, SIGINT);                 /* For ^C */
 pthread_sigmask(SIG_UNBLOCK, &s, &s1);
}  


/* Keep track of the current number of clients for stats & fd limit */
int client_max_count = 0;

int count_clients(int i) {
  static pthread_mutex_t counter_lock = PTHREAD_MUTEX_INITIALIZER;
  static int             client_count = 0;
  int j;
 
  pthread_mutex_lock(&counter_lock);
  client_count += i;
  if (client_count > client_max_count)
    client_max_count = client_count;
  j = client_count;
  pthread_mutex_unlock(&counter_lock);
  return(j);
}  













int count_requests(int i) {
  static int count=0;
  static pthread_mutex_t count_lock = PTHREAD_MUTEX_INITIALIZER;

 pthread_mutex_lock(&count_lock);
 count += i;
 i = count;
 pthread_mutex_unlock(&count_lock);
 return(i);				/* Can't return count */
}  

void print_requests()
{request_t              *r = requests;

 while (r != NULL)
   {printf("<Request: %d>\n", r->client->socket);
    r = r->next;
  }
}


/* Synchronize on the number of OUTSTANDING REQUESTS per client. */

void wait_for_requests_to_zero(client_t *client) {




}

int decrement_requests_for(client_t *client) {
  int i;
  






  return(i);
}

void increment_requests_for(client_t *client) {



}


/* Build a new REQUEST */

request_t *new_request(client_t *client, char *ibuf) {
  request_t             *request;

  pthread_t tid = pthread_self();
  DEBUG(printf("Server_%d[%s] get_request() received: \"%s\"\n",
               PID, thread_name(tid), ibuf));
  request = (request_t *) malloc(sizeof(request_t));
  request->client = client;
  strcpy(request->data, ibuf);
  count_requests(1);








  return(request);
}


int delete_request(request_t *request) {
  int i;
  

  free(request);
  return(i);
}



/*
  Send "End" and close the socket.


*/

void close_client(client_t *client) {
  int j;

  DEBUG(printf("Closing socket %s...\n", client->name));
  
  pthread_mutex_lock(&client->lock);
  if (client->socket != -1) { 			/* Ensure only close() once. */
    write(client->socket, END_CLIENT_MSG, MESSAGE_SIZE);   /* Ignore errors */
    close(client->socket);
    client->socket = -1;


    j = count_clients(-1);


    DEBUG(printf("Closed %s. (%d active clients)\n",
                 client->name, count_clients(0)));
  }
  pthread_mutex_unlock(&client->lock);
}





void write_msg(client_t *client, char *obuf) {
  int                   nbytes, socket, active;
  char                  *cname;
  char                  *t_name = thread_name(pthread_self());

  DEBUG(printf("Server_%d[%s] write_msg() sending: \"%s\"\n",
               PID, t_name, obuf));
  pthread_mutex_lock(&client->lock);
  socket = client->socket;
  cname  = client->name;

  pthread_mutex_unlock(&client->lock);
  

  retry: nbytes = write(socket, obuf, MESSAGE_SIZE);

  if (nbytes == MESSAGE_SIZE) {
    return;
  }

  if (nbytes > -1) {     
    printf("Only wrote %d bytes to %s. (Impossible?)", nbytes, cname);
    abort();
  }

  if (errno == EINTR) {
    printf("EINTR while trying to write to %s on fd#%d. retrying...\n",
	   cname, socket);
    goto retry;
  }

  if ((errno == EPIPE) || (errno == EBADF)) {
    printf("Failed trying to write to %s. \n", cname);
    perror("Closing socket");



    close_client(client);
    return;
  }
  else
    perror("Unknown bug (Impossible?)"), abort();
}




















int open_port() {
  struct sockaddr_in    cli_addr, serv_addr;
  int                   port_socket, clilen, i;

  /* Open a new port. Try to get requested port. */
  if((port_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    perror("Can't create new socket"), abort();

  for (i=REQUESTED_TCP_PORT; i< REQUESTED_TCP_PORT+MAX_PORT_RANGE; i++) {
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(i);
    if (bind(port_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
      {DEBUG(printf("Can't bind to port %d\n", i));}
    else {
      printf("Server bound to port: %d\n", i);
      ACTUAL_TCP_PORT=i;
      listen(port_socket, 5);
      return(port_socket);
    }
  }
  printf("Could not find an available port from %d to %d",
	 REQUESTED_TCP_PORT, REQUESTED_TCP_PORT+MAX_PORT_RANGE);
  abort();
}



client_t *accept_a_connection(int port_socket) {
  int                   new_socket, clilen;
  struct sockaddr_in    cli_addr;

  clilen = sizeof(cli_addr);
  new_socket = accept(port_socket, (struct sockaddr *) &cli_addr, &clilen);
  if (new_socket < 0) 
    perror("Accept failed. (Impossible?)"), abort();

  return(new_client(new_socket));
}


void *reporter(void *arg) {

  while (TRUE) {
    sleep(30);
    printf("Server up on port %d. Processed %d requests.\n",
	   ACTUAL_TCP_PORT, count_requests(0));
  }
}


int startup_initialize() {
  int 		i;

  set_up_signal_mask();

  PTHREAD_ATTR_INIT(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

}


void *acceptor(void *arg) {
  client_t *client;
  pthread_t tid;
  int port_socket = (int) arg;
  
  while (TRUE) {
    client = accept_a_connection(port_socket);
    PTHREAD_CREATE(&tid, &attr, producer, (void *) client);
  }
}



client_t *new_client(int socket) {
  client_t *client = (client_t *) malloc(sizeof(client_t));

  client->socket = socket;

  client->outstanding_requests=0;
  count_clients(1);
  DEBUG(printf("New Client fd#%d. (%d active clients)\n",
	       socket, count_clients(0)));
  return(client);
}

void *producer(void *arg) {
  request_t *request;
  client_t *client = (client_t *) arg;
  pthread_t tid;
  DEBUG(printf("Producer starting.\n"));

  while (TRUE) {
    request = get_request(client);
    if (request == NULL)  {
      close_client(client);
      return;
    }
     PTHREAD_CREATE(&tid, &attr, process_request, request);
  }
}

request_t *get_request(client_t *client) {
  request_t 		*request;
  char    		ibuf[MESSAGE_SIZE];
  int     		nbytes;

  nbytes = read(client->socket, ibuf, MESSAGE_SIZE);
  if (nbytes != MESSAGE_SIZE) {printf("Read failed!\n"); abort();}
  if (strncmp(ibuf, END_CLIENT_MSG, 3) == 0) return(NULL);

  request = new_request(client, ibuf);
  return(request);
}



/* Send a reply back to client */
void *process_request(void *arg) { request_t *request = (request_t *) arg;
  client_t              *client = request->client;
  char                  *cname;
  char                  obuf[MESSAGE_SIZE];
  char                  *t_name = thread_name(pthread_self());
  int                   i, nbytes, finishing, socket;

  DEBUG(printf("Server_%d[%s] processing: \"%s\"\n",
	       PID, t_name, request->data));

  delay(SLEEP, SPIN);
  sprintf(obuf, "Server_%d[%s] reply %d to %s",
	  PID, t_name, n_replies++, request->data);
  write_msg(client, obuf);
  delete_request(request);
}

main(int argc, char **argv) {
  int                   i;
  pthread_t tid;

  PID = getpid();

  if (argc > 1) REQUESTED_TCP_PORT = atoi(argv[1]);
  if (argc > 2) SLEEP = atoi(argv[2]);
  if (argc > 3) SPIN = atoi(argv[3]);
  if (argc > 4) N_CONSUMERS = atoi(argv[4]);
  if (argc > 5) STOPPER_SLEEP = atoi(argv[5]);
  if (argc > 6) KILLER_SLEEP = atoi(argv[6]);
  printf("Server_%d(TCP_PORT %d SLEEP %dms SPIN %dus N_CONSUMERS \n\
%d STOPPER %ds KILLER %ds)\n",
         PID, REQUESTED_TCP_PORT, SLEEP, SPIN, N_CONSUMERS,
         STOPPER_SLEEP, KILLER_SLEEP);

  startup_initialize();

  PTHREAD_CREATE(&tid, &attr, reporter, NULL);

  port_socket = open_port();
  if (KILLER_SLEEP > 0)
    PTHREAD_CREATE(&tid, &attr, killer, (void *) KILLER_SLEEP);

  acceptor((void *)port_socket);
}

