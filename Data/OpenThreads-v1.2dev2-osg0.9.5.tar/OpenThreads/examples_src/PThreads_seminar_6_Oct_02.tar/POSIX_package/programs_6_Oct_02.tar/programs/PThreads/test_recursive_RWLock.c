/*                test_recursive_RWLock.c                */
 

/*
cc -o test_recursive_mutex test_recursive_mutex.c -L. -R. -g -lpthread -lthread -thread_extensions -lposix4
*/

#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h" 

char *s[6] = {"", "*", "**", "***", "****", "*****"};


thread_rrwlock_t m;


void *recursive_wr(void *arg)
{int            i = (int) arg;
 pthread_t      tid = pthread_self();
 char           *name = thread_name(tid);

 
 if (i > 0)
   {printf("%s Trying to enter write level %d \t%s\n", name, 6-i, s[6-i]);
    thread_rrw_wrlock(&m);
    printf("%s Entered         write level %d \t%s\n", name, 6-i, s[6-i]);
    delay(200, 0);
    recursive((void *)(i-1));
    thread_rrw_unlock(&m);
    printf("%s Leaving         write level %d \t%s\n", name, 6-i, s[6-i]);
  }
 return;
}

void *recursive_rd(void *arg)
{int            i = (int) arg;
 pthread_t      tid = pthread_self();
 char           *name = thread_name(tid);

 
 if (i > 0)
   {printf("%s Trying to enter read level %d \t%s\n", name, 6-i, s[6-i]);
    thread_rrw_rdlock(&m);
    printf("%s Entered         read level %d \t%s\n", name, 6-i, s[6-i]);
    delay(200, 0);
    recursive((void *)(i-1));
    thread_rrw_unlock(&m);
    printf("%s Leaving         read level %d \t%s\n", name, 6-i, s[6-i]);
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

 PTHREAD_CREATE(&tid, &attr, recursive_rw, (void *) 5);
 PTHREAD_CREATE(&tid, &attr, recursive_rw, (void *) 5);
 PTHREAD_CREATE(&tid, &attr, recursive_rw, (void *) 5);
 PTHREAD_CREATE(&tid, &attr, recursive_rd, (void *) 5);
 PTHREAD_CREATE(&tid, &attr, recursive_rd, (void *) 5);
 PTHREAD_CREATE(&tid, &attr, recursive_rd, (void *) 5);
 sleep(20);
 PTHREAD_CREATE(&tid, &attr, recursive_rw, (void *) 5);

 pthread_exit(0);
}
