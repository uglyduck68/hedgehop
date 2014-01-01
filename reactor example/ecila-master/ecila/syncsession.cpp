#include "syncsession.h"

#include "ringbuffer.h"
#include "ipackethandler.h"
#include "idemultiplexer.h"
#include "syncsessionpool.h"








US_ECILA

SyncSession::SyncSession()
{
	sess_pool_		= 0;

	sock_.Mode(Socket::SOCK_SYNC_TCP);
}






SyncSession::SyncSession(IDemultiplexer *demultiplexer, SyncSessionPool *sess_pool)
:	Session(demultiplexer)
{
	sess_pool_		= 0;

	SessionPool(sess_pool);

	sock_.Mode(Socket::SOCK_SYNC_TCP);
}








SyncSession::~SyncSession()
{
}








bool_t SyncSession::OnOpen(EventResult *evr)
{
	bool_t ret = FALSE;

	IDemultiplexer *demultiplexer = Demultiplexer();
	if(demultiplexer)
	{
		ret = demultiplexer->RegisterHandler(this, EVENT_READ | EVENT_WRITE | EVENT_ERROR);
		if(!ret) { ECILA_TRACE(); return FALSE; }
	}

	ret = Open();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = Connect();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = pkt_handler_->HandleEvents(this->UIDX(), this, EVENT_OPEN);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t SyncSession::OnClose(EventResult *evr)
{
	bool_t ret = FALSE;

	IDemultiplexer *demultiplexer = Demultiplexer();
	if(demultiplexer)
	{
		ret = demultiplexer->UnRegisterHandler(this);
		if(!ret) { ECILA_TRACE(); return FALSE; }
	}

	ret = sock_.Close();
	if(!ret) { ECILA_TRACE(); return FALSE; }

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








bool_t SyncSession::OnRead(EventResult *evr)
{
	bool_t ret = FALSE;

	if(sock_.Status() != Socket::STATUS_CONNECTED)
	{
		ECILA_ERROR(("[SyncSession::OnWrite] "ECILA_FI64U"\n", UIDX())); return FALSE;
	}

	char_t *buffer = recv_buffer_->GetInPtr();
	int32_t remain = recv_buffer_->Remain();

	int32_t nbytes = sock_.Recv((char_t*)buffer, remain);
	if(nbytes == Socket::ERR_TRANSFER)
	{
		return OnError(evr);
	}
	
	ret = recv_buffer_->ForwardInPtr(nbytes);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = pkt_handler_->HandleEvents(this->UIDX(), this, EVENT_READ);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	if(recv_buffer_->Length() == 0) { recv_buffer_->Reset(); }

	return TRUE;
}








bool_t SyncSession::OnWrite(EventResult *evr)
{
	bool_t ret = FALSE;

	if(sock_.Status() != Socket::STATUS_CONNECTED)
	{
		ECILA_ERROR(("[SyncSession::OnWrite] "ECILA_FI64U"\n", UIDX())); return FALSE;
	}

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

	char_t *buffer = send_buffer_->GetOutPtr();
	int32_t nbytes = sock_.Send((char_t*)buffer, length);
	if(nbytes == Socket::ERR_TRANSFER)
	{
		return OnError(evr);
	}
	
	ret = send_buffer_->ForwardOutPtr(nbytes);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = pkt_handler_->HandleEvents(this->UIDX(), this, EVENT_WRITE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	if(send_buffer_->Length() == 0) { send_buffer_->Reset(); }

	return TRUE;
}








bool_t SyncSession::OnError(EventResult *evr)
{
	bool_t ret = FALSE;

	if(sock_.Status() == Socket::STATUS_NONE) { return TRUE; }

	ret = OnClose(0);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








SyncSessionPool* SyncSession::SessionPool()
{
	return sess_pool_;
}








bool_t SyncSession::SessionPool(SyncSessionPool *sess_pool)
{
	ECILA_ASSERT(sess_pool);

	sess_pool_ = sess_pool;
	return TRUE;
}








void SyncSession::Reset()
{
	recv_buffer_->Reset();
	send_buffer_->Reset();
}

