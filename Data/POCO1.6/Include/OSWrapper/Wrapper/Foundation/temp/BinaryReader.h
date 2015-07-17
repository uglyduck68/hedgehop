
#ifndef X1_BinaryReader_INCLUDED
#define X1_BinaryReader_INCLUDED


#include "../../Foundation/include/Poco/BinaryReader.h"

namespace Poco {


class BinaryReader
{
public:
	enum StreamByteOrder
	{
		NATIVE_BYTE_ORDER        = 1,  /// the host's native byte-order
		BIG_ENDIAN_BYTE_ORDER    = 2,  /// big-endian (network) byte-order
		NETWORK_BYTE_ORDER       = 2,  /// big-endian (network) byte-order
		LITTLE_ENDIAN_BYTE_ORDER = 3,  /// little-endian byte-order
		UNSPECIFIED_BYTE_ORDER   = 4   /// unknown, byte-order will be determined by reading the byte-order mark
	};

	BinaryReader(std::istream& istr, StreamByteOrder byteOrder = NATIVE_BYTE_ORDER)
		: Poco::BinaryReader(istr, byteOrder)
	{}
//	BinaryReader(std::istream& istr, TextEncoding& encoding, StreamByteOrder byteOrder = NATIVE_BYTE_ORDER)
//		: Poco::BinaryReader(istr, encoding, byteOrder)
//	{}
	virtual ~BinaryReader()
	{}
};


template <typename T>
class BasicMemoryBinaryReader : public Poco::BasicMemoryBinaryReader<T>
{
public:
	BasicMemoryBinaryReader(const Buffer<T>& data, StreamByteOrder byteOrder = NATIVE_BYTE_ORDER)
		: Poco::BasicMemoryBinaryReader<T>(data, byteOrder)
	{
	}

//	BasicMemoryBinaryReader(const Buffer<T>& data, TextEncoding& encoding, StreamByteOrder byteOrder = NATIVE_BYTE_ORDER)
//		: Poco::BasicMemoryBinaryReader<T>(data, encoding, byteOrder)
//	{
//	}

	virtual ~BasicMemoryBinaryReader()
	{
	}
};

} // x1 namespace


#endif // Foundation_BinaryReader_INCLUDED
