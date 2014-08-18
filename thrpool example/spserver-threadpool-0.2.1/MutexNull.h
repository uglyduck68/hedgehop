#pragma once

#include "X1.h"
#include "CondVar.h"

NS_X1_START

class DECL_SPEC_DLL MutexNull
{
public:
	MutexNull(void)		{}
	~MutexNull(void)	{}

	int Lock()
	{
		return 0;
	}
	
	int UnLock()
	{
		return 0;
	}

	friend class CondVar;
};

NS_X1_END