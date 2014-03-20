/*                test_single_wakeup_cv.c                */


/*
cc -o test_single_wakeup_cv test_single_wakeup_cv.c -L. -R. -fast -lpthread -lthread -lthread_extensions -lposix4
*/

#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"
#include <tnf/probe.h>


int PTHREAD_CREATE(pthread_t *new_thread_ID,
                   const pthread_attr_t *attr,
                   void * (*start_func)(void *), void *arg)
{
     thr_create(0, NULL, start_func, arg, 0x00000001, new_thread_ID);
}


pthread_key_t SLEEP_NODE;


/*
   ================================================================
                        Counting Semaphores
   ================================================================

  In case the platform doesn't implement semaphores.

*/


#define THREAD_SEMA_INITIALIZER \
 {PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER, 0}

typedef struct _sema {
        pthread_mutex_t lock;   /* lock for structure           */
        pthread_cond_t  cv;     
        int             count;
} thread_sema_t;



int thread_sema_init(thread_sema_t *s)
{
  pthread_mutex_init(&(s->lock), NULL);
  pthread_cond_init(&(s->cv), NULL);
  s->count = 0;
}


int thread_sema_destroy(thread_sema_t *s)
{
  pthread_mutex_destroy(&(s->lock));
  pthread_cond_destroy(&(s->cv));
}



int thread_sema_wait(thread_sema_t *s)
{
  TNF_PROBE_0(thread_sema_wait_start,  "swcv", "");
  pthread_mutex_lock(&(s->lock));
  while (s->count == 0) pthread_cond_wait(&s->cv, &(s->lock));
  s->count--;
  pthread_mutex_unlock(&(s->lock));
  TNF_PROBE_0(thread_sema_wait_end,  "swcv", "");
}



int thread_sema_post(thread_sema_t *s)
{
  TNF_PROBE_0(thread_sema_post_start,  "swcv", "");
  pthread_mutex_lock(&(s->lock));
  s->count++;  
  pthread_mutex_unlock(&(s->lock));
  pthread_cond_signal(&s->cv);
  TNF_PROBE_0(thread_sema_post_end,  "swcv", "");
}




/*
   ================================================================
                        Recursive1_ Mutex
   ================================================================

*/


typedef struct _snode {
  struct _snode                 *next;
  struct _snode                 *previous;      /* not used yet */
  thread_sema_t                 sema;
  struct _swcv                  *swcv;          /* not used yet */
  pthread_t                     tid;
} sleep_node_t;

#define THREAD_RECURSIVE1__MUTEX_INITIALIZER \
 {PTHREAD_MUTEX_INITIALIZER, NULL, NULL, FALSE, 0, NULL_TID}

typedef struct _rm {
  pthread_mutex_t               lock;           /* lock for structure   */
  sleep_node_t                  *sleep_queue;
  sleep_node_t                  *sleep_queue_last;
  int                           owned;
  int                           count;
  pthread_t                     owner;
} thread_recursive1__mutex_t;




int thread_recursive1__mutex_init(thread_recursive1__mutex_t *m,
                                    pthread_mutexattr_t *attr)
{
  pthread_mutex_init(&(m->lock), NULL);
  m->sleep_queue = NULL;
  m->sleep_queue_last = NULL;
  m->owned = FALSE;
  m->owner = NULL_TID;
  m->count = 0;
}


int thread_recursive1__mutex_destroy(thread_recursive1__mutex_t *m)
{
  pthread_mutex_destroy(&(m->lock));
}



