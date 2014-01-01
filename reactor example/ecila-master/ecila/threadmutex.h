#pragma once


#include "ecila.h"







NS_ECILA_START

class DECL_SPEC_DLL ThreadMutex
{

public:

	ThreadMutex()
	{
		#ifdef OS_WINDOWS
		InitializeCriticalSection(&mutex_);
		#else
		pthread_mutex_init(&mutex_, 0);
		#endif
	}






	~ThreadMutex()
	{
		#ifdef OS_WINDOWS
		DeleteCriticalSection(&mutex_);
		#else
		pthread_mutex_destroy(&mutex_);
		#endif
	}






	void Acquire()
	{
		#ifdef OS_WINDOWS
		EnterCriticalSection(&mutex_);
		#else
		pthread_mutex_lock(&mutex_);
		#endif
	}






	void Release()
	{
		#ifdef OS_WINDOWS
		LeaveCriticalSection(&mutex_);
		#else
		pthread_mutex_unlock(&mutex_);
		#endif
	}




private:

	thread_mutex_t	mutex_;

	ThreadMutex(const ThreadMutex &m);
/*
	{
		mutex_ = m.mutex_;
	}
*/

	void operator =(const ThreadMutex &m);
/*
	{
		mutex_ = m.mutex_;
	}
*/

	friend class ThreadCondition;

};

NS_ECILA_END

