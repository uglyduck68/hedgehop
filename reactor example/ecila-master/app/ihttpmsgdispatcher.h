#pragma once


#include <ecila/ecila.h>
#include <ecila/node.h>
#include <ecila/bufferpool.h>
#include <ecila/msgqueue.h>

#include "http.h"
#include "httpmsgreq.h"
#include "httpmsgres.h"








class IHttpMsgDispatcher
{
public:

			 IHttpMsgDispatcher();
	virtual ~IHttpMsgDispatcher();


	bool_t Initialize	(NS_ECILA::Node *root);
	bool_t Finalize		();


	virtual bool_t	Dispatch (serial_t uidx, HttpMsgReq *req) = 0;
	virtual void	CacheNode()	= 0;


protected:

	NS_ECILA::Node       *root_;
	NS_ECILA::BufferPool *buff_pool_;
	NS_ECILA::MsgQueue   *network_q_;

	bool_t SendResponse(serial_t uidx, int32_t status, const char_t* context, uint32_t context_len);

};

