/** @file rmSwitchBuffer.h
 ** @brief 스위치 가능한 버퍼 클래스
 ** @date 2014-11-10
 ** @author 박현(hyunpark@endcs.net)
 **/

#ifndef RM_INCLUDE_RMSWITCHBUFFER
#define RM_INCLUDE_RMSWITCHBUFFER

#include "buffer/rmBuffer.h"
class Mutex;
class Event;
//--------------------------------------------------------------------------
/*!	@class	rmSwitchBuffer
 *	@brief	스위치 가능한 버퍼 클래스
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class rmSwitchBuffer : public rmBuffer
{
private:
	rmSwitchBuffer(const rmSwitchBuffer&);
	rmSwitchBuffer& operator=(const rmSwitchBuffer&);
public:
	/// 생성자
	rmSwitchBuffer();
	/// 소멸자
	virtual ~rmSwitchBuffer();
	/// 현재 버퍼를 가져온다.
	virtual void GetBDArray(BDVector& Buffer);
	/// 활성화된 버퍼의 사이즈를 반환.
	virtual const size_t GetSize();
	/// 마지막 버퍼의 사이즈를 반환.
	virtual const size_t GetSize2();
	/// 활성화된 버퍼가 비어있는지 확인
	virtual const bool isEmpty();

	/// 버퍼에 데이터를 추가한다.
	virtual void AddData(void* buf,unsigned short sz,std::function<void(void*)> Work );
	virtual void AddSocketData(void* buf,unsigned short sz,std::function<void(void*,RefPtr<ISocket>)> Work );
	
	/// 버퍼를 초기화 한다.
	virtual void Clear();

	/// 사용한 버퍼를 초기화 한다.
	virtual void ClearUsedBuffer();

protected:
	void SwitchBuffer();
	unsigned char Active;
	unsigned char Last;
	bool bisEmpty;
	size_t nSize;
	size_t nSize2;
	RefPtr<Mutex> m_output;
	RefPtr<Mutex> m_input;
	RefPtr<Event> m_WaitEvent;
	std::vector<BDVector> m_Buffers;
};

#endif // RM_INCLUDE_RMSWITCHBUFFER