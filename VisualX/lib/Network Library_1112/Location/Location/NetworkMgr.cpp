#include "StdAfx.h"
#include "NetworkMgr.h"
#include "EnLib2.h"

CNetworkMgr::CNetworkMgr(void) : cnt(0)
{
	Init();
}

void CNetworkMgr::Init()
{
	EnLibrary::InitializeLibrary<1,1>("*.*.*.*","Reliable");
	EnLibrary::Initialize<1,DMSG_TM_SYSTRACK>();
	EnLibrary::Initialize<1,DMSG_OSSMMI_PLATFORMREQ>([&](DMSG_OSSMMI_PLATFORMREQ* msg)
	{
		printf("OK! Platform Req Cnt : %d!\n",++cnt);
	});
}
void CNetworkMgr::Release()
{
	EnLibrary::ReleaseLibrary<1>();
}
void CNetworkMgr::Start()
{
	EnLibrary::Resume();
}
void CNetworkMgr::Pause()
{
	EnLibrary::Suspend();
}
void CNetworkMgr::SendGPS(int no,bool flag)
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
void CNetworkMgr::Send3000()
{
	auto SendTarget = [&]()
	{
		int i =0;
		while(i <= 3000){
			SendGPS(++i,true);
			Sleep(0.3);
		}
	};
	auto SendOwnship = [&]()
	{
		SendGPS(0);
		Sleep(300);
	};
	EnLibrary::AddTask([&]()
		{
			EnLibrary::AddTask(SendTarget);
			EnLibrary::AddTask(SendOwnship);
		});
}
CNetworkMgr::~CNetworkMgr(void)
{
	Release();
}
