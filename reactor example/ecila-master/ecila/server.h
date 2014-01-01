#pragma once

#include "iservice.h"

#include <string>








NS_ECILA_START

class Node;
class IniLoader;
class DANodeList;
class IPacketHandler;
class ITask;

class DECL_SPEC_DLL Server
:	public IService
{
public:

			 Server(const char_t *cfg);
	virtual ~Server();

	virtual void Start();

	bool_t Initialize	(IPacketHandler *pkt_handler, ITask *network_task, ITask *dispatch_task);
	bool_t Finalize		();

	DANodeList*	NodeList	();
	Node*		RootNode	();
	void		JoinAll		();


private:

	std::string		cfg_filename_;
	IniLoader		*ini_loader_;
	DANodeList		*node_list_;
	
	Node			*root_;
	Node			*pool_;
	Node			*msg_q_;
	Node			*events_;
	Node			*thread_;
	Node			*dictionary_;

	IPacketHandler	*pkt_handler_;
	ITask			*network_task_;
	ITask			*dispatch_task_;

	bool_t MakeNodeObject();
	bool_t MakePoolObject();
	bool_t MakeMsgqObject();
	bool_t MakeEventsObject();
	bool_t MakeDispatchThread();
	bool_t MakeNetworkThread();
};
	
NS_ECILA_END

