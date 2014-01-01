#pragma once


#include "iasyncresult.h"








NS_ECILA_START

class DECL_SPEC_DLL AsyncResultImpl
 :	public IAsyncResult
{
public:

			 AsyncResultImpl();
	virtual ~AsyncResultImpl();

	virtual void Complete(EventResult *evr);
};

NS_ECILA_END

