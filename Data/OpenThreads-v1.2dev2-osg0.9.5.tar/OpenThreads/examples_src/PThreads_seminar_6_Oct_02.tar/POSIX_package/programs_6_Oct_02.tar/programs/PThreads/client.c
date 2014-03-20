/*                client.c                */

/*
  The client side simply sends a hugh number of requests to the
  chosen server as fast as requested, spawing one thread to do the
  sending and another to receive the replies. You may request multiple
  pairs of senders & receivers each with their own socket. The 
  senders & receivers run asynchronously intentionally, thus replies
  may be received out-of-order.

  The client will try the requested port first, then the next higher
  port and keep going (in case the server is actually on another port).

  Nothing interesting here.


cc -o client client.c -L. -R. -g -lpthread -pthread_extensions -lposix4 -lnsl -lsocket
*/


#define _POSIX_C_SOURCE 199506L 
#define __EXTENSIONS__

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/resource.h>
#include "thread_extensions.h"


/* Constants etc. rlimit set to MAX_FDS in main() */
/* MESSAGE_SIZE must be < 1m (for buffers to fit on the stack) */
#define                 MESSAGE_SIZE 70
#define                 MAX_FDS  1000

/* 127.0.0.1 is the loopback address.  You may change it. */
const char              *SERV_HOST_ADDR =   "127.0.0.1";
int                     REQUESTED_TCP_PORT = 6500, ACTUAL_TCP_PORT;
int			MAX_PORT_RANGE = 100;
int                     N_REQUESTS = 10000;
int                     SLEEP = 0, SPIN= 0, N_CONSUMERS=10;
int                     PID;
thread_single_barrier_t client_barrier;
const char              *END_CLIENT_MSG = 
  "End\0                                                                   ";


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



/* Send out N_REQUESTS requests to server */
void *send_requests(void *arg) {
  int            i, j, sockfd = (int) arg, err;
  char           obuf[MESSAGE_SIZE];
  char           *name = thread_name(pthread_self());

  set_up_signal_mask();
  printf("Client_%d[%s] \tSending %d requests on fd#%d...\n",
	 PID, name, N_REQUESTS, sockfd);
  for (j=0; j<N_REQUESTS; j++) {
    sprintf(obuf, "Client_%d[%s] Request: %d", PID, name, j);
    err=write(sockfd, obuf, MESSAGE_SIZE);
    if (err == -1) {
      printf("Write failed from Client_%d[%s]\n", PID, name);
      perror("");
      pthread_exit(NULL);
    }
    DEBUG(printf("Client_%d[%s] sent: '%s'\n", PID, name, obuf));
    delay(SLEEP, SPIN);
    if ((j%1000 == 0) && ! (j==0))
      printf("Client_%d[%s] \tSent %d requests on fd#%d.\n",
	     PID, name, j, sockfd);
  }
  err=write(sockfd, END_CLIENT_MSG, MESSAGE_SIZE);
  if (err == -1) {
    printf("Write END failed from Client_%d[%s]\n", PID, name);
    perror("");
    thread_single_barrier_post(&client_barrier);
    pthread_exit(NULL);
  }
  DEBUG(printf("Client_%d[%s] sent: '%s'\n", PID, name, END_CLIENT_MSG));
  printf("Client_%d[%s] \tDone sending on fd#%d.\n", PID, name, sockfd);
}


