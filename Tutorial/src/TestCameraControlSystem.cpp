#include "StdAfx.h"
#include "..\include\TestCameraControlSystem.h"

CCS::CameraControlSystem* mCameraCS = NULL;

// ----------------------------------------------------------------------------
// Misc
// ----------------------------------------------------------------------------
Ogre::TextAreaOverlayElement* mTextArea = 0;
bool mShowInformation = false;
SceneNode *headNode ;
SceneNode* atheneNode;
AnimationState* mAnimState;

TestCameraControlSystem::TestCameraControlSystem(void) :
		mKeyBuffer(-1), mCamNode(NULL) /*, mAniso(1), mSceneDetailIndex(0)*/
{
}


TestCameraControlSystem::~TestCameraControlSystem(void)
{
//	if( mCamNode )
//		delete mCamNode;
}
