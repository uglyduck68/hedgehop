/*!	@file Lock.h
 *	@brief ����ȭ Ŭ����
 *	@author ����(hyunpark@endcs.net)
 *	@date 2014-11-10
 */

#pragma once
#include <vector>
#include "common/atomic.h"
#include "common/HandlerHolder.h"

template<typename T>
class RefPtr;

/*!	@struct ILock
 *	@brief ��� �������̽�
 *	@author ����(hyunpark@endcs.net)
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
 *	@brief	���� ���� ��
 *	@author	����(hyunpark@endcs.net)
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
	/// ���
	ScopedLock(ILock& guard);
	/// ��� ����
	~ScopedLock();
};
/*!	@class	ReverseScopedLock
 *	@brief	���� ���� ��
 *	@author	����(hyunpark@endcs.net)
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
	/// ��� ����
	ReverseScopedLock(ILock& guard);
	/// ���
	~ReverseScopedLock();
};
/*!	@class	Mutex
 *	@brief	����ȭ Ŭ����(Mutex)
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class Mutex : public ILock
{
public:
	/// ������
	Mutex();
	/// �Ҹ���
	~Mutex();

	/// ���
	virtual void Lock();
	/// ��� �� �ִ��� Ȯ��
	virtual bool TryLock();
	/// n ms �� ��ٴ�.
	virtual bool WaitLock(long timeout = 0xFFFFFFFF);
	/// ��� ����
	virtual void Unlock();
private:
	Mutex(const Mutex&);
	const Mutex& operator=(const Mutex&);
protected:
	HandleHolder hMutex;
};
/*!	@class	CSLock
 *	@brief	����ȭ Ŭ����(Critical Section)
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class CSLock : public ILock
{
	/// ������
	CSLock();
	/// �Ҹ���
	~CSLock();

	/// ���
	virtual void Lock();
	/// ��� �� �ִ��� Ȯ��
	virtual bool TryLock();
	/// n ms �� ��ٴ�.
	virtual bool WaitLock(long timeout = 0xFFFFFFFF);
	/// ��� ����
	virtual void Unlock();
private:
	CSLock(const CSLock&);
	const CSLock& operator=(const CSLock&);
protected:
	CRITICAL_SECTION cs;
};
/*!	@struct MultiWaitBase
 *	@brief MultiWaitBase Interface
 *	@author ����(hyunpark@endcs.net)
 *	@date 2014-11-10
 */
struct MultiWaitBase
{
	virtual void* GetHandle() = 0;
};
/// MultiWait ������
typedef MultiWaitBase* MultiWaitPtr;

int WaitForMultiple(std::vector<MultiWaitPtr>& objects,unsigned long timeout = 0xFFFFFFFF);

DWORD cooprativeWait(HANDLE waitHandle, unsigned long timeout = 0xFFFFFFFF);

/*!	@class	Event
 *	@brief	����ȭ Ŭ����(Event)
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class Event : public MultiWaitBase
{
public:
	/// ������
	Event();
	/// �Ҹ���
	virtual ~Event();

	/** ���
		@param timeout : ���ð�(�⺻�� infinite) */
	long Wait(long timeout = 0xFFFFFFFF);
	/// ��������� üũ
	bool Check();
	/// ����
	void Notify();
	/// �ʱ�ȭ
	void Reset();
	/// �ڵ��� ���´�.
	virtual void* GetHandle();
private:
	Event(const Event&);
	const Event& operator=(const Event&);
protected:
	HandleHolder hEvent;

};
/*!	@class	Semaphore
 *	@brief	����ȭ Ŭ����(Semaphore)
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class Semaphore : public MultiWaitBase
{
public:
	/// ������
	Semaphore();
	/// �Ҹ���
	~Semaphore();
	/** ���
		@param timeout : ���ð�(�⺻�� infinite) */
	long Wait(long timeout = 0xFFFFFFFF);
	/// ��������� üũ
	bool Check();
	/** ����
		@param count : ������ ����ŭ ���� */
	bool Notify(long count = 1);

	virtual void* GetHandle();
private:
	Semaphore(const Semaphore&);
	const Semaphore& operator=(const Semaphore&);

private:
	HandleHolder hSemaphore;
};
/*!	@class	ConditionVariable
 *	@brief	����ȭ Ŭ����(Condition Variable)
 *	@author	����(hyunpark@endcs.net)
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
	/// ������
	ConditionVariable();
	/// �Ҹ���
	~ConditionVariable();
	/// ����
	int Notify();
	/// ������� ��� ���� ������ ����
	int NotifyAll();
	/** ���
		@param external_mutex : ����߿� ��ٸ� ����ȭ ��ü
		@param timeout_ms : ��� �ð� */
	int Wait(Mutex& external_mutex,long timeout_ms);
};
/*!	@class	FastReadWriteLock
 *	@brief	����ȭ Ŭ����(Fast Read Write Lock)
 *	@author	����(hyunpark@endcs.net)
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