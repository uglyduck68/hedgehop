// TestTimer.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <stdio.h>

///////////////////////////////////////////////////////////////////////////////
// Test SelectTimer class
///////////////////////////////////////////////////////////////////////////////
#include "SelectTimer.h"

NS_X1_USE


class Timer1 :public Timer
{
public:
	Timer1() {}

	void Run(Timer* pArg)
	{
		static int	nCallCount	= 0;

		Timer1*	p	= static_cast<Timer1*>(pArg);

		printf("Timer1: current time: %13.2lf, Call #: %d\n", Timer::Now(), nCallCount++);
	}
};

class Timer2 :public Timer
{
public:
	Timer2() {}

	void Run(Timer* pArg)
	{
		static int	nCallCount	= 0;

		Timer2*	p	= static_cast<Timer2*>(pArg);

		printf("Timer2: current time: %13.2lf, Call #: %d\n", Timer::Now(), nCallCount++);
	}
};

class Timer3 :public Timer
{
public:
	Timer3() {}

	void Run(Timer* pArg)
	{
		static int	nCallCount	= 0;

		Timer3*	p	= static_cast<Timer3*>(pArg);

		printf("Timer3: current time: %13.2lf, Call #: %d\n", Timer::Now(), nCallCount++);
	}
};


int TestSelectTimer()
{
	SelectTimer		TimerMng;
	Timer1			T1;
	Timer2			T2;
	Timer3			T3;

	T1.SetExpireTime(1);	// this is 1 sec timer
	T2.SetExpireTime(2);	// 2 sec timer
	T3.SetExpireTime(3);	// 3 sec timer

	printf("T1: id: %d\n", TimerMng.RegisterTimer(&T1));
	printf("T1: id: %d\n", TimerMng.RegisterTimer(&T2));
	printf("T1: id: %d\n", TimerMng.RegisterTimer(&T3));

	TimerMng.Start();

	TimerMng.Join();

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	TestSelectTimer();

	return 0;
}

