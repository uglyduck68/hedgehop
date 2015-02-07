// EntitySimulator.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <stdio.h>
#include "EnLib2.h"
#include "OPVEnum.h"
#include "Randomized.h"
#include "Mgr/LocationMgr.h"
#include <tchar.h>
void Initialize(){
	EnLibrary::InitializeLibrary<DOMAIN_ID,1>();
	EnLibrary::Initialize<DOMAIN_ID,SC_SIM_OWNSHIP>();
	EnLibrary::Initialize<DOMAIN_ID,SC_SIM_OWNSHIP_STATE>();
	EnLibrary::Initialize<DOMAIN_ID,SC_SIM_ENTITY>();
	EnLibrary::Initialize<DOMAIN_ID,SC_SIM_ENTITY_STATE>();
	EnLibrary::Initialize<DOMAIN_ID,SC_SIM_ENVIRONMENT>();
	EnLibrary::Resume();
}
void Release(){
	EnLibrary::ReleaseLibrary();
}
CRandomized Generator;
LocationMgr Loc;
const int maxidx = 20;
void SendFullInformation(){
	SC_SIM_OWNSHIP msg;
	memset(&msg,0,sizeof(SC_SIM_OWNSHIP));
	POS& pos = Loc.GetLocation(0);
	msg.nEntityID = 0;
	msg.stEntityInfo.ulType = OPV::_ENUM_ENTITY_TYPE::SuW;
	msg.stEntityInfo.ulPlatformClass = OPV::_ENUM_ENTITY_CLASS::Cruiser;
	msg.stEntityAttribute.fHeight = 0;
	msg.stEntityAttribute.fLength = 40;
	msg.stEntityAttribute.fWeight = 10;
	msg.stEntityAttribute.fWidth = 10;
	msg.stEntityAttribute.fMaxAcceleration = 5;
	msg.stEntityAttribute.fMaxSpeed = 35;
	msg.stEntityAttribute.fMaxAltitude = 180;
	msg.stEntityAttribute.fMaxHealthPoint = 100;
	msg.stEntityState.stPosition.dLon = pos.x;
	msg.stEntityState.stPosition.dLat = pos.y;
	msg.stEntityState.fCourse = 35;
	msg.stEntityState.fSpeed = 10;
	msg.stEntityState.fHeading = 10;
	msg.stEntityState.fRoll = 10;
	msg.stEntityState.fPitch = 10;
	msg.stEntityInfo.nMode1 = Generator.get(0,738);
	msg.stEntityInfo.nMode2 = Generator.get(0,77778);
	msg.stEntityInfo.nMode3A = Generator.get(0,77778);
	msg.stEntityInfo.nMode4 = Generator.get(0,77778);
	EnLibrary::Send(&msg);

	for(int i=1; i<maxidx; i++){
		SC_SIM_ENTITY msg;
		memset(&msg,0,sizeof(SC_SIM_ENTITY));
		POS& pos = Loc.GetLocation(i);
		msg.nEntityID = i;
		msg.stEntityInfo.ulType = OPV::_ENUM_ENTITY_TYPE::SuW;
		msg.stEntityInfo.ulPlatformClass = OPV::_ENUM_ENTITY_CLASS::Cruiser;
		msg.stEntityAttribute.fHeight = 0;
		msg.stEntityAttribute.fLength = 40;
		msg.stEntityAttribute.fWeight = 10;
		msg.stEntityAttribute.fWidth = 10;
		msg.stEntityAttribute.fMaxAcceleration = 5;
		msg.stEntityAttribute.fMaxSpeed = 35;
		msg.stEntityAttribute.fMaxAltitude = 180;
		msg.stEntityAttribute.fMaxHealthPoint = 100;
		msg.stEntityState.stPosition.dLon = pos.x;
		msg.stEntityState.stPosition.dLat = pos.y;
		msg.stEntityState.fCourse = 35;
		msg.stEntityState.fSpeed = 10;
		msg.stEntityState.fHeading = 10;
		msg.stEntityState.fRoll = 10;
		msg.stEntityState.fPitch = 10;
		msg.stEntityInfo.nMode1 = Generator.get(0,738);
		msg.stEntityInfo.nMode2 = Generator.get(0,77778);
		msg.stEntityInfo.nMode3A = Generator.get(0,77778);
		msg.stEntityInfo.nMode4 = Generator.get(0,77778);
		EnLibrary::Send(&msg);
	}
}
void SendInformation()
{
	printf("Sending Information!\n");
	for(int i=0; i<maxidx; i++){
		SC_SIM_ENTITY_STATE msg;
		memset(&msg,0,sizeof(SC_SIM_ENTITY_STATE));
		POS& pos = Loc.GetLocation(i);
		msg.nEntityID = i;
		msg.stEntityState.stPosition.dLon = pos.x;
		msg.stEntityState.stPosition.dLat = pos.y;
		msg.stEntityState.fCourse = 35;
		msg.stEntityState.fSpeed = 10;
		msg.stEntityState.fHeading = 10;
		msg.stEntityState.fRoll = 10;
		msg.stEntityState.fPitch = 10;
		EnLibrary::Send(&msg);
	}
}
void SendOwnshipInformation()
{
	printf("Sending Ownship Information!\n");
	SC_SIM_OWNSHIP_STATE msg;
	memset(&msg,0,sizeof(SC_SIM_OWNSHIP_STATE));
	POS& pos = Loc.GetLocation(0);
	msg.nEntityID = 0;
	msg.stEntityState.stPosition.dLon = pos.x;
	msg.stEntityState.stPosition.dLat = pos.y;
	msg.stEntityState.fCourse = 35;
	msg.stEntityState.fSpeed = 10;
	msg.stEntityState.fHeading = 10;
	msg.stEntityState.fRoll = 10;
	msg.stEntityState.fPitch = 10;
	EnLibrary::Send(&msg);
}

void SendEnv(){
	printf("Sending Environment Information!\n");

	SC_SIM_ENVIRONMENT msg;
	memset(&msg,0,sizeof(SC_SIM_ENVIRONMENT));
	int envID = Generator.get(1,8);
	msg.nWeather = Generator.get(1,8);
	msg.fTemparature = Generator.get(-12.5,48.9);
	msg.fAirPressure = Generator.get(0.0,30.0);
	msg.fHumidity = Generator.get(0.0,20.0);
	msg.fVisibility = Generator.get(0.0,50.0);
	msg.fWindDirection = Generator.get(0.0,160.0);
	msg.fWindSpeed = Generator.get(0.0,50.0);
	msg.fWaterDirection = Generator.get(0.0,160.0);
	msg.fWaterSpeed = Generator.get(0.0,50.0);
	EnLibrary::Send(&msg);
}
bool isRun;
void SubRoutine()
{
	EnLibrary::AddTask(SendInformation,500,isRun);
	EnLibrary::AddTask(SendOwnshipInformation,500,isRun);
	EnLibrary::AddTask(SendEnv,200,isRun);
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
