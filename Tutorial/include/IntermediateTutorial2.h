#ifndef __ITutorial02_h_
#define __ITutorial02_h_
 
///////////////////////////////////////////////////////////////////////////////////////////
// source: http://www.ogre3d.org/tikiwiki/tiki-index.php?page=IntermediateTutorial2SdkTraysSource
// - Basic tutorial 03 is terrain generation that camera being able to go through the part of terrain.
//	IntermediateTutorial 03�� ���� ������ �հ� �������� �������� ������ ���̳�, exception error��
//	������ ������ �ʴ´�.
//	���� �� ����� Basic Tutorial 03�� �߰��� ����.
///////////////////////////////////////////////////////////////////////////////////////////
//SdkTray-version
 
#include "BaseApplication.h"
 
class ITutorial02 : public BaseApplication
{
public:
    ITutorial02(void);
    virtual ~ITutorial02(void);
 
protected:
    virtual void createScene(void);
	virtual void chooseSceneManager(void);
	virtual void createFrameListener(void);
	//frame listener
	virtual bool frameRenderingQueued(const Ogre::FrameEvent &evt);
	//mouse listener
	virtual bool mouseMoved(const OIS::MouseEvent &arg);
	virtual bool mousePressed(const OIS::MouseEvent &arg,OIS::MouseButtonID id);
	virtual bool mouseReleased(const OIS::MouseEvent &arg,OIS::MouseButtonID id);
 
 
protected:
	Ogre::RaySceneQuery *mRaySceneQuery;// The ray scene query pointer
    bool mLMouseDown, mRMouseDown;		// True if the mouse buttons are down
    int mCount;							// The number of robots on the screen
	Ogre::SceneNode *mCurrentObject;	// The newly created object
    //CEGUI::Renderer *mGUIRenderer;	// Not needed since we are using SdkTrays
	float mRotateSpeed;		
 
};
 
#endif // #ifndef __ITutorial02_h_