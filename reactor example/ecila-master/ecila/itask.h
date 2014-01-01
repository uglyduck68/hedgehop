#pragma once


#include "ecila.h"





NS_ECILA_START


class DECL_SPEC_DLL ITask
{
public:

			 ITask() {}
	virtual ~ITask() {}

	virtual bool_t Run() = 0;

};


NS_ECILA_END

