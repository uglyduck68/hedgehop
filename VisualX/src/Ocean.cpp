#include "StdAfx.h"
#include "Ocean.h"
#include "Debug.h"

Ocean::Ocean(Ogre::SceneManager* pSceneMgr) :
	m_pOceanEnt(NULL), mSceneMgr(pSceneMgr)
{
}


Ocean::~Ocean(void)
{
}

/**
* create ocean entity
*/
void Ocean::createScene()
{
   // Define a plane mesh that will be used for the ocean surface
    Ogre::Plane oceanPlane;

    oceanPlane.normal = Ogre::Vector3::UNIT_Y;
    oceanPlane.d = 20;

    Ogre::MeshManager::getSingleton().createPlane("OceanPlane",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        oceanPlane,
        MAX_WIDTH, MAX_HEIGHT, 50, 50, true, 1, 1, 1, Ogre::Vector3::UNIT_Z);

    m_pOceanEnt = mSceneMgr->createEntity( "OceanTest", "OceanPlane" );

	if( m_pOceanEnt )
	{
		mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(m_pOceanEnt);

		// axis is "axis.png" in "./resource" folder.
		// if not call you get "Expression: pRep" in 1.9v.
		m_pOceanEnt->setMaterialName("OceanHLSL_GLSL");
		m_pOceanEnt->setCastShadows(true);
	}
	else
	{
		DebugPrintf("Error: fail to create ocean entity\n");
	}
}
