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
#include "ArtifexLoader.h"

using namespace std;
using namespace Ogre;

ArtifexLoader::ArtifexLoader(SampleApp *sampleapp, string zonepath) 
{
	mSampleApp = sampleapp;
	mZonePath = zonepath;
	
	mTerrainMgr = mSampleApp->mTerrainMgr;
    mTerrainInfo = mSampleApp->mTerrainInfo;
    mSplatMgr = mSampleApp->mSplatMgr;
   
	mRoot = mSampleApp->mRoot;
	mSceneMgr = mSampleApp->mSceneMgr;
	
	mCamNode = mSampleApp->mCamNode;
	mCamera = mSampleApp->mCamera;
	
	ResourceGroupManager::getSingleton().createResourceGroup(ETM_GROUP);	
};

ArtifexLoader::~ArtifexLoader() 
{

};

bool ArtifexLoader::loadZone(string zonename, bool use_cfg_settings, bool fog, bool water, bool skye, bool statics, bool groundcover, bool movables, bool mobiles) 
{
	mZoneName = zonename;
	
	cout << "\n|= ArtifexTerra3D =| Zoneloader 0.80: adding " << zonename.c_str() << " to resources.\n\n ";
	ResourceGroupManager::getSingleton().addResourceLocation(mZonePath+zonename,"FileSystem",ETM_GROUP);
	ResourceGroupManager::getSingleton().initialiseResourceGroup(ETM_GROUP);
	
	loadZoneCFG(mZoneName);
	
	if (skye) loadSkye();
	if (fog) loadFog();
	
	initETM();		
	
	createColourLayer();	
	setupTextures();
	loadTerrain(mZoneName);
		
	if (!use_cfg_settings) {	
		if (water) loadWater();	
		if (groundcover) staticsLoader("groundcover",50);
		if (mobiles) spawnLoader("mobile");
		if (movables) spawnLoader("movable");
		if (statics)  staticsLoader("static",1500);				
	} else {	
		if (mWaterVisible==1) loadWater();	
		if (mLoadGroundcover==1) spawnLoader("groundcover");//staticsLoader("groundcover",50);
		if (mLoadMobiles==1) spawnLoader("mobile");
		if (mLoadMovables==1) spawnLoader("movable");
		if (mLoadStatics==1) spawnLoader("static"); //staticsLoader("static",1500);		
	}
	
	mCamNode->setPosition(mCamX,mCamY,mCamZ);			   
	mCamera->pitch( Degree(-5) );
	mCamera->yaw( Degree(75) );
	return true;	
};

void ArtifexLoader::loadSkye() 
{
	mSceneMgr->setSkyBox(true, mSkyBoxName , mSkyRadius);	
};

void ArtifexLoader::updateLightmap()
{
	Image lightmap;
	ET::createTerrainLightmap(*mTerrainInfo, lightmap, 128, 128, Vector3(1, -1, 1), ColourValue(1,1,1),
		ColourValue(0.7, 0.7,  0.7), true);     

	TexturePtr tex = TextureManager::getSingleton().getByName("ETLightmap");
	tex->getBuffer(0, 0)->blitFromMemory(lightmap.getPixelBox(0, 0));
};

float ArtifexLoader::getMeshYAdjust(Ogre::String meshfile)
{
	Ogre::ConfigFile mCFile;
	float realY = 0;
	try {
		mCFile.load("y_correction_tables.cfg");	
		realY = Ogre::StringConverter::parseReal(mCFile.getSetting(meshfile));	
	} catch (...){
		cout << "\n|= ArtifexTerra3D =| Zoneloader 0.80: getMeshYAdjust - An error occured getting the setting for " << meshfile.c_str() << ".\n";
	};
	return realY;
};

