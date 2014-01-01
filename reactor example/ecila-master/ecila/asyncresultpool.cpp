#include "asyncresultpool.h"
#include "guard.h"








US_ECILA

AsyncResultPool::AsyncResultPool()
{
	pool_	= 0;
}








AsyncResultPool::~AsyncResultPool()
{
	Finalize();
}








bool_t AsyncResultPool::Initialize()
{
	bool_t ret = FALSE;

	try
	{
		pool_ = new Pool<ActPoolElement>();
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








bool_t AsyncResultPool::Finalize()
{
	ECILA_SAFE_DELETE(pool_);

	return TRUE;
}








EventResult* AsyncResultPool::Acquire()
{
	Guard<ThreadMutex> auto_release_lock(mutex_);

	ActPoolElement *elem = pool_->Acquire(__FILE__, __LINE__);
	if(!elem) { ECILA_TRACE(); return FALSE; }

	//managing map
	acquire_map_[&elem->evr_] = elem;
	return &elem->evr_;
}








bool_t AsyncResultPool::Release(EventResult *evr)
{
	Guard<ThreadMutex> auto_release_lock(mutex_);

	ECILA_ASSERT(evr);

	bool_t ret = FALSE;

	ITER_T iter = acquire_map_.find(evr);
	if(iter == acquire_map_.end()) { ECILA_TRACE(); return FALSE; }

	ActPoolElement *act = iter->second;
	if(!act) { ECILA_TRACE(); return FALSE; }
	acquire_map_.erase(iter);

	evr->Reset();

	ret = pool_->Release(act);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}

