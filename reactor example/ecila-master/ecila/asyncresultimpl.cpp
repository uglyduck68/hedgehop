#include "asyncresultimpl.h"
#include "ieventhandler.h"
#include "eventresult.h"








US_ECILA

AsyncResultImpl::AsyncResultImpl()
{
}








AsyncResultImpl::~AsyncResultImpl()
{
}








void AsyncResultImpl::Complete(EventResult *evr)
{
	evr->Handler()->Complete(evr);
}

