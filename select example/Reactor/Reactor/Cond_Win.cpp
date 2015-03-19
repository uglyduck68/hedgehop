#include "Cond_Win.h"

NS_X1_START

// all sources is showed up in solution exploror of VisualStudio.
#if defined(_X1_WINDOWS_) && !defined(_X1_USE_PTHREAD_)

Cond_Win::Cond_Win(void)
{
	InitializeConditionVariable(&m_Condv);
}


Cond_Win::~Cond_Win(void)
{
}

ret_t Cond_Win::Wait(Mutex& mutex)
{
	CRITICAL_SECTION	CriticalSection;

	if (SleepConditionVariableCS(&m_Condv, &mutex.GetMutex(), INFINITE) != 0)
		return X1_OK;

	return X1_FAIL;
}

ret_t Cond_Win::Notify()
{
	WakeConditionVariable(&m_Condv);

	return X1_OK;
}

ret_t Cond_Win::NotifyAll()
{
	WakeAllConditionVariable(&m_Condv);

	return X1_OK;
}

////
//// following functions just for ease interface
////
//ret_t Cond_Win::Lock()
//{
//	return X1_OK;
//}
//	
//ret_t Cond_Win::Unlock()
//{
//	return X1_OK;
//}

#endif

NS_X1_END
