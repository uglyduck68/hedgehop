#include "Cond_Pthd.h"

NS_X1_START

Cond_Pthd::Cond_Pthd(void)
{
	if(pthread_cond_init(&m_Condv, 0) != 0)
	{
		X1_TRACE();
	}
}


Cond_Pthd::~Cond_Pthd(void)
{
	if(pthread_cond_destroy(&m_Condv) != 0)
	{
		X1_TRACE();
	}
}

ret_t Cond_Pthd::Wait(Mutex& mutex)
{
	if (pthread_cond_wait(&m_Condv, (thread_mutex_t *)&mutex.GetMutex()) == 0)
		return X1_OK;

	return X1_FAIL;
}

ret_t Cond_Pthd::Notify()
{
	if (pthread_cond_signal(&m_Condv) == 0)
		return X1_OK;

	return X1_FAIL;
}

ret_t Cond_Pthd::NotifyAll()
{
	if (pthread_cond_broadcast(&m_Condv) == 0)
		return X1_OK;

	return X1_FAIL;
}

//
//// following functions just for ease interface
////
//ret_t Cond_Pthd::Lock()
//{
//	return X1_OK;
//}
//	
//ret_t Cond_Pthd::Unlock()
//{
//	return X1_OK;
//}

NS_X1_END