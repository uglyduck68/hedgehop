/*                time_cs_bound.c                */

/*
cc -o time_cs_bound time_cs_bound.c -L. -R. -fast -lpthread -lthread -lthread_extensions -lposix4
*/

#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"

int N=1000;
sem_t barrier;

void *f1(void *arg)
{int i;
 for (i=0; i<N; i++)
   {
     sched_yield();
   }
 sem_post(&barrier);
}

main(int argc, char **argv)
{int i;
 pthread_attr_t attr;
 pthread_t tid;

 SEM_INIT(&barrier, 0, 0);
 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
 
 if (argc >= 2) N = atoi(argv[1]);
 if (N>=1000000)
     printf("\n\nRunning %s for %dm iterations\n", argv[0], N/1000000);
 else
     printf("\n\nRunning %s for %dk iterations\n", argv[0], N/1000);

 iobench_start();
 PTHREAD_CREATE(&tid, &attr, f1, NULL);
 PTHREAD_CREATE(&tid, &attr, f1, NULL);
 thread_single_barrier(&barrier, 2);

 iobench_end();
 iobench_report();
 pthread_exit(0);
}

