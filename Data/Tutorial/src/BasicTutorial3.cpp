#include "StdAfx.h"
#include "..\include\BasicTutorial3.h"


BasicTutorial3::BasicTutorial3(void)
{
}


BasicTutorial3::~BasicTutorial3(void)
{
}
//-------------------------------------------------------------------------------------
void BasicTutorial3::destroyScene(void)
{
    OGRE_DELETE mTerrainGroup;
    OGRE_DELETE mTerrainGlobals;
 
}
//-------------------------------------------------------------------------------------
void getTerrainImage(bool flipX, bool flipY, Ogre::Image& img)
{
    img.load("terrain.png", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    if (flipX)
        img.flipAroundY();
    if (flipY)
        img.flipAroundX();
 
 
}
//-------------------------------------------------------------------------------------
void BasicTutorial3::defineTerrain(long x, long y)
{
    Ogre::String filename = mTerrainGroup->generateFilename(x, y);
    if (Ogre::ResourceGroupManager::getSingleton().resourceExists(mTerrainGroup->getResourceGroup(), filename))
    {
        mTerrainGroup->defineTerrain(x, y);
    }
    else
    {
        Ogre::Image img;
        getTerrainImage(x % 2 != 0, y % 2 != 0, img);
        mTerrainGroup->defineTerrain(x, y, &img);
        mTerrainsImported = true;
    }
 
}
//-------------------------------------------------------------------------------------
void BasicTutorial3::initBlendMaps(Ogre::Terrain* terrain)
{
    Ogre::TerrainLayerBlendMap* blendMap0 = terrain->getLayerBlendMap(1);
    Ogre::TerrainLayerBlendMap* blendMap1 = terrain->getLayerBlendMap(2);
    Ogre::Real minHeight0 = 70;
    Ogre::Real fadeDist0 = 40;
    Ogre::Real minHeight1 = 70;
    Ogre::Real fadeDist1 = 15;
    float* pBlend0 = blendMap0->getBlendPointer();
    float* pBlend1 = blendMap1->getBlendPointer();
    for (Ogre::uint16 y = 0; y < terrain->getLayerBlendMapSize(); ++y)
    {
        for (Ogre::uint16 x = 0; x < terrain->getLayerBlendMapSize(); ++x)
        {
            Ogre::Real tx, ty;
 
            blendMap0->convertImageToTerrainSpace(x, y, &tx, &ty);
            Ogre::Real height = terrain->getHeightAtTerrainPosition(tx, ty);
            Ogre::Real val = (height - minHeight0) / fadeDist0;
            val = Ogre::Math::Clamp(val, (Ogre::Real)0, (Ogre::Real)1);
            *pBlend0++ = val;
 
            val = (height - minHeight1) / fadeDist1;
            val = Ogre::Math::Clamp(val, (Ogre::Real)0, (Ogre::Real)1);
            *pBlend1++ = val;
        }
    }
    blendMap0->dirty();
    blendMap1->dirty();
    blendMap0->update();
    blendMap1->update();
 
}
//-------------------------------------------------------------------------------------
void BasicTutorial3::configureTerrainDefaults(Ogre::Light* light)
{
	// Configure global

	// lower number more vertices and more accurate terrain
	mTerrainGlobals->setMaxPixelError(8);
	// testing composite map
	// setCompositeMapDistance decides how far the Ogre terrain will render the lightmap terrain
	mTerrainGlobals->setCompositeMapDistance(3000); 

// Configure default import settings for if we use imported image
    Ogre::Terrain::ImportData& defaultimp = mTerrainGroup->getDefaultImportSettings();
    defaultimp.terrainSize = 513;
    defaultimp.worldSize = 12000.0f;
    defaultimp.inputScale = 600; // due terrain.png is 8 bpp
    defaultimp.minBatchSize = 33;
    defaultimp.maxBatchSize = 65;

// textures
    defaultimp.layerList.resize(3);
    defaultimp.layerList[0].worldSize = 100;
    defaultimp.layerList[0].textureNames.push_back("dirt_grayrocky_diffusespecular.dds");
    defaultimp.layerList[0].textureNames.push_back("dirt_grayrocky_normalheight.dds");
    defaultimp.layerList[1].worldSize = 30;
    defaultimp.layerList[1].textureNames.push_back("grass_green-01_diffusespecular.dds");
    defaultimp.layerList[1].textureNames.push_back("grass_green-01_normalheight.dds");
    defaultimp.layerList[2].worldSize = 200;
    defaultimp.layerList[2].textureNames.push_back("growth_weirdfungus-03_diffusespecular.dds");
    defaultimp.layerList[2].textureNames.push_back("growth_weirdfungus-03_normalheight.dds");
}
//-------------------------------------------------------------------------------------
void BasicTutorial3::createScene(void)
{
	mCamera->setPosition(Ogre::Vector3(1683, 50, 2116));
	mCamera->lookAt(Ogre::Vector3(1963, 50, 1660));
	mCamera->setNearClipDistance(0.1);
	mCamera->setFarClipDistance(50000);

	if (mRoot->getRenderSystem()->getCapabilities()->hasCapability(Ogre::RSC_INFINITE_FAR_PLANE))
	{
		mCamera->setFarClipDistance(0);   // enable infinite far clip distance if we can
  
		Ogre::LogManager::getSingletonPtr()->logMessage("Ogre::RSC_INFINITE_FAR_PLANE is supported. far clip distance is infinite.");
	} 


Ogre::Vector3 lightdir(0.55, -0.3, 0.75);
    lightdir.normalise();
 
    Ogre::Light* light = mSceneMgr->createLight("tstLight");
    light->setType(Ogre::Light::LT_DIRECTIONAL);
    light->setDirection(lightdir);
    light->setDiffuseColour(Ogre::ColourValue::White);
    light->setSpecularColour(Ogre::ColourValue(0.4, 0.4, 0.4));
 
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.2, 0.2, 0.2));

	mTerrainGlobals = OGRE_NEW Ogre::TerrainGlobalOptions();

	mTerrainGroup = OGRE_NEW Ogre::TerrainGroup(mSceneMgr, Ogre::Terrain::ALIGN_X_Z, 
		513,		// terrain size
		12000.0f	// world size
		);
    mTerrainGroup->setFilenameConvention(Ogre::String("BasicTutorial3Terrain"), Ogre::String("dat"));
    mTerrainGroup->setOrigin(Ogre::Vector3::ZERO);

	configureTerrainDefaults(light);

	for (long x = 0; x <= 0; ++x)
        for (long y = 0; y <= 0; ++y)
            defineTerrain(x, y);
 
    // sync load since we want everything in place when we start
    mTerrainGroup->loadAllTerrains(true);

	if (mTerrainsImported)
    {
        Ogre::TerrainGroup::TerrainIterator ti = mTerrainGroup->getTerrainIterator();
        while(ti.hasMoreElements())
        {
            Ogre::Terrain* t = ti.getNext()->instance;
            initBlendMaps(t);
        }
    }

	mTerrainGroup->freeTemporaryResources();
}
//-------------------------------------------------------------------------------------
void BasicTutorial3::createFrameListener(void)
{
    BaseApplication::createFrameListener();
 
    mInfoLabel = mTrayMgr->createLabel(OgreBites::TL_TOP, "TInfo", "", 350);
	/** 
	* get followings from Intermediate Tutorial 02 
	*/
	// Setup default variables
	mCount = 0;
	mCurrentObject = NULL;
	mLMouseDown = false;
	mRMouseDown = false;
	// Reduce move speed
	//mMoveSpeed = 50;
	mRotateSpeed = .1;
	// Create RaySceneQuery
	mRaySceneQuery = mSceneMgr->createRayQuery(Ogre::Ray());
 
	//SdkTray - version - to get the mouse cursor on the screen:
	mTrayMgr->showCursor();
 
}
//-------------------------------------------------------------------------------------
bool BasicTutorial3::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
    bool ret = BaseApplication::frameRenderingQueued(evt);
    if (mTerrainGroup->isDerivedDataUpdateInProgress())
    {
        mTrayMgr->moveWidgetToTray(mInfoLabel, OgreBites::TL_TOP, 0);
        mInfoLabel->show();
        if (mTerrainsImported)
        {
            mInfoLabel->setCaption("Building terrain, please wait...");
        }
        else
        {
            mInfoLabel->setCaption("Updating textures, patience...");
        }
    }
    else
    {
        mTrayMgr->removeWidgetFromTray(mInfoLabel);
        mInfoLabel->hide();
        if (mTerrainsImported)
        {
            mTerrainGroup->saveAllTerrains(true);
            mTerrainsImported = false;
        }
    }
	/** 
	* get followings from Intermediate Tutorial 02 
	*/
	// Setup the scene query
	Ogre::Vector3	camPos = mCamera->getPosition();
	Ogre::Ray		cameraRay(Ogre::Vector3(camPos.x, 5000.0f, camPos.z), Ogre::Vector3::NEGATIVE_UNIT_Y);

