/**
 * @file	Cond_Pthd.h
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 * @date	2014-05-20
 * @version	0.1
 *
 * This is wrapper class of Mutex for Pthread.
 */

#pragma once
#include "condi.h"

NS_X1_START

class Cond_Pthd :
	public CondI
{
public:
	Cond_Pthd(void);
	~Cond_Pthd(void);

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
	pthread_cond_t	m_Condv;
};

NS_X1_END
