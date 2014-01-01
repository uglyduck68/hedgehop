#pragma once


#include "ecila.h"
#include "threadmutex.h"







NS_ECILA_START

class DECL_SPEC_DLL ThreadCondition
{
private:

	thread_condition_t	cond_;
	const ThreadMutex	&mutex_;

public:

	ThreadCondition(const ThreadMutex &mutex)
	: mutex_(mutex)
	{
		#ifdef OS_WINDOWS
		memset(&cond_, 0, sizeof(cond_));
		InitializeConditionVariable(&cond_);
		#else
		if(pthread_cond_init(&cond_, 0) != 0)
		{
			ECILA_TRACE();
		}
		#endif
	}

	~ThreadCondition()
	{
		#ifdef OS_WINDOWS
		#else
		if(pthread_cond_destroy(&cond_) != 0)
		{
			ECILA_TRACE();
		}
		#endif
	}

	void Wait(int32_t timeout_msec)
	{
		#ifdef OS_WINDOWS
		SleepConditionVariableCS(&cond_, (thread_mutex_t *)&mutex_.mutex_, timeout_msec);
		#else
		pthread_cond_timedwait(&cond_, (thread_mutex_t *)&mutex_.mutex_, 0);
		#endif
	}

	void Notify()
	{
		#ifdef OS_WINDOWS
		WakeConditionVariable(&cond_);
		#else
		pthread_cond_signal(&cond_);
		#endif
	}

	void NotifyAll()
	{
		#ifdef OS_WINDOWS
		WakeAllConditionVariable(&cond_);
		#else
		pthread_cond_broadcast(&cond_);
		#endif
	}


private:
	void operator =(const ThreadCondition& ref);// {}

};

NS_ECILA_END

