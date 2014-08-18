/**
* @file		Thread.cpp
* @auther	Younghwan Kim<uglyduck68@gmail.com>
* @version	0.1
* @date		20140816
* @brief	implementation file for Thread class.
*/
#include "Thread.h"
#include "Guard.h"

#include <stdio.h>

NS_X1_USE

Thread::Thread(void)	: 
	m_Running(NOT_CREATED), m_Detached(0), m_nJoinable(0)
{

}


Thread::~Thread(void)
{
	if (m_Running == 1 && m_Detached == 0) 
	{
		sp_thread_detach(m_h);
	}

	if (m_Running == RUNNING) 
	{
		/** thread cancellation is *NOT* implemented on Windows */
		sp_thread_cancel(m_h);
	}

	sp_thread_destroy(m_h);
}

sp_thread_t&	Thread::Self()
{
	return m_h;//sp_thread_self();
}

/*
* @function		GetId()
* @return		return thread id that is printable.
*/
sp_thread_id_t	Thread::GetId()
{
	return sp_thread_get_id(m_h);
}

static sp_thread_result_t	SP_THREAD_CALL RunThread(void* pArg)
{
	sp_thread_result_t	ret;
	Thread*	pThread	= static_cast<Thread*>(pArg);

	/// run thread function
	ret	= pThread->Run(pThread);

	pThread->m_Running	= Thread::DEAD;

#if	_BUILD_USE_PTHREAD_ == 1 || _BUILD_USE_PTHREAD_WIN32_ == 1
	LOG("thread %lu signal\n",  (long unsigned int)pThread->GetId());

	pThread->Signal();
#endif

	return ret;
}

int	Thread::Start()
{
	sp_thread_attr_t attr;

	sp_thread_attr_init( &attr );
	sp_thread_attr_setdetachstate( &attr, SP_THREAD_CREATE_DETACHED );

	/** I always create thread with detached status */
    int result = sp_thread_create(&m_h, &attr, RunThread, this);

    if (result == 0) 
	{
        m_Running	= RUNNING;
		m_Detached	= 1;
    }

	sp_thread_attr_destroy(&attr);

    return result;
}

/** conditional variable that signal */
int	Thread::Signal()
{
	Guard<Mutex> guard(m_MutexJoin);

	if (m_nJoinable == 1)
	{
		m_CondJoin.Signal();
	}	

	return 0;
}


/**
* @function	Join
* @brief	wait the signal 
* @return	0 always
*/
int	Thread::Join()
{
    int result = 0;

	if (m_Running == RUNNING)
	{
		/** I am waiting when only running */

#if _BUILD_USE_PTHREAD_WIN32_ == 1
		LOG("thread %lu waiting\n",  (long unsigned int)GetId());
#else
		LOG("thread %lu waiting\n",  (long unsigned int)GetId());
#endif


		Wait();

	}


#if	_BUILD_USE_PTHREAD_WIN32_ == 1
	LOG("thread %lu wait is done\n",  (long unsigned int)GetId());
#else
	LOG("thread %lu wait is done\n",  (long unsigned int)GetId());
#endif

    return result;
}

/** conditional variable that wait */
int	Thread::Wait()
{
	Guard<Mutex> guard(m_MutexJoin);

	// I will wait the signal
	m_nJoinable		= 1;

#if	_BUILD_USE_WIN32_ONLY_ == 1
	sp_thread_join(m_h, NULL);
#else
	m_CondJoin.Wait(m_MutexJoin);
#endif

	m_nJoinable		= 0;	

	return 0;
}


/*
* I always create thread with  detached status.
* So this function is *Not* uselesee.
*/
int	Thread::Detach()
{
    int result = -1;

    if (m_Running == 1 && m_Detached == 0)
	{
        result = sp_thread_detach(m_h);

        if (result == 0) 
		{
            m_Detached = 1;
        }
    }

    return result;
}

