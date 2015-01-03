/**
 * @file		Trajectory.h
 * @remarks		Represents a trajectory in 3D space.
 *				This class is used to draw a trajectory in 3D space given by a series of
 *				points.
*/
#include "DynamicLines.h"

#include <OgreVector3.h>
#include <OgreManualObject.h>
#include <OgreSceneManager.h>


class Trajectory :public DynamicLines
{
public:
	Trajectory( Ogre::SceneManager* Mgr, Ogre::RenderOperation::OperationType opType=Ogre::RenderOperation::OT_LINE_STRIP, char* pName = "Trajectory" ) :
	  mSceneMgr(Mgr), mSNode(NULL)
	{
		if( mSceneMgr )
		{
			mSNode	= mSceneMgr->getRootSceneNode()->createChildSceneNode( pName );
			mSNode->attachObject( static_cast<Ogre::MovableObject*>( this ));
		}
	}

	~Trajectory()
	{
		if( mSceneMgr && mSNode )
		{
			mSceneMgr->destroySceneNode( mSNode );
		}
	}

protected:
	Ogre::SceneManager*		mSceneMgr;
	Ogre::SceneNode*		mSNode;

};

