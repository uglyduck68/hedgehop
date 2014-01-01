#pragma once


#include "session.h"








NS_ECILA_START

class Buffer;
class AsyncResult;
class AsyncResultPool;
class AsyncSessionPool;

class DECL_SPEC_DLL AsyncSession
:	public Session
{
public:

			 AsyncSession();
			 AsyncSession(IDemultiplexer *demultiplexer, AsyncSessionPool *sess_pool);
	virtual ~AsyncSession();

	virtual bool_t PostOpen		();
	virtual bool_t PostClose	();
	virtual bool_t PostRead		();
	virtual bool_t PostWrite	();
	virtual bool_t PostError	();

	//completion operation
	virtual bool_t	OnOpen	(EventResult *evr);
	virtual bool_t	OnClose	(EventResult *evr);
	virtual bool_t	OnRead	(EventResult *evr);
	virtual bool_t	OnWrite	(EventResult *evr);
	virtual bool_t	OnError	(EventResult *evr);
	virtual bool_t	Complete(EventResult *evr);

	AsyncSessionPool* SessionPool();
	bool_t			  SessionPool(AsyncSessionPool *sess_pool);

	AsyncResultPool*  ActPool();
	bool_t			  ActPool(AsyncResultPool *act_pool);

	void Reset();


private:
	bool_t				post_close_yn_;
	AsyncSessionPool	*sess_pool_;
	AsyncResultPool		*act_pool_;
};

NS_ECILA_END
