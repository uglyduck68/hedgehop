#include "osapi.h"







void ecila_msleep(uint32_t msec)
{
	#ifdef OS_WINDOWS
	Sleep(msec);
	#else
	usleep(msec * 1000);
	#endif
}

