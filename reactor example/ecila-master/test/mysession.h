#pragma once

#include <ecila/syncsession.h>
#include <ecila/eventresult.h>





class MySession
:	public NS_ECILA::SyncSession
{
public:
			 MySession();
	virtual ~MySession();

	virtual bool_t	OnRead	(NS_ECILA::EventResult *evr);
	virtual bool_t	OnWrite	(NS_ECILA::EventResult *evr);
	virtual bool_t	OnError	(NS_ECILA::EventResult *evr);
	virtual bool_t	Complete(NS_ECILA::EventResult *evr);


private:

};
