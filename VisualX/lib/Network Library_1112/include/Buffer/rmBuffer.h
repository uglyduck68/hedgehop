/** @file rmBuffer.h
 ** @date 2014-11-10
 ** @author 박현(hyunpark@endcs.net)
 **/

#ifndef RM_INCLUDE_RMBUFFER_H_
#define RM_INCLUDE_RMBUFFER_H_

//--------------------------------------------------------------------------
#include "Buffer/rmBufferedData.h"
#include <deque>
#include "common/refptr.hpp"
//--------------------------------------------------------------------------

typedef std::deque<RefPtr<rmBufferedData>> BDVector;
/// 버퍼 인터페이스
class rmBuffer
{
private:
	rmBuffer(const rmBuffer&);
	rmBuffer& operator=(const rmBuffer&);
public:
	rmBuffer(){}
	virtual ~rmBuffer() {}
	virtual void GetBDArray(BDVector& Buffer) = 0;
	virtual const size_t GetSize() = 0;
	virtual const size_t GetSize2() = 0;
	virtual const bool isEmpty() = 0;

	virtual void AddData(void* data, unsigned short len,std::function<void(void*)> Work) = 0;

	virtual void AddSocketData(void* data, unsigned short len,std::function<void(void*,RefPtr<ISocket>)> Work) = 0;

	virtual void Clear() = 0;

	virtual void ClearUsedBuffer() = 0;
};


#endif // RM_INCLUDE_RMBUFFER_H_