// TestThreadMQ.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <OpenThreads\Mutex.h>
#include <OpenThreads\Thread.h>
#include <OpenThreads\MsgQueue_T.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;
using namespace	OpenThreads;


const int	MAX_TEST_LOOP	=	1000;

MsgQueueV<Mutex>			varQueue;

class Producer1V : public OpenThreads::Thread
{
	virtual void Run()
	{
		char			varMsg[]	= "abcdefghijklmnopqrstuvwxyz01234567890";
		int				nRangeMin	= 1;
		int				nRangeMax	= strlen(varMsg);

		for( int i = 0; i < MAX_TEST_LOOP; i++ )
		{
			int		nLen	= (float)rand() / (RAND_MAX + 1) * (nRangeMax - nRangeMin);

			if( nLen == 0 || nLen > strlen(varMsg) )
				nLen	= 1;

			varQueue.Push( static_cast<void *>(varMsg), nLen );

			cout << i << " thread #" << this->getThreadId() << " push length " << nLen << endl;
		}

		cout << " thread #" << this->getThreadId() << " completes. " << endl;
	}
};

/**
* @class		Producer that generate void-typed variable message
*/
class Consumer1V : public OpenThreads::Thread
{
	virtual void Run()
	{
		int		i = 0;

		while(1)
		{
			char			varMsg[256]	= {0x00,};
			int				nLen;

			if( varQueue.WaitFront( varMsg, &nLen ))
			{
				varMsg[nLen]	= 0x00;

				cout << i << " thread " << this->getThreadId() << " front length " << nLen << " " << varMsg << endl;
			}
			else
				// if queue is empty then I will wait in the queue
				// so following cout is *NOT* performed.
				cout << i << " thread " << this->getThreadId() << " front " << "fails" << endl;

			i++;
		}
	}
};

void Test3()
{
	cout << "*** Test3 starts ***\n" << endl;

	// seed random number generation
	srand( (unsigned)time( NULL ) );

	Consumer1V*	pC1	= new Consumer1V();
	Consumer1V*	pC2	= new Consumer1V();

	Producer1V*	pP1	= new Producer1V();
	Producer1V*	pP2	= new Producer1V();


	pP1->Start();
	pP2->Start();

	pC1->Start();
	pC2->Start();



	pC1->Join();
	pC2->Join();

	pP1->Join();
	pP2->Join();

	cout << "\n*** Test3 ends ***" << endl;
}


MsgQueue<int, Mutex>		intQueue;
MsgQueue<string, Mutex>		strQueue;

class Producer1 : public OpenThreads::Thread
{
	virtual void Run()
	{
		int				nRangeMin	= 0;
		int				nRangeMax	= MAX_TEST_LOOP;

		for( int i = 0; i < MAX_TEST_LOOP; i++ )
		{
			int		v	= i;	// rand();

			intQueue.Push( v );

			cout << i << " thread #" << this->getThreadId() << " push " << v << endl;
		}

		cout << " thread #" << this->getThreadId() << " completes. " << endl;
	}
};

/**
* @class		Producer that generate void-typed variable message
*/
class Consumer1 : public OpenThreads::Thread
{
	virtual void Run()
	{
		int		i = 0;

		while(1)
		{
			int	v;

			if( intQueue.WaitFront( v ))
				cout << i << " thread " << this->getThreadId() << " front " << v << endl;
			else
				// if queue is empty then I will wait in the queue
				// so following cout is *NOT* performed.
				cout << i << " thread " << this->getThreadId() << " front " << "fails" << endl;

			i++;
		}
	}
};

/**
* @function		Test2
* test multi threads to Front & Pop the built-in data type.
* test result shows that Push & Front functions work rightly.
*/void Test2()
{
	cout << "*** Test2 starts ***\n" << endl;

	// seed random number generation
	srand( (unsigned)time( NULL ) );


	Consumer1*	pC1	= new Consumer1();
	Consumer1*	pC2	= new Consumer1();

	Producer1*	pP1	= new Producer1();
	Producer1*	pP2	= new Producer1();

	pP1->Start();
	pP2->Start();

	pC1->Start();
	pC2->Start();



	pC1->Join();
	pC2->Join();

	pP1->Join();
	pP2->Join();

	cout << "\n*** Test2 ends ***" << endl;
}

/**
* @function		Test1
* test Front & Pop function.
* test result shows that Push & Front functions work rightly.
*/
void Test1()
{
	MsgQueue<string, NullMutex>	strQueue;

	cout << "********************" << endl;
	cout << "*** Test1 starts ***" << endl;

	strQueue.Push(string("I"));
	strQueue.Push(string("love"));
	strQueue.Push(string("you"));

	string	s1;
	
	strQueue.Front( s1 );

	cout << s1 << endl;	// "I"

	strQueue.Front( s1 );

	cout << s1 << endl;	// "love"

	strQueue.Front( s1 );

	cout << s1 << endl;	// "you"

	cout << "*** Test1 ends ***" << endl;
	cout << "******************" << endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	OpenThreads::Thread::Init();

#if		0
	Test1();

	Test2();
#endif

	Test3();

	return 0;
}

