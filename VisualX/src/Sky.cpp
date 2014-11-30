#include "StdAfx.h"
#include "Sky.h"


// ----------------------------------------------------------------------------
// SkyX-related ptrs
// ----------------------------------------------------------------------------
SkyX::SkyX* mSkyX = 0;
SkyX::BasicController* mBasicController = 0;

// ----------------------------------------------------------------------------
// Misc
// ----------------------------------------------------------------------------
Ogre::TextAreaOverlayElement* mTextArea = 0;
Ogre::uint32 mCurrentPreset = 0;
Ogre::Camera* mRenderingCamera = 0;


/** Demo presets
    @remarks The best way of determinate each parameter value is by using a real-time editor.
			 These presets have been quickly designed using the Paradise Editor, which is a commercial solution.
			 At the time I'm writting these lines, SkyX 0.1 is supported by Ogitor. Hope that the Ogitor team will 
			 support soon SkyX 0.4, this way you all are going to be able to quickly create cool SkyX configurations.
 */
SkyXSettings mPresets[] = {
	// Sunset
	SkyXSettings(Ogre::Vector3(8.85f, 7.5f, 20.5f),  -0.08f, 0, SkyX::AtmosphereManager::Options(9.77501f, 10.2963f, 0.01f, 0.0022f, 0.000675f, 30, Ogre::Vector3(0.57f, 0.52f, 0.44f), -0.991f, 3, 4), false, true, 300, false, Ogre::Radian(270), Ogre::Vector3(0.63f,0.63f,0.7f), Ogre::Vector4(0.35, 0.2, 0.92, 0.1), Ogre::Vector4(0.4, 0.7, 0, 0), Ogre::Vector2(0.8,1)),
	// Clear
	SkyXSettings(Ogre::Vector3(17.16f, 7.5f, 20.5f), 0, 0, SkyX::AtmosphereManager::Options(9.77501f, 10.2963f, 0.01f, 0.0017f, 0.000675f, 30, Ogre::Vector3(0.57f, 0.54f, 0.44f), -0.991f, 2.5f, 4), false),
	// Thunderstorm 1
	SkyXSettings(Ogre::Vector3(12.23, 7.5f, 20.5f),  0, 0, SkyX::AtmosphereManager::Options(9.77501f, 10.2963f, 0.01f, 0.00545f, 0.000375f, 30, Ogre::Vector3(0.55f, 0.54f, 0.52f), -0.991f, 1, 4), false, true, 300, false, Ogre::Radian(0), Ogre::Vector3(0.63f,0.63f,0.7f), Ogre::Vector4(0.25, 0.4, 0.5, 0.1), Ogre::Vector4(0.45, 0.3, 0.6, 0.1), Ogre::Vector2(1,1), true, 0.5, Ogre::Vector3(1,0.976,0.92), 2),
	// Thunderstorm 2
	SkyXSettings(Ogre::Vector3(10.23, 7.5f, 20.5f),  0, 0, SkyX::AtmosphereManager::Options(9.77501f, 10.2963f, 0.01f, 0.00545f, 0.000375f, 30, Ogre::Vector3(0.55f, 0.54f, 0.52f), -0.991f, 0.5, 4), false, true, 300, false, Ogre::Radian(0), Ogre::Vector3(0.63f,0.63f,0.7f), Ogre::Vector4(0, 0.02, 0.34, 0.24), Ogre::Vector4(0.29, 0.3, 0.6, 1), Ogre::Vector2(1,1), true, 0.5, Ogre::Vector3(0.95,1,1), 2),
	// Desert
	SkyXSettings(Ogre::Vector3(7.59f, 7.5f, 20.5f), 0, -0.8f, SkyX::AtmosphereManager::Options(9.77501f, 10.2963f, 0.01f, 0.0072f, 0.000925f, 30, Ogre::Vector3(0.71f, 0.59f, 0.53f), -0.997f, 2.5f, 1), true),
	// Night
	SkyXSettings(Ogre::Vector3(21.5f, 7.5, 20.5), 0.03, -0.25, SkyX::AtmosphereManager::Options(), true)
};

