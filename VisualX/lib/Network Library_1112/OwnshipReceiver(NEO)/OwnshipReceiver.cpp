// OwnshipReceiver.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "EnLib2.h"

#include <windows.h>

std::vector<long> g_count(3);
DWORD dwTime;
std::vector<std::vector<long>> g_vList;

void writeLog()
{
	DWORD dwLog = GetTickCount() - dwTime;

	char path[255] = { 0x00,};
	sprintf(path,"./log_%ld.csv",dwLog);

	FILE* fp= fopen(path,"w");
	int sz = g_vList.size();

	std::vector<std::vector<long>>::iterator iter = g_vList.begin();
	int i=1;
	for(auto iter = g_vList.begin(); iter != g_vList.end(); ++iter,++i)
	{
		fprintf(fp,"%d,%d,%d,%d\n",i,(*iter)[0],(*iter)[1],(*iter)[2]);
	}
	fclose(fp);
	dwTime = 0;
}

bool	bIsRun	= true;	//< flag to control the execution of Timer function

/**
 * @function		Timer
 * @remarks			this timer is executed by separated thread
 */
void Timer()
{
	static int		loop	= 0;
	SYSTEMTIME		t;

	GetSystemTime( &t );

	printf("loop: %d, Curr time: %d:%d:%d.%d\n", loop, t.wHour, t.wMinute, t.wSecond, t.wMilliseconds);

	if( loop++ > 10 )
	{
		// send signal to stop timer
		printf("reset timer\n");

		bIsRun	= false;
	}
};


/**
 * @function		ThreadSample
 * @remarks			thread function sample
 */
void ThreadSample()
{
	while(1)
	{
		printf("%s is called\n", __FUNCTION__);

		Sleep(1500);
	};
}

int _tmain(int argc, _TCHAR* argv[])
{
	bool isLog = false;
	dwTime = 0;

	//////////////////////////////////////////////////////////////////////////////
	// Step 1:
	//	- initialize DDS library
	//////////////////////////////////////////////////////////////////////////////
	EnLibrary::InitializeLibrary<1,1>("*.*.*.*","Reliable");

	g_vList.reserve(3000);
	//////////////////////////////////////////////////////////////////////////////
	// Step 2-1:
	//	- declare the DMSG_OSSMMI_PLATFORMREQ for PUB
	//////////////////////////////////////////////////////////////////////////////
	EnLibrary::Initialize<1, DMSG_OSSMMI_PLATFORMREQ>();

	//////////////////////////////////////////////////////////////////////////////
	// Step 2-1:
	//	- declare sub callback for DMSG_TM_SYSTRACK using lambda function
	//////////////////////////////////////////////////////////////////////////////
	EnLibrary::Initialize<1,DMSG_TM_SYSTRACK>([&](DMSG_TM_SYSTRACK* msg)
	{		
		if(msg == NULL) return;
		if(dwTime == 0 && msg->trkNo.trkNo != 0){
			dwTime = GetTickCount();
			g_vList.clear();
		}
		g_count[0] = EnLibrary::GetDDSBufferSize();
		g_count[1] = EnLibrary::GetDDSBufferSize2();
		g_count[2] = msg->trkNo.trkNo;
		printf("[%d,%d]TM_SYSTRACK Lon : %f Lat : %f TargetNo : %d \n",g_count[0],g_count[1],msg->positionCHSys.longitude,msg->positionCHSys.latitude,g_count[2]);
		if(msg->trkNo.trkNo != 0 && isLog)
		g_vList.push_back(g_count);

		///////////////////////////////////////////////////////////////////////
		// Pub DMSG_OSSMMI_PLATFORMREQ for echo
		///////////////////////////////////////////////////////////////////////
		DMSG_OSSMMI_PLATFORMREQ req;
		memset(&req,0,sizeof(DMSG_OSSMMI_PLATFORMREQ));
		EnLibrary::Send(&req);

	});

	//////////////////////////////////////////////////////////////////////////////
	// Step 3:
	//	- activate internal threads for PUB
	//////////////////////////////////////////////////////////////////////////////
	EnLibrary::Resume();


	///////////////////////////////////////////////////////////////////////////
	// Library Sample Code Snippet
	//	- register timer with 1500 ms periodic
	///////////////////////////////////////////////////////////////////////////
	EnLibrary::AddTask([&]()
	{
		// How can I send the parameters to TImer function?
		Timer();
	}, 1500, bIsRun);

	///////////////////////////////////////////////////////////////////////////
	// Library Sample Code Snippet
	//	- register thread function that AddTask has internal threadpool
	///////////////////////////////////////////////////////////////////////////
	EnLibrary::AddTask([&]()
	{
		ThreadSample();
	});

	char c;

	printf("enter command('s', 'e', 'q', 'i') : ");

	while(1)
	{
		c = getchar();
		switch(c)
		{
		case 's':
			isLog = true;
			break;
		case 'e':
			isLog = false;
			break;
		case 'q':
			writeLog();
			return 0;
		case 'i':
			writeLog();
			break;
		}
	}

	//////////////////////////////////////////////////////////////////////////////
	// Step 4:
	//	- finalize DDS library
	//////////////////////////////////////////////////////////////////////////////
	EnLibrary::ReleaseLibrary();
}
