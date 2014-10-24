/*                ServerSelect/server_select.c                */
/* 4567890 234567890 234567890 234567890 234567890 234567890 234567890 2345678*/
/*

  This is a section of code stolen directly from a C program which
  does exactly the same thing, PThreads/server_select.c. The comments
  below are from that program.



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
  that the producer, which may be blocked on select() is woken up by doing a
  sending data on a special "Interruptor" pipe. Both read() and accept() are
  assumed never to block because they are only called after select()
  returns. Calls to write() are also assumed never to block (although an
  uncooperative client could cause this by never reading replies and letting
  the socket fill up (~64k!)).

  Select uses special positions:
  0 = interruptor pipe, 1 = acceptor, 2 = overflow

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
#include "native_select.h"


/* Constants etc. rlimit set to MAX_FDS in main() */
#define                 MAX_FDS  1024
int                     ACTUAL_MAX_FDS=MAX_FDS;


 /* String sent by & to client when done */
const char              *END_CLIENT_MSG =
  "End                                                                    ";
 /* String sent by & to client when done */
const char              *NEW_CLIENT_MSG =
  "New                                                                    ";
/* String used by Stopper thread to wake up Producer */
const char              *STOP_MSG =  
  "STOP                                                                   ";

/* Optional command line arguments (+ defaults) */
int                     REQUESTED_TCP_PORT = 6500, ACTUAL_TCP_PORT,
                        MAX_PORT_RANGE=100;

/* Array of clients */
client_t                clients[MAX_FDS];

/* Other useful bits */
int                     PID;
int                     port_socket;
int                     interrupter_pipe[2];


/* Barriers and variables used for shutting down the server */
int                     stop_producer = FALSE;
pthread_mutex_t         requests_lock = PTHREAD_MUTEX_INITIALIZER;




/* This is part of a more general function that works on
   ALL pthreads implementations. See PThreads/thread_extensions.c */

char *thread_name(pthread_t tid) {
  char s[100], *name;

  sprintf(s, "T@%d", (int) tid);
  name = (char *) malloc(strlen(s)+1);  
  strcpy(name, s);              /* Yes, it leaks. The real one doesn't. */
  return(name);
}




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


int count_requests(int i) {
  static int count=0;
  static pthread_mutex_t count_lock = PTHREAD_MUTEX_INITIALIZER;

 pthread_mutex_lock(&count_lock);
 count += i;
 i = count;
 pthread_mutex_unlock(&count_lock);
 return(i);                             /* Can't return count */
}  


/* Used for debugging */
void dump_client_data() {
  int i;

  for (i=0; i<ACTUAL_MAX_FDS; i++) {
    if (clients[i].active)
      printf("%s on fd#%d\n", clients[i].name, clients[i].socket);
  }
}


/*
  Send "End" and close the socket.
  It's OK if the socket has already been closed.
  This is only called when outstanding_requests == 0.
*/

