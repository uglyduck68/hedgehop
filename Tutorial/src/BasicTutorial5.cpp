#include "StdAfx.h"
#include "..\include\BasicTutorial5.h"


#include "BasicTutorial5.h"
 
//-------------------------------------------------------------------------------------
BasicTutorial05::BasicTutorial05(void)
{
}
//-------------------------------------------------------------------------------------
BasicTutorial05::~BasicTutorial05(void)
{
}
 
//-------------------------------------------------------------------------------------
void BasicTutorial05::createScene(void)
{
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.25, 0.25, 0.25));
 
        // add the ninja
	Ogre::Entity *ent = mSceneMgr->createEntity("Ninja", "ninja.mesh");
        Ogre::SceneNode *node = mSceneMgr->getRootSceneNode()->createChildSceneNode("NinjaNode");
        node->attachObject(ent);
 
        // create the light
        Ogre::Light *light = mSceneMgr->createLight("Light1");
        light->setType(Ogre::Light::LT_POINT);
        light->setPosition(Ogre::Vector3(250, 150, 250));
        light->setDiffuseColour(Ogre::ColourValue::White);
        light->setSpecularColour(Ogre::ColourValue::White);
 
       // Create the scene node
        node = mSceneMgr->getRootSceneNode()->createChildSceneNode("CamNode1", Ogre::Vector3(-400, 200, 400));
 
        // Make it look towards the ninja
        node->yaw(Ogre::Degree(-45));
 
        // Create the pitch node
        node = node->createChildSceneNode("PitchNode1");
        node->attachObject(mCamera);
 
        // create the second camera node/pitch node
        node = mSceneMgr->getRootSceneNode()->createChildSceneNode("CamNode2", Ogre::Vector3(0, 200, 400));
        node = node->createChildSceneNode("PitchNode2");
 
}
	void BasicTutorial05::createFrameListener(void){
		BaseApplication::createFrameListener();
 
		// Populate the camera container
		mCamNode = mCamera->getParentSceneNode();
 
		// set the rotation and move speed
		mRotate = 0.13;
		mMove = 250;
 
		mDirection = Ogre::Vector3::ZERO;
 
}
	bool BasicTutorial05::frameRenderingQueued(const Ogre::FrameEvent& evt)
	{
		    if(mWindow->isClosed())
        return false;
 
		if(mShutDown)
			return false;
 
		//Need to capture/update each device
		mKeyboard->capture();
		mMouse->capture();
 
		mTrayMgr->frameRenderingQueued(evt);
		mCamNode->translate(mDirection * evt.timeSinceLastFrame, Ogre::Node::TS_LOCAL);
		return true;
	}
 
		// OIS::KeyListener
		bool BasicTutorial05::keyPressed( const OIS::KeyEvent &arg )
		{
		    switch (arg.key)
			{
				case OIS::KC_1:
					mCamera->getParentSceneNode()->detachObject(mCamera);
					mCamNode = mSceneMgr->getSceneNode("CamNode1");
					mCamNode->attachObject(mCamera);
					break;
 
				case OIS::KC_2:
				    mCamera->getParentSceneNode()->detachObject(mCamera);
					mCamNode = mSceneMgr->getSceneNode("CamNode2");
					mCamNode->attachObject(mCamera);
					break;
				case OIS::KC_UP:
				case OIS::KC_W:
					mDirection.z = -mMove;
					break;
 
				case OIS::KC_DOWN:
				case OIS::KC_S:
					mDirection.z = mMove;
					break;
 
				case OIS::KC_LEFT:
				case OIS::KC_A:
					mDirection.x = -mMove;
					break;
 
				case OIS::KC_RIGHT:
				case OIS::KC_D:
					mDirection.x = mMove;
					break;
 
				case OIS::KC_PGDOWN:
				case OIS::KC_E:
					mDirection.y = -mMove;
					break;
 
				case OIS::KC_PGUP:
				case OIS::KC_Q:
					mDirection.y = mMove;
					break;
 
				case OIS::KC_ESCAPE: 
					mShutDown = true;
					break;
			    default:
					break;
			}
			return true;
		}
 
		bool BasicTutorial05::keyReleased( const OIS::KeyEvent &arg )
		{
 
			switch (arg.key)
			{
				case OIS::KC_UP:
				case OIS::KC_W:
					mDirection.z = 0;
					break;
 
				case OIS::KC_DOWN:
				case OIS::KC_S:
					mDirection.z = 0;
					break;
 
				case OIS::KC_LEFT:
				case OIS::KC_A:
					mDirection.x = 0;
					break;
 
				case OIS::KC_RIGHT:
				case OIS::KC_D:
					mDirection.x = 0;
					break;
 
				case OIS::KC_PGDOWN:
				case OIS::KC_E:
					mDirection.y = 0;
					break;
 
				case OIS::KC_PGUP:
				case OIS::KC_Q:
					mDirection.y = 0;
					break;
 
				default:
					break;
				}
				return true;
		}
		// OIS::MouseListener
		bool BasicTutorial05::mouseMoved( const OIS::MouseEvent &arg )
		{
			if (arg.state.buttonDown(OIS::MB_Right))
				{
					mCamNode->yaw(Ogre::Degree(-mRotate * arg.state.X.rel), Ogre::Node::TS_WORLD);
					mCamNode->pitch(Ogre::Degree(-mRotate * arg.state.Y.rel), Ogre::Node::TS_LOCAL);
				}
			return true;
		}
		
		bool BasicTutorial05::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id ){
			Ogre::Light *light = mSceneMgr->getLight("Light1");
			switch (id)
			{
			case OIS::MB_Left:
				light->setVisible(! light->isVisible());
				break;
			default:
				break;
			}
			return true;
		}

		bool BasicTutorial05::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
		{
			return true;
		}

