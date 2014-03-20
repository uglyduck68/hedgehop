/*                client_dirty.c                */

/*
  The client side simply sends a hugh number of requests to the
  chosen server as fast as possible, spawing one thread to do the
  sending and another to receive the replies.

  Nothing interesting here.


cc -o client client.c -L. -R. -g -lpthread -lthread -pthread_extensions -lposix4 -lnsl -lsocket
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
#include "thread_extensions.h"


/* 127.0.0.1 is the loopback address.  You may change it. */
const char      *SERV_HOST_ADDR =   "127.0.0.1";
int             TCP_PORT = 6500;
int             N_REQUESTS = 10000;
int             SLEEP = 0, SPIN= 0, N_CONSUMERS=10;
int             PID;
int             KILLER_SLEEP = 10;
const int       MESSAGE_SIZE = 70;
const char      *END = 
  "End\0                                                                   ";
thread_single_barrier_t client_barrier;


/* Send out 10,000 segments */
void *send_requests(void *arg)
{int i, j, sockfd = (int) arg;
 char obuf[100], ibuf[100];
 char *name = thread_name(pthread_self());

 printf("Client_%d[%s] \tSending %d requests on #%x...\n", PID, name, N_REQUESTS, sockfd);
 for (j=0; j<N_REQUESTS; j++)
   {sprintf(obuf, "Client_%d[%s] Request: %d", PID, name, j);
   write(sockfd, obuf, MESSAGE_SIZE);
   DEBUG(printf("Client_%d[%s] sent: '%s'\n", PID, name, obuf));
   delay(SLEEP, SPIN);
   if ((j%1000 == 0) && ! (j==0))
     printf("Client_%d[%s] \tSent %d segments on #%x.\n", PID, name, j, sockfd);
   }
 write(sockfd, END, MESSAGE_SIZE);
 printf("Client_%d[%s] \tDone sending on #%x.\n", PID, name, sockfd);
}

/* Listen to segments until "End" */
void *receive_replies(void *arg)
{int i, j, sockfd = (int) arg;
 struct sockaddr_in serv_addr;
 char obuf[100], ibuf[100];
 char *name = thread_name(pthread_self());

 printf("Client_%d[%s] \tReceiving segments on #%x...\n", PID, name, sockfd);

 for (j=1; 1; j++)
   {int         nbytes;

    nbytes = read(sockfd, ibuf, MESSAGE_SIZE);
    if (nbytes < 0) {perror("Read failed!\n"); abort();}
    if (nbytes != MESSAGE_SIZE)
      {printf("Read failed! Read: %d bytes:\n %s", nbytes, ibuf);
      abort();}

    if (strncmp(ibuf, END, 3) == 0) break;
    if ((j%1000 == 0) && ! (j==0))
      printf("Client_%d[%s] \tReceived %d segments on #%x.\n",
             PID, name, j, sockfd);
    DEBUG(printf("Client_%d[%s] Got: '%s'\n", PID, name, ibuf));
  }
 close(sockfd);
 if (j < N_REQUESTS)
   printf("Client_%d[%s] \tDone receiving on #%x. Server dropped %d requests!\n", PID,
          name, N_REQUESTS-j, sockfd);
 else
    printf("Client_%d[%s] \tDone receiving on #%x.\n", PID, name, sockfd);
 thread_single_barrier_post(&client_barrier);
}


main(int argc, char **argv)
{int i, j, sockfd, N_SOCKETS = 1;
 pthread_attr_t attr;
 struct sockaddr_in serv_addr;
 pthread_t tid;


 PID = getpid();
 if (argc > 1) TCP_PORT = atoi(argv[1]);
 if (argc > 2) SLEEP = atoi(argv[2]);
 if (argc > 3) SPIN = atoi(argv[3]);
 if (argc > 4) N_SOCKETS = atoi(argv[4]);
 if (argc > 5) N_REQUESTS = atoi(argv[5]);
 if (argc > 6) KILLER_SLEEP = atoi(argv[6]);
 printf("Client_%d(TCP_PORT %d SLEEP %dms SPIN %dus N_SOCKETS %d N_REQUESTS %d\n", 
        PID, TCP_PORT, SLEEP, SPIN, N_SOCKETS, N_REQUESTS);


 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
 thread_single_barrier_init(&client_barrier, N_SOCKETS);

 memset((char *) &serv_addr, 0, sizeof(serv_addr));
 serv_addr.sin_family = AF_INET;
 serv_addr.sin_addr.s_addr = inet_addr(SERV_HOST_ADDR);
 serv_addr.sin_port = htons(TCP_PORT);

    if (KILLER_SLEEP > 0)
      PTHREAD_CREATE(&tid, &attr, killer, (void *) KILLER_SLEEP);

 iobench_start();

 for (i=0; i < N_SOCKETS; i++)
   {if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
      {perror("clientsoc: can't open stream socket"); exit(0);}
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
      perror("Can't connect to server"), exit(0);

    PTHREAD_CREATE(&tid, &attr, send_requests, (void *) sockfd);
    PTHREAD_CREATE(&tid, &attr, receive_replies, (void *) sockfd);
    }

 thread_single_barrier_wait(&client_barrier);
 iobench_end();
 iobench_report();
 exit(NULL);
}