int thread_recursive1__mutex_lock(thread_recursive1__mutex_t *m)
{pthread_t tid = pthread_self();
 sleep_node_t *node = (sleep_node_t *) pthread_getspecific(SLEEP_NODE);

 TNF_PROBE_0(thread_recursive1__mutex_lock_start,  "swcv", "");
 pthread_mutex_lock(&(m->lock));
 if (m->owned && !pthread_equal(m->owner, tid))
   {
     node->next = NULL;
     if (m->sleep_queue == NULL)
       {m->sleep_queue = node;}
     else
       {m->sleep_queue_last->next = node;}

     m->sleep_queue_last = node;
     pthread_mutex_unlock(&(m->lock));
     thread_sema_wait(&node->sema);     /* Ownership handed off ! */
   }
 else
   {
     m->owner = tid;
     m->owned = TRUE;
     m->count++;
     pthread_mutex_unlock(&(m->lock));
   }

 TNF_PROBE_0(thread_recursive1__mutex_lock_end,  "swcv", "");
}



int thread_recursive1__mutex_unlock(thread_recursive1__mutex_t *m)
{
 TNF_PROBE_0(thread_recursive1__mutex_unlock_start,  "swcv", "");
  pthread_mutex_lock(&(m->lock));


 if ((m->sleep_queue_last == NULL) &&
     (m->sleep_queue != NULL))
   abort();


  m->count--;
  thread_recursive1__mutex_unlock_internal(m);
  pthread_mutex_unlock(&(m->lock));
 TNF_PROBE_0(thread_recursive1__mutex_unlock_end,  "swcv", "");
}

int thread_recursive1__mutex_unlock_internal(thread_recursive1__mutex_t *m)
{ sleep_node_t *node;

  if (m->count == 0)
    if (m->sleep_queue == NULL)
      {
        m->owned = FALSE;
        m->owner = NULL_TID;
      }
    else
      { /* Hand off ownership ! */
        TNF_PROBE_0(thread_recursive1__mutex_unlock_handoff_start,  "swcv", "");
        node = m->sleep_queue;
        m->sleep_queue = node->next;
        if (node->next == NULL)
          {m->sleep_queue_last = NULL;}
        m->owner = node->tid;
        m->count++;
        thread_sema_post(&node->sema);
        TNF_PROBE_0(thread_recursive1__mutex_unlock_handoff_end,  "swcv", "");
      }

  return(0);
}





/*
   ================================================================
                        Single Wakeup CV
   ================================================================

*/



#define THREAD_SWCV_INITIALIZER \
 {PTHREAD_MUTEX_INITIALIZER, NULL, NULL, NULL}

typedef struct _swcv {
  pthread_mutex_t               lock;           /* lock for structure   */
  sleep_node_t                  *sleep_queue;
  sleep_node_t                  *sleep_queue_last;
  thread_recursive1__mutex_t    *external_lock;
} thread_swcv_t;


void thread_swcv_destructor(void *v)
{sleep_node_t *node = (sleep_node_t *) v;

 free(node);
}

void thread_swcv_runtime_init()         /* Run once in main() */
{
 pthread_key_create(&SLEEP_NODE, thread_swcv_destructor);
}


void thread_swcv_thread_init()          /* Run in every start_fn() */
{sleep_node_t *node;

  node = (sleep_node_t *) malloc (sizeof(sleep_node_t));
  node->previous = NULL;                /* Needed for interrupts only */
  node->swcv = NULL;                    /* Needed for interrupts only */
  node->next = NULL;    
  node->tid  = pthread_self();
  thread_sema_init(&node->sema);
  pthread_setspecific(SLEEP_NODE, node);
}




void thread_swcv_wait(thread_swcv_t *cv, thread_recursive1__mutex_t *m)
{ sleep_node_t *node = (sleep_node_t *) pthread_getspecific(SLEEP_NODE);

 TNF_PROBE_0(thread_swcv_wait_start,  "swcv", "");
 pthread_mutex_lock(&cv->lock);
 thread_recursive1__mutex_unlock(m);
 cv->external_lock = m;         /* We'll need this... */

 node->next = NULL;
 if (cv->sleep_queue == NULL)
    {cv->sleep_queue_last = node;
     cv->sleep_queue = node;
    }
 else
   {cv->sleep_queue_last->next = node;
    cv->sleep_queue_last = node;}
 pthread_mutex_unlock(&cv->lock);
 thread_sema_wait(&node->sema);

 /* When you wake up, you will have been on the MUTEX sleep Q ! */
 /* thread_recursive1__mutex_lock() does a direct hand-off! */
 /*  DONE FOR YOU: thread_recursive1__mutex_lock(m); */
 TNF_PROBE_0(thread_swcv_wait_end,  "swcv", "");
}

