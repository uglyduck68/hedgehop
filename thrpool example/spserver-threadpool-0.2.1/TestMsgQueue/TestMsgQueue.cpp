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

const int	MAX_SIZE		= 100;
const char	END_PACKET		= 0xff;
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
		nId			= 0;
		nSize		= sizeof(*this);
		caBody[0]	= 0x00;
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
///////////////////////////////////////////////////////////////////////////////
// [Scenario]
//	- Create a receive thread that emulate to receive the packets 
//		from remote TCP/IP application.
//	- This receive thread push the received packet to message queue 
//		in message handler thread.
//	- The message handler thread receive the packet and parse it and assign
//		this packet into any thread in the threadpool.
///////////////////////////////////////////////////////////////////////////////

void	FreePacket(Dummy* pPacket)
{
	if (pPacket->nSize> sizeof(void*))
	{
		free(pPacket);
	}
}

sp_thread_result_t A_PacketHandler(void* pData)
{
	Dummy*	pPacket		= static_cast<Dummy*>(pData);

	// process the packet
	sp_sleep(1);

	printf("%s: ID: %d... is processed\n", __FUNCTION__, pPacket->nId);

	FreePacket(pPacket);

	return NULL;
}

sp_thread_result_t B_PacketHandler(void* pData)
{
	Dummy*	pPacket		= static_cast<Dummy*>(pData);

	// process the packet
	sp_sleep(1);

	printf("%s: ID: %d... is processed\n", __FUNCTION__, pPacket->nId);

	FreePacket(pPacket);

	return NULL;
}

sp_thread_result_t C_PacketHandler(void* pData)
{
	Dummy*	pPacket		= static_cast<Dummy*>(pData);

	// process the packet
	sp_sleep(1);

	printf("%s: ID: %d... is processed\n", __FUNCTION__, pPacket->nId);

	FreePacket(pPacket);

	return NULL;
}

sp_thread_result_t D_PacketHandler(void* pData)
{
	Dummy*	pPacket		= static_cast<Dummy*>(pData);

	// process the packet
	sp_sleep(1);

	printf("%s: ID: %d... is processed\n", __FUNCTION__, pPacket->nId);

	FreePacket(pPacket);

	return NULL;
}

sp_thread_result_t E_PacketHandler(void* pData)
{
	Dummy*	pPacket		= static_cast<Dummy*>(pData);

	// process the packet
	sp_sleep(1);

	printf("%s: ID: %d... is processed\n", __FUNCTION__, pPacket->nId);

	FreePacket(pPacket);

	return NULL;
}

sp_thread_result_t F_PacketHandler(void* pData)
{
	Dummy*	pPacket		= ((Dummy*)pData);

	// process the packet
	sp_sleep(1);

	printf("%s: ID: %d... is processed\n", __FUNCTION__, pPacket->nId);

	FreePacket(pPacket);

	return NULL;
}

/**
* @class	HandlerThread that pop the packet from message queue,
*			parse it, and send handler function and the packet as argument into threadpool.
*/
class HandlerThread : public ThreadWithMsgQueue
{
public:
	HandlerThread()
	{
		m_pPool		= new Threadpool(2);
	}

	~HandlerThread()
	{
		delete m_pPool;
	}

	sp_thread_result_t	Run(Thread* pArg)
	{
		void*	pData	= NULL;
		int		nLen	= 0;

		for(int i = 0; i < MAX_SIZE; i++)
		{
			Pop(&pData, &nLen);

			// parsing the message queue
			switch( ((Dummy*)pData)->nId )
			{
			case 0:
				// I want to insert function and argument into threadpool to process it by thread
				m_pPool->Assign(A_PacketHandler, pData);
				break;
			case 1:
				m_pPool->Assign(B_PacketHandler, pData);
				break;

			case 2:
				m_pPool->Assign(C_PacketHandler, pData);
				break;

			case 3:
				m_pPool->Assign(D_PacketHandler, pData);
				break;

			case 4:
				m_pPool->Assign(E_PacketHandler, pData);
				break;

			default:
				// process packet #5 to #9
				m_pPool->Assign(F_PacketHandler, pData);
				break;
			}

			if( ((Dummy*)pData)->caBody[0]	== END_PACKET)
			{
				// end of thread
				printf("%s: end of thread: The processed packet is %d\n", 
					__FUNCTION__, i+1);
				break;
			}
		}

		return NULL;
	}

protected:
	Threadpool*		m_pPool;
};

#define	MSG_COUNT	10

/**
* @class	ReceiveThread that is emulate the thread that receive the packet 
*			from remote TCP/IP application.
*/
class ReceiveThread : public Thread
{
public:
	sp_thread_result_t	Run(Thread* pArg)
	{
		for(int i = 0; i < MAX_SIZE; i++)
		{
			g_Packet.nId = (i % MSG_COUNT);

			printf("ReceiveThread::Run: Push: %d, count: %d\n", g_Packet.nId, i);

			// push message into queue to handle this message by handler
			// if g_Packet.nSize is more than sizeof(void*), then
			// Push function allocate the memory and copy g_Packet to it.
			// This allocated memory *MUST* be free by user in side of Pop.

			if( i == MAX_SIZE-1 )
			{
				// prepare the last packet
				g_Packet.caBody[0]	= END_PACKET;
			}

#if	0		// Push method test #1
			// Push just assign the address of g_Packet
			// This is useful for user to want just the pointer of packet, 
			// Any malloc and copy operation is *NOT* made.
			m_pHandler->Push(&g_Packet, sizeof(void*));
#endif

#if	0		// Push method test #2
			// g_Packet.nSize > sizeof(void*), so Push method malloc and copy it.
			m_pHandler->Push(&g_Packet, g_Packet.nSize);
#endif
			
#if	1		// Push method test #3
			// This Push method is for just convenient according to the concept of OO.
			m_pHandler->Push(new MsgQueueItem(&g_Packet, g_Packet.nSize));
#endif
			g_Packet.nId++;

			// wait next packet
			sp_sleep(1);
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

	// set packet handler
	RcvThread.Set(&WorkThread);

	///////////////////////////////////////////////////////////////////////////
	// start emulation threads
	///////////////////////////////////////////////////////////////////////////

	// wait the packet
	WorkThread.Start();

	// generate packet and push the packet into the message queue in packet handler
	RcvThread.Start();

	// wait the end of threads
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

