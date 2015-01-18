/**
* @file			Decoy.h
* @remarks		미사일 기만기 인터페이스.
*				현재 mesh 모델은 단순 파이프 형상임.
*				기만기는 기만기 런처에서 발사된 직후
*				자함 인근에서 불꽃놀이의 불꽃으로 폭파된다.
*/
#pragma once
#include "airvessel.h"
class CDecoy :
	public CAirVessel
{
public:
	CDecoy(void);
	~CDecoy(void);
};

