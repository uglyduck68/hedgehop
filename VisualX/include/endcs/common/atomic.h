/*!	@file atomic.h
 *	@brief atomic
 *	@author ����(hyunpark@endcs.net)
 *	@date 2014-11-10
 */
#pragma once
#include <windows.h>
	/** @brief Compare And Swap
		\���� ���� Ʋ���ٸ� ��� �۾��� ������ �������´�.
		\���� ���ٸ� ���ο� ������ ��ü�Ѵ�.
		@tparam T : ��� Ÿ��
		@param address : Ȯ���� ���� ������
		@param oldValue : ���� ��
		@param newValue : ���ο� �� */
template <typename T>
bool CAS(long *address,T oldValue, T newValue)
{
	return CAS((volatile LONG*)address,oldValue,newValue);
}
template <typename T>
bool CAS(volatile long *address,T oldValue, T newValue)
{
	return ((long)oldValue == InterlockedCompareExchange(address,oldValue,newValue));
}
/*!	@class	AtomicFlag
 *	@brief ���ڼ��� �߰��� �÷��� Ŭ����	
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class AtomicFlag
{
public:
	/// ������
	AtomicFlag();
	/// flag�� true�� �����Ѵ�.
	void Set();
	/// flag�� true���� Ȯ���Ѵ�.
	bool IsSet();
	/// flag�� false�� �����Ѵ�.
	void Reset();
private:
	AtomicFlag(const AtomicFlag&);
	const AtomicFlag& operator=(const AtomicFlag&);
private:
	long flag;
};
/*!	@class	AtomicNumber
 *	@brief	���ڼ��� �߰��� ���� Ŭ����
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class AtomicNumber
{
public:
	/// ������
	AtomicNumber();
	/// ���� 1���� ��Ų��.
	void Inc();
	/// ���� 1���� ��Ų��.
	void Dec();
	/// ���� ���� ���´�.
	long GetValue();
	/// ���� �����Ѵ�.
	void SetValue(long value);

	void operator = (const long& value);
	bool operator == (const long& value);
	long operator()();
private:
	AtomicNumber(const AtomicFlag&);
	const AtomicNumber& operator=(const AtomicFlag&);
private:
	long number;
};

void _MemoryFence();