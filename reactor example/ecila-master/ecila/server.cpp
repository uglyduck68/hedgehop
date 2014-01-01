#include "server.h"


//node
#include "node.h"
#include "danodelist.h"

//config
#include "iniloader.h"

//pool objext
#include "syncsessionpool.h"
#include "asyncsessionpool.h"
#include "asyncresultpool.h"
#include "bufferpool.h"

//msg_q object
#include "msgqueue.h"

//events object
#include "idemultiplexer.h"
#include "iacceptor.h"
#include "ipackethandler.h"
#include "demultiplexer.h"
#include "acceptor.h"

//thread object
#include "thread.h"







US_ECILA

Server::Server(const char_t *cfg)
{
	ECILA_ASSERT(cfg);
	cfg_filename_	= cfg;
	node_list_		= 0;
	ini_loader_		= 0;


	root_			= 0;
	pool_			= 0;
	msg_q_			= 0;
	events_			= 0;
	thread_			= 0;
	dictionary_		= 0;


	pkt_handler_	= 0;
	network_task_	= 0;
	dispatch_task_	= 0;
}








Server::~Server()
{
	Finalize();
}









void Server::Start()
{
	Thread *dispatch_thread = thread_->FindChild<Thread>("dispatch_thread");
	ECILA_ASSERT(dispatch_thread);
	dispatch_thread->Start(dispatch_task_, root_);

	Thread *network_thread = thread_->FindChild<Thread>("network_thread");
	ECILA_ASSERT(network_thread);
	network_thread->Start(network_task_, root_);
}








DANodeList* Server::NodeList()
{
	return node_list_;
}








Node* Server::RootNode()
{
	return root_;
}








void Server::JoinAll()
{
	for(Node::ITER_T iter = thread_->BeginIter();
		iter != thread_->EndIter();
		++iter)
	{
		Thread *t = (Thread*)iter->second;
		if(!t) continue;

		t->Join();
	}
}








