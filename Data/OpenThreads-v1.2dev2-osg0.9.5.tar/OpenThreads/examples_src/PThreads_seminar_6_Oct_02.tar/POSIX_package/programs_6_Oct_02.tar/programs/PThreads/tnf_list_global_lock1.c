/*                tnf_list_global_lock1.c                */

/*

  Make a list of people (with names like "Jan_1234") and their salaries.
  Then spawn some threads to run down that list and give raises to all
  the people I like.  Spawn some more threads to delete from the list
  the people you don't like.  (Some people I like might also be people
  you don't like.)

  Insert delays during the raising and deleting functions to simulate disk
  I/O and make the program more interesting.

  Now consider the following parameters:
        o  Raise delay
        o  Liquidation delay
        o  Time for average search

  Which of the various locking designs works fastest for which combination
  of the above?



  This program allocates one global mutex to protect everything.

  GLOBAL_LOCK

         __________________________________
        |    Name      |  salary  |  next  |
        |  "Jan_123"   |  100000  |    o---|------>
        |______________|__________|________|

*/

/*
cc -o list_global_lock list_global_lock.c -L. -R. -g -lpthread -lthread -pthread_extensions -lposix4
*/


#define _POSIX_C_SOURCE 199506L

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include "thread_extensions.h"

#include <tnf/probe.h>

struct person_struct
{char *                 name;
 int                    salary;
 struct person_struct * next;
};
typedef struct person_struct person_t;


sem_t                   barrier;
thread_fifo_mutex_t     people_lock = THREAD_FIFO_MUTEX_INITIALIZER;
person_t                        people;

int E_THREADS           = 1;            /* # threads running liquidate */
int F_THREADS           = 10;           /* # threads running raise */
int N_PEOPLE            = 1000;         /* # of people in initial list */
int N_FRIENDS           = 100;          /* # of people to give raises */
int LIQUIDATE_DELAY     = 100;          /* sleep time during liquidation */
int RAISE_DELAY         = 20;           /* sleep time during raise giving */


int PTHREAD_CREATE(pthread_t *new_thread_ID,
                   const pthread_attr_t *attr,
                   void * (*start_func)(void *), void *arg)
{
     thr_create(0, NULL, start_func, arg, 0x00000001, new_thread_ID);
}

void count_conflicts(int i)             /* Note the encapsulation */
{static int count=0, old_count=0, max_count = 0;
 static pthread_mutex_t count_lock = PTHREAD_MUTEX_INITIALIZER;

 pthread_mutex_lock(&count_lock);
 count += i;
 if (i == -1) printf("Conflicts: %d\n", max_count);
 if (count > max_count)
   max_count = count;
 pthread_mutex_unlock(&count_lock);
}    

void count_finds(int i)         /* Note the encapsulation */
{static int count=0, old_count=0, max_count = 0;
 static pthread_mutex_t count_lock = PTHREAD_MUTEX_INITIALIZER;

 pthread_mutex_lock(&count_lock);
 count += i;
 if (i == -1) printf("Total raises + liquidations: %d\n", max_count);
 if (count > max_count)
   max_count = count;
 pthread_mutex_unlock(&count_lock);
}  


void print_people(person_t *p)  /* Debugging function. Not 100% MT safe */
{int i = 0;

 thread_fifo_mutex_lock(&people_lock);
 while(p != NULL)
   {printf("(%s  %d) ", p->name, p->salary);
    p = p->next;
    i++;
    if ((i % 5) == 0) printf("\n");
  }
 thread_fifo_mutex_unlock(&people_lock);
}


person_t *find_person(char *name)
{person_t *p = &people, *p1, *p2;

 p1 = p->next;
 while(p1 != NULL)
   {if (strcmp(p1->name, name) == 0)
      /* Found! Return previous, Still holding p->lock ! */
      {count_finds(1); return(p);}
    p = p1;
    p1 = p->next;
  }
 return(NULL);                           /* Couldn't find 'em!  Too bad. */
}


void give_raise(person_t *p)
{
  if (p == NULL) return;
  p->next->salary++;
  delay(RAISE_DELAY, 0);
}


pthread_mutex_lock_conflicts(thread_fifo_mutex_t *people_lock)
{
       thread_fifo_mutex_lock(people_lock);
  }

void *give_friends_raise(void *arg)
{person_t *p, *friends = (person_t *) arg;

 TNF_PROBE_0(give_friends_raise_start,  "lgl", "");

  while(friends != NULL)
    {pthread_mutex_lock_conflicts(&people_lock);
    TNF_PROBE_0(give_friend_raise_start,  "lgl", "");
     p = find_person(friends->name);
    TNF_PROBE_0(give_friend_raise_middle,  "lgl", "");
     give_raise(p);
    TNF_PROBE_0(give_friend_raise_end,  "lgl", "");
     thread_fifo_mutex_unlock(&people_lock);
     friends = friends->next;
     /*     sched_yield(); */
   }
 TNF_PROBE_0(give_friends_raise_end,  "lgl", "");
  sem_post(&barrier);
}


