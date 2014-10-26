/*!	@file	rmSwitchBuffer.h
 *	@brief	내부 저장 공간의 스위칭 기능을 추가한 버퍼 클래스 선언
 *	@author	이현우 (hwlee@endcs.net)
 *	@date	2014-2-6
 */

#ifndef RM_INCLUDE_RMSWITCHBUFFER
#define RM_INCLUDE_RMSWITCHBUFFER

#include "buffer/rmBuffer.h"

//--------------------------------------------------------------------------
class rmSwitchBuffer : public rmBuffer
{
private:
	rmSwitchBuffer(const rmSwitchBuffer&);
	rmSwitchBuffer& operator=(const rmSwitchBuffer&);
public:
	rmSwitchBuffer();
	virtual ~rmSwitchBuffer();

	virtual BDVector& GetBDArray();
	virtual const unsigned int GetSize() const;
	virtual const unsigned int GetSize2() const;
	virtual void AddData(void* buf,unsigned short sz,std::shared_ptr<ICommandInterface> Work);
	virtual void AddData(void* buf,unsigned short sz,std::function<void(void*)> Work );
	virtual void AddSocketData(void* buf,unsigned short sz,std::function<void(void*,std::shared_ptr<ISocket>)> Work );
	virtual void Clear();

	virtual void ClearUsedBuffer();

private:
	void SwitchBuffer();

	unsigned char Active;
	unsigned char Last;
	std::vector<BDVector> m_Buffers;
};

#endif // RM_INCLUDE_RMSWITCHBUFFER