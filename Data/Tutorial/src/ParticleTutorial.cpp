#include "StdAfx.h"
#include "..\include\ParticleTutorial.h"


ParticleTutorial::ParticleTutorial(void)
{
}


ParticleTutorial::~ParticleTutorial(void)
{
}

/**
* @function		setupResources
* @brief		setup particle related things
*				I refered to ParicleFx of Ogre samples
*/
void ParticleTutorial::setupResources(void)
{
	// call setupResources of base class
	BaseApplication::setupResources();
}

void ParticleTutorial::createScene(void)
{
	//////////////////////////////////////////////////////////////////////////////
	// I refered to SampleBrowser.h that initialize some rendering related things
	// to prevent exception of "Examples/Aureola"
	//////////////////////////////////////////////////////////////////////////////
	//bool success = initialiseRTShaderSystem(mSceneMgr);
	//if (!success) 
	//{
	//}

	///////////////////////////////////////////////////////////////////////////
	// set camera
	///////////////////////////////////////////////////////////////////////////
	// set our camera to orbit around the origin and show cursor
	mCameraMan->setStyle(OgreBites::CameraStyle::CS_ORBIT);
	mCameraMan->setYawPitchDist(Degree(0), Degree(15), 250);
//	mTrayMgr->showCursor();

    // Set ambient light
	mSceneMgr->setAmbientLight(ColourValue(0.5f, 0.5f, 0.5f));
    Entity* ent = mSceneMgr->createEntity("head", "ogrehead.mesh");

    // Add entity to the root scene node
    mOgreHead	= mSceneMgr->getRootSceneNode()->createChildSceneNode();
	mOgreHead->attachObject(ent);
	
	///////////////////////////////////////////////////////////////////////////
	// create my own resources for particle system
	///////////////////////////////////////////////////////////////////////////
	ParticleSystem::setDefaultNonVisibleUpdateTimeout(5);  // set nonvisible timeout

	ParticleSystem* ps;

    // create some nice fireworks and place it at the origin
    ps = mSceneMgr->createParticleSystem("Fireworks", "Examples/Fireworks");
	mSceneMgr->getRootSceneNode()->attachObject(ps);


	// create a green nimbus around the ogre head
    ps = mSceneMgr->createParticleSystem("Nimbus", "Examples/GreenyNimbus");
	mSceneMgr->getRootSceneNode()->attachObject(ps);
       
    ps = mSceneMgr->createParticleSystem("Rain", "Examples/Rain");  // create a rainstorm
    ps->fastForward(5);   // fast-forward the rain so it looks more natural
    mSceneMgr->getRootSceneNode()->createChildSceneNode(Vector3(0, 1000, 0))->attachObject(ps);

	ps = mSceneMgr->createParticleSystem("JenEngine1", "Examples/JetEngine1");  // create a rainstorm
    ps->fastForward(5);   // fast-forward the rain so it looks more natural
//    mSceneMgr->getRootSceneNode()->createChildSceneNode(Vector3(0, 1000, 0))->attachObject(ps);

	/////
	// change some properties to test particle system
	/////

	// change -y-axis direction to -z-axis like fighter's jet engine flare
	ps->getEmitter(0)->setDirection( Vector3(0, 0, -1) );
	mOgreHead->attachObject(ps);

	ps = mSceneMgr->createParticleSystem("JenEngine2", "Examples/JetEngine2");  // create a rainstorm
    ps->fastForward(5);   // fast-forward the rain so it looks more natural
    mSceneMgr->getRootSceneNode()->createChildSceneNode(Vector3(100, 1000, 100))->attachObject(ps);

	///////////////
	// cause exception. But ogre sample works well.
	///////////////
    // create aureola around ogre head perpendicular to the ground
#if		0	
    ps = mSceneMgr->createParticleSystem("Aureola", "Examples/Aureola");
    mSceneMgr->getRootSceneNode()->attachObject(ps);
#endif

    // create shared pivot node for spinning the fountains
    mFountainPivot = mSceneMgr->getRootSceneNode()->createChildSceneNode();

    ps = mSceneMgr->createParticleSystem("Fountain1", "Examples/PurpleFountain");  // create fountain 1
    // attach the fountain to a child node of the pivot at a distance and angle
	mFountainPivot->createChildSceneNode(Vector3(200, -100, 0), Quaternion(Degree(20), Vector3::UNIT_Z))->attachObject(ps);
        
    ps = mSceneMgr->createParticleSystem("Fountain2", "Examples/PurpleFountain");  // create fountain 2
    // attach the fountain to a child node of the pivot at a distance and angle
	mFountainPivot->createChildSceneNode(Vector3(-200, -100, 0), Quaternion(Degree(-20), Vector3::UNIT_Z))->attachObject(ps);

	return;
}

bool ParticleTutorial::frameRenderingQueued(const FrameEvent& evt)
{
	mFountainPivot->yaw(Degree(evt.timeSinceLastFrame * 30));   // spin the fountains around

	// spin ogre head to check the direction of jet engine flare
	mOgreHead->yaw(Degree(evt.timeSinceLastFrame * 30));

	return BaseApplication::frameRenderingQueued( evt );
}