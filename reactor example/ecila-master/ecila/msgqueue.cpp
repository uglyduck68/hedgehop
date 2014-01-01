#include "msgqueue.h"

#include "buffer.h"
#include "guard.h"







US_ECILA

MsgQueue::MsgQueue()
{
}








MsgQueue::~MsgQueue()
{
}







void MsgQueue::Push(Buffer *buffer)
{
	Guard<ThreadMutex> auto_release_lock(mutex_);

	ECILA_ASSERT(buffer);

	queue_.push(buffer);
}








Buffer* MsgQueue::Pop()
{
	Guard<ThreadMutex> auto_release_lock(mutex_);

	if(queue_.empty()) { return 0; }

	Buffer* buffer = queue_.front();
	queue_.pop();

	return buffer;
}

