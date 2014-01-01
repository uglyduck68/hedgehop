#include "bufferpool.h"
#include "guard.h"








US_ECILA

BufferPool::BufferPool()
{
	pool_	= 0;
}








BufferPool::~BufferPool()
{
	Finalize();
}








bool_t BufferPool::Initialize()
{
	bool_t ret = FALSE;

	try
	{
		pool_ = new Pool<Buffer>();
		ECILA_ASSERT(pool_);

		ret = pool_->Initialize();
		if(!ret) { ECILA_TRACE(); return FALSE; }

	}
	catch(...)
	{
		ECILA_TRACE(); return FALSE;
	}

	return TRUE;
}








bool_t BufferPool::Finalize()
{
	ECILA_SAFE_DELETE(pool_);

	return TRUE;
}








Buffer* BufferPool::Acquire()
{
	Guard<ThreadMutex> auto_release_lock(mutex_);

	ECILA_ASSERT(pool_);

	Buffer *sess = pool_->Acquire(__FILE__, __LINE__);
	if(!sess) { ECILA_TRACE(); return 0; }

	return sess;
}








bool_t BufferPool::Release(Buffer *buffer)
{
	Guard<ThreadMutex> auto_release_lock(mutex_);

	ECILA_ASSERT(pool_);

	bool_t ret = FALSE;

	buffer->Reset();

	ret = pool_->Release(buffer);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}

