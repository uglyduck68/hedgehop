/*                test_dmutex.c                */

/*
cc -o test_dmutex test_dmutex.c -L. -R. -g -lpthread -lthread -pthread_extensions -lposix4
*/


#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"


pthread_dmutex_t lock1, lock2, lock3, lock4;




void *test1(void *arg)
{int i = (int) arg;

 for (i=0; i<5; i++)
   {pthread_dmutex_lock(&lock1);
    delay(100, 0);
    printf("%s in critical section 1\n", thread_name(pthread_self()));
    print_dmutexes();
    pthread_dmutex_unlock(&lock1);
  }
 return;
}



void *test2(void *arg)
{int i = (int) arg;

 for (i=0; i<5; i++)
   {pthread_dmutex_lock(&lock1);
    delay(100, 0);
    printf("%s in critical section 2\n", thread_name(pthread_self()));
    print_dmutexes();
    pthread_dmutex_unlock(&lock1);
  }
 return;
}



void *test3(void *arg)
{int i = (int) arg;

 for (i=0; i<5; i++)
   {pthread_dmutex_lock(&lock3);
    delay(100, 0);
    printf("%s in critical section 3\n", thread_name(pthread_self()));
    print_dmutexes();
    pthread_dmutex_unlock(&lock3);
  }
 return;
}


main(int argc, char **argv)
{int i;
 pthread_attr_t attr;
 pthread_t tid;

 pthread_dmutex_init(&lock1, NULL);
 pthread_dmutex_init(&lock2, NULL);
 pthread_dmutex_init(&lock3, NULL);
 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

 PTHREAD_CREATE(&tid, &attr, test1,  NULL);
 PTHREAD_CREATE(&tid, &attr, test1,  NULL);
 PTHREAD_CREATE(&tid, &attr, test1,  NULL);
 PTHREAD_CREATE(&tid, &attr, test1,  NULL);
 PTHREAD_CREATE(&tid, &attr, test2,  NULL);
 PTHREAD_CREATE(&tid, &attr, test2,  NULL);
 PTHREAD_CREATE(&tid, &attr, test3,  NULL);
 PTHREAD_CREATE(&tid, &attr, test3,  NULL);
 PTHREAD_CREATE(&tid, &attr, test3,  NULL);

 sleep(5);
 printf("Now crash with a self-deadlock...\n");
 pthread_dmutex_lock(&lock3);
 pthread_dmutex_lock(&lock3);   /* Comment out this line for next error */
 printf("Now crash with a non-owner unlock...\n");
 pthread_dmutex_unlock(&lock1);

 pthread_exit(0);
}
