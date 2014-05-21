/**
 * @file	MsgQueue.cpp
 *
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 *
 * This is thread-safe message queueu. This class was tested by TestMessageQ project.
 */

#include "Guard.h"
#include "Cond.h"

NS_X1_START

template<typename T, typename L>
MsgQueue<T, L>::MsgQueue(void)
{

}


template<typename T, typename L>
MsgQueue<T, L>::~MsgQueue(void)
{

}

template<typename T, typename L>
void	MsgQueue<T, L>::Push(T pData)
{
	// use scope lock class. But You use direct lock of mutex below.
	Guard<L>	scopeLock(m_Mutex);

//	m_Mutex.Lock();

	m_Queue.push(pData);

	// wakeup threads
	m_Cond.Notify();

//	m_Mutex.Unlock();
}


template<typename T, typename L>
T		MsgQueue<T, L>::Pop()
{
	// use scope lock class. But You use direct lock of mutex below.
	Guard<L>	scopeLock(m_Mutex);

//	m_Mutex.Lock();

	while (m_Queue.empty())
	{
		m_Cond.Wait(m_Mutex);
	}

	T		pData	= m_Queue.front();
	m_Queue.pop();

//	m_Mutex.Unlock();

	return pData;
}

NS_X1_END