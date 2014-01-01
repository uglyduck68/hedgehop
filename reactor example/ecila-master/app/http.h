#pragma once

#include <ecila/timer.h>








class HTTP
{
public:
	enum CODE
	{
		STATUS_UNKNOWN               = 0,
		STATUS_OK                    = 200,
		STATUS_BAD_REQUEST           = 400,
		STATUS_NOT_FOUND             = 404,
		STATUS_INTERNAL_SERVER_ERROR = 500,
	};


	static const char_t* Status(int32_t status);
	static int32_t       AssembleGMTDateTime(NS_ECILA::DateTimeValue &dtv, char_t *buffer, uint32_t size);

};
