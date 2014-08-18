#pragma once

#include "X1.h"

NS_X1_START

class DECL_SPEC_DLL MutexNull
{
public:
	MutexNull(void)		{}
	~MutexNull(void)	{}

	ret_t Acquire()		
	{
		return X1_OK;
	}


	ret_t Release()		
	{
		return X1_OK;
	}

	ret_t Lock()
	{
		return Acquire();
	}
	
	ret_t Unlock()
	{
		return Release();
	}

	friend class Cond;
};

NS_X1_END