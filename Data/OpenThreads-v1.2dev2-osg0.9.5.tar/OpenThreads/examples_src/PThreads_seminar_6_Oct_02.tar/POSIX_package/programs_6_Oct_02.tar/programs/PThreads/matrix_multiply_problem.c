/*                matrix_multiply_problem.c                */

/*

 
*/



#define _POSIX_C_SOURCE 199506L

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include "thread_extensions.h"



#define SIZE            128

int N_THREADS =         1;
sem_t                   barrier;

int a[SIZE] [SIZE], b[SIZE] [SIZE], c[SIZE] [SIZE];

struct _v
{int    row_start, row_end;
 int    col_start, col_end;
} ;
typedef struct _v element_t;



void *multiply_rows(void *arg)
{element_t *e = (element_t *) arg;
 int i, j, k, sum;
 DEBUG(printf("%s: %d %d\n", thread_name(pthread_self()), e->row_start, e->row_end));

 for (i = e->row_start; i < e->row_end; i++)
   {for (j = e->col_start; j < e->col_end; j++)
     {sum = 0;
     for (k = 0; k < SIZE; k++)
       sum += a[i][k] * b[k][j];
     c[i][j] = sum;
     }
   }

 sem_post(&barrier);

 free(e);
 pthread_exit(NULL);
}

void fill_matrix(int m[SIZE][SIZE])

{int i, j, n = 0;

 for (i=0; i<SIZE; i++)
   for (j=0; j<SIZE; j++)
     m[i][j] = (n++) % 17;
}

void print_matrix(int m[SIZE][SIZE])
{int i, j, n = 0;

 for (i=0; i<SIZE; i++)
   {printf("\n\t| ");
    for (j=0; j<SIZE; j++)
      printf("%5d ", m[i][j]);
    printf("|");
  }
}


main(int argc, char *argv[])
{int i, j, n = 0;
 element_t *element;
 pthread_attr_t attr;
 pthread_t tid;

 SEM_INIT(&barrier, NULL, 0);
 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

 fill_matrix(a);
 fill_matrix(b);

 iobench_start();
 for (i=0; i<N_THREADS; i++)
     {element = (element_t *) malloc(sizeof(element_t));
      element->row_start = (SIZE/N_THREADS) * i; 
      element->row_end = (SIZE/N_THREADS) * (i + 1);
      element->col_start = 0;
      element->col_end = SIZE;
      
      PTHREAD_CREATE(&tid, &attr, multiply_rows, element);
    }
 thread_single_barrier(&barrier, N_THREADS);

 iobench_end();

 if (SIZE < 17)
   {printf("\n\n\n");
   print_matrix(a);
   printf("\n\n\t\t\t\t * \n");
   print_matrix(b);
   printf("\n\n\t\t\t\t = \n");
   print_matrix(c);
   printf("\n\n\n");
   }
 else
   printf("c[%d, %d] = %d\n", SIZE, SIZE, c[SIZE-1][SIZE-1]);

 iobench_report();
 printf("Done\n");
 exit(0);
}

