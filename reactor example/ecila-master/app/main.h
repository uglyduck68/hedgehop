#pragma once

#include <ecila/server.h>





class PacketHandler;
class NetworkTask;
class DispatchTask;

class Main
{
public:


	 Main();
	~Main();

	void Run();

private:

	PacketHandler		*pkt_handler_;
	NetworkTask			*network_task_;
	DispatchTask		*dispatch_task_;
	NS_ECILA::Server	*svr_frame_;


	bool_t	InitDictionary();
};

