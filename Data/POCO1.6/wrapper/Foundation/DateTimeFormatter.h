#ifndef X1_DateTimeFormatter_INCLUDED
#define X1_DateTimeFormatter_INCLUDED


#include "../../Foundation/include/Poco/DateTimeFormatter.h"
//#include "./LocalDateTime.h"


namespace X1 {

class DateTimeFormatter : public Poco::DateTimeFormatter
{
public:
	DateTimeFormatter(const Poco::DateTimeFormatter& date) : Poco::DateTimeFormatter(date)
	{}

};

} // namespace X1


#endif // Foundation_DateTimeFormatter_INCLUDED
