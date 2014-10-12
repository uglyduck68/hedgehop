/**
* @file		InputController.h
* 
* This file is interface input controller that
* control the camera according to the input of keyboard and mouse input.
*/

#pragma once

using namespace Ogre;

class CInputController : public FrameListener, 
	public OIS::KeyListener, 
	public OIS::MouseListener
{
public:
	CInputController(Root* root, OIS::Keyboard *keyboard, OIS::Mouse *mouse);
	~CInputController(void);

	virtual bool frameStarted( const FrameEvent &evt );
    virtual void createFrameListener(void);

	bool keyPressed( const OIS::KeyEvent &evt );
	bool keyReleased( const OIS::KeyEvent &evt );
	bool mouseMoved( const OIS::MouseEvent &evt );
	bool mousePressed( const OIS::MouseEvent &evt, OIS::MouseButtonID id )
	{
		return true;
	}

	bool mouseReleased( const OIS::MouseEvent &evt, OIS::MouseButtonID id )
	{
		return true;
	}



private:
	Ogre::Root*			mRoot;
	Ogre::SceneManager* mSceneMgr;
	OIS::Keyboard*		mKeyboard;
	OIS::Mouse*			mMouse;

	/** nodes for camera holder technique */
	SceneNode*			mCameraHolder;
	SceneNode*			mCameraYaw;
	SceneNode*			mCameraPitch;

	bool mContinue;
	bool				m_bCameraHolderMode;

};

