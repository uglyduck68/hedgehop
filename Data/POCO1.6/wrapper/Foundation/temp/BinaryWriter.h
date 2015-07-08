
#ifndef X1_BinaryWriter_INCLUDED
#define X1_BinaryWriter_INCLUDED

#include "../../Foundation/include/Poco/BinaryWriter.h"
//#include "./TextEncoding.h"

namespace X1 {

class BinaryWriter : public Poco::BinaryWriter
{
public:
	enum StreamByteOrder
	{
		NATIVE_BYTE_ORDER        = 1, /// the host's native byte-order
		BIG_ENDIAN_BYTE_ORDER    = 2, /// big-endian (network) byte-order
		NETWORK_BYTE_ORDER       = 2, /// big-endian (network) byte-order
		LITTLE_ENDIAN_BYTE_ORDER = 3  /// little-endian byte-order
	};
	
	BinaryWriter(std::ostream& ostr, StreamByteOrder byteOrder = NATIVE_BYTE_ORDER)
		: Poco::BinaryWriter(ostr, (Poco::BinaryWriter::StreamByteOrder)byteOrder)
	{}

//	BinaryWriter(std::ostream& ostr, TextEncoding& encoding, StreamByteOrder byteOrder = NATIVE_BYTE_ORDER)
//		: Poco::BinaryWriter(ostr, (Poco::TextEncoding)encoding, (Poco::BinaryWriter::StreamByteOrder)byteOrder)
//	{}

	~BinaryWriter()
	{}
};


template <typename T>
class BasicMemoryBinaryWriter : public Poco::BasicMemoryBinaryWriter<T>
{
public:
	BasicMemoryBinaryWriter(Buffer<T>& data, StreamByteOrder byteOrder = NATIVE_BYTE_ORDER)
		: Poco::BasicMemoryBinaryWriter<T>(data, (Poco::BinaryWriter::StreamByteOrder)byteOrder)
	{
	}

//	BasicMemoryBinaryWriter(Buffer<T>& data, TextEncoding& encoding, StreamByteOrder byteOrder = NATIVE_BYTE_ORDER)
//		: Poco::BasicMemoryBinaryWriter<T>(data, (Poco::TextEncoding)encoding, (Poco::BinaryWriter::StreamByteOrder)byteOrder)
//	{
//	}

	virtual ~BasicMemoryBinaryWriter()
	{
	}
};

}//X1...


#endif // Foundation_BinaryWriter_INCLUDED
