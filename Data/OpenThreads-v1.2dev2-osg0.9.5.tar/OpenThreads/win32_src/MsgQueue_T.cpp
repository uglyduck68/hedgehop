
#include <OpenThreads\Mutex>
#include <OpenThreads\MsgQueue_T.h>
#include <OpenThreads\Guard.h>



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
	Guard<L>	scopeLock(m_Mutex);

	m_Queue.push(pData);
}


template<typename T, typename L>
T		MsgQueue<T, L>::Pop()
{
	Guard<L>	scopeLock(m_Mutex);

	if (m_Queue.empty())
		return NULL;

	T		pData	= m_Queue.front();
	m_Queue.pop();

	return pData;
}
template<typename T, typename L>
int		ClearAll()
{
	m_Queue<T>.Clear();
}
/**
 * The explicit template instantiation of MsgQueue
 */
template class MsgQueue<void*, OpenThreads::Mutex>;
template class MsgQueue<void*, OpenThreads::NullMutex>;