/* TimeValue - Encapsulates a time value */

/* Copyright (c) 1999 Wind River Systems, Inc. */

/*
modification history
--------------------
01c,10dec01,dbs  diab build
01b,19jan00,nel  Modifications for Linux debug build
01a,08Jul99,aim  created
*/

#ifndef _TimeValue_h_
#define _TimeValue_h_

#include "Config.h"
#include "Types.h"

#if	defined(_X1_WINDOWS_)
#include <WinSock.h>
#include <time.h>
#endif

#include <iostream>

#ifdef _X1_VXWORKS_
#include "sys/times.h"
#endif
#ifdef _X1_LINUX_
#include "sys/time.h"
#endif


using namespace std;

NS_X1_START

class DECL_SPEC_DLL TimeValue
{
public:

	virtual ~TimeValue ();

	TimeValue ();

	TimeValue (const struct timeval& tv);

	TimeValue (long sec, long usec = 0);

	TimeValue& operator += (const TimeValue &rhs);
	TimeValue& operator -= (const TimeValue &rhs);

	friend const TimeValue operator +
		(
		const TimeValue &lhs,
		const TimeValue &rhs
		);

	friend const TimeValue operator -
		(
		const TimeValue &lhs,
		const TimeValue &rhs
		);

	friend int operator >
		(
		const TimeValue &tv1,
		const TimeValue &tv2
		);

	friend int operator <
		(
		const TimeValue &tv1,
		const TimeValue &tv2
		);

	friend int operator <=
		(
		const TimeValue &tv1,
		const TimeValue &tv2
		);

	friend int operator >=
		(
		const TimeValue &tv1,
		const TimeValue &tv2
		);

	friend int operator ==
		(
		const TimeValue &tv1,
		const TimeValue &tv2
		);

	friend int operator !=
		(
		const TimeValue &tv1,
		const TimeValue &tv2
		);

	friend ostream& operator <<
		(
		ostream& os,
		const TimeValue&
		);

	long sec () const;
	long usec () const;

	void set (const timeval&);
	void set (int, int);

	operator timeval () const;
	operator const timeval* () const;
	operator timeval* ();

	static const TimeValue  now ();
	static const TimeValue& zero ();

	// return millisec from timeval
	long msec() const
	{
		return (m_tv.tv_sec * 1000 + m_tv.tv_usec / 1000);
	}
private:

	void normalize ();
	// Put the timevalue into a canonical form.

	struct timeval m_tv;
};

NS_X1_END

extern int gettimeofday(struct timeval *tv, struct timezone *tz);

#endif // _TimeValue_h_
