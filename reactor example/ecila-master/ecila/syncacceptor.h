#pragma once


#include "iacceptor.h"
#include "syncsession.h"






NS_ECILA_START

class SyncSessionPool;

class DECL_SPEC_DLL SyncAcceptor
:	public IAcceptor, public SyncSession
{
public:

	enum ENUM_MAX
	{
		MAX_BACK_LOG = 10,
	};

			 SyncAcceptor(IDemultiplexer *reactor, SyncSessionPool *sess_pool);
	virtual ~SyncAcceptor();

	virtual bool_t Open(uint16_t port, const char_t *ip = 0);


private:

	virtual bool_t OnRead(EventResult *evr);

	virtual bool_t MakeEventHandler		(SyncSession *&sess);
	virtual bool_t AcceptEventHandler	(SyncSession *sess);
	virtual bool_t ActivateEventHandler	(SyncSession *sess);

};

NS_ECILA_END

