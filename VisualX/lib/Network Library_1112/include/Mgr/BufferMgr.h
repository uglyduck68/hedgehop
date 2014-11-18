/*!	@file BufferMgr.h
 *	@brief ���۸� �����ϴ� �Ŵ��� Ŭ����
 *	@author ����(hyunpark@endcs.net)
 *	@date 2014-11-10
 */
#pragma once
#include "buffer/rmBuffer.h"
#include "common/refptr.hpp"
/*!	@class	BufferMgr
 *	@brief	���۸� �����ϴ� �Ŵ��� Ŭ����
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class BufferMgr
{
public:
	/// ������
	BufferMgr(void);
	/// �Ҹ���
	~BufferMgr(void);
	/** ���� �Ŵ����� ��ȯ�Ѵ�.
		\ �̱��� �������̽�	*/
	static BufferMgr& GetBufferMgr();
	/** ���� �Ŵ����� �޸𸮿��� �����Ѵ�.
		\ �̱��� ����	*/
	static void ReleaseBufferMgr();
	/// ���۸� ��ȯ�Ѵ�.
	rmBuffer& GetBuffer();
	/// DDS ���۸� ��ȯ�Ѵ�.
	rmBuffer& GetDDSBuffer();

private:
	void Init();
	class BufferImpl;
	BufferImpl* m_Impl;
};

