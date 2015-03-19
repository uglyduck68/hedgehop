/**
 * @file	Cond_Win.h
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 * @date	2014-05-20
 * @version	0.1
 *
 * This is wrapper class of condition variabls for Windows.
 */
#pragma once

#include "condi.h"

NS_X1_START

// all sources is showed up in solution exploror of VisualStudio.
#if defined(_X1_WINDOWS_) && !defined(_X1_USE_PTHREAD_)

class Cond_Win :
	public CondI
{
public:
	Cond_Win(void);
	~Cond_Win(void);

	ret_t Wait(Mutex& mutex);

	ret_t Notify();

	ret_t NotifyAll();

	//
	// following functions just for ease interface
	//
	//ret_t Lock();
	//
	//ret_t Unlock();

protected:
	CONDITION_VARIABLE	m_Condv;
};

#endif

NS_X1_END
