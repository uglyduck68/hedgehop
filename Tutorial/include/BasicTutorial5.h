/**
 * @file		BasicTutorial5
 * @remarks		닌자 하나 나오고, WSAD 마우스 오른쪽 버튼으로 조명 키고/끄기, 
 *				마우스 왼쪽 버튼으로 회전.
 *				숫자 1/2로 각기 만든 카메라를 카메라 노드에 설정하여 시점 변환, 
 *				화살표 4방향 키.
 *				단지 buffered input 샘플 프로그램임.
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


