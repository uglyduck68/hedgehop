/*
CC -o  subclass subclass.cc -L. -R. -D__sun -D__sun2_6 -g -lpthread -lthread -lposix4 -lthread_extensions
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


void *foo(void *arg);






class MyRunnable
{int value;

 public:
 MyRunnable(int v);
 void run();
};

MyRunnable::MyRunnable(int v)
{value = v;}

void MyRunnable::run()
{
  foo(1);
}



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



void bar(void)
{Monitor m(&mutex);
 int temp;

 temp = global;
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
