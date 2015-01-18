#include "StdAfx.h"
#include "..\include\Ship.h"


CShip::CShip(Ogre::SceneManager* pSceneMgr, int nID, string mesh) : CTarget(pSceneMgr, nID, mesh)
{
}


CShip::~CShip(void)
{
}
