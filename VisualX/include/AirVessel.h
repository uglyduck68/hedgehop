/**
* @file			AirVessel.h
* @remarks		헬기, 전투기, 미사일, 기만기 등의 비행체의 base class
*/
#pragma once
#include "target.h"
class CAirVessel :
	public CTarget
{
public:
	CAirVessel(void);
	~CAirVessel(void);
};

