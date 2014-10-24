/*                stack_solution.c                */

/*

*/

#define _POSIX_C_SOURCE 199506L


#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"

pthread_attr_t attr;
pthread_t foo_tid;



void *baz(void *arg)
{char s[100];

 strcpy(s, "It's a crying shame!");
 pthread_exit(0);
}


void *bar(void *arg)
{char *s = (char *) arg;
 pthread_t tid;
 
 pthread_join(foo_tid, NULL);
 printf("First attempt: %s\n",s);
 PTHREAD_CREATE(&tid, &attr, baz, NULL);
 printf("Second attempt: %s\n",s);
 pthread_join(tid, NULL);
 printf("Third attempt: %s\n",s);
}

void *foo(void *arg)
{pthread_t tid;
 char *s = (char *) malloc(100);

 strcpy(s, "It's a wonderful world!");
 PTHREAD_CREATE(&tid, &attr, bar, s);
 pthread_exit(0);
}


main(int argc, char **argv)
{
 PTHREAD_ATTR_INIT(&attr); 
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
 
 PTHREAD_CREATE(&foo_tid, &attr, foo, NULL);
 pthread_exit(0);
}

