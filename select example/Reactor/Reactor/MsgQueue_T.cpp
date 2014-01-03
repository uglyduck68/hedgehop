
#include "Guard.h"

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
void	MsgQueue<T, L>::Push(T* pData)
{
	Guard<L>	scopeLock(m_Mutex);

	m_Queue.push(pData);
}


template<typename T, typename L>
T*		MsgQueue<T, L>::Pop()
{
	Guard<L>	scopeLock(m_Mutex);

	if (m_Queue.empty())
		return NULL;

	T*		pData	= m_Queue.front();
	m_Queue.pop();

	return pData;
}

NS_X1_END