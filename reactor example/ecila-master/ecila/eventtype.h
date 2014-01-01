#pragma once

#pragma once


#include "ecila.h"








NS_ECILA_START

typedef uint32_t EVENT_T;

enum EVENT_TYPE
{
	EVENT_NONE		= 0,
	EVENT_OPEN		= 1 << 0,
	EVENT_READ		= 1 << 1,
	EVENT_WRITE		= 1 << 2,
	EVENT_CLOSE		= 1 << 3,
	EVENT_ERROR		= 1 << 4,
	EVENT_TIMEOUT	= 1 << 5,
	EVENT_SIGNAL	= 1 << 6,
};

NS_ECILA_END