void setPreset(const SkyXSettings& preset)
{
	assert(mSkyX != NULL);

	// prevent flow of time
#if	1
	// demo mode
	mSkyX->setTimeMultiplier(preset.timeMultiplier);
#else
	mSkyX->setTimeMultiplier(0/*preset.timeMultiplier*/);
#endif
	mBasicController->setTime(preset.time);
	mBasicController->setMoonPhase(preset.moonPhase);
	mSkyX->getAtmosphereManager()->setOptions(preset.atmosphereOpt);

	// Layered clouds
	if (preset.layeredClouds)
	{
		// Create layer cloud
		if (mSkyX->getCloudsManager()->getCloudLayers().empty())
		{
			mSkyX->getCloudsManager()->add(SkyX::CloudLayer::Options(/* Default options */));
		}
	}
	else
	{
		// Remove layer cloud
		if (!mSkyX->getCloudsManager()->getCloudLayers().empty())
		{
			mSkyX->getCloudsManager()->removeAll();
		}
	}

	mSkyX->getVCloudsManager()->setWindSpeed(preset.vcWindSpeed);
	mSkyX->getVCloudsManager()->setAutoupdate(preset.vcAutoupdate);

	SkyX::VClouds::VClouds* vclouds = mSkyX->getVCloudsManager()->getVClouds();

	vclouds->setWindDirection(preset.vcWindDir);
	vclouds->setAmbientColor(preset.vcAmbientColor);
	vclouds->setLightResponse(preset.vcLightResponse);
	vclouds->setAmbientFactors(preset.vcAmbientFactors);
	vclouds->setWheater(preset.vcWheater.x, preset.vcWheater.y, false);

	if (preset.volumetricClouds)
	{
		// Create VClouds
		if (!mSkyX->getVCloudsManager()->isCreated())
		{
			// SkyX::MeshManager::getSkydomeRadius(...) works for both finite and infinite(=0) camera far clip distances
			mSkyX->getVCloudsManager()->create(mSkyX->getMeshManager()->getSkydomeRadius(mRenderingCamera));
		}
	}
	else
	{
		// Remove VClouds
		if (mSkyX->getVCloudsManager()->isCreated())
		{
			mSkyX->getVCloudsManager()->remove();
		}
	}

	vclouds->getLightningManager()->setEnabled(preset.vcLightnings);
	vclouds->getLightningManager()->setAverageLightningApparitionTime(preset.vcLightningsAT);
	vclouds->getLightningManager()->setLightningColor(preset.vcLightningsColor);
	vclouds->getLightningManager()->setLightningTimeMultiplier(preset.vcLightningsTM);

	// Reset camera position/orientation
	//mRenderingCamera->setPosition(0,0,0);
	//mRenderingCamera->setDirection(0,0,1);

	mSkyX->update(0);
}

CSky::CSky(Ogre::SceneManager* pSceneMgr) :
	mSceneMgr(pSceneMgr)
{
}


CSky::~CSky(void)
{
}

/**
* create sky entity
*/
void CSky::createScene()
{
	// Create SkyX
	mBasicController = new SkyX::BasicController();
	mSkyX = new SkyX::SkyX(mSceneMgr, mBasicController);
	mSkyX->create();

	// Distance geometry falling is a feature introduced in SkyX 0.2
	// When distance falling is enabled, the geometry linearly falls with the distance and the
	// amount of falling in world units is determinated by the distance between the cloud field "plane"
	// and the camera height multiplied by the falling factor.
	// For this demo, a falling factor of two is good enough for the point of view we're using. That means that if the camera
	// is at a distance of 100 world units from the cloud field, the fartest geometry will fall 2*100 = 200 world units.
	// This way the cloud field covers a big part of the sky even if the camera is in at a very low altitude.
	// The second parameter is the max amount of falling distance in world units. That's needed when for example, you've an 
	// ocean and you don't want to have the volumetric cloud field geometry falling into the water when the camera is underwater.
	// -1 means that there's not falling limit.
	mSkyX->getVCloudsManager()->getVClouds()->setDistanceFallingParams(Ogre::Vector2(2,-1));


	setPreset(mPresets[mCurrentPreset]);
 
}