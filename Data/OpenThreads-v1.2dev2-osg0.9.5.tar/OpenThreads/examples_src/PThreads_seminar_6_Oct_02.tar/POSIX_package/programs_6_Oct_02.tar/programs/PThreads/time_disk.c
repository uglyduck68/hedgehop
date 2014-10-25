/*                time_disk.c                */

/*
  This program runs a set of read() calls against one large file.
  It runs with one or more threads so you can see the performance
  effect of MT.  Each read() gets one byte from a random location.
  You can run it for a number of iterations & get mean & SD.

  Make sure that there are links in /tmp pointing to wherever you
  can find room.

  lrwxrwxrwx   1 bil other ... time_disk0.tmp -> /disk2/6/temp_disk_test
  ln -s /disk2/6/temp_disk_test /tmp/time_disk0.tmp

  The file must be much larger than physical memory.  10x would be great,
  but 2x will do.  Expect "performance" to improve as the mbuffers get
  loaded.  For a file 2x Physical, initial 100/s will improve to 200/s
  (as 50% of the file will become cached).  To populate the cache, you
  can run this program for a while.

  runtime = (Physical Memory / PAGE_SIZE)   / READS_PER_SECOND  eg:
  160seconds = (128MB        / (8KB/PAGE))  / 100

  CF: Same program in Java: TimeDisk/Test.java

*/


#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include <tnf/probe.h>
#include <math.h>
#include <unistd.h>
#include "thread_extensions.h"


#define MAX_FILE_SIZE   1024*1024*1024
#define PAGE_SIZE       8192
#define MAX_PAGES       (MAX_FILE_SIZE/PAGE_SIZE)
#define MAX_THREADS     512
#define MAX_DENSITY     100


/*  Hack for early TNF bug */
int PTHREAD_CREATE(pthread_t *new_thread_ID,
                   const pthread_attr_t *attr,
                   void * (*start_func)(void *), void *arg)
{
     thr_create(0, NULL, start_func, arg, 0x00000001, new_thread_ID);
}



pthread_attr_t          attr;
int                     nProcessed[MAX_THREADS];
pthread_t               threads[MAX_THREADS];
int                     MAX_READS;
int                     density[MAX_DENSITY];
int                     hits[MAX_PAGES];
int                     fd;
char                    *path = "/tmp/time_disk0.tmp";
off_t                   length;
int                     PID;
int                     stop=FALSE;
int                     N_THREADS=1, SPIN_TIME=0, RUNTIME=1, ITERATIONS=1;


extern double real_time, total_real_time, user_time,
  system_time, trap_time, wait_time;



void *test(void *arg) {
  int    me = ((int) arg) % 1000; /* Hack to get two values in one! */

  /* Don't reuse seed, even across processes */
  long  seed = ((int) arg) + PID*100000;

  int   i, fileOffset, s;
  char  *thread = thread_name(pthread_self());
  char  buf[10];

  for (i=0; i< MAX_READS; i++) {
    if (stop) break;
    fileOffset = abs((rand_r(&seed)*PAGE_SIZE) % length);
    hits[(int) fileOffset/PAGE_SIZE]++;
    TNF_PROBE_1(process_request_start,  "start", "",
                tnf_int, location, fileOffset);
    /* DEBUG(printf("%s reading at %d\n", thread, fileOffset)); */
    s = pread(fd, &buf, 1, fileOffset);
    TNF_PROBE_0(process_request_end, "end", "");
    if (s != 1) printf("Error! at %d\n", fileOffset);
    delay(0, SPIN_TIME*1000);
    nProcessed[me]++;
  }
  stop=TRUE;    /* If one thread completes MAX_READS, all quit. */
                /* Presumably never get here. */
}




main(int argc, char **argv) {
  int           i, j;
  pthread_t     tid;
  double        rates[MAX_THREADS], S = 0.0, mean, rate_sum = 0.0;
  int           totalProcessed;


  PID = getpid();
  PTHREAD_ATTR_INIT(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

  if (argc > 1) N_THREADS       = atoi(argv[1]);
  if (argc > 2) SPIN_TIME       = atoi(argv[2]);
  if (argc > 3) RUNTIME         = atoi(argv[3]);
  if (argc > 4) ITERATIONS      = atoi(argv[4]);
  printf("time_disk(N_THREADS %d SPIN_TIME %dms RUNTIME %ds ITERATIONS %d)\n", 
         N_THREADS, SPIN_TIME, RUNTIME, ITERATIONS);
  if (N_THREADS>MAX_THREADS) {
    printf("Too many threads! Max is %d\n", MAX_THREADS);
    abort();
  }
 
  fd = open(path, O_RDONLY);
  if (fd == -1)   {printf("Check %s (see comments)!", path); exit(1);}
  length = lseek(fd, 0, SEEK_END);

  /* Should never be used, except when seed==1 (to read from mbufs)*/
  MAX_READS=RUNTIME*10000;

  if (SPIN_TIME>0)  calibrate_delay();

  for (j=0; j<ITERATIONS; j++) {

    for (i=0; i<MAX_PAGES; i++) hits[i]=0;
    for (i=0; i<MAX_DENSITY; i++) density[i]=0;
    for (i=0; i<N_THREADS; i++) nProcessed[i]=0;
    totalProcessed=0;

    for (i=0; i<N_THREADS; i++)
      PTHREAD_CREATE(&threads[i], &attr, test, (void *) (j*1000 + i));

    iobench_start();
    sleep(RUNTIME);
    stop = TRUE;
    for (i=0; i<N_THREADS; i++) {pthread_join(threads[i], NULL);}
    iobench_end();

    for (i=0; i<N_THREADS; i++) {
      DEBUG(printf("%s processed \t%d\n",
                   thread_name(threads[i]), nProcessed[i]));
      totalProcessed += nProcessed[i];
    }
    
    for (i=0; i<MAX_PAGES; i++) {
      if (hits[i] < MAX_DENSITY)
        density[hits[i]]++;
      else
        DEBUG(printf("Page %d got %d hits\n", i, hits[i]));
    }
    
    DEBUG(printf("nHits \t nPages \n"));
    for (i=1; i<MAX_DENSITY; i++) {
      if (density[i]>0)
        DEBUG(printf("%d \t %d\n", i, density[i]));
    }

    if (ITERATIONS==1) iobench_report();
    if (ITERATIONS==1) printf("totalProcessed: %d, rate: %f/sec\n",
                              totalProcessed, totalProcessed / real_time);
    rates[j] =  totalProcessed / real_time;
    rate_sum += totalProcessed / real_time;
    stop=FALSE;
  }

  if (ITERATIONS>1) {
    mean = rate_sum/ITERATIONS;

    for (i=0; i<ITERATIONS; i++) S+=(mean-rates[i])*(mean-rates[i]);
    S = sqrt(S/(ITERATIONS-1));
    printf("Mean rate: %3.2f/sec, Standard Deviation: %3.2f\n", mean, S);
  }
}
