#pragma once

#ifdef	WIN32
#include	<WinSock2.h>
#include	<time.h>
#elif defined(LINUX)
#include <sys/time.h>
#endif

#include	"spthread.h"

/**
* @function		gettimeofday
* @param		tv that is the time in UTC format
* @brief		emulation of gettimeofday of POSIX
*/
extern int gettimeofday( struct timeval* tv );
extern int gettimeofday(struct timeval *tv, struct timezone *tz);