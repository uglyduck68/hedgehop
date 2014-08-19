

#include	"gettimeofday.h"

int gettimeofday( struct timeval* tv ) 
{
    FILETIME time;
    double   timed;

	// get system time
	// In Windows XP, time resolution is 15ms
	// In Windows 7, time resolution is sub-ms.
	GetSystemTimeAsFileTime( &time );

    // Apparently Win32 has units of 1e-7 sec (tenths of microsecs)
    // 4294967296 is 2^32, to shift high word over
    // 11644473600 is the number of seconds between
    // the Win32 epoch 1601-Jan-01 and the Unix epoch 1970-Jan-01
    // Tests found floating point to be 10x faster than 64bit int math.

    timed = ((time.dwHighDateTime * 4294967296e-7) - 11644473600.0) +
            (time.dwLowDateTime  * 1e-7);

    tv->tv_sec  = (long) timed;
    tv->tv_usec = (long) ((timed - tv->tv_sec) * 1e6);

    return 0;
}

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
