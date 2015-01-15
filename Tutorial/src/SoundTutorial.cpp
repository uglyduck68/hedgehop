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
	// ���� ���� �÷��̰� �����ϵ��� ������ �������� ������ ���� �ڵ��� ������ �Ѵ�.
	//////////////////////////////////////////////////////////////////////////////
    if (arg.key == OIS::KC_1)
	{
		/** Sound two - prebuffered, streamed, looping from true, true options */
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

		if( !sound->isPlaying() )
			sound->play();

		sound1	= mSoundManager->getSound("TwoOne");

		if( !sound1 )
		{
			// make another sound
			if ( sound1 = mSoundManager->createSound("TwoOne", "explosion_feu.wav")/*, true, true)*/ )	
			{
	//			sound->setMaxDistance(300);
	//			sound->setReferenceDistance(100);
	//			sound->play();
	//			sound->setLoopOffset(5.f);
			}

		}

		if( sound->isPlaying() && !sound1->isPlaying() )
			sound1->play();

		sound2	= mSoundManager->getSound("TwoTwo");

		if( !sound2 )
		{
			// make another sound
			if ( sound2 = mSoundManager->createSound("TwoTwo", "explosion_feu.wav")/*, true, true)*/ )	
			{
	//			sound->setMaxDistance(300);
	//			sound->setReferenceDistance(100);
	//			sound->play();
	//			sound->setLoopOffset(5.f);
			}

		}

		if( sound->isPlaying() && sound1->isPlaying() && !sound2->isPlaying() )
			sound2->play();
    }
    else if (arg.key == OIS::KC_2)   // toggle visibility of advanced frame stats
    {
		/** Sound two - prebuffered, streamed, looping */
		OgreOggISound*	sound = 0;

		sound	= mSoundManager->getSound("ThreeTwo");

		if( !sound )
		{
			if ( sound = mSoundManager->createSound("ThreeTwo", "jet_exhaust.wav")/*, true, true)*/ )	
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
