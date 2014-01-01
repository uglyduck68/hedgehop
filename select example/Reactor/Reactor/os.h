#pragma once


#include "Config.h"

//OS DEFINED
#if   defined (_X1_WINDOWS_)
#include "os_windows.h"

#elif defined (_X1_VXWORKS_)
#include "os_vxworks.h"

#elif defined (_X1_LINUX_)
#include "os_linux.h"

#endif

