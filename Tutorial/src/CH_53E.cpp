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
		// ī�޶� �� �� ���ϰ� �ڵ鸵�ϱ� ���Ͽ� ī�޶� ���� ��带 �����Ѵ�.
		// @FIXME
		// - �� �������� getCameraPosition �Լ��� ���Ͽ� ī�޶��� ��ġ�� ���� �� ����.
		// �Ƹ��� ���� scene node ������ �ȵǼ� �� ũ�Ⱑ �������� ����.
		// ���� MBR�� �̿����� �ʰ�, ������ 100 ���̿� ī�޶� ��ġ��ų �� �ֵ����Ѵ�.
		Vector3	pos(0, 100, 0);

		m_pCamHolder		= m_pSceneNode->createChildSceneNode(m_strName + "_camHolder", pos);
	}
}

