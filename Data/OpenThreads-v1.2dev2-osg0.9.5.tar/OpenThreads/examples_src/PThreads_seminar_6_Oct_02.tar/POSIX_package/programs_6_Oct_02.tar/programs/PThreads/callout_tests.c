/*                callout_tests.c                */

/*  
================================================================
  I want to read from an unreliable device and interrupt it if
it should fail to return from the read after some amount of time.
So I set a per-thread timer and longjmp() out of the device
driver should it expire.
================================================================  


cc -o callout_tests callout_tests.c -L. -R. -lcallout -g  -lpthread -lthread -pthread_extensions -lposix4
*/

#define _POSIX_C_SOURCE 199506L

#include <stdio.h>
#include <assert.h>
#include <pthread.h>
#include <setjmp.h>
#include "callout.h"
#include "thread_extensions.h"





int                     TIMEOUT = 3, DEVICE_SPEED = 3;
pthread_key_t           JMPBUF_KEY;


void my_SigHandler(int signo)
{void                   *envp;
 pthread_t              tid = pthread_self();
 char                   *name = thread_name(tid);

 /*   Note that printf() and thread_name() are not signal safe! */
 printf("Got signal in thread: %s. Signal %d\n", name, signo);
 envp = pthread_getspecific(JMPBUF_KEY);
 siglongjmp((int *) envp, 1);
}

void slow_device_interrupter(void *arg)
{pthread_t *ptid;

 ptid = (pthread_t *) arg;
 printf("Interrupting the device on thread %s...\n", thread_name (*ptid));
 pthread_kill(*ptid, SIGUSR1);   /* Interrupt the device. */
}


device_read(int speed)  /* Fake a read from the actual device */
{
  delay(speed*1000, 0);
}


void call_device(int speed, int timeout)
{int                    timer_number;
 pthread_t              tid = pthread_self();

 timer_number = thread_settimer(timeout, slow_device_interrupter,
                                 (void *) &tid); /* Should not pass tid! */
 device_read(speed);
 thread_deletetimer(timer_number);
 printf("Device responded in time!\n");
}


/* This thread doesn't do anything useful for this program.  It does
   prove that you can have different threads calling sigwait() on 
   different signal sets.
*/
void *my_sigwaiter(void *arg)
{int            sig, err;
 sigset_t       s;
 
 sigfillset(&s);
 pthread_sigmask(SIG_BLOCK, &s, NULL);  /* Take no interrupts */

 sigemptyset (&s);
 sigaddset (&s, SIGINT);
 sigaddset (&s, SIGTSTP);
 sigaddset (&s, SIGQUIT);
 sigaddset (&s, SIGHUP);

 /* User program waits for everything EXCEPT USR1 and ALRM */
 while(1)
    {err = sigwait(&s, &sig);
    if (err != 0) {
        printf("%s\n", strerror(err));
        abort();
     }
     switch (sig)
       {case SIGINT  :  printf("Exit on SIGINT\n"), exit(1);
        case SIGTSTP :  printf("Exit on SIGSTP\n"), exit(1);
        case SIGQUIT :  printf("Exit on SIGQUIT\n"), exit(1);

        default:        printf("Default handler for signal: %d\n", sig);
      }
   }
}


main(int argc, char *argv[])
{jmp_buf                        env;
 sigset_t                       s, s1, s2;
 static struct sigaction        action; 
 int                            i;
 pthread_t                      tid;


 
 /* Initialize things */
 action.sa_handler = (void (*)(void)) my_SigHandler;
 sigaction(SIGUSR1, &action, NULL);

 sigfillset(&s);
 pthread_sigmask(SIG_BLOCK, &s, &s2); /* Block everything, then... */
 sigemptyset(&s);
 sigaddset(&s, SIGUSR1);
 pthread_sigmask(SIG_UNBLOCK, &s, &s1); /* Unblock USR1 */

 PTHREAD_CREATE(&tid, NULL, my_sigwaiter, NULL);
 pthread_key_create(&JMPBUF_KEY, NULL);

#if !defined(__sun) && !defined(__alpha)
 initialize_thread_timer();
#endif

 /* The real program begins here. */
   
 for (i=0; i < 4; i++)

   {DEVICE_SPEED = i; TIMEOUT = 4 - i;
    printf("DEVICE_SPEED=%d TIMEOUT=%d\n", DEVICE_SPEED, TIMEOUT);
    if (sigsetjmp(env, 1) != 0)
      {printf("Device timed out!\n");
       continue;
     }
    pthread_setspecific(JMPBUF_KEY, (void *)env);
    call_device(DEVICE_SPEED, TIMEOUT);
  }

 printf("Done\n");
 exit(0);
}

