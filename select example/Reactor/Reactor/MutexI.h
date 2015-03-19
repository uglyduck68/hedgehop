/**
 * @file	MutexI.h
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 * @date	2014-05-20
 * @version	0.1
 *
 * This is virtual abstract class of mutex.
 */

#pragma once

#include "X1.h"

NS_X1_START

class DECL_SPEC_DLL MutexI
{
public:
	MutexI(void);
	~MutexI(void);

	virtual ret_t Acquire() = 0;;

	virtual ret_t Release() = 0;

	/// Lock just call Acquire
	virtual ret_t Lock() = 0;
	
	/// Unlock just call Release
	virtual ret_t Unlock() = 0;

	virtual thread_mutex_t& GetMutex() = 0;

	virtual ret_t Destroy() = 0;
};

NS_X1_END