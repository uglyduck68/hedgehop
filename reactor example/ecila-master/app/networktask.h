#pragma once


#include <ecila/itask.h>
#include <ecila/iactsession.h>
#include <ecila/idemultiplexer.h>
#include <ecila/msgqueue.h>
#include <ecila/bufferpool.h>








class NetworkTask
:	public NS_ECILA::ITask
{
public:

			 NetworkTask();
	virtual ~NetworkTask();

	virtual bool_t Run();


private:

	NS_ECILA::IDemultiplexer	*demultiplexer_;
	NS_ECILA::MsgQueue			*network_q_;
	NS_ECILA::BufferPool		*buff_pool_;
	NS_ECILA::IActSession		*act_sess_pool_;

	void CacheNode(NS_ECILA::Node *root);

	bool_t DispatchMsg();

};

