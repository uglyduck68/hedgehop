/**
 * @file	Cond.h
 *
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 */

#pragma once

#include "X1.h"
#include "Mutex.h"

NS_X1_START

/**
 * @class	Cond
 * @brief	class for conditional variables
 *
 * This class is wrapping for conditional variables, which allows
 * threads to block until shared data changes state.
 *
 */
class DECL_SPEC_DLL Cond
{
private:
	/// condition variable.
	thread_cond_t		m_Condv;

public:

	Cond();

	~Cond(void);

	ret_t Wait(Mutex& mutex);

	ret_t Notify();

	ret_t NotifyAll();

	//
	// following functions just for ease interface
	//
	ret_t Lock();
	
	ret_t Unlock();
private:
	void operator =(const Cond& ref);// {}

};

NS_X1_END