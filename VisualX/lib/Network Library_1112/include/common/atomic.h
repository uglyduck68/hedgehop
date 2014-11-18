/*!	@file atomic.h
 *	@brief atomic
 *	@author 박현(hyunpark@endcs.net)
 *	@date 2014-11-10
 */
#pragma once
#include <windows.h>
	/** @brief Compare And Swap
		\비교후 값이 틀리다면 모든 작업을 돌리고 빠져나온다.
		\값이 같다면 새로운 값으로 대체한다.
		@tparam T : 대상 타입
		@param address : 확인할 값의 포인터
		@param oldValue : 기존 값
		@param newValue : 새로운 값 */
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
 *	@brief 원자성이 추가된 플래그 클래스	
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class AtomicFlag
{
public:
	/// 생성자
	AtomicFlag();
	/// flag를 true로 설정한다.
	void Set();
	/// flag가 true인지 확인한다.
	bool IsSet();
	/// flag를 false로 설정한다.
	void Reset();
private:
	AtomicFlag(const AtomicFlag&);
	const AtomicFlag& operator=(const AtomicFlag&);
private:
	long flag;
};
/*!	@class	AtomicNumber
 *	@brief	원자성이 추가된 숫자 클래스
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class AtomicNumber
{
public:
	/// 생성자
	AtomicNumber();
	/// 값을 1증가 시킨다.
	void Inc();
	/// 값을 1감소 시킨다.
	void Dec();
	/// 현재 값을 얻어온다.
	long GetValue();
	/// 값을 설정한다.
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