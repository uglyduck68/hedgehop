#include "StdAfx.h"
#include "Ocean.h"
#include "Debug.h"

using namespace	std;

COcean::COcean(Ogre::SceneManager* pSceneMgr) :
	m_pOceanEnt(NULL), mSceneMgr(pSceneMgr),
	m_pOcean(NULL), m_pPlane(NULL)
{
}


COcean::~COcean(void)
{
	DEL(m_pPlane);
}

/**
* create ocean entity
*/
void COcean::createScene()
{
   // Define a plane mesh that will be used for the ocean surface
	//m_pPlane	= new /*(nothrow)*/ Ogre::MovablePlane("OceanPlane");
	//m_pPlane->d	= 0;
	//m_pPlane->normal	= Ogre::Vector3::UNIT_Y;

    Ogre::Plane oceanPlane;

    oceanPlane.normal	= Ogre::Vector3::UNIT_Y;
    oceanPlane.d		= 0;

    Ogre::MeshManager::getSingleton().createPlane("OceanPlane",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        oceanPlane,
        MAX_WIDTH, MAX_HEIGHT, XSEGMENT, YSEGMENT, true, 1, 1, 1, Ogre::Vector3::UNIT_Z);

    m_pOceanEnt = mSceneMgr->createEntity( "OceanTest", "OceanPlane" );

	if( m_pOceanEnt )
	{
		m_pOcean	= mSceneMgr->getRootSceneNode()->createChildSceneNode("Ocean", Ogre::Vector3(0, GetSurface(), 0));
		m_pOcean->attachObject(m_pOceanEnt);
//		m_pOcean->translate(0, 1000, 0);

		// axis is "axis.png" in "./resource" folder.
		// if not call you get "Expression: pRep" in 1.9v.
		m_pOceanEnt->setMaterialName("Ocean2_Cg");		// "OceanCg"
		m_pOceanEnt->setCastShadows(false);
	}
	else
	{
		DebugPrintf("Error: fail to create ocean entity\n");
	}
}
