#pragma once


#include "ihttpmsgdispatcher.h"







class HttpMsgNotFound
:	public IHttpMsgDispatcher
{
public:

			 HttpMsgNotFound();
	virtual ~HttpMsgNotFound();


private:

	virtual bool_t	Dispatch(serial_t uidx, HttpMsgReq *req);
	virtual void	CacheNode();

};
