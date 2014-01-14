#pragma once

#include "TRACE.h"

#ifdef _X1_WINDOWS_
#include <Windows.h>
#include <tchar.h>

#define LOG_INTERNAL(format,...)	{fprintf(stderr, format, ##__VA_ARGS__);\
	TCHAR	__debugStr[1000];\
		_stprintf(__debugStr, _T(format), ##__VA_ARGS__);\
		OutputDebugString(__debugStr);}
#elif defined(_X1_VXWORKS_)
#define LOG_INTERNAL(format,...)	{fprintf(stderr, format, ##__VA_ARGS__);}
#endif


#define TRACE_IMP(X)	Trace(X, __LINE__, __FILE__)
#define TRACE(X)		TRACE_IMP(X)
