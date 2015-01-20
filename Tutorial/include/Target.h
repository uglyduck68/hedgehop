/**
 * @file    Target.h
 *
 * This file is base class of ship, fighter, missile and so on.
 */

#pragma once
#include "OgreOggSound.h"

using namespace	std;
using namespace	Ogre;
using namespace	OgreOggSound;


class CTarget  : public Ogre::FrameListener
{
protected:
	Ogre::SceneManager*         mSceneMgr;
    //Ogre::Camera*               mCamera;
    //Ogre::Root*                 mRoot;

	string					m_strName;		// character name
	string					m_strMeshName;	// meshfile name
	SceneNode*				m_pSceneNode;	// scene node

	// viewpoint node
	// In chase mode camera always look at this node
	SceneNode*				m_pViewpointNode;	
	Vector3					VP_DEFAULT_POSITION;// position of viewpoint node

	SceneNode*				m_pCamHolder;	//* camera holder node
	OgreOggISound*			m_pSound;

public:
	CTarget(Ogre::SceneManager* pSceneMgr, int nID, string mesh);
	~CTarget(void);

	SceneNode*	GetSceneNode()
	{
		return m_pSceneNode;
	}

	SceneNode*	GetViewpointNode()
	{
		return m_pViewpointNode;
	}

	SceneNode* GetCamNode()
	{
		return m_pCamHolder;
	}

	operator SceneNode*()
	{
		return m_pSceneNode;
	}

	/**
	* @function		getViewport
	* @return		tracking camera가 이 target에 attached된 경우
	*				camera가 바라 봐야할 viewpoint를 return
	*/
	Vector3 getViewport()
	{
		if (m_pViewpointNode)
			return m_pViewpointNode->_getDerivedPosition();

		return Vector3(0, 0, 0);
	}

	Vector3 getCameraPosition(const Ogre::SceneNode* target)
	{
		AxisAlignedBox	bb		= target->_getWorldAABB();
		const Vector3			min	= bb.getMinimum();
		const Vector3			max	= bb.getMaximum();

		Vector3	pos				= target->_getDerivedPosition();
		pos.y	+= (max.y - min.y + 10);	// offset 10

		return pos;
	}

	/**
	* @function		setTrackingCamera
	* @remarks		chase mode에서 카메라와 그 시점 위치를 결정한다.
	*				
	*/
	void	setTrackingCameraPosition(Ogre::Camera* pCamera)
	{
		// set the location of camera
#if	0
		pCamera->setPosition (getCameraPosition(m_pSceneNode));
#else
		// Method 2 to handle viewpoint of camera
		pCamera->setPosition (m_pCamHolder->_getDerivedPosition());
#endif
	}
	/*
	* @function		MoveTo that translate mesh to @Dest and set mesh's
	* orientation to @Dest
	* @param		Src	that is mesh's current position
	* @param		Dest that is mesh's destination position
	* @return		1 if success
	*/
	int		MoveTo( Ogre::Vector3 Src, Ogre::Vector3 Dest );
	//void setPosition( Ogre::Vector3 pos )
	//{
	//	m_pSceneNode->setPosition( pos );
	//}

	//void setPosition(float x, float y, float z)
	//{
	//	assert(m_pSceneNode);

	//	m_pSceneNode->setPosition(x, y, z);
	//}

	virtual bool frameRenderingQueued( const FrameEvent &evt );
    virtual void createFrameListener(void);

};

