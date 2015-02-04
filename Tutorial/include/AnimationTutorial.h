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
 *	[20150116] CameraMan 이용하여 tracking camera 샘플 완성.
 */

///////////////////////////////////////////////////////////////////////////////
// FIXME
//	- 1. camera node가 화면을 벗어 났다가 다시 돌아 왔을 때 사운드가 복귀하지 않는다
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "baseapplication.h"
#include "Target.h"
#include "CH_53E.h"	// for hellicopter
#include "DynamicLines.h"
#include "Trajectory.h"

#include <OgreManualObject.h>
#include <string>
#include <boost/scoped_ptr.hpp>

using namespace	Ogre;
using namespace	std;

#define		TIME_INTERVAL_1_SEC		(0.1)		// 1 second

class CamNodeListener2 : public Ogre::Node::Listener
{
public:
	CamNodeListener2(Ogre::Camera* Cam, Ogre::SceneNode* Target) : mCam(Cam), mCamNode(Target), mPrevPos(Ogre::Vector3::ZERO) 
	{
//		mCamNode	= Target->createChildSceneNode();

		// 이제 카메라는 노드의 위치 및 방향에 영향을 받는다
//		mCamNode->attachObject( mCam );

		// 카메라 위치 재초기화: 
		mCam->setPosition( Target->_getDerivedPosition()/*Vector3::ZERO*/ );
		mCam->setOrientation( Target->getOrientation() );
	};

	~CamNodeListener2(){};

	SceneNode* GetSceneNode()
	{
		return mCamNode;
	}

	Vector3& locateCameraOnTarget(Vector3& pos)
	{
		pos.y	+= 100;
		pos.z	-= 100;

		return pos;
	}
	/**
	* @function		nodeUpdated
	* @remarks		
	*	//* 원점에서 표적을 잘 바라본다.
	*	mCam->setPosition( Ogre::Vector3::ZERO ); mCam->lookAt( nod->_getDerivedPosition() );
	*	mCam->setPosition( mPrevPos ); mCam->lookAt( CurrPos ); 는 아래와 결과가 같다.
	*	mCam->setPosition( mPrevPos ); mCam->lookAt( Ogre::Vector3::ZERO ); 
	*/
	void nodeUpdated(const Ogre::SceneNode *nod, const Ogre::FrameEvent& evt);

protected:
	Ogre::Real			mTimeSinceLastFrame;

	// the previous position of target node that is used to
	// calculate the orientation of target
	// target orientation is directional vector from previous to current position
	Ogre::Vector3		mPrevPos;
	Ogre::SceneNode*	mCamNode;
	Ogre::Camera*		mCam;
};


