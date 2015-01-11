/**
 * @file		Terrain.h
 * @remarks		define terrain
 */

#pragma once

#include "CollisionTools.h"

class CTerrain// : public Ogre::FrameListener
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

	MOC::CollisionTools*		m_pCollisionTools;
	bool						m_bCollision;

    void defineTerrain(long x, long y);
    void initBlendMaps(Ogre::Terrain* terrain);
    void configureTerrainDefaults(Ogre::Light* light);

	std::vector<Ogre::Entity*>		m_vecTerrainEnty;
	std::vector<Ogre::SceneNode*>	m_vecTerrainNode;

public:
    virtual void createScene(void);
    virtual void createFrameListener(void);
    virtual void destroyScene(void);
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);

	Ogre::TerrainGroup* GetTerrainGroup()
	{
		return mTerrainGroup;
	}

	void getTerrainImage(bool flipX, bool flipY, Ogre::Image& img);

	/**
	* @function		isCollision
	* @remarks		check the collision of terrain and camera
	* @FIXME		in VS2010 'inline' function MUST have body in .h.
	*/
	/*inline*/ bool IsCollision( Ogre::Camera* Cam, Ogre::Real* CollDist );
};

