// TestContainer.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include "X1.h"
#include "ListQueue_T.h"
#include "MsgQueue_T.h"
#include "Mutex.h"
#include "MutexNull.h"
#include "Cond.h"
#include "Thread.h"

#include <memory>

using namespace X1;
using namespace std;

struct QDATA
{
	void*		pUsrData;
	int			nWorkID;
	int			nLen;

	QDATA()
	{
		nWorkID		= nLen	= -1;
		pUsrData			= NULL;
	}

	void	Fini()
	{
		if (pUsrData)
		{
			free(pUsrData);

			pUsrData	= NULL;
		}
	}

	~QDATA()
	{
		Fini();
	}

	int Set(QDATA* pData)
	{
		return Set(pData->nWorkID, pData->nLen, pData->pUsrData);
	}

	int	Set(int WorkID, int Len, const void* pData)
	{
		nWorkID		= WorkID;
		nLen		= Len;

		if (Len <= 0)
			pUsrData		= NULL;
		else
		{
			// malloc do memory allocation if Len is 0
			pUsrData			= malloc(Len);

			if (pUsrData)
			{
				// FIXME: memcpy have a big overload
				memcpy(pUsrData, pData, nLen);

				return 1;	// success
			}

			if (pUsrData)
				free(pUsrData);

			return -1;	// fail
		}

		return 1;		// success
	}

	void	Clear()
	{
		Fini();
	}
};

/******************************************************************************
 * test list type queue that is *NOT* thread-safe.
 * this queue will be modified to support thread-safe.
 *****************************************************************************/
int	TestListQueue_T()
{
	int			n	= ListQueue<QDATA>::GetMaxLength();
	ListQueue<QDATA>	MyQ;
	QDATA*		pUsr;

	/**
	 * testcase 1
	 *	basic enqueue test
	 */
	if (n > 0)
	{
		/// pUsr must be deleted by delete [] operator !!!
		/// so pUsr isn't be delete in ListQueue.
		pUsr	= new (nothrow)QDATA[n];

		if (pUsr == NULL)
		{
			printf("Error: fail to new\n");
			return -1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		pUsr[i].nWorkID		= i;

		/**
		 * testcase 2
		 *	user data malloc & free test
		 */

		pUsr[i].nLen		= 100;
		pUsr[i].pUsrData	= malloc(100);

		if (MyQ.Enqueue(&pUsr[i]) < 0)
		{
			printf("Error: fail to enqueue the data[%d]\n", i);
			break;
		}
	}
	/**
	* testcase 3
	*	test of front
	*/
	for (int j = 0; j < 50; j++)
	{
		QDATA*	tmp;

		if (MyQ.Dequeue(tmp) > 0)
			printf("front(%d): work ID: %d, Len: %d\n", j, tmp->nWorkID, tmp->nLen);
		else
			printf("front(%d): queue is empty%d\n", j);

		/*
		* I use tmp
		*/

		// free pUsrData
		tmp->Clear();
	}

	delete [] pUsr;

	MyQ.Debug();

	// delete all data
	MyQ.DeleteAll();

	return X1_OK;
}


/******************************************************************************
 * test message queue
 *****************************************************************************/

/// step 0: create thread-safe message queue. use MutexNull object in case of single thread.
MsgQueue<QDATA, Mutex/*MutexNull*/>		g_MsgQ;

const int	MAX_SIZE		= 1000;

static void*	P1(void* pArg)
{
	X1_TRACE();

	QDATA*	pData;

	for(int i = 0; i < MAX_SIZE; i++)
	{
		pData	= new QDATA;

		pData->nWorkID	= i;

		g_MsgQ.Push(pData);

		printf("P1: push: work ID: %d\n", pData->nWorkID);
	}
	return NULL;
}

static void*	P2(void* pArg)
{
	X1_TRACE();
	QDATA*	pData;

	for(int i = 0; i < MAX_SIZE; i++)
	{
		pData	= new QDATA;

		pData->nWorkID	= MAX_SIZE + i;

		g_MsgQ.Push(pData);

		printf("P2: push: work ID: %d\n", pData->nWorkID);
	}
	return NULL;
}

static void*	C1(void* pArg)
{
	X1_TRACE();
	QDATA*	pData;

	for(int i = 0; i < MAX_SIZE; i++)
	{
		pData	= g_MsgQ.Pop();

		if (pData == NULL)
			printf("C1: work ID: NULL\n");
		else
			printf("C1: work ID: %d\n", pData->nWorkID);
	}

	return NULL;
}

static void*	C2(void* pArg)
{
	X1_TRACE();
	QDATA*	pData;

	for(int i = 0; i < MAX_SIZE; i++)
	{
		pData	= g_MsgQ.Pop();

		if (pData == NULL)
			printf("C2: work ID: NULL\n");
		else
			printf("C2: work ID: %d\n", pData->nWorkID);
	}
	return NULL;
}

int	TestMsgQueue_T()
{
	Thread	p1, p2;
	Thread	c1, c2;

	/// step 0: create thread-safe message queue
	/// step 1: create producer threads
	if (p1.Start(P1, NULL) != X1_OK)
	{
		printf("Error: fail to create P1\n");

		return -1;
	}

	if (p2.Start(P2, NULL) != X1_OK)
	{
		printf("Error: fail to create P1\n");

		return -1;
	}
	/// step 2: create consumer threads
	if (c1.Start(C1, NULL) != X1_OK)
	{
		printf("Error: fail to create P1\n");

		return -1;
	}

	if (c2.Start(C2, NULL) != X1_OK)
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

	return X1_OK;
}

int _tmain(int argc, _TCHAR* argv[])
{
#if 0
	TestListQueue_T();
#endif

#if 1
	TestMsgQueue_T();
#endif

	return 0;
}

