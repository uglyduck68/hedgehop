/*                false_tmp.c                */

/*
  Demonstrates what NOT to do on an MP.  If SEPARATION = 1, then there will be
  horrible false sharing and the machine will crawl.  If SEPARATION = 16
  then there will be no false sharing and the program will run about 10x
  faster.
*/


#define _POSIX_C_SOURCE 199506L 

#include <pthread.h>
#include <semaphore.h>
#include "thread_extensions.h"

#pragma align 4 (c2, c1)
char c2;
int AVOCADOS_NUMBER = 6023500;
int N_CPUS = 8;
int SEPARATION = 16;            /* 8 64-bit words per cache-line on Ultra SPARC */
sem_t exit_barrier;
int a[128];
char c1;
int N_CPUS1 = 8;


main(int argc, char **argv)
{int i;
 pthread_t tid;

 printf("AVOCADOS_NUMBER at: %x, N_CPUS at: %x\n", &AVOCADOS_NUMBER, &N_CPUS);
 printf("a[0] at: %x, a[1] at: %x\n", &a[0], &a[1]);
 printf("c1 at: %x, c2 at: %x\n", &c1, &c2);

}
