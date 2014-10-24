/*                time_signal.c                */

/*
cc -o time_signal time_signal.c -L. -R. -fast -lpthread -lthread -lthread_extensions -lposix4
*/

#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"

int N=100;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

main(int argc, char **argv)
{int i;
 pthread_cond_t cv =  PTHREAD_COND_INITIALIZER;
 
 if (argc >= 2) N = atoi(argv[1]);
 if (N>=1000000)
     printf("\n\nRunning %s for %dm iterations\n", argv[0], N/1000000);
 else
     printf("\n\nRunning %s for %dk iterations\n", argv[0], N/1000);
 iobench_start();
 for (i=0; i<N; i++)
   {
     pthread_cond_signal(&cv);
   }

 iobench_end();
 iobench_report();

 pthread_exit(0);
}

/*
On a 110MHz SS4
$ time_signal 10000000

Running time_signal for 10m iterations

  CPU time      2.19567

*/