class AnimationTutorial :
	public BaseApplication
{
public:
	AnimationTutorial(void);
	~AnimationTutorial(void);
protected:
	SceneNode*				m_pSceneNode;	// scene node
	SceneNode*				m_pCamNode;		// camera node for chase camera
	CTarget*				m_pTarget;

	std::vector<CTarget*>	m_vecTarget;

	/**
	* 부드러운 회전을 위한 변수 선언
	*/
	bool					mRotating;		// 현재 구면보간을 이용하여 회전 중인가?
	Quaternion				mSrcQuat;
	Quaternion				mDestQuat;
	Real					mRotatingTime;	// 회전 경과 시간

	SceneNode*	GetSceneNode(int nIndex = 0)
	{
		if( m_vecTarget.size() > 0 )
			return *m_vecTarget[nIndex];

		// error case
		assert(m_vecTarget.size() > 0);

		return NULL;

//		return m_pSceneNode;
	}

	//< coordinate of 3D circle
	std::deque<Vector3> m_WalkList;		// set of waypoint
	Real				mDistance;		// 다음 지점까지 남은 거리
	Vector3				mDirection;		// 객체가 움직이고 있는 방향
	Vector3				mDestination;	// 객체가 가고 있는 목표점

	/*
	* for 부드러운 회전
	* 원래는 100 이였으나 속도가 너무 빨라 TIME_INTERVAL_1_SEC 시간 동안
	* 회전해야할 부분을 넘어서게 된다. 따라서 속도롤 줄인다.
	*/
	static const int	m_WalkSpeed		= 100;	// character speed. change speed to 10 from 100.
	static const int	MAX_INDEX		= 100;	// # of points that make up circle. change speed to 50 from 100.



	//< object to display 3D circle that is orbit of fighter
//	ManualObject*		m_pCircle;

	//< object for trajectory of fighter
	Trajectory*		m_Trajectory;


	typedef enum { 
		CAM_AUTOTRACKING,	// *NOT* used
		CAM_CHASING,		// target tracking camera mode
		CAM_MANUAL			// free run mode (방향키와 마우스로 viewpoint 제어
	} CAM_MODE;

	CAM_MODE				m_CamMode;

	// 두 지점 사이의 이동 시 m_ElapseTime 시간내에 이루어져야 한다.
	Real					m_ElapsedTime;
		
	CamNodeListener2*		m_CamListener;
protected:

	void	SetChasingMode(bool bChaseMode)
	{
		if (bChaseMode == true)
		{
			mCameraMan->setStyle(OgreBites::CS_MANUAL);					// we will be controlling the camera ourselves, so disable the camera man
			mCamera->setAutoTracking(true, m_pTarget->GetViewpointNode());				// make the camera face the head
			m_pTarget->setTrackingCameraPosition (mCamera);
		
			m_CamMode	= CAM_CHASING;
		}
		else
		{
			mCameraMan->setStyle(OgreBites::CS_FREELOOK);					// we will be controlling the camera ourselves, so disable the camera man

			m_CamMode	= CAM_MANUAL;
		}
	}

	//int		createSceneNode(string MeshName)
	//{
	//	// create target entity

	//	m_pTarget	= new (std::nothrow) CTarget( mSceneMgr, m_vecTarget.size(), MeshName );

	//	if (m_pTarget)
	//	{
	//		m_pTarget->createScene();
	//		m_vecTarget.push_back( m_pTarget );
	//	}

	//	return 1;
	//}

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
		Ogre::Real	VAL	= 1;

		///////////////////////////////////////////////////////////////////////
		// +,- 키를 이용하여 viewpoint node 위치를 조절함으로서 
		// viewpoint node를 바라 보도록 설정된 tracking camera의 viewpoint length를
		// 조절한다.
		// 일부 키가 이미 BaseApplication::keyPressed() 에서 처리되고 있기 때문에
		// else 문으로 처리한다.
		///////////////////////////////////////////////////////////////////////
		if( arg.key	== OIS::KC_ADD )
		{
			// + key on number pad
			m_pTarget->GetViewpointNode()->translate (0, 0, -VAL);
		}
		else if (arg.key == OIS::KC_SUBTRACT)
		{
			// - key on number pad
			m_pTarget->GetViewpointNode()->translate (0, 0, VAL);
		}
		else if (arg.key == OIS::KC_UP)
		{
			m_pTarget->GetCamNode()->translate(0, VAL, 0);
		}
		else if (arg.key == OIS::KC_DOWN)
		{
			m_pTarget->GetCamNode()->translate(0, -VAL, 0);
		}
		else if (arg.key == OIS::KC_M)
		{
			// toggle camera mode
			if (m_CamMode == CAM_CHASING)
			{
				SetChasingMode(false);

				setupCameraPosition();
			}
			else if (m_CamMode == CAM_MANUAL)
			{
				SetChasingMode(true);
			}
		}
		else if (arg.key == OIS::KC_E)
		{
			// change the effects
			switch(m_pTarget->GetEffect())
			{
			case CTarget::EFT_ALL:
				m_pTarget->SetEffect(CTarget::EFT_JETENGINE);
				break;
			case CTarget::EFT_JETENGINE:
				m_pTarget->SetEffect(CTarget::EFT_SMOKE);
				break;
			case CTarget::EFT_SMOKE:
				m_pTarget->SetEffect(CTarget::EFT_EXPLOSION);
				break;
			case CTarget::EFT_EXPLOSION:
				m_pTarget->SetEffect(CTarget::EFT_WATER_EXPLOSION);
				break;
			case CTarget::EFT_WATER_EXPLOSION:
				m_pTarget->SetEffect(CTarget::EFT_ALL);
				break;
			default:
				break;
			}
		}
		else
		{
			// process other keys
			return BaseApplication::keyPressed(arg);
		}

		return true;
	}

	bool keyReleased(const OIS::KeyEvent &arg)
	{
		return BaseApplication::keyReleased(arg);
	}

	void destroyScene(void);

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

