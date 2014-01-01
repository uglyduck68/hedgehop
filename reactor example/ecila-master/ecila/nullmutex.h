#pragma once


#include "ecila.h"








NS_ECILA_START

class DECL_SPEC_DLL NullMutex
{
public:

	 NullMutex	()	{}
	~NullMutex	()	{}

	void Lock	()	{}
	void UnLock	()	{}
};

NS_ECILA_END

