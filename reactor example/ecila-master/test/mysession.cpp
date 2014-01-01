#include "mysession.h"






US_ECILA


MySession::MySession()
{
}








MySession::~MySession()
{
}








bool_t MySession::OnRead(EventResult *evr)
{
	return TRUE;
}








bool_t MySession::OnWrite(EventResult *evr)
{
	return TRUE;
}








bool_t MySession::OnError(EventResult *evr)
{
	return TRUE;
}








bool_t MySession::Complete(EventResult *evr)
{
	return TRUE;
}

