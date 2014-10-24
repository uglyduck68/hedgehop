/*                word_tearing.c                */

/*
  Demonstrates what NOT to do on an MP.  
*/


#define _POSIX_C_SOURCE 199506L 

#include <pthread.h>
#include <semaphore.h>
#include "thread_extensions.h"


char c1, c2;
sem_t exit_barrier;
pthread_attr_t attr;

void *worker(void *arg)
{char c;
 c = c1; 
 c1 = 'a';

 sem_post(&exit_barrier);
}

main(int argc, char **argv)
{int i;
 pthread_t tid;


 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
 SEM_INIT(&exit_barrier, 0, 0);

   PTHREAD_CREATE(&tid, &attr, worker, NULL);

 thread_single_barrier(&exit_barrier, 1);
}
