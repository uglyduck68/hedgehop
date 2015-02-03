/* ===========================================================================
Artifex Loader v0.80.2 beta

Freeware

Copyright (c) 2008 MouseVolcano (Thomas Gradl, Esa Kylli, Erik Biermann, Karolina Sefyrin)

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
THE SOFTWARE.
=========================================================================== */
#pragma once
#ifndef ARTIFEXLOADER_H
#define ARTIFEXLOADER_H

#pragma warning (disable : 4530)

#include <cstdlib>
#include <iostream>

#include "Ogre.h"
#include "SampleApp.h"

// includes needed to work with the Enhanced Terrain Manager
#include "ETTerrainManager.h"
#include "ETTerrainInfo.h"
#include "ETBrush.h"
#include "ETSplattingManager.h"
//

#define ETM_GROUP "ETM" // the resourcegroup for the zone

using namespace std;
using namespace Ogre;

class SampleApp;

class ArtifexLoader {
public:
	ArtifexLoader(SampleApp *sampleapp, string zonepath="");
	~ArtifexLoader();
	
	float mFogR;
	float mFogG;
	float mFogB;
	float mFogDensity;
	float mFogStart;
	float mFogEnd;	

	float mCamX;
	float mCamY;
	float mCamZ;
	
	// *** terrainDimensions
	int mTerrX, mTerrZ, mTerrY;

	void initETM();
	void createColourLayer();
	void loadWater();
	void loadSkye();
	
	int mWaterVisible; 
	int mWaterXPos;
	int mWaterYPos; 
	int mWaterZPos; 
	int mWaterWidth; 
	int mWaterLength; 
	String mWaterMaterial;	
	
	SceneNode* mWaterNode;

	SampleApp *mSampleApp;

	ET::TerrainManager* mTerrainMgr;
    ET::TerrainInfo* mTerrainInfo;
    ET::SplattingManager* mSplatMgr;
   
	Root* mRoot;
	SceneManager* mSceneMgr;
	
	SceneNode* mCamNode;
	Camera* mCamera;

	string mZonePath;
	string mZoneName;
	
	Image* mOverlay;
	TexturePtr mOverlayTex;	
	
	Image* mSplatting[9];
	String mTexturePath[9];
	TexturePtr mSplattingTex[9];
	void setupTextures();
	int mTextureSize;
	int mCoverMapSize;	
	
	bool mLightmap;
	float mLightmapShadow;
	
	string mSkyBoxName;
	float mSkyRadius;
	
	bool mLoadGrass;
	
	bool mLoadStatics;
	bool mLoadMovables;
	bool mLoadMobiles;
	bool mLoadGroundcover;

	vector <Spawn> mStaticsFile;
	vector <Spawn> mMovablesFile;
	vector <Spawn> mMobilesFile;
	vector <Spawn> mGroundcoversFile;
	
	void updateLightmap();
	
	float getMeshYAdjust(Ogre::String meshfile);
	
	void spawnLoader(String which);
	void staticsLoader(String which, float renderDistance);
	
	void loadTerrain(std::string zone="");	
	void loadFog(std::string zone="");	


	bool loadZone(std::string zonename, bool use_cfg_settings=true, bool fog=true, bool water=true, bool skye=true, bool statics=true, bool groundcover=true, bool movables=true, bool mobiles=true);
	void unloadZone(std::string zonename);

	void loadZoneCFG(std::string zonename="");	
};
#endif