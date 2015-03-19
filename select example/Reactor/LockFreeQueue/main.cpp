// LockFreeQueue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "LockFreeQueue.h"
#include "CpuUsage.h"
#include "Time.h"

#include <pthread.h>

/********************************************************************
 * Lock Free Queue Test
 *
 * Scenario
 *	1. each producer push MAX_DATA data into Q.
 *	2. one consumer pop MAX_DATA data * number of producer from Q.
 *	3. measure run time and CPU usage every 1 second.
 *	4. compare the result of LockFreeQueues and normal locked queue.
 *******************************************************************/

LockFreeQueue			g_Q;

int				g_bEndFlag	= false;
const int		MAX_THREAD	= 4;//1;	// max. of producer. default is 4.
									// set to 1 if you want validation test
const int		SLEEP_TIME	= 1000;	// 1 sec
const int		MAX_DATA	= 10000000;

void* Producer(void* pArg)
{
	OBJ_TYPE	data;
	int			nId	= (int)pArg;	// pArg MUST less than MAX_THREAD
	int			Data[MAX_THREAD]	= {0,};


	for (; Data[nId] < MAX_DATA; Data[nId]++)
	{
		data	= (OBJ_TYPE)Data[nId];

		g_Q.push(data);
	}

	return NULL;
}

void* Consumer(void* pArg)
{
	int			NoData	= 0;
	OBJ_TYPE	data;

	while(1)
	{
		if (g_Q.pop(data) == -1)
		{
			printf("Error: fail to pop because Q is empty\n");
			continue;
		}

		NoData++;

		if (NoData == MAX_DATA * MAX_THREAD)
			break;
	}

	// notify that everythign is end
	g_bEndFlag		= true;

	return NULL;
}

/**
 * @function		ConsumerForValidation
 * @brief			thread to validate the input to Q
 * @remark			*MUST* use one producer
 */
void* ConsumerForValidation(void* pArg)
{
	int			NoData	= 0;
	OBJ_TYPE	data;	//< data is start from 0
	OBJ_TYPE	OldData	= (OBJ_TYPE)-1;

	while(1)
	{
		if (g_Q.pop(data) == -1)
		{
			printf("Error: fail to pop because Q is empty\n");
			continue;
		}

		NoData++;

		if (NoData == MAX_DATA * MAX_THREAD)
			break;

		if (((int)data - (int)OldData) != 1)
		{
			printf("Error: invalide data: %d, %d\n", data, OldData);
		}

		OldData		= data;
	}

	// notify that everythign is end
	g_bEndFlag		= true;

	return NULL;
}

/**
 * @function		CheckCPUUsage
 * @brief			thread function to calculate the average of CPU usage percentile
 */
void* CheckCPUUsage(void* pArg)
{
	CPUUsage	Usage;
	int			UsageTotal		= 0;
	int			UsageCount		= 0;

	while(!g_bEndFlag)
	{
		// get cpu usage
		UsageTotal		+= Usage.GetUsage();
		UsageCount++;

		// sleep 1 sec
		Sleep (SLEEP_TIME);
	}
		
	printf("average CPU usage percentile: %d\n", UsageTotal / UsageCount);

	return NULL;
}

int _tmain(int argc, _TCHAR* argv[])
{

	pthread_t	PId[MAX_THREAD + 2];

	struct timeval	start, end;

	Time::gettimeofday(&start, NULL);

	printf("Info: # of producer thread: %d, # of consumer thread: 1, # of data per producer: %d\n", MAX_THREAD, MAX_DATA);
	printf("Info: start time is %d seconds.\n", start.tv_sec);

	if (pthread_create(&PId[MAX_THREAD+1], NULL, CheckCPUUsage, NULL) != 0)
	{
		printf("Error: fail to pthread_create (Consumer)\n");
	}

	for (int i = 0; i < MAX_THREAD; i++)
	{
		if (pthread_create(&PId[i], NULL, Producer, (void*)i) != 0)
		{
			printf("Error: fail to pthread_create (Producer)\n");
		}
	}

#if	1	// 1 if validation test
	printf("Info: Validation Test\n");

	if (pthread_create(&PId[MAX_THREAD], NULL, ConsumerForValidation, NULL) != 0)
	{
		printf("Error: fail to pthread_create (Consumer)\n");
	}
#else
	if (pthread_create(&PId[MAX_THREAD], NULL, Consumer, NULL) != 0)
	{
		printf("Error: fail to pthread_create (Consumer)\n");
	}
#endif
	for (int i = 0; i < MAX_THREAD + 2; i++)
	{
		pthread_join (PId[i], NULL);
	}

	Time::gettimeofday(&end, NULL);

	printf("Info:   end time is %d seconds.\n\trunning-time is %d seconds.\n", end.tv_sec, end.tv_sec - start.tv_sec);

	return 0;
}