#pragma once
#include <functional>
#include "common/refptr.hpp"

class Event;
class Task;
class ITimerPolicy
{
public:
	virtual bool getPolicy() = 0;
	virtual void Notify() = 0;
};
typedef std::function<void()> Work;

class CTimer
{
protected:
	RefPtr<ITimerPolicy> policy;
	double cycles;
	bool isRun;
	RefPtr<Task> work;

public:
	CTimer();
	CTimer(int counter);
	CTimer(bool looper);
	void operator()( Work _f,const double& _cycles);
	virtual ~CTimer();

	void Stop();

};
