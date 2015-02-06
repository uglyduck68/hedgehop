// ObjectPool.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <Windows.h>
#include <pthread.h>

#include "ObjectPool.h"

void* Consumer(void* pArg)
{
	CObjectPool*	pInstance	= CObjectPool::GetInstance();
	OBJ_TYPE		pFreeObj;

	while(1)
	{
		printf("Debug: %s_%d: try to get free object\n", __FUNCTION__, (int)pArg);

		pInstance->GetFreeObject(pFreeObj);

		if (pFreeObj == NULL)
		{
			printf("Error: %s_%d: fail to get free object\n", __FUNCTION__, (int)pArg);
		}
		else
		{
			printf("Debug: %s_%d: using free object: %0x\n", __FUNCTION__, (int)pArg, pFreeObj);

			Sleep(1000);

			printf("Debug: %s_%d: returned free object: %0x\n", __FUNCTION__, (int)pArg, pFreeObj);
			pInstance->ReturnFreeObject(pFreeObj);
		}
	}

	return NULL;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CObjectPool*	pInstance	= CObjectPool::GetInstance();
	void*	p[10];
	const int	MAX_THREAD	= 3;
	pthread_t	cons[MAX_THREAD];

	for (int i = 0; i < pInstance->GetPoolSize(); i++)
	{
		p[i]	= reinterpret_cast<void*>(i + 1);

		/**
		* Step 1: register the free object
		*/
		pInstance->InsertFreeObject(p[i]);
	}

	for (int i = 0; i < MAX_THREAD; i++)
	{
		if( pthread_create(&cons[i], NULL, Consumer, (void*)i ) != 0 )  
		{
			printf("Error: fail to pthread_create\n");
		}
	}

	// wait for all threads to create
	Sleep(1000);

	printf("Info: main thread waiting for %d threads\n", MAX_THREAD);

	for (int i = 0; i < MAX_THREAD; i++)
		pthread_join(cons[i], NULL);


	printf("Info: end of execution of ObjectPool\n");

	return 0;
}

