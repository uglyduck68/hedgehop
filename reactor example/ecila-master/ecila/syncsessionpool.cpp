#include "syncsessionpool.h"
#include "serial.h"








US_ECILA

SyncSessionPool::SyncSessionPool()
{
	serial_	= 0;
	pool_	= 0;
}








SyncSessionPool::~SyncSessionPool()
{
	Finalize();
}








bool_t SyncSessionPool::Initialize()
{
	bool_t ret = FALSE;

	try
	{
		serial_ = new Serial();
		ECILA_ASSERT(serial_);

		pool_ = new Pool<SyncSession>();
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








bool_t SyncSessionPool::Finalize()
{
	ECILA_SAFE_DELETE(serial_);
	ECILA_SAFE_DELETE(pool_)

	return TRUE;
}








SyncSession* SyncSessionPool::Acquire()
{
	ECILA_ASSERT(pool_);

	bool_t ret = FALSE;

	SyncSession *sess = pool_->Acquire(__FILE__, __LINE__);
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








bool_t SyncSessionPool::Release(SyncSession *sess)
{
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








Session* SyncSessionPool::ACTSession(serial_t uidx)
{
	ITER_T iter = map_.find(uidx);
	if(iter == map_.end())
	{
		ECILA_ERROR(("[SyncSessionPool::ACTSession] "ECILA_FI64U"\n", uidx));
		return 0;
	}

	return iter->second;
}








bool_t SyncSessionPool::Register(serial_t uidx, SyncSession *sess)
{
	ITER_T iter = map_.find(uidx);
	if(iter != map_.end()) { ECILA_TRACE(); return FALSE; }

	map_[uidx] = sess;
	return TRUE;
}








bool_t SyncSessionPool::UnRegister(serial_t uidx)
{
	ITER_T iter = map_.find(uidx);
	if(iter == map_.end()) { ECILA_TRACE(); return FALSE; }

	map_.erase(iter);
	return TRUE;
}

