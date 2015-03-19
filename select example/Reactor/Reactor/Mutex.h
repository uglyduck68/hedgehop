/**
 * @file	Mutex.h
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 * @date	2014-05-20
 * @version	0.1
 *
 * This is interface of mutex.
 */

/**
 * Mutex class
 */
#pragma once

#include "X1.h"
#include "MutexI.h"

NS_X1_START

class DECL_SPEC_DLL Mutex
{
protected:
	MutexI*    m_pMutex;

public:
	Mutex(void);
	~Mutex(void);

	ret_t Acquire();

	ret_t Release();

	/// Lock just call Acquire
	ret_t Lock();
	
	/// Unlock just call Release
	ret_t Unlock();
	

	const thread_mutex_t&	GetMutex();

	ret_t Destroy();

	friend class Cond;
};

NS_X1_END