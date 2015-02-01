#include "StdAfx.h"
#include "..\include\Target.h"

const char*	TARGET_NAME_PREFIX	= "Target_";

CTarget::CTarget(Ogre::SceneManager* pSceneMgr, int nID, string mesh) :
	mSceneMgr(pSceneMgr)
{
	char	temp[20];

	itoa(nID, temp, 10);

	// set target name
	m_strName		= TARGET_NAME_PREFIX;
	m_strName		+= temp;

	// set target mesh name
	m_strMeshName	= mesh;

	// create target entity
	m_pSceneNode		= mSceneMgr->getRootSceneNode()->createChildSceneNode();
	Ogre::Entity*	pEntity		= mSceneMgr->createEntity(m_strMeshName);

	Ogre::Any			any(pEntity);

	m_pSceneNode->setUserAny(any);

	m_pSceneNode->attachObject(pEntity);
}


CTarget::~CTarget(void)
{
}

bool CTarget::frameRenderingQueued( const Ogre::FrameEvent &evt )
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

/*
* @function		MoveTo that translate mesh to @Dest and set mesh's
* orientation to @Dest
* @param		Src	that is mesh's current position
* @param		Dest that is mesh's destination position
* @return		1 always
* @note			if you want to turn target smoothly, 
* then use slerp (spherical linear interpolation) function and 
* rotating time (timeSinceLastFrame)
*/
int		CTarget::MoveTo( Ogre::Vector3 Src, Ogre::Vector3 Dest )
{
	// get the direction vector from source to destination
	Ogre::Vector3			Dir				= Dest - Src;

	// normalize the direction vector
	Ogre::Real		Dist			= Dir.normalise();

	// get the orientation quaternion based on Z-axis
	// because the orientation of all models are Z-axis on XZ plane.
	Ogre::Quaternion		quat			= Ogre::Vector3(Ogre::Vector3::UNIT_Z).getRotationTo( Dir );

	// set target's orientation to destination
	GetSceneNode()->setOrientation( quat );

	// move target to destination
	GetSceneNode()->setPosition( Dest );

	return true;
}
