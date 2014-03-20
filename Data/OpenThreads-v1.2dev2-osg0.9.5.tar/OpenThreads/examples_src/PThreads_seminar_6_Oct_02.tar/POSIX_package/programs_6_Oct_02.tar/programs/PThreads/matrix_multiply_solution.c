/*                matrix_multiply_solution.c                */

/*
*/


#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"



struct _v
{int    row_start, row_end;
 int    col_start, col_end;
} ;
typedef struct _v element_t;

pthread_attr_t          attr;
sem_t                   barrier;
int                     GET_DELAY = 0, PROCESS_DELAY = 0;
int                     BLOCK_SIZE = 4;
int N_THREADS =         1;
int                     nOps = 0;
int                     repeat = 0;
int                     SIZE = 128;

#define MAX_SIZE                1024


int a[MAX_SIZE] [MAX_SIZE], b[MAX_SIZE] [MAX_SIZE], c[MAX_SIZE] [MAX_SIZE];



void *multiply_rows(void *arg)
{element_t *e = (element_t *) arg;
 int h, i, j, k, l=0, sum;
 DEBUG(printf("%s: [%d - %d, %d - %d]\n", thread_name(pthread_self()),
              e->row_start, e->row_end, e->col_start, e->col_end));

 for (h = 0; h < repeat; h++)
   for (i = e->row_start; i <= e->row_end; i++)
     {for (j = e->col_start; j <= e->col_end; j++)
       {sum = 0;
       for (k = 0; k < SIZE; k++)
         {sum += a[i][k] * b[k][j];      l++;}
       c[i][j] = sum;
       }
     }
 nOps += l;
 sem_post(&barrier);
}

void fill_matrix(int m[MAX_SIZE][MAX_SIZE])

{int i, j, n = 0;

 for (i=0; i<SIZE; i++)
   for (j=0; j<SIZE; j++)
     m[i][j] = (n++) % 17;
}

void print_matrix(int m[MAX_SIZE][MAX_SIZE])
{int i, j, n = 0;

 for (i=0; i<SIZE; i++)
   {printf("\n\t| ");
    for (j=0; j<SIZE; j++)
      printf("%5d ", m[i][j]);
    printf("|");
  }
}


main(int argc, char **argv)
{int i, j;
 pthread_t tid;
 int MT = 1;

 SEM_INIT(&barrier, NULL,  0); 
 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

 if (argc >= 2) MT     = atoi(argv[1]);
 if (argc >= 3) repeat = atoi(argv[2]);
 if (argc >= 4) SIZE   = atoi(argv[3]);
 printf("MT = %d repeat = %d SIZE = %d \n", MT, repeat, SIZE);

 fill_matrix(a);
 fill_matrix(b);


 iobench_start();

if (MT)
  {
   {element_t *e = (element_t *) malloc(sizeof(element_t));
    e->row_start = 0; e->row_end = SIZE/2 - 1;
    e->col_start = 0; e->col_end = SIZE/2 - 1;
    PTHREAD_CREATE(&tid, &attr, multiply_rows, e);
   }

   {element_t *e = (element_t *) malloc(sizeof(element_t));
    e->row_start = SIZE/2; e->row_end = SIZE-1;
    e->col_start = 0; e->col_end = SIZE/2 - 1;
    PTHREAD_CREATE(&tid, &attr, multiply_rows, e);
   }

   {element_t *e = (element_t *) malloc(sizeof(element_t));
    e->row_start = 0; e->row_end = SIZE/2 - 1;
    e->col_start = SIZE/2; e->col_end = SIZE-1;
    PTHREAD_CREATE(&tid, &attr, multiply_rows, e);
   }

   {element_t *e = (element_t *) malloc(sizeof(element_t));
    e->row_start = SIZE/2; e->row_end = SIZE-1;
    e->col_start = SIZE/2; e->col_end = SIZE-1;
    PTHREAD_CREATE(&tid, &attr, multiply_rows, e);
   }
 thread_single_barrier(&barrier, 4);
  }
else
{element_t *e = (element_t *) malloc(sizeof(element_t));
    e->row_start = 0; e->row_end = SIZE - 1;
    e->col_start = 0; e->col_end = SIZE-1;
    multiply_rows(e);
   }
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


   printf("nOps: %d\n", nOps);

 iobench_report();
 printf("Done\n");
 exit(0);
}
