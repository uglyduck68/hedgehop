#include "kqueuereactor.h"
#include "ieventhandler.h"







#ifdef USE_DEMULTIPLEXER_KQUEUE

US_ECILA

KqueueReactor::KqueueReactor()
{
	kqfd_			= 0;
	max_handler_	= 0;

	memset(rep_, 0, sizeof(rep_));
	InitDemultiplexer();
}







KqueueReactor::~KqueueReactor()
{
	FiniDemultiplexer();
}







bool_t KqueueReactor::HandleEvents(int32_t timeout_msec)
{
	bool_t ret = FALSE;

	struct timespec timeout;
	timeout.tv_sec	=  timeout_msec / 1000;
	timeout.tv_nsec = (timeout_msec % 1000) * 1000 * 1000;

	int32_t result = kevent(kqfd_, 0, 0, rep_, IDemultiplexer::MAX_REPOSITORY_SIZE, ((timeout_msec < 0) ? NULL : &timeout));

	if	   (result < 0)	{ ECILA_TRACE(); return FALSE; }
	else if(result == 0){ return FALSE; }

	ECILA_PRINT(("event: ok\n"));

	for(int32_t i=0; i<result; i++)
	{
		struct kevent *ev = &rep_[i];
		if(ev == 0) { ECILA_TRACE(); continue; }

		if(ev->udata == 0) { ECILA_TRACE(); continue; }

		//이벤트 핸들러의 OnXXXX()류 함수에서 에러가 발생하여, 디멀티플렉서의 핸들 등록을 해재할 경우
		//이벤트 핸들러의 포인터를 0로 초기함으로, 레퍼런스를 얻어 이벤트를 처리하도록 한다.
		IEventHandler &h = *(IEventHandler*)ev->udata;

		if(ev->flags  & EV_ERROR) 		{ ret = h.OnError(0); if(!ret) { continue; } }
		if(ev->filter & EVFILT_READ)	{ ret = h.OnRead(0);  if(!ret) { continue; } }
		if(ev->filter & EVFILT_WRITE)	{ ret = h.OnWrite(0); if(!ret) { continue; } }
	}

	return TRUE;
}







bool_t KqueueReactor::RegisterHandler(IEventHandler *h, EVENT_T e)
{
	if(max_handler_ >= IDemultiplexer::MAX_REPOSITORY_SIZE) { ECILA_TRACE(); return FALSE; }

	short_t  filter	= TranslateEventMask(e);
	ushort_t flag	= EV_ADD | EV_ENABLE;

	struct kevent kev;
	memset(&kev, 0, sizeof(kev));

	EV_SET(&kev, h->Descriptor(), filter, flag, 0, 0, (void *)h);

	int32_t ret = kevent(kqfd_, &kev, 1, 0, 0, 0);
	if(ret < 0) { ECILA_ERROR(("errno (%d)\n", errno)); ECILA_TRACE(); return FALSE; }

	max_handler_++;

	ret = h->Registered(TRUE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = h->InitialEventMask(e);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;;
}








bool_t KqueueReactor::UnRegisterHandler(IEventHandler *h)
{
	if(max_handler_ == 0) { ECILA_TRACE(); return FALSE; }

	short_t  filter	= EVFILT_READ | EVFILT_WRITE;
	ushort_t flag	= EV_DELETE | EV_DISABLE;

	struct kevent kev;
	memset(&kev, 0, sizeof(kev));

	EV_SET(&kev, h->Descriptor(), filter, flag, 0, 0, 0);

	int32_t ret = kevent(kqfd_, &kev, 1, 0, 0, 0);
	if(ret < 0) { ECILA_ERROR(("errno (%d): %s\n", errno, strerror(errno))); ECILA_TRACE(); return FALSE; }

	max_handler_--;

	ret = h->Registered(FALSE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = h->InitialEventMask(EVENT_NONE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t KqueueReactor::EnableEventMask(IEventHandler *h, EVENT_T e)
{
	if(!h->Registered()) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t KqueueReactor::DisableEventMask(IEventHandler *h, EVENT_T e)
{
	return TRUE;
}








bool_t KqueueReactor::InitDemultiplexer()
{
	kqfd_ = kqueue();
	if(kqfd_ < 0) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t KqueueReactor::FiniDemultiplexer()
{
	if(kqfd_ == 0) { return TRUE; }
	if(kqfd_ <  0) { ECILA_TRACE(); return FALSE; }

	int32_t ret = close(kqfd_);
	if(ret < 0) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








short_t KqueueReactor::TranslateEventMask(EVENT_T e)
{
	short_t filter = 0;

	if(e & EVENT_READ)	filter |= EVFILT_READ;
	if(e & EVENT_WRITE)	filter |= EVFILT_WRITE;

	return filter;
}

#endif

