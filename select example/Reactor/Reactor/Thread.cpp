/**
 * @file	Thread.h
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 * @date	2014-05-14
 *
 * This is implementation of Thread class that is wrapper of pthread or OpenThreads.
 */
#include <stdio.h> 
#include <stdlib.h> 

#include "X1.h"

#ifdef _X1_LINUX_
#include <sys/time.h>	// for now and gettimeofday
#endif

#include <time.h>
#include <signal.h> 

#ifdef _WIN32
#include <Windows.h>
#endif
#include <sys/timeb.h>

#include "Thread.h" 

using namespace std; 


NS_X1_START

long Thread::m_id = 0; 

pthread_attr_t Thread::m_attr; 

void* Thread::ThreadHandler(void* arg) 
{ 
	signal(SIGINT/*SIGUSR1*/, InterruptHandler); 

	Thread* thread = (Thread*) arg; 

	try 
	{ 
		thread->Run(); 
	} 
	//
	// On WIN32 raise API send the signal, But don't catch it.
	//
	catch (InterruptedException&) 
	{ 
		thread->m_isInterrupted = true; 
	} 
	catch (...) 
	{ 
	} 

	thread->m_state = DIED; 

	if (thread->m_joinning) 
	{ 
		pthread_mutex_lock(&thread->m_mutexJoin); 
		pthread_cond_broadcast(&thread->m_condJoin); 
		pthread_mutex_unlock(&thread->m_mutexJoin); 
	} 

	return NULL; 
} 

void Thread::InterruptHandler(int sigInt) 
{ 
	throw InterruptedException("Thread interrupted");     
} 

Thread::Thread() 
{ 
	Init(); 
}  

Thread::~Thread() 
{ 
	pthread_attr_destroy(&m_attr); 
	pthread_mutex_destroy(&m_mutexJoin); 
	pthread_mutex_destroy(&m_mutexSync); 
	pthread_cond_destroy(&m_condJoin); 
} 

void Thread::Init() 
{ 
	m_joinning		= false; 
	m_isInterrupted	= false; 

	pthread_mutex_init(&m_mutexJoin, NULL); 
	pthread_mutex_init(&m_mutexSync, NULL); 
	pthread_cond_init(&m_condJoin, NULL); 

	m_state = Thread::INIT; 

	pthread_mutex_lock(&m_mutexSync); 

	// create the attribute of thread creation.
	if (m_id == 0) 
	{ 
		pthread_attr_init(&m_attr); 
		pthread_attr_setdetachstate(&m_attr, PTHREAD_CREATE_DETACHED); 
	} 

	// set thread id automatically
	m_nId	= m_id;

	m_id++;    

	pthread_mutex_unlock(&m_mutexSync); 
} 

int Thread::Start() 
{ 
	if (m_state == STARTED) 
	{ 
		throw IllegalThreadStateException("Thread is running"); 
	} 
	else if (m_state == INIT) 
	{ 
		m_state = STARTED; 
		if (pthread_create(&m_thread, &m_attr, ThreadHandler, this) != 0)
		{
			printf("Error: fail to create thread(%s, %d)\n", __FILE__, __LINE__);
		}

		printf("Info: thread(%d) is created\n", m_thread);
	} 
	else if (m_state == DIED) 
	{ 
		throw IllegalThreadStateException("Thread is dead"); 
	} 

	return 0;	///< 0 if successful like OpenThreads
} 

/**
 * @return	0 if success
 * @return	!= 0 if error
 */
int Thread::Join() 
{ 
	int		nRet	= 0;

	if (m_state == STARTED) 
	{ 
		if ((nRet = pthread_mutex_lock(&m_mutexJoin)) != 0)
		{
			printf("Error: errno: %d: thread: %d, fail to call pthread_mutex_lock in Join\n", nRet, m_thread);
		}

		m_joinning = true; 

		if ((nRet = pthread_cond_wait(&m_condJoin, &m_mutexJoin)) != 0)
		{
			printf("Error: errno: %d: thread: %d, fail to call pthread_cond_timedwait in Join\n", nRet, m_thread);
		}

		m_joinning = false; 

		if ((nRet = pthread_mutex_unlock(&m_mutexJoin)) != 0)
		{
			printf("Error: errno: %d: thread: %d, fail to call pthread_mutex_unlock in Join\n", nRet, m_thread);
		}
	} 

	return nRet;	///< 0 if successful like OpenThreads
} 

/**
 * @return	0 if success
 * @return	!= 0 if error
 */
int Thread::Join(unsigned long msec) 
{ 
	int		nRet	= 0;

	if (m_state == STARTED) 
	{ 
		struct timeval		now; 
		struct _timeb currSysTime;
struct timespec		timeout; 
const DWORD NANOSEC_PER_MILLISEC = 1000000;
		
		// to convert msec to sec + msec
//		ldiv_t t = ldiv(msec, 1000); 

//		gettimeofday(&now, NULL); 
_ftime(&currSysTime);
		
		timeout.tv_sec	= (long)currSysTime.time;//now.tv_sec + t.quot; 
		timeout.tv_nsec	=  NANOSEC_PER_MILLISEC * currSysTime.millitm;//now.tv_usec * 1000 + t.rem * 1000000; // overflow!
			
//		if ((nRet = pthread_mutex_init(&m_mutexJoin, NULL)) != 0)
//			printf("Error: pthread_mutex_init fails\n");

		if ((nRet = pthread_mutex_lock(&m_mutexJoin)) != 0)
		{
			printf("Error: errno: %d: thread: %d, fail to call pthread_mutex_lock\n", nRet, m_thread);
		}

		m_joinning = true; 

		while (nRet == 0)
		{
			// I don't know why pthread_cond_timedwait fails always??? 별 지랄을 다 해도 계속 에러가 나네..젠장...
			if ((nRet = pthread_cond_timedwait(&m_condJoin, &m_mutexJoin, &timeout)) != 0)
			{
				// EPERM(1) means mutex is not mine at that time!!!
				printf("Error: errno: %d: thread: %d, fail to call pthread_cond_timedwait\n", nRet, m_thread);
			}

			if (nRet == ETIMEDOUT)
				break;
		}

		m_joinning = false; 

		pthread_mutex_unlock(&m_mutexJoin); 
	} 

	return nRet;
} 

ret_t Thread::Interrupt() 
{ 
	int		nRet	= 0;

	// To use raise API don't catch InterruptedException.
#if	0
	return (ret_t)raise(SIGINT);
#endif

	// Win32 pthread_kill don't send signal.
	if ((nRet = pthread_kill(m_thread, SIGINT/*SIGUSR1*/)) != 0)
	{
		// nRet = ESRCH(3): 
		printf("Error: errno: %d: thread: %d: fail to call pthread_kill\n", nRet, m_thread);
	}

	if (nRet == 0) 
		return X1_OK;

	return X1_FAIL;
} 

bool Thread::IsInterrupted() 
{ 
	return m_isInterrupted; 
} 

bool Thread::IsAlive() 
{ 
	return m_state == STARTED; 
} 


NS_X1_END