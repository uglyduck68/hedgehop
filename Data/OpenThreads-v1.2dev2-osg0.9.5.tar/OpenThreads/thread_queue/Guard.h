#pragma once

#include <OpenThreads\Exports>

/**
 * @class	Guard
 * @brief	class for scoped locking
 */

template <typename LOCK>
class OPENTHREAD_EXPORT_DIRECTIVE Guard
{
private:
	bool	m_bOwner;
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