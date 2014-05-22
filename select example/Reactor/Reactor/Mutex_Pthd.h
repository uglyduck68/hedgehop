/**
 * @file	Mutex_Pthd.h
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 * @date	2014-05-20
 * @version	0.1
 *
 * This is wrapper class of Mutex for Pthread.
 */

#pragma once

#include "mutexi.h"

NS_X1_START

class Mutex_Pthd :
	public MutexI
{
public:
	Mutex_Pthd(void);
	~Mutex_Pthd(void);

	ret_t Acquire();

	ret_t Release();

	/// Lock just call Acquire
	ret_t Lock();
	
	/// Unlock just call Release
	ret_t Unlock();

	thread_mutex_t&	GetMutex()
	{
		return m_Mutex;
	}

	ret_t Destroy();

protected:
	thread_mutex_t		m_Mutex;
};

NS_X1_END