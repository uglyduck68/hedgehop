#pragma once


#include "session.h"









NS_ECILA_START

class SyncSessionPool;

class DECL_SPEC_DLL SyncSession
:	public Session
{
public:

			 SyncSession();
			 SyncSession(IDemultiplexer *demultiplexer, SyncSessionPool *sess_pool);
	virtual ~SyncSession();

	virtual bool_t	OnOpen	(EventResult *evr);
	virtual bool_t	OnClose	(EventResult *evr);
	virtual bool_t	OnRead	(EventResult *evr);
	virtual bool_t	OnWrite	(EventResult *evr);
	virtual bool_t	OnError	(EventResult *evr);
	virtual bool_t	Complete(EventResult *evr)	{ return FALSE; }

	SyncSessionPool* SessionPool();
	bool_t			 SessionPool(SyncSessionPool *sess_pool);

	void Reset();


private:
	SyncSessionPool	*sess_pool_;
};

NS_ECILA_END