void close_client(client_t *client) {
  int j;

  DEBUG(printf("Closing socket %s...\n", client->name));
  
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





int write_msg(client_t *client, char *obuf) {
  int                   nbytes, socket, active;
  char                  *cname;
  char                  *t_name = thread_name(pthread_self());

  DEBUG(printf("Server_%d[%s] write_msg() sending: \"%s\"\n",
               PID, t_name, obuf));
  pthread_mutex_lock(&client->lock);
  socket = client->socket;
  cname  = client->name;
  active = client-> active;
  pthread_mutex_unlock(&client->lock);
  
  if (active)  { /* Another consumer got an error & closed socket */
  retry: nbytes = write(socket, obuf, MESSAGE_SIZE);

  if (nbytes == MESSAGE_SIZE) {
    return 0;
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
    pthread_mutex_lock(&client->lock);
    client->active = FALSE;
    pthread_mutex_unlock(&client->lock);
    return -1; /* Error! Java  will need to close client. */
  }
  else
    perror("Unknown bug (Impossible?)"), abort();
  }
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
      DEBUG(printf("Server bound to port: %d\n", i));
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

int startup_initialize() {
  int           i;
  struct rlimit         r;

  set_up_signal_mask();

  getrlimit(RLIMIT_NOFILE, &r);
  r.rlim_cur=r.rlim_max;
  ACTUAL_MAX_FDS = r.rlim_max-10; /* Leave 10 for Java, stdio */
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
    client->index = i;
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

    /* clients[2] is the overflow indicator for too many clients. */
  clients[2].socket = -1;
  strcpy(clients[2].name, "Overflow");
  clients[2].active = FALSE; /* Don't select() on -1 */
  clients[2].outstanding_requests=-1; /* Don't let it be used by anyone else */

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

  pthread_mutex_unlock(&client->lock);
  write(socket, END_CLIENT_MSG, MESSAGE_SIZE);             /* Ignore errors */
  close(socket);
  printf("Too many clients (max = %d). Ignoring new one.\n", ACTUAL_MAX_FDS-3);
  return(&clients[CLIENT_OVERFLOW]);    /* Notify Java of overflow */
}



request_t *new_request(client_t *client, const char *ibuf) {
  request_t             *request;

  pthread_t tid = pthread_self();
  DEBUG(printf("Server_%d[%s] get_request() received: \"%s\" on: %d\n",
               PID, thread_name(tid), ibuf, client->index));
  request = (request_t *) malloc(sizeof(request_t));
  request->client = client;
  strcpy(request->data, ibuf);
  count_requests(1);

  pthread_mutex_lock(&client->lock);
  if ((client->name[0] == ' ') || (client->name[0] == 'N')){
    /* Hack to get a client name! */
    strncpy(client->name, ibuf, 18);    /* Runs only on first request */
    client->name[18] = 0;
  }
  pthread_mutex_unlock(&client->lock);
  return(request);
}


int delete_request(request_t *request) {
  int i;
  
  free(request);
  return(i);
}




/* Wait for any client to send a request & return that request. */
/* Only one thread may call get_request(). */
request_t *get_request() {
  fd_set                readset, errorset;
  int                   i, num_ready, num_now, nbytes, socket;
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
      DEBUG(printf("Server_%d[%s] get_request() stopping\n"));
      return(new_request(&clients[0], STOP_MSG));           /* Clean exit */
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
        /* close_client(client); Let Java close */
        printf("Error condition on %s, fd#%d from select(). Impossible?\n",
               client->name, client->socket);
        return new_request(client, END_CLIENT_MSG);
      }


      if (client->active && FD_ISSET(client->socket, &readset)) {
        /* This is the socket with data ready! */
        socket = client->socket;
        pthread_mutex_unlock(&client->lock);

        if (i == 1) {
          DEBUG(printf("Accepting...\n"));
          client=accept_a_connection(socket);
          return(new_request(client, NEW_CLIENT_MSG));
        }
        nbytes = read(socket, buf, MESSAGE_SIZE);

        if ((nbytes == -1) || (nbytes != MESSAGE_SIZE)) {
          printf("Read only %d bytes on %s!\n", nbytes, client->name);
          if (i == 0) {
            printf("Interrupt pipe failed. Impossible!\n");
            abort();
          }
          pthread_mutex_lock(&client->lock);
          client->active = FALSE;
          pthread_mutex_unlock(&client->lock);
          return new_request(client, END_CLIENT_MSG);
        }

        if (i == 0) {    /* Should have exited on stop_producer */ 
          printf("Bogus message on Interruptor. Impossible!\n");
          printf("\'%s\'\n", buf);
          abort();
        }
        
        if (nbytes == MESSAGE_SIZE) {/* All is well, return new request_t. */
          DEBUG(printf("Server_%d[%s] get_request() received: \"%s\"\n",
                       PID, thread_name(tid), buf));
          request = new_request(client, buf);
          return(request);
        }
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
    
  bottom: {}
  }     /* End while(TRUE) */
}


initialize_port() {
  PID = getpid();
  startup_initialize();
  initialize_clients();
}



void set_stop(int i) {
  pthread_mutex_lock(&requests_lock);
  stop_producer = i;
  pthread_mutex_unlock(&requests_lock);
  if (i) /* Only interrupt on stop = TRUE */
    write(interrupter_pipe[WRITE], STOP_MSG, MESSAGE_SIZE);
}
