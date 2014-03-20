/*                recover.c                */

/*

*/

/*
cc -o cancellation cancellation.c -L. -R. -g -lpthread -lthread -pthread_extensions -lposix4
*/

#define _POSIX_C_SOURCE 199506L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include "thread_extensions.h"


/*
   ================================================================
                        Recover Mutex Lock
   ================================================================
*/


#define RECOVER_MUTEX_INITIALIZER \
 {PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER, \
    NULL, NULL, 0, 0, FALSE, NULL_TID}


typedef pthread_dmutex_t recover_mutex_t;


extern  int     recover_mutex_init(recover_mutex_t *, pthread_mutexattr_t *);
extern  int     recover_mutex_destroy(recover_mutex_t *);
extern  int     recover_mutex_lock(recover_mutex_t *);
extern  int     recover_mutex_trylock(recover_mutex_t *);
extern  int     recover_mutex_unlock(recover_mutex_t *);




int recover_mutex_lock(recover_mutex_t *m)
{int old, i;

  pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old);
  i = pthread_dmutex_lock(m);
  pthread_setcancelstate(old, &old);
  return(i);
}



int recover_mutex_unlock(recover_mutex_t *m)
{int old, i;

  pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old);
  i = pthread_dmutex_unlock(m);
  pthread_setcancelstate(old, NULL);
  return(i);
}



/*
   ================================================================
                        Main Program
   ================================================================
*/


pthread_attr_t  attr;


sem_t           death_lock;
pthread_cond_t  wait_cv      = PTHREAD_COND_INITIALIZER;

int answer;             /* Protected by death_lock */
pthread_t tid;

typedef struct _item
{int            data1;
 int            index1;
 int            data2;
 int            index2;
 int            date;
} item_t;


typedef struct _transaction
{item_t         *item;
 int            valid;
 pthread_mutex_t lock;
} transaction_t;




transaction_t transaction;

recover_mutex_t db_lock;
int db[2];
int db_date;
int date;




void print_db()
{int i;

 printf("db_date: %d\n", db_date);

 for (i=0; i<2; i++)
   printf("db[%d] = %d\n", i, db[i]);
}
void *commit(item_t *item)
{
  recover_mutex_lock(&db_lock);
  delay(10,100);
  db[item->index1] = item->data1;
  delay(10,100);
  db[item->index2] = item->data2;
  delay(10,100);
  db_date = item->date;
  recover_mutex_unlock(&db_lock);
}

void *tester(void *arg)
{int i, alive;
 item_t *item;

 while (TRUE)
   {delay(10, 100);
    alive = !pthread_kill(tid, NULL);
    if (alive) continue;
    printf("Recovering!");
    print_db();
    print_dmutex(&db_lock);
    if (db_lock.owned)
      {printf("Not locked!");
       db_lock.owned = NULL;
       if ( (db_date < date) && transaction.valid)
         {printf("Locked and out of date!");
          commit(transaction.item);
        }
       else
         printf("Locked, but in date!");
     }
  }
}
void *canceller(void *arg)
{int i;
 item_t *item;

 while (TRUE)
   {delay(99, 1000);
    printf("Cancelling...\n");
    pthread_cancel(tid);
  }
}



void *insert(item_t *item)
{int old;

  pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, &old);
  pthread_mutex_lock(&transaction.lock);
  transaction.item = item;
  transaction.valid = TRUE;
  pthread_mutex_unlock(&transaction.lock);
  pthread_setcanceltype(old, NULL);
  commit(item);
  pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, &old);
  pthread_mutex_lock(&transaction.lock);
  transaction.valid = FALSE;
  pthread_mutex_unlock(&transaction.lock);
  
  pthread_setcanceltype(old, NULL);
}

void *start_inserting(void *arg)
{int i;
 item_t *item;

 pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
 item = (item_t *) malloc(sizeof(item_t));
 for (i=0; i<200; i++)
   {item->date = date++;
    item->index1 = 1;
    item->data1 =  date*2;
    item->index2 = 2;
    item->data2 =  date*4;
    insert(item);
  }
}

void *start_inserts()
{int i, pid, n_cancelled=0, status, err;
 pthread_t tid0, tid1;

 PTHREAD_CREATE(&tid0, &attr, tester, (void *)NULL);
 PTHREAD_CREATE(&tid1, &attr, canceller, (void *)NULL);


 for (i=0; i<20; i++)
   {PTHREAD_CREATE(&tid, &attr, start_inserting, (void *)NULL);
   err = pthread_join(tid, (void **) &status);
    if ((void *)status == (void *)PTHREAD_CANCELED) n_cancelled++;

    printf("Thread %d joined, err=%d, candel=%d\n", tid, err, n_cancelled );
  }
 printf("Finished\n");
}


main()
{int i;

 PTHREAD_ATTR_INIT(&attr);
 pthread_dmutex_init(&db_lock, NULL);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);/* Also default */
 SEM_INIT(&death_lock, NULL, 1);

 for (i=0; i<2; i++)
   start_inserts();

 printf("Done\n");
 exit(0);
}
