/*                test_barrier.c                */

/*
*/


/*
cc -o test_barrier test_barrier.c -L. -R. -g -lpthread -lthread -lthread_extensions -lposix4
*/

#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"



thread_barrier_t barrier;


void *foo(void *arg)
{int i = (int) arg;
 pthread_t tid = pthread_self();
 char *name = thread_name(tid);

 printf("%s entering level %d\n", name, i);

 thread_barrier_wait(&barrier);
 printf("%s leaving level %d\n", name, i);
 return;
}


main(int argc, char **argv)
{int i, j, N = 4;
 pthread_attr_t attr;
 pthread_t tid;

 thread_barrier_init(&barrier, N);

 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

 for (i = 0; i < N; i++)
   {for (j = 0; j < N-1; j++)
      PTHREAD_CREATE(&tid, &attr, foo, (void *) 3);
    thread_barrier_wait(&barrier);
  }

 pthread_exit(0);
}
