#include "Mutex.h"

NS_X1_START

Mutex::Mutex(void)
{
#if	defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	m_Mutex	= CreateMutex( NULL, false, NULL );
#else
	if (pthread_mutex_init(&m_Mutex, NULL) != 0)
	{
		// error
	}
#endif
}


Mutex::~Mutex(void)
{
#if	defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	CloseHandle(m_Mutex);
#else
	int rc = pthread_mutex_destroy(&m_Mutex); 

	if (rc == EBUSY)
	{                        
		pthread_mutex_unlock(&m_Mutex);               
		pthread_mutex_destroy(&m_Mutex);  
	}
#endif
}

ret_t Mutex::Acquire()
{
#if	defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	WaitForSingleObject(m_Mutex, INFINITE);
	//EnterCriticalSection(&m_Mutex);
#else
	if (pthread_mutex_lock(&m_Mutex) == 0)
		return X1_OK;

	return X1_FAIL;
#endif
}


ret_t Mutex::Release()
{
#if	defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	ReleaseMutex(m_Mutex);
	//LeaveCriticalSection(&m_Mutex);
#else
	if (pthread_mutex_unlock(&m_Mutex) == 0)
		return X1_OK;

	return X1_FAIL;
#endif
}

ret_t Mutex::Lock()
{
	return Acquire();
}
	
ret_t Mutex::Unlock()
{
	return Release();
}

NS_X1_END