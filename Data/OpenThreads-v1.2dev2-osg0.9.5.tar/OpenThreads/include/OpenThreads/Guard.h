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
	: m_bOwner(false), m_pLock(&lock)
	{
		Lock(); 
	}


	~Guard()
	{
		Unlock();
	}


	void Lock()
	{
		m_pLock->lock();
		m_bOwner = true;
	}


	void Unlock()
	{
		if(m_bOwner)
		{
			m_bOwner = false;
			m_pLock->unlock();
		}
	}
};