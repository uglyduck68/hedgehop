#pragma once

#include "ace/OS_NS_string.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_netdb.h"
#include "ace/OS_NS_sys_socket.h"
#include "ace/OS_NS_time.h"
#include "ace/Get_Opt.h"
#include "ace/Acceptor.h"
#include "ace/Thread_Manager.h"
#include "ace/TP_Reactor.h"
#include "ace/Svc_Handler.h"
#include "ace/SSL/SSL_SOCK_Connector.h"
#include "ace/SSL/SSL_SOCK_Acceptor.h"

#include <map>

using namespace	std;

class Request_Handler;

class Request_HandlerCmp
{
public:
	bool operator() (const Request_Handler* lhs, const Request_Handler* rhs) const
	{
		if( (int)lhs < (int)rhs)
			return true;

		return false;
	}
};

class Request_Handler : public ACE_Svc_Handler<ACE_SSL_SOCK_Stream,
	ACE_MT_SYNCH>
{
	friend class Request_HandlerCmp;

	// = TITLE
	//   This class is the Svc_Handler used by <Acceptor>.
public:
	/// The default constructor makes sure the right reactor is used.
	Request_Handler (ACE_Thread_Manager *tm = 0);

	int open (void * = 0);

protected:
	virtual int handle_input (ACE_HANDLE fd = ACE_INVALID_HANDLE);
	virtual int handle_close (ACE_HANDLE fd, ACE_Reactor_Mask = 0);

	int	AddConnectedList(Request_Handler* Handler);

private:
	size_t  nr_msgs_rcvd_;

	map<Request_Handler*, Request_Handler*, Request_HandlerCmp>	ConnectedList;
};

typedef	pair<Request_Handler*, Request_Handler*> RHPair;

