#include "asyncsessionpool.h"

#include "guard.h"
#include "serial.h"








US_ECILA

AsyncSessionPool::AsyncSessionPool()
{
	serial_	= 0;
	pool_	= 0;
}








AsyncSessionPool::~AsyncSessionPool()
{
	Finalize();
}








bool_t AsyncSessionPool::Initialize()
{
	bool_t ret = FALSE;

	try
	{
		serial_ = new Serial();
		ECILA_ASSERT(serial_);

		pool_ = new Pool<AsyncSession>();
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








bool_t AsyncSessionPool::Finalize()
{
	ECILA_SAFE_DELETE(serial_);
	ECILA_SAFE_DELETE(pool_);

	return TRUE;
}








AsyncSession* AsyncSessionPool::Acquire()
{
	Guard<ThreadMutex> auto_release_lock(mutex_);

	ECILA_ASSERT(pool_);

	bool_t ret = FALSE;

	AsyncSession *sess = pool_->Acquire(__FILE__, __LINE__);
	if(!sess) { ECILA_TRACE(); return 0; }

	serial_t uidx = serial_->Issue();
	ret = sess->UIDX(uidx);
	if(!ret) { ECILA_TRACE(); return 0; }

	ret = sess->SessionPool(this);
	if(!ret) { ECILA_TRACE(); return 0; }

	ret = Register(uidx, sess);
	if(!ret) { ECILA_TRACE(); return 0; }

	return sess;
}








bool_t AsyncSessionPool::Release(AsyncSession *sess)
{
	Guard<ThreadMutex> auto_release_lock(mutex_);

	ECILA_ASSERT(pool_);

	bool_t ret = FALSE;

	ret = UnRegister(sess->UIDX());
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = pool_->Release(sess);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	sess->UIDX(0);
	sess->Reset();

	return TRUE;
}








Session* AsyncSessionPool::ACTSession(serial_t uidx)
{
	Guard<ThreadMutex> auto_release_lock(mutex_);

	ITER_T iter = map_.find(uidx);
	if(iter == map_.end())
	{
		ECILA_ERROR(("[AsyncSessionPool::ACTSession] "ECILA_FI64U"\n", uidx));
		return 0;
	}

	return iter->second;
}








bool_t AsyncSessionPool::Register(serial_t uidx, AsyncSession *sess)
{
	ITER_T iter = map_.find(uidx);
	if(iter != map_.end()) { ECILA_TRACE(); return FALSE; }

	map_[uidx] = sess;
	return TRUE;
}








bool_t AsyncSessionPool::UnRegister(serial_t uidx)
{
	ITER_T iter = map_.find(uidx);
	if(iter == map_.end()) { ECILA_TRACE(); return FALSE; }

	map_.erase(iter);
	return TRUE;
}

