#include "StdAfx.h"
#include "..\include\Target.h"

const char*	TARGET_NAME_PREFIX	= "Target_";

/**
 *@function		CTarget
 *@brief		base class of all target characters
 *@FIXME		���ؼ� �����ڿ� �� ���� �κ��� ���������
 *				���� createScene �Լ����� ���鵵�� �����ϴ� ���� ����
 */
CTarget::CTarget(Ogre::SceneManager* pSceneMgr, int name, string mesh) :
	mSceneMgr(pSceneMgr),
	m_pViewpointNode(NULL),
	//* viewpoint of tracking camera
	//* B787�� -z ������ �ٶ� �� �ֱ� ������ viewpoint�� -z ���� �����Ѵ�.
	//* viewpoint ���� ������ Ȯ���ϱ� ���Ͽ� -z ������ -50 �����Ѵ�.
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
		// ī�޶� �� �� ���ϰ� �ڵ鸵�ϱ� ���Ͽ� ī�޶� ���� ��带 �����Ѵ�.
		// @FIXME
		// - �� �������� getCameraPosition �Լ��� ���Ͽ� ī�޶��� ��ġ�� ���� �� ����.
		// �Ƹ��� ���� scene node ������ �ȵǼ� �� ũ�Ⱑ �������� ����.
		// ���� MBR�� �̿����� �ʰ�, ������ 100 ���̿� ī�޶� ��ġ��ų �� �ֵ����Ѵ�.
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
		// ī�޶� �� �� ���ϰ� �ڵ鸵�ϱ� ���Ͽ� ī�޶� ���� ��带 �����Ѵ�.
		// @FIXME
		// - �� �������� getCameraPosition �Լ��� ���Ͽ� ī�޶��� ��ġ�� ���� �� ����.
		// �Ƹ��� ���� scene node ������ �ȵǼ� �� ũ�Ⱑ �������� ����.
		// ���� MBR�� �̿����� �ʰ�, ������ 100 ���̿� ī�޶� ��ġ��ų �� �ֵ����Ѵ�.
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
