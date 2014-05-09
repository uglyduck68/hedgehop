/**
 * @file	MsgQueue.h
 *
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 *
 * This is thread-safe message queueu. This class was tested by TestMessageQ project.
 */

#pragma once

//#include <pthread.h>
#include <queue>

#include "X1.h"
#include "Cond.h"

NS_X1_START

/**
 * @class	MsgQueue
 *
 * MsgQueue is template thread-safe message queue. 
 * But you can user MutexNull class for single thread.
 * FIXME:	use lock-free algorithm of MPMC.
 */
template<typename T, typename L>
class MsgQueue
{
private:
	typedef std::queue< T > QUEUE_T;

	QUEUE_T			m_Queue;

	/// this mutex is used to push & pop item.
	/// so this variables don't be used in Size function.
	L				m_Mutex;
	L				m_MutexSize;
																
	/// conditional variable. this will be replaced by class.
	Cond			m_Cond;		

public:
	MsgQueue(void);
	virtual ~MsgQueue(void);

	inline void	Push(T pData);
	inline T		Pop();
	int		Size()
	{
		// no race condition in case of test of 2 threads
//		m_MutexSize.Lock();
		int		n = m_Queue.size();
//		m_MutexSize.Unlock();

		return n;
	}
};

NS_X1_END

#include "MsgQueue_T.cpp"

