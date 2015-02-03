#include "StdAfx.h"
#include "..\include\AnimationTutorial.h"
#include "OgreOggSound.h"

#include <new>


using namespace	Ogre;
using namespace	OgreOggSound;

/**
* @function		getCameraPosition
* @param		target
* @param		back that MBR과 노드의 방향을 고려한 상단 후방 중앙점
* @param		front that MBR과 노드의 방향을 고려한 상단 전방 중앙점
* @remarks		*NOT* yet implemented.
*/
int getCameraPosition(const Ogre::SceneNode* target, Vector3& back, Vector3& front)
{
	AxisAlignedBox	bb	= target->_getWorldAABB();
	const Vector3			min	= bb.getMinimum();
	const Vector3			max	= bb.getMaximum();
	Vector3					a, b;

	// B787.mesh는 -Z 방향임
//	if( target->getOrientation() == Quaternion(Degree(180), Vector3::UNIT_Y) )
	{
		// -Z축을 보고 있는 경우, 후방 중앙에서 살짝 높고, 뒤에 위치하도록 조정
		a.x	= min.x; a.y = max.y + 10; a.z = max.z + 10;
		b.x = max.x; b.y = max.y; b.z = max.z;
	}
	//else if ( target->getOrientation() == Quaternion(Degree(0), Vector3::UNIT_Y))
	//{
	//	// +Z축을 보고 있는 경우
	//	a.x	= min.x; a.y = max.y; a.z = min.z;
	//	b.x = max.x; b.y = max.y; b.z = min.z;
	//}

	Vector3	c	= a	+ b;
	c	*= 0.5;

	back	= c;
#if	0	
	// check the coordinate of AABB is changed when scene node rotates. 
	// the coordinate is changed.
	Ogre::LogManager::getSingleton().logMessage( "min coord: " + StringConverter::toString(min));
	Ogre::LogManager::getSingleton().logMessage( "max coord: " + StringConverter::toString(max));
#endif
	return 1;
}


void CamNodeListener2::nodeUpdated(const Ogre::SceneNode *nod, const Ogre::FrameEvent& evt)
{ 

	Ogre::Vector3		CurrPos		= nod->_getDerivedPosition();
	Ogre::Vector3		pos;

	CurrPos.y	+= 100;
	CurrPos.z	-= 100;

//	mCam->setPosition( m_pTarget->GetSceneNode()->getCameraPosition() );
};

AnimationTutorial::AnimationTutorial(void) :
	m_pSceneNode(NULL), mDirection(Vector3::ZERO), 
	m_CamMode(CAM_MANUAL), m_pCamNode(NULL),
	m_ElapsedTime(TIME_INTERVAL_1_SEC),
	m_CamListener(NULL),
	m_Trajectory(NULL),		// trajetory of fighter
	mRotating(false),
	mRotatingTime(0.0f)
{
}


AnimationTutorial::~AnimationTutorial(void)
{
	// delete all targets
	for( std::vector<CTarget*>::iterator itr = m_vecTarget.begin(); itr != m_vecTarget.end(); itr++ )
	{
		if( *itr )
		{
			DEL(*itr);
		}
	}

	//////
	// FIXME
	//	- following cause abort error at exit
	//////
//	DEL( m_Trajectory );
}

void AnimationTutorial::destroyScene(void)
{
//	DEL( m_Trajectory );
}

	
void AnimationTutorial::createFrameListener(void)
{
	// create keyboard & mouse and Register this for handing key & mouse event
	BaseApplication::createFrameListener();
}

bool AnimationTutorial::nextLocation(Real& distance)
{
	if(m_WalkList.empty())
	{
		return false;
	}

	mDestination = m_WalkList.front(); 
	m_WalkList.pop_front();

#if	1
	// loop indefinitely
	m_WalkList.push_back( mDestination );
#else
#endif
		
	mDirection	= mDestination - GetSceneNode()->getPosition();
	mDistance	= mDirection.normalise();

	distance	= mDirection.length();

	/*
	* for 부드러운 회전
	*/
	mSrcQuat	= GetSceneNode()->getOrientation();

	// @FIXME
	// 현재 B787.mesh가 -Z 방향이므로, 추후 Z 방향으로 수정 시 소스 수정
	mDestQuat		= Vector3(Vector3::UNIT_Z).getRotationTo (mDirection);
	mRotating		= false;
	mRotatingTime	= 0.0f;

	return true;
}

