#pragma once

#include "ecila.h"
#include "eventtype.h"

#include "thread.h"
#include "threadmutex.h"
#include "threadcondition.h"






NS_ECILA_START

class IDemultiplexer;

class DECL_SPEC_DLL LFThreadPool
{
public:

	LFThreadPool()
	:	leader_thread_(0),
		followers_condition_(mutex_)
	{
	}
	
	~LFThreadPool()
	{
	}


	void Join(int32_t timeout_msec = 0);
	void PromotionNewLeader();

//	void DeactivateHandle(handle_t h, EVENT_T e);
//	void ReactivateHandle(handle_t h, EVENT_T e);


private:
	IDemultiplexer *reactor_;
	thread_id_t		leader_thread_;
	ThreadMutex		mutex_;
	ThreadCondition followers_condition_;

};

NS_ECILA_END