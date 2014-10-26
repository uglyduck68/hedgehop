/*!	@file	rmBuffer.h
 *	@brief	버퍼 구현 추상 클래스 선언
 *	@author	이현우 (hwlee@endcs.net)
 *	@date	2014-2-6
 */

#ifndef RM_INCLUDE_RMBUFFER_H_
#define RM_INCLUDE_RMBUFFER_H_

//--------------------------------------------------------------------------
#include "Buffer/rmBufferedData.h"
#include <deque>
//--------------------------------------------------------------------------
class ICommandInterface;

typedef std::deque<std::shared_ptr<rmBufferedData>> BDVector;

class rmBuffer
{
private:
	rmBuffer(const rmBuffer&);
	rmBuffer& operator=(const rmBuffer&);
public:
	rmBuffer(){}
	virtual ~rmBuffer() {}
	virtual BDVector& GetBDArray() = 0;
	virtual const unsigned int GetSize() const = 0;
	virtual const unsigned int GetSize2() const = 0;

	virtual void AddData(void* data, unsigned short len,std::shared_ptr<ICommandInterface> Work) = 0;

	virtual void AddData(void* data, unsigned short len,std::function<void(void*)> Work) = 0;

	virtual void AddSocketData(void* data, unsigned short len,std::function<void(void*,std::shared_ptr<ISocket>)> Work) = 0;

	virtual void Clear() = 0;

	virtual void ClearUsedBuffer() = 0;
};


#endif // RM_INCLUDE_RMBUFFER_H_