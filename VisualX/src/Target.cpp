#include "StdAfx.h"
#include "..\include\Target.h"

const char*	TARGET_NAME_PREFIX	= "Target_";

CTarget::CTarget(Ogre::SceneManager* pSceneMgr, int name, string mesh) :
	mSceneMgr(pSceneMgr)
{
	char	temp[20];

	itoa(name, temp, 10);

	// set target name
	m_strName		= TARGET_NAME_PREFIX;
	m_strName		+= temp;

	// set target mesh name
	m_strMeshName	= mesh;

	// create target entity
	m_pSceneNode		= mSceneMgr->getRootSceneNode()->createChildSceneNode();
	Entity*	pEntity		= mSceneMgr->createEntity(m_strMeshName);

	Any			any(pEntity);

	m_pSceneNode->setUserAny(any);

	m_pSceneNode->attachObject(pEntity);
}


CTarget::~CTarget(void)
{
}

bool CTarget::frameRenderingQueued( const FrameEvent &evt )
{
	/** to test interference of ocean wave simulation and vehicle */
	m_pSceneNode->yaw(Ogre::Radian(evt.timeSinceLastFrame));

	return true;
}

void CTarget::createFrameListener(void)
{
	Ogre::Root::getSingletonPtr()->addFrameListener(this);

	return;
}
