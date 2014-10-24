/*                callout.c                */



/*

 The interface to the per-thread alarm package.  This is fully MT-safe
 and will handle any number of alarms / sleeps.

   int thread_settimer(int delay, void fn(void *), void *arg)
   thread_deletetimer(int timer_number)
   void thread_sleep(int t)



 typically:

   i = thread_settimer(20, foo, TID);
   ...
   thread_deletetimer(i);

 "Run function foo(TID) in 20 seconds."

 If the thread gets to the deletetimer() line before the alarm expires,
 only that one alarm will be affected.

 TID can be any value, and foo() is allowed to send a signal to specific
 threads if desired (eg, TID).  That thread would have to install a signal
 handler in that case (presumably SIGUSR1).


 thread_sleep(3);

 "Put the current thread to sleep for 3 seconds."

 sleep() uses SIGALRM, so it will not work with other uses of alarm().
 thread_sleep() is based upon thread_settimer() and works reliably with any
 number of threads.  Note that the sleeping thread will become RUNNABLE
 at wake-up time.  When it actually gets a CPU is a scheduling question.
 (Yes, nanosleep() makes more sense, but this is a nice proof-of-concept.)


 The user code must not handle SIGALRM, but that is the only limitation.
 (Mask it out & don't sigwait() on it.)  The user code may install handlers
 or sigwait() for any other signal.

 This library uses alarm(), hence its finest granularity is 1 second.  Higher
 resolution timers can easily be built on top of this, and are left to the
 reader as an exercise.


  Build a dynamic library:

cc  -G -o libcallout.so callout.c -g -lpthread -lthread -lposix4

Bug in nanosleep() in Solaris 8? pthread_kill() doesn't work?!
*/



#define _POSIX_C_SOURCE 199506L

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include "thread_extensions.h"


 /*  This runs before main() and starts up the sigwait() loop for SIGALRM. */

void initialize_thread_timer();

#ifdef __sun
#pragma init (initialize_thread_timer)
#endif

#if defined (__alpha) && defined (__osf__)
__init_thread_timer()
{initialize_thread_timer();}
#endif


typedef struct timer_struct {
  int                   expire_time;   /* UTC time */
  int                   number;        /* Unique identifier */
  void                  (*fn)(void *); /* Function to call */
  void                  *arg;          /* Argument to fn */
  struct timer_struct   *next;         /* Pointer to next */
} timer_queue_t;

timer_queue_t           *timer_queue;
pthread_t               _SIGWAIT_TID;
pthread_mutex_t         timer_queue_mutex;
sem_t                   timer_sema;
int                     timer_number;

void UnusedSigHandler(int signo)
{
  /* This should never happen.  
     Note that printf() and thread_name() are not signal safe!
     */
  printf("Got SIGALRM (%d) in handler for thread %d?!\n",
         signo, thread_name(pthread_self()));
  exit(1);
}

 /* To wake up a sleeping thread, just release its semaphore.  The
   thread will run as soon as the scheduler decides to schedule it. 
 */
void thread_timer_wakeup(void *s)
{
  sem_post((sem_t *) s);
}

 /* Set a sleep time.  This function will set up the ALRM, then sleep
   on a semaphore it creates for the purpose. */
void thread_sleep(int t)
{sem_t s;

 if (t < 1) return;
 SEM_INIT(&s, 0, NULL);
 thread_settimer(t, thread_timer_wakeup, &s);
 while(sem_wait(&s) != 0) DEBUG(printf("Sem Interrupted\n");)
 sem_destroy(&s);
}


initialize_timer()
{
  _SIGWAIT_TID = pthread_self();
  timer_queue = (timer_queue_t *) malloc(sizeof(timer_queue_t));
  timer_queue->next = NULL;
  timer_queue->expire_time = -1;
  timer_number = 1;
  sem_post(&timer_sema);                /* Used only for initialization */
}

