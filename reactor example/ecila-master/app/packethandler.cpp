#include "packethandler.h"

#include <ecila/packet.h>
#include <ecila/ringbuffer.h>






US_ECILA

PacketHandler::PacketHandler()
{
	dispatch_q_ = 0;
	buff_pool_  = 0;
}








PacketHandler::~PacketHandler()
{
}








bool_t PacketHandler::HandleEvents(serial_t uidx, Session *sess, EVENT_T e)
{
	if(!sess) { ECILA_TRACE(); return FALSE; }

	switch(e)
	{
	case NS_ECILA::EVENT_OPEN	: return OnOpen(uidx, sess);
	case NS_ECILA::EVENT_CLOSE	: return OnClose(uidx, sess);
	case NS_ECILA::EVENT_READ	: return OnRead(uidx, sess);
	case NS_ECILA::EVENT_WRITE	: return OnWrite(uidx, sess);
	default						: { ECILA_TRACE(); return FALSE; }
	}
}








void PacketHandler::CacheNode()
{
	dispatch_q_ = root_->FindObject<MsgQueue>("/msg_q/dispatch_q");
	ECILA_ASSERT(dispatch_q_);

	buff_pool_ = root_->FindObject<BufferPool>("/pool/buff_pool");
	ECILA_ASSERT(buff_pool_);
}








bool_t PacketHandler::OnOpen(serial_t uidx, Session *sess)
{
	ECILA_PRINT(("[PacketHandler::OnOpen] uidx:"ECILA_FI64U", sock:%d\n", uidx, sess->Descriptor()));
	return TRUE;
}








bool_t PacketHandler::OnClose(serial_t uidx, Session *sess)
{
	ECILA_PRINT(("[PacketHandler::OnClose] uidx:"ECILA_FI64U", sock:%d\n", uidx, sess->Descriptor()));
	return TRUE;
}








bool_t PacketHandler::OnRead(serial_t uidx, Session *sess)
{
	bool_t  ret  = FALSE;
	int32_t iret = 0;

	RingBuffer *rbuffer    = sess->RecvBuffer();
	char_t     *context    = rbuffer->GetOutPtr();
	int32_t    context_len = rbuffer->Length();


	iret = HttpReqComplete(context, context_len);
	if(iret == -2) { ECILA_TRACE(); return FALSE; } // request format error
	if(iret == -1) { return TRUE; }                 // skip (more context)


	ret = rbuffer->ForwardOutPtr(context_len);
	if(!ret) { ECILA_TRACE(); return FALSE; }


	Buffer *buffer = buff_pool_->Acquire();
	if(!buffer) { ECILA_TRACE(); return FALSE; }

	PacketHeader pkt_header;
	pkt_header.kind_ = PKT_KIND_USERAPP;
	pkt_header.cmd_  = PKT_CMD_RECV;
	pkt_header.size_ = context_len;
	pkt_header.uidx_ = uidx;

	ret = buffer->PutBinary((char_t*)&pkt_header, sizeof(pkt_header));
	if(!ret) { ECILA_TRACE(); goto _ERROR; }

	ret = buffer->PutBinary(context, context_len);
	if(!ret) { ECILA_TRACE(); goto _ERROR; }

	dispatch_q_->Push(buffer);
	return TRUE;


_ERROR:
	buff_pool_->Release(buffer);
	return FALSE;
}








bool_t PacketHandler::OnWrite(serial_t uidx, Session *sess)
{
	return TRUE;
}








int32_t PacketHandler::HttpReqComplete(const char_t *context, int32_t context_len)
{
	if(context_len <= 4) { return -1; }

	if(ecila_strnicmp(context, "GET", 3) == 0)
	{
		return ecila_strncmp(&context[context_len - 4], "\r\n\r\n", 4) == 0 ? 0 : -2;
	}
	else if(ecila_strnicmp(context, "POST", 4) == 0)
	{
		const char_t *postvalue = strstr(context, "\r\n\r\n");
		if(postvalue == NULL) { return -1; }

		int32_t postvalue_len = &context[context_len] - postvalue - 4;
		if(postvalue_len < 0) { ECILA_TRACE(); return -2; }

		Tokenizer tk1;
		uint32_t line_count = tk1.STokenize(context, "\r\n");
		if(line_count <= 0) { return -1; }

		bool_t   f_content = FALSE;
		uint32_t n_content = 0;

		for(uint32_t i=0; i<line_count; i++)
		{
			if(ecila_strnicmp(tk1.Token(i), "CONTENT-LENGTH", 14) == 0)
			{
				f_content = TRUE;
				n_content = i;
				break;
			}
		}

		if(!f_content) { return -1; }

		Tokenizer tk2;
		uint32_t count = tk2.CTokenize(tk1.Token(n_content), ": ");
		if(count != 2) { ECILA_TRACE() return -2; }

		return ecila_atoi32(tk2.Token(1)) == postvalue_len ? 0 : -1;
	}
	else
	{
		ECILA_TRACE(); return -2;
	}
}

