#include "Mutex_Pthd.h"

NS_X1_START

Mutex_Pthd::Mutex_Pthd(void)
{
	if (pthread_mutex_init(&m_Mutex, NULL) != 0)
	{
		// error
	}
}


Mutex_Pthd::~Mutex_Pthd(void)
{

}

ret_t Mutex_Pthd::Acquire()
{
	if (pthread_mutex_lock(&m_Mutex) == 0)
		return X1_OK;

	return X1_FAIL;
}

ret_t Mutex_Pthd::Release()
{
	if (pthread_mutex_unlock(&m_Mutex) == 0)
		return X1_OK;

	return X1_FAIL;
}


/// Lock just call Acquire
ret_t Mutex_Pthd::Lock()
{
	return Acquire();
}

	
/// Unlock just call Release
ret_t Mutex_Pthd::Unlock()
{
	return Release();
}

ret_t Mutex_Pthd::Destroy()
{
	int rc = pthread_mutex_destroy(&m_Mutex); 

	if (rc == 0)
		return X1_OK;

	if (rc == EBUSY)
	{                        
		pthread_mutex_unlock(&m_Mutex);               
		pthread_mutex_destroy(&m_Mutex);  
	}

	return X1_FAIL;
}

NS_X1_END