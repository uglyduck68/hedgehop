/*                cache_thrash.c                */

/*
cc -o cache_thrash cache_thrash.c -L. -R. -D__sun -D__sun2_6 -fast -lpthread -lthread -lposix4 -lthread_extensions 

  Standard deviation < 1% of mean.

*/


#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"


#define SIZE            1000000


int                     INTERATIONS = 30;
int                     BLOCK_SIZE = 1;
int                     touches = 0;
int                     CACHE_RESIDENT = 0;
int                     a[SIZE+100];


int add_rows()
{int            sum = 0, i, j; 

 for (i = 0; i <  BLOCK_SIZE; i++)
   {
     DEBUG(printf("%d %d\n", j, i));
     for (j = i; j < SIZE; j+= BLOCK_SIZE*2)
       {if (CACHE_RESIDENT)
         {sum += a[i];
         sum += a[i+BLOCK_SIZE];
         }
       else
         {sum += a[j];
         sum += a[j+BLOCK_SIZE];
         }
       }
   }
 touches += SIZE;
 return(sum);
}


main(int argc, char **argv)
{int i, j, k;

 if (argc >= 2) INTERATIONS    = atoi(argv[1]);
 if (argc >= 3) CACHE_RESIDENT = atoi(argv[2]);
 printf("INTERATIONS: %d CACHE_RESIDENT: %d\n",  INTERATIONS, CACHE_RESIDENT);

 j = add_rows();

 for (k = 1; k <= 8; k = k*2)
   {iobench_start();
   touches = 0;
   BLOCK_SIZE = k;
   for (i = 0; i <  INTERATIONS; i++)
     j = add_rows();
   iobench_end();
   printf("BLOCK_SIZE: %d.  Total of %dM touches. Sum: %d\n", BLOCK_SIZE, touches/1000000, j);
   iobench_report();
   }

 printf("Done\n");
 exit(0);
}
