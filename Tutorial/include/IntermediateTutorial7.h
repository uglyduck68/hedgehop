// http://www.ogre3d.org/tikiwiki/tiki-index.php?page=Basic+Tutorial+3
#pragma once
#include "StdAfx.h"

#include "baseapplication.h"
class IntermediateTutorial7 :
	public BaseApplication, public Ogre::RenderTargetListener

{
public:
	IntermediateTutorial7(void);
	virtual ~IntermediateTutorial7(void);

protected:
	// derived from FrameListener via BaseApplication
    virtual void createScene(void);
    virtual void createFrameListener(void);
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);


	// derived from Ogre::RenderTargetListener
    virtual void preRenderTargetUpdate(const Ogre::RenderTargetEvent& evt);
    virtual void postRenderTargetUpdate(const Ogre::RenderTargetEvent& evt);

	// from BaseApplication
	void setupResources(void);

    Ogre::MovablePlane* mPlane;
    Ogre::Entity* mPlaneEnt;
    Ogre::SceneNode* mPlaneNode;
    Ogre::Rectangle2D* mMiniScreen;

};

