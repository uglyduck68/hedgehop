#include "Mutex_Win.h"

NS_X1_START

// all sources is showed up in solution exploror of VisualStudio.
#if defined(_X1_WINDOWS_) && !defined(_X1_USE_PTHREAD_)

Mutex_Win::Mutex_Win(void)
{
//	m_Mutex	= CreateMutex( NULL, false, NULL );

	InitializeCriticalSection(&m_Mutex);
}


Mutex_Win::~Mutex_Win(void)
{
//	if (m_Mutex)
//		CloseHandle(m_Mutex);

	DeleteCriticalSection(&m_Mutex);
}

ret_t Mutex_Win::Acquire()
{
//	if (m_Mutex)
//		WaitForSingleObject(m_Mutex, INFINITE);

	EnterCriticalSection(&m_Mutex);

	return X1_OK;
}

ret_t Mutex_Win::Release()
{
//	if (m_Mutex == NULL || ReleaseMutex(m_Mutex) == 0)
//		return X1_FAIL;

	LeaveCriticalSection(&m_Mutex);

	return X1_OK;
}


/// Lock just call Acquire
ret_t Mutex_Win::Lock()
{
	return Acquire();
}

	
/// Unlock just call Release
ret_t Mutex_Win::Unlock()
{
	return Release();
}

ret_t Mutex_Win::Destroy()
{
	DeleteCriticalSection(&m_Mutex);

	return X1_OK;
}

#endif

NS_X1_END

