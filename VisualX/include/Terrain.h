#pragma once

//#include "baseapplication.h"

class CTerrain : public Ogre::FrameListener
{
public:
	CTerrain(Ogre::SceneManager* pSceneMgr, Ogre::Camera* pCamera);
	~CTerrain(void);

private:
    Ogre::TerrainGlobalOptions* mTerrainGlobals;
    Ogre::TerrainGroup*			mTerrainGroup;
    bool mTerrainsImported;

	Ogre::SceneManager*         mSceneMgr;
    Ogre::Camera*               mCamera;
    Ogre::Root*                 mRoot;
 
	Ogre::Entity*				m_pTerrainEnt;
	Ogre::SceneNode*			m_pTerrain;

    void defineTerrain(long x, long y);
    void initBlendMaps(Ogre::Terrain* terrain);
    void configureTerrainDefaults(Ogre::Light* light);

public:
//	OgreBites::Label* mInfoLabel;

public:
    virtual void createScene(void);
    virtual void createFrameListener(void);
    virtual void destroyScene(void);
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);

	Ogre::TerrainGroup* GetTerrainGroup()
	{
		return mTerrainGroup;
	}

	bool IsTerrainLoad()
	{
		return mTerrainsImported;
	}

};

