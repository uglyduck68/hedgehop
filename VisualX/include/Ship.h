/**
* @file			Ship.h
* @remarks		����, ��Ʈ �� ������(surface ship)�� base class.
*/
#pragma once
#include "target.h"
class CShip :
	public CTarget
{
public:
	CShip() {}	//*
	CShip(Ogre::SceneManager* pSceneMgr, int nID, string mesh);
	~CShip(void);
};

