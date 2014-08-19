#pragma once

#ifdef	WIN32
#include	<WinSock2.h>
#include	<time.h>
#elif defined(LINUX)
#include <sys/time.h>
#endif

#include	"spthread.h"

extern int gettimeofday( struct timeval* tv );
extern int gettimeofday(struct timeval *tv, struct timezone *tz);