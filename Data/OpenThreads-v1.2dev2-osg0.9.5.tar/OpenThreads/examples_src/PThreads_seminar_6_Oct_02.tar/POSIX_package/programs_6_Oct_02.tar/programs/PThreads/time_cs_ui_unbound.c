/*                time_cs_ui_unbound.c                */

/*
cc -o time_cs_ui_unbound time_cs_ui_unbound.c -L. -R. -fast -lthread
*/

#define _REENTRANT

#include <thread.h>
#include <errno.h>

int N=1000;
int a;
sem_t barrier;

void *f1(void *arg)
{int i;
 for (i=0; i<N; i++)
   {
     thr_yield();
     a++;
   }
 sem_post(&barrier);
}

main(int argc, char **argv)
{int i;
 thread_t tid;

 
 SEM_INIT(&barrier, 0, 0);
 
 if (argc >= 2) N = atoi(argv[1]);
 if (N>=1000000)
   printf("\n\nRunning %s for %dm iterations\n", argv[0], N/1000000);
 else
   printf("\n\nRunning %s for %dk iterations\n", argv[0], N/1000);

 iobench_start();
 thr_create(NULL, NULL, f1, 0, NULL, NULL);
 thr_create(NULL, NULL, f1, 0, NULL, NULL);
   
 thread_single_barrier(&barrier, 2);

 iobench_end();
 iobench_report();
 thr_exit(0);
}

