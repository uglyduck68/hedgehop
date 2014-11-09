#include "StdAfx.h"
#include "..\include\SoundTutorial.h"

using namespace OgreOggSound;

SoundTutorial::SoundTutorial(void)
{
}


SoundTutorial::~SoundTutorial(void)
{
}


void SoundTutorial::createScene()
{
    Ogre::Entity* ogreHead = mSceneMgr->createEntity("Head", "ogrehead.mesh");

    Ogre::SceneNode* mOgreMonster = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    mOgreMonster->attachObject(ogreHead);

    // Set ambient light
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

    // Create a light
    Ogre::Light* l = mSceneMgr->createLight("MainLight");
    l->setPosition(20,80,50);



	mSoundManager = OgreOggSoundManager::getSingletonPtr();
	
	mSoundManager->init();

	// mCamera->getParentSceneNode() return NULL
	if( mCamera->getParentSceneNode() )
		mCamera->getParentSceneNode()->attachObject(mSoundManager->getListener());

	Ogre::Root::getSingleton().addFrameListener(this);

	/** Sound two - prebuffered, streamed, looping */
	//sound = 0;
	//if ( sound = mSoundManager->createSound("Two", "one.ogg", true, true) )	
	//{
	//	sound->setMaxDistance(300);
	//	sound->setReferenceDistance(100);
	//	mOgreMonster->attachObject(sound);
	//	sound->play();
	//	sound->setLoopOffset(5.f);
	//}
	///** Sound three - non streamed, looping, moving */
	//sound = 0;
	//if ( sound = mSoundManager->createSound("Three", "three.ogg", false, true) )
	//{
	//	sound->setMaxDistance(50);
	//	sound->setReferenceDistance(1);
	//	mOgreMonster->attachObject(sound);
	//	sound->play();
	//}
	///** Sound one - streamed, looping, EFX Direct filter */
	//sound = 0;
	//sound = mSoundManager->createSound("background", "four.ogg", true, true);
	//if ( sound ) 
	//{
	//	sound->disable3D(true);
	//	sound->play();		 
	//}													  

}

bool SoundTutorial::keyPressed(const OIS::KeyEvent &arg)
{
	///////////////////////////////////////////////////////////////////////////
	// �Ʒ��� ���� �ϸ� 1 ���� �� "explosion_feu.wav" ����ϰ�,
	// 2 ��� ���� "jet_exhaust.wav" ����Ѵ�. �� ���ÿ� �� ������ ����� �ȴ�.
	// ������ 1�� �������� ������ "explosion_feu.wav" ������ ���� ��������� �ʴ´�.
	//////////////////////////////////////////////////////////////////////////////
    if (arg.key == OIS::KC_1)
	{
		/** Sound two - prebuffered, streamed, looping from true, true options */
		OgreOggISound*	sound = 0;

		sound	= mSoundManager->getSound("Two");

		if( !sound )
		{
			//
			// sean, last parameter "true, true" playback infinitely
			//
			if ( sound = mSoundManager->createSound("Two", "explosion_feu.wav")/*, true, true)*/ )	
			{
	//			sound->setMaxDistance(300);
	//			sound->setReferenceDistance(100);
	//			sound->play();
	//			sound->setLoopOffset(5.f);
			}
		}

		sound->play();
    }
    else if (arg.key == OIS::KC_2)   // toggle visibility of advanced frame stats
    {
		/** Sound two - prebuffered, streamed, looping */
		OgreOggISound*	sound = 0;

		sound	= mSoundManager->getSound("TwoTwo");

		if( !sound )
		{
			if ( sound = mSoundManager->createSound("TwoTwo", "jet_exhaust.wav")/*, true, true)*/ )	
			{
			}
		}

		sound->play();
    }

	return BaseApplication::keyPressed( arg );
}

bool SoundTutorial::keyReleased(const OIS::KeyEvent &arg)
{
	return BaseApplication::keyReleased( arg );
}
