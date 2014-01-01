#pragma once


#include "ecila.h"





NS_ECILA_START


class DECL_SPEC_DLL IService
{
public:

			 IService() {}
	virtual ~IService() {}

	virtual void Start() = 0;
};


NS_ECILA_END