void ArtifexLoader::spawnLoader(string which)
{
	string meshName="", meshFile="", xPos="", yPos="", zPos="", rot="", tmp="", 
		typeName="", entName="", scale="", rotX="", rotZ="";

	int counter=1;
	bool fileend = false;
	
	string filename = mZonePath+mZoneName+"/spawns_" + which + ".cfg";

	std::ifstream fp;

	fp.open(filename.c_str(), std::ios::in | std::ios::binary);
	if(!fp) return; 

	DataStreamPtr stream(new FileStreamDataStream(filename, &fp, false));

	string line;

	do
	{		
		for (int a=0;a<=10;a++) 
		{	
			line = stream->getLine();
			if(stream->eof()) {
				fileend = true;
				break;
			}
			tmp = line;
			line = "";
			StringUtil::trim(tmp);

			if (StringUtil::startsWith(tmp,"//",false) || tmp.empty())
			{
				a--;
				continue;
			}
			else {
				switch (a)
				{
					case 0:
						meshName = tmp;
						break;
					case 1:
						// bracket
						break;
					case 2:
						meshFile = tmp;
						break;
					case 3:
						xPos = tmp;
						break;
					case 4:
						yPos = tmp;
						break;
					case 5:
						zPos = tmp;
						break;
					case 6:
						rot = tmp;
						break;
					case 7:
						scale = tmp;
						break;
					case 8:
						rotX = tmp;
						break;
					case 9:
						rotZ = tmp;
						break;
					case 10:
						// bracket close
						break;
					default:
						break;
				}
				tmp = "";
			}
		}
		if (fileend) break;
		{
			//***************************					
			entName = meshName; 
			//***************************
			Entity *newModel = NULL;
			lCreateEntity:
			try {
				newModel = mSampleApp->mSceneMgr->createEntity((string) entName, (string) meshFile);
			} catch(Exception &e) {
				if (e.getNumber() != 4) {
					cout << "\n|= ArtifexTerra3D =| Zoneloader 0.80: Error " << e.getNumber() << " creating Entity " << entName.c_str() << ": " << e.getFullDescription().c_str() << "\n";
				} else if (e.getNumber() == 4) {
					cout << "\n|= ArtifexTerra3D =| Zoneloader 0.80: Entity with the name " << entName.c_str() << " already exists, creating a random name:";
					entName = "Entity"+StringConverter::toString((int)Math::RangeRandom(100000,999999));
					cout << entName.c_str() << ".\n";
					goto lCreateEntity;
				}
				break;
			};					
			newModel->setQueryFlags(ENTITY_MASK);
			//****************************
			float x=0,y=0,z=0,r=0,s=0,rx=0,rz=0;
			x = StringConverter::parseReal(xPos);					
			y = StringConverter::parseReal(yPos);
			z = StringConverter::parseReal(zPos);
			
			r = StringConverter::parseReal(rot);
			s = StringConverter::parseReal(scale);
			rx = StringConverter::parseReal(rotX);
			rz = StringConverter::parseReal(rotZ);
			// auto drop models on terrain
			if (y==0) {		
				float tmpY = getMeshYAdjust(meshFile)* s;
				y = (float) mSampleApp->mTerrainInfo->getHeightAt(x,z)+tmpY;
			}

			Spawn spawn;

			spawn.name = entName;
			spawn.meshfile = meshFile;
			spawn.x = x;
			spawn.y = y;
			spawn.z = z;
			spawn.ry = r;
			spawn.scale = s;
			spawn.rx = rx;
			spawn.rz = rz;

			if (which == "static")
				mStaticsFile.push_back(spawn);
			else if (which == "movable")
				mMovablesFile.push_back(spawn);
			else if (which == "mobile")
				mMobilesFile.push_back(spawn);
			else if (which == "groundcover")
				mGroundcoversFile.push_back(spawn);

			//****************************					
			{
				SceneNode *mNode = NULL;
				try {
					mNode = mSampleApp->mSceneMgr->getRootSceneNode()->createChildSceneNode(entName+"Node",Ogre::Vector3(x,y,z),Quaternion ((Degree(r)), Vector3::UNIT_Y));
					mNode->attachObject(newModel);
					mNode->setScale(s,s,s);						
					mNode->setOrientation(Quaternion ((Degree(rx)), Vector3::UNIT_X)*Quaternion ((Degree(r)), Vector3::UNIT_Y)*Quaternion ((Degree(rz)), Vector3::UNIT_Z));
				} catch (Exception &e) {
					cout << "\n|= ArtifexTerra3D =| Zoneloader 0.80: spawnloader error - problems reading " << filename.c_str()  << ":" << e.what() << "\n";
				};
			}
			//***************************			
		}				
		counter ++;
	} while (!stream->eof() && !StringUtil::startsWith(tmp,"[END]",false));			

}

