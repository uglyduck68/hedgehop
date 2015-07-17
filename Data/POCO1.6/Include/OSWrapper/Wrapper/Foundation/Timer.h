#ifndef X1_Timer_INCLUDED
#define X1_Timer_INCLUDED


#include "Poco/Timer.h"

namespace X1 {


class Timer: public Poco::Timer
{
public:

	Timer(long startInterval = 0, long periodicInterval = 0) : Poco::Timer(startInterval, periodicInterval)
	{}

	Timer(Poco::Timer timer) : Poco::Timer(timer.getStartInterval(), timer.getPeriodicInterval())
	{
	}
		
	virtual ~Timer()
	{}
};


template <class C> 
class TimerCallback: public Poco::TimerCallback<C>
{
public:
	typedef void (C::*Callback)(Timer&);


	//function pointer casting for compile...
	TimerCallback(C& object, Callback method): Poco::TimerCallback<C>(object, (void(C::*)(Poco::Timer&))method)
	{
	}

	TimerCallback(const TimerCallback& callback): Poco::TimerCallback<C>(callback)
	{
	}

	virtual ~TimerCallback()
	{
	}

};


} // namespace X1


#endif // Foundation_Timer_INCLUDED
