/**
 * @file		AnimationTutorial.h
 * @remarks		DDS를 통해서 오브젝트의 이동 좌표를 1초 주기로 받는다.
 *				1초 동안에 30여 프레임 이상의 프레임이 전시됨으로
 *				1초 동안에 전시되는 프레임 사이에서 오브젝트의 이동이
 *				animation 기법으로 전시됨을 테스트 한다.
 *				오브젝트의 움직임을 시뮬레이션하기 위하여
 *				오브젝트를 중심을 기준으로 원형 운동을 하도록 한다.
 * @author		sean kim<uglyduck68@gmail.com>
 */
#pragma once

#include "baseapplication.h"
#include <OgreManualObject.h>
#include <string>

using namespace	Ogre;
using namespace	std;

class AnimationTutorial :
	public BaseApplication
{
public:
	AnimationTutorial(void);
	~AnimationTutorial(void);
protected:
	SceneNode*				m_pSceneNode;	// scene node

	SceneNode*	GetSceneNode()
	{
		return m_pSceneNode;
	}

	static const int	MAX_INDEX	= 100;

	//< coordinate of 3D circle
	Vector3			m_aCirclePos[ MAX_INDEX ];

	//< object to display 3D circle that is orbit of fighter
	ManualObject*	m_pCircle;

protected:

	int		createSceneNode(string MeshName)
	{
		// create target entity
		m_pSceneNode		= mSceneMgr->getRootSceneNode()->createChildSceneNode();
		Entity*	pEntity		= mSceneMgr->createEntity(MeshName);

		Any			any(pEntity);

		m_pSceneNode->setUserAny(any);

		m_pSceneNode->attachObject(pEntity);

		return 1;
	}

	void createCamera(void)
	{
		BaseApplication::createCamera();

		//< 
		mCamera->setPosition(1000, 1000, 1000);

		mCamera->lookAt(0, 0, 0);
	}

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
};

