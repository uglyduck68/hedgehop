/*                test_recursive_mutex.c                */

/*

  Test your recursive mutex.  Replace "thread_recursive_mutex" with
  "my_thread_recursive_mutex", then write it!

*/


/*
cc -o test_recursive_mutex test_recursive_mutex.c -L. -R. -g -lpthread -lthread -thread_extensions -lposix4
*/

#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"

typedef struct {
  pthread_mutex_t       lock;           /* lock for structure */
  pthread_cond_t        cv;             /* waiting list control */
  pthread_t             owner;          /* NULL_TID or TID */
} my_thread_recursive_mutex_t;


char *s[6] = {"", "*", "**", "***", "****", "*****"};


thread_recursive_mutex_t m;


void *recursive(void *arg)
{int            i = (int) arg;
 pthread_t      tid = pthread_self();
 char           *name = thread_name(tid);

 
 if (i > 0)
   {printf("%s Trying to enter level %d \t%s\n", name, 6-i, s[6-i]);
    thread_recursive_mutex_lock(&m);
    printf("%s Entered         level %d \t%s\n", name, 6-i, s[6-i]);
    delay(200, 0);
    recursive((void *)(i-1));
    thread_recursive_mutex_unlock(&m);
    printf("%s Leaving         level %d \t%s\n", name, 6-i, s[6-i]);
  }
 return;
}


main(int argc, char **argv)
{int                    i;
 pthread_attr_t         attr;
 pthread_t              tid;

 thread_recursive_mutex_init(&m, NULL);

 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

 PTHREAD_CREATE(&tid, &attr, recursive, (void *) 5);
 PTHREAD_CREATE(&tid, &attr, recursive, (void *) 5);
 PTHREAD_CREATE(&tid, &attr, recursive, (void *) 5);

 pthread_exit(0);
}
