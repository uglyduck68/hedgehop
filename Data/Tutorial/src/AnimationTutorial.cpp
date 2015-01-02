#include "StdAfx.h"
#include "..\include\AnimationTutorial.h"
#include "OgreOggSound.h"

#include <new>


using namespace	Ogre;
using namespace	OgreOggSound;

AnimationTutorial::AnimationTutorial(void) :
	m_pSceneNode(NULL), mDirection(Vector3::ZERO), 
	m_CamMode(CAM_MANUAL), m_pCamNode(NULL),
	m_ElapsedTime(TIME_INTERVAL),
	m_Trajectory(NULL)		// trajetory of fighter
{
//	mTrajectory.reset( new CTrajectory( GetSceneManager() ) );
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

	//while( !m_lstTarget.empty() )
	//{
	//	CTarget*	pTarget	= m_lstTarget.front(); m_lstTarget.pop_front();

	//	DEL(pTarget);
	//}
}
	
void AnimationTutorial::createFrameListener(void)
{
	BaseApplication::createFrameListener();

//	mRoot->addFrameListener(this);
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
	createSceneNode("razor.mesh");
	GetSceneNode()->setPosition( Vector3(0, 0, 500) );

	//////
	// add camera to scene node for chase camera
	//////
	m_pCamNode	= GetSceneNode()->createChildSceneNode();
	//m_pCamNode->attachObject( mCamera );

	if( mCamera->getParentSceneNode() )
		mCamera->getParentSceneNode()->attachObject(mSoundManager->getListener());

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
	m_Trajectory	= ::new (std::nothrow) DynamicLines(RenderOperation::OT_LINE_STRIP);

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
		if( nPointIndex == 1 )
		m_Trajectory->addPoint( vPos );
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
		SceneNode*	pLinesNode	= mSceneMgr->getRootSceneNode()->createChildSceneNode("lines");
		pLinesNode->attachObject( static_cast<Ogre::MovableObject*>( m_Trajectory ));

//		mTrajectoryNode			= mSceneMgr->getRootSceneNode()->createChildSceneNode("Trajectory");
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
//	createDebugOverlay();

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
		m_ElapsedTime	= TIME_INTERVAL;
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

		if(mDistance <= 0.0f)
		{
			// if character reaches the waypoint
			// the remaining distance is less then zero
			GetSceneNode()->setPosition(mDestination);

			// clear direction to set the next waypoins
			mDirection = Vector3::ZERO;

			if(nextLocation(waypointDistance))
			{
			if( m_Trajectory )
			{
				m_Trajectory->addPoint( mDestination );
				m_Trajectory->update();
			}
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

			// print amount time taken to move between two way points
			printMsgToDebugOverlay( "waypoint distance: " + StringConverter::toString(mDistance) + ", elapsed time is " + StringConverter::toString(TIME_INTERVAL - m_ElapsedTime));
	
			// In the future move this into nextLocation
			m_ElapsedTime	= TIME_INTERVAL;
		}
		else
		{
			GetSceneNode()->translate(mDirection * move);
		}
	}

	m_ElapsedTime	-= evt.timeSinceLastFrame;


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