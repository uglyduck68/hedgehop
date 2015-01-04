/**
 * @file		Terrain.cpp
 * @remarks		implement terrain
 */

#include "StdAfx.h"

#include "Terrain.h"


CTerrain::CTerrain(Ogre::SceneManager* pSceneMgr, Ogre::Camera* pCamera) :
	mSceneMgr(pSceneMgr), mCamera(pCamera), mTerrainGlobals(NULL), mTerrainGroup(NULL),
	mTerrainsImported(false),
	m_pCollisionTools(NULL)
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
	//oskim, initBlendMaps() �������� �ʾƾ� �Ʒ� �ڵ尡 �����
	defaultimp.layerList.resize(1);
	defaultimp.layerList[0].worldSize = 96000.0f;
	defaultimp.layerList[0].textureNames.push_back("Colombia.jpg");

}
//-------------------------------------------------------------------------------------
void CTerrain::createScene(void)
{
#if	0
	m_pTerrainEnt = mSceneMgr->createEntity("Terrain", "ColMESH3.mesh");
//	m_pTerrainEnt->setMaterialName("ColMESH");
	mSceneMgr->getRootSceneNode()->createChildSceneNode("TerrainNode")->attachObject(m_pTerrainEnt);

	// scale up the terrain
	mSceneMgr->getSceneNode("TerrainNode")->setScale(500, 200, 500);
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