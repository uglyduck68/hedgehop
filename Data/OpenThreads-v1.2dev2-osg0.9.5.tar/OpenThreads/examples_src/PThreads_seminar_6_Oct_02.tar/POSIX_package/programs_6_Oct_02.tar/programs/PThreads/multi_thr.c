/*                multi_thr.c                */

/*
  Simple program that just illustrates thread creation, thread exiting,
  waiting for threads, and returning status from threads.
*/

/*
cc -o multi_thr multi_thr.c -L. -R. -g -lpthread -lthread -pthread_extensions -lposix4
*/

#define _POSIX_C_SOURCE 199506L

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "thread_extensions.h"


/* Function prototypes for thread routines */
void *sub_a(void *);
void *sub_b(void *);
void *sub_c(void *);
void *sub_d(void *);
void *sub_e(void *);

pthread_t               tid_a, tid_b, tid_c, tid_d, tid_e, tid_main;
pthread_attr_t          attr;
int                     zero;
float                   f;


int time1()
{return(time(NULL)-zero);}


void *sub_a(void *arg)
{int            err, i;
 pthread_t      tid = pthread_self();

 printf("[%2d] A: \t In thread A [%s]\n", time1(), thread_name(tid));
 sleep(1);
 PTHREAD_CREATE(&tid_d, &attr, sub_d, NULL);
 printf("[%2d] A: \t Created thread D [%s]\n", time1(), thread_name(tid_d));

 sleep(3);
 printf("[%2d] A: \t Thread exiting...\n", time1());
 return((void *)77);            /* Same as pthread_exit((void *)77) */
}


void *sub_b(void *arg)
{pthread_t      tid = pthread_self();
 printf("[%2d] B: \t In thread B [%s]\n", time1(), thread_name(tid));

 sleep(4);

 printf("[%2d] B: \t Thread exiting...\n", time1());
 pthread_exit(NULL);
}


void *sub_c(void *arg)
{void           *status;
 int            err, i;

 pthread_t tid = pthread_self();
 pthread_t      *ptid = (pthread_t *) arg; /* Passing a POINTER to the TID */
 char           *name = thread_name(tid);

 printf("[%2d] C: \t In thread C [%s]\n", time1(), name);
 sleep(2);

 printf("[%2d] C: \t Joining main thread...\n", time1());
 if (err=pthread_join(*ptid, &status)) 
   printf("pthread_join Error. %s", strerror(err)), exit(1);
 printf("[%2d] C: \t Main thread [%s] returning status: %d\n",
        time1(), thread_name(*ptid), (int) status);

 sleep(1);

 PTHREAD_CREATE(&tid_b, &attr, sub_b, NULL);
 printf("[%2d] C: \t Created thread B [%s]\n", time1(), thread_name(tid_b));

 sleep(4);
 printf("[%2d] C: \t Thread exiting...\n", time1());
 f = 88.8;
 pthread_exit((void *) &f);
}

void *cleanup(void *arg)
{pthread_t tid = pthread_self();
 char *name = thread_name(tid);

  printf("[%2d] D: \t %s cancelled! \n", time1(), name);
}



void * sub_d(void *arg)
{int            err, i;
 pthread_t      tid_e;
 void           *status;
 pthread_t      tid = pthread_self();

 printf("[%2d] D: \t In thread D [%s]\n", time1(), thread_name(tid));

 pthread_cleanup_push(cleanup, NULL);
 pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
 pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

 sleep(1);
 PTHREAD_CREATE(&tid_e, &attr, sub_e, NULL);
 printf("[%2d] D: \t Created thread E [%s]\n", time1(), thread_name(tid_e));

 sleep(5);

        /* D should get cancelled before this runs. */
 printf("[%2d] D: \t Thread exiting...\n", time1());
 pthread_cleanup_pop(0);
 return((void *)55);
}


void * sub_e(void *arg)
{int            err, i;
 void           *status;
 pthread_t      tid = pthread_self();

 printf("[%2d] E: \t In thread E [%s]\n", time1(), thread_name(tid)); 

 sleep(3);
 printf("[%2d] E: \t Joining thread A...\n", time1());
 if (err=pthread_join(tid_a, &status)) 
   printf("pthread_join Error. %s", strerror(err)), exit(1);
 printf("[%2d] E: \t Thread A [%s] returning status: %d\n",
        time1(), thread_name(tid_a), (int) status);

 sleep(2);

 printf("[%2d] E: \t Joining thread C...\n", time1());
 if (err=pthread_join(tid_c, &status)) 
   printf("pthread_join Error. %s", strerror(err)), exit(1);
 printf("[%2d] E: \t Thread C [%s] returning status: %f\n",
        time1(), thread_name(tid_c), *((float *) status));

 sleep(2);
 printf("[%2d] E: \t Joining thread D...\n", time1());
 if (err=pthread_join(tid_d, &status)) 
   printf("pthread_join Error. %s", strerror(err)), exit(1);
 if ((void*) status == (void*) PTHREAD_CANCELED)
   printf("[%2d] E: \t Thread D [%s] returning status: PTHREAD_CANCELED\n",
          time1(), thread_name(tid_d));
 else
   printf("[%2d] E: \t Thread D [%s] returning status: %d\n",
          time1(), thread_name(tid_d), (int) status);

 sleep(1);
 printf("[%2d] E: \t Thread exiting...\n", time1());
 pthread_exit((void *)44);
}



main()
{int            err;

 zero = time(NULL);
 tid_main = pthread_self();
 printf("Time Thread \t Event\n");
 printf("==== ====== \t =====\n");
 printf("[%2d] Main: \t Started [%s]\n", time1(), thread_name(tid_main));

 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); /* Also default */

 sleep(1);
 PTHREAD_CREATE(&tid_a, &attr, sub_a, NULL);
 printf("[%2d] Main: \t Created thread A [%s]\n", time1(), thread_name(tid_a));

 sleep(1);
 PTHREAD_CREATE(&tid_c, &attr, sub_c, (void *) &tid_main);
 printf("[%2d] Main: \t Created thread C [%s]\n", time1(), thread_name(tid_c));

 sleep(2);
 printf("[%2d] Main: \t Cancelling thread D [%s]\n",
        time1(), thread_name(tid_d));
 pthread_cancel(tid_d);

 sleep(1);
 printf("[%2d] Main: \t Thread exiting...\n", time1());
 pthread_exit((void *) NULL);
}

