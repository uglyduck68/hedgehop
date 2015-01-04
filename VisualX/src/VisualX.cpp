/*
-----------------------------------------------------------------------------
Filename:    CVisualX.cpp
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
#include "CollisionTools.h"
#include "VisualX.h"

const char*	VISUALX_CONFIG_FILE	=	"visualx.cfg";

const int	MAX_TARGET	= 50;
const int	MAX_CAMERA_COLLISION_DISTANCE	= 50;

/**
* define space of battle field
*/

const int	MAX_Y		= 1000;					/** elevation */
const int	MAX_X		= COcean::MAX_WIDTH;	/** width */
const int	MAX_Z		= COcean::MAX_HEIGHT;	/** height */

//-------------------------------------------------------------------------------------
CVisualX::CVisualX(void) :
	m_pOcean(NULL), m_pSky(NULL), m_pTerrain(NULL), m_pInputController(NULL),
	m_bCollision(false), m_pCollisionTools(NULL),
	///////////////////////////////////////////////////////////////////////////
	// intro initialization
	///////////////////////////////////////////////////////////////////////////
	m_IsIntro(true),
	m_snIntroTarget(NULL),
	m_nIntroCurIndex(0),
	m_RotTime(ROT_TIME)
{
	///////////////////////////////////////////////////////////////////////////
	// ocean wave Fx
	///////////////////////////////////////////////////////////////////////////
	mActiveVertexProgram.setNull();
	mActiveVertexParameters.setNull();
}
//-------------------------------------------------------------------------------------
void CVisualX::DeleteTargets()
{
	for( TARGET_LIST::iterator itr = m_listTarget.begin(); itr != m_listTarget.end(); itr++ )
	{
//		CTarget*	pTarget	= m_listTarget.front();

		DEL(*itr);
	}
}
CVisualX::~CVisualX(void)
{
	DEL(m_pOcean);
	DEL(m_pSky);
	DEL(m_pTerrain);
	DEL(m_pInputController);

	
	// delete all targets
	DeleteTargets();

	DEL( m_pCollisionTools );
}

void CVisualX::setupCameraPosition()
{
	//
	// setup camera for iso viewing
	//
    mCamera->setPosition(Ogre::Vector3(0,10000,8000));
    // Look back along -Z
    mCamera->lookAt(Ogre::Vector3(0,0,-300));
}

/**
* @function		configure that load visualx configuration file
*/
bool CVisualX::configure(void)
{
	// call ogre configuration setting from ogre dialog
	if( BaseApplication::configure() == false)
		return false;

	// load visualx configuration settings
	m_Config.Load( VISUALX_CONFIG_FILE );

	return true;
}

