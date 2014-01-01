#include "syncacceptor.h"
#include "syncsessionpool.h"








US_ECILA

SyncAcceptor::SyncAcceptor(IDemultiplexer *demultiplexer, SyncSessionPool *sess_pool)
:	SyncSession(demultiplexer, sess_pool)
{
}






SyncAcceptor::~SyncAcceptor()
{
}






bool_t SyncAcceptor::Open(unsigned short port, const char *ip)
{
	bool_t ret = FALSE;

	ret = sock_.Open();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = sock_.Bind(port, ip);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = sock_.SetNonBlock(TRUE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = sock_.Listen(MAX_BACK_LOG);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = OnOpen(0);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}






bool_t SyncAcceptor::OnRead(EventResult *evr)
{
	bool_t ret = FALSE;

	SyncSession *sess = 0;

	ret = MakeEventHandler(sess);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = AcceptEventHandler(sess);
	if(!ret) { ECILA_TRACE(); goto _ERROR; }

	ret = ActivateEventHandler(sess);
	if(!ret) { ECILA_TRACE(); goto _ERROR; }

	return TRUE;

_ERROR:
	sess->OnClose(0);
	return FALSE;
}






bool_t SyncAcceptor::MakeEventHandler(SyncSession *&sess)
{
	bool_t ret = FALSE;

	IDemultiplexer *demultiplexer = Demultiplexer();
	if(!demultiplexer) { ECILA_TRACE(); return FALSE; }

	SyncSessionPool *sess_pool = SessionPool();
	if(!sess_pool) { ECILA_TRACE(); return FALSE; }

	sess = sess_pool->Acquire();
	if(!sess) { ECILA_TRACE(); return FALSE; }

	//cache demultiplexer
	ret = sess->Demultiplexer(demultiplexer);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	//cache packet handler
	ret = sess->PKTHandler(pkt_handler_);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}






bool_t SyncAcceptor::AcceptEventHandler(SyncSession *sess)
{
	bool_t ret = FALSE;

	ret = sock_.Accept((Socket *)sess->Handle());
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}






bool_t SyncAcceptor::ActivateEventHandler(SyncSession *sess)
{
	bool_t ret = FALSE;

	Socket *sock = (Socket *)sess->Handle();
	if(!sock) { ECILA_TRACE(); return FALSE; }

	ret = sock->SetNonBlock(TRUE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return sess->OnOpen(0);
}

