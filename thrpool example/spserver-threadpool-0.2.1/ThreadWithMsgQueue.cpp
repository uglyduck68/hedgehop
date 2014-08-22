#include "ThreadWithMsgQueue.h"

NS_X1_USE

ThreadWithMsgQueue::ThreadWithMsgQueue(void)
{
}


ThreadWithMsgQueue::~ThreadWithMsgQueue(void)
{
}

/**
* @function		Push
* @Param		pItem
*				nLen that if nLen > sizeof(void*) then Push function copy it
* @return		0 if success
*/
int	ThreadWithMsgQueue::Push(void* pItem, int nLen)
{
	MsgQueueItem	QItem(pItem, nLen);

	m_MsgQueue.Push(QItem);

	if( QItem.nLen > sizeof(void*))
	{
		// reset pointer because tp prevent MsgQueueItem.dtor to free pUsrData
		QItem.pUsrData	= NULL;
		QItem.nLen		= 0;
	}

	return 0;
}

/**
* @function		Pop that thread can be blocked in this function 
*				when no item in queue.
*/
int ThreadWithMsgQueue::Pop(void** ppItem, int* pnLen)
{
	int				nRet	= 0;
	MsgQueueItem	pQItem;

	pQItem	= m_MsgQueue.Pop();


	*ppItem		= pQItem.pUsrData;
	*pnLen		= pQItem.nLen;

	return nRet;
}