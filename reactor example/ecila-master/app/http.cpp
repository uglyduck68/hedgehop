#include "http.h"








US_ECILA



const char_t* HTTP::Status(int32_t status)
{
	switch(status)
	{
	case HTTP::STATUS_OK                    : return "200 OK";
	case HTTP::STATUS_BAD_REQUEST           : return "400 Bad Request";
	case HTTP::STATUS_NOT_FOUND             : return "404 Not Found";
	case HTTP::STATUS_INTERNAL_SERVER_ERROR : return "500 Internal Server Error";
	default                                 : return "0 UNKNOWN";
	}
}








int32_t HTTP::AssembleGMTDateTime(DateTimeValue &dtv, char_t *buffer, uint32_t size)
{
	int32_t len = 0;

	const char_t *t_wday[] = { "Sun", "Mon", "Tue", "Wed", "Fri", "Sat", "Sun" };
	const char_t *t_mon[]  = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	len = ecila_sprintf(buffer, size, "%s, %02d %s %d %02d:%02d:%02d GMT",
						t_wday[dtv.wday_],
						dtv.mday_,
						t_mon[dtv.mon_ - 1],
						dtv.year_,
						dtv.hour_,
						dtv.min_,
						dtv.sec_);
	return len;
}

