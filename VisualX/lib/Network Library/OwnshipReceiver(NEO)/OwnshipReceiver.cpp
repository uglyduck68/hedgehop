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

int _tmain(int argc, _TCHAR* argv[])
{
	bool isLog = false;
	dwTime = 0;
	EnLibrary::InitializeLibrary<1,1>("*.*.*.*","Reliable");

	g_vList.reserve(3000);
	/// SUB
	EnLibrary::Initialize<1,DMSG_OSSMMI_PLATFORMREQ>();
	/// PUB
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
		/// echo! 
		DMSG_OSSMMI_PLATFORMREQ req;
		memset(&req,0,sizeof(DMSG_OSSMMI_PLATFORMREQ));
		EnLibrary::Send(&req);

	});
	/// 내부 스레드 활성화 PUB할경우 필요
	EnLibrary::Resume();
	char c;
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
		case 'l':
			writeLog();
			break;
		}
	}
	EnLibrary::ReleaseLibrary();
}
