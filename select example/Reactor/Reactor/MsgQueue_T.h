#pragma once

#include "X1.h"

#include <queue>

NS_X1_START

template<typename T, typename L>
class DECL_SPEC_DLL MsgQueue
{
private:
	typedef std::queue< T* > QUEUE_T;

	QUEUE_T		m_Queue;
	L			m_Mutex;

public:
	MsgQueue(void);
	virtual ~MsgQueue(void);

	// FIXME: this class must be modified to support singleton
	static MsgQueue*	Instance()		{}

	inline void	Push(T* pData);
	inline T*		Pop();
	int		Size()
	{
		return m_Queue.size();
	}
};

NS_X1_END

#include "MsgQueue_T.cpp"

