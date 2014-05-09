/**

*/
#pragma once

//#include <pthread.h>
#include <queue>

#include "X1.h"
#include "Cond.h"

NS_X1_START

/**
 * MsgQueue is template thread-safe message queue. But you can user MutexNull object for single thread.
 * FIXME:	use lock-free algorithm of MPMC.
 *			change thread_mutex_t to L.
 */
template<typename T, typename L>
class /*DECL_SPEC_DLL*/ MsgQueue
{
private:
	typedef std::queue< T > QUEUE_T;

	QUEUE_T			m_Queue;

	/// mutex lock. this will be replaced by class.
	/// this mutex is used to push & pop item.
	/// so this variables don't be used in Size function.
	L				m_Mutex;	
																
	/// conditional variable. this will be replaced by class.
	Cond<L>			m_Cond(typename L xxMutex);		

public:
	MsgQueue(void);
	virtual ~MsgQueue(void);


//	static MsgQueue*	Instance()		{}

	inline void	Push(T pData);
	inline T		Pop();
	int		Size()
	{
//		m_Mutex.Lock();
		int		n = m_Queue.size();
//		m_Mutex.Unlock();
	}
};

NS_X1_END

#include "MsgQueue_T.cpp"

