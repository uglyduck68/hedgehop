/*                time_cs_sema.c                */

/*
cc -o time_cs time_cs.c -L. -R. -fast -lpthread -lthread -lthread_extensions -lposix4
*/

#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"

int N=1000;
sem_t                   s1, s2;
sem_t barrier;

void *f1(void *arg)
{int i;
 for (i=0; i<N; i++)
   {
     sem_post(&s1);
     SEM_WAIT(&s2);
   }
  pthread_exit(0);
}

void *f2(void *arg)
{int i;
 for (i=0; i<N; i++)
   {
     SEM_WAIT(&s1);
     sem_post(&s2);
   }
 sem_post(&barrier);
  pthread_exit(0);
}


main(int argc, char **argv)
{int i;
 pthread_attr_t attr;

 SEM_INIT(&s1, NULL, 1000);
 SEM_INIT(&s2, NULL, 1000);
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
 PTHREAD_CREATE(NULL, &attr, f1, NULL);
 PTHREAD_CREATE(NULL, &attr, f2, NULL);
   
 thread_single_barrier(&barrier, 2);

 iobench_end();
 iobench_report();
 pthread_exit(0);
}


/*
On an US1 167MHz

time time_cs 1000000

real     1:45.2  == 105 sec/10^6  --> 52us/context switch
user       49.8
sys        54.0
*/

 
