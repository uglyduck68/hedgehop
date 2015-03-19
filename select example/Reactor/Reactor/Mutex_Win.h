/**
 * @file	Mutex_Win.h
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 * @date	2014-05-20
 * @version	0.1
 *
 * This is wrapper class of Mutex for Windows.
 */

#pragma once

#include "mutexi.h"

NS_X1_START

// all sources is showed up in solution exploror of VisualStudio.
#if defined(_X1_WINDOWS_) && !defined(_X1_USE_PTHREAD_)

class Mutex_Win :
	public MutexI
{
public:
	Mutex_Win(void);
	~Mutex_Win(void);
	ret_t Acquire();

	ret_t Release();

	/// Lock just call Acquire
	ret_t Lock();
	
	/// Unlock just call Release
	ret_t Unlock();

	thread_mutex_t& GetMutex()
	{
		return m_Mutex;
	}
	virtual ret_t Destroy();

protected:
	// currently m_Mutex is CRITICAL_SECTION type.
	// But a short time ago m_Mutex was HANDLE type.
	thread_mutex_t	m_Mutex;
};
#endif

NS_X1_END