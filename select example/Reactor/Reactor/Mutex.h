/**
 * Mutex class
 */
#pragma once

#include "X1.h"


NS_X1_START

class DECL_SPEC_DLL Mutex
{
protected:
	thread_mutex_t    m_Mutex;

public:
	Mutex(void);
	~Mutex(void);

	ret_t Acquire();

	ret_t Release();

	/// Lock just call Acquire
	ret_t Lock();
	
	/// Unlock just call Release
	ret_t Unlock();
	

	friend class Cond;
};

NS_X1_END