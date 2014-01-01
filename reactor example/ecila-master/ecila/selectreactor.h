#pragma once


#include "idemultiplexer.h"








NS_ECILA_START

class EventHandlerRep;

class DECL_SPEC_DLL SelectReactor
:	public IDemultiplexer
{
public:

			 SelectReactor();
	virtual ~SelectReactor();

	virtual bool_t HandleEvents		(int32_t timeout_msec);
	virtual bool_t RegisterHandler	(IEventHandler *h, EVENT_T e);
	virtual bool_t UnRegisterHandler(IEventHandler *h);

	virtual bool_t EnableEventMask	(IEventHandler *h, EVENT_T e);
	virtual bool_t DisableEventMask	(IEventHandler *h, EVENT_T e);


private:

	fd_set			rset_;
	fd_set			wset_;
	fd_set			eset_;
	EventHandlerRep *rep_;

	bool_t BindHandleEvent();
	bool_t WaitHandleEvent(int32_t timeout_msec, bool_t &b_timeout);
	bool_t ExecHandleEvent();
};

NS_ECILA_END

