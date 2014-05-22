#include "Semaphore_Pthd.h"


Semaphore_Pthd::Semaphore_Pthd(void)
{
	m_bInit	= false;
}


Semaphore_Pthd::~Semaphore_Pthd(void)
{
	Destroy();
}

ret_t	Semaphore_Pthd::Init(int InitValue, int MaxValue)
{
	if (m_bInit == false && sem_init(&m_Sem, 0, MaxValue) == 0)
	{
		m_bInit	= true;

		return X1_OK;
	}

	return X1_FAIL;
}

ret_t	Semaphore_Pthd::GetValue(int* pValue)
{
	if (m_bInit == true && sem_getvalue(&m_Sem, pValue) == 0)
		return X1_OK;

	return X1_FAIL;
}

ret_t	Semaphore_Pthd::Wait()
{
	if (sem_wait(&m_Sem) == 0)
		return X1_OK;

	return X1_FAIL;
}

ret_t	Semaphore_Pthd::Post()
{
	if (m_bInit == true && sem_post(&m_Sem) == 0)
		return X1_OK;

	return X1_FAIL;
}

ret_t	Semaphore_Pthd::Destroy()
{
	if (m_bInit == true && sem_destroy(&m_Sem) == 0)
	{
		m_bInit	= false;

		return X1_OK;
	}

	return X1_FAIL;
}