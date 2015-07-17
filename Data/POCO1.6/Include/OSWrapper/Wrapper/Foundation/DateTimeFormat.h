#ifndef X1_DateTimeFormat_INCLUDED
#define X1_DateTimeFormat_INCLUDED


#include "Poco/DateTimeFormat.h"


namespace X1 {


class DateTimeFormat : public Poco::DateTimeFormat
{
public:
	DateTimeFormat(Poco::DateTimeFormat dateTime) : Poco::DateTimeFormat(dateTime)
	{}
};


} // namespace X1


#endif // Foundation_DateTimeFormat_INCLUDED
