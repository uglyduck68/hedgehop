#include "StdAfx.h"
#include "..\include\Target.h"

const char*	TARGET_NAME_PREFIX	= "Target_";

/**
 *@function		CTarget
 *@brief		base class of all target characters
 *@FIXME		급해서 생성자에 모델 생성 부분을 만들었지만
 *				추후 createScene 함수에서 만들도록 수정하는 것이 좋음
 */
CTarget::CTarget(Ogre::SceneManager* pSceneMgr, int name, string mesh) :
	mSceneMgr(pSceneMgr),
	m_pViewpointNode(NULL),
	//* viewpoint of tracking camera
	//* B787은 -z 방향을 바라 복 있기 때문에 viewpoint로 -z 값을 적용한다.
	//* viewpoint 동작 유무를 확인하기 위하여 -z 값으로 -50 적용한다.
	VP_DEFAULT_POSITION(0, 0, -50),
	m_eftJetEngine(NULL), m_eftSmoke(NULL), m_eftExplosion(NULL), m_eft(EFT_JETENGINE)
{
	char	temp[20];

	itoa(name, temp, 10);

	// set target name
	m_strName		= TARGET_NAME_PREFIX;
	m_strName		+= temp;

	// set target mesh name
	m_strMeshName	= mesh;
/*
	// create target entity
	m_pSceneNode		= mSceneMgr->getRootSceneNode()->createChildSceneNode();
	Entity*	pEntity		= mSceneMgr->createEntity(m_strMeshName);

	Any			any(pEntity);

	GetSceneNode()->setUserAny(any);

	GetSceneNode()->attachObject(pEntity);

	///////////////////////////////////////////////////////////////////////////
	// create my own resources for particle system
	///////////////////////////////////////////////////////////////////////////
	createEffects();

	// attache particle to scene node
	SetEffect(EFT_JETENGINE);

	///////////////////////////////////////////////////////////////////////////
	// create my own sounds
	///////////////////////////////////////////////////////////////////////////
	m_pSound	= OgreOggSoundManager::getSingletonPtr()->createSound(m_strName, "jet_exhaust.wav");

	// start to play sound
	if( m_pSound )
		m_pSound->play();

	///////////////////////////////////////////////////////////////////////////
	// create viewpoint node for tracking camera
	///////////////////////////////////////////////////////////////////////////
	if (m_pSceneNode)
	{
		m_pViewpointNode	= m_pSceneNode->createChildSceneNode(m_strName + "_viewpoint", VP_DEFAULT_POSITION);

		// Method 2 to handle viewpoint of camera
		// 카메라를 좀 더 편하게 핸들링하기 위하여 카메라를 담을 노드를 생성한다.
		// @FIXME
		// - 이 시점에서 getCameraPosition 함수를 통하여 카메라의 위치를 구할 수 없음.
		// 아마도 실제 scene node 생성이 안되서 그 크기가 정해지지 않음.
		// 따라서 MBR을 이용하지 않고, 강제로 100 높이에 카메라를 위치시킬 수 있도록한다.
		Vector3	pos(0, 100, 0);

		m_pCamHolder		= m_pSceneNode->createChildSceneNode(m_strName + "_camHolder", pos);
	}
*/
}


CTarget::~CTarget(void)
{
}

/**
* @function		createScene
* @brief		create entity and scene node
*/
void	CTarget::createScene()
{
	// create target entity
	m_pSceneNode		= mSceneMgr->getRootSceneNode()->createChildSceneNode();
	Entity*	pEntity		= mSceneMgr->createEntity(m_strMeshName);

	Any			any(pEntity);

	GetSceneNode()->setUserAny(any);

	GetSceneNode()->attachObject(pEntity);

	///////////////////////////////////////////////////////////////////////////
	// create my own resources for particle system
	///////////////////////////////////////////////////////////////////////////
	createEffects();

	// attache particle to scene node
	SetEffect(EFT_JETENGINE);

	///////////////////////////////////////////////////////////////////////////
	// create my own sounds
	///////////////////////////////////////////////////////////////////////////
	m_pSound	= OgreOggSoundManager::getSingletonPtr()->createSound(m_strName, "jet_exhaust.wav");

	// start to play sound
	if( m_pSound )
		m_pSound->play();

	///////////////////////////////////////////////////////////////////////////
	// create viewpoint node for tracking camera
	///////////////////////////////////////////////////////////////////////////
	if (m_pSceneNode)
	{
		m_pViewpointNode	= m_pSceneNode->createChildSceneNode(m_strName + "_viewpoint", VP_DEFAULT_POSITION);

		// Method 2 to handle viewpoint of camera
		// 카메라를 좀 더 편하게 핸들링하기 위하여 카메라를 담을 노드를 생성한다.
		// @FIXME
		// - 이 시점에서 getCameraPosition 함수를 통하여 카메라의 위치를 구할 수 없음.
		// 아마도 실제 scene node 생성이 안되서 그 크기가 정해지지 않음.
		// 따라서 MBR을 이용하지 않고, 강제로 100 높이에 카메라를 위치시킬 수 있도록한다.
		Vector3	pos(0, 100, 0);

		m_pCamHolder		= m_pSceneNode->createChildSceneNode(m_strName + "_camHolder", pos);
	}
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
	Vector3			Dir				= Dest - Src;

	// normalize the direction vector
	Ogre::Real		Dist			= Dir.normalise();

	// get the orientation quaternion based on Z-axis
	// because the orientation of all models are Z-axis on XZ plane.
	Quaternion		quat			= Vector3(Vector3::UNIT_Z).getRotationTo( Dir );

	// set target's orientation to destination
	GetSceneNode()->setOrientation( quat );

	// move target to destination
	GetSceneNode()->setPosition( Dest );

	return true;
}
