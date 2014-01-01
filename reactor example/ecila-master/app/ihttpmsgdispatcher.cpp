#include "ihttpmsgdispatcher.h"


#include <ecila/packet.h>








US_ECILA

IHttpMsgDispatcher::IHttpMsgDispatcher()
{
	root_      = 0;
	buff_pool_ = 0;
	network_q_ = 0;
}








IHttpMsgDispatcher::~IHttpMsgDispatcher()
{
}








bool_t IHttpMsgDispatcher::Initialize(NS_ECILA::Node *root)
{
	root_ = root;
	ECILA_ASSERT(root_);
	
	buff_pool_ = root_->FindObject<BufferPool>("/pool/buff_pool");
	ECILA_ASSERT(buff_pool_);

	network_q_ = root_->FindObject<MsgQueue>("/msg_q/network_q");
	ECILA_ASSERT(network_q_);

	return TRUE;
}








bool_t IHttpMsgDispatcher::Finalize()
{
	return TRUE;
}








bool_t IHttpMsgDispatcher::SendResponse(serial_t uidx, int32_t status, const char_t* context, uint32_t context_len)
{
	bool_t ret = FALSE;

	Buffer* buffer = buff_pool_->Acquire();
	if(!buffer) { ECILA_TRACE(); return FALSE; }

	PacketHeader pkt_header;
	HttpMsgRes   res;

	ret = res.Version(1, 1);
	if(!ret) { ECILA_TRACE(); goto _ERROR; }

	ret = res.Status(status);
	if(!ret) { ECILA_TRACE(); goto _ERROR; }

	ret = res.PutHeader("Content-Type", "text/html; charset=UTF-8");
	if(!ret) { ECILA_TRACE(); goto _ERROR; }

	ret = res.PutContext(context, context_len);
	if(!ret) { ECILA_TRACE(); goto _ERROR; }

	ret = buffer->ForwardInPtr(sizeof(pkt_header));
	if(!ret) { ECILA_TRACE(); goto _ERROR; }

	ret = res.Serialize(buffer);
	if(!ret) { ECILA_TRACE(); goto _ERROR; }


	pkt_header.kind_ = PKT_KIND_USERAPP;
	pkt_header.cmd_  = PKT_CMD_SEND | PKT_CMD_CLOSE;
	pkt_header.size_ = buffer->Length() - sizeof(pkt_header);
	pkt_header.uidx_ = uidx;


	ret = buffer->RewindInPtr(buffer->Length());
	if(!ret) { ECILA_TRACE(); goto _ERROR; }

	ret = buffer->PutBinary((char_t*)&pkt_header, sizeof(pkt_header));
	if(!ret) { ECILA_TRACE(); goto _ERROR; }

	ret = buffer->ForwardInPtr(pkt_header.size_);
	if(!ret) { ECILA_TRACE(); goto _ERROR; }

	network_q_->Push(buffer);
	return TRUE;


_ERROR:
	ret = buff_pool_->Release(buffer);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return FALSE;
}