void ArtifexLoader::staticsLoader(Ogre::String which, float renderDistance)
{
	Ogre::String meshName="", meshFile="", xPos="", yPos="", zPos="", rot="", tmp="", 
		typeName="", entName="", scale="", rotX="", rotZ="";

	int counter=1;

	if (which.empty()) typeName = "static";
	else typeName = which;

	StaticGeometry *staticGeometry;
	staticGeometry = mSceneMgr->createStaticGeometry((string)mZoneName+typeName);
	staticGeometry->setRenderingDistance(renderDistance); 
	
	Ogre::String filename = mZonePath+mZoneName+"/spawns_" + typeName + ".cfg";

	std::ifstream fp;

	fp.open(filename.c_str(), std::ios::in | std::ios::binary);
	if(!fp) return; 

	DataStreamPtr stream(new FileStreamDataStream(filename, &fp, false));

	Ogre::String line;
	
	do {   		
		for (int a=0;a<=10;a++) 
		{	
			line = stream->getLine();
			if(stream->eof()) break;
			tmp = line;
			line = "";
			Ogre::StringUtil::trim(tmp);

			if (Ogre::StringUtil::startsWith(tmp,"//",false) || tmp.empty())
			{
				a--;
				continue;
			}
			else {
				switch (a)
				{
					case 0:
						meshName = tmp;
						break;
					case 1:
						// bracket
						break;
					case 2:
						meshFile = tmp;
						break;
					case 3:
						xPos = tmp;
						break;
					case 4:
						yPos = tmp;
						break;
					case 5:
						zPos = tmp;
						break;
					case 6:
						rot = tmp;
						break;
					case 7:
						scale = tmp;
						break;
					case 8:
						rotX = tmp;
						break;
					case 9:
						rotZ = tmp;
						break;
					case 10:
						// bracket close
						break;
					default:
						break;
				}
				tmp = "";
			}
		}
		try {
			//***************************					
			entName = meshName;
			//***************************
			Entity *newModel = mSceneMgr->createEntity((string) entName, (string) meshFile);
			newModel->setQueryFlags(ENTITY_MASK);
			//****************************
			float x=0,y=0,z=0,r=0,s=0,rx=0,rz=0;
			x = Ogre::StringConverter::parseReal(xPos);					
			y = Ogre::StringConverter::parseReal(yPos);
			z = Ogre::StringConverter::parseReal(zPos);
			r = Ogre::StringConverter::parseReal(rot);
			s = Ogre::StringConverter::parseReal(scale);
			rx = Ogre::StringConverter::parseReal(rotX);
			rz = Ogre::StringConverter::parseReal(rotZ);

			// auto drop models on terrain
			if (y==0) {		
				float tmpY = getMeshYAdjust(meshFile)* s;
				y = (float) mTerrainInfo->getHeightAt(x,z)+tmpY;
			}

			//****************************					
			staticGeometry->addEntity(newModel,Ogre::Vector3(x,y,z),Quaternion ((Degree(r)), Vector3::UNIT_Y), Vector3(s,s,s));   
			mSceneMgr->destroyEntity(newModel);
			//***************************			
		} catch (Exception &e){ 
			cout << "\n|= ArtifexTerra3D =| Zoneloader 0.80: staticsloader error - problems reading " << filename.c_str() << ":" << e.what() << "\n";		
		};
		
		counter ++;
	} while (!stream->eof() && !StringUtil::startsWith(tmp,"[END]",false));
				
	staticGeometry->build();
}

