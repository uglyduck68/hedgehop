#include "StdAfx.h"
#include "..\include\AirVessel.h"


CAirVessel::CAirVessel(void)
{
}

CAirVessel::CAirVessel(Ogre::SceneManager* pSceneMgr, int name, string mesh) : CTarget(pSceneMgr, name, mesh)
{
}

CAirVessel::~CAirVessel(void)
{
}
