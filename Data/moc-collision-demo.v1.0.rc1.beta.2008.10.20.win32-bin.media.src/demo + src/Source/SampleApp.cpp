/* ===========================================================================
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
THE SOFTWARE.
=========================================================================== */
#include "SampleApp.h"

using namespace Ogre;
using namespace MOC;
using namespace std;

SampleApp::SampleApp()
{
	mShouldQuit = false;
	mRenderWin = 0;
	mSceneMgr = 0;

	mLMouseDown = mMMouseDown = mRMouseDown = false;
	
	mRotateSpeed = 0.5f;	
	mMoveSpeed = 25;
	mDirection = Vector3::ZERO;
	mPitch = 0.0f;
	mRotation = 0.0f;
	
	mLastTime = mTimer.getMilliseconds();	
	
	mTimer1 = 0.0;
	mCollision = true;
};

SampleApp::~SampleApp()
{
	delete mCollisionTools;
	delete mArtifexLoader;
};

void SampleApp::Startup()
{
	mRoot = new Root("plugins.cfg", "ogre.cfg", "ogre.log");
	if (!mRoot->restoreConfig())
	{
		mShouldQuit = !mRoot->showConfigDialog();
		if(mShouldQuit) return;
	}

	mRoot->saveConfig();
	mRoot->initialise(true, "MOC Demo - Minimal Ogre Collision 1.0 beta");
	
	parseResources();
	
	mRenderWin = mRoot->getAutoCreatedWindow();

 	setupEmptyScene();

	loadInputSystem();

	Ogre::WindowEventUtilities::addWindowEventListener(mRenderWin, this);
	
	// init the info overlay
	mInfoOverlay = new OgreStatOverlay(mRenderWin);
	mInfoOverlay->showDebugOverlay(true);
	
	// init the loader with the path to your zones
	mArtifexLoader = new ArtifexLoader(this,"../media/");	
	// load a zone	
	mArtifexLoader->loadZone("testzone");

	// init the collision handler
	mCollisionTools = new CollisionTools(mSceneMgr, mArtifexLoader->mTerrainInfo);
	
	// set how far we want the camera to be above ground
	mCollisionTools->setHeightAdjust(4.5f);

	// place the camera node on the ground
	mCollisionTools->calculateY(mCamNode);
};

void SampleApp::Update() 
{
	
	Root::getSingleton().renderOneFrame();

	Ogre::WindowEventUtilities::messagePump();
	InputManager::getSingletonPtr()->capture();
	
	// take time since last loop to adapt movement to system speed
	const float timeFactor = ((float)(mTimer.getMilliseconds()-mLastTime)/1000);

	mTimer1 -= timeFactor;

	// commit the camera movement (if moving and not colliding with any entity)
	if (mDirection != Vector3::ZERO)
	{
		// save last position
		Vector3 oldPos = mCamNode->getPosition();
		
		// commit move
		mCamNode->translate(mCamera->getOrientation() * mDirection * (mMoveSpeed * timeFactor));
		
		// collision on?		
		if (mCollision) {
		
			// calculate the new Y position: check vs. terrain & all objects flagged with ENTITY_MASK
			// multiple masks possible like e.g. ENTITY_MASK|MY_MASK|ETC_MASK
			// doGridCheck casts a 2nd ray, gridWidth=2.0f ogre units away from the exact camera position to 
			// avoid falling through small wholes or gaps in hangbridges for example.
			mCollisionTools->calculateY(mCamNode,true,true,2.0f,ENTITY_MASK);
		
			// check if we are colliding with anything with a collision radius of 2.5 ogre units and we 
			// set the ray origin -1.0 lower towards the ground to get smaller obstacles too
			if (mCollisionTools->collidesWithEntity(oldPos, mCamNode->getPosition(), 2.5f, -1.0f, ENTITY_MASK))
			{
				// undo move
				mCamNode->setPosition(oldPos);
			}
		} else {
			// collision off -> get terrain height
			Vector3 pos = mCamNode->getPosition();
			float y =  mTerrainInfo->getHeightAt(pos.x,pos.z);
			mCamNode->setPosition(pos.x,y+4.5f,pos.z);
		}
	}

	// commit the camera rotation (if rotating)
	if (mRotation != 0.0f)
	{
		mCamera->yaw( Degree(mRotation * mRotateSpeed* 50 *timeFactor) );
		//mCamera->pitch( Degree(-mPitch * mRotateSpeed* 50 *timeFactor) );

		// normalise the camera orientation to avoid distortion of the perspective
		Quaternion q = mCamera->getOrientation();
		q.normalise();
		mCamera->setOrientation(q);
	}

	mInfoOverlay->updateStats();

	mLastTime = mTimer.getMilliseconds();		
    
};

void SampleApp::setupEmptyScene() {
	
	// choose SceneManager
	mSceneMgr = mRoot->createSceneManager(ST_GENERIC, "SampleAppSceneMgr");
	
	// set ilumination
	mSceneMgr->setAmbientLight(ColourValue(1, 1, 1));
	

	// setup mCamera and viewport
	mCamera = mSceneMgr->createCamera("MainCam");
	//mCamera->setPosition(500,500,500);
	
	Viewport* viewport = mRenderWin->addViewport(mCamera);
	viewport->setBackgroundColour(ColourValue(0.5, 0.5, 0.5));
	
	mCamera->setAspectRatio((float)viewport->getActualWidth() / (float) viewport->getActualHeight());
	
	mCamNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("camNode");
	mCamNode->attachObject(mCamera);
	mCamNode->setPosition(500,500,500);
	
	mCamera->setNearClipDistance( 0.2f );

	// create a lightsource
	Light* light = mSceneMgr->createLight( "Sun" );
	light->setType( Light::LT_DIRECTIONAL );
	light->setDiffuseColour( ColourValue( .82, .81, .7 ) );
	light->setSpecularColour( ColourValue( .82, .81, .7 ) );
	light->setDirection( Vector3( 0, -1, 1 ) ); 

};

