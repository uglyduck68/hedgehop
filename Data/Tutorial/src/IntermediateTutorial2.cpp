//SdkTray-version
 
//Following includes are not needed since we are using SdkTrays
//#include <CEGUISystem.h>			
//#include <CEGUISchemeManager.h>	
//#include <RendererModules/Ogre/CEGUIOgreRenderer.h>		
 
#include "IntermediateTutorial2.h"
 
//-------------------------------------------------------------------------------------
ITutorial02::ITutorial02(void)
{
}
//-------------------------------------------------------------------------------------
ITutorial02::~ITutorial02(void)
{
	mSceneMgr->destroyQuery(mRaySceneQuery);
}
 
//-------------------------------------------------------------------------------------
void ITutorial02::createScene(void)
{
	// Set ambient light
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
	mSceneMgr->setSkyDome(true, "Examples/CloudySky", 5, 8);
 
	// World geometry
	mSceneMgr->setWorldGeometry("terrain.cfg");
 
	// Set camera look point
	mCamera->setPosition(40, 100, 580);
	mCamera->pitch(Ogre::Degree(-30));
	mCamera->yaw(Ogre::Degree(-45));
 
	// Following lines are not needed since we are using SdkTrays
	// CEGUI setup
	//mGUIRenderer = &CEGUI::OgreRenderer::bootstrapSystem();
	// Mouse
	//CEGUI::SchemeManager::getSingleton().create((CEGUI::utf8*)"TaharezLook.scheme");
	//CEGUI::MouseCursor::getSingleton().setImage("TaharezLook", "MouseArrow");
 
	//SdkTray - version:
	//Must come in createFrameListener, since the BaseApplication initializes the mTrayMgr there
 
}
void ITutorial02::createFrameListener(void)
{
	BaseApplication::createFrameListener();
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
void ITutorial02::chooseSceneManager(void)
{
	// Use the terrain scene manager.
	mSceneMgr = mRoot->createSceneManager(Ogre::ST_EXTERIOR_CLOSE);
}
 
bool ITutorial02::frameRenderingQueued(const Ogre::FrameEvent &evt)
{
	if (!BaseApplication::frameRenderingQueued(evt))
		return false;
 
	// Setup the scene query
	Ogre::Vector3 camPos = mCamera->getPosition();
	Ogre::Ray cameraRay(Ogre::Vector3(camPos.x, 5000.0f, camPos.z), Ogre::Vector3::NEGATIVE_UNIT_Y);
	mRaySceneQuery->setRay(cameraRay);
 
	// Perform the scene query
	Ogre::RaySceneQueryResult &result = mRaySceneQuery->execute();
	Ogre::RaySceneQueryResult::iterator itr = result.begin();
	// Get the results, set the camera height
	if (itr != result.end() && itr->worldFragment)
	{
		Ogre::Real terrainHeight = itr->worldFragment->singleIntersection.y;
		if ((terrainHeight + 10.0f) > camPos.y)
			mCamera->setPosition( camPos.x, terrainHeight + 10.0f, camPos.z );
	}
	return true;
}
bool ITutorial02::mouseMoved(const OIS::MouseEvent &arg)
{
	// Update SdkTrays with the mouse motion
	mTrayMgr->injectMouseMove(arg);
 
	//Not needed, since we are using SdkTrays
	// Update CEGUI with the mouse motion
	//CEGUI::System::getSingleton().injectMouseMove(arg.state.X.rel, arg.state.Y.rel);
 
	// If we are dragging the left mouse button.
	if (mLMouseDown)
	{
		//Not needed, since we are using SdkTrays
		//CEGUI::Point mousePos = CEGUI::MouseCursor::getSingleton().getPosition();
		//mCamera->getCameraToViewportRay(mousePos.d_x/float(arg.state.width),mousePos.d_y/float(arg.state.height));
 
		//SdkTray - version:
		Ogre::Ray mouseRay = mTrayMgr->getCursorRay(mCamera);
 
		mRaySceneQuery->setRay(mouseRay);
		Ogre::RaySceneQueryResult &result = mRaySceneQuery->execute();
		Ogre::RaySceneQueryResult::iterator itr = result.begin();
		if (itr != result.end() && itr->worldFragment)
			mCurrentObject->setPosition(itr->worldFragment->singleIntersection);
 
	} // if
 
	// If we are dragging the right mouse button.
	else if (mRMouseDown)
	{
		mCamera->yaw(Ogre::Degree(-arg.state.X.rel * mRotateSpeed));
		mCamera->pitch(Ogre::Degree(-arg.state.Y.rel * mRotateSpeed));
	} // else if
	return true;
}
 
bool ITutorial02::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	// Left mouse button down
	if (id == OIS::MB_Left)
	{
		//Not needed, since we are using SdkTrays:
		// Setup the ray scene query, use CEGUI's mouse position
		//CEGUI::Point mousePos = CEGUI::MouseCursor::getSingleton().getPosition();
		//Ogre::Ray mouseRay = mCamera->getCameraToViewportRay(mousePos.d_x/float(arg.state.width), mousePos.d_y/float(arg.state.height));
 
		//SdkTray - version:
		Ogre::Ray mouseRay = mTrayMgr->getCursorRay(mCamera);
 
		mRaySceneQuery->setRay(mouseRay);
		// Execute query
		Ogre::RaySceneQueryResult &result = mRaySceneQuery->execute();
		Ogre::RaySceneQueryResult::iterator itr = result.begin( );
 
		// Get results, create a node/entity on the position
		if (itr != result.end() && itr->worldFragment)
		{
			char name[16];
			sprintf( name, "Robot%d", mCount++ );
			Ogre::Entity *ent = mSceneMgr->createEntity(name, "robot.mesh");
			mCurrentObject = mSceneMgr->getRootSceneNode()->createChildSceneNode(std::string(name)+ "Node", itr->worldFragment->singleIntersection);
			mCurrentObject->attachObject(ent);
			mCurrentObject->setScale(0.1f, 0.1f, 0.1f);
		} // if
		mLMouseDown = true;
	} // if
 
 
	// Right mouse button down
	else if (id == OIS::MB_Right)
	{
		//Not needed, since we are using SdkTrays:
		//CEGUI::MouseCursor::getSingleton().hide();
 
		//SdkTray - version:
		mTrayMgr->hideCursor();
 
		mRMouseDown = true;
	} // else if
 
	return true;
}
bool ITutorial02::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	// Left mouse button up
        if (id == OIS::MB_Left)
        {
            mLMouseDown = false;
        } // if
 
        // Right mouse button up
        else if (id == OIS::MB_Right)
        {
            //Not needed, since we are using SdkTrays:
			//CEGUI::MouseCursor::getSingleton().show();
 
			//SdkTray - version:
			mTrayMgr->showCursor();
 
            mRMouseDown = false;
        } // else if
	return true;
}
