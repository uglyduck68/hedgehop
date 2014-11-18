/** @file Verbose.h
 ** @date 2014-11-10
 ** @author ¹ÚÇö(hyunpark@endcs.net)
 **/

#pragma once

#ifdef _DEBUG
#include <assert.h>
#include <tchar.h>
#include <stdio.h>
#include <wtypes.h>
inline void TRACE_(LPCTSTR lpszFormat, ...)
{
	TCHAR lpszBuffer[0x160];
	va_list fmtList;
	va_start(fmtList, lpszFormat);
	vsprintf_s(lpszBuffer, lpszFormat, fmtList);
	va_end(fmtList);
	::OutputDebugString(lpszBuffer);
};
#define PRINT_DBG(fmt, ...) {printf("[%s(%d)] %s : "fmt"\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);}
#define TRACE_DBG(fmt, ...) {TRACE_("[%s(%d)] %s : "fmt"\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);}
#define ASSERT_DBG(val)
#define LERROR(str) throw std::logic_error(str)
#else
#define PRINT_DBG(fmt,...)
#define TRACE_DBG(fmt,...)
#define ASSERT_DBG(val)
#define LERROR(str)
#endif