/**
* @file		TestCamera.h
* @remarks	for testing 3rd person camera(fixed, chasing), 1st person camera.
*			refer to http://www.ogre3d.org/tikiwiki/tiki-index.php?page=3rd+person+camera+system+tutorial
*/
#pragma once

#include "baseapplication.h"

using namespace	Ogre;


// Generic Character class
 class Character {
 // Attributes ------------------------------------------------------------------------------
     protected:
         SceneNode *mMainNode; // Main character node
         SceneNode *mSightNode; // "Sight" node - The character is supposed to be looking here
         SceneNode *mCameraNode; // Node for the chase camera
         Entity *mEntity; // Character entity
         SceneManager *mSceneMgr;
     public:
 // Methods ---------------------------------------------------------------------------------
     protected:
     public:
         // Updates the character (movement...)
         virtual void update (Real elapsedTime, OIS::Keyboard *input) = 0;
         // The three methods below returns the two camera-related nodes, 
         // and the current position of the character (for the 1st person camera)
         SceneNode *getSightNode () {
             return mSightNode;
         }
         SceneNode *getCameraNode () {
             return mCameraNode;
         }
         Vector3 getWorldPosition () {
             return mMainNode->_getDerivedPosition ();
         }
 };

 // Specialization of the Character class - Our dear Ogre :D
 class OgreCharacter : public Character {
 // Attributes ------------------------------------------------------------------------------
     protected:
         String mName;
     public:
 // Methods ---------------------------------------------------------------------------------
     protected:
     public:
         OgreCharacter (String name, SceneManager *sceneMgr) {
             // Setup basic member references
             mName = name;
             mSceneMgr = sceneMgr;
 
             // Setup basic node structure to handle 3rd person cameras
             mMainNode = mSceneMgr->getRootSceneNode ()->createChildSceneNode (mName);
             mSightNode = mMainNode->createChildSceneNode (mName + "_sight", Vector3 (0, 0, 100));
             mCameraNode = mMainNode->createChildSceneNode (mName + "_camera", Vector3 (0, 50, -100));
 
             // Give this character a shape :)
             mEntity = mSceneMgr->createEntity (mName, "OgreHead.mesh");
             mMainNode->attachObject (mEntity);
         }
         ~OgreCharacter () {
             mMainNode->detachAllObjects ();
             delete mEntity;
             mMainNode->removeAndDestroyAllChildren ();
             mSceneMgr->destroySceneNode (mName);
         }
 
         void update (Real elapsedTime, OIS::Keyboard *input) {
             // Handle movement
             if (input->isKeyDown (OIS::KC_W)) {
                 mMainNode->translate (mMainNode->getOrientation () * Vector3 (0, 0, 100 * elapsedTime));
             }
             if (input->isKeyDown (OIS::KC_S)) {
                 mMainNode->translate (mMainNode->getOrientation () * Vector3 (0, 0, -50 * elapsedTime));
             }
             if (input->isKeyDown (OIS::KC_A)) {
                 mMainNode->yaw (Radian (2 * elapsedTime));
             }
             if (input->isKeyDown (OIS::KC_D)) {
                 mMainNode->yaw (Radian (-2 * elapsedTime));
             }
         }
 
         // Change visibility - Useful for 1st person view ;)
         void setVisible (bool visible) {
             mMainNode->setVisible (visible);
         }
 };

 // Our extended camera class
 class ExtendedCamera {
 // Attributes ------------------------------------------------------------------------------
     protected:
         SceneNode *mTargetNode; // The camera target
         SceneNode *mCameraNode; // The camera itself
         Camera *mCamera; // Ogre camera
 
         SceneManager *mSceneMgr;
         String mName;
 
         bool mOwnCamera; // To know if the ogre camera binded has been created outside or inside of this class
 
         Real mTightness; // Determines the movement of the camera - 1 means tight movement, while 0 means no movement
     public:
 // Methods ---------------------------------------------------------------------------------
     protected:
     public:
         ExtendedCamera (String name, SceneManager *sceneMgr, Camera *camera = 0) {
             // Basic member references setup
             mName = name;
             mSceneMgr = sceneMgr;
 
             // Create the camera's node structure
             mCameraNode = mSceneMgr->getRootSceneNode ()->createChildSceneNode (mName);
             mTargetNode = mSceneMgr->getRootSceneNode ()->createChildSceneNode (mName + "_target");
             mCameraNode->setAutoTracking (true, mTargetNode); // The camera will always look at the camera target
             mCameraNode->setFixedYawAxis (true); // Needed because of auto tracking
 
             // Create our camera if it wasn't passed as a parameter
             if (camera == 0) {
                 mCamera = mSceneMgr->createCamera (mName);
                 mOwnCamera = true;
             }
             else {
                 mCamera = camera;
                                 // just to make sure that mCamera is set to 'origin' (same position as the mCameraNode)
                                 mCamera->setPosition(0.0,0.0,0.0);
                 mOwnCamera = false;
             }
             // ... and attach the Ogre camera to the camera node
             mCameraNode->attachObject (mCamera);
 
             // Default tightness
             mTightness = 0.01f;
         }
         ~ExtendedCamera () {
             mCameraNode->detachAllObjects ();
             if (mOwnCamera)
                 delete mCamera;
             mSceneMgr->destroySceneNode (mName);
             mSceneMgr->destroySceneNode (mName + "_target");
         }
 
         void setTightness (Real tightness) {
             mTightness = tightness;
         }
 
         Real getTightness () {
             return mTightness;
         }
 
         Vector3 getCameraPosition () {
             return mCameraNode->getPosition ();
         }
 
         void instantUpdate (Vector3 cameraPosition, Vector3 targetPosition) {
             mCameraNode->setPosition (cameraPosition);
             mTargetNode->setPosition (targetPosition);
         }
 
         void update (Real elapsedTime, Vector3 cameraPosition, Vector3 targetPosition) {
             // Handle movement
             Vector3 displacement;
 
             displacement = (cameraPosition - mCameraNode->getPosition ()) * mTightness;
             mCameraNode->translate (displacement);
 
             displacement = (targetPosition - mTargetNode->getPosition ()) * mTightness;
             mTargetNode->translate (displacement);
         }
 };

 
