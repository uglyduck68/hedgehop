
#ifndef X1_LocalDateTime_INCLUDED
#define X1_LocalDateTime_INCLUDED



#include "DateTime.h"

#include "Poco/LocalDateTime.h"


namespace X1 {


class LocalDateTime : public Poco::LocalDateTime
{
public:
	LocalDateTime() : Poco::LocalDateTime()
	{}

	LocalDateTime(int year, int month, int day, int hour = 0, int minute = 0, int second = 0, int millisecond = 0, int microsecond = 0)
		: Poco::LocalDateTime(year, month, day, hour , minute , second, millisecond, microsecond)
	{}


	//@ deprecated
	LocalDateTime(int tzd, int year, int month, int day, int hour, int minute, int second, int millisecond, int microsecond)
		: Poco::LocalDateTime(tzd, year, month, day, hour, minute, second, millisecond, microsecond)
	{}

	LocalDateTime(const DateTime& dateTime) : Poco::LocalDateTime(dateTime)
	{}

	//@ deprecated
	LocalDateTime(int tzd, const DateTime& dateTime)
		: Poco::LocalDateTime(tzd, dateTime)
	{}

	//@ deprecated
	LocalDateTime(int tzd, const DateTime& dateTime, bool adjust)
		: Poco::LocalDateTime(tzd, dateTime, adjust)
	{}

	LocalDateTime(const Poco::DateTime& dateTime) : Poco::LocalDateTime(dateTime)
	{}

	LocalDateTime(double julianDay): Poco::LocalDateTime(julianDay)
	{}
	

	/// Copy constructor. Creates the LocalDateTime from another one.
	LocalDateTime(const LocalDateTime& dateTime) : Poco::LocalDateTime(dateTime)
	{}

	LocalDateTime(const Poco::LocalDateTime& dateTime) : Poco::LocalDateTime(dateTime)
	{}

		

	virtual ~LocalDateTime()
	{}
	
//	friend class DateTimeFormatter;
//	friend class DateTimeParser;
};


} // namespace X1


#endif // Foundation_LocalDateTime_INCLUDED
