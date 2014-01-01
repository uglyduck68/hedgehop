#include "selectreactor.h"
#include "eventhandlerrep.h"
#include "ieventhandler.h"







US_ECILA

SelectReactor::SelectReactor()
:	rep_(0)
{
	rep_ = new EventHandlerRep();
}








SelectReactor::~SelectReactor()
{
	ECILA_SAFE_DELETE(rep_);
}








bool_t SelectReactor::HandleEvents(int32_t timeout_msec)
{
	bool_t ret       = FALSE;
	bool_t b_timeout = FALSE;

	ret = BindHandleEvent();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = WaitHandleEvent(timeout_msec, b_timeout);
	if(!ret && b_timeout == TRUE)  { return TRUE; }
	if(!ret && b_timeout == FALSE) { ECILA_TRACE(); return FALSE; }

	ret = ExecHandleEvent();
	if(!ret) { ECILA_TRACE(); return FALSE; }
	
	return TRUE;
}








bool_t SelectReactor::RegisterHandler(IEventHandler *h, EVENT_T e)
{
	bool_t ret = FALSE;

	ret = rep_->Register(h, e);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = h->Registered(TRUE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = h->InitialEventMask(e);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t SelectReactor::UnRegisterHandler(IEventHandler *h)
{
	bool_t ret = FALSE;

	ret = rep_->UnRegister(h);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = h->Registered(FALSE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = h->InitialEventMask(EVENT_NONE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t SelectReactor::EnableEventMask(IEventHandler *h, EVENT_T e)
{
	if(!h->Registered()) { ECILA_TRACE(); return FALSE; }

	for(uint32_t i=0; i<rep_->Capacity(); i++)
	{
		EventHandlerRep::DATA_T *t = rep_->Get(i);
		if(!t) { ECILA_TRACE(); return FALSE; }

		if(t->handler_ != h) continue;

		t->eventmask_ |= e;
		return TRUE;
	}

	return FALSE;
}








bool_t SelectReactor::DisableEventMask(IEventHandler *h, EVENT_T e)
{
	if(!h->Registered()) { ECILA_TRACE(); return FALSE; }

	for(uint32_t i=0; i<rep_->Capacity(); i++)
	{
		EventHandlerRep::DATA_T *t = rep_->Get(i);
		if(!t) { ECILA_TRACE(); return FALSE; }

		if(t->handler_ != h) continue;

		t->eventmask_ ^= e;
		return TRUE;
	}

	return FALSE;
}








bool_t SelectReactor::BindHandleEvent()
{
	FD_ZERO(&rset_); FD_ZERO(&wset_); FD_ZERO(&eset_);

	uint32_t count = 0;
	for(uint32_t i=0; i<rep_->Capacity(); i++)
	{
		EventHandlerRep::DATA_T *t = rep_->Get(i);
		if(!t) { ECILA_TRACE(); return FALSE; }

		if(t->handler_ == 0) continue;

#ifdef OS_WINDOWS
#pragma warning(push)
#pragma warning(disable : 4127)
#endif
		if(t->eventmask_ & EVENT_READ)	{ FD_SET(t->handler_->Descriptor(), &rset_); }
		if(t->eventmask_ & EVENT_WRITE)	{ FD_SET(t->handler_->Descriptor(), &wset_); }
		if(t->eventmask_ & EVENT_ERROR)	{ FD_SET(t->handler_->Descriptor(), &eset_); }

#ifdef OS_WINDOWS
#pragma warning(pop)
#endif
		rep_->MaxDescriptor(t->handler_->Descriptor());

		count++;
		if(count == rep_->Count()) break;
	}

	return TRUE;
}








bool_t SelectReactor::WaitHandleEvent(int32_t timeout_msec, bool_t &b_timeout)
{
	int32_t ret = 0;

	struct timeval timeout;
	timeout.tv_sec	=  timeout_msec / 1000;
	timeout.tv_usec = (timeout_msec % 1000) * 1000;

	ret = select(rep_->MaxDescriptor() + 1, &rset_, &wset_, &eset_, ((timeout_msec < 0) ? NULL : &timeout));
	if	   (ret <  0) { ECILA_TRACE();    return FALSE; }
	else if(ret == 0) { b_timeout = TRUE; return FALSE; }	// timeout
	else              { return TRUE; }
}








bool_t SelectReactor::ExecHandleEvent()
{
	bool_t ret = FALSE;
	
	uint32_t count = 0;
	uint32_t act_count = rep_->Count();
	for(uint32_t i=0; i<rep_->Capacity(); i++)
	{
		EventHandlerRep::DATA_T *t = rep_->Get(i);
		if(!t) { ECILA_TRACE(); return FALSE; }

		if(t->handler_ == 0) continue;

		//이벤트 핸들러의 OnXXXX()류 함수에서 에러가 발생하여, 디멀티플렉서의 핸들 등록을 해재할 경우
		//이벤트 핸들러의 포인터를 0로 초기함으로, 레퍼런스를 얻어 이벤트를 처리하도록 한다.
		IEventHandler &h = *t->handler_;

		if(FD_ISSET(h.Descriptor(), &rset_)) { ret = h.OnRead(0);  if(!ret) goto _ERROR; }
		if(FD_ISSET(h.Descriptor(), &wset_)) { ret = h.OnWrite(0); if(!ret) goto _ERROR; }
		if(FD_ISSET(h.Descriptor(), &eset_)) { ret = h.OnError(0); if(!ret) goto _ERROR; }

_ERROR:
		count++;
		if(count == act_count) break;
	}

	return TRUE;
}

