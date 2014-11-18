#pragma once

/**
 * @file		BasicTutorial4
 * @remarks		key I, K, J, L, U, O�� ó���Ѵ� (unbuffered ���).
 *				�� Ű�� ���� forward, backward, left yaw(or strafe), right yaw(or strafe), up and down.
 *				��, 0.5�� ���ȿ� ���� Ű 1 �̺�Ʈ�� ���� light on/off ó���Ѵ�.
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
 


