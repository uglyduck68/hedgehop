#pragma once

#include "airvessel.h"

class CCH_53E :
	public CAirVessel
{
public:
	CCH_53E(void);
	CCH_53E(Ogre::SceneManager* pSceneMgr, int name, string mesh);
	~CCH_53E(void);

protected:
	AnimationState* mAnimState;

public:
	/**
	* @function		createScene
	* @brief		create entity and scene node
	*/
	void	createScene();
};

