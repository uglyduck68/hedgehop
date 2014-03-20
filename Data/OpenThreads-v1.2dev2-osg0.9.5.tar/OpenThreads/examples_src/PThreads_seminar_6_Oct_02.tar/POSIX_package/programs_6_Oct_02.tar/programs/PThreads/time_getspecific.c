/*                time_getspecific.c                */

/*
cc -o time_getspecific time_getspecific.c -L. -R. -fast -lpthread -lthread -lthread_extensions -lposix4
*/

#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"

int N=100;
pthread_key_t key;

main(int argc, char **argv)
{int i, value;

 pthread_key_create(&key, NULL);
 if (argc >= 2) N = atoi(argv[1]);
 if (N>=1000000)
     printf("\n\nRunning %s for %dm iterations\n", argv[0], N/1000000);
 else
     printf("\n\nRunning %s for %dk iterations\n", argv[0], N/1000);
     pthread_setspecific(key, (void *) 1);

 iobench_start();
 for (i=0; i<N; i++)
   {
     value = (int) pthread_getspecific(key);
   }
 iobench_end();
 iobench_report();

 pthread_exit(0);
}

/*
On an US1 167MHz
$ time time_lock 10000000

real        7.6  --> .76us/lock,unlock
user        7.5
sys         0.0


*/