#if	1
	/**
	* Ogre v1.9에서 전반적으로 잘 동작한다.
	* 하지만 지형과 camera가 거의 직각으로 만나는경우 지형을 뚫고 지나가는 버그가 있다 [solved].
	*/
	Ogre::TerrainGroup::RayResult	result	= mTerrainGroup->rayIntersects(cameraRay);


	if(( result.position == camPos ) || ( result.position.y > camPos.y ))
	{
		// if camera meet the terrain or camera is under the terrain, 
		// then move camera up to terrain
		mCamera->setPosition(result.position.x, result.position.y + 10, result.position.z );
	}
	else if( result.hit && fabs(camPos.y - result.position.y) < 10 )
	{
		// if ray hit the terrain and the distance between hit position and camera is
		// less than 100, make camera higher
		mCamera->setPosition( camPos.x, result.position.y + 10, camPos.z );

	}
#else
	/** 
	* get followings from Intermediate Tutorial 02 
	*/
	mRaySceneQuery->setRay(cameraRay);
 
	// Perform the scene query
	Ogre::RaySceneQueryResult &result = mRaySceneQuery->execute();
	Ogre::RaySceneQueryResult::iterator itr = result.begin();

	// Get the results, set the camera height
	if (itr != result.end() && itr->worldFragment)
	{
	    DebugPrintf("Debug: collision detected: cam pos(%f, %f, %f) terrain height: %f",
			camPos.x, camPos.y, camPos.z, itr->worldFragment->singleIntersection.y);

		Ogre::Real terrainHeight = itr->worldFragment->singleIntersection.y;

		if ((terrainHeight + 100.0f) > camPos.y)
			mCamera->setPosition( camPos.x, terrainHeight + 100.0f, camPos.z );
	}
#endif 
    return ret;
}