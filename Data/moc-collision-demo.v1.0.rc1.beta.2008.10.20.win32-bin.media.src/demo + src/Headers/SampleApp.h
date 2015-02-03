/* ===========================================================================
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
THE SOFTWARE.
=========================================================================== */
#pragma once
#ifndef SAMPLEAPP_H
#define SAMPLEAPP_H

#pragma warning (disable : 4530)

// include for the masks and Spawn struct, needed for ArtifexLoader
#include "CustomTypes.h"  

// includes needed to work with the Enhanced Terrain Manager
#include "ETTerrainManager.h"
#include "ETTerrainInfo.h"
#include "ETBrush.h"
#include "ETSplattingManager.h"
//

#include "Ogre.h"
#include "InputManager.h"

// include the overlay
#include "OgreStatOverlay.h"
class OgreStatOverlay;

// include the collisiontools
#include "CollisionTools.h"

// include the zoneloader
#include "ArtifexLoader.h"
class ArtifexLoader;
//

class SampleApp : public OIS::MouseListener, public OIS::KeyListener, public Ogre::WindowEventListener
{
public:	
	float mTimer1, mTimer2;

	// *** Artifex Setup ***
	ArtifexLoader* mArtifexLoader;
	// *********************
	
	// *** ETM Setup ***
	ET::TerrainManager* mTerrainMgr;
    ET::TerrainInfo* mTerrainInfo;
    ET::SplattingManager* mSplatMgr;
    // *****************

	// *** MOC Setup ***
	MOC::CollisionTools* mCollisionTools;
	bool mCollision;
	void pickEntity(const OIS::MouseEvent &arg, const uint32 queryMask = 0xFFFFFFFF);
	// *****************
	
	// *** Stat & Info Overlay ***
	OgreStatOverlay *mInfoOverlay;
	// ***************************
    
	// *** Basic Ogre Setup ***
	Ogre::Root* mRoot;
	Ogre::RenderWindow* mRenderWin;
	Ogre::SceneManager* mSceneMgr;
	
	InputManager* mInputMgr;
	Ogre::SceneNode* mCamNode;
	Ogre::Camera* mCamera; 
		
	unsigned long mLastTime;
	Ogre::Timer mTimer;
	
	void parseResources();
	
	void setupEmptyScene();
		
	void loadInputSystem();	

	bool mShouldQuit;
	
	bool mLMouseDown, mMMouseDown, mRMouseDown;
	
	float mRotateSpeed, mMoveSpeed, mRotation, mPitch;
	
	Ogre::Vector3 mDirection;
	
	SampleApp();
	~SampleApp();

	void Startup();
	void Update();
	void Shutdown();	

	bool mouseMoved(const OIS::MouseEvent &arg);
	bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

	bool keyPressed( const OIS::KeyEvent &arg );
	bool keyReleased( const OIS::KeyEvent &arg );	

	void windowMoved(Ogre::RenderWindow* rw);
	void windowResized(Ogre::RenderWindow* rw);
	void windowClosed(Ogre::RenderWindow* rw);
	void windowFocusChange(Ogre::RenderWindow* rw);
	// *** End Basic Ogre Setup *** //	
};
#endif