thread_timer_setalarm()
{int now = time(NULL);
 int delay;
  
 pthread_mutex_lock(&timer_queue_mutex);
 if (timer_queue->next == NULL)
   {pthread_mutex_unlock(&timer_queue_mutex);
    return;}
 delay = timer_queue->next->expire_time - now;
 if (delay < 1) delay = 1;
  alarm(delay);
 pthread_mutex_unlock(&timer_queue_mutex);
}

 /* Delete the node for the 1st matching entry.  Leave the ALRM. */
void thread_deletetimer(int timer_number)
{
  timer_queue_t         *tq, *tq1, *tq2, *ts;

  pthread_mutex_lock(&timer_queue_mutex);
  tq2 = timer_queue;
  for (tq = timer_queue, tq1 = timer_queue->next;
       tq1 != NULL;
       tq1 = tq1->next, tq = tq->next)
    {if (tq1->number == timer_number)
     {tq->next = tq1->next;
      free(tq1);}}
 pthread_mutex_unlock(&timer_queue_mutex);
}


int thread_settimer(int delay, void fn(void *), void *arg)
{
  timer_queue_t         *tq, *tq1, *tq2, *ts;
  int                   expire_time;
  int                   killp = 0;

  ts  = (timer_queue_t *) malloc(sizeof(timer_queue_t));
  expire_time = (int) time(NULL)+delay;
  ts->expire_time=expire_time;
  ts->fn = fn;
  ts->arg = arg;

  pthread_mutex_lock(&timer_queue_mutex);
  timer_number++;
  ts->number = timer_number;
  tq2 = timer_queue;
  DEBUG(if (tq2->next == NULL) printf("New Timer\n");)
  for (tq = timer_queue, tq1 = timer_queue->next;
       1;
       tq1 = tq1->next, tq = tq->next)
    {if ((tq1 == NULL) || (tq1->expire_time > expire_time))
     {tq->next = ts;
      ts->next = tq1;
      if (tq2->next == ts) killp = 1;
      pthread_mutex_unlock(&timer_queue_mutex);

      thread_timer_setalarm();
      return(timer_number);}
   }
}

thread_expired_timer()
{
  timer_queue_t         *tq, *tq1;
  int                   now = time(NULL);
  void                  (*fn) (void *);
  void                  *arg;
  

  pthread_mutex_lock(&timer_queue_mutex);
  tq = timer_queue->next;
  tq1 = tq->next;
  
  while(tq->expire_time <= now)
    {fn = tq->fn;
     arg = tq->arg;
     free(tq);
     tq = tq1;
     timer_queue->next = tq;
          
     pthread_mutex_unlock(&timer_queue_mutex);
     fn(arg);

     if (tq1 == NULL) {DEBUG(printf("No timer.\n");) return;}
     pthread_mutex_lock(&timer_queue_mutex);
     tq1 = tq1->next;
   }
  alarm(tq->expire_time - now);
  pthread_mutex_unlock(&timer_queue_mutex);
}
  
void *sigwaiter(void *arg)
{int                            sig, err;
 sigset_t                       s;
 static struct sigaction        action; 

 action.sa_handler = (void (*)(void)) UnusedSigHandler;
 sigaction(SIGALRM, &action, NULL);
 sigfillset(&s);
 pthread_sigmask(SIG_BLOCK, &s, NULL);  /* Take no interrupts */
 initialize_timer();

 sigemptyset(&s);
 sigaddset(&s, SIGALRM);

 while(1)
    {err = sigwait(&s, &sig);
     if (err) {errno = err; perror("Sigwait error!");}
     switch (sig)
       {case SIGALRM :          thread_expired_timer();
                                break;
       default:                 printf("IMPOSSIBLE! signal: %d\n", sig);
      }
   }
}


void initialize_thread_timer()
{ pthread_attr_t        attr;
  int                   err;
  pthread_t             tid;

  SEM_INIT(&timer_sema, 0, 0);
  PTHREAD_ATTR_INIT(&attr);
  err = pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
  pthread_mutex_lock(&timer_queue_mutex);
  PTHREAD_CREATE(&tid, &attr, sigwaiter, NULL);
  while(sem_wait(&timer_sema) != 0) ;
  pthread_mutex_unlock(&timer_queue_mutex);
}
