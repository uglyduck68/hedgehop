#pragma once


#include "ihttpmsgdispatcher.h"







class HttpMsgIndex
:	public IHttpMsgDispatcher
{
public:

			 HttpMsgIndex();
	virtual ~HttpMsgIndex();


private:

	virtual bool_t	Dispatch(serial_t uidx, HttpMsgReq *req);
	virtual void	CacheNode();

};
