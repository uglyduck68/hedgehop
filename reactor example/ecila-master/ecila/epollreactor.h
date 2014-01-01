#pragma once


#include "idemultiplexer.h"





#ifdef USE_DEMULTIPLEXER_EPOLL

NS_ECILA_START

class DECL_SPEC_DLL EpollReactor
:	public IDemultiplexer
{
public:

			 EpollReactor();
	virtual ~EpollReactor();

	virtual bool_t HandleEvents		(int32_t timeout_msec);
	virtual bool_t RegisterHandler	(IEventHandler *h, EVENT_T e);
	virtual bool_t UnRegisterHandler(IEventHandler *h);
	virtual bool_t EnableEventMask	(IEventHandler *h, EVENT_T e);
	virtual bool_t DisableEventMask	(IEventHandler *h, EVENT_T e);


private:

	int32_t				efd_;
	uint32_t			max_handler_;
	struct epoll_event	rep_[IDemultiplexer::MAX_REPOSITORY_SIZE];

	bool_t   InitDemultiplexer();
	bool_t   FiniDemultiplexer();
	uint32_t TranslateEventMask(EVENT_T e);
};

NS_ECILA_END

#endif