void thread_swcv_broadcast(thread_swcv_t *cv)
{
  TNF_PROBE_0(thread_swcv_broadcast_start,  "swcv", "");
  pthread_mutex_lock(&cv->lock);
  if ((cv->external_lock == NULL) || (cv->sleep_queue == NULL))
    { /* Obviously hasn't called wait yet.  OR nothing to do. */
      pthread_mutex_unlock(&cv->lock);
      TNF_PROBE_0(thread_swcv_broadcast_end,  "swcv", "");

      return;
    }
  pthread_mutex_lock(&cv->external_lock->lock);

  if (cv->external_lock->sleep_queue == NULL)
    {cv->external_lock->sleep_queue = cv->sleep_queue;}
  else
    {cv->external_lock->sleep_queue_last->next = cv->sleep_queue;}

  cv->external_lock->sleep_queue_last = cv->sleep_queue_last;
  cv->sleep_queue = NULL;
  cv->sleep_queue_last = NULL;
  if (!cv->external_lock->owned)
    thread_recursive1__mutex_unlock_internal(cv->external_lock);

  pthread_mutex_unlock(&cv->external_lock->lock);
  pthread_mutex_unlock(&cv->lock);
  TNF_PROBE_0(thread_swcv_broadcast_end,  "swcv", "");
}

void thread_swcv_signal(thread_swcv_t *cv)
{sleep_node_t *node;

 TNF_PROBE_0(thread_swcv_signal_start,  "swcv", "");
 pthread_mutex_lock(&cv->lock);
 if (cv->external_lock == NULL)
   { /* Obviously hasn't called wait yet. */
     pthread_mutex_unlock(&cv->lock);
     TNF_PROBE_0(thread_swcv_signal_end,  "swcv", "");
     return;
   }
 pthread_mutex_lock(&cv->external_lock->lock);

 node = cv->sleep_queue;

 if (node != NULL)
   {
     cv->sleep_queue = node->next;
     if (node->next == NULL) cv->sleep_queue_last = NULL;
     node->next = NULL;
     if (cv->external_lock->sleep_queue == NULL)
       {cv->external_lock->sleep_queue = node;}
     else
       {cv->external_lock->sleep_queue_last->next = node;}
     cv->external_lock->sleep_queue_last = node;
     if (!cv->external_lock->owned)
       thread_recursive1__mutex_unlock_internal(cv->external_lock);
   }

 pthread_mutex_unlock(&cv->external_lock->lock);
 pthread_mutex_unlock(&cv->lock);
 TNF_PROBE_0(thread_swcv_signal_end,  "swcv", "");
}





/*
   ================================================================
                        Test Single Wakeup CV
   ================================================================

*/

int N_CONS = 25;
int NORMAL = 1;
int N = 100000;
pthread_cond_t  requests_consumer  = PTHREAD_COND_INITIALIZER;
pthread_cond_t  requests_producer  = PTHREAD_COND_INITIALIZER;
pthread_mutex_t requests_lock      = PTHREAD_MUTEX_INITIALIZER;
thread_swcv_t  requests_consumer2 = THREAD_SWCV_INITIALIZER;
thread_swcv_t  requests_producer2 = THREAD_SWCV_INITIALIZER;
thread_recursive1__mutex_t requests_lock2     = THREAD_RECURSIVE1__MUTEX_INITIALIZER;
int length = 0;
sem_t barrier;

