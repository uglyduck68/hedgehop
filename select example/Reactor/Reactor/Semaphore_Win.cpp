#include "Semaphore_Win.h"


Semaphore_Win::Semaphore_Win(void)
{
	m_bInit	= false;
}


Semaphore_Win::~Semaphore_Win(void)
{
}

ret_t	Semaphore_Win::Init(int InitValue, int MaxValue)
{
	m_Sem	= CreateSemaphore(NULL, InitValue, MaxValue, NULL);

	if (m_Sem == NULL)
		return X1_FAIL;
	



	m_bInit		= true;
	m_nSemValue	= InitValue;

	if ((m_Mutex = CreateMutex(NULL, FALSE, NULL)) == NULL)
	{
		Destroy();	///< destroy semaphore
		return X1_FAIL;
	}	

	return X1_OK;
}

ret_t	Semaphore_Win::GetValue(int* pValue)
{
	*pValue		=	m_nSemValue;

	return X1_OK;
}

ret_t	Semaphore_Win::Wait()
{
	if (WaitForSingleObject(m_Sem, INFINITE) == WAIT_FAILED)
		return X1_FAIL;

	// lock
	WaitForSingleObject(m_Mutex, INFINITE);

	m_nSemValue--;

	// ulock
	if (!ReleaseMutex(m_Mutex))
		return X1_FAIL;

	return X1_OK;
}

ret_t	Semaphore_Win::Post()
{
	if (ReleaseSemaphore(m_Sem, 1, NULL) == 0)
		return X1_FAIL;

	// lock
	WaitForSingleObject(m_Mutex, INFINITE);

	m_nSemValue++;

	// unlock
	if (!ReleaseMutex(m_Mutex))
		return X1_FAIL;

	return X1_OK;
}

ret_t	Semaphore_Win::Destroy()
{
	if (m_bInit == true)
		CloseHandle(m_Sem);

	return X1_OK;
}