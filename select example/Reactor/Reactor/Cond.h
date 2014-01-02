#pragma once

#include "X1.h"
#include "Mutex.h"

NS_X1_START

/**
 * @class	Cond
 * @brief	class for conditional variables
 */
class DECL_SPEC_DLL Cond
{
private:
	thread_cond_t		m_Cond;
	const Mutex&		m_Mutex;

public:
	Cond(const Mutex& mutex) : m_Mutex(mutex)
	{
		#if	defined(OS_WINDOWS) && !defined(PTHREAD_H)
		memset(&m_Cond, 0, sizeof(m_Cond));
		InitializeConditionVariable(&m_Cond);
		#else
		if(pthread_cond_init(&m_Cond, 0) != 0)
		{
			X1_TRACE();
		}
		#endif
	}

	~Cond(void)
	{
		#if	defined(OS_WINDOWS) && !defined(PTHREAD_H)
		#else
		if(pthread_cond_destroy(&m_Cond) != 0)
		{
			X1_TRACE();
		}
		#endif
	}

	void Wait(int32_t timeout_msec)
	{
		#if	defined(OS_WINDOWS) && !defined(PTHREAD_H)
		SleepConditionVariableCS(&m_Cond, (thread_mutex_t *)&m_Mutex.m_Mutex, timeout_msec);
		#else
		pthread_cond_timedwait(&m_Cond, (thread_mutex_t *)&m_Mutex.m_Mutex, 0);
		#endif
	}

	void Notify()
	{
		#if	defined(OS_WINDOWS) && !defined(PTHREAD_H)
		WakeConditionVariable(&m_Cond);
		#else
		pthread_cond_signal(&m_Cond);
		#endif
	}

	void NotifyAll()
	{
		#if	defined(OS_WINDOWS) && !defined(PTHREAD_H)
		WakeAllConditionVariable(&m_Cond);
		#else
		pthread_cond_broadcast(&m_Cond);
		#endif
	}


private:
	void operator =(const Cond& ref);// {}

};

NS_X1_END