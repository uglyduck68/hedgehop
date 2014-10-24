/*                test_fifo_mutex.c                */

/*
cc -o test_fifo_mutex test_fifo_mutex.c -L. -R. -g -lpthread -lthread -thread_extensions -lposix4
*/



#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"



thread_fifo_mutex_t mf = THREAD_FIFO_MUTEX_INITIALIZER;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER ;



void *test_fifo(void *arg)
{int i = (int) arg;
 pthread_t tid = pthread_self();
 char *name = thread_name(tid);

 for (i=0; i<5; i++)
   {thread_fifo_mutex_lock(&mf);
    delay(10, 0);
    printf("%s in critical section (FIFO)\n", name);
    thread_fifo_mutex_unlock(&mf);
  }
 return;
}


void *test_mutex(void *arg)
{int i = (int) arg;
 pthread_t tid = pthread_self();
 char *name = thread_name(tid);

 for (i=0; i<5; i++)
   {pthread_mutex_lock(&m);
    delay(10, 0);
    printf("%s in critical section (mutex)\n", name);
    pthread_mutex_unlock(&m);
  }
 return;
}


main(int argc, char **argv)
{int i;
 pthread_attr_t attr;
 pthread_t tid;


 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

 PTHREAD_CREATE(&tid, &attr, test_mutex, NULL);
 PTHREAD_CREATE(&tid, &attr, test_mutex, NULL);
 PTHREAD_CREATE(&tid, &attr, test_mutex, NULL);
 PTHREAD_CREATE(&tid, &attr, test_mutex, NULL);
 sleep(1);      /* Cheap! But sufficent for a quick test */
 PTHREAD_CREATE(&tid, &attr, test_fifo,  NULL);
 PTHREAD_CREATE(&tid, &attr, test_fifo,  NULL);
 PTHREAD_CREATE(&tid, &attr, test_fifo,  NULL);
 PTHREAD_CREATE(&tid, &attr, test_fifo,  NULL);

 pthread_exit(0);
}
