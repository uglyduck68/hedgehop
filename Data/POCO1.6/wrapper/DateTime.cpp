#include "./Foundation/LocalDateTime.h"
#include "./Foundation/DateTime.h"
#include "./Foundation/DateTimeFormat.h"
#include "./Foundation/DateTimeFormatter.h"
#include "./Foundation/DateTimeParser.h"

#include <iostream>


using X1::LocalDateTime;
using X1::DateTime;
using X1::DateTimeFormat;
using X1::DateTimeFormatter;
using X1::DateTimeParser;


int main(int argc, char** argv)
{
	LocalDateTime now;
	
	std::string str = DateTimeFormatter::format(now, DateTimeFormat::ISO8601_FORMAT);
	DateTime dt;
	int tzd;
	DateTimeParser::parse(DateTimeFormat::ISO8601_FORMAT, str, dt, tzd);
	dt.makeUTC(tzd);
	LocalDateTime ldt(tzd, dt);
	return 0;
}
