#pragma once


#include "node.h"
#include "buffer.h"
#include "pool.h"
#include "threadmutex.h"








NS_ECILA_START

class DECL_SPEC_DLL BufferPool
:	public Node
{
public:
	
			 BufferPool();
	virtual ~BufferPool();

	CLASSNAME("BufferPool");

	bool_t Initialize();
	bool_t Finalize();

	Buffer*	Acquire();
	bool_t	Release(Buffer *buffer);


private:

	ThreadMutex		mutex_;
	Pool<Buffer>	*pool_;
};

NS_ECILA_END
