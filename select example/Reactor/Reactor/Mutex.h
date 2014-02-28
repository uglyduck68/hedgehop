#pragma once

#include "X1.h"
#include	<pthread.h>

NS_X1_START

class DECL_SPEC_DLL Mutex
{
protected:
	thread_mutex_t    m_Mutex;

public:
	Mutex(void);
	~Mutex(void);

	void Acquire()
	{
#if	defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
		WaitForSingleObject(m_Mutex, INFINITE);
		//EnterCriticalSection(&m_Mutex);
#else
		pthread_mutex_lock(&m_Mutex);
#endif
	}


	void Release()
	{
#if	defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
		ReleaseMutex(m_Mutex);
		//LeaveCriticalSection(&m_Mutex);
#else
		pthread_mutex_unlock(&m_Mutex);
#endif
	}

	void Lock()
	{
		Acquire();
	}
	
	void Unlock()
	{
		Release();
	}
	
	friend class Cond;
};

NS_X1_END