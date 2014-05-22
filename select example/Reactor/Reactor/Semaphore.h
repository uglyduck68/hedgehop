/**
 * @file	Semaphore.h
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 * @date	2014-05-20
 * @version	0.1
 * This is interface of Semaphore class.
 */
#pragma once

#include "X1.h"
#include "SemaphoreI.h"

NS_X1_START

class DECL_SPEC_DLL Semaphore
{
public:
	Semaphore(void);
	~Semaphore(void);

	ret_t	Init(int InitValue, int MaxValue);
	ret_t	GetValue(int* pValue);
	ret_t	Wait();
	ret_t	Post();
	ret_t	Destroy();

protected:
	SemaphoreI*		m_pSem;
};

NS_X1_END

