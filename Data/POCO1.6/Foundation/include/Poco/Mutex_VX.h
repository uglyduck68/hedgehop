//
// Mutex_VX.h
//
// $Id: //poco/1.4/Foundation/include/Poco/Mutex_VX.h#1 $
//
// Library: Foundation
// Package: Threading
// Module:  Mutex
//
// Definition of the MutexImpl and FastMutexImpl classes for VxWorks.
//
// Copyright (c) 2004-2011, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//

#if 0
#ifndef Foundation_Mutex_VX_INCLUDED
#define Foundation_Mutex_VX_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/Exception.h"
#include <semLib.h>
#include <errno.h>


namespace Poco {


class Foundation_API MutexImpl
{
protected:
	MutexImpl();
	MutexImpl(bool fast);
	~MutexImpl();
	void lockImpl();
	bool tryLockImpl();
	bool tryLockImpl(long milliseconds);
	void unlockImpl();


private:
	SEM_ID _sem;
};


class Foundation_API FastMutexImpl: public MutexImpl
{
protected:
	FastMutexImpl();
	~FastMutexImpl();
};


//
// inlines
//






} // namespace Poco


#endif // Foundation_Mutex_VX_INCLUDED
#endif
