#pragma once

/**
 * @file		BasicTutorial4
 * @remarks		key I, K, J, L, U, O를 처리한다 (unbuffered 방식).
 *				이 키에 따라 forward, backward, left yaw(or strafe), right yaw(or strafe), up and down.
 *				단, 0.5초 동안에 들어온 키 1 이벤트에 따라 light on/off 처리한다.
 */
#include "BaseApplication.h"
 
class BasicTutorial4 : public BaseApplication
{
public:
    BasicTutorial4(void);
    virtual ~BasicTutorial4(void);
protected:
    virtual void createScene(void);
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
private:
    bool processUnbufferedInput(const Ogre::FrameEvent& evt);
};
 


