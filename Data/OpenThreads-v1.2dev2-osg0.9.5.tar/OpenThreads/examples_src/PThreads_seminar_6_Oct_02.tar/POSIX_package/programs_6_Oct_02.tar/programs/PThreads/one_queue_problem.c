/*                one_queue_problem.c                */

/*
  This is the prototypical producer/consumer example done by
  building a singly linked list.  Note the use of the semaphore
  to prevent the consumers from running when the list is empty.
  Unfortunately, there's nothing to prevent the list from getting
  infinitely long...

  Delays are inserted to simulate disk I/O (and to make things
  run slower!).
*/


/*
cc -o one_queue_problem one_queue_problem.c -L. -R. -g -lpthread -lthread -pthread_extensions -lposix4
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
pthread_mutex_t         requests_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_attr_t          attr;
sem_t                   requests_length;
int			max_length_empirical = 0, sval;
int                     GET_DELAY = 100, PROCESS_DELAY = 250;
int                     N_PROD = 2, N_CONS = 2;



void print_requests()
{request_t *r = requests;

 while (r != NULL)
   {printf("<Request: %d>\n", r->client);
    r = r->next;
  }
}


request_t *get_request()
{static int count = 0;
 static pthread_mutex_t mr  = PTHREAD_MUTEX_INITIALIZER;
 int c;
 request_t *request;
 pthread_t tid = pthread_self();

 delay(GET_DELAY, 0);
 pthread_mutex_lock(&mr);
 c=count++;
 pthread_mutex_unlock(&mr);

 request = (request_t *) malloc(sizeof(request_t));
 request->client = c;                        /* Cannot use count here! */
 request->tid = pthread_self();

 DEBUG(printf("[%s] Creating request  %4d\n", thread_name(tid), c));
 return(request);
}


void process_request(request_t *request)
{pthread_t tid = pthread_self();
  delay(PROCESS_DELAY, 0);
  DEBUG(printf("[%s] Processed request %4d [%s]\n", thread_name(tid),
               request->client, thread_name(request->tid)));
  free(request);
}


request_t *remove_request()
{request_t *request;

 pthread_mutex_lock(&requests_lock);
 request = requests;
 requests = requests->next;
 pthread_mutex_unlock(&requests_lock);
 return(request);
}


void add_request(request_t *request)
{
 pthread_mutex_lock(&requests_lock);
 request->next = requests;                      /* Insert at head of list */
 requests = request;
 sem_getvalue(&requests_length, &sval);
 if (sval+1 > max_length_empirical)
   max_length_empirical = sval+1;
 pthread_mutex_unlock(&requests_lock);
}


void *producer(void *arg)
{request_t      *request;

 while(TRUE)
   {
     request = get_request();
     add_request(request);
     sem_post(&requests_length);
   }
}


void *consumer(void *arg)
{request_t      *request;

 while(TRUE)
   {
     SEM_WAIT(&requests_length);
     request = remove_request();
     process_request(request);
   }
}


main(int argc, char **argv)
{int i;
pthread_t tid;

 SEM_INIT(&requests_length, NULL,  0);

 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

 if (argc >= 2) GET_DELAY = atoi(argv[1]);
 if (argc >= 3) PROCESS_DELAY = atoi(argv[2]);
 if (argc >= 4) N_PROD        = atoi(argv[3]);
 if (argc >= 5) N_CONS        = atoi(argv[4]);
 printf("GET_DELAY (ms) = %d PROCESS_DELAY (ms) = %d N_PROD = %d N_CONS = %d\n",
        GET_DELAY, PROCESS_DELAY, N_PROD, N_CONS);

 for (i=0; i<N_CONS; i++)
   PTHREAD_CREATE(&tid, &attr, consumer, NULL);
 for (i=0; i<N_PROD; i++)
   PTHREAD_CREATE(&tid, &attr, producer, NULL);

 sleep(20);
 sem_getvalue(&requests_length, &sval);
 printf("Done.\nCurrent List length: %d Max length was: %d\n",
	sval, max_length_empirical);
 exit(0);
}
