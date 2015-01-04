#include "StdAfx.h"
#include "..\include\SkyTest.h"
#include "Terrain.h"

SkyTest::SkyTest(void) : 
	m_pSky(NULL)
{
}


SkyTest::~SkyTest(void)
{
	DEL( m_pSky );
}

void SkyTest::createLight()
{
	// Set ambient light
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

	// Create a light
	Ogre::Light* l = mSceneMgr->createLight("MainLight");

	l->setPosition(20,80,50);	
}

/**
* create sky entity
*/
void SkyTest::createScene()
{
	// create light
	createLight();

	DEL( m_pSky );

	// create sky
	m_pSky	= new CSky(mSceneMgr, mCamera);

	if( m_pSky )
	{
		m_pSky->createScene();

		// set sunny day
		m_pSky->setPreset( 1 );
	}

	// create land
	m_pTerrain	= new CTerrain(mSceneMgr, mCamera);
	if( m_pTerrain )
		m_pTerrain->createScene();

}

void SkyTest::createFrameListener(void)
{
	// create keyboard & mouse and Register this for handing key & mouse event
	BaseApplication::createFrameListener();

	if( m_pSky )
		m_pSky->createFrameListener();

	if( m_pTerrain )
		m_pTerrain->createFrameListener();
}

void SkyTest::setupCameraPosition()
{
	mCamera->setPosition(1000, 10000, 1000);
	mCamera->lookAt(0, 0, 0);
}

bool SkyTest::keyPressed(const OIS::KeyEvent &arg)
{
	switch (arg.key)   // toggle visibility of advanced frame stats
    {
	case OIS::KC_0:
		// toggle wether or not sky is visible
//		m_bSkyShow	= !m_bSkyShow;
//		mSkyX->setVisible( m_bSkyShow );
		break;
	case OIS::KC_1:	// sunset, KC_1(0x02) that defined at OISKeyboard.h
	case OIS::KC_2:	// clear
	case OIS::KC_3:	// thunderstorm 1
	case OIS::KC_4:	// thunderstorm 2
	case OIS::KC_5:	// desert
	case OIS::KC_6:	// night, KC_6(0x07) that defined at OISKeyboard.h
	case OIS::KC_7:	// Day and Èå¸², KC_7 that defined at OISKeyboard.h
	case OIS::KC_8:	// Night and Èå¸², KC_8 that defined at OISKeyboard.h
		m_pSky->setPreset( arg.key - OIS::KC_1 );
        break;
    }

 	return BaseApplication::keyPressed( arg );
}
bool SkyTest::keyReleased(const OIS::KeyEvent &arg)
{
	return BaseApplication::keyReleased( arg );
}
bool SkyTest::mouseMoved(const OIS::MouseEvent &arg)
{
	return BaseApplication::mouseMoved( arg);
}
bool SkyTest::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	return BaseApplication::mousePressed( arg, id );
}
bool SkyTest::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{

	return BaseApplication::mouseReleased( arg, id );
}