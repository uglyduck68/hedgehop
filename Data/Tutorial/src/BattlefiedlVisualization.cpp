/*
-----------------------------------------------------------------------------
Filename:    BattlefiedlVisualization.cpp
-----------------------------------------------------------------------------


This source file is generated by the
   ___                   _              __    __ _                  _ 
  /___\__ _ _ __ ___    /_\  _ __  _ __/ / /\ \ (_)______ _ _ __ __| |
 //  // _` | '__/ _ \  //_\\| '_ \| '_ \ \/  \/ / |_  / _` | '__/ _` |
/ \_// (_| | | |  __/ /  _  \ |_) | |_) \  /\  /| |/ / (_| | | | (_| |
\___/ \__, |_|  \___| \_/ \_/ .__/| .__/ \/  \/ |_/___\__,_|_|  \__,_|
      |___/                 |_|   |_|                                 
      Ogre 1.8.x Application Wizard for VC10 (May 2012)
      https://bitbucket.org/jacmoe/ogreappwizards
-----------------------------------------------------------------------------
*/
#include "StdAfx.h"
#include "BattlefiedlVisualization.h"
#include "IntermediateTutorial7.h"
#include "IntermediateTutorial2.h"
#include "BasicTutorial3.h"
#include "ParticleTutorial.h"
#include "SoundTutorial.h"
#include "AnimationTutorial.h"

//-------------------------------------------------------------------------------------
BattlefiedlVisualization::BattlefiedlVisualization(void)
{
}
//-------------------------------------------------------------------------------------
BattlefiedlVisualization::~BattlefiedlVisualization(void)
{
}

//-------------------------------------------------------------------------------------
void BattlefiedlVisualization::createScene(void)
{
    Ogre::Entity* ogreHead = mSceneMgr->createEntity("Head", "ogrehead.mesh");

    Ogre::SceneNode* headNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    headNode->attachObject(ogreHead);

    // Set ambient light
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

    // Create a light
    Ogre::Light* l = mSceneMgr->createLight("MainLight");
    l->setPosition(20,80,50);
}



#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
  //      BattlefiedlVisualization app;
		//IntermediateTutorial7		app7;
		//ITutorial02					app2;
//		BasicTutorial3				appB3;
//		ParticleTutorial			appB3;	// jetengine particle test
//		SoundTutorial			appB3;		// ogreoggsound test
		AnimationTutorial		appB3;		// character moving animation test

        try {
            appB3.go();
        } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occured: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif
