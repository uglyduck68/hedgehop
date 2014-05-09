/**
 * @file	Cond.cpp
 *
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 *
 * This template implementation file is included to Cond.h.
 */
#include "Cond.h"

NS_X1_START


template<typename L>
Cond<L>::Cond(/*const*/ L& mutex) : m_Mutex(mutex)
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

template<typename L>
Cond<L>::~Cond(void)
{
#if	defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
#elif defined(PTHREAD_H)
	if(pthread_cond_destroy(&m_Condv) != 0)
	{
		X1_TRACE();
	}
#endif
}

template<typename L>
ret_t Cond<L>::Wait(int32_t timeout_msec)
{
#if	defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	SleepConditionVariableCS(&m_Condv, (thread_mutex_t *)&m_Mutex.m_Mutex, timeout_msec);
#elif defined(PTHREAD_H)

	if (pthread_cond_timedwait(&m_Condv, (thread_mutex_t *)&m_Mutex.m_Mutex, 0) == 0)
		return X1_OK;

	return X1_FAIL;
#endif
}

template<typename L>
ret_t Cond<L>::Notify()
{
#if	defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	WakeConditionVariable(&m_Condv);
#elif defined(PTHREAD_H)

	if (pthread_cond_signal(&m_Condv) == 0)
		return X1_OK;

	return X1_FAIL;
#endif
}

template<typename L>
ret_t Cond<L>::NotifyAll()
{
#if	defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	WakeAllConditionVariable(&m_Condv);
#elif defined(PTHREAD_H)

	if (pthread_cond_broadcast(&m_Condv) == 0)
		return X1_OK;

	return X1_FAIL;
#endif
}

//
// following functions just for ease interface
//
template<typename L>
ret_t Cond<L>::Lock()
{
	return m_Mutex.Lock();
}
	
template<typename L>
ret_t Cond<L>::Unlock()
{
	return m_Mutex.Unlock();
}

NS_X1_END