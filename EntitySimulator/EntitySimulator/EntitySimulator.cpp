// EntitySimulator.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <stdio.h>
#include "EnLib2.h"
#include "OPVEnum.h"
#include "Randomized.h"
#include "Mgr/LocationMgr.h"
#include <tchar.h>
void Initialize(){
	EnLibrary::InitializeLibrary<1,1>();
	EnLibrary::Initialize<1,SC_SIM_OWNSHIP>();
	EnLibrary::Initialize<1,SC_SIM_ENTITY>();
	EnLibrary::Initialize<1,SIM_SC_ENTITY_STATE>();
	EnLibrary::Initialize<1,SC_SIM_ENVIRONMENT>();
	EnLibrary::Resume();
}
void Release(){
	EnLibrary::ReleaseLibrary();
}
CRandomized Generator;
LocationMgr Loc;
const int maxidx = 20;
void SendFullInformation(){
	for(int i=1; i<maxidx; i++){
		SC_SIM_ENTITY msg;
		memset(&msg,0,sizeof(SC_SIM_ENTITY));
		POS& pos = Loc.GetLocation(i);
		msg.unEntityID = i;
		msg.nEntityType = OPV::_ENUM_ENTITY_TYPE::SuW;
		msg.nEntityClass = OPV::_ENUM_ENTITY_CLASS::Cruiser;
		msg.stEntityAttribute.dDraft =0;
		msg.stEntityAttribute.dHeight = 0;
		msg.stEntityAttribute.dLength = 40;
		msg.stEntityAttribute.dWeight = 10;
		msg.stEntityAttribute.dWidth = 10;
		msg.stEntityState.stPosition.dLon = pos.x;
		msg.stEntityState.stPosition.dLat = pos.y;
		msg.stEntityState.dCourse = 35;
		msg.stEntityState.dSpeed = 10;
		msg.stEntityState.dHeading = 10;
		msg.stEntityState.dRoll = 10;
		msg.stEntityState.dPitch = 10;
		msg.stIFF.nMode_1 = Generator.get(0,738);
		msg.stIFF.n_Mode_2 = Generator.get(0,77778);
		msg.stIFF.nMode3A = Generator.get(0,77778);
		msg.stIFF.nMode_4 = Generator.get(0,77778);
		EnLibrary::Send(&msg);
	}
}
void SendInformation()
{
	printf("Sending Information!\n");
	for(int i=0; i<maxidx; i++){
		SIM_SC_ENTITY_STATE msg;
		memset(&msg,0,sizeof(SIM_SC_ENTITY_STATE));
		POS& pos = Loc.GetLocation(i);
		msg.unEntityID = i;
		msg.stEntityState.stPosition.dLon = pos.x;
		msg.stEntityState.stPosition.dLat = pos.y;
		msg.stEntityState.dCourse = 35;
		msg.stEntityState.dSpeed = 10;
		msg.stEntityState.dHeading = 10;
		msg.stEntityState.dRoll = 10;
		msg.stEntityState.dPitch = 10;
		EnLibrary::Send(&msg);
	}
}
void SendOwnship()
{
	printf("Sending Ownship Information!\n");

	SC_SIM_OWNSHIP msg;
	memset(&msg,0,sizeof(SC_SIM_OWNSHIP));
	POS& pos = Loc.GetLocation(0);
	msg.unEntityID = 0;
	msg.nEntityType = OPV::_ENUM_ENTITY_TYPE::SuW;
	msg.nEntityClass = OPV::_ENUM_ENTITY_CLASS::Cruiser;
	msg.stEntityAttribute.dDraft =0;
	msg.stEntityAttribute.dHeight = 0;
	msg.stEntityAttribute.dLength = 40;
	msg.stEntityAttribute.dWeight = 10;
	msg.stEntityAttribute.dWidth = 10;

	msg.stEntityState.stPosition.dLon = pos.x;
	msg.stEntityState.stPosition.dLat = pos.y;
	msg.stEntityState.dCourse = 35;
	msg.stEntityState.dSpeed = Generator.get(15.0f,30.0f);
	msg.stEntityState.dHeading = 10;
	msg.stEntityState.dRoll = 10;
	msg.stEntityState.dPitch = 10;
	msg.stIFF.nMode_1 = Generator.get(0,738);
	msg.stIFF.n_Mode_2 = Generator.get(0,77778);
	msg.stIFF.nMode3A = Generator.get(0,77778);
	msg.stIFF.nMode_4 = Generator.get(0,77778);
	EnLibrary::Send(&msg);
}
void SendEnv(){
	printf("Sending Environment Information!\n");

	SC_SIM_ENVIRONMENT msg;
	memset(&msg,0,sizeof(SC_SIM_ENVIRONMENT));
	int envID = Generator.get(1,8);
	msg.nWeather = Generator.get(1,8);
	msg.dTemparature = Generator.get(-12.5,48.9);
	msg.dAirPressure = Generator.get(0.0,30.0);
	msg.dHumidity = Generator.get(0.0,20.0);
	msg.dVisibility = Generator.get(0.0,50.0);
	msg.dWindDirection = Generator.get(0.0,160.0);
	msg.dWindSpeed = Generator.get(0.0,50.0);
	msg.dWaterDirection = Generator.get(0.0,160.0);
	msg.dWaterSpeed = Generator.get(0.0,50.0);
	EnLibrary::Send(&msg);
}
bool isRun;
void SubRoutine()
{
	EnLibrary::AddTask(SendInformation,200,isRun);
	EnLibrary::AddTask([&](){
		SendOwnship();
		SendEnv();
	},500,isRun);
}
int _tmain(int argc, _TCHAR* argv[])
{
	Initialize();
	printf("Send Full Information\n");
	SendFullInformation(); /// Full Data 전송
	printf("Ok! Wait 2sec\n");
	Sleep(2000); /// 2초 대기
	isRun = true;
	SubRoutine();
	system("pause");
	isRun = false;
	Release();
	return 0;
}
