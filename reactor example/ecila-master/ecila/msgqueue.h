#pragma once


#include <queue>

#include "node.h"
#include "threadmutex.h"






NS_ECILA_START

class Buffer;

class DECL_SPEC_DLL MsgQueue
:	public Node
{
public:

			 MsgQueue();
	virtual ~MsgQueue();

	CLASSNAME("MsgQueue");

	void	Push(Buffer *buffer);
	Buffer*	Pop();


private:
	typedef std::queue< Buffer* > QUEUE_T;

	QUEUE_T		queue_;
	ThreadMutex	mutex_;
};

NS_ECILA_END

