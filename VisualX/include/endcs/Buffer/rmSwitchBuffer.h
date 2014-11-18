/** @file rmSwitchBuffer.h
 ** @brief ����ġ ������ ���� Ŭ����
 ** @date 2014-11-10
 ** @author ����(hyunpark@endcs.net)
 **/

#ifndef RM_INCLUDE_RMSWITCHBUFFER
#define RM_INCLUDE_RMSWITCHBUFFER

#include "buffer/rmBuffer.h"
class Mutex;
class Event;
//--------------------------------------------------------------------------
/*!	@class	rmSwitchBuffer
 *	@brief	����ġ ������ ���� Ŭ����
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class rmSwitchBuffer : public rmBuffer
{
private:
	rmSwitchBuffer(const rmSwitchBuffer&);
	rmSwitchBuffer& operator=(const rmSwitchBuffer&);
public:
	/// ������
	rmSwitchBuffer();
	/// �Ҹ���
	virtual ~rmSwitchBuffer();
	/// ���� ���۸� �����´�.
	virtual void GetBDArray(BDVector& Buffer);
	/// Ȱ��ȭ�� ������ ����� ��ȯ.
	virtual const size_t GetSize();
	/// ������ ������ ����� ��ȯ.
	virtual const size_t GetSize2();
	/// Ȱ��ȭ�� ���۰� ����ִ��� Ȯ��
	virtual const bool isEmpty();

	/// ���ۿ� �����͸� �߰��Ѵ�.
	virtual void AddData(void* buf,unsigned short sz,std::function<void(void*)> Work );
	virtual void AddSocketData(void* buf,unsigned short sz,std::function<void(void*,RefPtr<ISocket>)> Work );
	
	/// ���۸� �ʱ�ȭ �Ѵ�.
	virtual void Clear();

	/// ����� ���۸� �ʱ�ȭ �Ѵ�.
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