/*                clear_memory.c                */


#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"



main(int argc, char **argv)
{int i, j, fd;
 int loc, s;
 char *buf = "1";
 int reverse = 0;
 char *path = "/disk2/6/Java/bil/tmp1";

 if (argc >= 2) reverse     = atoi(argv[1]);
 if (argc >= 3) path     = argv[2];

 if (reverse)
   printf("Reading 8000 blocks reverse from %s\n",      path);
 else
   printf("Reading 8000 blocks forward from %s\n",      path);

 fd = open(path, O_RDONLY);

 for (j=0; j < 8000; j++)
   {loc = j * 8192;
    if (reverse) loc = 66000000 - loc;
    s = pread(fd, buf, 1, loc);
    if (s == -1) {perror(""); exit(1);}
   }
 printf("Done\n");
 exit(0);
}

