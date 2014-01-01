#include "acceptor.h"

#include "iniloader.h"
#include "demultiplexer.h"
#include "syncacceptor.h"
#include "asyncacceptor.h"
#include "syncsessionpool.h"
#include "asyncsessionpool.h"
#include "asyncresultpool.h"
#include "ipackethandler.h"







US_ECILA

Acceptor::Acceptor()
{
	acceptor_		= 0;
	pkt_handler_	= 0;
}








Acceptor::~Acceptor()
{
	ECILA_SAFE_DELETE(acceptor_);
}





void Acceptor::Initialize(Node *root, IPacketHandler *pkt_handler)
{
	ECILA_ASSERT(pkt_handler);
	pkt_handler_ = pkt_handler;

	//ini_loader
	IniLoader *ini_loader = root->FindObject<IniLoader>("/iniloader");
	ECILA_ASSERT(ini_loader);
	const char_t *netio = ini_loader->Property("server", "netio");
	ECILA_ASSERT(netio);


	//demultiplexer
	Demultiplexer *demultiplexer = root->FindObject<Demultiplexer>("/events/demultiplexer");
	ECILA_ASSERT(demultiplexer);


	//act_pool
	AsyncResultPool *act_pool = root->FindObject<AsyncResultPool>("/pool/act_pool");
	ECILA_ASSERT(act_pool);


	//sess_pool
	if(ecila_strncmp(netio, "async", 5) == 0)
	{
		AsyncSessionPool *sess_pool = root->FindObject<AsyncSessionPool>("/pool/sess_pool");
		ECILA_ASSERT(sess_pool);

		AsyncAcceptor *acceptor = new AsyncAcceptor(demultiplexer->DemultiplexerImpl(), sess_pool);
		ECILA_ASSERT(acceptor);

		acceptor->ActPool(act_pool);
		acceptor->PKTHandler(pkt_handler_);
		acceptor_ = acceptor;
	}
	else if(ecila_strncmp(netio, "sync", 4) == 0)
	{
		SyncSessionPool *sess_pool = root->FindObject<SyncSessionPool>("/pool/sess_pool");
		ECILA_ASSERT(sess_pool);

		SyncAcceptor *acceptor = new SyncAcceptor(demultiplexer->DemultiplexerImpl(), sess_pool);
		ECILA_ASSERT(acceptor);

		acceptor->PKTHandler(pkt_handler_);
		acceptor_ = acceptor;
	}
	else
	{
		ECILA_TRACE();
	}
}








IAcceptor* Acceptor::AcceptorImpl()
{
	return acceptor_;
}

