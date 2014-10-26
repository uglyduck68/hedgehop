#pragma once
#include <functional>

class rmThread;
class QTimer;
class ITimerPolicy;
class CTimer
{
	rmThread* Thread;
	ITimerPolicy* policy;
	std::function<void()> f;
	QTimer* Timer;
	double cycles;

	void release();
	void run();
	void initalize();

public:
	CTimer();
	CTimer(std::function<void()> _f,const double& _cycles,bool looper);
	CTimer(std::function<void()> _f,const double& _cycles,int counter);
	CTimer(std::function<void()> _f,const double& _cycles);

	void operator ()(std::function<void()> _f,const double& _cycles,bool looper);
	void operator ()(std::function<void()> _f,const double& _cycles,int counter);
	void operator()( std::function<void()> _f,const double& _cycles);
	virtual ~CTimer();

	void Stop();

};
