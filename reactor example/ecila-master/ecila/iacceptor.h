#pragma once


#include "ecila.h"









NS_ECILA_START

class DECL_SPEC_DLL IAcceptor
{
public:
			 IAcceptor() {}
	virtual ~IAcceptor() {}

	virtual bool_t Open(uint16_t port, const char_t *ip = 0) = 0;
};

NS_ECILA_END

