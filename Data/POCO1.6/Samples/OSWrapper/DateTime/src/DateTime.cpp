//
// DateTime.cpp
//
// $Id: //poco/1.4/Foundation/samples/DateTime/src/DateTime.cpp#1 $
//
// This sample demonstrates the DateTime class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//

#include "Wrapper/Config.h"
#include "Wrapper/Foundation/LocalDateTime.h"
#include "Wrapper/Foundation/DateTime.h"
#include "Wrapper/Foundation/DateTimeFormat.h"
#include "Wrapper/Foundation/DateTimeFormatter.h"
#include "Wrapper/Foundation/DateTimeParser.h"
#include <iostream>


using X1::LocalDateTime;
using X1::DateTime;
using X1::DateTimeFormat;
using X1::DateTimeFormatter;
using X1::DateTimeParser;


int main(int argc, char** argv)
{
	// [Error] followings cause signal 6 in vxworks RTP
	LocalDateTime now;
	
	std::string str = DateTimeFormatter::format(now, DateTimeFormat::ISO8601_FORMAT);
	
	std::cout << str << std::endl;
	
	DateTime dt;
	int tzd;
	DateTimeParser::parse(DateTimeFormat::ISO8601_FORMAT, str, dt, tzd);
	dt.makeUTC(tzd);
	LocalDateTime ldt(tzd, dt);
	return 0;
}
