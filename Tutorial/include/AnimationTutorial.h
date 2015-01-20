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
 *	[20150116] CameraMan �̿��Ͽ� tracking camera ���� �ϼ�.
 */

///////////////////////////////////////////////////////////////////////////////
// FIXME
//	- 1. camera node�� ȭ���� ���� ���ٰ� �ٽ� ���� ���� �� ���尡 �������� �ʴ´�
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "baseapplication.h"
#include "Target.h"
#include "DynamicLines.h"
#include "Trajectory.h"

#include <OgreManualObject.h>
#include <string>
#include <boost/scoped_ptr.hpp>

using namespace	Ogre;
using namespace	std;

#define		TIME_INTERVAL		(1.0)		// 1 second

class CamNodeListener2 : public Ogre::Node::Listener
{
public:
	CamNodeListener2(Ogre::Camera* Cam, Ogre::SceneNode* Target) : mCam(Cam), mCamNode(Target), mPrevPos(Ogre::Vector3::ZERO) 
	{
//		mCamNode	= Target->createChildSceneNode();

		// ���� ī�޶�� ����� ��ġ �� ���⿡ ������ �޴´�
//		mCamNode->attachObject( mCam );

		// ī�޶� ��ġ ���ʱ�ȭ: 
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
	*	//* �������� ǥ���� �� �ٶ󺻴�.
	*	mCam->setPosition( Ogre::Vector3::ZERO ); mCam->lookAt( nod->_getDerivedPosition() );
	*	mCam->setPosition( mPrevPos ); mCam->lookAt( CurrPos ); �� �Ʒ��� ����� ����.
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
//	ManualObject*		m_pCircle;

	//< object for trajectory of fighter
	Trajectory*		m_Trajectory;


	typedef enum { CAM_AUTOTRACKING, CAM_CHASING, CAM_MANUAL } CAM_MODE;

	CAM_MODE				m_CamMode;

	// �� ���� ������ �̵� �� m_ElapseTime �ð����� �̷������ �Ѵ�.
	Real					m_ElapsedTime;
		
	CamNodeListener2*		m_CamListener;
protected:

	int		createSceneNode(string MeshName)
	{
		// create target entity

		m_pTarget	= new CTarget( mSceneMgr, m_vecTarget.size(), MeshName );

		m_vecTarget.push_back( m_pTarget );

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
		Ogre::Real	VAL	= 1;

		///////////////////////////////////////////////////////////////////////
		// +,- Ű�� �̿��Ͽ� viewpoint node ��ġ�� ���������μ� 
		// viewpoint node�� �ٶ� ������ ������ tracking camera�� viewpoint length��
		// �����Ѵ�.
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

		return BaseApplication::keyPressed(arg);
	}

	bool keyReleased(const OIS::KeyEvent &arg)
	{
		return BaseApplication::keyPressed(arg);
	}

	void destroyScene(void);

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

