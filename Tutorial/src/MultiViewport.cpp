#include "StdAfx.h"
#include "..\include\MultiViewport.h"


MultiViewport::MultiViewport(void) :
	m_IsIntro(true),
	m_snIntroTarget(NULL),
	m_RotTime(ROT_TIME)
{
}


MultiViewport::~MultiViewport(void)
{
}

void MultiViewport::setupCameraPosition()
{
	//
	// setup camera for iso viewing
	//
    mCamera->setPosition(Ogre::Vector3(1000, 1000, 1000));

    mCamera->lookAt(Ogre::Vector3(0, 0, 0));
}

/**
* @function		createViewport
* @remarks			BaseApplication 클래스에서 생성하는 
*					전체 스크린에 해당하는 main viewport 외에
*					인트로에 사용될 viewport를 생성한다.
*/
void MultiViewport::createViewports(void)
{
	// create the main viewport
	BaseApplication::createViewports();

	//
	// create intro viewport
	//

	m_IntroCamera		= mSceneMgr->createCamera("IntroCamera");

	if( m_IntroCamera )
	{
		m_IntroCamera->setPosition(100, 100, 100);
		m_IntroCamera->lookAt(0, 0, 0);
	}

	m_IntroViewport		= mWindow->addViewport(m_IntroCamera, 1, 0.2, 0.2, 0.6, 0.6);

	if( m_IntroViewport )
	{
		m_IntroViewport->setBackgroundColour(Ogre::ColourValue(0.2, 0.2, 0.2));
		m_IntroCamera->setAspectRatio( Real(m_IntroViewport->getActualWidth()) / 
			Real(m_IntroViewport->getActualHeight()));
	}
}

/**
* @function		createScene
* @remarks			인트로에 사용될 타켓을 만든다. 일단
*					ogrehead를 여러개 만든어 회전 인트로 테스트만
*					진행하자. 실제에서는 소리까지 있어야 할지 모른다.
*/
void MultiViewport::createScene(void)
{
	Ogre::SceneNode*		pTemp	= NULL;

    // Set ambient light
	mSceneMgr->setAmbientLight(ColourValue(0.5f, 0.5f, 0.5f));
    
	///////////////////////////////////////////////////////////////////////////
	// create 1st target
	///////////////////////////////////////////////////////////////////////////
	Entity* ent = mSceneMgr->createEntity("head", "ogrehead.mesh");

    // Add entity to the root scene node
    pTemp	= mSceneMgr->getRootSceneNode()->createChildSceneNode();
	pTemp->attachObject(ent);
	pTemp->setVisible(false);

	// insert 1st target
	m_TargetList.push_back( pTemp );

	///////////////////////////////////////////////////////////////////////////
	// create 2nd target
	///////////////////////////////////////////////////////////////////////////
	ent = mSceneMgr->createEntity("ninja", "ninja.mesh");

    // Add entity to the root scene node
    pTemp	= mSceneMgr->getRootSceneNode()->createChildSceneNode();
	pTemp->attachObject(ent);
	pTemp->setVisible(false);

	// insert 2nd target
	m_TargetList.push_back( pTemp );

	///////////////////////////////////////////////////////////////////////////
	// create 3rd target
	///////////////////////////////////////////////////////////////////////////
	ent = mSceneMgr->createEntity("razor", "razor.mesh");

    // Add entity to the root scene node
    pTemp	= mSceneMgr->getRootSceneNode()->createChildSceneNode();
	pTemp->attachObject(ent);
	pTemp->setVisible(false);

	// insert 3rd target
	m_TargetList.push_back( pTemp );

	// set intro taget initially
	SetNextIntroTarget();
}

void MultiViewport::createFrameListener(void)
{
	// BaseApplication::createFrameListener create mTrayMgr
	BaseApplication::createFrameListener();

	// if intro mode, then hide all information
	if (m_IsIntro)
		mTrayMgr->hideAll();
}

bool MultiViewport::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
	if( m_IsIntro && m_snIntroTarget)
	{
		m_snIntroTarget->yaw(Degree(evt.timeSinceLastFrame * 30));

		m_RotTime		-= evt.timeSinceLastFrame;

		if( m_RotTime < 0 )
		{
			SetNextIntroTarget();
		}
	}


	// check shutdown and update the panel information
	return BaseApplication::frameRenderingQueued( evt );
}

bool MultiViewport::keyPressed(const OIS::KeyEvent &arg)
{
	if( m_IsIntro && arg.key == OIS::KC_SPACE )
	{
		SetNextIntroTarget();

		if( m_snIntroTarget == NULL )
		{
			///////////////////////////////////////////////////////////////////
			// end the intro mode
			///////////////////////////////////////////////////////////////////
			SetIntroEnd();
		}
	}

	return BaseApplication::keyPressed( arg );
}
bool MultiViewport::keyReleased(const OIS::KeyEvent &arg)
{
	return BaseApplication::keyReleased( arg );
}

bool MultiViewport::mouseMoved(const OIS::MouseEvent &arg)
{
	if (m_IsIntro)
		return true;

	return BaseApplication::mouseMoved( arg );
}

bool MultiViewport::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	if (m_IsIntro)
		return true;
	return BaseApplication::mousePressed( arg, id );
}

bool MultiViewport::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	if (m_IsIntro)
		return true;
	return BaseApplication::mouseReleased( arg, id );
}
