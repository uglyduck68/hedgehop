#pragma once


#include "idemultiplexer.h"





#ifdef USE_DEMULTIPLEXER_KQUEUE

NS_ECILA_START

class DECL_SPEC_DLL KqueueReactor
:	public IDemultiplexer
{
public:

			 KqueueReactor();
	virtual ~KqueueReactor();

	virtual bool_t HandleEvents		(int32_t timeout_msec);
	virtual bool_t RegisterHandler	(IEventHandler *h, EVENT_T e);
	virtual bool_t UnRegisterHandler(IEventHandler *h);
	virtual bool_t EnableEventMask	(IEventHandler *h, EVENT_T e);
	virtual bool_t DisableEventMask	(IEventHandler *h, EVENT_T e);


private:

	int32_t			kqfd_;
	uint32_t		max_handler_;
	struct kevent	rep_[IDemultiplexer::MAX_REPOSITORY_SIZE];

	bool_t	InitDemultiplexer();
	bool_t	FiniDemultiplexer();
	short_t	TranslateEventMask(EVENT_T e);

};
	
NS_ECILA_END

#endif

