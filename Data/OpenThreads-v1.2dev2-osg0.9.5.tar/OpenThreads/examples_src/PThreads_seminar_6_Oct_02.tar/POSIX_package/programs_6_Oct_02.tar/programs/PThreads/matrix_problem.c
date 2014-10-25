/*                matrix_problem.c                */

/*

This program illustrates the dangers of inadvertantly using shared
data, and the problems which result.

What is particularly interesting about this program, is that the
thread start times must be considered as random, making this into
a big race condition.  It is possible that you will get the correct
answer.  It is possible that all the threads will get the same values
for {i,j}, it is possible for any combination of values! A very nice
program indeed.

*/


/*
cc -o matrix_problem matrix_problem.c -L. -R. -g -lpthread -lthread -pthread -lposix4
*/


#define _POSIX_C_SOURCE 199506L

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include "thread_extensions.h"



#define SIZE            4

pthread_mutex_t         unused_lock = PTHREAD_MUTEX_INITIALIZER;
sem_t                   barrier;
int                     a[SIZE] [SIZE], b[SIZE] [SIZE], c[SIZE] [SIZE];

typedef struct _v
{int    i;
 int    j;
} element_t;



void *add_element(void *arg)
{element_t *e = (element_t *) arg;

 delay(100, 100);
 c[e->i] [e->j] =  a[e->i] [e->j] +  b[e->i] [e->j];
 sem_post(&barrier);
 pthread_exit(NULL);
}


void fill_matrix(int m[SIZE][SIZE])
{int i, j, n = 0;

 for (i=0; i<SIZE; i++)
   for (j=0; j<SIZE; j++)
     m[i][j] = n++;
}

void print_matrix(int m[SIZE][SIZE])
{int i, j, n = 0;

 for (i=0; i<SIZE; i++)
   {printf("\n\t| ");
    for (j=0; j<SIZE; j++)
      printf("%2d ", m[i][j]);
    printf("|");
  }
}


main(int argc, char *argv[])
{int            i, j, n = 0;
 element_t      element;
 pthread_attr_t attr;
 pthread_t      tid;

 SEM_INIT(&barrier, NULL, 0);
 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

 fill_matrix(a);
 fill_matrix(b);


 iobench_start();
 for (i=0; i<SIZE; i++)
   for (j=0; j<SIZE; j++)
     {element.i = i; element.j = j;
      PTHREAD_CREATE(&tid, &attr, add_element, &element);
      delay(0, 40000);
    }
 thread_single_barrier(&barrier, SIZE*SIZE);
 iobench_end();

 printf("\n\n\n");
 print_matrix(a);
 printf("\n\n\n\t       + \n");
 print_matrix(b);
 printf("\n\n\n\t       = \n");
 print_matrix(c);
 printf("\n\n\n");
 iobench_report();
 printf("Done\n");
 exit(0);
}

