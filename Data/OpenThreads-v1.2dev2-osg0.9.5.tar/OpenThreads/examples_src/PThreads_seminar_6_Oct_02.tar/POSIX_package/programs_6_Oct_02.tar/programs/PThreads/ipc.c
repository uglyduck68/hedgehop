/*                ipc.c                */

/*
  Create a shared memory segment for parent and child, place a counter
  in with associated CV & mutex, then spawn the child.  Count up to
  five in the parent, waiting in the child to decrement it back down.

  A couple of calls to sleep() keep things running slow enough to 
  observe what's going on.

  Note that if N>1 and the parent is fast, that buf->done will get
  set before child has processed everything.
*/
/*
cc -o ipc ipc.c -L. -R. -g -lpthread -lthread -lthread_extensions -lposix4
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include "thread_extensions.h"

#ifndef _POSIX_THREAD_PROCESS_SHARED
COMPILE_FAILED "_POSIX_THREAD_PROCESS_SHARED not defined!  This program won't run!"
#endif

/* a structure that will be used between processes */
typedef struct {
        pthread_cond_t parent_cv;
        pthread_cond_t child_cv;
        pthread_mutex_t lock;
        int messages_pending;
        int parent_done;
} buf_t;

buf_t   *buf;
int C_SLEEP = 1, P_SLEEP = 2, N = 1;


my_child()
 {int   i, j, fd, *count, done=0;

    for (i=1;;i++)
      {printf("Child PID(%d): waiting...\n", getpid());

       pthread_mutex_lock(&buf->lock);
       while (buf->messages_pending == 0) 
         pthread_cond_wait(&buf->child_cv, &buf->lock);

       buf->messages_pending--;
       printf("Child PID(%d): received message %d.\n", getpid(), i);

       done = buf->parent_done;
       pthread_mutex_unlock(&buf->lock);
       pthread_cond_signal(&buf->parent_cv);
       sleep(C_SLEEP);  /* wait a second to make it more interesting*/
       if (done)
         {printf("Child PID(%d): exiting...\n", getpid());
          exit(0);
        }
     }
  }

my_parent()
 {int   i;

  for (i=0;i<5;i++)
    {pthread_mutex_lock(&buf->lock);
                /* Never more than N msgs pending. */
     while (buf->messages_pending >= N)
       pthread_cond_wait(&buf->parent_cv, &buf->lock);
     buf->messages_pending++;   /* increment the counter */
     printf("Parent PID(%d): sending message %d.\n", getpid(), i+1);
     if (i == 4) buf->parent_done = 1;
     pthread_mutex_unlock(&buf->lock);
     pthread_cond_signal(&buf->child_cv);
         
     sleep(P_SLEEP);    /* wait a second to make it more interesting*/
   }

  printf("Parent PID(%d): exiting...\n", getpid());
  exit(0);
}


main(int argc, char *argv[])
{int fd;
 pthread_condattr_t cond_attr;
 pthread_mutexattr_t mutex_attr;

 /* open a file to use in a memory mapping */
 fd = open("/dev/zero", O_RDWR);

 /* Create a shared memory map with the open file for the data 
    structure which will be shared between processes. */

 buf=(buf_t *)mmap(NULL, sizeof(buf_t), PROT_READ|PROT_WRITE,
                   MAP_SHARED, fd, 0);

 /* Initialize the counter and SVs.  PTHREAD_PROCESS_SHARED makes
    them visible to both processes. */


 PTHREAD_MUTEXATTR_INIT(&mutex_attr);
 pthread_mutexattr_setpshared(&mutex_attr, PTHREAD_PROCESS_SHARED);

 PTHREAD_CONDATTR_INIT(&cond_attr);
 pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED);

 pthread_cond_init(&buf->parent_cv, &cond_attr);
 pthread_cond_init(&buf->child_cv, &cond_attr);
 pthread_mutex_init(&buf->lock, &mutex_attr);
 buf->messages_pending = 0;
 buf->parent_done = 0;


 if (argc >= 2) P_SLEEP = atoi(argv[1]);
 if (argc >= 3) C_SLEEP = atoi(argv[2]);
 if (argc >= 4) N       = atoi(argv[3]);
 printf("P_SLEEP=%d C_SLEEP=%d N=%d\n", P_SLEEP, C_SLEEP, N);

 if (fork() == 0)
   my_child();
 else
   my_parent();
}
