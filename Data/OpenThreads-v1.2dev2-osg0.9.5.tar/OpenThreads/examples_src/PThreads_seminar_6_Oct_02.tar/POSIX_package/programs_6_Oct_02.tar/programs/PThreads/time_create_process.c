/*                time_create_process.c                */

/*
cc -o time_create_process time_create_process.c -L. -R. -fast -lpthread -lthread -lthread_extensions -lposix4
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include "thread_extensions.h"

#ifndef _POSIX_THREAD_PROCESS_SHARED
COMPILE_FAILED "_POSIX_THREAD_PROCESS_SHARED not defined!  This program won't run!"
#endif

int N, NO=FALSE;

child()
{
  exit(0);
}


main(int argc, char **argv)
{int i;
 
 if (argc >= 2) N = atoi(argv[1]);
 if (argc >= 3) NO = atoi(argv[2]);
 if (N>=1000000)
     printf("\n\nRunning %s for %dm iterations\n", argv[0], N/1000000);
 else
   if (N>=1000)
     printf("\n\nRunning %s for %dk iterations\n", argv[0], N/1000);
   else
     printf("\n\nRunning %s for %d iterations\n", argv[0], N);

 iobench_start();
 for (i=0; i<N; i++)
   {if (fork() == 0)
      child();
    wait(NULL);
  }
 iobench_end();
 iobench_report();
}
