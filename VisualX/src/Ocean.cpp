#include "StdAfx.h"
#include "Ocean.h"
#include "Debug.h"

using namespace	std;

COcean::COcean(Ogre::SceneManager* pSceneMgr) :
	m_pOceanEnt(NULL), mSceneMgr(pSceneMgr),
	m_pOcean(NULL)
{
}


COcean::~COcean(void)
{
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

//    Ogre::Plane oceanPlane;

    m_Plane.normal	= Ogre::Vector3::UNIT_Y;
    m_Plane.d		= GetSurface();

    Ogre::MeshManager::getSingleton().createPlane("OceanPlane",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        m_Plane,
        MAX_WIDTH, MAX_HEIGHT, XSEGMENT, YSEGMENT, true, 1, 1, 1, Ogre::Vector3::UNIT_Z);

    m_pOceanEnt = mSceneMgr->createEntity( "OceanTest", "OceanPlane" );

	if( m_pOceanEnt )
	{
		m_pOcean	= mSceneMgr->getRootSceneNode()->createChildSceneNode("Ocean"/*, Ogre::Vector3(0, GetSurface(), 0)*/);
		m_pOcean->attachObject(m_pOceanEnt);
//		m_pOcean->translate(0, 1000, 0);

		// axis is "axis.png" in "./resource" folder.
		// if not call you get "Expression: pRep" in 1.9v.
		m_pOceanEnt->setMaterialName("OceanTest_Cg");		// "OceanCg" -> "Ocean2_Cg" -> "OceanTest_Cg"
		m_pOceanEnt->setCastShadows(false);
//		m_pOceanEnt->setQueryFlags(1);	// if QueryFlag is 0xffffffff then this is useless

	}
	else
	{
		DebugPrintf("Error: fail to create ocean entity\n");
	}
}
