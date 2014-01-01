#include "asyncsession.h"

#include "ringbuffer.h"
#include "ipackethandler.h"
#include "idemultiplexer.h"
#include "asyncresultpool.h"
#include "asyncsessionpool.h"







US_ECILA

AsyncSession::AsyncSession()
{
	post_close_yn_	= FALSE;
	act_pool_		= 0;
	sess_pool_		= 0;

	sock_.Mode(Socket::SOCK_ASYNC_TCP);
}








AsyncSession::AsyncSession(IDemultiplexer *demultiplexer, AsyncSessionPool *sess_pool)
:	Session(demultiplexer)
{
	post_close_yn_	= FALSE;
	act_pool_		= 0;
	sess_pool_		= 0;

	SessionPool(sess_pool);
	sock_.Mode(Socket::SOCK_ASYNC_TCP);
}








AsyncSession::~AsyncSession()
{
}








bool_t AsyncSession::PostOpen()
{
	bool_t ret = FALSE;

	IDemultiplexer *demultiplexer = Demultiplexer();
	if(demultiplexer)
	{
		ret = demultiplexer->RegisterHandler(this, EVENT_READ | EVENT_WRITE | EVENT_ERROR);
		if(!ret) { ECILA_TRACE(); return FALSE; }
	}

	return OnOpen(0);
}








bool_t AsyncSession::PostClose()
{
	bool_t ret = FALSE;

	if(post_close_yn_ == TRUE) { return TRUE; }

	EventResult *evr = act_pool_->Acquire();
	if(!evr) { ECILA_TRACE(); return FALSE; }

	evr->Event(EVENT_CLOSE);
	evr->Handler(this);
	evr->Buffer(recv_buffer_->GetInPtr(), recv_buffer_->Remain()); 

	ret = sock_.SetLinger(TRUE, 0);
	if(!ret) { ECILA_TRACE(); goto _ERROR; }

	ret = sock_.Disconnect(evr);
	if(!ret) { ECILA_TRACE(); goto _ERROR; }

	post_close_yn_ = TRUE;
	return TRUE;


_ERROR:

	act_pool_->Release(evr);
	return FALSE;
}








bool_t AsyncSession::PostRead()
{
	int32_t iret = 0;
	if(post_close_yn_ == TRUE) { return TRUE; }

	if(sock_.Status() != Socket::STATUS_CONNECTED)
	{
		ECILA_TRACE(); return FALSE;
	}

	EventResult *evr = act_pool_->Acquire();
	if(!evr) { ECILA_TRACE(); return FALSE; }

	evr->Event(EVENT_READ);
	evr->Handler(this);
	evr->Buffer(recv_buffer_->GetInPtr(), recv_buffer_->Remain()); 

	iret = sock_.Recv(evr->Buffer(), evr->BufferSize(), evr->WSABuff(), evr);
	if(iret == Socket::ERR_TRANSFER) { ECILA_TRACE(); goto _ERROR; }

	return TRUE;

_ERROR:

	act_pool_->Release(evr);
	return FALSE;
}








bool_t AsyncSession::PostWrite()
{
	int32_t iret = 0;
	if(post_close_yn_ == TRUE) { return TRUE; }

	if(sock_.Status() != Socket::STATUS_CONNECTED)
	{
		ECILA_TRACE(); return FALSE;
	}

	EventResult *evr = act_pool_->Acquire();
	if(!evr) { ECILA_TRACE(); return FALSE; }

	evr->Event(EVENT_WRITE);
	evr->Handler(this);
	evr->Buffer(send_buffer_->GetOutPtr(), send_buffer_->Length()); 

	iret = sock_.Send(evr->Buffer(), evr->BufferSize(), evr->WSABuff(), evr);
	if(iret == Socket::ERR_TRANSFER) { ECILA_TRACE(); goto _ERROR; }

	return TRUE;

_ERROR:

	act_pool_->Release(evr);
	return FALSE;
}








