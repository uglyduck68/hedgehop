/**
* @file		Guard.h
* @auther	Younghwan Kim<uglyduck68@gmail.com>
* @version	0.1
* @date		20140816
* @brief	This file has Guard class that support scoped lock.
*/

#pragma once

#include "X1.h"

NS_X1_START

/**
 * @class	Guard
 * @brief	class for scoped locking
 */

template <typename LOCK>
class DECL_SPEC_DLL Guard
{
private:
	bool_t	m_bOwner;
	LOCK*	m_pLock;


public:
	
	Guard(LOCK &lock)
	: m_bOwner(FALSE), m_pLock(&lock)
	{
		Lock(); 
	}


	~Guard()
	{
		UnLock();
	}


	void Lock()
	{
		m_pLock->Lock();
		m_bOwner = TRUE;
	}


	void UnLock()
	{
		if(m_bOwner)
		{
			m_bOwner = FALSE;
			m_pLock->UnLock();
		}
	}
};

NS_X1_END