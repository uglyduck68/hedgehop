/**
 * @file    Target.h
 *
 * This file is base class of ship, fighter, missile and so on.
 */

#pragma once

using namespace	std;
using namespace	Ogre;

class CTarget  : public Ogre::FrameListener
{
protected:
	Ogre::SceneManager*         mSceneMgr;
    //Ogre::Camera*               mCamera;
    //Ogre::Root*                 mRoot;

	string					m_strName;
	string					m_strMeshName;
	SceneNode*				m_pSceneNode;

public:
	CTarget(Ogre::SceneManager* pSceneMgr, int name, string mesh);
	~CTarget(void);

	SceneNode*	GetSceneNode()
	{
		return m_pSceneNode;
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

