#include "asyncacceptor.h"

#include "ringbuffer.h"
#include "idemultiplexer.h"
#include "asyncsessionpool.h"
#include "asyncresultpool.h"








US_ECILA

AsyncAcceptor::AsyncAcceptor(IDemultiplexer *demultiplexer, AsyncSessionPool *sess_pool)
:	AsyncSession(demultiplexer, sess_pool)
{
}






AsyncAcceptor::~AsyncAcceptor()
{
}






bool_t AsyncAcceptor::Open(unsigned short port, const char *ip)
{
	bool_t ret = FALSE;

	ret = sock_.Mode(Socket::SOCK_ASYNC_TCP);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = sock_.Open();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = PostOpen();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = sock_.Bind(port, ip);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = sock_.SetConditionalAccept(TRUE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = sock_.Listen(MAX_BACK_LOG);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = PostRead();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t AsyncAcceptor::MakeNewConnection()
{
	bool_t ret = FALSE;

	AsyncSession *sess = 0;

	ret = MakeEventHandler(sess);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = ActivateEventHandler(sess);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = AcceptEventHandler(sess);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t AsyncAcceptor::GetPeerInfomation(char_t *buffer, uint32_t size, AsyncSession *sess)
{
	bool_t ret = FALSE;

	#ifdef OS_WINDOWS
	sockaddr_in *local_addr		= 0;
	sockaddr_in *remote_addr	= 0;
	int32_t local_addr_len		= 0;
	int32_t remote_addr_len		= 0;

	GetAcceptExSockaddrs(buffer,
						0,
						sizeof(sockaddr_in) + 16,
						sizeof(sockaddr_in) + 16,
						(sockaddr **)&local_addr,
						&local_addr_len,
						(sockaddr **)&remote_addr,
						&remote_addr_len);

	Socket *sock = (Socket *)sess->Handle();
	if(!sock) { ECILA_TRACE(); return FALSE; }

	IPAddrs *ipaddr = sock->GetIpAddrs();
	if(!ipaddr) { ECILA_TRACE(); return FALSE; }

	ret = ipaddr->Init(remote_addr);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	#endif


	return TRUE;
}







bool_t AsyncAcceptor::PostRead() 
{
	bool_t ret = FALSE;

//	for(uint32_t i=0; i<MAX_BACK_LOG; i++)
//	{
		ret = MakeNewConnection(); 
		if(!ret) { ECILA_TRACE(); return FALSE; }
//	}

	return TRUE;
}








bool_t AsyncAcceptor::OnRead(EventResult *evr)
{
	bool_t ret = FALSE;

	ret = MakeNewConnection();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	AsyncSession* sess = (AsyncSession*)evr->AcceptHandler();
	if(!sess) { ECILA_TRACE(); return FALSE; }


	Socket *sock = (Socket *)sess->Handle();
	if(!sock) { ECILA_TRACE(); return FALSE; }

	ret = sock->SetUpdateAcceptContext((Socket*)this->Handle());
	if(!ret) { ECILA_TRACE(); return FALSE; }


	ret = GetPeerInfomation(evr->Buffer(), evr->BufferSize(), sess);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = sess->RecvBuffer()->Reset();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = sess->PostOpen();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = sess->PostRead();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}







bool_t AsyncAcceptor::MakeEventHandler(AsyncSession *&sess)
{
	bool_t ret = FALSE;

	IDemultiplexer *demultiplexer = Demultiplexer();
	if(!demultiplexer) { ECILA_TRACE(); return FALSE; }

	AsyncSessionPool *sess_pool = SessionPool();
	if(!sess_pool) { ECILA_TRACE(); return FALSE; }

	AsyncResultPool *act_pool = ActPool();
	if(!act_pool) { ECILA_TRACE(); return FALSE; }

	sess = sess_pool->Acquire();
	if(!sess) { ECILA_TRACE(); return FALSE; }

	//cache demultiplexer
	ret = sess->Demultiplexer(demultiplexer);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	//cache async result pool
	ret = sess->ActPool(act_pool);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	//cache packet handler
	ret = sess->PKTHandler(pkt_handler_);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}









bool_t AsyncAcceptor::ActivateEventHandler(AsyncSession *sess)
{
	bool_t ret = FALSE;

	Socket* sock = (Socket*)sess->Handle();
	if(!sock) { ECILA_TRACE(); return FALSE; }

	ret = sock->Mode(Socket::SOCK_ASYNC_TCP);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = sock->Open();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;;
}








bool_t AsyncAcceptor::AcceptEventHandler(AsyncSession *sess)
{
	bool_t ret = FALSE;

	AsyncResultPool *act_pool = ActPool();
	if(!act_pool) { ECILA_TRACE(); return FALSE; }

	EventResult *evr = act_pool->Acquire();
	if(!evr) { ECILA_TRACE(); return FALSE; }

	RingBuffer *buffer = sess->RecvBuffer();
	if(!buffer) { ECILA_TRACE(); return FALSE; }

	evr->Event(EVENT_READ);
	evr->Handler(this);
	evr->AcceptHandler(sess);
	evr->Buffer((char_t*)buffer->GetInPtr(), buffer->Remain());

	ret = sock_.Accept((Socket *)sess->Handle(), evr->Buffer(), evr);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}

