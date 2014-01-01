#pragma once

#include "ecila.h"







NS_ECILA_START

class Session;

class DECL_SPEC_DLL IActSession
{
public:
			 IActSession() {}
	virtual ~IActSession() {}

	virtual Session* ACTSession(serial_t uidx) = 0;
};

NS_ECILA_END

