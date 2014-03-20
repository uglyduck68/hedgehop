/*                stop_queue_solution.c                */

/*
  This is the prototypical producer/consumer example done by
  building a singly linked list. Every few seconds we stop the
  queue completely, letting the consumers complete their current
  request, but not taking anything new from the queue.  Upon
  restart, the consumers get to empty the list before the producers
  start.

  Delays are inserted to simulate disk I/O (and to make things
  run slower!).
*/

/*
cc -o stop_queue_solution stop_queue_solution.c -L. -R. -g -lpthread -lthread -pthread_extensions -lposix4
*/

#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"


typedef struct request_struct
{int                    client;
 char                   *buf;
 pthread_t              tid;
 struct request_struct  *next;
} request_t;

request_t               *requests = NULL;
int                     length = 0;
pthread_cond_t          requests_producer = PTHREAD_COND_INITIALIZER;
pthread_cond_t          requests_consumer = PTHREAD_COND_INITIALIZER;
pthread_mutex_t         requests_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_attr_t          attr;
sem_t                   barrier;
int                     GET_DELAY = 200, PROCESS_DELAY = 250;
int                     stop = FALSE;
int                     N_PROD = 2, N_CONS = 2;
int                     n_processed = 0, n_produced = 0;



void print_requests()
{request_t *r = requests;

 while (r != NULL)
   {printf("<Request: %d>\n", r->client);
    r = r->next;
  }
}

 
request_t *get_request()
{static pthread_mutex_t mr  = PTHREAD_MUTEX_INITIALIZER;
 int c;
 request_t *request;
 pthread_t tid = pthread_self();
 char *name = thread_name(tid);

 delay(GET_DELAY, 0);
 pthread_mutex_lock(&mr);
 c=n_produced++;
 pthread_mutex_unlock(&mr);

 request = (request_t *) malloc(sizeof(request_t));
 request->client = c;                        /* Cannot use count here! */
 request->tid = tid;

 DEBUG(printf("[%s] Creating request  %4d\n", name, c));
 return(request);
}


void process_request(request_t *request)
{static pthread_mutex_t mr  = PTHREAD_MUTEX_INITIALIZER;
 pthread_t tid = pthread_self();
 char *name = thread_name(tid);

 delay(PROCESS_DELAY, 0);
 DEBUG(printf("[%s] Processed request %4d [%s]\n",
              name, request->client, thread_name(request->tid)));
 free(request);
 pthread_mutex_lock(&mr);
 n_processed++;
 pthread_mutex_unlock(&mr);
}



request_t *remove_request()
{request_t *request;

 request = requests;
 requests = requests->next;
 length--;
 return(request);
}


void add_request(request_t *request)
{
 request->next = requests;                      /* Insert at head of list */
 requests = request;
 length++;
}


void *producer(void *arg)
{request_t *request;
 while(TRUE)
   {request = get_request();
    pthread_mutex_lock(&requests_lock);
    while ((length >= 10) && (!stop))
      pthread_cond_wait(&requests_producer, &requests_lock);
    add_request(request);
    if (stop) break;
    pthread_mutex_unlock(&requests_lock);
    pthread_cond_signal(&requests_consumer);
  }
 pthread_mutex_unlock(&requests_lock);
 sem_post(&barrier);
 pthread_exit(NULL);
}


void *consumer(void *arg)
{request_t *request;

 while(TRUE)
   {pthread_mutex_lock(&requests_lock);
    while ((length == 0) && (!stop))
      pthread_cond_wait(&requests_consumer, &requests_lock);
    if (stop) break;
    request = remove_request();
    pthread_mutex_unlock(&requests_lock);
    pthread_cond_signal(&requests_producer);
    process_request(request);
  }
 pthread_mutex_unlock(&requests_lock);
 sem_post(&barrier);
 pthread_exit(NULL);
}


void *stopper(void *arg)
{
  sleep(4);
  pthread_mutex_lock(&requests_lock);
  stop = TRUE;                          /* No mutex? Lost wakeup!! */
  pthread_mutex_unlock(&requests_lock);
  printf("Time to stop!\n");
  pthread_cond_broadcast(&requests_producer);
  pthread_cond_broadcast(&requests_consumer);
  pthread_exit(NULL);
}



main(int argc, char **argv)
{int i, j;
 pthread_t tid;

 SEM_INIT(&barrier, NULL,  0); 
 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

 if (argc >= 2) GET_DELAY     = atoi(argv[1]);
 if (argc >= 3) PROCESS_DELAY = atoi(argv[2]);
 if (argc >= 4) N_PROD        = atoi(argv[3]);
 if (argc >= 5) N_CONS        = atoi(argv[4]);
 printf("GET_DELAY (ms) = %d PROCESS_DELAY (ms) = %d N_PROD = %d N_CONS = %d\n",
        GET_DELAY, PROCESS_DELAY, N_PROD, N_CONS);
 PTHREAD_CREATE(&tid, &attr, killer, (void *) 60);

 for (j=0; j < 3; j++)
   {printf("Starting consumers. List length: %d Produced: %d Consumed %d.\n",
           length, n_produced, n_processed);
    for (i=0; i<N_CONS; i++)
      PTHREAD_CREATE(&tid, &attr, consumer, NULL);
    pthread_mutex_lock(&requests_lock);

    while (length != 0) 
      pthread_cond_wait(&requests_producer, &requests_lock);

    printf("Starting producers. List length: %d Produced: %d Consumed %d.\n",
           length, n_produced, n_processed);
    pthread_mutex_unlock(&requests_lock);
    for (i=0; i<N_PROD; i++)
      PTHREAD_CREATE(&tid, &attr, producer, NULL);

    PTHREAD_CREATE(&tid, &attr, stopper, NULL);
    thread_single_barrier(&barrier, N_PROD+N_CONS);
    stop = FALSE;
    printf("All exited. List length: %d Produced: %d Consumed %d.\n",
           length, n_produced, n_processed);
    sleep(4);
   }
 printf("Done\n");
 exit(0);
}

