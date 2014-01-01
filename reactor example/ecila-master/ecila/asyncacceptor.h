#pragma once

#include "iacceptor.h"
#include "asyncsession.h"








NS_ECILA_START

class AsyncSessionPool;

class DECL_SPEC_DLL AsyncAcceptor
:	public IAcceptor, public AsyncSession
{
public:

	enum ENUM_MAX
	{
		MAX_BACK_LOG = 10,
	};

			 AsyncAcceptor(IDemultiplexer *demultiplexer, AsyncSessionPool *sess_pool);
	virtual ~AsyncAcceptor();

	virtual bool_t Open(uint16_t port, const char_t *ip = 0);


private:

	bool_t	MakeNewConnection();
	bool_t	GetPeerInfomation(char_t *buffer, uint32_t size, AsyncSession *sess);

	virtual bool_t PostRead();
	virtual bool_t OnRead(EventResult *evr);

	virtual bool_t MakeEventHandler		(AsyncSession *&sess);
	virtual bool_t ActivateEventHandler	(AsyncSession *sess);
	virtual bool_t AcceptEventHandler	(AsyncSession *sess);
};

NS_ECILA_END

