#include "StdAfx.h"
#include "..\include\AnimationTutorial.h"

using namespace	Ogre;

AnimationTutorial::AnimationTutorial(void) :
	m_pSceneNode(NULL)
{
}


AnimationTutorial::~AnimationTutorial(void)
{
}

void AnimationTutorial::createScene()
{
	//////////////////////////////////////////////////////////////////////////////
	//
	//////////////////////////////////////////////////////////////////////////////
	createSceneNode("razor.mesh");
	GetSceneNode()->setPosition( Vector3(0, 0, 500) );

	//////////////////////////////////////////////////////////////////////////////
	//
	//////////////////////////////////////////////////////////////////////////////
	m_pCircle	= mSceneMgr->createManualObject("3D circle");

	// get the distance from origin to this scene node
	Vector3		ScenePos		= GetSceneNode()->getPosition();
	Real		Radius			= ScenePos.distance( Vector3::ZERO );

	if( Radius == 0 )
		Radius		= 500;

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
			//m_paTrack[ nPointIndex ]	= new CFighter( mSceneMgr, nPointIndex + 1, m_strMeshName );

			//// move fighter to destination
			//m_paTrack[ nPointIndex ]->MoveTo( m_aCirclePos[ nPointIndex - 1 ], m_aCirclePos[ nPointIndex ]);
		}

		m_pCircle->position( m_aCirclePos[ nPointIndex ] );
		m_pCircle->index( nPointIndex++ );
	}

	m_pCircle->index( 0 );
	m_pCircle->end();

	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject( m_pCircle );

	//////////////////////////////////////////////////////////////////////////////
	//
	//////////////////////////////////////////////////////////////////////////////
    // Set ambient light
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

    // Create a light
    Ogre::Light* l = mSceneMgr->createLight("MainLight");
    l->setPosition(20,80,50);

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
	MoveTo(m_aCirclePos[ 0 ], m_aCirclePos[ 1 ], evt);

	return BaseApplication::frameStarted( evt );
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

	if( evt.timeSinceLastFrame != 0 )
		Dest	*= evt.timeSinceLastFrame;

	// move target to destination
	GetSceneNode()->setPosition( Dest );

	return true;
}