bool_t AsyncSession::PostError()
{
	bool_t ret = FALSE;
	if(post_close_yn_ == TRUE) { return TRUE; }

	if(sock_.Status() == Socket::STATUS_NONE) { return TRUE; }

	sock_.Status(Socket::STATUS_CLOSED);

	ret = PostClose();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t AsyncSession::OnOpen(EventResult *evr)
{
	bool_t ret = FALSE;

	ret = Open();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = Connect();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = pkt_handler_->HandleEvents(this->UIDX(), this, EVENT_OPEN);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t AsyncSession::OnClose(EventResult *evr)
{
	bool_t ret = FALSE;

	if(!evr) { return PostClose(); }
	
	IDemultiplexer *demultiplexer = Demultiplexer();
	if(demultiplexer)
	{
		ret = demultiplexer->UnRegisterHandler(this);
		if(!ret) { ECILA_TRACE(); return FALSE; }
	}

	ret = Close();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = pkt_handler_->HandleEvents(this->UIDX(), this, EVENT_CLOSE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	if(sess_pool_)
	{
		ret = sess_pool_->Release(this);
		if(!ret) { ECILA_TRACE(); return FALSE; }
	}

	return TRUE;
}








bool_t AsyncSession::OnRead(EventResult *evr)
{
	bool_t ret = FALSE;

	ulong_t nbytes = evr->Transffered();
	if(nbytes == 0)
	{
		recv_buffer_->Reset();
		return PostError();
	}

	ret = recv_buffer_->ForwardInPtr(nbytes);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = pkt_handler_->HandleEvents(this->UIDX(), this, EVENT_READ);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	if(recv_buffer_->Length() == 0) { recv_buffer_->Reset(); }

	return PostRead();
}








bool_t AsyncSession::OnWrite(EventResult *evr)
{
	bool_t ret = FALSE;

	if(!evr) { return PostWrite(); }

	int32_t length = send_buffer_->Length();
	if(length == 0) 
	{
		send_buffer_->Reset();

		IDemultiplexer *demultiplexer = Demultiplexer();
		if(demultiplexer)
		{
			ret = demultiplexer->DisableEventMask(this, EVENT_WRITE);
			if(!ret) { ECILA_TRACE(); return FALSE; }
		}
		
		return TRUE;
	}

	ulong_t nbytes = evr->Transffered();
	if(nbytes == 0)
	{
		recv_buffer_->Reset();
		return PostError();
	}

	ret = send_buffer_->ForwardOutPtr(nbytes);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = pkt_handler_->HandleEvents(this->UIDX(), this, EVENT_WRITE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	if(send_buffer_->Length() == 0) { send_buffer_->Reset(); }

	return PostWrite();
}








bool_t AsyncSession::OnError(EventResult *evr)
{
	recv_buffer_->Reset();

	sock_.Status(Socket::STATUS_CLOSED);

	return PostClose();
}








bool_t AsyncSession::Complete(EventResult *evr)
{
	bool_t ret = FALSE;
	int32_t e = ((evr->Error() > 0) ? EVENT_ERROR : evr->Event());

	if(e & EVENT_OPEN)	{ ret = OnOpen(evr);	if(!ret) { ECILA_TRACE(); } }
	if(e & EVENT_CLOSE)	{ ret = OnClose(evr);	if(!ret) { ECILA_TRACE(); } }
	if(e & EVENT_READ)	{ ret = OnRead(evr);	if(!ret) { ECILA_TRACE(); } }
	if(e & EVENT_WRITE)	{ ret = OnWrite(evr);	if(!ret) { ECILA_TRACE(); } }
	if(e & EVENT_ERROR) { ret = OnError(evr);	if(!ret) { ECILA_TRACE(); } }

	act_pool_->Release(evr);
	return ret;
}








AsyncSessionPool* AsyncSession::SessionPool()
{
	return sess_pool_;
}








bool_t AsyncSession::SessionPool(AsyncSessionPool *sess_pool)
{
	ECILA_ASSERT(sess_pool);

	sess_pool_ = sess_pool;
	return TRUE;
}









AsyncResultPool* AsyncSession::ActPool()
{
	return act_pool_;
}








bool_t AsyncSession::ActPool(AsyncResultPool *act_pool)
{
	ECILA_ASSERT(act_pool);

	act_pool_ = act_pool;
	return TRUE;
}








void AsyncSession::Reset()
{
	recv_buffer_->Reset();
	send_buffer_->Reset();

	post_close_yn_	= FALSE;
}

