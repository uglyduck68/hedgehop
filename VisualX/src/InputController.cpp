#include "StdAfx.h"
#include "..\include\InputController.h"


CInputController::CInputController(Root* root, OIS::Keyboard *keyboard, OIS::Mouse *mouse) : 
	mRoot(root), mKeyboard(keyboard), mMouse(mouse), mContinue(true),
	mCameraYaw(NULL), mCameraPitch(NULL), mCameraHolder(NULL),
	m_bCameraHolderMode(false)
{
	/**
	* Note the technique of making the camera of world coordinate transform
	*/
	SceneNode* professorRoot = mSceneMgr->getRootSceneNode()->createChildSceneNode("ProfessorRoot");


	mCameraYaw = professorRoot->createChildSceneNode("CameraYaw", Vector3(0.0f, 120.0f, 0.0f));
	mCameraPitch = mCameraYaw->createChildSceneNode("CameraPitch");
	mCameraHolder = mCameraPitch->createChildSceneNode("CameraHolder", Vector3(0.0f, 80.0f, 500.0f));

}


CInputController::~CInputController(void)
{
}

bool CInputController::frameStarted(const FrameEvent &evt)
{
	mKeyboard->capture();
	mMouse->capture();

	return mContinue;
}

void CInputController::createFrameListener(void)
{
	mKeyboard->setEventCallback(this);
	mMouse->setEventCallback(this);

	mRoot->addFrameListener(this);
}

// Key Linstener Interface Implementation

bool CInputController::keyPressed( const OIS::KeyEvent &evt )
{
	switch(evt.key)
	{
	case OIS::KC_LCONTROL: m_bCameraHolderMode = true; break;
	default:
		break;
	}

	return true;
}

bool CInputController::keyReleased( const OIS::KeyEvent &evt )
{

	switch(evt.key) 
	{
	case OIS::KC_ESCAPE: mContinue = false; break;
	case OIS::KC_LCONTROL: m_bCameraHolderMode = true; break;
	default:
		break;
	}

	return true;
}


// Mouse Listener Interface Implementation

bool CInputController::mouseMoved( const OIS::MouseEvent &evt )
{
	assert( mCameraYaw != NULL && mCameraPitch != NULL && mCameraHolder != NULL );

	if( !m_bCameraHolderMode )
		return true;

	mCameraYaw->yaw(Degree(-evt.state.X.rel));
	mCameraPitch->pitch(Degree(-evt.state.Y.rel));

	mCameraHolder->translate(Ogre::Vector3(0, 0, -evt.state.Z.rel * 0.1f));

	return true;
}