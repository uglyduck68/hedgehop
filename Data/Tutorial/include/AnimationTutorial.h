/**
 * @file		AnimationTutorial.h
 * @remarks		DDS를 통해서 오브젝트의 이동 좌표를 1초 주기로 받는다.
 *				1초 동안에 30여 프레임 이상의 프레임이 전시됨으로
 *				1초 동안에 전시되는 프레임 사이에서 오브젝트의 이동이
 *				animation 기법으로 전시됨을 테스트 한다.
 *				오브젝트의 움직임을 시뮬레이션하기 위하여
 *				오브젝트를 중심을 기준으로 원형 운동을 하도록 한다.
 *				refer to http://www.ogre3d.org/tikiwiki/tiki-index.php?page=Intermediate+Tutorial+1.
 *				
 * @author		sean kim<uglyduck68@gmail.com>
 * @history
 *	[20141207] try to add chasing camera test codes to check the
 *		functionality of mCameraMan->setTarget() API that is different with
 *		chasing camera. -> is replaced with CameraControlSystem.
 * @Fixme
 *	- 현재의 항공기 궤적은 사전에 만들어 지므로 포탄의 궤적으로 사용되지 못 함.
 *		따라서 동적으로 생성 가능한 궤적 테스트가 필요함.
 */

///////////////////////////////////////////////////////////////////////////////
// FIXME
//	- 1. camera node가 화면을 벗어 났다가 다시 돌아 왔을 때 사운드가 복귀하지 않는다
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
	Real				mDistance;		// 다음 지점까지 남은 거리
	Vector3				mDirection;		// 객체가 움직이고 있는 방향
	Vector3				mDestination;	// 객체가 가고 있는 목표점
	static const int	m_WalkSpeed		= 100;	// character speed


	//< object to display 3D circle that is orbit of fighter
	ManualObject*	m_pCircle;

	//< object for trajetory of fighter
	DynamicLines*		m_Trajectory;

	typedef enum { CAM_AUTOTRACKING, CAM_CHASING, CAM_MANUAL } CAM_MODE;

	CAM_MODE				m_CamMode;

	// 두 지점 사이의 이동 시 m_ElapseTime 시간내에 이루어져야 한다.
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
				// auto tracking 기능은 mCamera 수준에서 이루어 지며,
				// 일단 auto tracking 이 시작되면 CS_ORBIT인 경우는
				// 마우스 제어가 눈으로 확인되나,
				// CS_FREELOOK인 경우는 거의 제어가 안되는 것처럼 보인다.
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
	*				일일이 좌표를 계산하고 translate 시키지 않아도 이 함수와 같이 animation 시킬 수 있다.
	*				아래 함수는 위 링크의 샘플이다. 하지만 아마도 동작하지 않을 듯 하다.
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
	//	- DDS로 부터 받은 좌표 2 점 (이 두 점을 받는 시간 간격은 보통 1초로 가정한다)
	//		사이를 별도의 좌표 계산 없이 NodeAnimationTrack 방법으로 수행 가능한지 테스트.
	//////////////////////////////////////////////////////////////////////////////
	AnimationState*		mAnimState;
};

