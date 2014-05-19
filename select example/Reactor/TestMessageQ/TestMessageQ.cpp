/**
 * This test the functionality of Message Queue with OpenThread library
 * And add the function to test Thread class.
 */
// TestMessageQ.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <OpenThreads/Thread.h>
//#include "../Reactor/Types.h"
#include "../Reactor/MsgQueue_T.h"
#include "../Reactor/Mutex.h"

using namespace X1;

int			g_nId	= 0;
const int	g_Iteration	= 10000;
Mutex		g_Mutex;


/// define Item class that is used to push/pop to Queue
class Item
{
public:
	int		m_nId;

	Item()
	{
		m_nId	= g_nId;

		g_Mutex.Lock();
		g_nId++;
		g_Mutex.Unlock();
	}
};

/// define Producer class
class Producer : public OpenThreads::Thread
{
public:
	/// I don't know why X1 namespace is specified explicitly
	/// Perhaps MsgQueue name conflict?
	X1::MsgQueue<Item*, Mutex>& m_Queue;

	virtual void Run()
	{
	}
};

/// define Consumer class
class Consumer : public OpenThreads::Thread
{
public:
	int		m_nEnd;

	Consumer(X1::MsgQueue<Item*, Mutex>& Queue) : m_Queue(Queue)
	{
	}

	/// I don't know why X1 namespace is specified explicitly
	/// Perhaps MsgQueue name conflict?
	X1::MsgQueue<Item*, Mutex>& m_Queue;

	virtual void Run()
	{
		Item*	pItem	= NULL;

		while(1)
		{
			pItem		= m_Queue.Pop();

			//if ((pItem->m_nId % 100) == 0)
//			printf("Thread: %d,   Item: %d\n", this->getThreadId(), pItem->m_nId);

			// compare end condition for only 2 threads.
			// this sample application use 2 threads.
			// if you use 3 threads, end condition is 3 comparision.
			if (pItem->m_nId == g_Iteration - 1 || pItem->m_nId == g_Iteration - 2)
			{
				printf("Thread: %d, end\n", this->getThreadId());
				break;
			}
		}
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	OpenThreads::Thread::Init();

	X1::MsgQueue<Item*, Mutex>	Queue;

	Consumer*	pConsumer1	= new Consumer(Queue);
	Consumer*	pConsumer2	= new Consumer(Queue);

	pConsumer1->start();
	pConsumer2->start();

	Item*	pItem;

	FILETIME		tm1, tm2;
	GetSystemTimeAsFileTime(&tm1);

	// produce work items
	for(int i = 0; i < g_Iteration; i++)
	{
		pItem	= new Item();

		Queue.Push(pItem);

		//pItem	= new Item();

		//Queue.Push(pItem);

		if ((pItem->m_nId % 100) == 0)
			printf("Main thread produce Item: %d\n", pItem->m_nId);
	}

//	printf("Main thread enter join\n");

	pConsumer1->join();
	pConsumer2->join();

	GetSystemTimeAsFileTime(&tm2);

	printf("Main thread end, elapsed: %d\n", tm2.dwLowDateTime - tm1.dwLowDateTime);

	return 0;
}

