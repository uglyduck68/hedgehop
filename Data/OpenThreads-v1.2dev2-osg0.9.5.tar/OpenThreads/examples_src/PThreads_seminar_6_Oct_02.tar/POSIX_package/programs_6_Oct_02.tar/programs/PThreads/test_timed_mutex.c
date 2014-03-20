/*                test_timed_mutex.c                */

/*
*/


/*
cc -o test_timed_mutex test_timed_mutex.c -L. -R. -g -lpthread -lthread -lthread_extensions -lposix4
*/

#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"



thread_timed_mutex_t m;
struct timespec abstime;

void *timed(void *arg)
{int err, i = (int) arg;
 pthread_t tid = pthread_self();
 char *name = thread_name(tid);

 sleep(i);
 printf("%s trying to acquire mutex after sleeping %d sec.\n",
        name, i);
 err=thread_timed_mutex_lock(&m, &abstime);
 if (err)
   if (err==ETIMEDOUT)
     {printf("%s timed out!\n", name);
      pthread_exit(NULL);
    }
   else
     {printf("%s error: %s!\n", name, strerror(err));
      pthread_exit(NULL);
    }
 
 printf("%s acquired mutex.\n", name);
 sleep(2);
 printf("%s releasing mutex.\n", name);
 thread_timed_mutex_unlock(&m);
 pthread_exit(NULL);
}


main(int argc, char **argv)
{int i;
 pthread_attr_t attr;

 thread_timed_mutex_init(&m, NULL);
 clock_gettime(CLOCK_REALTIME, &abstime);
 abstime.tv_sec += 6;
 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

 PTHREAD_CREATE(NULL, &attr, timed, (void *) 0);
 PTHREAD_CREATE(NULL, &attr, timed, (void *) 1);
 PTHREAD_CREATE(NULL, &attr, timed, (void *) 1);
 PTHREAD_CREATE(NULL, &attr, timed, (void *) 1);
 PTHREAD_CREATE(NULL, &attr, timed, (void *) 1);

 pthread_exit(0);
}