void *producer1(void *arg)
{int i;

  for (i = 0; i < N; i++)
   {
    pthread_mutex_lock(&requests_lock);
    while (length > 0)
      pthread_cond_wait(&requests_producer, &requests_lock);
    length += 10;
    pthread_cond_broadcast(&requests_consumer);
    sched_yield();
    pthread_mutex_unlock(&requests_lock);
  }
 sem_post(&barrier);
 pthread_exit(NULL);
}


void *consumer1(void *arg)
{
 while(1)
   {pthread_mutex_lock(&requests_lock);
    while (length == 0)
      pthread_cond_wait(&requests_consumer, &requests_lock);
    length--;
    if (length == 0) pthread_cond_signal(&requests_producer);
    pthread_mutex_unlock(&requests_lock);
    sched_yield();
  }
}


void *producer2(void *arg)
{int i;

 thread_swcv_thread_init();
 for (i = 0; i < N; i++)
   {
     thread_recursive1__mutex_lock(&requests_lock2);
     while (length > 0)
       thread_swcv_wait(&requests_producer2, &requests_lock2);
     length += 10;
     TNF_PROBE_0(thread_swcv_producer,  "swcv", "");
     /*     DEBUG(printf("%s adding 10\n",  thread_name(pthread_self())));  */
     thread_swcv_broadcast(&requests_consumer2);
     sched_yield();   
     thread_recursive1__mutex_unlock(&requests_lock2);
   }
 sem_post(&barrier);
 pthread_exit(NULL);
}


void *consumer2(void *arg)
{
  thread_swcv_thread_init();
  while(1)
    {
      thread_recursive1__mutex_lock(&requests_lock2);
      while (length == 0)
        thread_swcv_wait(&requests_consumer2, &requests_lock2);
      length--;
      TNF_PROBE_0(thread_swcv_consumer,  "swcv", "");
      /*      DEBUG(printf("%s removing 1\n", thread_name(pthread_self()))); */
      if (length == 0) thread_swcv_signal(&requests_producer2);
      thread_recursive1__mutex_unlock(&requests_lock2);
    }
}


void *producer3(void *arg)
{int i;

 thread_swcv_thread_init();
 for (i = 0; i < N; i++)
   {
     thread_recursive1__mutex_lock(&requests_lock2);
     sched_yield();   
     thread_recursive1__mutex_unlock(&requests_lock2);
     sched_yield();   
   }
 sem_post(&barrier);
 pthread_exit(NULL);
}


void *consumer3(void *arg)
{int i;

 thread_swcv_thread_init();
 for (i = 0; i < N; i++)
   {
     thread_recursive1__mutex_lock(&requests_lock2);
     sched_yield();   
     thread_recursive1__mutex_unlock(&requests_lock2);
     sched_yield();   
   }
 pthread_exit(NULL);
}


main(int argc, char **argv)
{int i;
 pthread_attr_t attr;
 pthread_t tid;

 TNF_PROBE_0(main_startup,  "swcv", "");

 thread_swcv_runtime_init(); 
 SEM_INIT(&barrier, 0, 0);
 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
 
 if (argc >= 2) N = atoi(argv[1]);
 if (argc >= 3) NORMAL = atoi(argv[2]);
 if (N>=1000000)
     printf("\n\nRunning %s for %dm iterations\n", argv[0], N/1000000);
 else
     printf("\n\nRunning %s for %dk iterations\n", argv[0], N/1000);

 for (i=0; i<N_CONS; i++)
 if (NORMAL)
   PTHREAD_CREATE(&tid, &attr, consumer1, NULL);
 else
   PTHREAD_CREATE(&tid, &attr, consumer2, NULL);
 iobench_start();
 if (NORMAL)
   PTHREAD_CREATE(&tid, &attr, producer1, NULL);
 else
   PTHREAD_CREATE(&tid, &attr, producer2, NULL);
 thread_single_barrier(&barrier, 1);

 iobench_end();
 iobench_report();
 exit(0);
}

