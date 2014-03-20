/*                false_sharing.c                */

/*
  Demonstrates what NOT to do on an MP.  If SEPARATION = 1, then there will be
  horrible false sharing and the machine will crawl.  If SEPARATION = 16
  then there will be no false sharing and the program will run about 10x
  faster.
*/


#define _POSIX_C_SOURCE 199506L 

#include <pthread.h>
#include <semaphore.h>
#include "thread_extensions.h"


int             AVOCADOS_NUMBER = 6023500;
int             N_CPUS = 4;
int             SEPARATION = 16; /* 8 64-bit words per cache-line on Ultra SPARC */
sem_t           exit_barrier;
int             a[128];
pthread_attr_t  attr;


void *worker(void *arg)
{int            index = (int) arg;
 int            i;

 for (i=0; i<AVOCADOS_NUMBER; i++)
   {a[index]++;}

 sem_post(&exit_barrier);
}

main(int argc, char **argv)
{int            i, j;
 pthread_t      tid;

 if (argc >= 2) N_CPUS = atoi(argv[1]);
    
 printf("N_CPUS = %d \n \n", N_CPUS);

 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
 SEM_INIT(&exit_barrier, 0, 0);

 for (j=1;j<17;j+=j)
   {
     SEPARATION=j;
     printf("SEPARATION = %d\n", SEPARATION);
     iobench_start();
     for (i=0;i<N_CPUS;i++)
       PTHREAD_CREATE(&tid, &attr, worker, (void *) (i * SEPARATION));
     
     thread_single_barrier(&exit_barrier, N_CPUS);
     iobench_end();
     iobench_report();
   }
     printf("Done\n");
     exit(0);
}
