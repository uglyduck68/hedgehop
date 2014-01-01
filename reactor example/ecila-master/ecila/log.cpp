#include "log.h"
#include "timer.h"
#include "file.h"








US_ECILA


///////////////////////////////////////////////////////////////////////////////
//
// Log
//
///////////////////////////////////////////////////////////////////////////////
Log::Log()
{
}







Log::~Log()
{
}








bool_t Log::Write(ENUM_MEDIA type, ENUM_LEVEL level, const char_t *fileprefix, const char_t *format, ...)
{
	bool_t ret = FALSE;

	int32_t msg_len = 0;
	char_t msg[MAX_MSG_LEN + 1] = {0, };
	DateTimeValue dtv;

	ret = Time::GetLocalDateTimeValue(dtv);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	//stamp datetime value
	msg_len += ecila_sprintf(&msg[msg_len], sizeof(msg) - msg_len, "[%04d-%02d-%02d %02d:%02d:%02d] ",
		dtv.year_, dtv.mon_, dtv.day_,
		dtv.hour_, dtv.min_, dtv.sec_);
	if(msg_len <= 0) { ECILA_TRACE(); return FALSE; }
	

	//assemble variable msg
	va_list vargs;
	va_start(vargs, format);
	msg_len += ecila_vsprintf(&msg[msg_len], sizeof(msg) - msg_len, format, vargs);
	if(msg_len <= 0) { ECILA_TRACE(); return FALSE; }
	va_end(vargs);


	//stamp new line
	msg_len += ecila_sprintf(&msg[msg_len], sizeof(msg) - msg_len, "\n");
	if(msg_len <= 0) { ECILA_TRACE(); return FALSE; }

	switch(type)
	{
	case MEDIA_CONSOLE	: return WriteConsole(dtv, level, msg);
	case MEDIA_FILE		: return WriteFile(dtv, level, fileprefix, msg);
	default				: { ECILA_TRACE(); return FALSE; }
	}
}








bool_t Log::WriteConsole(DateTimeValue &dtv, ENUM_LEVEL level, const char_t *msg)
{
	ECILA_PRINT((msg));

	return TRUE;
}








bool_t Log::WriteFile(DateTimeValue &dtv, ENUM_LEVEL level, const char_t *fileprefix, const char_t *msg)
{
	bool_t ret = FALSE;
	int32_t iret = 0;

	ret = WriteConsole(dtv, level, msg);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	if(!fileprefix) { ECILA_TRACE(); return FALSE; }

	char_t filename[MAX_FILE_NAME_LEN + 1] = {0, };
	iret = ecila_sprintf(filename, sizeof(filename), "%s.%04d%02d%02d", fileprefix, dtv.year_, dtv.mon_, dtv.day_);
	if(iret < 0) { ECILA_TRACE(); return FALSE; }

	File file;
	ret = file.Open(filename, "a+");
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = file.Write(msg);
	if(!ret) { ECILA_TRACE(); return FALSE; }
	
	return TRUE;
}