void liquidate_person(person_t *p)
{person_t  *p1;

 p1 = p->next;
 p->next = p1->next;

 DEBUG(printf("Killing: (%s %d)\n", p1->name, p1->salary));
 free(p1->name);
 free(p1);
 delay(LIQUIDATE_DELAY, 0);
 return;
}


void *liquidate_enemies(void *arg)
{person_t *p, *enemies = (person_t *) arg;

 TNF_PROBE_0(liquidate_enemies_start,  "lgl", "");
  while(enemies != NULL)
    {pthread_mutex_lock_conflicts(&people_lock);
    TNF_PROBE_0(liquidate_enemy_start,  "lgl", "");
     p = find_person(enemies->name);
    TNF_PROBE_1(liquidate_enemy_middle,  "lgl", "", tnf_int, salary, p->salary);
     if (p) liquidate_person(p);
    TNF_PROBE_0(liquidate_enemy_end,  "lgl", "");
     thread_fifo_mutex_unlock(&people_lock);
     enemies = enemies->next;
     /*      sched_yield(); */
   }
  TNF_PROBE_0(liquidate_enemies_end,  "lgl", "");
 DEBUG({printf("\nAfter the purge...\n"); print_people(people.next);});
 sem_post(&barrier);
}


person_t *make_list_of_friends(int seed1)
{int i, r;
 unsigned int seed = (int) seed1;
 char s[20], *s1;
 person_t *p, friends;

 friends.next = NULL;

 for (i=0; i<N_FRIENDS; i++)   
   {r = rand_r(&seed) % N_PEOPLE;
    sprintf(s, "Jan_%d", r);
    s1 = (char *) malloc(strlen(s)+1);
    strcpy(s1, s);
    p = (person_t *) malloc(sizeof(person_t));
    p->name = s1;
    p->next = friends.next;
    friends.next = p;
  }
 return(friends.next);
}


person_t *make_list_of_enemies(int s)
{
  return(make_list_of_friends(s));
}


void add_to_people(char *name)
{person_t *p;

 p = (person_t *) malloc(sizeof(person_t));
 p->name = name;
 thread_fifo_mutex_lock(&people_lock);
 p->next = people.next;
 p->salary = 10;
 people.next = p;
 thread_fifo_mutex_unlock(&people_lock);
}


void make_list_of_people()
{int i, n;
 char s[20], *s1;

 for (i=0; i<N_PEOPLE; i++)
   {sprintf(s, "Jan_%d", i);
    s1 = (char *) malloc(strlen(s)+1);
    strcpy(s1, s);
    add_to_people(s1);
  }
}


main(int argc, char *argv[])
{int i;
 pthread_attr_t attr;
  pthread_t tid;

 SEM_INIT(&barrier, NULL, 0);
 PTHREAD_ATTR_INIT(&attr);
 pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);
 people.next = NULL;
 people.name = (char *) -1;                     /* SEGV if you touch this ! */

 if (argc >= 2) LIQUIDATE_DELAY = atoi(argv[1]);
 if (argc >= 3) RAISE_DELAY     = atoi(argv[2]);
 if (argc >= 4) N_PEOPLE        = atoi(argv[3]);
 if (argc >= 5) N_FRIENDS       = atoi(argv[4]);
 if (argc >= 6) E_THREADS       = atoi(argv[5]);
 if (argc >= 7) F_THREADS       = atoi(argv[6]);

 printf(
 "LIQUIDATE=%d RAISE=%d N_PEOPLE=%d N_FRIENDS=%d E_THREADS=%d F_THREADS=%d\n",
 LIQUIDATE_DELAY, RAISE_DELAY, N_PEOPLE, N_FRIENDS, E_THREADS, F_THREADS );

 make_list_of_people();
 iobench_start();
 for (i=0; i<F_THREADS; i++)
   PTHREAD_CREATE(&tid, &attr, give_friends_raise, make_list_of_friends(i*10));
 for (i=0; i<E_THREADS; i++)
   PTHREAD_CREATE(&tid, &attr, liquidate_enemies, make_list_of_enemies(i));

 thread_single_barrier(&barrier, F_THREADS + E_THREADS);/* Instead of join()! */
 iobench_end();
 count_finds(-1);
 count_conflicts(-1);
 iobench_report();
 pthread_exit(0);
}