void ArtifexLoader::loadTerrain(std::string zone)
{
	try {
		mTerrainMgr->destroyTerrain();
	} catch (Exception &e) {};
	Image image;
	image.load(mZonePath+zone+"/ETterrain.png", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

	ET::TerrainInfo info;
	ET::loadHeightmapFromImage(info, image);
	info.setExtents(AxisAlignedBox(0, 0, 0, mTerrX, mTerrY, mTerrZ));
	mTerrainMgr->createTerrain(info);
	mTerrainInfo = const_cast<ET::TerrainInfo*> (&mTerrainMgr->getTerrainInfo());

	// now load the splatting maps
	
	for (uint i = 0; i < mSplatMgr->getNumMaps(); ++i)
	{
		image.load(mZonePath+zone+"/ETcoverage."+StringConverter::toString(i)+".png",ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
		mSplatMgr->loadMapFromImage(i, image);
	}
	
	MaterialPtr material (MaterialManager::getSingleton().getByName("ETTerrainMaterial"));
	mTerrainMgr->setMaterial(material);
	
	updateLightmap();
	
	mSampleApp->mTerrainMgr = mTerrainMgr;
    mSampleApp->mTerrainInfo = mTerrainInfo;    
}

void ArtifexLoader::loadFog(std::string zone)
{
	try {
		ConfigFile fogfile;
		fogfile.load(mZonePath+mZoneName+"/zonesettings.cfg");
		
		mFogR = StringConverter::parseReal(fogfile.getSetting("FogR"));
		mFogG = StringConverter::parseReal(fogfile.getSetting("FogG"));
		mFogB = StringConverter::parseReal(fogfile.getSetting("FogB"));

		mFogDensity = StringConverter::parseReal(fogfile.getSetting("FogDensity"));
		mFogStart = StringConverter::parseReal(fogfile.getSetting("FogStart"));
		mFogEnd = StringConverter::parseReal(fogfile.getSetting("FogEnd"));
		
		ColourValue fadeColour(mFogR, mFogG, mFogB);
		mSceneMgr->setFog(Ogre::FOG_LINEAR, fadeColour, mFogDensity, mFogStart,mFogEnd);
		
	} catch (Exception &e) {
		cout << "\n|= ArtifexTerra3D =| Zoneloader 0.80: Error loading fog - "<< e.what() <<"\n";
	}	
}

void ArtifexLoader::unloadZone(string zonename)
{

	try {
		StaticGeometry* staticGeometry = mSceneMgr->getStaticGeometry((string)mZoneName+"static");
		staticGeometry->destroy();
		mSceneMgr->destroyStaticGeometry(staticGeometry);
	} catch (...) {};	
	
	try {
		StaticGeometry* staticGeometry = mSceneMgr->getStaticGeometry((string)mZoneName+"groundcover");
		staticGeometry->destroy();
		mSceneMgr->destroyStaticGeometry(staticGeometry);
	} catch (...) {};	
	
	string spawntype = "";
	vector <Spawn> *tmpSpawns;	

	SceneNode *tmpNode = NULL;
	for (int a=1;a<5;a++) 
	{
		switch (a) {
			case ST_STATIC:	
				continue;				
			case ST_MOVABLE:
				spawntype = "movable";
				tmpSpawns = &mMovablesFile;
				break;
			case ST_MOBILE:
				spawntype = "mobile";
				tmpSpawns = &mMobilesFile;
				break;
			case ST_GROUNDCOVER:
				continue;		
		}

		vector<Spawn>::iterator tmpIter;
		
		for (tmpIter = tmpSpawns->begin(); tmpIter != tmpSpawns->end(); ++tmpIter) 
		{
			Spawn ts = *tmpIter;
			
			try {
				tmpNode = mSceneMgr->getSceneNode(ts.name+"Node");
				cout <<"Found "<< ts.name.c_str() <<". \n";
			} catch (Exception &e) { 
				cout << "\n|= ArtifexTerra3D =| Zoneloader 0.80: Error - " << e.getDescription().c_str() << "\n";
			};
			
			if (tmpNode != NULL) {
				try {					
					tmpNode->detachAllObjects();					
					mSceneMgr->destroySceneNode(tmpNode->getName());
					mSceneMgr->destroyEntity(ts.name);
				} catch(...) {
				};
			}
			tmpNode = NULL;			
		}
		tmpSpawns->clear();
	}
	
	try {
		mTerrainMgr->destroyTerrain();
	} catch (Exception &e) {};	
	
	try {
		mWaterNode->detachAllObjects();		
		mSceneMgr->destroySceneNode("WaterNode");
		mSceneMgr->destroyEntity("water");
	} catch (Exception &e) {};
	
	try {
		mSceneMgr->setSkyBox(false, mSkyBoxName);
	} catch (Exception &e) {};
	
	ResourceGroupManager::getSingleton().destroyResourceGroup(ETM_GROUP);
};

void ArtifexLoader::loadZoneCFG(string zonename) 
{
	Ogre::ConfigFile setupfile;	
	
	try {	
		setupfile.load(mZonePath+zonename+"/zonesettings.cfg");	
		mTerrX = atoi(setupfile.getSetting("TerrainWidth_X").c_str());
		mTerrZ = atoi(setupfile.getSetting("TerrainWidth_Z").c_str());
		mTerrY = atoi(setupfile.getSetting("TerrainHeight_Y").c_str());	

		mCamX = atoi(setupfile.getSetting("Camera_X").c_str());
		mCamZ = atoi(setupfile.getSetting("Camera_Z").c_str());
		mCamY = atoi(setupfile.getSetting("Camera_Y").c_str());		
		
		mSkyBoxName = setupfile.getSetting("Sky").c_str();
		mSkyRadius = atoi(setupfile.getSetting("SkyRadius").c_str());
		
		mWaterVisible = atoi(setupfile.getSetting("WaterVisible").c_str());
		
		mLoadGrass = atoi(setupfile.getSetting("LoadGrassMap").c_str())==1?true:false;
		
		mLoadStatics = atoi(setupfile.getSetting("LoadStatics").c_str())==1?true:false;
		mLoadMovables = atoi(setupfile.getSetting("LoadMovables").c_str())==1?true:false;
		mLoadMobiles = atoi(setupfile.getSetting("LoadMobiles").c_str())==1?true:false;
		mLoadGroundcover = atoi(setupfile.getSetting("LoadGroundcover").c_str())==1?true:false;
		
		for (int i=0; i<9; i++) {
			mTexturePath[i] = setupfile.getSetting("Splatting"+StringConverter::toString(i)).c_str();		
		}			
	} catch (Exception &e){
		cout << "\n|= ArtifexTerra3D =| Zoneloader 0.80: Error - An error occured reading zonesettings.cfg. " << e.getDescription().c_str() <<"\n";
	};
	
};

void ArtifexLoader::createColourLayer() 
{
	mOverlay = new Image();	
	try {	
		if (mZoneName!="") {
			mOverlay->load(mZonePath+mZoneName+"/artifexterra3d_colourmap.png",ETM_GROUP);	  
		}

		mOverlayTex = TextureManager::getSingleton().createManual(
		"ArtifexTerra3D_ColourMap", ETM_GROUP, Ogre::TEX_TYPE_2D, 2048, 2048, 1, mOverlay->getFormat());	

		mOverlayTex->unload();
		mOverlayTex->loadImage(*mOverlay); 	
	  
	}catch(Exception &e) { 
		std::cout <<"#-#-#-# Error loading colourlayer: "<< e.getDescription() <<"\n"; 	
	}	
};

void ArtifexLoader::loadWater()
{
	ConfigFile setupfile;
    setupfile.load(mZonePath+mZoneName+"/zonesettings.cfg");
	mWaterXPos = atoi(setupfile.getSetting("WaterXPos").c_str());
	mWaterYPos = atoi(setupfile.getSetting("WaterYPos").c_str());
	mWaterZPos = atoi(setupfile.getSetting("WaterZPos").c_str());
	mWaterWidth = atoi(setupfile.getSetting("WaterWidth_X").c_str());
	mWaterLength = atoi(setupfile.getSetting("WaterWidth_Z").c_str());
	mWaterMaterial = setupfile.getSetting("WaterMaterial");

	Entity *pWaterEntity;
	Plane nWaterPlane;

	nWaterPlane.normal = Vector3::UNIT_Y;

	MeshManager::getSingleton().createPlane(
		"WaterPlane",
		ETM_GROUP,
		nWaterPlane,
		mWaterWidth, mWaterLength,
		20, 20,
		true, 1,
		10, 10,
		Vector3::UNIT_Z);

	pWaterEntity = mSceneMgr->createEntity("water", "WaterPlane");
	pWaterEntity->setQueryFlags(WATER_MASK);
	pWaterEntity->setMaterialName(mWaterMaterial);

	mWaterNode =
		mSampleApp->mSceneMgr->getRootSceneNode()->createChildSceneNode("WaterNode");
	mWaterNode->attachObject(pWaterEntity);
	mWaterNode->setPosition(mWaterXPos, mWaterYPos, mWaterZPos);	
}

void ArtifexLoader::setupTextures() {
	String num = "";
	mTextureSize = 1024;
	
	for (int a=0;a<9;a++) {
		num = StringConverter::toString(a);
		mSplatting[a] = new Image();
		mSplatting[a]->load(mZonePath+mZoneName+"/"+mTexturePath[a],ETM_GROUP);

		// create a manual texture	  
		mSplattingTex[a] = TextureManager::getSingleton().createManual(
		"Splatting"+num, ETM_GROUP, Ogre::TEX_TYPE_2D, mTextureSize, mTextureSize, 1, mSplatting[a]->getFormat());	
		// load the imagefile 
		mSplattingTex[a]->loadImage(*mSplatting[a]);
	}
}

void ArtifexLoader::initETM() {	
	mTerrainMgr = new ET::TerrainManager(mSceneMgr);
	mTerrainMgr->setLODErrorMargin(2, mCamera->getViewport()->getActualHeight());
	mTerrainMgr->setUseLODMorphing(true, 0.2, "morphFactor");	

	ET::TerrainInfo terrainInfo (513, 513, vector<float>(513*513, 0.5f));
	terrainInfo.setExtents(AxisAlignedBox(0, 0, 0, mTerrX, mTerrY, mTerrZ));
	mTerrainMgr->createTerrain(terrainInfo);	
	
	mCoverMapSize = 1024;
	mSplatMgr = new ET::SplattingManager("ETSplatting", ETM_GROUP, mCoverMapSize, mCoverMapSize, 3);
	mSplatMgr->setNumTextures(9);

	TexturePtr lightmapTex = TextureManager::getSingleton().createManual(
	"ETLightmap", ETM_GROUP, TEX_TYPE_2D, 128, 128, 1, PF_BYTE_RGB); 
	Image lightmap;	
	
	ET::createTerrainLightmap(terrainInfo, lightmap, 128, 128, Vector3(1, -1, 1), ColourValue::White,
	ColourValue(0.7, 0.7, 0.7),true);
	lightmapTex->getBuffer(0, 0)->blitFromMemory(lightmap.getPixelBox(0, 0));
}