void CVisualX::CreateIntroViewport()
{
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
* @function		createViewport
* @remarks			BaseApplication 클래스에서 생성하는 
*					전체 스크린에 해당하는 main viewport 외에
*					인트로에 사용될 viewport를 생성한다.
*/
void CVisualX::createViewports(void)
{
	// create the main viewport
	BaseApplication::createViewports();

	///////////////
	// create intro viewport
	///////////////
	CreateIntroViewport();
}


/**
* @function		createCamera that create input controller
*/
void CVisualX::createCamera(void)
{
	assert(mSceneMgr != NULL);

	BaseApplication::createCamera();
}

/**
* @function		CallCreatePostprocess
* @remarks		call CreatePostprocess of CTarget to 
*				post processinf according to characteristic of each target.
* FIXME: 
*	이렇게 후처리를 하면 같은 종류는 같은 후처리를 하게된다. 예를 들어,
*	같은 종류의 전투기는 같은 소리, 엔진 특수 효과 를 갖데된다. 이렇게 되지
*	않으려면 많은 CFighter를 만들면 된다.
*/
void CVisualX::CallCreatePostprocess()
{
	for( TARGET_LIST::iterator itr = m_listTarget.begin(); itr != m_listTarget.end(); itr++ )
	{
		(*itr)->GetSceneNode()->setVisible( true );
		(*itr)->CreatePostprocess();
	}

	setupCameraPosition();
}


//-------------------------------------------------------------------------------------
void CVisualX::createScene(void)
{
	///////////////////////////////////////////////////////////////////////////
	// create target for intro
	///////////////////////////////////////////////////////////////////////////
	if( m_IsIntro == true )
	{
		///////////////////////////////////////////////////////////////////////////
		// create lights
		///////////////////////////////////////////////////////////////////////////

		// Set ambient light
		mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

		// Create a light
		Ogre::Light* l = mSceneMgr->createLight("MainLight");

		l->setPosition(20,80,50);

		///////////////////////////////////////////////////////////////////////////
		// create targets
		///////////////////////////////////////////////////////////////////////////

		///////////
		// create fighter
		///////////
		CFighter*	pFighter	= new (nothrow) CFighter(mSceneMgr, 1, "razor.mesh");

		assert( pFighter != NULL);

		pFighter->GetSceneNode()->setVisible( false );
		m_listTarget.push_back( pFighter );

		CTarget*	pTarget		= new (nothrow) CTarget(mSceneMgr, 2, "ogrehead.mesh");
		pTarget->GetSceneNode()->setVisible( false );
		m_listTarget.push_back( pTarget );

		// Let's start intro
		SetNextIntroTarget();

//		return;
	}

	//////////////////////////////////////////////////////////////////////////////
	// initialize particle system setting
	//////////////////////////////////////////////////////////////////////////////
	ParticleSystem::setDefaultNonVisibleUpdateTimeout(5);  // set nonvisible timeout

	//////////////////////////////////////////////////////////////////////////////
	// initialize ogg sound
	//////////////////////////////////////////////////////////////////////////////
	OgreOggSound::OgreOggSoundManager *mSoundManager	= OgreOggSoundManager::getSingletonPtr();
	
	if( mSoundManager )
		mSoundManager->init();

	if( mCamera->getParentSceneNode() )
		mCamera->getParentSceneNode()->attachObject(mSoundManager->getListener());

	CallCreatePostprocess();

	/*
	// set fighter positino below camera position
	pFighter->GetSceneNode()->setPosition( mCamera->getPosition().x, 
		mCamera->getPosition().y - 100,
		mCamera->getPosition().z );

	pFighter->createFrameListener();
	*/

	///////////////////////////////////////////////////////////////////////////
	// create entities for battlefield
	///////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////
	// create sky
	////////////////////////////////////////////////

	m_pSky		= new (nothrow) CSky(mSceneMgr, mCamera);

	if( m_pSky )
	{
		m_pSky->createScene();
		m_pSky->setVisible( false );
	}


	////////////////////////////////////////////////
	// create terrain
	////////////////////////////////////////////////
//	m_pTerrain		= new (nothrow) CTerrain(mSceneMgr, mCamera);

	if( m_pTerrain )
	{
		m_pTerrain->createScene();
		m_pTerrain->createFrameListener();
	}

	///////////////////////////////////////////////////////////////////////////
	// create ocean
	///////////////////////////////////////////////////////////////////////////

	m_pOcean	= new (nothrow) COcean(mSceneMgr);

	if( m_pOcean )
	{
		m_pOcean->createScene();
		m_pOcean->setVisible( false );
	}


#if	0
	///
	// create sample targets for performance test
	///
	srand( (unsigned)time( NULL ) );

	for(int i = 0; i < MAX_TARGET; i++)
	{
		CTarget*	pTarget	= new (nothrow) CTarget(mSceneMgr, i, "ogrehead.mesh");

		assert(pTarget);

		/**
		* locate the target around the camera
		*/
		Ogre::Vector3	position	= mCamera->getPosition();
		int				nRangeMin	= 0;
		int				nRangeMax	= 1000;

		pTarget->setPosition((float)rand() / (RAND_MAX + 1) * (nRangeMax - nRangeMin) + position.x, 
#if	1
			(float)rand() / (RAND_MAX + 1) * (nRangeMax - nRangeMin) + position.y, 
#else
			/* for interference test with ocean */
			m_pOcean->GetSurface() - 10, 
#endif
			(float)rand() / (RAND_MAX + 1) * (nRangeMax - nRangeMin) + position.z);

		m_listTarget.push_back(pTarget);

		/* add frame listener */
		pTarget->createFrameListener();
	}
#endif

#if		0
	m_pInputController	= new (nothrow) CInputController(mRoot, mKeyboard, mMouse);
	if( m_pInputController )
		/* add frame listener */
		m_pInputController->createFrameListener();
#endif

	///////////////////////////////////////////////////////////////////////////
	// create CollisionTools
	///////////////////////////////////////////////////////////////////////////
	m_pCollisionTools	= new (nothrow) MOC::CollisionTools( mSceneMgr );

	if( m_pCollisionTools )
	{
		// error case. log it.
	}

//#ifdef	_DEBUG
	// make xyz-axis for debugging
	Ogre::Entity* mAxesEntity = mSceneMgr->createEntity("Axes", "axes.mesh");
	mSceneMgr->getRootSceneNode()->createChildSceneNode("AxesNode",Ogre::Vector3(0,0,0))->attachObject(mAxesEntity);
	mSceneMgr->getSceneNode("AxesNode")->setScale(50, 50, 50);
//#endif


}

void CVisualX::setupResources(void)
{
	// load base class's resources
	BaseApplication::setupResources();

	/** add my own resource location */
	Ogre::ResourceGroupManager::getSingleton().addResourceLocation("./resource",
		"FileSystem");

	// following call cause assertion fails.
	// BaseApplication::loadResources() function has following call.
//	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}

void CVisualX::createFrameListener(void)
{
	// add base frame listener
	BaseApplication::createFrameListener();

	if(m_pSky)
		m_pSky->createFrameListener();

	// create ray scene query for collision detection
	mRaySceneQuery = mSceneMgr->createRayQuery(Ogre::Ray());
}

bool CVisualX::frameStarted( const FrameEvent &evt )
{

	return BaseApplication::frameStarted( evt );
}
    
bool CVisualX::frameRenderingQueued(const Ogre::FrameEvent& evt)
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

	/** 
	* RAY_Y_ORG is bigger than camPos.y because check wether or not camera is under the ocean.
	* distToColl is RAY_Y_ORG - m_pOcean->GetSurface() where camera is above ocean.
	*/
	const Ogre::Real RAY_Y_ORG			= 50000.0f;	
	const Ogre::Real CAM_COLLISION_MIN	= 100.0f;
	Ogre::Real		distToColl	= 0;
	Ogre::Vector3	camPos		= mCamera->getPosition();
	Ogre::Ray		camRay(Ogre::Vector3(camPos.x, RAY_Y_ORG, camPos.z), Ogre::Vector3::NEGATIVE_UNIT_Y);
	Ogre::Vector3	hitPos		= Ogre::Vector3::ZERO;
	Ogre::Entity*	pEntity		= NULL;
	bool			bCamPosMoved	= false;

	//////////////////////////////////////////////////////////////////////////////
	// check the collision with terrain
	//////////////////////////////////////////////////////////////////////////////

	// IsCollision do *NOT* work for ColMESH3.mesh
	if( m_pTerrain && m_pTerrain->IsCollision( camRay, hitPos, pEntity, distToColl ))
	{
//		DebugPrintf("Debug: camRay intersect with terrain. dist: %f hit pos: (%f, %f, %f), cam pos: (%f, %f, %f)", 
//			distToColl, hitPos.x, hitPos.y, hitPos.z, camPos.x, camPos.y, camPos.z );

		if(( hitPos == camPos ) || ( hitPos.y > camPos.y ))
		{
			// if camera meet the terrain or camera is under the terrain, 
			// then move camera up to terrain
			mCamera->setPosition( camPos.x, hitPos.y + CAM_COLLISION_MIN*2, camPos.z );

			bCamPosMoved	= true;
		}
		else if( fabs(camPos.y - hitPos.y) < CAM_COLLISION_MIN )
		{
			// if ray hit the terrain and the distance between hit position and camera is
			// less than 100, make camera higher
			mCamera->setPosition( camPos.x, hitPos.y + CAM_COLLISION_MIN*2, camPos.z );
		
			bCamPosMoved	= true;
		}
	}

	//////////////////////////////////////////////////////////////////////////////
	// check the collision with ocean
	//////////////////////////////////////////////////////////////////////////////
	camRay.setOrigin( mCamera->getPosition( ));

	if( bCamPosMoved == false )
	{
		if( m_pOcean && m_pOcean->IsCollision( camRay, &distToColl ))
		{
			// cam is too low or cam is under the ocean, then make cam higher from ocean
			if( distToColl < (CAM_COLLISION_MIN + COcean::GetSurface()))
				mCamera->setPosition( camPos.x, CAM_COLLISION_MIN + COcean::GetSurface(), camPos.z );

//		DebugPrintf("Debug: camRay intersect with ocean. dist: %f", distToColl );
		}
		else
		{
			// camera is always on the ocean, so there is hit with ocean always.
			// If no collision then camera is under the ocean.
			mCamera->setPosition( camPos.x, CAM_COLLISION_MIN + COcean::GetSurface(), camPos.z );
		}
	}

	//if( m_pCollisionTools->raycast( camRay, hitPos, pEntity, distToColl ))
	//{
	//	DebugPrintf("Debug: collision detected: dist: %f, hit pos: (%f, %f, %f), cam pos: (%f, %f, %f)",
	//		distToColl, hitPos.x, hitPos.y, hitPos.z, camPos.x, camPos.y, camPos.z );

	//	if( hitPos.y > camPos.y )
	//	{
	//		// camera is under the hit position. eg. camera under the ocean
	//		mCamera->setPosition( camPos.x, hitPos.y + 1000, camPos.z );
	//	}
	//	else if( camPos.y - hitPos.y < 100 )
	//	{
	//		// is about to hit the entity
	//		mCamera->setPosition( camPos.x, camPos.y + (100), camPos.z );
	//	}
	//}
	//else
	//{
	//	DebugPrintf("Debug: cam pos: (%f, %f, %f)", camPos.x, camPos.y, camPos.z );
	//}


//	if( CheckCollision( camPos, Ogre::Vector3::NEGATIVE_UNIT_Y, distToColl, hitPos ) == true )
	//{
	//	DebugPrintf("Debug: collision detected: dist: %f, hit pos: (%f, %f, %f), cam pos: (%f, %f, %f)",
	//		distToColl, hitPos.x, hitPos.y, hitPos.z, camPos.x, camPos.y, camPos.z );

	//	if( distToColl < 100.0f )
	//		// camera is about to collide with any thing
	//		// stop the camera or move the camera to avoid the collision here
	//		mCamera->setPosition( camPos.x, camPos.y + 100, camPos.z );
	//}

	return BaseApplication::frameRenderingQueued( evt );
}

void CVisualX::controlWaveFreq(int nKey)
{
	static Real	waveFreq	= 0.028f;
	static Real waveAmp		= 1.8f;

	mActiveMaterial = Ogre::MaterialManager::getSingleton().getByName( "Ocean2_Cg" );
	mActiveMaterial->load();
	Ogre::Technique* currentTechnique = mActiveMaterial->getSupportedTechnique(0);

	if(currentTechnique)
	{
		mActivePass = currentTechnique->getPass(0);

		if(mActivePass)
		{
			if (mActivePass->hasFragmentProgram())
			{
				mActiveFragmentProgram = mActivePass->getFragmentProgram();
				mActiveFragmentParameters = mActivePass->getFragmentProgramParameters();
			}
			if (mActivePass->hasVertexProgram())
			{
				mActiveVertexProgram = mActivePass->getVertexProgram();
				mActiveVertexParameters = mActivePass->getVertexProgramParameters();

				waveFreq	*= 2;
				waveAmp		*= 2;

				mActiveVertexParameters->setNamedConstant("waveFreq", waveFreq);
				mActiveVertexParameters->setNamedConstant("waveAmp", waveAmp);
			}

			GpuProgramParametersSharedPtr activeParameters = mActiveVertexParameters;

			if(!activeParameters.isNull())
			{
				activeParameters->_writeRawConstant(
					6, waveFreq);
			}		}
	}

}

bool CVisualX::keyPressed(const OIS::KeyEvent &arg)
{
	if( m_IsIntro && arg.key == OIS::KC_SPACE )
	{
		SetNextIntroTarget();

		//if( m_snIntroTarget == NULL )
		//{
		//	///////////////////////////////////////////////////////////////////
		//	// end the intro mode
		//	///////////////////////////////////////////////////////////////////
		//	SetIntroEnd();
		//}
	
		return BaseApplication::keyPressed(arg);
	}

	switch(arg.key)
	{
	case OIS::KC_1:
		// increase waveFreq by multiplying 2
		m_pOcean->ControlWaveFreq( WAVEFX_INC, 0.01 );
		break;
	case OIS::KC_2:
		// increase waveFreq by multiplying 2
		m_pOcean->ControlWaveFreq( WAVEFX_INC, -0.01 );
		break;
	case OIS::KC_3:
		// increase waveFreq by multiplying 2
		m_pOcean->ControlWaveAmp( WAVEFX_INC, 2 );
		break;
	case OIS::KC_4:
		// increase waveFreq by multiplying 2
		m_pOcean->ControlWaveAmp( WAVEFX_INC, -2 );
		break;
	case OIS::KC_W:
	case OIS::KC_UP:
		if( m_bCollision )
			return true;
	default:
		break;
	}

	return BaseApplication::keyPressed(arg);
}

bool CVisualX::keyReleased(const OIS::KeyEvent &arg)
{
	return BaseApplication::keyReleased(arg);
}

/**
* @function		CheckCollision
* @remark		for ocean and terrain I will execute the query to check the collision with camera,
*				But for characters like ships, fighter I will calc. the distance from camera
*				to character and I will judge the collision using the distance.
*				But currently collison function do *NOT* work for ocean and terrain.
* @return		true if camera is about to collide with any target except the plane (ocean).
*/
bool  CVisualX::CheckCollision(const Ogre::Vector3& position, const Ogre::Vector3& direction, 
	Ogre::Real& distToColl, Ogre::Vector3& hitPos)
{
	if( m_pCollisionTools )
	{
		Ogre::Entity*	target	= NULL;

//		position + direction * Ogre::Vector3(3,3,3);
		if( m_pCollisionTools->raycastFromPoint( position, direction, hitPos, target, distToColl ))
		{
			return true;
		}

		return false;
	}

    Ogre::Ray ray(position, direction);

	// I will execute the query for world geometry that is maybe
	// plane, geometry, singleIntersection, or renderOp.
	mRaySceneQuery->setQueryTypeMask( Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
	mRaySceneQuery->setWorldFragmentType( Ogre::RaySceneQuery::WFT_SINGLE_INTERSECTION );
    mRaySceneQuery->setRay(ray);
	mRaySceneQuery->setSortByDistance(true);
	mRaySceneQuery->setQueryMask(0xFFFFFFFF);	/** catch any entity */

    Ogre::RaySceneQueryResult &result = mRaySceneQuery->execute();

    Ogre::RaySceneQueryResult::iterator itr;

	int	i = 0;
    for (itr = result.begin(); itr != result.end(); itr++, i++) 
	{
		DebugPrintf("distance[%d]: %f", i, itr->distance);
		/* NOTE
		* distance between two frames is 1459.913086 (shift+w key).
		* so collision distance is bigger than 1459.913086. <--- maybe WRONG!!!
		*/
		if( itr->distance != 0 && itr->distance < 1500 )
			return true;

		//if( itr->worldFragment->singleIntersection.distance() )
		//{
		//	return true;
		//}
    }

	return false;
}

bool CVisualX::mouseMoved(const OIS::MouseEvent &arg)
{
	if (m_IsIntro)
		return true;

	return BaseApplication::mouseMoved( arg );
}

bool CVisualX::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	if (m_IsIntro)
		return true;
	return BaseApplication::mousePressed( arg, id );
}

bool CVisualX::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	if (m_IsIntro)
		return true;
	return BaseApplication::mouseReleased( arg, id );
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
        CVisualX app;

        try {
            app.go();
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
