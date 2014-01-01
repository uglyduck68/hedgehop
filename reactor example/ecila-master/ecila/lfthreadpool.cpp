#include "lfthreadpool.h"

#include "guard.h"
#include "idemultiplexer.h"








US_ECILA

void LFThreadPool::Join(int32_t timeout_msec)
{
	Guard<ThreadMutex> guard(mutex_);

	for(;;)
	{
		while(leader_thread_ != 0)
		{
//			followers_condition_.Wait(INFINITE);
		}		

		leader_thread_ = Thread::Self();

		guard.Release();

		

		PromotionNewLeader();
		guard.Acquire();
	}
}








void LFThreadPool::PromotionNewLeader()
{
	Guard<ThreadMutex> guard(mutex_);

	if(leader_thread_ != Thread::Self()) { return; }

	leader_thread_ = 0;
	followers_condition_.NotifyAll();
}

