#include "session.h"

#include "idemultiplexer.h"
#include "ipackethandler.h"
#include "ringbuffer.h"








US_ECILA

Session::Session(IDemultiplexer *demultiplexer)
:	IEventHandler	(demultiplexer),
	recv_buffer_	(0),
	send_buffer_	(0)
{
	recv_buffer_	= new RingBuffer(RingBuffer::DEFAULT_BUFFER_SIZE * 2);
	send_buffer_	= new RingBuffer(RingBuffer::DEFAULT_BUFFER_SIZE * 2);

	pkt_handler_	= 0;
}






Session::~Session()
{
	ECILA_SAFE_DELETE(recv_buffer_);
	ECILA_SAFE_DELETE(send_buffer_);
}







handle_t Session::Handle()
{
	return &sock_;
}







descriptor_t Session::Descriptor()
{
	return sock_.GetSocket();
}






bool_t Session::Open()
{
	if(sock_.Status() != Socket::STATUS_NONE)
	{
		ECILA_TRACE(); return FALSE;
	}

	sock_.Status(Socket::STATUS_OPENED);
	return TRUE;
}








bool_t Session::Connect()
{
	if(sock_.Status() != Socket::STATUS_OPENED)
	{
		ECILA_TRACE(); return FALSE;
	}

	sock_.Status(Socket::STATUS_CONNECTED);
	return TRUE;
}








bool_t Session::Close(bool_t force)
{
	if(force == TRUE)
	{
		return OnClose(0);
	}

	if(sock_.Status() == Socket::STATUS_NONE)
	{
		ECILA_TRACE(); return FALSE;
	}

	sock_.Status(Socket::STATUS_NONE);
	return TRUE;
}








bool_t Session::Recv(char_t *buffer, uint32_t &size)
{
	return FALSE;
}








bool_t Session::Send(char_t *buffer, uint32_t &size)
{
	bool_t ret = FALSE;

	ret = Demultiplexer()->EnableEventMask(this, EVENT_WRITE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = send_buffer_->PutBinary(buffer, size);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = OnWrite(0);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}







bool_t Session::PKTHandler(IPacketHandler *pkt_handler)
{
	pkt_handler_ = pkt_handler;
	return TRUE;
}








IPacketHandler* Session::PKTHandler()
{
	return pkt_handler_;
}








RingBuffer* Session::RecvBuffer()
{
	return recv_buffer_;
}








RingBuffer* Session::SendBuffer()
{
	return send_buffer_;
}

