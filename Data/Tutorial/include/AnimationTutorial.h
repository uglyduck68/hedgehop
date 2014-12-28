/**
 * @file		AnimationTutorial.h
 * @remarks		DDS�� ���ؼ� ������Ʈ�� �̵� ��ǥ�� 1�� �ֱ�� �޴´�.
 *				1�� ���ȿ� 30�� ������ �̻��� �������� ���õ�����
 *				1�� ���ȿ� ���õǴ� ������ ���̿��� ������Ʈ�� �̵���
 *				animation ������� ���õ��� �׽�Ʈ �Ѵ�.
 *				������Ʈ�� �������� �ùķ��̼��ϱ� ���Ͽ�
 *				������Ʈ�� �߽��� �������� ���� ��� �ϵ��� �Ѵ�.
 *				refer to http://www.ogre3d.org/tikiwiki/tiki-index.php?page=Intermediate+Tutorial+1.
 *				
 * @author		sean kim<uglyduck68@gmail.com>
 * @history
 *	[20141207] try to add chasing camera test codes to check the
 *		functionality of mCameraMan->setTarget() API that is different with
 *		chasing camera. -> is replaced with CameraControlSystem.
 * @Fixme
 *	- ������ �װ��� ������ ������ ����� ���Ƿ� ��ź�� �������� ������ �� ��.
 *		���� �������� ���� ������ ���� �׽�Ʈ�� �ʿ���.
 */

///////////////////////////////////////////////////////////////////////////////
// FIXME
//	- 1. camera node�� ȭ���� ���� ���ٰ� �ٽ� ���� ���� �� ���尡 �������� �ʴ´�
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "baseapplication.h"
#include "Target.h"
#include "DynamicLines.h"

#include <OgreManualObject.h>
#include <string>

using namespace	Ogre;
using namespace	std;

#define		DEL(p)	if(p) {delete p; p=NULL;}
#define		TIME_INTERVAL		(1.0)		// 1 second

class AnimationTutorial :
	public BaseApplication
{
public:
	AnimationTutorial(void);
	~AnimationTutorial(void);
protected:
	SceneNode*				m_pSceneNode;	// scene node
	SceneNode*				m_pCamNode;		// camera node for chase camera

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

	//< object for trajetory of fighter
	DynamicLines*		m_Trajectory;

	typedef enum { CAM_AUTOTRACKING, CAM_CHASING, CAM_MANUAL } CAM_MODE;

	CAM_MODE				m_CamMode;

	// �� ���� ������ �̵� �� m_ElapseTime �ð����� �̷������ �Ѵ�.
	Real					m_ElapsedTime;

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

	bool nextLocation(Real& distance);

	bool keyPressed(const OIS::KeyEvent &arg)
	{
		/////////
		// set auto tracking.
		// In auto tracking mode mouse control is disabled.
		/////////
		if( arg.key	== OIS::KC_A )
		{
			if( m_CamMode != CAM_AUTOTRACKING )
			{
				//////
				// auto tracking ����� mCamera ���ؿ��� �̷�� ����,
				// �ϴ� auto tracking �� ���۵Ǹ� CS_ORBIT�� ����
				// ���콺 ��� ������ Ȯ�εǳ�,
				// CS_FREELOOK�� ���� ���� ��� �ȵǴ� ��ó�� ���δ�.
				//////
				mCameraMan->setTarget( GetSceneNode() );

				m_CamMode	= CAM_AUTOTRACKING;
			}
			else
			{
			}
		}
		else if ( arg.key == OIS::KC_C )
		{
			if( m_CamMode == CAM_AUTOTRACKING )
			{
				// cancel auto tracking
				mCameraMan->setTarget( NULL );
			}

			m_CamMode	= CAM_CHASING;
			
			SceneNode*	pSN	= GetSceneNode();

//			mCamera->setPosition( pSN->_getDerivedPosition() + Vector3(0, 50, -100) );
//			mCamera->lookAt( pSN->_getDerivedPosition() + Vector3(0, 0, 100) );


			// move camera befind the target
		}
		else if (arg.key == OIS::KC_M )
		{
			if( m_CamMode == CAM_AUTOTRACKING )
			{
				// cancel auto tracking
				mCameraMan->setTarget( NULL );
			}

			m_CamMode	= CAM_MANUAL;
		}

		return BaseApplication::keyPressed(arg);
	}


	/**
	*@function		initCameraAnimation
	*@remarks		refer to TestCameraControlSystem and http://www.ogre3d.org/forums/viewtopic.php?f=21&t=66840.
	*				������ ��ǥ�� ����ϰ� translate ��Ű�� �ʾƵ� �� �Լ��� ���� animation ��ų �� �ִ�.
	*				�Ʒ� �Լ��� �� ��ũ�� �����̴�. ������ �Ƹ��� �������� ���� �� �ϴ�.
	*/

	SceneNode*			mCamNode;
	AnimationState*		mCamAnimState;

	void InitCameraAnimations()
	{

		mCamNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("camera node");
		mCamNode->attachObject(mCamera);

		Ogre::Animation* mCamAnim = mSceneMgr->createAnimation( "Camera Animation", 10 );
		mCamAnim ->setInterpolationMode( Ogre::Animation::IM_SPLINE );
	   // mCamAnim->setRotationInterpolationMode(Animation::RIM_SPHERICAL);

		Ogre::NodeAnimationTrack* mCamTrack = mCamAnim->createNodeTrack( 0, mCamNode );

	   // mCamTrack->setUseShortestRotationPath( true );

		Ogre::TransformKeyFrame* mCamKey;
   
		mCamKey= mCamTrack->createNodeKeyFrame( 0 );
		mCamKey->setTranslate( Ogre::Vector3(0, 0, 100) );
  
	   mCamKey= mCamTrack->createNodeKeyFrame( 10 );
	   mCamKey->setTranslate( Ogre::Vector3(0, 0, 150) );

		//mCamKey->setRotation( Ogre::Quaternion(0.1,0.1,0.1,0.1) );

		mCamAnimState = mSceneMgr->createAnimationState( "Camera Animation" );

		/////////
		// If you want to start animation, then just call setEnable.
		/////////
		mCamAnimState->setEnabled( true );
	}

	///////////////////////////////////////////////////////////////////////////
	// Other Animation Test
	//	- DDS�� ���� ���� ��ǥ 2 �� (�� �� ���� �޴� �ð� ������ ���� 1�ʷ� �����Ѵ�)
	//		���̸� ������ ��ǥ ��� ���� NodeAnimationTrack ������� ���� �������� �׽�Ʈ.
	//////////////////////////////////////////////////////////////////////////////
	AnimationState*		mAnimState;
};

