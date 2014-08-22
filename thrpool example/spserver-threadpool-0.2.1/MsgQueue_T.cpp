/**
 * @file	MsgQueue.cpp
 *
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 *
 * This is thread-safe message queueu. This class was tested by TestMessageQ project.
 */

#include "Guard.h"
#include "CondVar.h"

NS_X1_USE

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

	m_Queue.push(pData);

	// wakeup threads
	m_Cond.Signal();
}


template<typename T, typename L>
T		MsgQueue<T, L>::Pop()
{
	m_Mutex.Lock();

	while (m_Queue.empty())
	{
		m_Cond.Wait(m_Mutex);
	}

	T		pData	= m_Queue.front();
	m_Queue.pop();

	m_Mutex.UnLock();

	/// [error] T::dtor is call to free resources
	return pData;
}

template<typename T, typename L>
int		MsgQueue<T, L>::Size()
{
	// use scope lock class. But You use direct lock of mutex below.
	m_Mutex.Lock();
	int		n = m_Queue.size();
	m_Mutex.UnLock();

	return n;
}
