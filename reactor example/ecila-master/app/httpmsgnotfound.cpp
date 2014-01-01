#include "httpmsgnotfound.h"








HttpMsgNotFound::HttpMsgNotFound()
:	IHttpMsgDispatcher()
{
}








HttpMsgNotFound::~HttpMsgNotFound()
{
}








bool_t HttpMsgNotFound::Dispatch(serial_t uidx, HttpMsgReq *req)
{
	bool_t ret = FALSE;

	ret = SendResponse(uidx, HTTP::STATUS_NOT_FOUND, "404 Not Found", 13);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








void HttpMsgNotFound::CacheNode()
{
}
