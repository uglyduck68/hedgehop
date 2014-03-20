/*                server_select.c                */
/* 4567890 234567890 234567890 234567890 234567890 234567890 234567890 2345678*/
/*

  This version of the server is designed to be robust under client
  failure and implements a complete shutdown, first closing the port,
  then shutting down the producer thread, finally closing the Interruptor
  pipe. The consumers do not exit, but they continue and empty the queue,
  then they sit around waiting for the server to restart. (This is
  trickier than it may seem!)

  This uses a single producer thread which calls select() on all clients
  and on the port socket. When a new connect comes it, it gets accepted
  and the new socket added to the select() list. When a new request
  comes in, it is read and returned as a request_t.
  

  Any IO failures are handled by printing out an error message, closing the
  socket in question, then ignoring it. The Client program is sent an "End"
  message then, and left to its own devices to deal with the fact that the
  socket has been closed early.

  Shutdown is accomplished by setting "stop" variables and then ensuring
  that the producer, which may be blocked on select() is woken up by 
  sending data on a special "Interruptor" pipe. Both read() and accept() are
  assumed never to block because they are only called after select()
  returns. Calls to write() are also assumed never to block (although an
  uncooperative client could cause this by never reading replies and letting
  the socket fill up (~64k!)).

  This has been tested on Solaris 2.6 with 1,000 clients and messages up to
  1m characters.

*/

/*                                           replies
                                  <-------------------------
                 _______     _______     _______            |
   Requests     |_______|-->|_______|-->|_______|           |
                               ^            |               |
                               |            |               |
        requests __________    |            |            __________
Client1 ------->| PRODUCER |   |             ---------> | CONSUMER |
Client2 ------->| select() |   |                        |          |
Client3 ------->|  read()  |---                         |          |
Client4 =======>|  accept()|<-------------------        |__________|
        connect |__________|                    |
                                 Interruptor    |
                                 Pipe           |        __________
                 __________                     |       | CONSUMER |
                | STOPPER  |                    |       |          |
                |          |                    |       |          |
                |stop vars |--------------------        |__________|
                |__________|            "STOP"
                                                                ...

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
#include <sys/resource.h>
#include "thread_extensions.h"



/* Constants etc. rlimit set to MAX_FDS in main() */
/* MESSAGE_SIZE must be < 1m (for buffers to fit on the stack) */
#define                 MESSAGE_SIZE 70
#define                 READ 0
#define                 WRITE 1
#define                 MAX_FDS  1024
int                     ACTUAL_MAX_FDS=MAX_FDS;

 /* String sent by & to client when done */
const char              *END_CLIENT_MSG = "End";
/* String used by Stopper thread to wake up Producer */
const char              *STOP_MSG = "STOP";

/* The structures for clients, and requests */

