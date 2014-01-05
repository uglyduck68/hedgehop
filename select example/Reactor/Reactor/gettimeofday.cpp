#include "Config.h"
#include "Types.h"

#if	defined(_X1_WINDOWS_)
#include <Windows.h>
#include <time.h>
#endif


#if	defined(_X1_VXWORKS_)

int gettimeofday (struct timeval *tv_ptr, void *ptr)
{
	struct timespec ts;

	if ((clock_gettime (CLOCK_REALTIME, &ts)) == ERROR)
	{
		printf ("Gettimeofday error\n");
		return (1);
	}

	tv_ptr -> tv_sec  = ts.tv_sec;
	tv_ptr -> tv_usec = ts.tv_nsec/1000;

	return (0);
}

#elif	defined(_X1_WINDOWS_)

// constant for epoch time
#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000Ui64
#else
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000ULL
#endif


// gettimeofday in windows
int gettimeofday(struct timeval *tv, struct timezone *tz)
{
	FILETIME ft;
	unsigned __int64 tmpres = 0;
	static int tzflag;

	if (NULL != tv)
	{
		// get system time
		// In Windows XP, time resolution is 15ms
		// In Windows 7, time resolution is sub-ms.
		GetSystemTimeAsFileTime(&ft);

		tmpres |= ft.dwHighDateTime;
		tmpres <<= 32;
		tmpres |= ft.dwLowDateTime;

		// change 100 nano sec. to 1 micro sec.
		tmpres /= 10;

		// change to UNIX epoch time
		tmpres -= DELTA_EPOCH_IN_MICROSECS;    

		// adjust to sec & micro sec.
		tv->tv_sec	= long(tmpres / 1000000UL);
		tv->tv_usec	= (tmpres % 1000000UL);
	}

	// handle timezone 
	if (NULL != tz)
	{
		if (!tzflag)
		{
			_tzset();
			tzflag++;
		}
		tz->tz_minuteswest	= _timezone / 60;
		tz->tz_dsttime		= _daylight;
	}

	return 0;
}

#endif

