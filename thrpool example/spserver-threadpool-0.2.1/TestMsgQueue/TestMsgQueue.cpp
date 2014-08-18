// TestMsgQueue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MsgQueue_T.h"
#include "Mutex.h"
#include "Thread.h"

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

int _tmain(int argc, _TCHAR* argv[])
{
	TestMsgQueue_T();
	return 0;
}

