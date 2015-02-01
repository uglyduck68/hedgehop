#include "StdAfx.h"
#include "..\include\Fighter.h"


CFighter::CFighter(Ogre::SceneManager* pSceneMgr, int name, string mesh) : CTarget(pSceneMgr, name, mesh)
{
	///////////////////////////////////////////////////////////////////////////
	// animation FX
	///////////////////////////////////////////////////////////////////////////
	mDirection	= Ogre::Vector3::ZERO;

#ifdef	_TEST_TRACK_
	for(int i = 0; i < MAX_INDEX; i++ )
		m_paTrack[ i ]	= NULL;
#endif
}


CFighter::~CFighter(void)
{
#ifdef	_TEST_TRACK_
	for(int i = 0; i < MAX_INDEX; i++ )
		DEL( m_paTrack[ i ])
#endif
}

/**
 * @function	PostCreate
 * @remarks		post processinf according to characteristic of each target
 */
void CFighter::CreatePostprocess() 
{
	Ogre::Root::getSingleton().addFrameListener(this);

	///////////////////////////////////////////////////////////////////////////
	// create my own resources for particle system
	///////////////////////////////////////////////////////////////////////////
	Ogre::ParticleSystem* ps;

	ps = mSceneMgr->createParticleSystem("JenEngine1", "Examples/JetEngine1");  // create a rainstorm
    ps->fastForward(5);   // fast-forward the rain so it looks more natural

	// change -y-axis direction to -z-axis like fighter's jet engine flare
	ps->getEmitter(0)->setDirection( Ogre::Vector3(0, 0, -1) );

	// attache particle to scene node
	GetSceneNode()->attachObject(ps);

	///////////////////////////////////////////////////////////////////////////
	// create my own sounds
	///////////////////////////////////////////////////////////////////////////

	// create sound that loop flag is true
	m_pSound	= OgreOggSoundManager::getSingletonPtr()->createSound(m_strName, "jet_exhaust.wav", false, true);

	// start to play sound
	if( m_pSound )
		m_pSound->play();

	// set fighter position
	GetSceneNode()->setPosition( Ogre::Vector3(0, 5000, 1000) );

	// make orbit from position of fighter
	CreateCircleOrbit();
}

void CFighter::CreateCircleOrbit()
{
	//////////////////////////////////////////////////////////////////////////////
	//
	//////////////////////////////////////////////////////////////////////////////
	m_pCircle	= mSceneMgr->createManualObject("3D circle");

	// get the distance from origin to this scene node
	Ogre::Vector3		ScenePos		= GetSceneNode()->getPosition();
	Ogre::Real		Radius			= ScenePos.distance( Ogre::Vector3::ZERO );

	if( Radius == 0 )
		Radius		= 1000;

	// accurary is the count of points (and lines)
	Ogre::Real const Accurary	= MAX_INDEX / 2;

	m_pCircle->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_LINE_STRIP );

	unsigned	nPointIndex	= 0;
	Ogre::Vector3		vPos;

	// make waypoints
	for( Ogre::Real theta = 0; theta <= 2 * Ogre::Math::PI; theta += Ogre::Math::PI / Accurary )
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

		m_pCircle->position( vPos );
		m_pCircle->index( nPointIndex++ );
	}

	m_pCircle->index( 0 );
	m_pCircle->end();

	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject( m_pCircle );
}

void CFighter::createFrameListener(void)
{
	CTarget::createFrameListener();

///
// create test tracks of fighter and
// drive code to send test tracks to CFighter
///
#ifdef	_TEST_TRACK_
	string		name;

	m_pCircle	= mSceneMgr->createManualObject(name);

	// get the distance from origin to this scene node
	Vector3		ScenePos		= GetSceneNode()->getPosition();
	Ogre::Real const Radius		= ScenePos.distance( Vector3::ZERO );

	// accurary is the count of points (and lines)
	Ogre::Real const Accurary	= MAX_INDEX / 2;

	m_pCircle->begin("BaseWhiteNoLighting", RenderOperation::OT_LINE_STRIP );

	unsigned	nPointIndex	= 0;

	for( Ogre::Real theta = 0; theta <= 2 * Math::PI; theta += Math::PI / Accurary )
	{
		m_aCirclePos[ nPointIndex ].x	= Radius * cos( theta );
		m_aCirclePos[ nPointIndex ].y	= ScenePos.y;
		m_aCirclePos[ nPointIndex ].z	= Radius * sin( theta );

		if( nPointIndex == 0 )
		{
			// set initial position
			m_pSceneNode->setPosition( m_aCirclePos[ 0 ]);
		}
		else
		{
			m_paTrack[ nPointIndex ]	= new CFighter( mSceneMgr, nPointIndex + 1, m_strMeshName );

			// move fighter to destination
			m_paTrack[ nPointIndex ]->MoveTo( m_aCirclePos[ nPointIndex - 1 ], m_aCirclePos[ nPointIndex ]);
		}

		m_pCircle->position( m_aCirclePos[ nPointIndex ] );
		m_pCircle->index( nPointIndex++ );
	}

	m_pCircle->index( 0 );
	m_pCircle->end();

	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject( m_pCircle );

#endif
}

bool CFighter::nextLocation()
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
		
	mDirection = mDestination - GetSceneNode()->getPosition();
	mDistance = mDirection.normalise();

	return true;
}

bool CFighter::frameRenderingQueued( const Ogre::FrameEvent &evt )
{
	// get the next position
//	Vector3		ToPos	= m_aCirclePos[ ++m_nCurPos % MAX_INDEX ];

//	Quaternion	q		= ToPos.getRotationTo( m_aCirclePos[ ++m_nCurPos % MAX_INDEX ]);

//	m_pSceneNode->rotate( q, Ogre::Node::TS_WORLD );

	// move fighter to next position
//	m_pSceneNode->setPosition( ToPos );

	return true;
}

/**
* @function		frameStarted
* @remarks		make animation effect
*/
bool CFighter::frameStarted(const Ogre::FrameEvent& evt)
{
	if(mDirection == Ogre::Vector3::ZERO)
	{
		// set direction and distance to move for character
		if(nextLocation())
		{
		}
	}
	else
	{
		// calculate the distance to go
		Ogre::Real move	= m_WalkSpeed * evt.timeSinceLastFrame;

		// calculate the remaining distance
		mDistance	-= move;

		if(mDistance <= 0.0f)
		{
			// if character reaches the waypoint
			// the remaining distance is less then zero
			GetSceneNode()->setPosition(mDestination);

			// clear direction to set the next waypoins
			mDirection = Ogre::Vector3::ZERO;

			if(nextLocation())
			{
				Ogre::Vector3 src = GetSceneNode()->getOrientation() * Ogre::Vector3::UNIT_Z;

				// if angle of two vector is 180, then dot product is -1.
				if(1.0f + src.dotProduct(mDirection) < 0.0001f)
				{
					GetSceneNode()->yaw(Ogre::Degree(180));
				}
				else
				{
					Ogre::Quaternion quat = src.getRotationTo(mDirection);
					GetSceneNode()->rotate(quat);
				}
			}
		}
		else
		{
			GetSceneNode()->translate(mDirection * move);
		}
	}

	return true;
}
