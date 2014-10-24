/**
* @file		MsgQueue_T.h
* @author	sean<uglyduck68@gmail.com>
* @version	0.1
* @brief	This file is interface of fixed-length type and thread-safe
* message queue that use std::queueu.
*/

#pragma once

#include <queue>

#include <OpenThreads/Exports.h>
#include <OpenThreads/Guard.h>
#include <OpenThreads/Condition.h>
#include <OpenThreads/Mutex.h>

using namespace	OpenThreads;

namespace OpenThreads {
/**
 * @class		MsgQueue is template thread-safe message queue. 
 * But you can user MutexNull class for single thread. and
 * This message queue is for fixed length message.
 * @param		@T is data type
 * @param		@L is lock type that is one of Mutex or MutexNull.
 * @note		
 * FIXME: use lock-free algorithm of MPMC.
 */
template<typename T, typename L>
class MsgQueue
{
protected:
	typedef std::queue< T > QUEUE_T;

	QUEUE_T		m_Queue;
	L			m_Mutex;
	Condition	m_Cond;

public:
	MsgQueue(void)
	{
	}

	virtual ~MsgQueue(void)
	{
	}

	void		Push(T& pData)
	{
		Guard<L>	scopeLock(m_Mutex);

		m_Queue.push(pData);	// *NOTE* Here push_back cause compile error

		scopeLock.Unlock();

		// wakeup threads after unlocking the mutex
		m_Cond.signal();
	}
	bool		Front(T& pData)
	{
		Guard<L>	scopeLock(m_Mutex);

		if (m_Queue.empty())
			return false;

		pData	= m_Queue.front();
		m_Queue.pop();

		return true;
	}
	bool		WaitFront(T& pData)
	{
		Guard<L>	scopeLock(m_Mutex);

		while( m_Queue.empty() )
		{
			m_Cond.wait(&m_Mutex);
		}

		pData	= m_Queue.front();
		m_Queue.pop();

		return true;
	}
	int		Size()
	{
		Guard<L>	scopeLock(m_Mutex);
		return m_Queue.size();
	}

	bool	Empty()
	{
		Guard<L>	scopeLock(m_Mutex);
		return m_Queue.empty();
	}
};

/**
* @class	MsgQueueItem
* @brief	emulate general data type. if MsgQueueItem is used 
* as MsgQueue<MsgQueueItem, L> and MsqQueue::Pop operation is to
* call the MsgQueueItem::dtor to free resource. Sometimes this
* cause the memory leak.
*/
struct MsgQueueItem
{
	void*		pUsrData;
	int			nLen;

	MsgQueueItem()
	{
		nLen		= -1;
		pUsrData	= NULL;
	}

	MsgQueueItem(void* pData, int Len)
	{
		Set(pData, Len);
	}

	/**
	* @function		Free
	* @brief		free the memory
	*/
	void	Fin()
	{
		if (pUsrData && nLen > 0)
		{
			free(pUsrData);
		}

		pUsrData	= NULL;
	}

	~MsgQueueItem()
	{
		// it MsgQueueItem is local or stack variable, then
		// this dtor is called to free resources. 
		// this situation is sometimes unintened.
		// so comment out
	//	Fin();
	}

	int Set(MsgQueueItem* pData)
	{
		return Set(pData->pUsrData, pData->nLen);
	}

	int	Set(void* pData, int Len)
	{
		nLen		= Len;

		if (Len <= 0/*sizeof(void*)*/)
		{
			pUsrData		= NULL;

			return -1;
		}
		else
		{
			// malloc do memory allocation if Len is 0
			pUsrData			= malloc(Len);
			
			if (pUsrData)
			{
				// FIXME: memcpy have a big overload
				memcpy(pUsrData, pData, nLen);

				return 0;	// success
			}
			else
			{

				return -1;	// fail
			}
		}

		return 0;		// success
	}

	void	Clear()
	{
		Fin();
	}
};

/**
 * @class		MsgQueueV is template thread-safe message queue. 
 * But you can user MutexNull class for single thread. and
 * This message queue is for variable length message.
 * @param		@L is lock type that is one of Mutex or MutexNull.
 * @note		
 * FIXME: use lock-free algorithm of MPMC.
 */
template<typename L>
class MsgQueueV : public MsgQueue<MsgQueueItem, L>
{
private:

public:
	MsgQueueV(void)
	{
	}

	virtual ~MsgQueueV(void)
	{
	}

	/**
	* @function		Push
	* @brief		It create MsgQueueItem and malloc internally
	* to copy from @pData and @nLen.
	*/
	void		Push(void* pData, int nLen)
	{
		Guard<L>	scopeLock(m_Mutex);

		if( pData == NULL || nLen <= 0 )
			return;

		MsgQueueItem	qi(pData, nLen);

		m_Queue.push( qi );

		scopeLock.Unlock();

		// wakeup threads after unlocking the mutex
		m_Cond.signal();

		return;
	}

	/**
	* @function		Front that is same name as a meaning of std::queue
	* @param		@pnLen is the length of first user data in queueu.
	* @return		return pointer to  @pData above
	*				NULL if queue is empty
	*/
	void*	Front(int* pnLen)
	{
		Guard<L>	scopeLock(m_Mutex);

		MsgQueueItem	qi	= m_Queue.front();

		if( qi != NULL && qi.nLen > 0 )
		{
			*pnLen		= qi.nLen;

			return qi.pUsrData;
		}

		return NULL;
	}

	void*	WaitFront(int* pnLen)
	{
		Guard<L>	scopeLock(m_Mutex);

		while( m_Queue.empty() )
		{
			m_Cond.wait(&m_Mutex);
		}

		MsgQueueItem	qi	= m_Queue.front();

		if( qi != NULL && qi.nLen > 0 )
		{
			*pnLen		= qi.nLen;

			return qi.pUsrData;
		}

		return NULL;
	}

	/**
	* @function		Front that is same name as a meaning of std::queue.
	*				This function copy the first item to @pData.
	* @param		@pnLen is the length of first user data in queueu.
	* @return		return pointer to  @pData above
	*				NULL if queue is empty
	*/
	void*	Front(void* pData, int* pnLen)
	{
		Guard<L>	scopeLock(m_Mutex);

		MsgQueueItem	qi	= m_Queue.front();

		if( qi != NULL && qi.nLen > 0 )
		{
			*pnLen		= qi.nLen;

			memcpy( pData, qi.pUsrData, qi.nLen );

			// qi is not used any more, free allocated memory
			qi.Clear();

			m_Queue.pop();

			return pData;
		}

		return NULL;
	}

	void*	WaitFront(void* pData, int* pnLen)
	{
		Guard<L>	scopeLock(m_Mutex);

		while( m_Queue.empty() )
		{
			m_Cond.wait(&m_Mutex);
		}

		MsgQueueItem	qi	= m_Queue.front();

		if( qi.pUsrData != NULL && qi.nLen > 0 )
		{
			*pnLen		= qi.nLen;

			memcpy( pData, qi.pUsrData, qi.nLen );

			// qi is not used any more, free allocated memory
			qi.Clear( );

			m_Queue.pop();

			return pData;
		}

		return NULL;
	}

	/**
	* @function		Pop that is same name as a meaning of std::queue.
	*				This function remove the first MsgQueueItem and free
	*				memory that is allocated internally.
	*/
	void			Pop()
	{
		Guard<L>	scopeLock(m_Mutex);

		MsgQueueItem	qi	= m_Queue.front();

		// free memory
		qi.Clear();

		m_Queue.pop();

		return;
	}
};
}


