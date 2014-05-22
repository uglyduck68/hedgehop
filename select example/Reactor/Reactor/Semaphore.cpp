/**
 * @file	Semaphore.h
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 * @date	2014-05-20
 * @version	0.1
 * This is implementation of Semaphore wrapper class.
 */

#include "Semaphore.h"

#ifdef	_X1_USE_PTHREAD_
#include "Semaphore_Pthd.h"
#else defined(_X1_WINDOWS_)
#include "Semaphore_Win.h"
#endif

NS_X1_USE

Semaphore::Semaphore(void)
{
#ifdef	_X1_USE_PTHREAD_
	m_pSem	= new Semaphore_Pthd;
#else defined(_X1_WINDOWS_)	// WIN32
	m_pSem	= new Semaphore_Win;
#endif
}


Semaphore::~Semaphore(void)
{
	delete m_pSem;
}

ret_t	Semaphore::Init(int InitValue, int MaxValue)
{
	return m_pSem->Init(InitValue, MaxValue);
}

ret_t	Semaphore::GetValue(int* pValue)
{
	return m_pSem->GetValue(pValue);
}

ret_t	Semaphore::Wait()
{
	return m_pSem->Wait();
}

ret_t	Semaphore::Post()
{
	return m_pSem->Post();
}

ret_t	Semaphore::Destroy()
{
	return m_pSem->Destroy();
}