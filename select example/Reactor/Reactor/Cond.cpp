/**
 * @file	Cond.cpp
 *
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 *
 * This template implementation file is included to Cond.h.
 */
#include "Cond.h"
#include "Cond_Pthd.h"
#include "Cond_Win.h"

NS_X1_START


Cond::Cond()
{
#if	defined(_X1_WINDOWS_) && !defined(_X1_USE_PTHREAD_)
	m_pCondv		= new Cond_Win;
#elif defined(_X1_USE_PTHREAD_)
	m_pCondv		= new Cond_Pthd;
#endif
}

Cond::~Cond(void)
{
	delete m_pCondv;
}

ret_t Cond::Wait(Mutex& mutex)
{
	return m_pCondv->Wait(mutex);
}

ret_t Cond::Notify()
{
	return m_pCondv->Notify();
}

ret_t Cond::NotifyAll()
{
	return m_pCondv->NotifyAll();
}


NS_X1_END