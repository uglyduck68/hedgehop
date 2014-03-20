/*                tmp.c                */

/*
  A simple server program.  It sets up a TCP port for the client
  program to connect to.

  This version is really just a producer/consumer program that happens
  to run across a socket.  Scope is SYSTEM global.

cc -o tmp tmp.c -L. -R. -g -lpthread -lthread -lthread_extensions -lposix4 -lnsl -lsocket
*/

/* Note that you need to define  __EXTENSIONS__ when using sockets. */
#define _POSIX_C_SOURCE 199506L 
#define __EXTENSIONS__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/uio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include "thread_extensions.h"


struct request_struct
{int                    socket_fd;
 char                   *buf;
 pthread_t              tid;
 struct request_struct  *next;
};
typedef struct request_struct request_t;

pthread_mutex_t         requests_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_attr_t          attr;
int                     TCP_PORT = 6500;
int                     SLEEP = 10;
int                     SPIN = 0;
int                     N_THREADS = 10;
sem_t                   requests_slots, requests_length;
request_t               *requests=NULL;
const int               MESSAGE_SIZE = 70;
const char              *END =
  "End\0                                                                   ";



main(int argc, char **argv)
{int i ;
  
i = pthread_mutex_lock(&requests_lock);
  printf("%d\n", i);

  
}
