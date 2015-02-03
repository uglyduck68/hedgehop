#include "StdAfx.h"
#include "..\include\CH_53E.h"


CCH_53E::CCH_53E(void)
{
}

/**
 *@function		CCH_53
 *@brief		create hellicopter
 */
CCH_53E::CCH_53E(Ogre::SceneManager* pSceneMgr, int name, string mesh)
{
}

CCH_53E::~CCH_53E(void)
{
}

/**
* @function		createScene
* @brief		create entity and scene node
*/
void	CCH_53E::createScene()
{
	// create target entity
	m_pSceneNode		= mSceneMgr->getRootSceneNode()->createChildSceneNode();
	Entity*	pEntity		= mSceneMgr->createEntity(m_strMeshName);

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

