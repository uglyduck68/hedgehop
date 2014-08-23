/**
* @file		ThreadWithMsgQueue.h
* @auther	Younghwan Kim<uglyduck68@gmail.com>
* @version	0.1
* @date		20140821
* @brief	interface file for thread with message queue
*/
#pragma once

#include "X1.h"
#include "Thread.h"
#include "MsgQueue_T.h"

NS_X1_START

	/**
	* @class		ThreadWithMsgQueue
	* @brief		this class has message queue.
	*				If message queueu empty then thread wait for the message queue item 
	*				to get into the queue.
	*/
	class ThreadWithMsgQueue : public Thread
	{
	public:
		ThreadWithMsgQueue(void);
		virtual ~ThreadWithMsgQueue(void);

		/**
		* @function		Push
		* @Param		pItem that is pointer to memory block of packet that is allocated by user.
		*				User *MUST* free it later.
		*				nLen that if nLen > sizeof(void*) 
		*				then Push function copy it after malloc.
		* @return		0 if success
		*/
		int	Push(void* pItem, int nLen);

		/**
		* @function		Push that is just for convenient
		* @Param		pItem
		* @return		0 if success
		*/
		int Push(MsgQueueItem* pItem);

		/**
		* @function		Pop that thread can be blocked in this function 
		*				when no item in queue.
		*/
		int Pop(void** ppItem, int* pnLen);

	protected:
		MsgQueue<MsgQueueItem, Mutex>	m_MsgQueue;
	};

NS_X1_END