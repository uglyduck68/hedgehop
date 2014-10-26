/*!	@file	rmThread.h
 *	@brief	�����带 �����ϴ� �߻� Ŭ���� ����
 *	@author	������ (hwlee@endcs.net)
 *	@date	2014-2-6
 */

#ifndef RM_INCLUDE_RMTHREAD_H_
#define RM_INCLUDE_RMTHREAD_H_
#include <functional>

//--------------------------------------------------------------------------
class rmRunable;

//--------------------------------------------------------------------------
class rmSync
{
public:	
	virtual ~rmSync() {}

	virtual void Lock() = 0;
	virtual bool TryLock() = 0;
	virtual void UnLock() = 0;
};

//--------------------------------------------------------------------------
enum rmThreadState
{							
	THREAD_STOP,	
	THREAD_RUN
};

//--------------------------------------------------------------------------
class rmThreadReporter
{
public:
	virtual ~rmThreadReporter() {}
	virtual void SetThreadState(const rmThreadState &state) = 0;
};
typedef std::function<void()> RunFunc;
class ThreadMgr;
//--------------------------------------------------------------------------
class rmThread : public rmThreadReporter
{
public:		
	rmThread();
	virtual ~rmThread();

	virtual void Start() = 0;
	virtual void Stop() = 0;

	rmRunable *GetRunable() const;

	// DI
	rmThread *LeaseRunable(rmRunable *runable);
	rmThread* LeaseRunable(RunFunc Func,bool isRunable_=true,ThreadMgr* Mgr=0);

	rmThreadState GetThreadState();	
	bool isRunable();
	void Run();

private:
	rmThread(const rmThread&);
	rmThread& operator=(const rmThread&);
	void SetThreadState(const rmThreadState &state);


private:
	// DI
	bool m_isRunable;
	RunFunc m_Function;
	rmRunable *m_Runable;

	rmThreadState m_ThreadState;
};

#endif // RM_INCLUDE_RMTHREAD_H_