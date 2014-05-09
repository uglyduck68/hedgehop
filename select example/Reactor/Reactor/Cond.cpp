/**
 * @file	Cond.cpp
 *
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 *
 * This template implementation file is included to Cond.h.
 */
#include "Cond.h"

NS_X1_START


Cond::Cond()
{
#if	defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	memset(&m_Condv, 0, sizeof(m_Condv));
	InitializeConditionVariable(&m_Condv);
#elif defined(PTHREAD_H)
	if(pthread_cond_init(&m_Condv, 0) != 0)
	{
		X1_TRACE();
	}
#endif
}

Cond::~Cond(void)
{
#if	defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
#elif defined(PTHREAD_H)
	if(pthread_cond_destroy(&m_Condv) != 0)
	{
		X1_TRACE();
	}
#endif
}

ret_t Cond::Wait(Mutex& mutex)
{
#if	defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	SleepConditionVariableCS(&m_Condv, (thread_mutex_t *)&m_Mutex.m_Mutex, timeout_msec);
#elif defined(PTHREAD_H)

	if (pthread_cond_wait(&m_Condv, (thread_mutex_t *)&mutex.m_Mutex) == 0)
		return X1_OK;

	return X1_FAIL;
#endif
}

ret_t Cond::Notify()
{
#if	defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	WakeConditionVariable(&m_Condv);
#elif defined(PTHREAD_H)

	if (pthread_cond_signal(&m_Condv) == 0)
		return X1_OK;

	return X1_FAIL;
#endif
}

ret_t Cond::NotifyAll()
{
#if	defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	WakeAllConditionVariable(&m_Condv);
#elif defined(PTHREAD_H)

	if (pthread_cond_broadcast(&m_Condv) == 0)
		return X1_OK;

	return X1_FAIL;
#endif
}


NS_X1_END