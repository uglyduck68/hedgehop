/*                time_create.c                */

/*
cc -o time_create time_create.c -L. -R. -fast -lpthread -lthread -pthread_extensions -lposix4
*/

#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"

int N=100000;

void *foo(void *arg)
{
  pthread_exit(0);
}


main(int argc, char **argv)
{int i;
 char *s;
 pthread_attr_t attr;
 pthread_t tid;

 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
 
 if (argc >= 2) N = atoi(argv[1]);
 if (argc >= 3)
   {pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
    s = "(bound)";
  }
 else
   {pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS);
    s = "(unbound)";
  }
 if (N>=1000000)
     printf("\n\nRunning %s %s for %dm iterations\n", argv[0], s, N/1000000);
 else
     printf("\n\nRunning %s %s for %dk iterations\n", argv[0], s, N/1000);


 iobench_start(); for (i=0; i<N; i++)
   {PTHREAD_CREATE(&tid, &attr, foo, NULL);
    pthread_join(tid, NULL);
  }
 iobench_end();
 iobench_report();
 pthread_exit(0);
}

