#include "Mutex.h"

#ifdef	_X1_USE_PTHREAD_
#include "Mutex_Pthd.h"
#else defined(_X1_WINDOWS_)
#include "Mutex_Win.h"
#endif


NS_X1_START

Mutex::Mutex(void)
{
#ifdef	_X1_USE_PTHREAD_
	m_pMutex	= new Mutex_Pthd;
#else defined(_X1_WINDOWS_)	// WIN32
	m_pMutex	= new Mutex_Win;
#endif
}


Mutex::~Mutex(void)
{
	delete m_pMutex;
}

ret_t Mutex::Acquire()
{
	if (m_pMutex)
		return m_pMutex->Acquire();

	return X1_FAIL;
}


ret_t Mutex::Release()
{
	if (m_pMutex)
		return m_pMutex->Release();

	return X1_FAIL;
}

ret_t Mutex::Lock()
{
	return Acquire();
}
	
ret_t Mutex::Unlock()
{
	return Release();
}

const thread_mutex_t&	Mutex::GetMutex()
{
	if (m_pMutex)
		return m_pMutex->GetMutex();

	/// following might be the cause of fatal error at runtime
	return NULL;
}

ret_t Mutex::Destroy()
{
	if (m_pMutex)
		return m_pMutex->Destroy();

	return X1_FAIL;
}

NS_X1_END