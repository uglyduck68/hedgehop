/**
 * @file	MsgQueue.h
 *
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 *
 * This is thread-safe message queueu. This class was tested by TestMessageQ project.
 */

#pragma once

#include "X1.h"
#include "CondVar.h"
#include <queue>


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
																
	/// conditional variable. this will be replaced by class.
	CondVar			m_Cond;		

public:
	MsgQueue(void);
	virtual ~MsgQueue(void);

	inline void	Push(T pData);
	inline T		Pop();
	int		Size();
};

/**
* @class	MsgQueueItem
* @brief	emulate general data type
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

	MsgQueueItem(const void* pData, int Len)
	{
		Set(pData, Len);
	}

	void	Fin()
	{
		if (pUsrData)
		{
			free(pUsrData);

			pUsrData	= NULL;
		}
	}

	~MsgQueueItem()
	{
		Fin();
	}

	int Set(MsgQueueItem* pData)
	{
		return Set(pData->pUsrData, pData->nLen);
	}

	int	Set(const void* pData, int Len)
	{
		nLen		= Len;

		if (Len <= 0)
			pUsrData		= NULL;
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
NS_X1_END

#include "MsgQueue_T.cpp"

