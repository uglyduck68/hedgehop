#pragma once








// flatform (OS_WINDOWS | OS_LINUX | OS_FREEBSD)
#if defined(_WINDOWS)
	#define OS_WINDOWS
#else
	//declar makefile.freebsd or makefile.linux
#endif




// bit type (USE_32BIT | USE_64BIT)
#define USE_64BIT




// flatform specific code
#if   defined (OS_WINDOWS)
	#define USE_DEMULTIPLEXER_IOCP
	#define USE_DEMULTIPLEXER_SELECT
	
#elif defined (OS_FREEBSD)
	#define USE_DEMULTIPLEXER_KQUEUE
	#define USE_DEMULTIPLEXER_SELECT

#elif defined (OS_LINUX)
	#define USE_DEMULTIPLEXER_EPOLL
	#define USE_DEMULTIPLEXER_SELECT

#endif




// debugging
//#define USE_DEBUG_MODE


