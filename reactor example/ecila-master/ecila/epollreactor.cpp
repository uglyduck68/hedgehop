#include "epollreactor.h"
#include "ieventhandler.h"








#ifdef USE_DEMULTIPLEXER_EPOLL

US_ECILA

EpollReactor::EpollReactor()
{
	efd_			= 0;
	max_handler_	= 0;

	memset(rep_, 0, sizeof(rep_));
	InitDemultiplexer();
}








EpollReactor::~EpollReactor()
{
	FiniDemultiplexer();
}








bool_t EpollReactor::HandleEvents(int32_t timeout_msec)
{
	bool_t ret = FALSE;

	int32_t result = epoll_wait(efd_, rep_, IDemultiplexer::MAX_REPOSITORY_SIZE, timeout_msec < 0 ? INFINITE : timeout_msec);
	if	   (result <  0) { ECILA_TRACE(); return FALSE; }
	else if(result == 0) { return FALSE; }	// timeout

	for(int32_t i=0; i<result; i++)
	{
		struct epoll_event *ev = &rep_[i];
		if(ev == 0) { ECILA_TRACE(); continue; }

		if(ev->data.ptr == 0) { ECILA_TRACE(); continue; }

		//이벤트 핸들러의 OnXXXX()류 함수에서 에러가 발생하여, 디멀티플렉서의 핸들 등록을 해재할 경우
		//이벤트 핸들러의 포인터를 0로 초기함으로, 레퍼런스를 얻어 이벤트를 처리하도록 한다.
		IEventHandler &h = *(IEventHandler*)ev->data.ptr;

		if(ev->events & EPOLLIN)	{ ret = h.OnRead(0);  if(!ret) { continue; } }
		if(ev->events & EPOLLOUT)	{ ret = h.OnWrite(0); if(!ret) { continue; } }
		if(ev->events & EPOLLERR) 	{ ret = h.OnError(0); if(!ret) { continue; } }
	}

	return TRUE;
}








bool_t EpollReactor::RegisterHandler(IEventHandler *h, EVENT_T e)
{
	if(max_handler_ >= IDemultiplexer::MAX_REPOSITORY_SIZE) { ECILA_TRACE(); return FALSE; }

	struct epoll_event ev;
	memset(&ev, 0, sizeof(ev));
	ev.events	= TranslateEventMask(e);
	ev.data.ptr	= (void *)h;

	int32_t ret = epoll_ctl(efd_, EPOLL_CTL_ADD, h->Descriptor(), &ev);
	if(ret < 0) { ECILA_TRACE(); return FALSE; }

	max_handler_++;

	ret = h->Registered(TRUE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = h->InitialEventMask(e);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t EpollReactor::UnRegisterHandler(IEventHandler *h)
{
	if(max_handler_ == 0) { ECILA_TRACE(); return FALSE; }

	struct epoll_event ev;
	memset(&ev, 0, sizeof(ev));

	int32_t ret = epoll_ctl(efd_, EPOLL_CTL_DEL, h->Descriptor(), &ev);
	if(ret < 0) { ECILA_TRACE(); return FALSE; }

	max_handler_--;

	ret = h->Registered(FALSE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = h->InitialEventMask(EVENT_NONE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t EpollReactor::EnableEventMask(IEventHandler *h, EVENT_T e)
{
	if(!h->Registered()) { ECILA_TRACE(); return FALSE; }

	struct epoll_event ev;
	memset(&ev, 0, sizeof(ev));
	EVENT_T new_event_mask = h->InitialEventMask() | e;
	ev.events	= TranslateEventMask(new_event_mask);
	ev.data.ptr	= (void *)h;

	int32_t ret = epoll_ctl(efd_, EPOLL_CTL_MOD, h->Descriptor(), &ev);
	if(ret < 0) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t EpollReactor::DisableEventMask(IEventHandler *h, EVENT_T e)
{
	if(!h->Registered()) { ECILA_TRACE(); return FALSE; }

	struct epoll_event ev;
	memset(&ev, 0, sizeof(ev));
	EVENT_T new_event_mask = h->InitialEventMask() ^ e;
	ev.events	= TranslateEventMask(new_event_mask);
	ev.data.ptr	= (void *)h;

	int32_t ret = epoll_ctl(efd_, EPOLL_CTL_MOD, h->Descriptor(), &ev);
	if(ret < 0) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t EpollReactor::InitDemultiplexer()
{
	efd_ = epoll_create(IDemultiplexer::MAX_REPOSITORY_SIZE);
	if(efd_ < 0) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t EpollReactor::FiniDemultiplexer()
{
	if(efd_ == 0) { return TRUE; }
	if(efd_ <  0) { ECILA_TRACE(); return FALSE; }

	int32_t ret = close(efd_);
	if(ret < 0) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








uint32_t EpollReactor::TranslateEventMask(EVENT_T e)
{
	uint32_t op = 0;

	if(e & EVENT_READ)	op |= EPOLLIN;
	if(e & EVENT_WRITE)	op |= EPOLLOUT;
	if(e & EVENT_ERROR)	op |= EPOLLERR;

	//edge triggered 로 동작하게 한다.(EPOLLET 를 없애면 level triggerd로 동장)
	return op | EPOLLET;
}

#endif

