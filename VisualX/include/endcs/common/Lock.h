/*!	@file Lock.h
 *	@brief 동기화 클래스
 *	@author 박현(hyunpark@endcs.net)
 *	@date 2014-11-10
 */

#pragma once
#include <vector>
#include "common/atomic.h"
#include "common/HandlerHolder.h"

template<typename T>
class RefPtr;

/*!	@struct ILock
 *	@brief 잠금 인터페이스
 *	@author 박현(hyunpark@endcs.net)
 *	@date 2014-11-10
 */
struct ILock
{
	virtual void Lock() = 0;
	virtual bool TryLock() = 0;
	virtual bool WaitLock(long timeout) = 0;
	virtual void Unlock() = 0;
};
/*!	@class	ScopedLock
 *	@brief	제약 범위 락
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class ScopedLock
{
private:
	ScopedLock(const ScopedLock&);
	const ScopedLock& operator=(const ScopedLock&);
protected:
	ILock& guard;

public:
	/// 잠금
	ScopedLock(ILock& guard);
	/// 잠금 해제
	~ScopedLock();
};
/*!	@class	ReverseScopedLock
 *	@brief	제약 범위 락
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class ReverseScopedLock
{
public:
private:
	ReverseScopedLock(const ReverseScopedLock&);
	const ReverseScopedLock& operator=(const ReverseScopedLock&);
protected:
	ILock& guard;

public:
	/// 잠금 해제
	ReverseScopedLock(ILock& guard);
	/// 잠금
	~ReverseScopedLock();
};
/*!	@class	Mutex
 *	@brief	동기화 클래스(Mutex)
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class Mutex : public ILock
{
public:
	/// 생성자
	Mutex();
	/// 소멸자
	~Mutex();

	/// 잠금
	virtual void Lock();
	/// 잠글 수 있는지 확인
	virtual bool TryLock();
	/// n ms 간 잠근다.
	virtual bool WaitLock(long timeout = 0xFFFFFFFF);
	/// 잠금 해제
	virtual void Unlock();
private:
	Mutex(const Mutex&);
	const Mutex& operator=(const Mutex&);
protected:
	HandleHolder hMutex;
};
/*!	@class	CSLock
 *	@brief	동기화 클래스(Critical Section)
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class CSLock : public ILock
{
	/// 생성자
	CSLock();
	/// 소멸자
	~CSLock();

	/// 잠금
	virtual void Lock();
	/// 잠글 수 있는지 확인
	virtual bool TryLock();
	/// n ms 간 잠근다.
	virtual bool WaitLock(long timeout = 0xFFFFFFFF);
	/// 잠금 해제
	virtual void Unlock();
private:
	CSLock(const CSLock&);
	const CSLock& operator=(const CSLock&);
protected:
	CRITICAL_SECTION cs;
};
/*!	@struct MultiWaitBase
 *	@brief MultiWaitBase Interface
 *	@author 박현(hyunpark@endcs.net)
 *	@date 2014-11-10
 */
struct MultiWaitBase
{
	virtual void* GetHandle() = 0;
};
/// MultiWait 포인터
typedef MultiWaitBase* MultiWaitPtr;

int WaitForMultiple(std::vector<MultiWaitPtr>& objects,unsigned long timeout = 0xFFFFFFFF);

DWORD cooprativeWait(HANDLE waitHandle, unsigned long timeout = 0xFFFFFFFF);

/*!	@class	Event
 *	@brief	동기화 클래스(Event)
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class Event : public MultiWaitBase
{
public:
	/// 생성자
	Event();
	/// 소멸자
	virtual ~Event();

	/** 대기
		@param timeout : 대기시간(기본값 infinite) */
	long Wait(long timeout = 0xFFFFFFFF);
	/// 대기중인지 체크
	bool Check();
	/// 통지
	void Notify();
	/// 초기화
	void Reset();
	/// 핸들을 얻어온다.
	virtual void* GetHandle();
private:
	Event(const Event&);
	const Event& operator=(const Event&);
protected:
	HandleHolder hEvent;

};
/*!	@class	Semaphore
 *	@brief	동기화 클래스(Semaphore)
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class Semaphore : public MultiWaitBase
{
public:
	/// 생성자
	Semaphore();
	/// 소멸자
	~Semaphore();
	/** 대기
		@param timeout : 대기시간(기본값 infinite) */
	long Wait(long timeout = 0xFFFFFFFF);
	/// 대기중인지 체크
	bool Check();
	/** 통지
		@param count : 지정된 수만큼 통지 */
	bool Notify(long count = 1);

	virtual void* GetHandle();
private:
	Semaphore(const Semaphore&);
	const Semaphore& operator=(const Semaphore&);

private:
	HandleHolder hSemaphore;
};
/*!	@class	ConditionVariable
 *	@brief	동기화 클래스(Condition Variable)
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class ConditionVariable
{
private:
	ConditionVariable(const ConditionVariable&);
	const ConditionVariable& operator=(const ConditionVariable&);
protected:
	Semaphore sema;
	Event waiters_done;
	size_t was_broadcast;

public:
	AtomicNumber waiters;
	/// 생성자
	ConditionVariable();
	/// 소멸자
	~ConditionVariable();
	/// 통지
	int Notify();
	/// 대기중인 모든 조건 변수에 통지
	int NotifyAll();
	/** 대기
		@param external_mutex : 대기중에 기다릴 동기화 객체
		@param timeout_ms : 대기 시간 */
	int Wait(Mutex& external_mutex,long timeout_ms);
};
/*!	@class	FastReadWriteLock
 *	@brief	동기화 클래스(Fast Read Write Lock)
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class FastReadWriteLock
{
private:
	struct LockState
	{
		unsigned long
		readWaiting :11,
		readLock	:11,
		writeWaiting	:9,
		writeLock	:1;


		LockState( long value /*= 0*/ )
		{
			*(long*)this = value;
		}

		operator long() const
		{
			return *reinterpret_cast<const unsigned long*>(this);
		}

		LockState& operator=( long value )
		{
			*(long*)this = value; return *this;
		}

		LockState& operator=( const LockState& rhs )
		{
			*(long*)this = (long)rhs; return *this;
		}

		bool operator==( long value ) const
		{
			return (long)*this == value;
		}

	};
	volatile long m_lockState;
	AtomicFlag whiles;
	Semaphore m_ReadSem;
	Semaphore m_WriteSem;
public:
	FastReadWriteLock();
	~FastReadWriteLock();
	void WaitForReadLock();
	bool TryReadLock();
	void ReleaseReadLock();
	void WaitForWriteLock();
	bool TryWriteLock();
	void ReleaseWriteLock();
};