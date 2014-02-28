#pragma once

#include "varargs.h"

class Error
{
public:
	Error(void);
	~Error(void);

	static char	m_caErrMsg[1024];

	//static void Set(char* pcErrMsg)
	//{
	//	strncpy(m_caErrMsg, pcErrMsg, 1024);
	//}

	static void Set(char* pcFormat, ...)
	{
		va_list		args;

		va_start(args, pcFormat);

		_vsprintf_p(m_caErrMsg, 1024, pcFormat, args);

		va_end(args);
	}

	static const char* Get()
	{
		return m_caErrMsg;
	}
};

