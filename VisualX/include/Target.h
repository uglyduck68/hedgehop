/**
 * @file		Target.h
 *
 * @remarks		모든 탈 것(군함, 전투기, 미사일 등등)의 base class
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

	string					m_strName;		// character name
	string					m_strMeshName;	// meshfile name
	SceneNode*				m_pSceneNode;	// scene node

public:
	CTarget() {}	//* default ctor for class inheritance
	CTarget(Ogre::SceneManager* pSceneMgr, int nID, string mesh);
	~CTarget(void);

	SceneNode*	GetSceneNode()
	{
		return m_pSceneNode;
	}

	operator SceneNode*()
	{
		return m_pSceneNode;
	}

	/**
	 * @function	PostCreate
	 * @remarks		post processinf according to characteristic of each target
	 */
	virtual void CreatePostprocess() {}

	/**
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

