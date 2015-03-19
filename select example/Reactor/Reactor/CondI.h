/**
 * @file	CondI.h
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 * @date	2014-05-20
 * @version	0.1
 *
 * This is virtual abstract class of condition variable.
 */

#pragma once

#include "X1.h"

#include "Mutex.h"

NS_X1_START

class CondI
{
public:
	CondI(void);
	~CondI(void);

	virtual ret_t Wait(Mutex& mutex)	= 0;

	virtual ret_t Notify() = 0;

	virtual ret_t NotifyAll() = 0;

	//
	// following functions just for ease interface
	//
//	virtual ret_t Lock() = 0;
	
//	virtual ret_t Unlock() = 0;
};

NS_X1_END