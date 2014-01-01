#pragma once


#include "idemultiplexer.h"





#ifdef USE_DEMULTIPLEXER_IOCP

NS_ECILA_START

class DECL_SPEC_DLL IocpProactor
:	public IDemultiplexer
{
public:

			 IocpProactor();
	virtual ~IocpProactor();

	virtual bool_t HandleEvents		(int32_t timeout_msec);
	virtual bool_t RegisterHandler	(IEventHandler *h, EVENT_T e);
	virtual bool_t UnRegisterHandler(IEventHandler *h);
	virtual bool_t EnableEventMask	(IEventHandler *h, EVENT_T e);
	virtual bool_t DisableEventMask	(IEventHandler *h, EVENT_T e);


private:
	handle_t	completion_port_;

	bool_t InitDemultiplexer();
	bool_t FiniDemultiplexer();

};

NS_ECILA_END

#endif

