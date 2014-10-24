/*                rt_thr.c                */

/*
  How to place an LWP into the realtime class.
*/
/*
cc -o rt_thr rt_thr.c -L. -R. -g -lpthread -lthread -lpthread_extensions -lposix4
*/

/*  _POSIX_C_SOURCE will not compile on Solaris 2.5 */
#define _REENTRANT
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/priocntl.h>
#include <sys/rtpriocntl.h>
#include "thread_extensions.h"

/* thread prototype */
void *rt_thread(void *);

main()
{pthread_attr_t thr_attr;
 int np;
  pthread_t tid;

 if ((np = sysconf(_SC_NPROCESSORS_ONLN)) != 1)
   printf("Warning: This system has %d processors active.\n \
           This demo will not be as effective with more then \
           one processor running.\n\n", np);

 /* create the thread that will run in realtime */
 PTHREAD_ATTR_INIT(&thr_attr);
 pthread_attr_setdetachstate(&thr_attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&thr_attr, PTHREAD_SCOPE_SYSTEM);
 PTHREAD_CREATE(&tid, &thr_attr, rt_thread, NULL);

 /* loop here forever, this thread is the TS scheduling class */
 while (1) {
   printf("MAIN: In time share class... running\n"); 
   sleep(1);
 }

}

/*
        This is the routine that is called by the created thread
*/

void *rt_thread(void *arg)
{pcinfo_t pcinfo;
 pcparms_t pcparms;
 int i;

 /* let the main thread run for a bit */
 sleep(4);

 /* get the class ID for the real-time class */
 strcpy(pcinfo.pc_clname, "RT");

 if (priocntl((idtype_t) 0, (id_t) 0, PC_GETCID, (caddr_t)&pcinfo) == -1)
   fprintf(stderr, "Error: getting RT class id\n"), exit(1);

 /* set up the real-time parameters */
 pcparms.pc_cid = pcinfo.pc_cid;
 ((rtparms_t *)pcparms.pc_clparms)->rt_pri = 10;
 ((rtparms_t *)pcparms.pc_clparms)->rt_tqnsecs = 0;

 /* set an infinite time quantum */
 ((rtparms_t *)pcparms.pc_clparms)->rt_tqsecs = RT_TQINF; 

 /* move this thread (LWP) to the real-time scheduling class */
 if (priocntl(P_LWPID, P_MYID, PC_SETPARMS, (caddr_t)&pcparms) == -1)
   fprintf(stderr, "Error: Setting RT mode.  Remember that you need to run this program as root.\n"), exit(1);

 /* simulate some processing */
 for (i=0;i<100000000;i++);

 printf("RT_THREAD: NOW EXITING...\n");
 printf("Done\n");
 exit(0);
}
