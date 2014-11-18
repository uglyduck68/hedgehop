/*!	@file BufferMgr.h
 *	@brief 버퍼를 관리하는 매니저 클래스
 *	@author 박현(hyunpark@endcs.net)
 *	@date 2014-11-10
 */
#pragma once
#include "buffer/rmBuffer.h"
#include "common/refptr.hpp"
/*!	@class	BufferMgr
 *	@brief	버퍼를 관리하는 매니저 클래스
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class BufferMgr
{
public:
	/// 생성자
	BufferMgr(void);
	/// 소멸자
	~BufferMgr(void);
	/** 버퍼 매니저를 반환한다.
		\ 싱글턴 인터페이스	*/
	static BufferMgr& GetBufferMgr();
	/** 버퍼 매니저를 메모리에서 제거한다.
		\ 싱글턴 해제	*/
	static void ReleaseBufferMgr();
	/// 버퍼를 반환한다.
	rmBuffer& GetBuffer();
	/// DDS 버퍼를 반환한다.
	rmBuffer& GetDDSBuffer();

private:
	void Init();
	class BufferImpl;
	BufferImpl* m_Impl;
};