void AnimationTutorial::createScene()
{
	//////////////////////////////////////////////////////////////////////////////
	// initialize particle system setting
	//////////////////////////////////////////////////////////////////////////////
	ParticleSystem::setDefaultNonVisibleUpdateTimeout(5);  // set nonvisible timeout

	//////////////////////////////////////////////////////////////////////////////
	// initialize ogg sound
	//////////////////////////////////////////////////////////////////////////////
	OgreOggSound::OgreOggSoundManager *mSoundManager	= OgreOggSoundManager::getSingletonPtr();
	
	if( mSoundManager )
		mSoundManager->init();

	// mCamera->getParentSceneNode() return NULL

	// move codes to below for chase camera
	if( mCamera->getParentSceneNode() )
		mCamera->getParentSceneNode()->attachObject(mSoundManager->getListener());

	//////////////////////////////////////////////////////////////////////////////
	// from here create targets
	//////////////////////////////////////////////////////////////////////////////
	m_pTarget	= new (std::nothrow) CTarget( mSceneMgr, m_vecTarget.size(), "B787.mesh" );

	if (m_pTarget)
	{
		m_pTarget->createScene();
		m_vecTarget.push_back( m_pTarget );
	}


	GetSceneNode()->setPosition( Vector3(0, 100, 500) );

	//////
	// add camera to scene node for chase camera. *NOT* used.
	//////
	m_pCamNode	= GetSceneNode()->createChildSceneNode();
	//m_pCamNode->attachObject( mCamera );

	if( mCamera->getParentSceneNode() )
		mCamera->getParentSceneNode()->attachObject(mSoundManager->getListener());

	///////////////////////////////////////////////////////////////////////
	// Sean, register node listener to change the position of camera whenever node move
	///////////////////////////////////////////////////////////////////////
	m_CamListener	= new CamNodeListener2( mCamera, GetSceneNode() );

	//* change to call nodeUpdated in frameStarted
//	GetSceneNode()->setListener( m_CamListener );

	///////////////////////////////////////////////////////////////////////////
	// set auto tracking using cameraman
	///////////////////////////////////////////////////////////////////////////
	SetChasingMode(false);

	m_pTarget->SetEffect (CTarget::EFT_ALL);

	//////////////////////////////////////////////////////////////////////////////
	// create 3D circle
	//////////////////////////////////////////////////////////////////////////////
//	m_pCircle	= mSceneMgr->createManualObject("3D circle");

	// get the distance from origin to this scene node
	Vector3		ScenePos		= GetSceneNode()->getPosition();
	Real		Radius			= ScenePos.distance( Vector3::ZERO );

	if( Radius == 0 )
		Radius		= 500;

	// accurary is the count of points (and lines)
	Ogre::Real const Accurary	= MAX_INDEX / 2;
	//////////////////////////////////////////////////////////////////////////////
	// create Trajectory
	//////////////////////////////////////////////////////////////////////////////
	m_Trajectory	= ::new (std::nothrow) Trajectory( mSceneMgr, RenderOperation::OT_LINE_STRIP);

//	m_pCircle->begin("BaseWhiteNoLighting", RenderOperation::OT_LINE_STRIP );

	unsigned	nPointIndex	= 0;
	Vector3		vPos;

	// make waypoints
	for( Ogre::Real theta = 0; theta <= 2 * Math::PI; theta += Math::PI / Accurary )
	{
		vPos.x	= Radius * cos( theta );
		vPos.y	= ScenePos.y;
		vPos.z	= Radius * sin( theta );

		m_WalkList.push_back( vPos );

		if( nPointIndex == 0 )
		{
			// set initial position
			GetSceneNode()->setPosition( m_WalkList.front() );
			m_WalkList.pop_front();
		}
		else
		{
			//m_paTrack[ nPointIndex ]	= new CFighter( mSceneMgr, nPointIndex + 1, m_strMeshName );

			//// move fighter to destination
			//m_paTrack[ nPointIndex ]->MoveTo( m_aCirclePos[ nPointIndex - 1 ], m_aCirclePos[ nPointIndex ]);
		}
		nPointIndex++;

//		m_pCircle->position( vPos );
//		m_pCircle->index( nPointIndex++ );
	}

//	m_pCircle->index( 0 );
//	m_pCircle->end();

	if( m_Trajectory == NULL)
	{
		Ogre::LogManager::getSingleton().logMessage("Error: fail to create DynamicLines");
	}
	else
	{
		m_Trajectory->update();
	}


//	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject( m_pCircle );

	//////////////////////////////////////////////////////////////////////////////
	// create lights
	//////////////////////////////////////////////////////////////////////////////
    // Set ambient light
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

    // Create a light
    Ogre::Light* l = mSceneMgr->createLight("MainLight");
    l->setPosition(20,80,50);

	//////////////////////////////////////////////////////////////////////////////
	// create debug overlay
	//////////////////////////////////////////////////////////////////////////////
	createDebugOverlay();

	// for debugging
	mSceneMgr->showBoundingBoxes(true);

	printMsgToDebugOverlay( Ogre::String("press + or -/up or down key to control viewpoint of tracking camera/camera itself\npress M to change camera mode\npress E to change effects"));
}

/**
* @function		frameRenderingQueued
* @remarks		render character
*/
bool  AnimationTutorial::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
	return BaseApplication::frameRenderingQueued( evt );
}

