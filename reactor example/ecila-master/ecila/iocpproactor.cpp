#include "iocpproactor.h"


#include "eventresult.h"
#include "ieventhandler.h"
#include "iasyncresult.h"





#ifdef USE_DEMULTIPLEXER_IOCP


US_ECILA

IocpProactor::IocpProactor()
{
	completion_port_	= 0;

	InitDemultiplexer();
}








IocpProactor::~IocpProactor()
{
	FiniDemultiplexer();
}








bool_t IocpProactor::HandleEvents(int32_t timeout_msec)
{
	ulong_t ret	= 0, nbytes = 0, key = 0;
	EventResult *evr = 0;

	ret = GetQueuedCompletionStatus(completion_port_, &nbytes, &key, (overlapped_t**)&evr, timeout_msec < 0 ? INFINITE : timeout_msec);
	if(!ret)
	{
		int32_t wsa_last_errno = WSAGetLastError();
		if(wsa_last_errno == WAIT_TIMEOUT) { return FALSE; }

		if(!evr) { ECILA_TRACE(); return FALSE; }
		evr->Status(ret); evr->Error(wsa_last_errno); 
	}
	else
	{
		if(!evr) { ECILA_TRACE(); return FALSE; }
		evr->Status(ret); evr->Transffered(nbytes);
	}

	IAsyncResult *act = evr->ActImpl();
	if(!act) { ECILA_TRACE(); return FALSE; }

	act->Complete(evr);
	return TRUE;

	/*
	ulong_t ret	= 0, nbytes = 0, key = 0;
	EventResult *evr = 0;

	ret = GetQueuedCompletionStatus(completion_port_, &nbytes, &key, (overlapped_t**)&evr, timeout_msec < 0 ? INFINITE : timeout_msec);
	if(!ret)
	{
		int32_t wsa_last_errno = WSAGetLastError();
		if(wsa_last_errno == WAIT_TIMEOUT) { return FALSE; }
		if(wsa_last_errno == ERROR_NETNAME_DELETED &&
			evr->Handler() != NULL &&
			evr->AcceptHandler() != NULL)
		{
			if(!evr) { ECILA_TRACE(); return FALSE; }
			evr->Status(TRUE); evr->Transffered(nbytes);
		}
		else
		{
			if(!evr) { ECILA_TRACE(); return FALSE; }
			evr->Status(ret); evr->Error(wsa_last_errno); 
		}
	}
	else
	{
		if(!evr) { ECILA_TRACE(); return FALSE; }
		evr->Status(ret); evr->Transffered(nbytes);
	}

	IAsyncResult *act = evr->ActImpl();
	if(!act) { ECILA_TRACE(); return FALSE; }

	act->Complete(evr);
	return TRUE;
	*/
}








bool_t IocpProactor::RegisterHandler(IEventHandler *h, EVENT_T e)
{
	bool_t ret = FALSE;

	handle_t completion_port = CreateIoCompletionPort((handle_t)(h->Descriptor()), completion_port_, 0, 0);
	if(!completion_port)
	{
		int32_t wsa_last_errno = WSAGetLastError();
		if(wsa_last_errno	!= ERROR_INVALID_PARAMETER &&
		   h->Registered()	!= FALSE)
		{
			ECILA_ERROR(("%d\n", wsa_last_errno)); ECILA_TRACE(); return FALSE;
		}
	}

	ret = h->Registered(TRUE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = h->InitialEventMask(e);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}







bool_t IocpProactor::UnRegisterHandler(IEventHandler *h)
{
	bool_t ret = FALSE;

	ret = h->Registered(FALSE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = h->InitialEventMask(EVENT_NONE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t IocpProactor::EnableEventMask(IEventHandler *h, EVENT_T e)
{
	if(!h->Registered()) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t IocpProactor::DisableEventMask(IEventHandler *h, EVENT_T e)
{
	if(!h->Registered()) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}








bool_t IocpProactor::InitDemultiplexer()
{
	if(completion_port_) { ECILA_TRACE(); return FALSE; }

	completion_port_ = CreateIoCompletionPort(INVALID_HANDLE_VALUE, 0, 0, 0);
	if(!completion_port_)
	{
		ECILA_TRACE(); return FALSE;
	}

	return TRUE;
}







bool_t IocpProactor::FiniDemultiplexer()
{
	bool_t ret = FALSE;

	ret = CloseHandle(completion_port_);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}


#endif

