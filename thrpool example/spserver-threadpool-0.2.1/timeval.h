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

NS_X1_START

	/**
	* @class	TimeVal
	*/
	class TimeVal
	{
	public:
		TimeVal(bool bNow = true)
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

		TimeVal(time_t mseconds)
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


		TimeVal(time_t seconds, suseconds_t useconds)
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

		TimeVal(const struct timeval& time)
		{
			m_timeval.tv_sec = time.tv_sec ;
			m_timeval.tv_usec = time.tv_usec ;
		}

		/**Allow copying (copy ctor)*/
		TimeVal(const TimeVal& tv)
		{
			m_timeval.tv_sec = tv.m_timeval.tv_sec;
			m_timeval.tv_usec = tv.m_timeval.tv_usec;
		}

		~TimeVal() {}

		/**Allow assignment (assignment operator)*/
		TimeVal& operator=(const TimeVal& rhs)
		{
			m_timeval.tv_sec = rhs.m_timeval.tv_sec;
			m_timeval.tv_usec = rhs.m_timeval.tv_usec;
			return *this;
		}


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

	private:
		struct timeval m_timeval;
	};

NS_X1_END


