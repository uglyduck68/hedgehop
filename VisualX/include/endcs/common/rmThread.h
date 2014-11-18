/*!	@file	rmThread.h
 *	@brief	스레드
 *	@author	박현 (hyunpark@endcs.net)
 *	@date	2014-10-28
 */

#ifndef RM_INCLUDE_RMTHREAD_H_
#define RM_INCLUDE_RMTHREAD_H_
#include <functional>
#include "common/RefPtr.hpp"
#include "common/HandlerHolder.h"
typedef std::function<void()> Work;
typedef std::function<void(const double&,std::function<void()>)> TimerWork;
template<typename T>
class taskQueue;
typedef taskQueue<Work> WorkQueue;

class Event;
class Mutex;
class AtomicNumber;

enum ThreadState{
	WS_TERMINATED,
	WS_READY,
	WS_RUNNING,
	WS_WORKING,
	WS_IDLING,
	WS_WAITING,
};
enum ThreadCancelMode
{
	CM_Defrred,
	CM_Async,
	CM_Disabled
};
struct ThreadCanceled{};
#if _WIN32_WINNT < 0x400
int SwitchToThread();
#endif
//--------------------------------------------------------------------------
class rmThreadBase
{
public:
	rmThreadBase();
	virtual ~rmThreadBase();
	void Resume();
	void Suspend();
	virtual void Run() = 0;

	unsigned long GetExitCode() const;
	int join() const;
	int detach();
	int attach();
	int cancel();
	int setCancelMode(ThreadCancelMode& cm);
	int microSleep(unsigned int microsec);

	int setProcessAffinity(unsigned int cpunum);
	bool yield() const;
	unsigned int GetThreadID() const;
	void* GetThreadHandle() const;
	bool SetThreadPriority(int nPriority);
	int GetThreadPriority();
	static rmThreadBase* CurrentThread();

protected:
	static unsigned __stdcall ThreadMain(void* owner);
	unsigned ThreadMainImpl();
	void RegisterTLS();
	unsigned int m_nThreadID;

	size_t stackSize;
	int cancelMode; // 0 - deffered (default) 1 - async 2 - disabled

	bool detached;

	HandleHolder m_hThread;
	RefPtr<Event> cancelEvent;
};

class rmThread : public rmThreadBase
{
public:
	typedef rmThreadBase Base;
	rmThread();
	virtual ~rmThread();
	bool isState(const ThreadState& pState);

	void Start();
	void Stop();
	void Resume();
	void Pause();
	void AddTask(Work task);
	bool CheckDone();
private:
	void setState(const ThreadState& pState);
	virtual void Run();
	Work NextTask();

	RefPtr<Mutex> m_mutex;
	RefPtr<Event> m_waitEvent;
	RefPtr<Event> m_workEvent;
	RefPtr<WorkQueue> m_Tasks;
	RefPtr<AtomicNumber> m_State;
};
#endif // RM_INCLUDE_RMTHREAD_H_