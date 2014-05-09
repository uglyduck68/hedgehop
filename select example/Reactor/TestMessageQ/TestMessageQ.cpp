/**
 * This test the functionality of Message Queue with OpenThread library
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

	virtual void run()
	{
	}
};

/// define Consumer class
class Consumer : public OpenThreads::Thread
{
public:
	Consumer(X1::MsgQueue<Item*, Mutex>& Queue) : m_Queue(Queue)
	{
	}

	/// I don't know why X1 namespace is specified explicitly
	/// Perhaps MsgQueue name conflict?
	X1::MsgQueue<Item*, Mutex>& m_Queue;

	virtual void run()
	{
		Item*	pItem	= NULL;

		while(1)
		{
			pItem		= m_Queue.Pop();

			printf("Thread: %d,   Item: %d\n", this->getThreadId(), pItem->m_nId);

			if (pItem->m_nId == g_Iteration)
				break;
		}
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	OpenThreads::Thread::Init();

	X1::MsgQueue<Item*, Mutex>	Queue;

	Consumer*	pConsumer1	= new Consumer(Queue);
	Consumer*	pConsumer2	= new Consumer(Queue);

	Item*	pItem;

	for(int i = 0; i < g_Iteration; i++)
	{
		pItem	= new Item();

		Queue.Push(pItem);

		pItem	= new Item();

		Queue.Push(pItem);
	}

	pConsumer1->join();
	pConsumer2->join();

	return 0;
}

