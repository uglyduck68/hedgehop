/**
 * @file		BasicTutorial5
 * @remarks		���� �ϳ� ������, WSAD ���콺 ������ ��ư���� ���� Ű��/����, 
 *				���콺 ���� ��ư���� ȸ��.
 *				���� 1/2�� ���� ���� ī�޶� ī�޶� ��忡 �����Ͽ� ���� ��ȯ, 
 *				ȭ��ǥ 4���� Ű.
 *				���� buffered input ���� ���α׷���.
 */

#pragma once

#include "BaseApplication.h"
 
class BasicTutorial05 : public BaseApplication
{
public:
    BasicTutorial05(void);
    virtual ~BasicTutorial05(void);
 
protected:
    virtual void createScene(void);
	virtual void createFrameListener(void);
 
	// Ogre::FrameListener
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
    // OIS::KeyListener
    virtual bool keyPressed( const OIS::KeyEvent &arg );
    virtual bool keyReleased( const OIS::KeyEvent &arg );
    // OIS::MouseListener
    virtual bool mouseMoved( const OIS::MouseEvent &arg );
    virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
    virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
 
	Ogre::Real mRotate;          // The rotate constant
	Ogre::Real mMove;            // The movement constant
 
	Ogre::SceneNode *mCamNode;   // The SceneNode the camera is currently attached to
 
	Ogre::Vector3 mDirection;     // Value to move in the correct direction
 
};