void SampleApp::Shutdown()
{
	Root::getSingleton().shutdown();
};

void SampleApp::parseResources()
{
    ConfigFile cf;
	try 
	{
		cf.load("resources.cfg");
	} 
	catch( Exception& e ) 
	{
		MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
		return;
	}

    // Go through all sections & settings in the file
    ConfigFile::SectionIterator seci = cf.getSectionIterator();

    String secName, typeName, archName;
    while (seci.hasMoreElements())
    {
        secName = seci.peekNextKey();
        ConfigFile::SettingsMultiMap *settings = seci.getNext();
        ConfigFile::SettingsMultiMap::iterator i;
        for (i = settings->begin(); i != settings->end(); ++i)
        {
            typeName = i->first;
            archName = i->second;
            ResourceGroupManager::getSingleton().addResourceLocation(
                archName, typeName, secName);
        }
    }

	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
};

void SampleApp::loadInputSystem()
{
	mInputMgr = InputManager::getSingletonPtr();
    mInputMgr->initialise(mRenderWin);
    mInputMgr->addMouseListener(this, "SampleAppMouseListener");
	mInputMgr->addKeyListener(this, "SampleAppKeyListener");
};

void SampleApp::pickEntity(const OIS::MouseEvent &arg, const Ogre::uint32 queryMask)
{
	Entity *tmpE = NULL;
    Vector3 result = Vector3::ZERO;
	float distToColl;
    if (mCollisionTools->raycastFromCamera(mRenderWin, mCamera, arg, result, (ulong&)tmpE, distToColl, queryMask))
	{
		SceneNode* node = tmpE->getParentSceneNode();
		if (node->getShowBoundingBox()) {
			node->showBoundingBox(false);
		} else {
			node->showBoundingBox(true);
		}
	}
}

bool SampleApp::mouseMoved(const OIS::MouseEvent &arg)
{
	if ( mRMouseDown )
	{
		mCamera->yaw( Degree(-arg.state.X.rel * mRotateSpeed) );		   
		mCamera->pitch( Degree(-arg.state.Y.rel * mRotateSpeed) );
	} 

	return true;
};

bool SampleApp::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	if ( id == OIS::MB_Left )
	{
		mLMouseDown = true;
		pickEntity(arg, ENTITY_MASK);
	}
	else if ( id == OIS::MB_Middle )
	{
		mMMouseDown = true;
	}
	else if (id == OIS::MB_Right)
	{		
		mRMouseDown = true;		  
	}
	return true;
};

bool SampleApp::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	if ( id == OIS::MB_Left )
	{
		mLMouseDown = false;
	}
	else if ( id == OIS::MB_Middle )
	{
		mMMouseDown = false;
	}
	else if (id == OIS::MB_Right)
	{		
		mRMouseDown = false;		  
	}
	return true;
};

bool SampleApp::keyPressed( const OIS::KeyEvent &arg )
{
	switch(arg.key)
	{
		case OIS::KC_UP:
		case OIS::KC_W:
			mDirection.z -= 1;
			if(mDirection.z<-1) mDirection.z=-1;
			break;
		case OIS::KC_DOWN:
		case OIS::KC_S:
			mDirection.z += 1;
			if(mDirection.z>1) mDirection.z=1;
			break;
		case OIS::KC_LEFT:
		case OIS::KC_A:
			mRotation = 3.5f;
			break;		
		case OIS::KC_RIGHT:
		case OIS::KC_D:
			mRotation = -3.5f;
			break;
	}

	return true;
};

bool SampleApp::keyReleased( const OIS::KeyEvent &arg )
{
	if(arg.key == OIS::KC_ESCAPE)
		mShouldQuit = true;

	switch(arg.key)
	{		
		case OIS::KC_UP:
		case OIS::KC_W:
			mDirection.z = 0;
			break;		
		case OIS::KC_DOWN:
		case OIS::KC_S:
			mDirection.z = 0;
			break;		
		case OIS::KC_LEFT:
		case OIS::KC_A:
			mRotation = 0.0f;
			break;
		case OIS::KC_RIGHT:
		case OIS::KC_D:
			mRotation = 0.0f;
			break;
		case OIS::KC_C:
			if(mTimer1<=0.0f) {
				if(mCollision) {
					mCollision = false;
					mInfoOverlay->mCollision="OFF";
				} else {
					mCollision = true;
					mInfoOverlay->mCollision="ON";
				}
				mTimer1 = 0.2f;
			}
			break;
		case OIS::KC_F12:
			mRoot->getAutoCreatedWindow()->writeContentsToTimestampedFile("screenshots\\artifex_terra_", ".PNG");	
			break;			
	}

	return true;
};

void SampleApp::windowMoved(RenderWindow* rw) {};

void SampleApp::windowResized(RenderWindow* rw) 
{
	mInputMgr->setWindowExtents(rw->getWidth(), rw->getHeight());
};

void SampleApp::windowClosed(RenderWindow* rw) 
{
	mShouldQuit = true;
};

void SampleApp::windowFocusChange(RenderWindow* rw) {};

