#include "dispatchtask.h"

#include <ecila/thread.h>
#include <ecila/packet.h>
#include <ecila/buffer.h>

#include "httpmsgreq.h"
#include "ihttpmsgdispatcher.h"
#include "httpmsgdispatcherdic.h"






US_ECILA

DispatchTask::DispatchTask()
{
	dispatch_q_	= 0;
	buff_pool_	= 0;
	httpd_dic_	= 0;
}








DispatchTask::~DispatchTask()
{
}








bool_t DispatchTask::Run()
{
	bool_t ret = FALSE;

	Node *root = static_cast< Node* >(Thread::UserPtr());
	if(!root) { ECILA_TRACE(); return FALSE; }

	CacheNode(root);

	while(!Thread::IsStop())
	{
		ret = DispatchMsg();
		if(!ret) { ecila_msleep(1); }
	}

	return TRUE;
}








void DispatchTask::CacheNode(Node *root)
{
	dispatch_q_ = root->FindObject<MsgQueue>("/msg_q/dispatch_q");
	ECILA_ASSERT(dispatch_q_);

	buff_pool_ = root->FindObject<BufferPool>("/pool/buff_pool");
	ECILA_ASSERT(buff_pool_);

	httpd_dic_ = root->FindObject<HttpMsgDispatcherDic>("/dictionary/httpd_dic");
	ECILA_ASSERT(httpd_dic_);
}








bool_t DispatchTask::DispatchMsg()
{
	bool_t ret = FALSE;

	Buffer *buffer = dispatch_q_->Pop();
	if(!buffer) { return FALSE; }

	PacketHeader pkt_header;

	ret = buffer->GetBinary((char_t*)&pkt_header, sizeof(pkt_header));
	if(!ret) { ECILA_TRACE(); goto _ERROR; }

	if(pkt_header.kind_ == PKT_KIND_USERAPP)
	{
		HttpMsgReq req;
		ret = req.Parse(buffer->GetOutPtr(), pkt_header.size_);
		//if(!ret) { ECILA_TRACE(); goto _ERROR; }

		IHttpMsgDispatcher *ihmd = httpd_dic_->Find(req.Uri());
		ret = ihmd->Dispatch(pkt_header.uidx_, &req);
		if(!ret) { ECILA_TRACE(); goto _ERROR; }
	}

	ret = buff_pool_->Release(buffer);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;


_ERROR:

	ret = buff_pool_->Release(buffer);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return FALSE;
}

