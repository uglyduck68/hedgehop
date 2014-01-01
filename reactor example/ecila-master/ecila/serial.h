#pragma once


#include "ecila.h"








NS_ECILA_START

class DECL_SPEC_DLL Serial
{
private:
	serial_t	serial_;


public:
	 Serial() : serial_(0) {}
	~Serial() {}

	serial_t Issue()
	{
		return ++serial_;
	}

};

NS_ECILA_END

