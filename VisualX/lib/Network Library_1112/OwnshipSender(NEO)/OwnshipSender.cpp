// OwnshipSender.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "LocationMgr.h"
#include "enLib2.h"

#include <time.h>
LocationMgr Loc;
void SendGPS(int no,bool flag=false)
{
	DMSG_TM_SYSTRACK msg;
	memset(&msg,0,sizeof(DMSG_TM_SYSTRACK));
	int trkno = no;
	int Identity = (rand()%6+1);
	float Speed = (rand()%30+15);
	int LocNo = 0;
	if(no != 0 && flag)
		LocNo = (rand()%19+1);
	else
		LocNo = trkno;
	POS& pos = Loc.GetLocation(LocNo);
	msg.trkNo.trkNo = trkno;

	msg.cTrackIdentity = no == 0 ? 0 : Identity;
	msg.positionCHSys.longitude = pos.x;
	msg.positionCHSys.latitude = pos.y;
	msg.fCourse = 35;
	msg.fRange = 40;
	msg.fSpeed = Speed;
	EnLibrary::Send(&msg);
}
void Send3000(){
	printf("Sending 3000 Target Start \n");
	for(int i=0; i<3000; ++i)
	{
		SendGPS(i+1,true);
	}
	SendGPS(0);
	printf("Sending 3000 Target End \n");
}
void SendTarget(){
	while(1)
	{
		for(int i=1; i< 20;++i)SendGPS(i);
		SendGPS(0);
		Sleep(300);
	}
}

/*CTimer SendTimer;*/
int _tmain(int argc, _TCHAR* argv[])
{
	int cnt = 0;
	EnLibrary::InitializeLibrary<1,1>("*.*.*.*","Reliable");
	EnLibrary::Initialize<1,DMSG_TM_SYSTRACK>();
	EnLibrary::Initialize<1,DMSG_OSSMMI_PLATFORMREQ>([&](DMSG_OSSMMI_PLATFORMREQ* msg)
	{
		printf("OK! Platform Req Cnt : %d!\n",++cnt);
	});
	EnLibrary::Resume();
	char c;
	srand((unsigned int)time(NULL));
	int i=0,j=0;
	bool isRun=true;	//요것 isRun 반드시 변수 처리해야 함
	Sleep(2000);
	while(1){
		c = getchar();
		switch(c)
		{
		case 'q':
			isRun=false;
			return 0;
			break;
		case 's':
			/// 내부에서 사용하는 Timer Thread
			/// Argument : Function,cycle,looper(count)
			/// looper : true,false
			/// counter : number
// 			SendTimer([&](){
// 				Send3000();
// 			},1500,true);
// 			break;
			EnLibrary::AddTask([&](){
				Send3000();
			},1500,isRun);
		case 'l':
			scanf("%d",&j);
			for(int i=0; i<j; ++i)Send3000();
			break;

		}
	}
}

