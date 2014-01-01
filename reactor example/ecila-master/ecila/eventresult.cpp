#include "eventresult.h"
#include "ieventhandler.h"
#include "iasyncresult.h"








US_ECILA

EventResult::EventResult()
{
	Reset(TRUE);
}









EventResult::~EventResult()
{
}








void EventResult::Event(EVENT_T e)
{
	eventmask_ = e;
}








int32_t EventResult::Event()
{
	return eventmask_;
}








void EventResult::Transffered(ulong_t v)
{
	nbytes_ = v;
}








ulong_t EventResult::Transffered()
{
	return nbytes_;
}








void EventResult::Status(bool_t v)
{
	status_ = v;
}








bool_t EventResult::Status()
{
	return status_;
}








void EventResult::Error(ulong_t v)
{
	errno_ = v;
}








ulong_t EventResult::Error()
{
	return errno_;
}








char_t* EventResult::Buffer()
{
	return buffer_;
}








void EventResult::Buffer(char_t *buffer, int32_t size)
{
	buffer_			= buffer;
	buffer_size_	= size;
}








int32_t EventResult::BufferSize()
{
	return buffer_size_;
}








wsabuf_t* EventResult::WSABuff()
{
	return &wsabuf_;
}








void EventResult::Handler(IEventHandler *h)
{
	handler_ = h;
}








IEventHandler* EventResult::Handler()
{
	return handler_;
}








void EventResult::AcceptHandler(IEventHandler *h)
{
	accept_handler_ = h;
}








IEventHandler* EventResult::AcceptHandler()
{
	return accept_handler_;
}








void EventResult::ActImpl(IAsyncResult *act_impl)
{
	act_impl_ = act_impl;
}








IAsyncResult* EventResult::ActImpl()
{
	return act_impl_;
}







void EventResult::Reset(bool_t rst_act_impl_yn)
{
	//clear overlapped struct
	#ifdef OS_WINDOWS
	this->Internal		= 0;
	this->InternalHigh	= 0;
	this->Offset		= 0;
	this->OffsetHigh	= 0;
	this->hEvent		= 0;
	#endif

	eventmask_			= EVENT_NONE;
	status_				= 0;
	errno_				= 0;
	nbytes_				= 0;


	buffer_				= 0;
	buffer_size_		= 0;

	memset(&wsabuf_,	0, sizeof(wsabuf_));


	handler_			= 0;
	accept_handler_		= 0;

	if(rst_act_impl_yn) { act_impl_	= 0; }
}

