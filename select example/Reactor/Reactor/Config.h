/**
 * This file defines some stuff for building this library
 */

///////////////////////////////////////////////////////////////////////////////
// Section for macro for build
///////////////////////////////////////////////////////////////////////////////

// I want to build this by using pthread. This is almost default option.
#define	_X1_USE_PTHREAD_

///////////////////////////////////////////////////////////////////////////////
// End of Section for macro for build
///////////////////////////////////////////////////////////////////////////////

#ifdef	_X1_USE_PTHREAD_
#include <pthread.h>
#endif

#ifdef	WIN32	// for windows

#define _X1_WINDOWS_
#define	_X1_USE_32BIT

#elif defined(_LINUX_)	// for Linux

#define	_X1_LINUX_

#elif defined(_VXWORKS_)	// for vxworks

#define	_X1_VXWORKS_

#endif

#ifdef	_UNICODE

#elif defined(_MBCS)
#define	_X1_WIDE_CHARACTER
#endif

// for VisualStudio compiler
#ifdef	_MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif