#include "timeval.h"

#include <stdio.h>

NS_X1_USE

TimeVal::TimeVal(bool bNow /*= true*/)
{
	if(bNow)
	{
		gettimeofday (&m_timeval);
	}
	else
	{
		m_timeval.tv_sec = 0;
		m_timeval.tv_usec = 0;
	}
}

/**
* @function		TimeVal
* @param		mseconds means milliseconds
*/
TimeVal::TimeVal(time_t mseconds)
{
	if(mseconds < 0 )
	{
		m_timeval.tv_sec = 0;
		m_timeval.tv_usec = 0;
	}
	else
	{
		m_timeval.tv_sec = (mseconds / 1000 );
		m_timeval.tv_usec = ((mseconds % 1000) * 1000 );
	}
}

/**
* @function		TimeVal
* @param		seconds means seconds
*				useconds means microseconds
*/
TimeVal::TimeVal(time_t seconds, suseconds_t useconds)
{
	// If the microseconds value is negative, then "borrow" from the seconds value.
	while(useconds < 0 )
	{
		useconds += 1000000 ;
		seconds-- ;
	}

	// "Normalize" the time so that the microseconds field is less than a million.
	while(useconds >= 1000000 )
	{
		seconds++ ;
		useconds -= 1000000 ;
	}

	if(seconds < 0 )
	{
		m_timeval.tv_sec = 0;
		m_timeval.tv_usec = 0;
	}
	else
	{
		m_timeval.tv_sec = seconds;
		m_timeval.tv_usec = useconds;
	}
}

TimeVal::TimeVal(const struct timeval& time)
{
	m_timeval.tv_sec = time.tv_sec ;
	m_timeval.tv_usec = time.tv_usec ;
}

/**Allow copying (copy ctor)*/
TimeVal::TimeVal(const TimeVal& tv)
{
	m_timeval.tv_sec = tv.m_timeval.tv_sec;
	m_timeval.tv_usec = tv.m_timeval.tv_usec;
}

TimeVal::~TimeVal() {}

/**Allow assignment (assignment operator)*/
TimeVal& TimeVal::operator=(const TimeVal& rhs)
{
	m_timeval.tv_sec = rhs.m_timeval.tv_sec;
	m_timeval.tv_usec = rhs.m_timeval.tv_usec;
	return *this;
}

/**
* @function		Now
* @param		yy means year
*				mo means month
*				dd means day
*				hh means hour in UTC format
*				mm means minute
*				ss means second
*				ms means microsecond
* 
* @return		0 if success
*				!= 0 if fail
*/
int TimeVal::Now(int& yy, int& mo, int& dd, int& hh, int& mm, int& ss, int& ms)
{
#ifdef	WIN3232
	SYSTEMTIME		st;

	GetLocalTime(&st);	/// or use GetSystemTime

	yy	= st.wYear;
	mo	= st.wMonth;
	dd	= st.wDay;
	hh	= st.wHour;
	mm	= st.wMinute;
	ss	= st.wSecond;
	ms	= st.wMilliseconds;
#else
	/**
	* following logic is tested in WIN32
	*/
	struct timeval now;
	long	Seconds	= 0;

	gettimeofday(&now, NULL);

	Seconds	= now.tv_sec + (9 * 3600);	// UTC + 9 hours is korean time

	ms	= now.tv_usec;	// micro second
	ss	= Seconds % 60;
	Seconds	/= 60;
	mm	= Seconds % 60;
	Seconds	/= 60;
	hh	= Seconds % 24;
	Seconds	/= 24;

	long	JD	= Seconds + JAN_1ST_1970;

	GetGregorianData(JD, yy, mo, dd);

#if	0
	/////
	// following is for test to ConvertTime function.
	// test result of ConvertTime is good.
	/////
	printf("%04d/%02d/%02d %02d:%02d:%02d.%04d\n", yy, mo, dd, hh, mm, ss, ms);

	TimeVal		tt;

	ConvertTime(yy, mo, dd, hh, mm, ss, ms, tt);

	Seconds	= tt.m_timeval.tv_sec;	// UTC + 9 hours is korean time

	ms	= tt.m_timeval.tv_usec;	// micro second
	ss	= Seconds % 60;
	Seconds	/= 60;
	mm	= Seconds % 60;
	Seconds	/= 60;
	hh	= Seconds % 24;
	Seconds	/= 24;

	JD	= Seconds + JAN_1ST_1970;

	GetGregorianData(JD, yy, mo, dd);
	printf("%04d/%02d/%02d %02d:%02d:%02d.%04d\n", yy, mo, dd, hh, mm, ss, ms);
#endif

#endif

	return 0;
}

int TimeVal::ConvertTime(int yy, int mo, int dd, int hh, int mm, int ss, int ms, TimeVal& Timeval)
{
	//Currently this function only operates correctly in 
	//the 1900 - 2036 primary epoch defined by NTP

	long JD = GetJulianDay(yy, mo, dd);
	JD -= JAN_1ST_1970;

	//ASSERT(JD >= 0); //NTP only supports dates greater than 1900
	long Seconds = JD;
	Seconds = (Seconds * 24) + hh;
	Seconds = (Seconds * 60) + mm;
	Seconds = (Seconds * 60) + ss;
	//ASSERT(Seconds <= 0xFFFFFFFF); //NTP Only supports up to 2036

	Timeval.m_timeval.tv_sec	= Seconds;
	Timeval.m_timeval.tv_usec	= ms;

	return 0;
}

void TimeVal::GetGregorianData(long JD, int& Year, int& Month, int& Day)
{
	long j = JD - 1721119;
	long y = (4 * j - 1) / 146097;
	j = 4 * j - 1 - 146097 * y;
	long d = j / 4;
	j = (4 * d + 3) / 1461;
	d = 4 * d + 3 - 1461 * j;
	d = (d + 4) / 4;
	long m = (5 * d - 3) / 153;
	d = 5 * d - 3 - 153 * m;
	d = (d + 5) / 5;
	y = 100 * y + j;
	if (m < 10) 
		m = m + 3;
	else 
	{
		m = m - 9;
		y = y + 1;
	}

	Year = (int) y;
	Month = (int) m;
	Day = (int) d;
}

long TimeVal::GetJulianDay(int Year, int Month, int Day)
{
	long y = (long) Year;
	long m = (long) Month;
	long d = (long) Day;
	if (m > 2) 
		m = m - 3;
	else 
	{
		m = m + 9;
		y = y - 1;
	}
	long c = y / 100;
	long ya = y - 100 * c;
	long j = (146097L * c) / 4 + (1461L * ya) / 4 + (153L * m + 2) / 5 + d + 1721119L;
	return j;
}

#ifdef	WIN32
void TimeVal::UnixTimeToFileTime(time_t t, LPFILETIME pft) 
{ 
	// Note that LONGLONG is a 64-bit value 
	LONGLONG ll; 

	ll = Int32x32To64(t, 10000000) + 116444736000000000; 
	pft->dwLowDateTime = (DWORD)ll; 
	pft->dwHighDateTime = ll >> 32; 
} 

void TimeVal::UnixTimeToSystemTime(time_t t, LPSYSTEMTIME pst) 
{ 
	FILETIME ft; 

	UnixTimeToFileTime(t, &ft); 
	FileTimeToSystemTime(&ft, pst); 
} 

#endif
