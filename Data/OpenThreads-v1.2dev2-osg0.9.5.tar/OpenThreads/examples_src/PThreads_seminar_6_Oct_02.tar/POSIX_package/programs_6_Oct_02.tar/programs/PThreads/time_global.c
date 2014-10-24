/*                time_global.c                */

 /*
cc -o time_global time_global.c -L. -R. -lpthread -lthread -lthread_extensions -lposix4 -fast
*/

#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"

int N=100;
int a[1000];

main(int argc, char **argv)
{int i, j, sum;
 char s[1000];

 if (argc >= 2) N = atoi(argv[1]);
 if (N>=1000000)
     printf("\n\nRunning %s for %dg iterations\n", argv[0], N/1000000);
 else
     printf("\n\nRunning %s for %dm iterations\n", argv[0], N/1000);


 iobench_start();
 for (i=0; i<N; i++)
    for (j=0; j<100; j+=1)
   {
     sum+=a[j];         /* Minimize the effect of pipeline disruption */
     sum+=a[j+1];
     sum+=a[j+2];
     sum+=a[j+3];
     sum+=a[j+4];
     sum+=a[j+5];
     sum+=a[j+6];
     sum+=a[j+7];
     sum+=a[j+8];
     sum+=a[j+9];
   }
 sprintf(s, "\nJunk Result: %d\n", sum);
 /*  Optimizer optimizes away unused values.   Use it or lose it! */
 iobench_end();
 iobench_report();

 pthread_exit(0);
}

