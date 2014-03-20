/*                time_reader.c                */

/*
cc -o time_reader time_reader.c -L. -R. -fast -lpthread -lthread -lthread_extensions -lposix4
*/


#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"

int N=100;
thread_rwlock_t m = THREAD_RWLOCK_INITIALIZER;

main(int argc, char **argv)
{int i;
 
 if (argc >= 2) N = atoi(argv[1]);
 if (N>=1000000)
     printf("\n\nRunning %s for %dm iterations\n", argv[0], N/1000000);
 else
     printf("\n\nRunning %s for %dk iterations\n", argv[0], N/1000);

 iobench_start();
 for (i=0; i<N; i++)
   {thread_rw_rdlock(&m);
    thread_rw_unlock(&m);
   }
 iobench_end();
 iobench_report();

 pthread_exit(0);
}