/* Listen to replies until "End" */
void *receive_replies(void *arg) {
  int                    i, j, socket = (int) arg;
  struct sockaddr_in     serv_addr;
  char                   ibuf[MESSAGE_SIZE];
  char                   *name = thread_name(pthread_self());

  set_up_signal_mask();
  printf("Client_%d[%s] \tReceiving replies on fd#%d...\n",
	 PID, name, socket);

  for (j=1; TRUE; j++) {
    int         nRead, totalRead, nZeros=0;

    for (totalRead = 0; totalRead < MESSAGE_SIZE; ) {
      nRead = read(socket, &ibuf[totalRead], MESSAGE_SIZE-totalRead);
      if (nRead <= 0) {
	if (nRead == 0) {
	  DEBUG(printf("Read zero from fd#%d\n", socket));
	  nZeros++;
	  if (nZeros < 5) continue;		/* Allow a few 0 reads */
	}
	printf("Read failed from Client_%d[%s] fd#%d!\n", PID, name, socket);
	perror("");
	abort();
      }
      nZeros=0;
      totalRead += nRead;
      DEBUG(printf("Read %d, Total Read: %d\n", nRead, totalRead));
    }
    DEBUG(printf("Client_%d[%s] received: '%s'\n", PID, name, ibuf));

    if (strncmp(ibuf, END_CLIENT_MSG, 3) == 0) break;
    if ((j%1000 == 0) && ! (j==0))
      printf("Client_%d[%s] \tReceived %d replies on fd#%d.\n",
             PID, name, j, socket);
  }

  close(socket);
  if (j < N_REQUESTS)
    printf("Client_%d[%s] \tDone receiving on fd#%d.\
Server dropped %d requests!\n",
	   PID, name, socket, N_REQUESTS-j);
  else
    printf("Client_%d[%s] \tDone receiving on fd#%d.\n", PID, name, socket);
  thread_single_barrier_post(&client_barrier);
}


int open_a_socket() {
  struct sockaddr_in     serv_addr;
  int sockfd, j;

  for (j=REQUESTED_TCP_PORT; j<REQUESTED_TCP_PORT+MAX_PORT_RANGE;j++) {
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
      {perror("clientsoc: can't open stream socket "); abort();}
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERV_HOST_ADDR);
    serv_addr.sin_port = htons(j);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
      {
	DEBUG(printf("Can't connect to server on port %d\n", j));
	close(sockfd);
      }
    else
      break;
    if (j==REQUESTED_TCP_PORT+MAX_PORT_RANGE-1) { /* Maybe server was down? */
      printf("Maybe server was down? Starting again...\n");
      j=REQUESTED_TCP_PORT-1;
      sleep(5);	/* Don't rush. Let the server restart */
    }
  }
  ACTUAL_TCP_PORT=j;
  return(sockfd);
}


main(int argc, char **argv) {
  int                    i, j, sockfd, N_SOCKETS = 1;
  pthread_attr_t         attr;
  pthread_t              tid;
  struct rlimit		r;


  PID = getpid();
  if (argc > 1) REQUESTED_TCP_PORT = atoi(argv[1]);
  if (argc > 2) SLEEP = atoi(argv[2]);
  if (argc > 3) SPIN = atoi(argv[3]);
  if (argc > 4) N_SOCKETS = atoi(argv[4]);
  if (argc > 5) N_REQUESTS = atoi(argv[5]);
  if (N_SOCKETS > MAX_FDS)
      printf("No more than %d connections allowed!\n", MAX_FDS), abort();
  printf("Client_%d(PORT %d SLEEP %dms SPIN %dus N_SOCKETS %d \
N_REQUESTS %d)\n", 
	 PID, REQUESTED_TCP_PORT, SLEEP, SPIN, N_SOCKETS, N_REQUESTS);



  getrlimit(RLIMIT_NOFILE, &r);
  r.rlim_cur=MAX_FDS+10;
  setrlimit(RLIMIT_NOFILE, &r);
  /*  printf("Current limit: %d Max limit: %d\n", r.rlim_cur, r.rlim_max); */
  set_up_signal_mask();


  PTHREAD_ATTR_INIT(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
  thread_single_barrier_init(&client_barrier, N_SOCKETS);

  iobench_start();

  for (i=0; i < N_SOCKETS; i++) {   
    sockfd=open_a_socket();
    printf("Connected to server on port %d\n", ACTUAL_TCP_PORT);
    PTHREAD_CREATE(&tid, &attr, send_requests, (void *) sockfd);
    PTHREAD_CREATE(&tid, &attr, receive_replies, (void *) sockfd);
  }

  thread_single_barrier_wait(&client_barrier);
  iobench_end();
  iobench_report();
  exit(NULL);
}
