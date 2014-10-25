/*                test_forker.c                */

/*
cc -o test_forker test_forker.c -L. -R. -g -lpthread -lthread -lthread_extensions -lposix4
*/


#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"



void *test1(void *arg)
{int i, j = (int) arg;

 for (i=0; i<j; i++)
   {delay(500, 0);
    printf("%s running\n", thread_name(pthread_self()));
    thread_wait_for_forker();
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

 PTHREAD_CREATE(&tid, &attr, test1,  (void *)100);
 PTHREAD_CREATE(&tid, &attr, test1,  (void *)100);
 PTHREAD_CREATE(&tid, &attr, test1,  (void *)100);
 PTHREAD_CREATE(&tid, &attr, test1,  (void *)100);

 for (i=0; i<4; i++)
   {sleep(2);
    printf("About to fork...\n");
    thread_wait_for_others(4);
    printf("Forking...\n");
    sleep(2);
    thread_awake_others();
    printf("Post Fork.\n");
  }
}
