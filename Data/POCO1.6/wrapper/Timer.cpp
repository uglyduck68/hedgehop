#include <iostream>

#include "./Foundation/Timer.h"
#include "./Foundation/Thread.h"
#include "./Foundation/Stopwatch.h"

using X1::Timer;
using X1::TimerCallback;
using X1::Thread;
using X1::Stopwatch;

class TimerExample
{
public:
	TimerExample()
	{
		_sw.start();
	}
	
	void onTimer(Timer& timer)
	{
		std::cout << "Callback called after " << _sw.elapsed()/1000 << " milliseconds." << std::endl;
	}
	
private:
	Stopwatch _sw;
};


int main(int argc, char** argv)
{	
	TimerExample example;

	Timer timer(250, 500);
	timer.start(TimerCallback<TimerExample>(example, &TimerExample::onTimer));
	
	Thread::sleep(5000);
	
	timer.stop();
	
	return 0;
}
