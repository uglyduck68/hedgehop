/**
 * @file		Terrain.cpp
 * @remarks		implement terrain
 */

#include "StdAfx.h"

#include "Terrain.h"


CTerrain::CTerrain(Ogre::SceneManager* pSceneMgr, Ogre::Camera* pCamera) :
	mSceneMgr(pSceneMgr), mCamera(pCamera), mTerrainGlobals(NULL), mTerrainGroup(NULL),
	mTerrainsImported(false),
	m_pCollisionTools(NULL),
	m_bCollision(false)
{
	mRoot	= Ogre::Root::getSingletonPtr();
}


CTerrain::~CTerrain(void)
{
	DEL( m_pCollisionTools );
}

//-------------------------------------------------------------------------------------
void CTerrain::destroyScene(void)
{
	if( mTerrainGroup )
		OGRE_DELETE mTerrainGroup;
	if( mTerrainGlobals )
	    OGRE_DELETE mTerrainGlobals; 
}
//-------------------------------------------------------------------------------------
void CTerrain::getTerrainImage(bool flipX, bool flipY, Ogre::Image& img)
{
    img.load("terrain.png", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    if (flipX)
        img.flipAroundY();
    if (flipY)
        img.flipAroundX();
 
}
//-------------------------------------------------------------------------------------
void CTerrain::defineTerrain(long x, long y)
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
void CTerrain::initBlendMaps(Ogre::Terrain* terrain)
{
	/*
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
	*/
}
//-------------------------------------------------------------------------------------
void CTerrain::configureTerrainDefaults(Ogre::Light* light)
{
// Configure global
    mTerrainGlobals->setMaxPixelError(8);

    // testing composite map
    mTerrainGlobals->setCompositeMapDistance(3000); 

// Important to set these so that the terrain knows what to use for derived (non-realtime) data
    mTerrainGlobals->setLightMapDirection(light->getDerivedDirection());
    mTerrainGlobals->setCompositeMapAmbient(mSceneMgr->getAmbientLight());
    mTerrainGlobals->setCompositeMapDiffuse(light->getDiffuseColour());

    // Configure default import settings for if we use imported image
    Ogre::Terrain::ImportData& defaultimp = mTerrainGroup->getDefaultImportSettings();

	defaultimp.terrainSize = 2049;
    defaultimp.worldSize = 96000.0f;
    defaultimp.inputScale = 600;
    defaultimp.minBatchSize = 33;
    defaultimp.maxBatchSize = 65;

// textures
	/*
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
	*/
	//oskim, initBlendMaps() 적용하지 않아야 아래 코드가 실행됨
	defaultimp.layerList.resize(1);
	defaultimp.layerList[0].worldSize = 96000.0f;
	defaultimp.layerList[0].textureNames.push_back("Colombia.jpg");

}
//-------------------------------------------------------------------------------------
void CTerrain::createScene(void)
{
#if	1
	// define initial position of terrain
	float fx = -2000.0f;
	float fz = -10.0f;
	float fy = 0.0f;

	Ogre::Entity*		TerrainEnty;
	Ogre::SceneNode*	TerrainNode;

	// Create an Entity
	TerrainEnty = mSceneMgr->createEntity("Terrain0", "out_x1y1.mesh");
	TerrainNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("ColombiaTerrain0");
	TerrainNode->attachObject( TerrainEnty );
	//colTerrainScene0->setPosition(-1700.0f,0.5f,-100.0f);
	TerrainNode->setPosition(fx, fz, fy);

	m_vecTerrainEnty.push_back( TerrainEnty );
	m_vecTerrainNode.push_back( TerrainNode );

	Ogre::Entity* ogreTerrain1 = mSceneMgr->createEntity("Terrain1", "out_x2y1.mesh");
	Ogre::SceneNode* colTerrainScene1 = mSceneMgr->getRootSceneNode()->createChildSceneNode("ColombiaTerrain1");
	colTerrainScene1->attachObject(ogreTerrain1);
	colTerrainScene1->setPosition(fx, fz, fy);
	
	Ogre::Entity* ogreTerrain2 = mSceneMgr->createEntity("Terrain2", "out_x2y2.mesh");
	Ogre::SceneNode* colTerrainScene2 = mSceneMgr->getRootSceneNode()->createChildSceneNode("ColombiaTerrain2");
	colTerrainScene2->attachObject(ogreTerrain2);
	colTerrainScene2->setPosition(fx, fz, fy);

	Ogre::Entity* ogreTerrain3 = mSceneMgr->createEntity("Terrain3", "out_x2y3.mesh");
	Ogre::SceneNode* colTerrainScene3 = mSceneMgr->getRootSceneNode()->createChildSceneNode("ColombiaTerrain3");
	colTerrainScene3->attachObject(ogreTerrain3);
	colTerrainScene3->setPosition(fx, fz, fy);

	Ogre::Entity* ogreTerrain4 = mSceneMgr->createEntity("Terrain4", "out_x2y4.mesh");
	Ogre::SceneNode* colTerrainScene4 = mSceneMgr->getRootSceneNode()->createChildSceneNode("ColombiaTerrain4");
	colTerrainScene4->attachObject(ogreTerrain4);
	colTerrainScene4->setPosition(fx, fz, fy);

	Ogre::Entity* ogreTerrain5 = mSceneMgr->createEntity("Terrain5", "out_x3y4.mesh");
	Ogre::SceneNode* colTerrainScene5 = mSceneMgr->getRootSceneNode()->createChildSceneNode("ColombiaTerrain5");
	colTerrainScene5->attachObject(ogreTerrain5);
	colTerrainScene5->setPosition(fx, fz, fy);

	Ogre::Entity* ogreTerrain6 = mSceneMgr->createEntity("Terrain6", "out_x4y4.mesh");
	Ogre::SceneNode* colTerrainScene6 = mSceneMgr->getRootSceneNode()->createChildSceneNode("ColombiaTerrain6");
	colTerrainScene6->attachObject(ogreTerrain6);
	colTerrainScene6->setPosition(fx, fz, fy);
	//////
	// test big terrain data
	//////
//	m_pTerrainEnt = mSceneMgr->createEntity("Terrain", "ColMESH3.mesh");
//	m_pTerrainEnt->setMaterialName("ColMESH");
//	mSceneMgr->getRootSceneNode()->createChildSceneNode("TerrainNode")->attachObject(m_pTerrainEnt);
//
//	// scale up the terrain
//	mSceneMgr->getSceneNode("TerrainNode")->setScale(500, 200, 500);
#else
	//////
	// following is orge tutorial that is using TerrainGlobalOption and TerrainGroup.
	// But the functionality of TerrainGroup is *NOT* perfect. in case of small terrain
	// there are too many swapping.
	//////
    Ogre::MaterialManager::getSingleton().setDefaultTextureFiltering(Ogre::TFO_ANISOTROPIC);
    Ogre::MaterialManager::getSingleton().setDefaultAnisotropy(7);
 
    Ogre::Vector3 lightdir(0.55, -0.3, 0.75);
    lightdir.normalise();
// 
    Ogre::Light* light = mSceneMgr->createLight("tstLight");
    light->setType(Ogre::Light::LT_DIRECTIONAL);
    light->setDirection(lightdir);
//    light->setDiffuseColour(Ogre::ColourValue::White);
//    light->setSpecularColour(Ogre::ColourValue(0.4, 0.4, 0.4));
 
    mTerrainGlobals = OGRE_NEW Ogre::TerrainGlobalOptions();
 
	// 2049 terrain size and 96000 terrain world size
    mTerrainGroup = OGRE_NEW Ogre::TerrainGroup(mSceneMgr, Ogre::Terrain::ALIGN_X_Z, 2049, 96000.0f);
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
#endif
	//////////////////////////////////////////////////////////////////////////////
	// create debug overlay
	//////////////////////////////////////////////////////////////////////////////
//	createDebugOverlay();
 
	m_pCollisionTools	= new MOC::CollisionTools( mSceneMgr );

}
//-------------------------------------------------------------------------------------
void CTerrain::createFrameListener(void)
{
}

//-------------------------------------------------------------------------------------
bool CTerrain::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
//    bool ret = BaseApplication::frameRenderingQueued(evt);
 
    if (mTerrainGroup->isDerivedDataUpdateInProgress())
    {
        if (mTerrainsImported)
        {
			printf("Building terrain, please wait...");
//			printMsgToDebugOverlay("Building terrain, please wait...");
        }
        else
        {
			printf("Updating textures, patience...");
//			printMsgToDebugOverlay("Updating textures, patience...");
        }
    }
    else
    {
        if (mTerrainsImported)
        {
            mTerrainGroup->saveAllTerrains(true);
            mTerrainsImported = false;
        }
    }
 
    return true;
}

bool CTerrain::IsCollision( Ogre::Camera* Cam, Ogre::Real* CollDist )
{

	/** 
	* RAY_Y_ORG is bigger than camPos.y because check wether or not camera is under the ocean.
	* distToColl is RAY_Y_ORG - m_pOcean->GetSurface() where camera is above ocean.
	*/
	const Ogre::Real RAY_Y_ORG			= 50000.0f;	
	Ogre::Vector3	camPos		= Cam->getPosition();
	Ogre::Ray		camRay(Ogre::Vector3(camPos.x, RAY_Y_ORG, camPos.z), Ogre::Vector3::NEGATIVE_UNIT_Y);
	Ogre::Vector3	result		= Ogre::Vector3::ZERO;
	float			ClosestDistance;

	/**
	* FIXME
	*	- raycast is very time consuming that cause 1 FPS
	*/
	bool			bColl	= m_pCollisionTools->raycast(camRay, result, m_pTerrainEnt, ClosestDistance);

	if( bColl == true )
		*CollDist	= ClosestDistance;
	else
		*CollDist	= 0;

	return bColl;
}
