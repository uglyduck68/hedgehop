#pragma once
#include "common\rmrunable.h"
#include <functional>
class ThreadMgr;
typedef std::function<void()> RunFunc;
class CommonRunable :
	public rmRunable
{
private:
	CommonRunable(const CommonRunable&);
	CommonRunable& operator=(const CommonRunable&);

public:
	CommonRunable(const RunFunc& Func,ThreadMgr* Mgr);
	~CommonRunable(void);
public:
	void SetState(bool State);
	void Run();
private:
	RunFunc m_Func;
	ThreadMgr* m_Mgr;
};

