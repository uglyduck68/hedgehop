// EntitySimulator.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <stdio.h>
#include "EnLib2.h"
#include "OPVEnum.h"
#include "Randomized.h"
#include "Mgr/LocationMgr.h"
#include <tchar.h>
void CallbackFullInformation(SC_SIM_ENTITY* msg)
{
	printf("[Entity Info] ");
	printf("Entity ID : %d, Entity Class : %d, Entity Type :%d Name : %s\n",msg->unEntityID,msg->nEntityClass,msg->nEntityType,msg->chName);
	printf("Draft : %f, Height : %f Length : %f Weight :%f Width : %f \n",msg->stEntityAttribute.dDraft,msg->stEntityAttribute.dHeight,msg->stEntityAttribute.dLength,msg->stEntityAttribute.dWeight,msg->stEntityAttribute.dWidth);
	printf("nMode1 : %d, nMode2 : %d, nMode3A : %d, nMode4 : %d \n",msg->stIFF.nMode_1,msg->stIFF.n_Mode_2,msg->stIFF.nMode3A,msg->stIFF.nMode_4);
	printf("Lon : %f, Lat : %f, Alt : %f, Course : %f, Heading : %f, Roll : %f, Pitch : %f, Speed : %f \n",msg->unEntityID,msg->stEntityState.stPosition.dLon,msg->stEntityState.stPosition.dLat,msg->stEntityState.stPosition.dAlt,msg->stEntityState.dCourse,msg->stEntityState.dHeading,msg->stEntityState.dHeading,msg->stEntityState.dRoll,msg->stEntityState.dPitch,msg->stEntityState.dSpeed);
}
void CallbackInformation(SIM_SC_ENTITY_STATE* msg)
{
	printf("[Entity State Info] ");
	printf(" EntityID : %d, Lon : %f, Lat : %f, Alt : %f, Course : %f, Heading : %f, Roll : %f, Pitch : %f, Speed : %f \n",msg->unEntityID,msg->stEntityState.stPosition.dLon,msg->stEntityState.stPosition.dLat,msg->stEntityState.stPosition.dAlt,msg->stEntityState.dCourse,msg->stEntityState.dHeading,msg->stEntityState.dHeading,msg->stEntityState.dRoll,msg->stEntityState.dPitch,msg->stEntityState.dSpeed);

}
void CallbackOwnship(SC_SIM_OWNSHIP* msg)
{
	printf("[Ownship Info]");
	printf("Entity ID : %d, Entity Class : %d, Entity Type :%d Name : %s\n",msg->unEntityID,msg->nEntityClass,msg->nEntityType,msg->chName);
	printf("Draft : %f, Height : %f Length : %f Weight :%f Width : %f \n",msg->stEntityAttribute.dDraft,msg->stEntityAttribute.dHeight,msg->stEntityAttribute.dLength,msg->stEntityAttribute.dWeight,msg->stEntityAttribute.dWidth);
	printf("nMode1 : %d, nMode2 : %d, nMode3A : %d, nMode4 : %d \n",msg->stIFF.nMode_1,msg->stIFF.n_Mode_2,msg->stIFF.nMode3A,msg->stIFF.nMode_4);
	printf("Lon : %f, Lat : %f, Alt : %f, Course : %f, Heading : %f, Roll : %f, Pitch : %f, Speed : %f \n",msg->unEntityID,msg->stEntityState.stPosition.dLon,msg->stEntityState.stPosition.dLat,msg->stEntityState.stPosition.dAlt,msg->stEntityState.dCourse,msg->stEntityState.dHeading,msg->stEntityState.dHeading,msg->stEntityState.dRoll,msg->stEntityState.dPitch,msg->stEntityState.dSpeed);
}
void CallbackEnv(SC_SIM_ENVIRONMENT* msg){
	printf("[Environment Info] ");
	printf("AirPressure : %f, Humidity : %f, Temprature : %f, Visibility : %f, ",msg->dAirPressure,msg->dHumidity,msg->dTemparature,msg->dVisibility);
	printf("Water Direction : %f, Water Speed : %f, Wind Direction : %f, Wind Speed : %f,  Weather : %d \n",msg->dWaterDirection,msg->dWaterSpeed,msg->dWindDirection,msg->dWindSpeed,msg->nWeather);
}

void Initialize(){
	EnLibrary::InitializeLibrary<1,1>();
	EnLibrary::Initialize<1,SC_SIM_OWNSHIP>(CallbackOwnship);
	EnLibrary::Initialize<1,SC_SIM_ENTITY>(CallbackFullInformation);
	EnLibrary::Initialize<1,SIM_SC_ENTITY_STATE>(CallbackInformation);
	EnLibrary::Initialize<1,SC_SIM_ENVIRONMENT>(CallbackEnv);
	EnLibrary::Resume();
}
void Release(){
	EnLibrary::ReleaseLibrary();
}
int _tmain(int argc, _TCHAR* argv[])
{
	Initialize();
	system("pause");
	Release();
	return 0;
}
