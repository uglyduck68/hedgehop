/**
 * @file		AnimationTutorial.h
 * @remarks		DDS�� ���ؼ� ������Ʈ�� �̵� ��ǥ�� 1�� �ֱ�� �޴´�.
 *				1�� ���ȿ� 30�� ������ �̻��� �������� ���õ�����
 *				1�� ���ȿ� ���õǴ� ������ ���̿��� ������Ʈ�� �̵���
 *				animation ������� ���õ��� �׽�Ʈ �Ѵ�.
 *				������Ʈ�� �������� �ùķ��̼��ϱ� ���Ͽ�
 *				������Ʈ�� �߽��� �������� ���� ��� �ϵ��� �Ѵ�.
 * @author		sean kim<uglyduck68@gmail.com>
 */
#pragma once

#include "baseapplication.h"
#include "Target.h"

#include <OgreManualObject.h>
#include <string>

using namespace	Ogre;
using namespace	std;

#define		DEL(p)	if(p) {delete p; p=NULL;}

class AnimationTutorial :
	public BaseApplication
{
public:
	AnimationTutorial(void);
	~AnimationTutorial(void);
protected:
	SceneNode*				m_pSceneNode;	// scene node

	std::vector<CTarget*>	m_vecTarget;

	SceneNode*	GetSceneNode(int nIndex = 0)
	{
		if( m_vecTarget.size() > 0 )
			return *m_vecTarget[nIndex];

		// error case
		assert(m_vecTarget.size() > 0);

		return NULL;

//		return m_pSceneNode;
	}

	static const int	MAX_INDEX	= 100;	// # of points that make up circle

	//< coordinate of 3D circle
	std::deque<Vector3> m_WalkList;		// set of waypoint
	Real				mDistance;		// ���� �������� ���� �Ÿ�
	Vector3				mDirection;		// ��ü�� �����̰� �ִ� ����
	Vector3				mDestination;	// ��ü�� ���� �ִ� ��ǥ��
	static const int	m_WalkSpeed		= 100;	// character speed


	//< object to display 3D circle that is orbit of fighter
	ManualObject*	m_pCircle;

protected:

	int		createSceneNode(string MeshName)
	{
		// create target entity
		//m_pSceneNode		= mSceneMgr->getRootSceneNode()->createChildSceneNode();
		//Entity*	pEntity		= mSceneMgr->createEntity(MeshName);

		//Any			any(pEntity);

		//m_pSceneNode->setUserAny(any);

		//m_pSceneNode->attachObject(pEntity);

		CTarget*	pTemp	= new CTarget( mSceneMgr, m_vecTarget.size(), MeshName );

		m_vecTarget.push_back( pTemp );

		return 1;
	}

	void setupCameraPosition(void)
	{
		//< relocate the camera for good looking
		mCamera->setPosition(1000, 1000, 1000);

		mCamera->lookAt(0, 0, 0);
	}
    
	void createFrameListener(void);

	/**
	* @function		createScene
	* @remarks		create character entity and node
	*/
	void createScene();

	/**
	* @function		frameRenderingQueued
	* @remarks		render character
	*/
	bool frameRenderingQueued(const Ogre::FrameEvent& evt);

	/**
	* @function		frameStarted
	* @remarks		make animation effect
	*/
	bool frameStarted(const Ogre::FrameEvent& evt);

	/*
	* @function		MoveTo that translate mesh to @Dest and set mesh's
	* orientation to @Dest
	* @param		Src	that is mesh's current position
	* @param		Dest that is mesh's destination position
	* @return		1 if success
	*/
	int		MoveTo( Ogre::Vector3 Src, Ogre::Vector3 Dest, const Ogre::FrameEvent& evt );

	bool nextLocation();
};

