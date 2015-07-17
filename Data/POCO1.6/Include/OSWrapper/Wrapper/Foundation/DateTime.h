//
// DateTime.h
//
// $Id: //poco/1.4/Foundation/include/Poco/DateTime.h#1 $
//
// Library: Foundation
// Package: DateTime
// Module:  DateTime
//
// Definition of the DateTime class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef X1_DateTime_INCLUDED
#define X1_DateTime_INCLUDED


#include "Poco/DateTime.h"
#include "Timestamp.h"
#include "Timespan.h"


namespace X1 {

class DateTime : public Poco::DateTime
{
public:
	enum Months
		/// Symbolic names for month numbers (1 to 12).
	{
		JANUARY = 1,
		FEBRUARY,
		MARCH,
		APRIL,
		MAY,
		JUNE,
		JULY,
		AUGUST,
		SEPTEMBER,
		OCTOBER,
		NOVEMBER,
		DECEMBER
	};
	
	enum DaysOfWeek
		/// Symbolic names for week day numbers (0 to 6).
	{
		SUNDAY = 0,
		MONDAY,
		TUESDAY,
		WEDNESDAY,
		THURSDAY,
		FRIDAY,
		SATURDAY
	};
		
	DateTime()
	{}

	DateTime(const Timestamp& timestamp) : Poco::DateTime(timestamp)
	{}
	DateTime(const Poco::Timestamp& timestamp) : Poco::DateTime(timestamp)
	{}

	/// Creates a DateTime for the date and time given in
	/// a Timestamp.
	
		
	DateTime(int year, int month, int day, int hour = 0, int minute = 0, int second = 0, int millisecond = 0, int microsecond = 0)
		: Poco::DateTime(year, month, day, hour , minute, second, millisecond, microsecond)
	{}
		/// Creates a DateTime for the given Gregorian date and time.
		///   * year is from 0 to 9999.
		///   * month is from 1 to 12.
		///   * day is from 1 to 31.
		///   * hour is from 0 to 23.
		///   * minute is from 0 to 59.
		///   * second is from 0 to 59.
		///   * millisecond is from 0 to 999.
		///   * microsecond is from 0 to 999.

	DateTime(double julianDay) : Poco::DateTime(julianDay)
	{}
		/// Creates a DateTime for the given Julian day.

	DateTime(Timestamp::UtcTimeVal utcTime, Timestamp::TimeDiff diff)
		: Poco::DateTime(utcTime, diff)
	{}

	DateTime(const DateTime& dateTime) : Poco::DateTime(dateTime)
	{}

	DateTime(const Poco::DateTime& dateTime) : Poco::DateTime(dateTime)
	{}

	/// Copy constructor. Creates the DateTime from another one.

	~DateTime()
	{}
};


} // namespace X1


#endif // Foundation_DateTime_INCLUDED
