//
// StreamCopier.h
//
// $Id: //poco/1.4/Foundation/include/Poco/StreamCopier.h#2 $
//
// Library: Foundation
// Package: Streams
// Module:  StreamCopier
//
// Definition of class StreamCopier.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef X1_StreamCopier_INCLUDED
#define X1_StreamCopier_INCLUDED


#include "../../Foundation/include/Poco/StreamCopier.h"

namespace X1 {

class StreamCopier : public Poco::StreamCopier
{
public:
	static std::streamsize copyStream(std::istream& istr, std::ostream& ostr, std::size_t bufferSize = 8192)
	{
		Poco::StreamCopier::copyStream(istr, ostr, bufferSize);
	}

#if defined(POCO_HAVE_INT64)
	static Poco::UInt64 copyStream64(std::istream& istr, std::ostream& ostr, std::size_t bufferSize = 8192)
	{
		Poco::StreamCopier::copyStream64(istr, ostr, bufferSize);
	}
#endif

	static std::streamsize copyStreamUnbuffered(std::istream& istr, std::ostream& ostr)
	{
		Poco::StreamCopier::copyStreamUnbuffered(istr, ostr);
	}

#if defined(POCO_HAVE_INT64)
	static Poco::UInt64 copyStreamUnbuffered64(std::istream& istr, std::ostream& ostr)
	{
		Poco::StreamCopier::copyStreamUnbuffered64(istr, ostr);
	}
#endif

	static std::streamsize copyToString(std::istream& istr, std::string& str, std::size_t bufferSize = 8192)
	{
		Poco::StreamCopier::copyToString(istr, str, bufferSize);
	}

#if defined(POCO_HAVE_INT64)
	static Poco::UInt64 copyToString64(std::istream& istr, std::string& str, std::size_t bufferSize = 8192)
	{
		Poco::StreamCopier::copyToString64(istr, str, bufferSize);
	}

#endif
};


} // namespace X1


#endif // Foundation_StreamCopier_INCLUDED
