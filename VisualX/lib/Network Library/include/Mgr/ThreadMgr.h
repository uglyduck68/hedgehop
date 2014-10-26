#pragma once
#include <vector>
#include "common/CommonRunable.h"
class rmThread;
class ThreadMgr
{
public:
	static ThreadMgr& GetThread();
	static void ReleaseThreadMgr();
	ThreadMgr();
	~ThreadMgr(void);
	rmThread* Register(RunFunc Func);
	void Pause();
	void Resume();
	void Stop();
	const bool getThreadStatus() const;
	const bool getStatus() const;
private:

	ThreadMgr(const ThreadMgr&);
	ThreadMgr& operator=(const ThreadMgr&);
	void setThreadStatus(const bool& Run);

	void setStatus(bool Pause);

	bool isRun;
	bool isPause;
	std::vector<std::shared_ptr<rmThread>> m_Thread;

};