bool_t Server::Initialize(IPacketHandler *pkt_handler, ITask *network_task, ITask *dispatch_task)
{
	bool_t ret = FALSE;

	pkt_handler_	= pkt_handler;
	network_task_	= network_task;
	dispatch_task_	= dispatch_task;

	ret = Socket::InitWinSock();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = MakeNodeObject();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = MakePoolObject();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = MakeMsgqObject();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = MakeEventsObject();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = MakeDispatchThread();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = MakeNetworkThread();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t Server::Finalize()
{
	//destroy node object
	ECILA_SAFE_DELETE(node_list_);

	bool_t ret = FALSE;

	ret = Socket::FiniWinSock();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t Server::MakeNodeObject()
{
	bool_t ret = FALSE;

	node_list_ = new DANodeList();
	ECILA_ASSERT(node_list_);

	root_ = new Node();
	node_list_->AddNode(root_);
	root_->Name("root");


	ini_loader_ = new IniLoader();
	node_list_->AddNode(ini_loader_);
	ret = ini_loader_->Load(cfg_filename_.c_str());
	if(!ret) { ECILA_TRACE(); return FALSE; }
	ini_loader_->Name("iniloader");
	ret = root_->Attach(ini_loader_);
	if(!ret) { ECILA_TRACE(); return FALSE; }


	pool_ = new Node();
	node_list_->AddNode(pool_);
	pool_->Name("pool");
	ret = root_->Attach(pool_);
	if(!ret) { ECILA_TRACE(); return FALSE; }


	msg_q_ = new Node();
	node_list_->AddNode(msg_q_);
	msg_q_->Name("msg_q");
	ret = root_->Attach(msg_q_);
	if(!ret) { ECILA_TRACE(); return FALSE; }


	events_ = new Node();
	node_list_->AddNode(events_);
	events_->Name("events");
	ret = root_->Attach(events_);
	if(!ret) { ECILA_TRACE(); return FALSE; }


	thread_ = new Node();
	node_list_->AddNode(thread_);
	thread_->Name("thread");
	ret = root_->Attach(thread_);
	if(!ret) { ECILA_TRACE(); return FALSE; }


	dictionary_ = new Node();
	node_list_->AddNode(dictionary_);
	dictionary_->Name("dictionary");
	ret = root_->Attach(dictionary_);
	if(!ret) { ECILA_TRACE(); return FALSE; }


	return TRUE;
}








bool_t Server::MakePoolObject()
{
	bool_t ret = FALSE;

	//ini_loader
	const char_t *netio = ini_loader_->Property("server", "netio");
	ECILA_ASSERT(netio);

	if(ecila_strncmp(netio, "async", 5) == 0)
	{
		AsyncSessionPool *sess_pool = new AsyncSessionPool();
		node_list_->AddNode(sess_pool);
		ret = sess_pool->Initialize();
		if(!ret) { ECILA_TRACE(); return FALSE; }
		sess_pool->Name("sess_pool");
		pool_->Attach(sess_pool);
	}
	else if(ecila_strncmp(netio, "sync", 4) == 0)
	{
		SyncSessionPool *sess_pool = new SyncSessionPool();
		node_list_->AddNode(sess_pool);
		ret = sess_pool->Initialize();
		if(!ret) { ECILA_TRACE(); return FALSE; }
		sess_pool->Name("sess_pool");
		pool_->Attach(sess_pool);
	}
	else
	{
		ECILA_TRACE(); return FALSE;
	}


	AsyncResultPool *act_pool = new AsyncResultPool();
	node_list_->AddNode(act_pool);
	ret = act_pool->Initialize();
	if(!ret) { ECILA_TRACE(); return FALSE; }
	act_pool->Name("act_pool");
	pool_->Attach(act_pool);


	BufferPool *buff_pool = new BufferPool();
	node_list_->AddNode(buff_pool);
	ret = buff_pool->Initialize();
	if(!ret) { ECILA_TRACE(); return FALSE; }
	buff_pool->Name("buff_pool");
	pool_->Attach(buff_pool);

	return TRUE;
}








bool_t Server::MakeMsgqObject()
{
	bool_t ret = FALSE;

	MsgQueue *dispatch_q = new MsgQueue();
	node_list_->AddNode(dispatch_q);
	dispatch_q->Name("dispatch_q");
	ret = msg_q_->Attach(dispatch_q);
	if(!ret) { ECILA_TRACE(); return FALSE; }


	MsgQueue *networ_q = new MsgQueue();
	node_list_->AddNode(networ_q);
	networ_q->Name("network_q");
	ret = msg_q_->Attach(networ_q);
	if(!ret) { ECILA_TRACE(); return FALSE; }
	
	return TRUE;
}








bool_t Server::MakeEventsObject()
{
	bool_t ret = FALSE;

	//ini_loader
	const char_t *netio = ini_loader_->Property("server", "netio");
	ECILA_ASSERT(netio);

	const char_t *listen_ip   = ini_loader_->Property("server", "listen_ip");
	ECILA_ASSERT(listen_ip);

	const char_t *listen_port = ini_loader_->Property("server", "listen_port");
	ECILA_ASSERT(listen_port);


	//pkt_handler
	ECILA_ASSERT(pkt_handler_);
	ret = pkt_handler_->Initialize(root_);
	if(!ret) { ECILA_TRACE(); return FALSE; }


	//init demultiplexer
	Demultiplexer *demultiplexer = new Demultiplexer();
	node_list_->AddNode(demultiplexer);
	demultiplexer->Initialize(netio);
	demultiplexer->Name("demultiplexer");
	ret = events_->Attach(demultiplexer);
	if(!ret) { ECILA_TRACE(); return FALSE; }


	//init acceptor
	Acceptor *acceptor = new Acceptor();
	node_list_->AddNode(acceptor);
	acceptor->Initialize(root_, pkt_handler_);
	acceptor->Name("acceptor");
	ret = events_->Attach(acceptor);
	if(!ret) { ECILA_TRACE(); return FALSE; }
	ret = acceptor->AcceptorImpl()->Open((uint16_t)ecila_atoui32(listen_port), listen_ip);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t Server::MakeDispatchThread()
{
	bool_t ret = FALSE;

	Thread *dispatch_thread = new Thread();
	node_list_->AddNode(dispatch_thread);
	dispatch_thread->Name("dispatch_thread");
	ret = thread_->Attach(dispatch_thread);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t Server::MakeNetworkThread()
{
	bool_t ret = FALSE;

	Thread *network_thread = new Thread();
	node_list_->AddNode(network_thread);
	network_thread->Name("network_thread");
	ret = thread_->Attach(network_thread);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}

