/**
* @file		Timeval.h
* @auther	Younghwan Kim (uglyduck68@gmail.com)
* @version	0.1
* @date		20140816
* @brief	interface file for struct timeval
*/
#pragma once

#include	"X1.h"

#ifdef	WIN32
#include <time.h>
#elif defined(LINUX)
#include <sys/time.h>
#endif

#include	"gettimeofday.h"

const long JAN_1ST_1900 = 2415021;
const long JAN_1ST_1970	= 2440588;	// Julian date at Unix epoch: 1970-01-01 

NS_X1_START

	/**
	* @class	TimeVal
	*/
	class TimeVal
	{
	public:
		TimeVal(bool bNow = true);

		TimeVal(time_t mseconds);


		TimeVal(time_t seconds, suseconds_t useconds);

		TimeVal(const struct timeval& time);

		/**Allow copying (copy ctor)*/
		TimeVal(const TimeVal& tv);

		~TimeVal();

		/**Allow assignment (assignment operator)*/
		TimeVal& operator=(const TimeVal& rhs);

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
		static int Now(int& yy, int& mo, int& dd, int& hh, int& mm, int& ss, int& ms);

		static int ConvertTime(int yy, int mo, int dd, int hh, int mm, int ss, int ms, TimeVal& Timeval);
#ifdef	WIN32
		/**
		 * refer to http://support.microsoft.com/kb/q167296/ 
		 * and in case of time_t is 64 bit UnixTimeToFileTime works well.
		 */		
		static void UnixTimeToFileTime(time_t t, LPFILETIME pft);
		static void UnixTimeToSystemTime(time_t t, LPSYSTEMTIME pst);

#endif

		friend TimeVal operator+(const TimeVal& lhs, const TimeVal& rhs)
		{
			return TimeVal(lhs.m_timeval.tv_sec + rhs.m_timeval.tv_sec,
				lhs.m_timeval.tv_usec + rhs.m_timeval.tv_usec );
		}

		friend TimeVal operator-(const TimeVal& lhs, const TimeVal& rhs)
		{
			return TimeVal(lhs.m_timeval.tv_sec - rhs.m_timeval.tv_sec,
				lhs.m_timeval.tv_usec - rhs.m_timeval.tv_usec);
		}

		friend bool operator==(const TimeVal& lhs, const TimeVal& rhs)
		{
			return ((lhs.m_timeval.tv_sec == rhs.m_timeval.tv_sec ) &&
				(lhs.m_timeval.tv_usec == rhs.m_timeval.tv_usec ));
		}

		friend bool operator>(const TimeVal& lhs, const TimeVal& rhs)
		{
			return ((lhs.m_timeval.tv_sec > rhs.m_timeval.tv_sec) ||
				((lhs.m_timeval.tv_sec == rhs.m_timeval.tv_sec) && (lhs.m_timeval.tv_usec > rhs.m_timeval.tv_usec))) ;
		}

		friend bool operator<(const TimeVal& lhs, const TimeVal& rhs)
		{
			return ((lhs.m_timeval.tv_sec < rhs.m_timeval.tv_sec) ||
				((lhs.m_timeval.tv_sec == rhs.m_timeval.tv_sec) && (lhs.m_timeval.tv_usec < rhs.m_timeval.tv_usec))) ;
		}

		operator timeval () const;
		operator const timeval* () const;
		operator timeval* ();

	protected:
		static void GetGregorianData(long JD, int& year, int& month, int& day);
		static long GetJulianDay(int Year, int Month, int Day);

	private:
		// on WIN32 m_timeval.tv_sec & m_timeval.tv_usec is long type in WinSock2.h.
		// on POSIX m_timeval.tv_sec & m_timeval.tv_usec is time_t type But time_t is long.
		// tv_sec means seconds and tv_usec means *microseconds*
		struct timeval m_timeval;
	};

NS_X1_END