class TestCamera :
	public BaseApplication
{
 protected:
     // References to the main character and the camera
     Character *mChar;
     ExtendedCamera *mExCamera;
 
     // Camera mode - Now supports 1st person, 3rd person (chasing) and 3rd person (fixed)
     unsigned int mMode;
 
 public:
     TestCamera()
     {
         mChar = 0;
         mExCamera = 0;
         mMode = 0;
     }
 
     void setCharacter (Character *character) {
         mChar = character;
     }
 
     void setExtendedCamera (ExtendedCamera *cam) {
         mExCamera = cam;
     }
 
     bool frameStarted(const FrameEvent& evt)
     {
         mKeyboard->capture();
 
         if (mChar) {
             mChar->update (evt.timeSinceLastFrame, mKeyboard);
 
             if (mExCamera) {
                 switch (mMode) {
                     case 0: // 3rd person chase
                         mExCamera->update (evt.timeSinceLastFrame, 
                                             mChar->getCameraNode ()->_getDerivedPosition (), 
                                             mChar->getSightNode ()->_getDerivedPosition ());
                         break;
                     case 1: // 3rd person fixed
                         mExCamera->update (evt.timeSinceLastFrame, 
                                             Vector3 (0, 200, 0), 
                                             mChar->getSightNode ()->_getDerivedPosition ());
                         break;
                     case 2: // 1st person
                         mExCamera->update (evt.timeSinceLastFrame, 
                                             mChar->getWorldPosition (), 
                                             mChar->getSightNode ()->_getDerivedPosition ());
                         break;
                 }
             }
         }
 
         // 3rd Person - Chase Camera
         if (mKeyboard->isKeyDown (OIS::KC_F1)) {
             mMode = 0;
             if (mChar)
                 static_cast<OgreCharacter *>(mChar)->setVisible (true);
             if (mExCamera) {
                 if (mChar)
                     mExCamera->instantUpdate (mChar->getCameraNode ()->_getDerivedPosition (), mChar->getSightNode ()->_getDerivedPosition ());
                 mExCamera->setTightness (0.01f);
             }
          }
         // 3rd Person - Fixed Camera
         if (mKeyboard->isKeyDown (OIS::KC_F2)) {
             mMode = 1;
             if (mChar)
                 static_cast<OgreCharacter *>(mChar)->setVisible (true);
             if (mExCamera) {
                 if (mChar)
                     mExCamera->instantUpdate (Vector3 (0, 200, 0), mChar->getSightNode ()->_getDerivedPosition ());
                 mExCamera->setTightness (0.01f);
             }
         }
         // 1st Person
         if (mKeyboard->isKeyDown (OIS::KC_F3))  {
             mMode = 2;
             if (mChar)
                 static_cast<OgreCharacter *>(mChar)->setVisible (false);
             if (mExCamera) {
                 if (mChar)
                     mExCamera->instantUpdate (mChar->getCameraNode()->_getDerivedPosition (), mChar->getSightNode ()->_getDerivedPosition ());
                 mExCamera->setTightness (1.0f);
             }
         }
 
         // Exit if we press Esc
         if(mKeyboard->isKeyDown (OIS::KC_ESCAPE))
             return false;
 
         return true;
     }
 

     void createScene(void)
     {
         // Set ambient light
         mSceneMgr->setAmbientLight(ColourValue(0.2, 0.2, 0.2));
 
         // LIGHTS!!
         // Create a point light
         Light* l = mSceneMgr->createLight("MainLight");
         // Accept default settings: point light, white diffuse, just set position
         // NB I could attach the light to a SceneNode if I wanted it to move automatically with
         //  other objects, but I don't
         l->setType(Light::LT_DIRECTIONAL);
         l->setDirection(-0.5, -0.5, 0);
 
         // CAMERA!!
         mCamera->setPosition (0, 0, 0);    // Required or else the camera will have an offset
 
         // ACTION!!!
         // Fill the scene with some razors
         SceneNode *razorNode;
         Entity *razorEntity;
         for (unsigned int i = 0; i < 30; ++i) {
             razorNode = mSceneMgr->getRootSceneNode ()->createChildSceneNode (StringConverter::toString (i), Vector3 (Math::RangeRandom (-1000, 1000), 0, Math::RangeRandom (-1000, 1000)));
             razorEntity = mSceneMgr->createEntity (StringConverter::toString (i), "razor.mesh");
             razorNode->attachObject (razorEntity);
         }
 
         // Main character
         OgreCharacter *ogre = new OgreCharacter ("Ogre 1", mSceneMgr);
         ExtendedCamera *exCamera = new ExtendedCamera ("Extended Camera", mSceneMgr, mCamera);
 
         // Frame listener to manage both character and camera updating and different camera modes
         // Need to create it here as we want to change some parameters here, thus avoiding defining 
         // ogre and exCamera as member variables
//         mFrameListener = new SampleListener (mWindow, mCamera);
         this->setCharacter (ogre);
         this->setExtendedCamera (exCamera);
     }
     void destroyScene(void)
     {
     }




};