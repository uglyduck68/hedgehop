/**
* @file			Ship.h
* @remarks		군함, 보트 등 수상함(surface ship)의 base class.
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

