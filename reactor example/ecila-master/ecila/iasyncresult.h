#pragma once


#include "ecila.h"






NS_ECILA_START

class EventResult;

//Asynchronous Completion Token
class DECL_SPEC_DLL IAsyncResult
{
public:
			 IAsyncResult() {}
	virtual ~IAsyncResult() {}
	virtual void Complete(EventResult *evr) = 0;
};

NS_ECILA_END