typedef struct client_struct {
  int                   active;                 /* Is the socket valid? */
  int                   socket;                 /* socket fd */
  char                  name[30];               /* "Client_123[T@23]" */
  int                   outstanding_requests;   /* No. unanswered */
  int                   finishing;              /* "End" received */
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
int                     REQUESTED_TCP_PORT = 6500, ACTUAL_TCP_PORT,
                        MAX_PORT_RANGE=100;
int                     STOPPER_SLEEP=-1, KILLER_SLEEP=-1;

/* Array of clients */
client_t                clients[MAX_FDS];

/* Other useful bits */
int                     PID;
pthread_attr_t          attr;
int                     port_socket;
int                     interrupter_pipe[2];


/* Barriers and variables used for shutting down the server */
thread_single_barrier_t producer_barrier;
thread_single_barrier_t stopper_barrier;
thread_barrier_t        consumer_barrier1, consumer_barrier2;
pthread_t               producer_thread;
int                     stop_producer = FALSE;
int                     stop_consumers= FALSE;


/* A List of REQUESTS with protection and related varaibles. */
request_t               *requests =     NULL;
int                     length =        0;
pthread_mutex_t         requests_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t          producer_cv =   PTHREAD_COND_INITIALIZER;
pthread_cond_t          consumer_cv =   PTHREAD_COND_INITIALIZER;



/* Some function declarations */

client_t *new_client(int);
void *producer(void *);
request_t *get_request();
void *process_request(request_t *);


/* A bunch of simple helper functions */

void set_up_signal_mask() {
 sigset_t               s, s1, s2;
 static struct          sigaction action; 

/* Block everything first (in particular SIGPIPE) */
 sigfillset(&s);
 pthread_sigmask(SIG_BLOCK, &s, &s2);   
 sigemptyset(&s);                       

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


/* Used for debugging */
void dump_client_data() {
  int i;

  for (i=0; i<ACTUAL_MAX_FDS; i++) {
    if (clients[i].active)
      printf("%s on fd#%d\n", clients[i].name, clients[i].socket);
  }
}


int count_requests(int i) {
  static int count=0;
  static pthread_mutex_t count_lock = PTHREAD_MUTEX_INITIALIZER;

  pthread_mutex_lock(&count_lock);
  count += i;
  i = count;
  pthread_mutex_unlock(&count_lock);
  return(i);                             /* Can't return count */
}  

int count_replies(int i) {
  static int count=0;
  static pthread_mutex_t count_lock = PTHREAD_MUTEX_INITIALIZER;

  pthread_mutex_lock(&count_lock);
  count += i;
  i = count;
  pthread_mutex_unlock(&count_lock);
  return(i);                             /* Can't return count */
}  

void print_requests() {
  request_t              *r = requests;

  while (r != NULL)
    {printf("<Request: %d>\n", r->client->socket);
    r = r->next;
    }
}


/* Synchronize on the number of OUTSTANDING REQUESTS per client. */

void wait_for_requests_to_zero(client_t *client) {
  pthread_mutex_lock(&client->lock);
  while (client->outstanding_requests > 0)
    pthread_cond_wait(&client->cv, &client->lock);
  pthread_mutex_unlock(&client->lock);
}

int decrement_requests_for(client_t *client) {
  int i;
  
  pthread_mutex_lock(&client->lock);
  client->outstanding_requests--;
  i = client->outstanding_requests;
  if (client->outstanding_requests == 0)
    pthread_cond_signal(&client->cv);
  pthread_mutex_unlock(&client->lock);
  return(i);
}

void increment_requests_for(client_t *client) {
  pthread_mutex_lock(&client->lock);
  client->outstanding_requests++;
  pthread_mutex_unlock(&client->lock); 
}


/* Build a new REQUEST */

request_t *new_request(client_t *client, char *ibuf) {
  request_t             *request;

  pthread_t tid = pthread_self();
  DEBUG(printf("Server_%d[%s] new request_t: \"%s\"\n",
               PID, thread_name(tid), ibuf));
  request = (request_t *) malloc(sizeof(request_t));
  request->client = client;
  strcpy(request->data, ibuf);
  count_requests(1);
  increment_requests_for(client); 

  pthread_mutex_lock(&client->lock);
  if (client->name[0] == ' ') {         /* Hack to get a client name! */
    strncpy(client->name, ibuf, 18);    /* Runs only on first request */
    client->name[18] = 0;
  }
  pthread_mutex_unlock(&client->lock);
  return(request);
}


int delete_request(request_t *request) {
  int i;
  
  i=decrement_requests_for(request->client);
  free(request);
  return(i);
}



/*
  Send "End" and close the socket.
  It's OK if the socket has already been closed.
  This is only called when outstanding_requests == 0.
*/

void close_client(client_t *client) {
  int j;
  char                  *t_name = thread_name(pthread_self());

  DEBUG(printf("Server_%d[%s] Closing socket %s...\n",
	       PID, t_name, client->name));
  
  pthread_mutex_lock(&client->lock);
  if (client->socket != -1) {                   /* Ensure only close() once. */
    write(client->socket, END_CLIENT_MSG, MESSAGE_SIZE);   /* Ignore errors */
    close(client->socket);
    client->socket = -1;
    client->active = FALSE;
    client->finishing = FALSE;
    j = count_clients(-1);
    if (j == 0)
      DEBUG(printf("Max open sockets: %d\n", client_max_count));
    DEBUG(printf("Closed %s. (%d active clients)\n",
                 client->name, count_clients(0)));
  }
  pthread_mutex_unlock(&client->lock);
}





void write_msg(client_t *client, const char *msg) {
  int                   nbytes, socket, active, totalWritten;
  char                  *cname;
  char                  *t_name = thread_name(pthread_self());
  char			obuf[MESSAGE_SIZE];
  

  DEBUG(printf("Server_%d[%s] write_msg() sending: \"%s\"\n",
               PID, t_name, msg));
  if (strlen(msg)<MESSAGE_SIZE) strcpy(obuf, msg, strlen(msg));

  pthread_mutex_lock(&client->lock);
  socket = client->socket;
  cname  = client->name;
  active = client-> active;
  
  if (!active)  { /* Another consumer got an error & closed socket */
    pthread_mutex_unlock(&client->lock);
    return;
  }

  for (totalWritten = 0; totalWritten < MESSAGE_SIZE; ) {
    nbytes = write(socket, &obuf[totalWritten], MESSAGE_SIZE-totalWritten);

    if (nbytes == -1) {
      if ((errno == EPIPE) || (errno == EBADF)) {
	printf("Server_%d[%s] Failed trying to write to %s. \n",
	       PID, t_name, cname);
	perror("Closing socket");
	pthread_mutex_lock(&client->lock);
	client->active = FALSE;
	pthread_mutex_unlock(&client->lock);
	close_client(client);
	break;
      }
      perror("Unknown bug (Impossible?)"), abort();
    }
    DEBUG(printf("Server_%d[%s] write_msg() wrote %d chars.\n",
		 PID, t_name, nbytes));
    totalWritten += nbytes;
  }
  pthread_mutex_unlock(&client->lock);
  return;
}


/* Manipulate the requests list. Caller must own requests_lock. */
request_t *remove_request() {
  request_t *request;

  request = requests;
  requests = requests->next;
  length--;
  return(request);
}

void add_request(request_t *request) {
  request->next = requests;                     /* Insert at head of list */
  requests = request;
  length++;
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


/* This will never block. Only called when select() indicates a new client. */
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
    printf("Server up on port %d. Processed %d requests. %d clients.\n",
           ACTUAL_TCP_PORT, count_requests(0), count_clients(0));
  }
}


int startup_initialize() {
  int                   i;
  struct rlimit         r;

  set_up_signal_mask();

  thread_barrier_init(&consumer_barrier1, N_CONSUMERS+1);
  thread_barrier_init(&consumer_barrier2, N_CONSUMERS+1);
  thread_single_barrier_init(&producer_barrier, 1);
  thread_single_barrier_init(&stopper_barrier, 1);
  PTHREAD_ATTR_INIT(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

  getrlimit(RLIMIT_NOFILE, &r);
  r.rlim_cur=r.rlim_max;
  ACTUAL_MAX_FDS = r.rlim_max-10;
  setrlimit(RLIMIT_NOFILE, &r);
  /*  getrlimit(RLIMIT_NOFILE, &r);
      printf("Current limit: %d Max limit: %d\n", r.rlim_cur, r.rlim_max); */


  for (i=0; i<ACTUAL_MAX_FDS; i++) {
    pthread_mutex_init(&clients[i].lock, NULL);
  }
}


int initialize_clients() {
  int i;
  client_t *client;
 
  count_clients(-count_clients(0)); /* Zero it out */
  for (i=0; i<ACTUAL_MAX_FDS; i++) {
    client = &clients[i];
    pthread_mutex_lock(&client->lock);
    close(client->socket);      /* Could be left open by dirty exit */
    client->socket = -1;
    client->name[0] = ' ';
    client->active = FALSE;
    client->finishing = FALSE;
    client->outstanding_requests = 0;
    pthread_mutex_unlock(&client->lock);
  }

  if (pipe(interrupter_pipe) < 0) 
    printf("Can't open Interruptor pipe\n"), abort();
 
  /* clients[0] is the local socket for announcing new clients. */
  clients[0].socket = interrupter_pipe[READ];
  strcpy(clients[0].name, "Interruptor");
  clients[0].active = TRUE;

  port_socket = open_port();
  /* clients[1] is the local socket for announcing new clients. */
  clients[1].socket = port_socket;
  strcpy(clients[1].name, "Acceptor");
  clients[1].active = TRUE; 
}





client_t *new_client(int socket) {
  int i, c;
  client_t *client;

  for (i=0; i<ACTUAL_MAX_FDS; i++) { /* Find an open slot in array */
    client=&clients[i];
    pthread_mutex_lock(&client->lock);

    if (!client->active & (client->outstanding_requests == 0)) {
      /* If client died dirty, there could still be outstanding requests. */
      client = &clients[i];
      client->socket = socket;
      client->active = TRUE;
      client->outstanding_requests=0;
      client->finishing = FALSE;
      client->name[0] = ' ';         /* Hack! (see new_request()) */
      c =count_clients(1);
      DEBUG(printf("New Client fd#%d. (%d active clients)\n",
                   socket, c));
      pthread_mutex_unlock(&client->lock);
      return(client);
    }

    pthread_mutex_unlock(&client->lock);
  }
  printf("Too many clients (max = %d). Ignoring new one.\n", ACTUAL_MAX_FDS-2);
  pthread_mutex_unlock(&client->lock);
  write(socket, END_CLIENT_MSG, MESSAGE_SIZE);             /* Ignore errors */
  close(socket);
}


/* Wait for any client to send a request & return that request. */
/* Only one thread may call get_request(). */
request_t *get_request() {
  fd_set                readset, errorset;
  int                   i, num_ready, num_now, nRead;
  int			totalRead, nZeros=0, socket;
  char                  buf[MESSAGE_SIZE];
  request_t             *request;
  client_t              *client;
  pthread_t             tid = pthread_self();


  while (TRUE) {

    /* Reset the bit arrays for select() */
    FD_ZERO(&readset);
    FD_ZERO(&errorset);
    for (i = 0; i < ACTUAL_MAX_FDS; i++) {
      client = &clients[i];
      pthread_mutex_lock(&client->lock);
      if (client->active) {
        FD_SET(client->socket, &readset);
        FD_SET(client->socket, &errorset);
      }
      pthread_mutex_unlock(&client->lock);
    }


    num_ready = select(OPEN_MAX, &readset, 0, &errorset, 0);


    /* Time to exit? */
    pthread_mutex_lock(&requests_lock);
    if (stop_producer) {
      pthread_mutex_unlock(&requests_lock);
      return(NULL);           /* Clean exit */
    }
    pthread_mutex_unlock(&requests_lock);

    
    if (num_ready < 0) {
      if (errno == EBADF) goto bottom;  /* An fd was closed, retry */
      perror("Error in select(). Impossible"); abort();
    }


    /* Find the socket with data ready */
    for (i = 0; i < ACTUAL_MAX_FDS;  i++) {
      client = &clients[i];
      pthread_mutex_lock(&client->lock);

      if (client->active && FD_ISSET(client->socket, &errorset)) {
        /* Error condition pending on this fd. (What does that mean??) */
        client->active = FALSE;
        pthread_mutex_unlock(&client->lock);
        close_client(client);
        printf("Error condition on %s, fd#%d from select(). Impossible?\n",
               client->name, client->socket);
        goto bottom;
      }


      if (client->active && FD_ISSET(client->socket, &readset)) {
        /* This is the socket with data ready! */
        socket = client->socket;
        pthread_mutex_unlock(&client->lock);

        if (i == 1) {
          accept_a_connection(socket);
          goto bottom;
        }

	for (totalRead = 0; totalRead < MESSAGE_SIZE; ) {
	  nRead = read(socket, &buf[totalRead], MESSAGE_SIZE-totalRead);
	  if (nRead <= 0) {
	    if (nRead == 0) {
	      DEBUG(printf("Read zero from %s\n", client->name));
	      nZeros++;
	      if (nZeros < 5) continue;		/* Allow a few 0 reads */
	    }
	    printf("Read failed on %s fd#%d! Closing it.\n",
	    client->name, client->socket);
	    if (nRead == -1) perror("");
	    pthread_mutex_lock(&client->lock);
	    client->active = FALSE;
	    pthread_mutex_unlock(&client->lock);
	    close_client(client);
	    goto bottom;
          }
	  nZeros = 0;
	  totalRead += nRead;
	  if (nRead<MESSAGE_SIZE)
	    DEBUG(printf("Read %d, Total Read: %d\n", nRead, totalRead));
	}

        if (i == 0) {    /* Should have exited on stop_producer */ 
          printf("Bogus message on Interruptor. Impossible!\n");
          abort();
        }
        
	DEBUG(printf("Server_%d[%s] get_request() received: \"%s\"\n",
		     PID, thread_name(tid), buf));
	request = new_request(client, buf);
	return(request);
      }
      pthread_mutex_unlock(&client->lock);
    }

    /* select() returned 0 ready, or failed to set readset */
    if (num_ready == 0)
      printf("select() returned 0 ready. Impossible?\n");
    else
      printf("select() returned %d ready (readset not set) Impossible?\n",
             num_ready);
    abort();
    
  bottom: nZeros = 0;
  }     /* End while(TRUE) */
}



/* Send a reply back to client */
void *process_request(request_t *request) {
  client_t              *client = request->client;
  char                  *cname;
  char                  obuf[MESSAGE_SIZE];
  char                  *t_name = thread_name(pthread_self());
  int                   i, nbytes, finishing, socket;

  DEBUG(printf("Server_%d[%s] processing: \"%s\"\n",
               PID, t_name, request->data));

    pthread_mutex_lock(&client->lock);
    socket = client->socket;
    cname = client->name;
    pthread_mutex_unlock(&client->lock);
    
    if (strncmp(request->data, END_CLIENT_MSG, 3) == 0) {
      pthread_mutex_lock(&client->lock);
      client->finishing = TRUE;
      pthread_mutex_unlock(&client->lock);
    }
    else {
      delay(SLEEP, SPIN);
      sprintf(obuf, "Server_%d[%s] reply %d to %s",
              PID, t_name, count_replies(1), request->data);
      write_msg(client, obuf);
    }
  i = delete_request(request);
  if (i == 0) {
    pthread_mutex_lock(&client->lock);
    finishing = client->finishing;
    pthread_mutex_unlock(&client->lock);
    if (finishing) close_client(client);
  }
}   


 
void *producer(void *arg) {
  request_t 		*request;
  char      		*t_name = thread_name(pthread_self());
  int 			j;


  DEBUG(printf("Server_%d[%s] Producer starting.\n", PID, t_name));
  set_up_signal_mask();

  while (TRUE) {
    request = get_request();

    if (request == NULL) {
      DEBUG(printf("Producer exiting via get_request().\n"));
      thread_single_barrier_post(&producer_barrier);
      pthread_exit(NULL);
    }

    
    pthread_mutex_lock(&requests_lock);
    while ((length >= 10) && (!stop_producer))
      pthread_cond_wait(&producer_cv, &requests_lock);
    add_request(request);
    if (stop_producer) break;
    pthread_mutex_unlock(&requests_lock);
    pthread_cond_signal(&consumer_cv);
  }


  pthread_mutex_unlock(&requests_lock);
  DEBUG(printf("Producer exiting via wait.\n"));
  thread_single_barrier_post(&producer_barrier);
  pthread_exit(NULL);
}


void *consumer(void *arg) {
  request_t 		*request;
  char      		*t_name = thread_name(pthread_self());

  DEBUG(printf("Server_%d[%s] Consumer starting.\n", PID, t_name));
  set_up_signal_mask();

  while(TRUE) {
    pthread_mutex_lock(&requests_lock);
    while ((length == 0) && (!stop_consumers))
      pthread_cond_wait(&consumer_cv, &requests_lock);
    if ((length == 0) && (stop_consumers)) {
      /* Empty the queue first, then indicate done. */
      pthread_mutex_unlock(&requests_lock);
      thread_barrier_wait(&consumer_barrier1); /* consumers are stopped */
      thread_barrier_wait(&consumer_barrier2); /* consumers may continue */
      continue;         /* Continue when everyone is done. */
    }
    request = remove_request();
    pthread_mutex_unlock(&requests_lock);
    pthread_cond_signal(&producer_cv);
    process_request(request);
  }
}



void *stopper(void *arg) {
  pthread_t waker_thread;
  
  sleep(STOPPER_SLEEP);
  printf("Time to stop!\n");

  /* Wake up producer if blocked in select() wait() */
  pthread_mutex_lock(&requests_lock);
  stop_producer = TRUE;
  pthread_mutex_unlock(&requests_lock);
  pthread_cond_broadcast(&producer_cv);
  /* Wake producer */
  write_msg(&clients[0], STOP_MSG);	/* Never read */
  thread_single_barrier_wait(&producer_barrier);
  close(interrupter_pipe[WRITE]);


  /* Wake up all consumers and stop them last. Otherwise the producer
   could still add a request after they all stopped. */
  pthread_mutex_lock(&requests_lock);
  stop_consumers=TRUE;
  pthread_mutex_unlock(&requests_lock);
  pthread_cond_broadcast(&consumer_cv);
  thread_barrier_wait(&consumer_barrier1);

  DEBUG(printf("Stopper finished.\n"));
  thread_single_barrier_post(&stopper_barrier);
  pthread_exit(NULL);
}

main(int argc, char **argv) {
  int                   i, j;
  pthread_t             tid;


  PID = getpid();

  if (argc > 1) REQUESTED_TCP_PORT = atoi(argv[1]);
  if (argc > 2) SLEEP = atoi(argv[2]);
  if (argc > 3) SPIN = atoi(argv[3]);
  if (argc > 4) N_CONSUMERS = atoi(argv[4]);
  if (argc > 5) STOPPER_SLEEP = atoi(argv[5]);
  if (argc > 6) KILLER_SLEEP = atoi(argv[6]);
  printf("Server_%d(TCP_PORT %d SLEEP %dms SPIN %dus N_CONSUMERS \
%d STOPPER %ds KILLER %ds)\n",
         PID, REQUESTED_TCP_PORT, SLEEP, SPIN, N_CONSUMERS,
         STOPPER_SLEEP, KILLER_SLEEP);

  startup_initialize();

  for (i=0; i<N_CONSUMERS; i++) {
    PTHREAD_CREATE(&tid, &attr, consumer, (void *) NULL);
  }

  PTHREAD_CREATE(&tid, &attr, reporter, NULL);

  for (j=0; j<100; j++) {         /* Start/Stop 100 times */
    printf("Starting up interation %d.\n", j);
    initialize_clients();

    PTHREAD_CREATE(&producer_thread, &attr, producer, (void *) NULL);
    if (STOPPER_SLEEP > 0)
      PTHREAD_CREATE(&tid, &attr, stopper, (void *) NULL);
    if (KILLER_SLEEP > 0)
      PTHREAD_CREATE(&tid, &attr, killer, (void *) KILLER_SLEEP);

    thread_single_barrier_wait(&stopper_barrier);
    printf("Shutdown successful. %d replies sent.\n\n\n", count_replies(0));

    pthread_mutex_lock(&requests_lock);
    stop_producer=FALSE;
    stop_consumers=FALSE;
    pthread_mutex_unlock(&requests_lock);
    thread_barrier_wait(&consumer_barrier2); /* NOW restart consumers */
  }
  printf("Exiting Server Normally after 100 iterations.\n");
}







