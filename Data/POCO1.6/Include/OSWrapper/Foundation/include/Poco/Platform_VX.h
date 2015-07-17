//
// Platform_VX.h
//
// $Id: //poco/1.4/Foundation/include/Poco/Platform_VX.h#1 $
//
// Library: Foundation
// Package: Core
// Module:  Platform
//
// Platform and architecture identification macros
// and platform-specific definitions for VxWorks
//
// Copyright (c) 2004-2011, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_Platform_VX_INCLUDED
#define Foundation_Platform_VX_INCLUDED

//@ include for GCC_DIAG_OFF and GCC_DIAG_ON
#include "Platform_POSIX.h"
#include <vxworks.h>		//@ for macro by <uglyduck68@gmail.com>
#define POCO_NO_SYS_SELECT_H 
//#define POCO_NO_FPENVIRONMENT		//@ replace with C99 by <uglyduck68@gmail.com>
#define POCO_NO_WSTRING 
#define POCO_NO_SHAREDMEMORY
#define POCO_NO_SYSLOGCHANNEL
//#define	HAVE_MEMMOVE
//#define	HAVE_BCOPY

#endif // Foundation_Platform_VX_INCLUDED
