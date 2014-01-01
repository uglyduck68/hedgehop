#pragma once


#include "config.h"






//OS DEFINED
#if   defined (OS_WINDOWS)
#include "os_windows.h"

#elif defined (OS_FREEBSD)
#include "os_freebsd.h"

#elif defined (OS_LINUX)
#include "os_linux.h"

#endif

