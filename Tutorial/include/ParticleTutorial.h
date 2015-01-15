#pragma once

#include "baseapplication.h"

using namespace	Ogre;

class ParticleTutorial :
	public BaseApplication
{
public:
	ParticleTutorial(void);
	~ParticleTutorial(void);

protected:
    virtual void setupResources(void);
    virtual void createScene(void);
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);


protected:
	SceneNode* mFountainPivot;

	SceneNode*	mOgreHead;

};

