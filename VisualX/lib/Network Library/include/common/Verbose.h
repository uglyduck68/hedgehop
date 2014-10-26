#pragma once

#ifdef _DEBUG
#include <assert.h>

#define PRINT_DBG(fmt, ...) {printf("[%s(%d)] %s : "fmt"\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);}
#define TRACE_DBG(fmt, ...) {TRACE("[%s(%d)] %s : "fmt"\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);}
#define ASSERT_DBG(val)
#define LERROR(str) throw std::logic_error(str)
#else
#define PRINT_DBG(fmt,...)
#define TRACE_DBG(fmt,...)
#define ASSERT_DBG(val)
#define LERROR(str)
#endif