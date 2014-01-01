#include "httpmsgindex.h"







HttpMsgIndex::HttpMsgIndex()
:	IHttpMsgDispatcher()
{
}








HttpMsgIndex::~HttpMsgIndex()
{
}








bool_t HttpMsgIndex::Dispatch(serial_t uidx, HttpMsgReq *req)
{
	bool_t ret = FALSE;

	ret = SendResponse(uidx, req->Status(), "Hello, World!!", 14);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








void HttpMsgIndex::CacheNode()
{
}
