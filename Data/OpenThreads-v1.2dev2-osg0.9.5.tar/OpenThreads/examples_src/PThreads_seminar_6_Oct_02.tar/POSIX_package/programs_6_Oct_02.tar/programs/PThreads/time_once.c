/*                time_once.c                */

 /*
cc -o time_once time_once.c -L. -R. -lpthread -lthread -lthread_extensions -lposix4 -fast
*/

#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"

int N=100;
int a[1000];

pthread_once_t once = PTHREAD_ONCE_INIT;
int done = FALSE;


void init(void)
{
  printf("Initializing...\n");
  done = TRUE;
}

main(int argc, char **argv)
{int i,  use_done = 0;
 char *s;

 if (argc >= 2) N = atoi(argv[1]);
 if (argc >= 3) use_done = atoi(argv[2]);
 if (use_done)
   s = "with";
 else
   s = "without";
   
 if (N>=1000000)
   printf("\n\nRunning %s (%s done) for %dm iterations\n",
          argv[0], s, N/1000000);
 else
   printf("\n\nRunning %s (%s done) for %dk iterations\n",
          argv[0], s, N/1000);

 iobench_start();
 if (use_done)
   for (i=0; i<N; i++)
     {if (!done)
       pthread_once(&once, init);     
     }
 else
   for (i=0; i<N; i++)
     {pthread_once(&once, init);     
     }
 iobench_end();
 iobench_report();

 pthread_exit(0);
}

