/**
 * @file    CTarget.h
 *
 * This file is base class of ship, fighter, missile and so on.
 */

#pragma once

using namespace	std;
using namespace	Ogre;

class CTarget
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

	void setPosition(float x, float y, float z)
	{
		assert(m_pSceneNode);

		m_pSceneNode->setPosition(x, y, z);

		DebugPrintf("setPosition: %f, %f, %f\n", x, y, z);
	}
};

