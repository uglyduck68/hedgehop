#include "StdAfx.h"
#include "..\include\CH_53E.h"


CCH_53E::CCH_53E(void) : mAnimState(NULL)
{
}

/**
 *@function		CCH_53
 *@brief		create hellicopter
 */
CCH_53E::CCH_53E(Ogre::SceneManager* pSceneMgr, int name, string mesh) : CAirVessel(pSceneMgr, name, mesh), mAnimState(NULL)
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

	assert(m_pSceneNode != NULL && pEntity != NULL);

	GetSceneNode()->attachObject(pEntity);

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

	///////////
	// To animate mesh to test collision
	///////////
	///< getAnimation or hasAnimation API
    Animation* anim = mSceneMgr->createAnimation(m_strName + "_Track", 2);
        
	// Spline it for nice curves
    anim->setInterpolationMode(Animation::IM_SPLINE);

    // Create a track to animate the camera's node
    NodeAnimationTrack* track = anim->createNodeTrack(0, GetSceneNode());
    
	Vector3		aniPos(500, 100, 0);	// start position

	//// Setup keyframes
    TransformKeyFrame* key = track->createNodeKeyFrame(0); // startposition (1)
    key->setTranslate(aniPos + Vector3(0, 0, 0));
    key->setRotation(Ogre::Quaternion::IDENTITY);

	// west�� �ٶ󺸵��� target ȸ��
//    key->setRotation(Quaternion(Degree(-90), Vector3::UNIT_Y));

    key = track->createNodeKeyFrame(1);	// (2)
    key->setTranslate(aniPos + Vector3(-1000, 0, 500));
	// �ٽ� ���� ������� �ٶ󺸵��� target ȸ��
//    key->setRotation(Quaternion(Degree(-180), Vector3::UNIT_Y));

#if	0
    // Create a new animation state to track this
    mAnimState = mSceneMgr->createAnimationState(m_strName + "_Track");
    mAnimState->setEnabled(true);


        // Create a track to animate the camera's node
        NodeAnimationTrack* track = anim->createNodeTrack(0, GetSceneNode());
        
		// Setup keyframes
        TransformKeyFrame* key = track->createNodeKeyFrame(0); // startposition (1)
        key->setTranslate(Vector3(0,0,0));
        key->setRotation(Ogre::Quaternion::IDENTITY);

        key = track->createNodeKeyFrame(2.5);	// (2)
        key->setTranslate(Vector3(0,0,1000));
        key->setRotation(Vector3::UNIT_Z.getRotationTo(Vector3(1000,0,1000)));

        key = track->createNodeKeyFrame(5);	// (3)
        key->setTranslate(Vector3(1000,0,1000));
        key->setRotation(Vector3::UNIT_Z.getRotationTo(Vector3(1000,0,0)));

        key = track->createNodeKeyFrame(7.5);	// (4)
        key->setTranslate(Vector3(1000,0,0));
        key->setRotation(Vector3::UNIT_Z.getRotationTo(Vector3::NEGATIVE_UNIT_X));

        key = track->createNodeKeyFrame(10);	// (5)
        key->setTranslate(Vector3(0,0,0));

        // Second round
        key = track->createNodeKeyFrame(11);	// (6)
        key->setTranslate(Vector3(0,0,400));
        key->setRotation(Quaternion(Radian(3.14/4.0),Vector3::UNIT_Z));
        key = track->createNodeKeyFrame(11.5);	// (7)
        key->setTranslate(Vector3(0,0,600));
        key->setRotation(Quaternion(Radian(-3.14/4.0),Vector3::UNIT_Z));
        key = track->createNodeKeyFrame(12.5);	// (8)
        key->setTranslate(Vector3(0,0,1000));
        key->setRotation(Vector3::UNIT_Z.getRotationTo(Vector3(500,500,1000)));
        key = track->createNodeKeyFrame(13.25);	// (9)
        key->setTranslate(Vector3(500,500,1000));
        key->setRotation(Vector3::UNIT_Z.getRotationTo(Vector3(1000,-500,1000)));
        key = track->createNodeKeyFrame(15);	// (10)
        key->setTranslate(Vector3(1000,0,1000));
        key->setRotation(Vector3::UNIT_Z.getRotationTo(Vector3(1000,0,-500)));
        key = track->createNodeKeyFrame(16);	// (11)
        key->setTranslate(Vector3(1000,0,500));
        key = track->createNodeKeyFrame(16.5);
        key->setTranslate(Vector3(1000,0,600));
        key = track->createNodeKeyFrame(17.5);
        key->setTranslate(Vector3(1000,0,0));
        key->setRotation(Vector3::UNIT_Z.getRotationTo(Vector3(-500,500,0)));
        key = track->createNodeKeyFrame(18.25);	// (12) 118.25? �� �길 ���� 20 ���� ũ��? ��Ÿ?
												// 118.25�� 18.25�� �ٲ㵵 ���� �޶��������� �� �𸣰���.
        key->setTranslate(Vector3(500,500,0));
        key->setRotation(Quaternion(Radian(3.14),Vector3::UNIT_X) * Vector3::UNIT_Z.getRotationTo(Vector3(-500,-500,0)));
        key = track->createNodeKeyFrame(20);	// (13)
        key->setTranslate(Vector3(0,0,0));
#endif
        // Create a new animation state to track this
        mAnimState = mSceneMgr->createAnimationState(m_strName + "_Track");
        mAnimState->setEnabled(true);

}

bool CCH_53E::frameStarted(const FrameEvent &e)
{
	mAnimState->addTime(e.timeSinceLastFrame);

	return true;
}