/**
* @function		frameStarted
* @remarks		make animation effect
*/
bool  AnimationTutorial::frameStarted(const Ogre::FrameEvent& evt)
{
//	MoveTo(m_aCirclePos[ 0 ], m_aCirclePos[ 1 ], evt);
	Real	waypointDistance;

	if(mDirection == Vector3::ZERO)
	{
		// set direction and distance to move for character
		if(nextLocation(waypointDistance))
		{
			if( m_Trajectory )
			{
				m_Trajectory->addPoint( mDestination );
				m_Trajectory->update();
			}
		}

		// In the future move this into nextLocation
		m_ElapsedTime	= TIME_INTERVAL_1_SEC;
	}
	else if (mRotating)
	{
		/*
		* for 부드러운 회전
		*/

		/*
		* @FIXME
		* 가상전장환경에서 target 위치 정보는 0.5초 단위로 날라 온다.
		* 단지 이 예제에서 원을 이루는 각 구간 사이의 시간이 0.5초 미만으로
		*/
		static const Real	ROTATION_TIME	= TIME_INTERVAL_1_SEC;

		mRotatingTime		+= evt.timeSinceLastFrame;
		mRotatingTime		= (mRotatingTime > ROTATION_TIME) ? ROTATION_TIME: mRotatingTime;

		Quaternion	delta	= Quaternion::Slerp(mRotatingTime / ROTATION_TIME, mSrcQuat, mDestQuat, true);

		GetSceneNode()->setOrientation (delta);

		if (mRotatingTime >= ROTATION_TIME)
		{
			mRotatingTime	= 0.0f;
			mRotating		= false;
		}
	}
	else
	{
		/////////////////////////////////////////////////////////////////////////////
		// FIX
		//	- 
		/////////////////////////////////////////////////////////////////////////////

		// calculate the distance to go
		Real move	= m_WalkSpeed * evt.timeSinceLastFrame;

		// calculate the remaining distance
		mDistance	-= move;

		if(mDistance <= 0.0f/*m_ElapsedTime <= 0*/)
		{
			// if character reaches the waypoint
			// the remaining distance is less then zero
			GetSceneNode()->setPosition(mDestination);

			// clear direction to set the next waypoins
			mDirection = Vector3::ZERO;

			if(nextLocation(waypointDistance))
			{
				//////
				// add trajectory
				//////
				if( m_Trajectory )
				{
					m_Trajectory->addPoint( mDestination );
					m_Trajectory->update();
				}

				///////////////////////////////////////////////////////////////
				// [20150116] Sean, B787 mesh가 현재 -Z 방향이다.
				///////////////////////////////////////////////////////////////
				Vector3 src = GetSceneNode()->getOrientation() * Vector3::UNIT_Z;

				// if angle of two vector is 180, then dot product is -1.
				if(1.0f + src.dotProduct(mDirection) < 0.0001f)
				{
					GetSceneNode()->yaw(Degree(180));
				}
				else
				{
					Ogre::Quaternion quat = src.getRotationTo(mDirection);
					GetSceneNode()->rotate(quat);
				}
			}

			// In the future move this into nextLocation
			m_ElapsedTime	= TIME_INTERVAL_1_SEC;
		}
		else
		{
			GetSceneNode()->translate(mDirection * move);
		}
	}

	/////////
	// call camera listener to move camera before node to move
	// 즉, chase camera가 아니다.
	/////////
//	if( m_CamListener )
//		m_CamListener->nodeUpdated( GetSceneNode(), evt );
	
	if ( m_CamMode == CAM_CHASING)
		m_pTarget->setTrackingCameraPosition(mCamera);

	m_ElapsedTime	-= evt.timeSinceLastFrame;

#if	0
	// print amount time taken to move between two way points
	Ogre::LogManager::getSingleton().logMessage( "scenode pos: " + StringConverter::toString(m_pTarget->GetSceneNode()->_getDerivedPosition()) + 
		" viewnode: " + StringConverter::toString(m_pTarget->GetViewpointNode()->_getDerivedPosition()));
#endif
	return true;
}


/*
* @function		MoveTo that translate mesh to @Dest and set mesh's
* orientation to @Dest
* @param		Src	that is mesh's current position
* @param		Dest that is mesh's destination position
* @return		1 if success
*/
int		AnimationTutorial::MoveTo( Ogre::Vector3 Src, Ogre::Vector3 Dest, const Ogre::FrameEvent& evt )
{
	// get the direction vector from source to destination
	Vector3			Dir				= Dest - Src;

	// normalize the direction vector
	Ogre::Real		Dist			= Dir.normalise();

	// get the orientation quaternion based on Z-axis
	// because the orientation of all models are Z-axis on XZ plane.
	Quaternion		quat			= Vector3(Vector3::UNIT_Z).getRotationTo( Dir );

	// set target's orientation to destination
	GetSceneNode()->setOrientation( quat );

	// move target to destination
	GetSceneNode()->setPosition( Dest );

	return true;
}