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
	int rc = pthread_mutex_destroy(m_Mutex); 

	if (rc == EBUSY)
	{                        
		pthread_mutex_unlock(m_Mutex);               
		pthread_mutex_destroy(m_Mutex);  
	}
#endif
}

NS_X1_END