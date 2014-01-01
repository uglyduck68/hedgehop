#include "demultiplexer.h"


#include "iocpproactor.h"
#include "kqueuereactor.h"
#include "epollreactor.h"
#include "selectreactor.h"








US_ECILA

Demultiplexer::Demultiplexer()
{
	demultiplexer_ = 0;
}








Demultiplexer::~Demultiplexer()
{
	ECILA_SAFE_DELETE(demultiplexer_);
}








void Demultiplexer::Initialize(const char_t *netio)
{
	if(ecila_strncmp(netio, "async", 5) == 0)
	{
		#if defined(USE_DEMULTIPLEXER_IOCP)
		demultiplexer_ = new IocpProactor();
		#else
		ECILA_TRACE();
		#endif
	}
	else if(ecila_strncmp(netio, "sync", 4) == 0)
	{
		#if defined(USE_DEMULTIPLEXER_KQUEUE)
		demultiplexer_ = new KqueueReactor();
	
		#elif defined(USE_DEMULTIPLEXER_EPOLL)
		demultiplexer_ = new EpollReactor();

		#else
		demultiplexer_ = new SelectReactor();
		#endif
	}
	else
	{
		ECILA_TRACE();
	}
}








IDemultiplexer* Demultiplexer::DemultiplexerImpl()
{
	return demultiplexer_;
}

