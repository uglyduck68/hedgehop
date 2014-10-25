/*                two_queues_problem.c                */

/*
  This is the prototypical producer/consumer example done by
  building a singly linked list.  However, this version has
  TWO queues, with a set of producers and consumers for each
  list which operate completely independently.

  Delays are inserted to simulate disk I/O (and to make things
  run slower!).
*/

/*
cc -o two_queues_problem two_queues_problem.c -L. -R. -g -lpthread -lthread -pthread_extensions -lposix4
*/

#define _POSIX_C_SOURCE 199506L

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include "thread_extensions.h"


struct request_struct
{int                    socket_fd;
 char                   *buf;
 pthread_t              tid;
 struct request_struct  *next;
};
typedef struct request_struct request_t;


pthread_attr_t          attr;
int                     GET_DELAY = 100, PROCESS_DELAY = 100;

request_t               *requests_1 = NULL;
pthread_mutex_t         requests_1_lock = PTHREAD_MUTEX_INITIALIZER;
sem_t                   requests_1_length, requests_1_slots;

request_t               *requests_2 = NULL;
pthread_mutex_t         requests_2_lock = PTHREAD_MUTEX_INITIALIZER;
sem_t                   requests_2_length, requests_2_slots;






request_t *get_request()
{static int count = 0;
 static pthread_mutex_t mr  = PTHREAD_MUTEX_INITIALIZER;
 int c;
 request_t *request;
 pthread_t tid = pthread_self();
 char *name = thread_name(tid);

 delay(GET_DELAY, 0);
 pthread_mutex_lock(&mr);
 c=count++;
 pthread_mutex_unlock(&mr);

 request = (request_t *) malloc(sizeof(request_t));
 request->socket_fd = c;                        /* Cannot use count here! */
 request->tid = tid;

 DEBUG(printf("[%s] Creating request %4d\n", name, c));
 return(request);
}

void process_request(request_t *request)
{pthread_t tid = pthread_self();
 char *name = thread_name(tid);

  delay(PROCESS_DELAY, 0);
  DEBUG(printf("[%s] Processed request %4d [%s]\n",
               name, request->socket_fd, thread_name(request->tid)));
  free(request);
}


request_t *remove_1()
{request_t *request;

 pthread_mutex_lock(&requests_1_lock);
 request = requests_1;
 requests_1 = requests_1->next;
 pthread_mutex_unlock(&requests_1_lock);
 return(request);
}


void add_1(request_t *request)
{
 pthread_mutex_lock(&requests_1_lock);
 request->next = requests_1;                    /* Insert at head of list */
 requests_1 = request;
 pthread_mutex_unlock(&requests_1_lock);
}

void *producer_1(void *arg)
{
 while(1)
   {SEM_WAIT(&requests_1_slots);
    add_1(get_request());
    sem_post(&requests_1_length);
  }
}


request_t *remove_2()
{request_t *request;

 pthread_mutex_lock(&requests_2_lock);
 request = requests_2;
 requests_2 = requests_2->next;
 pthread_mutex_unlock(&requests_2_lock);
 return(request);
}


void add_2(request_t *request)
{
 pthread_mutex_lock(&requests_2_lock);
 request->next = requests_2;                    /* Insert at head of list */
 requests_2 = request;
 pthread_mutex_unlock(&requests_2_lock);
}

void *producer_2(void *arg)
{
 while(1)
   {SEM_WAIT(&requests_2_slots);
    add_2(get_request());
    sem_post(&requests_2_length);
  }
}

void *consumer_1(void *arg)
{while(1)
   {SEM_WAIT(&requests_1_length);
    process_request(remove_1());
    sem_post(&requests_1_slots);
  }
}


void *consumer_2(void *arg)
{while(1)
   {SEM_WAIT(&requests_2_length);
    process_request(remove_2());
    sem_post(&requests_2_slots);
  }
}


main(int argc, char **argv)
{pthread_t tid;

 SEM_INIT(&requests_1_slots, NULL, 10);
 SEM_INIT(&requests_2_slots, NULL, 10);
 SEM_INIT(&requests_1_length, NULL,  0);
 SEM_INIT(&requests_2_length, NULL,  0);

 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

 if (argc >= 2) GET_DELAY = atoi(argv[1]);
 if (argc >= 3) PROCESS_DELAY = atoi(argv[2]);
 printf("GET_DELAY (ms) = %d PROCESS_DELAY (ms) = %d\n",
        GET_DELAY, PROCESS_DELAY);

 PTHREAD_CREATE(&tid, &attr, consumer_1, NULL);
 PTHREAD_CREATE(&tid, &attr, consumer_2, NULL);
 PTHREAD_CREATE(&tid, &attr, producer_1, NULL);
 PTHREAD_CREATE(&tid, &attr, producer_2, NULL);

 sleep(10);
 exit(0);
}
