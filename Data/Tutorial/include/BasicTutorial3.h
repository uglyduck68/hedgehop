/**
*@file	BasicTutorial3
* Ogre wiki�� terrain rendering ����� ���� basic tutorial 03 ������ �������
* ���� �浹 ȸ�� ����� intermediate tutorial 02 ������ ����� �߰� ��.
*/
#pragma once

#include "baseapplication.h"

class BasicTutorial3 :
	public BaseApplication
{
private:
    Ogre::TerrainGlobalOptions* mTerrainGlobals;
    Ogre::TerrainGroup* mTerrainGroup;
    bool mTerrainsImported;

	OgreBites::Label* mInfoLabel;
 
    void defineTerrain(long x, long y);
    void initBlendMaps(Ogre::Terrain* terrain);
    void configureTerrainDefaults(Ogre::Light* light);
public:
    BasicTutorial3(void);
    virtual ~BasicTutorial3(void);
 
protected:
    virtual void createScene(void);
    virtual void createFrameListener(void);
    virtual void destroyScene(void);
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);

protected:
	/** 
	* get followings from Intermediate Tutorial 02 
	*/
	Ogre::RaySceneQuery *mRaySceneQuery;// The ray scene query pointer
    bool mLMouseDown, mRMouseDown;		// True if the mouse buttons are down
    int mCount;							// The number of robots on the screen
	Ogre::SceneNode *mCurrentObject;	// The newly created object
    //CEGUI::Renderer *mGUIRenderer;	// Not needed since we are using SdkTrays
	float mRotateSpeed;		


};

