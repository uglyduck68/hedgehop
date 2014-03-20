/*
CC -o mutex mutex.cc -L. -R. -g -lpthread -lposix4 -lthread_extensions
*/


#define _POSIX_C_SOURCE 199506L
#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include "thread_extensions.h"


int global = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


class Monitor
{pthread_mutex_t *mutex;

 public:
 Monitor(pthread_mutex_t *m);
 virtual ~Monitor();
};


// Monitor constructor
Monitor::Monitor(pthread_mutex_t *m)
{mutex = m;
 pthread_mutex_lock(mutex);
}


// Monitor destructor
Monitor::~Monitor()
{pthread_mutex_unlock(mutex);}


/* sleep time will be quantized at 10ms, CPU time is VERY approximate. */
void delay(int sleep_ms, int cpu_us)
{int i;
 struct timespec tv;

 if (sleep_ms == 0 && cpu_us == 0) return;
 tv.tv_sec = sleep_ms/1000;
 tv.tv_nsec = (sleep_ms%1000) * 1000000;
 nanosleep(&tv, NULL);

 for (i=0; i<cpu_us*10; i++) ;
}



void bar(void)
{Monitor m(&mutex);
 int temp;

 temp = global;
 delay(10, 0);
 printf("T@%d %d == %d\n", pthread_self(), temp, global);
 global = temp+1;

 /* Now the destructor gets called to unlock the mutex */
}


void *foo(void *arg)
{int i;

 for (i=0; i< 5; i++)
   {bar();
  }
 return(NULL);
}


void baz(void)
{
 int temp;

 temp = global;
 delay(10, 0);
 printf("T@%d %d == %d\n", pthread_self(), temp, global);
 global = temp+1;

 /* Now the destructor gets called to unlock the mutex */
}


void *boo(void *arg)
{int i;

 for (i=0; i< 5; i++)
   {baz();
  }
 return(NULL);
}


main()
{int i;
 pthread_attr_t attr;
 pthread_t tid1, tid2;

 pthread_attr_init(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

 printf("This is how it works WITH the monitor...\n");
 pthread_create(&tid1, &attr, foo, NULL);
 pthread_create(&tid2, &attr, foo, NULL);
 pthread_join(tid1, NULL);
 pthread_join(tid2, NULL);
 
 printf("This is how it fails WITHOUT the monitor...\n");
 pthread_create(&tid1, &attr, boo, NULL);
 pthread_create(&tid2, &attr, boo, NULL);
 
 pthread_join(tid1, NULL);
 pthread_join(tid2, NULL);
 pthread_exit(NULL);
}
