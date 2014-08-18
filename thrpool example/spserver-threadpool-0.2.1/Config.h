/**
* @file		Config.h
* @auther	Younghwan Kim<uglyduck68@gmail.com>
* @version	0.1
* @date		20140816
* @brief	This Config.h has build settings for X1 library.
*/


#define	_BUILD_USE_PTHREAD_			0	// build by pthread on Linux, vxworks
#define	_BUILD_USE_WIN32_ONLY_		0	// build by only WIN32
#define	_BUILD_USE_PTHREAD_WIN32_	1	// build by pthread-win32

//#define	WIN32						// constant for win32 platform
//#define	LINUX						// constant for Linux platform

#if	_BUILD_USE_PTHREAD_ == 1 || _BUILD_USE_PTHREAD_WIN32_ == 1

	#include <pthread.h>

	#ifdef	WIN32
	// use pthread_win32 library
	#endif

#else

#endif