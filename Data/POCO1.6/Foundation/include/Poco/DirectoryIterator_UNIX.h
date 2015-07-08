//
// DirectoryIterator_UNIX.h
//
// $Id: //poco/1.4/Foundation/include/Poco/DirectoryIterator_UNIX.h#1 $
//
// Library: Foundation
// Package: Filesystem
// Module:  DirectoryIterator
//
// Definition of the DirectoryIteratorImpl class for UNIX.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_DirectoryIterator_UNIX_INCLUDED
#define Foundation_DirectoryIterator_UNIX_INCLUDED


#include "Poco/Foundation.h"
#include <dirent.h>


namespace Poco {


class Foundation_API DirectoryIteratorImpl
{
public:
	DirectoryIteratorImpl(const std::string& path);
	~DirectoryIteratorImpl();
	const std::string& get() const;
	const std::string& next();

	//
	// inlines
	//
	inline void duplicate()
	{
		++_rc;
	}

	inline void release()
	{
		if (--_rc == 0)
			delete this;
	}

	
private:
	DIR*        _pDir;
	std::string _current;
	int _rc;
};



} // namespace Poco


#endif // Foundation_DirectoryIterator_UNIX_INCLUDED
