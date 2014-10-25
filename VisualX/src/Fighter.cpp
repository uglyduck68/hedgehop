#include "StdAfx.h"
#include "..\include\Fighter.h"


CFighter::CFighter(Ogre::SceneManager* pSceneMgr, int name, string mesh) : CTarget(pSceneMgr, name, mesh)
{
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

bool CFighter::frameRenderingQueued( const FrameEvent &evt )
{
	// get the next position
	Vector3		ToPos	= m_aCirclePos[ ++m_nCurPos % MAX_INDEX ];

//	Quaternion	q		= ToPos.getRotationTo( m_aCirclePos[ ++m_nCurPos % MAX_INDEX ]);

//	m_pSceneNode->rotate( q, Ogre::Node::TS_WORLD );

	// move fighter to next position
//	m_pSceneNode->setPosition( ToPos );

	return true;
}
