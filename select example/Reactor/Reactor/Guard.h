/**
 * @file	Guard.h
 *
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 */

#pragma once

#include "X1.h"

NS_X1_START

/**
 * @class	Guard
 * @brief	class for scoped locking
 */

template <typename LOCK>
class /*DECL_SPEC_DLL*/ Guard
{
private:
	bool_t	m_bOwner;
	LOCK*	m_pLock;


public:
	
	Guard(LOCK &lock)
	: m_bOwner(FALSE), m_pLock(&lock)
	{
		Acquire(); 
	}


	~Guard()
	{
		Release();
	}


	void Acquire()
	{
		m_pLock->Acquire();
		m_bOwner = TRUE;
	}


	void Release()
	{
		if(m_bOwner)
		{
			m_bOwner = FALSE;
			m_pLock->Release();
		}
	}
};

NS_X1_END