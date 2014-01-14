// TestThreadpool.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include "X1.h"
#include "TimeValue.h"
#include "Thread.h"

using namespace X1;

/**
 * threadpool test program
 * - measure the execution time of some threads
 * - measure the execution time of some threads using threadpool
 * - analysis the difference of both
 */

const int	MAX_COUNT		= 1000000;
const int	MAX_THR_LOOP	= 10;

///////////////////////////////////////////////////////////////////////////////
/// define packet handling threads
///////////////////////////////////////////////////////////////////////////////
void*	thr1(void* Arg)
{
	// time to handle the packet
	Sleep(10);
	return NULL;
}
void*	thr2(void* Arg)
{
	// time to handle the packet
	Sleep(10);
	return NULL;
}
void*	thr3(void* Arg)
{
	// time to handle the packet
	Sleep(10);
	return NULL;
}
void*	thr4(void* Arg)
{
	// time to handle the packet
	Sleep(10);
	return NULL;
}
void*	thr5(void* Arg)
{
	// time to handle the packet
	Sleep(10);
	return NULL;
}
void*	thr6(void* Arg)
{
	// time to handle the packet
	Sleep(10);
	return NULL;
}
void*	thr7(void* Arg)
{
	// time to handle the packet
	Sleep(10);
	return NULL;
}
void*	thr8(void* Arg)
{
	// time to handle the packet
	Sleep(10);
	return NULL;
}
void*	thr9(void* Arg)
{
	// time to handle the packet
	Sleep(10);
	return NULL;
}
void*	thr10(void* Arg)
{
	// time to handle the packet
	Sleep(10);
	return NULL;
}

THRDFUNC	*PacketHandler[MAX_THR_LOOP] = {
	thr1,
	thr2,
	thr3,
	thr4,
	thr5,
	thr6,
	thr7,
	thr8,
	thr9,
	thr10,
};

// define pthread type function
void*	thr_parse_packet(void* Arg)
{
	int		i	= (int)Arg;

	// parse the packet
	Sleep(10);	// sleep 10 milli second

	// call the packet handler
	Thread*		thr	= new Thread();

	thr->Run(PacketHandler[i], NULL);

	thr->Join();

	delete thr;

	printf("Debug: thr_parse_packet finished\n");

	return NULL;
}

int _tmain(int argc, _TCHAR* argv[])
{
	TimeValue		s, e;


	s	= TimeValue::now();
	
	for(int i = 0; i < MAX_THR_LOOP; i++)
	{
		X1::Thread*		thr	= new Thread;

//		printf("thread[%d] starts\n", i);
		// start thread to parse the packet
		if (thr->Run(thr_parse_packet, (void*)i) != X1_OK)
		{
			printf("Error: fail to start thread\n");
			break;
		}

		// wait for the thread to finish the packet parsing 
		thr->Join();
//		printf("thread[%d] ends\n", i);

		delete thr;
	}

	e	= TimeValue::now();

	printf("thread execution time: %ld msec\n", e.msec() - s.msec());

	// in my notebook, those above take about 250 msec averagely.
	// So I wait 2 sec.
	Sleep(2000);

	return 0;
}


