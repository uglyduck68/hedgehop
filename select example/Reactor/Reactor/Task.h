#pragma once


#include "X1.h"

NS_X1_START

class DECL_SPEC_DLL Task
{
public:

			 Task() {}
	virtual ~Task() {}

	virtual int Run() = 0;
};

NS_X1_END

