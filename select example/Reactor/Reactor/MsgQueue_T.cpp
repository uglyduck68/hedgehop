
#include "Guard.h"
#include "Cond.h"

NS_X1_START

template<typename T, typename L>
MsgQueue<T, L>::MsgQueue(void)
{
	// initialize the lock resource as below
	// so I should make lock resource as class.
	// m_Mutex
//#ifdef	PTHREAD_H
//	pthread_mutex_init(&m_Mutex, NULL);
//	pthread_cond_init(&m_Cond, NULL);
//#endif
	m_Cond.Set(m_Mutex);
}


template<typename T, typename L>
MsgQueue<T, L>::~MsgQueue(void)
{
	// release the lock resouece as below
	// so I should make lock resource as class
//#ifdef	PTHREAD_H
//	pthread_mutex_destroy(&m_Mutex);
//	pthread_cond_destroy(&m_Cond);
//#endif
}

template<typename T, typename L>
void	MsgQueue<T, L>::Push(T pData)
{
	Guard<L>	scopeLock(m_Mutex);

	m_Queue.push(pData);

	// wakeup threads
	m_Cond.Notify();
}


template<typename T, typename L>
T		MsgQueue<T, L>::Pop()
{
	Guard<L>	scopeLock(m_Mutex);

	while (m_Queue.empty())
	{
		m_Cond.Wait(0);
	}

	T		pData	= m_Queue.front();
	m_Queue.pop();

	return pData;
}

NS_X1_END