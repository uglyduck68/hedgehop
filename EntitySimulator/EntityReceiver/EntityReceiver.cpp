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
	printf("Entity ID : %d, Entity Class : %d, Entity Type :%d Name : %s\n",msg->nEntityID,msg->stEntityInfo.ulPlatformClass,msg->stEntityInfo.ulType,msg->stEntityInfo.chESM_Name);
	printf("Height : %.2f Length : %.2f Weight :%.2f Width : %.2f \n",msg->stEntityAttribute.fHeight,msg->stEntityAttribute.fLength,msg->stEntityAttribute.fWeight,msg->stEntityAttribute.fWidth);
	printf("nMode1 : %d, nMode2 : %d, nMode3A : %d, nMode4 : %d \n",msg->stEntityInfo.nMode1,msg->stEntityInfo.nMode2,msg->stEntityInfo.nMode3A,msg->stEntityInfo.nMode4);
	printf("Lon : %.2f, Lat : %.2f, Alt : %.2f, Course : %.2f, Heading : %.2f, Roll : %.2f, Pitch : %.2f, Speed : %.2f \n",msg->nEntityID,msg->stEntityState.stPosition.dLon,msg->stEntityState.stPosition.dLat,msg->stEntityState.stPosition.dAlt,msg->stEntityState.fCourse,msg->stEntityState.fHeading,msg->stEntityState.fHeading,msg->stEntityState.fRoll,msg->stEntityState.fPitch,msg->stEntityState.fSpeed);
}
void CallbackInformation(SC_SIM_ENTITY_STATE* msg)
{
	printf("[Entity State Info] ");
	printf(" EntityID : %d, Lon : %.2f, Lat : %.2f, Alt : %.2f, Course : %.2f, Heading : %.2f, Roll : %.2f, Pitch : %.2f, Speed : %.2f \n",msg->nEntityID,msg->stEntityState.stPosition.dLon,msg->stEntityState.stPosition.dLat,msg->stEntityState.stPosition.dAlt,msg->stEntityState.fCourse,msg->stEntityState.fHeading,msg->stEntityState.fHeading,msg->stEntityState.fRoll,msg->stEntityState.fPitch,msg->stEntityState.fSpeed);

}
void CallbackOwnshipInformation(SC_SIM_OWNSHIP_STATE* msg)
{
	printf("[Ownship State Info] ");
	printf(" EntityID : %d, Lon : %.2f, Lat : %.2f, Alt : %.2f, Course : %.2f, Heading : %.2f, Roll : %.2f, Pitch : %.2f, Speed : %.2f \n",msg->nEntityID,msg->stEntityState.stPosition.dLon,msg->stEntityState.stPosition.dLat,msg->stEntityState.stPosition.dAlt,msg->stEntityState.fCourse,msg->stEntityState.fHeading,msg->stEntityState.fHeading,msg->stEntityState.fRoll,msg->stEntityState.fPitch,msg->stEntityState.fSpeed);
}
void CallbackOwnship(SC_SIM_OWNSHIP* msg)
{
	printf("[Ownship Info]");
	printf("Entity ID : %d, Entity Class : %d, Entity Type :%d Name : %s\n",msg->nEntityID,msg->stEntityInfo.ulPlatformClass,msg->stEntityInfo.ulType,msg->stEntityInfo.chESM_Name);
	printf("Draft : %.2f, Height : %.2f Length : %.2f Weight :%.2f Width : %.2f \n",msg->stEntityAttribute.fHeight,msg->stEntityAttribute.fLength,msg->stEntityAttribute.fWeight,msg->stEntityAttribute.fWidth);

	printf("nMode1 : %d, nMode2 : %d, nMode3A : %d, nMode4 : %d \n",msg->stEntityInfo.nMode1,msg->stEntityInfo.nMode2,msg->stEntityInfo.nMode3A,msg->stEntityInfo.nMode4);
	printf("Lon : %.2f, Lat : %.2f, Alt : %.2f, Course : %.2f, Heading : %.2f, Roll : %.2f, Pitch : %.2f, Speed : %.2f \n",msg->nEntityID,msg->stEntityState.stPosition.dLon,msg->stEntityState.stPosition.dLat,msg->stEntityState.stPosition.dAlt,msg->stEntityState.fCourse,msg->stEntityState.fHeading,msg->stEntityState.fHeading,msg->stEntityState.fRoll,msg->stEntityState.fPitch,msg->stEntityState.fSpeed);
}
void CallbackEnv(SC_SIM_ENVIRONMENT* msg){
	printf("[Environment Info] ");
	printf("AirPressure : %.2f, Humidity : %.2f, Temprature : %.2f, Visibility : %.2f, ",msg->fAirPressure,msg->fHumidity,msg->fTemparature,msg->fVisibility);
	printf("Water Direction : %.2f, Water Speed : %.2f, Wind Direction : %.2f, Wind Speed : %.2f,  Weather : %d \n",msg->fWaterDirection,msg->fWaterSpeed,msg->fWindDirection,msg->fWindSpeed,msg->nWeather);
}

void Initialize(){
	EnLibrary::InitializeLibrary<DOMAIN_ID,1>();
	EnLibrary::Initialize<DOMAIN_ID,SC_SIM_OWNSHIP>(CallbackOwnship);
	EnLibrary::Initialize<DOMAIN_ID,SC_SIM_ENTITY>(CallbackFullInformation);
	EnLibrary::Initialize<DOMAIN_ID,SC_SIM_OWNSHIP_STATE>(CallbackOwnshipInformation);
	EnLibrary::Initialize<DOMAIN_ID,SC_SIM_ENTITY_STATE>(CallbackInformation);
	EnLibrary::Initialize<DOMAIN_ID,SC_SIM_ENVIRONMENT>(CallbackEnv);
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
