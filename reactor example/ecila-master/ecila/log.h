#pragma once

#include "ecila.h"








NS_ECILA_START

class DateTimeValue;

class DECL_SPEC_DLL Log
{
public:
	enum ENUM_MAX	{ MAX_MSG_LEN = 4096, MAX_FILE_NAME_LEN = 255, };
	enum ENUM_MEDIA { MEDIA_CONSOLE, MEDIA_FILE, };
	enum ENUM_LEVEL { LEV_DEBUG, LEV_TRACE, LEV_INFO, LEV_WARN, LEV_ERROR, };


	 Log();
	~Log();

	static bool_t Write(ENUM_MEDIA type, ENUM_LEVEL level, const char_t *fileprefix, const char_t *format, ...);

private:

	static bool_t WriteConsole	(DateTimeValue &dtv, ENUM_LEVEL level, const char_t *msg);
	static bool_t WriteFile		(DateTimeValue &dtv, ENUM_LEVEL level, const char_t *fileprefix, const char_t *msg);
};

NS_ECILA_END

