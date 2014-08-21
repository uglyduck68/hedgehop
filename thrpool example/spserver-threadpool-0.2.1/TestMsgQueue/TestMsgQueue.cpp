// TestMsgQueue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MsgQueue_T.h"
#include "Mutex.h"
#include "Thread.h"
#include "ThreadWithMsgQueue.h"
#include "threadpool.h"

NS_X1_USE

/******************************************************************************
 * test message queue
 *****************************************************************************/
 int i;
/// step 0: create thread-safe message queue. use MutexNull object in case of single thread.
MsgQueue<MsgQueueItem*, Mutex>		g_MsgQ;

const int	MAX_SIZE		= 1000;

/**
* general message emulation for general network application
*/
typedef struct tagDummy
{
	int		nId;		// message id
	int		nSize;		// message size
	char	caBody[10];	// message body

	tagDummy()
	{
		nId		= 0;
		nSize	= sizeof(*this);
	}
} Dummy;

Dummy	g_Packet;

class P1 : public Thread
{
public:
	sp_thread_result_t	Run(Thread* pArg)
	{
		MsgQueueItem*	pData;

		for(int i = 0; i < MAX_SIZE; i++)
		{
			pData	= new MsgQueueItem(&g_Packet, g_Packet.nSize);	g_Packet.nId++;

			g_MsgQ.Push(pData);

			printf("P1: push: work ID: %d\n", ((tagDummy*)pData->pUsrData)->nId);
		}
		return NULL;
	}
};

class P2 : public Thread
{
public:
	sp_thread_result_t	Run(Thread* pArg)
	{
		MsgQueueItem*	pData;

		for(int i = 0; i < MAX_SIZE; i++)
		{
			pData	= new MsgQueueItem(&g_Packet, g_Packet.nSize);	g_Packet.nId++;

			g_MsgQ.Push(pData);

			printf("P2: push: work ID: %d\n", ((tagDummy*)pData->pUsrData)->nId);
		}
		return NULL;
	}
};

class C1 : public Thread
{
public:
	sp_thread_result_t	Run(Thread* pArg)
	{
		MsgQueueItem*	pData;

		for(int i = 0; i < MAX_SIZE; i++)
		{
			pData	= g_MsgQ.Pop();

			if (pData == NULL)
				printf("C1: work ID: NULL\n");
			else
				printf("C1: work ID: %d\n", ((tagDummy*)pData->pUsrData)->nId);
		}

		return NULL;
	}
};

class C2 : public Thread
{
public:
	sp_thread_result_t	Run(Thread* pArg)
	{
		MsgQueueItem*	pData;

		for(int i = 0; i < MAX_SIZE; i++)
		{
			pData	= g_MsgQ.Pop();

			if (pData == NULL)
				printf("C2: work ID: NULL\n");
			else
				printf("C2: work ID: %d\n", ((tagDummy*)pData->pUsrData)->nId);
		}
		return NULL;
		
	}
};


///////////////////////////////////////////////////////////////////////////////
// Test MsgQueue_T class
///////////////////////////////////////////////////////////////////////////////

int	TestMsgQueue_T()
{
	P1	p1;
	P2  p2;
	C1	c1;
	C2  c2;

	/// step 0: create thread-safe message queue
	/// step 1: create producer threads
	if (p1.Start() != 0)
	{
		printf("Error: fail to create P1\n");

		return -1;
	}

	if (p2.Start() != 0)
	{
		printf("Error: fail to create P1\n");

		return -1;
	}
	/// step 2: create consumer threads
	if (c1.Start() != 0)
	{
		printf("Error: fail to create P1\n");

		return -1;
	}

	if (c2.Start() != 0)
	{
		printf("Error: fail to create P1\n");

		return -1;
	}

	/// step 3: producer send message to consumer via message queue
	/// step 4: check the consumer receive all messages from producer

	p1.Join();
	p2.Join();
	c1.Join();
	c2.Join();

	printf("Info: end of message queue test. queue size: %d\n", g_MsgQ.Size());

	return 0;
}

///////////////////////////////////////////////////////////////////////////////
// Test ThreadWithMsgQueue class
// [Scenario]
//	- Create a receive thread that emulate to receive the packets 
//		from remote TCP/IP application.
//	- This receive thread push the received packet to message queue 
//		in message handler thread.
//	- The message handler thread receive the packet and parse it and assign
//		this packet into any thread in the threadpool.
///////////////////////////////////////////////////////////////////////////////
int a(void* pData, int nLen)
{
	return 1;
}

class HandlerThread : public ThreadWithMsgQueue
{
public:
	sp_thread_result_t	Run(Thread* pArg)
	{
		void*	pData;
		int		nLen;

		for(int i = 0; i < MAX_SIZE; i++)
		{
			Pop(&pData, &nLen);

			// parsing the message queue
			switch( ((Dummy*)pData)->nId )
			{
			case 0:
				// I want to insert function and argument into threadpool to process it by thread
				a(pData, nLen);
				break;
			case 1:
				break;

			case 2:
				break;

			case 3:
				break;

			case 4:
				break;

			case 5:
				break;
			}
		}

		return NULL;
	}
};

#define	MSG_COUNT	10

class ReceiveThread : public Thread
{
public:
	sp_thread_result_t	Run(Thread* pArg)
	{
		MsgQueueItem*	pData;

		for(int i = 0; i < MAX_SIZE; i++)
		{
			g_Packet.nId = (i % MSG_COUNT);

			// push message into queue to handle this message by handler
			m_pHandler->Push(&g_Packet, g_Packet.nSize);
		}
		return NULL;
	}

	void Set(HandlerThread* pThread)
	{
		m_pHandler	= pThread;
	}

protected:
	HandlerThread*	m_pHandler;	// point to handler thread
};

int TestThreadWithMesQueue()
{
	ReceiveThread	RcvThread;
	HandlerThread	WorkThread;

	RcvThread.Set(&WorkThread);

	WorkThread.Start();
	RcvThread.Start();


	RcvThread.Join();
	WorkThread.Join();

	return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{
#if	0
	TestMsgQueue_T();
#endif

	TestThreadWithMesQueue();

	return 0;
}

