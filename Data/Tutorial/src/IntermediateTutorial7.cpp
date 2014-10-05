#include "StdAfx.h"

#include "..\include\IntermediateTutorial7.h"


IntermediateTutorial7::IntermediateTutorial7(void)
{
}


IntermediateTutorial7::~IntermediateTutorial7(void)
{
}

void IntermediateTutorial7::createScene(void)
{
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.2f, 0.2f, 0.2f));
 
	Ogre::Light* light = mSceneMgr->createLight("MainLight");
	light->setPosition(20, 80, 50);
 
	mCamera->setPosition(60, 200, 70);
	mCamera->lookAt(0,0,0);
 
	Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().create("PlaneMat", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	Ogre::TextureUnitState* tuisTexture = mat->getTechnique(0)->getPass(0)->createTextureUnitState("grass_1024.jpg");
 
	mPlane = new Ogre::MovablePlane("Plane");
	mPlane->d = 0;
	mPlane->normal = Ogre::Vector3::UNIT_Y;
 
	Ogre::MeshManager::getSingleton().createPlane("PlaneMesh", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, *mPlane, 120, 120, 1, 1, true, 1, 1, 1, Ogre::Vector3::UNIT_Z);
	mPlaneEnt = mSceneMgr->createEntity("PlaneEntity", "PlaneMesh");
	mPlaneEnt->setMaterialName("PlaneMat");
 
	mPlaneNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	mPlaneNode->attachObject(mPlaneEnt);

	///////////////////////////////////////////////////////////////////////////
	// for mini map
	///////////////////////////////////////////////////////////////////////////

	// create a texture
	Ogre::TexturePtr rtt_texture = Ogre::TextureManager::getSingleton().createManual("RttTex", 
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, Ogre::TEX_TYPE_2D, 
		mWindow->getWidth(), mWindow->getHeight(), 
		0, Ogre::PF_R8G8B8, // for alpha channel use PF_R8G8B8A8 
		Ogre::TU_RENDERTARGET);

	// set some parameters
	Ogre::RenderTexture *renderTexture = rtt_texture->getBuffer()->getRenderTarget();

	renderTexture->addViewport(mCamera);
	renderTexture->getViewport(0)->setClearEveryFrame(true);
	renderTexture->getViewport(0)->setBackgroundColour(Ogre::ColourValue::Black);
	renderTexture->getViewport(0)->setOverlaysEnabled(false);

	// update texture before save this texture to file
	renderTexture->update();

	// Now save the contents
	renderTexture->writeContentsToFile("start.png");


	// Don't add this code!
	//renderTexture->setAutoUpdated(true);

	// create mini screen
	mMiniScreen = new Ogre::Rectangle2D(true);
	mMiniScreen->setCorners(0.5f, -0.5f, 1.0f, -1.0f);
	mMiniScreen->setBoundingBox(Ogre::AxisAlignedBox::BOX_INFINITE);

	Ogre::SceneNode* miniScreenNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("MiniScreenNode");
	miniScreenNode->attachObject(mMiniScreen);

	// create material named "RttMat"
	Ogre::MaterialPtr renderMaterial = Ogre::MaterialManager::getSingleton().create("RttMat", 
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	renderMaterial->getTechnique(0)->getPass(0)->setLightingEnabled(false);
	renderMaterial->getTechnique(0)->getPass(0)->createTextureUnitState("RttTex");


	// other texture test
	// use cg shader named "Sepia" material
	Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().getByName("Sepia");
	material->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName("RttTex");

	mMiniScreen->setMaterial("Sepia"/*"RttMat"*/);

	// this API enable preRenderTargetUpdate & postRenderTargetUpdate
	// so duplicated minimap is disappeared.
	renderTexture->addListener(this);
}

void IntermediateTutorial7::createFrameListener(void)
{
	BaseApplication::createFrameListener();
 
	mTrayMgr->hideLogo();
}

bool IntermediateTutorial7::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
	mPlaneNode->yaw(Ogre::Radian(evt.timeSinceLastFrame));
	return BaseApplication::frameRenderingQueued(evt);
}

void IntermediateTutorial7::preRenderTargetUpdate(const Ogre::RenderTargetEvent& evt)
{
	mMiniScreen->setVisible(false);
}
 
void IntermediateTutorial7::postRenderTargetUpdate(const Ogre::RenderTargetEvent& evt)
{
	mMiniScreen->setVisible(true);
}

void IntermediateTutorial7::setupResources(void)
{
	// load base class's resources
	BaseApplication::setupResources();

	/** add my own resource location */
	Ogre::ResourceGroupManager::getSingleton().addResourceLocation("./resource",
		"FileSystem");

#ifdef	_DEBUG
	Ogre::ResourceGroupManager::getSingleton().addResourceLocation("./resource/IntermediateTutorial7",
		"FileSystem");
#endif

	// following call cause assertion fails.
	// BaseApplication::loadResources() function has following call.
//	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}