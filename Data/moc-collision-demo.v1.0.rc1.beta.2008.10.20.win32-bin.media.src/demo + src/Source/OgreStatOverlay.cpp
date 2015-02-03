#include "ogreStatOverlay.h"

OgreStatOverlay::OgreStatOverlay(RenderWindow *window)
{
	mWin = window;
	mVisible = false;
	mCollision = "ON";
};

OgreStatOverlay::~OgreStatOverlay()
{
};

void OgreStatOverlay::showDebugOverlay(bool show)
{
    Ogre::Overlay* o = (Ogre::Overlay*)Ogre::OverlayManager::getSingleton().getByName("Core/DebugOverlay");

    if (show)
    {
        o->show();
		mVisible = true;
    }
    else
    {
        o->hide();
		mVisible = false;
    }
};

void OgreStatOverlay::updateStats()
{
    static Ogre::String currFps = "Current FPS: ";

    // update stats when necessary
	Ogre::OverlayElement* guiAvg = Ogre::OverlayManager::getSingleton().getOverlayElement("Core/AverageFps");
    Ogre::OverlayElement* guiCurr = Ogre::OverlayManager::getSingleton().getOverlayElement("Core/CurrFps");
    Ogre::OverlayElement* guiBest = Ogre::OverlayManager::getSingleton().getOverlayElement("Core/BestFps");
    Ogre::OverlayElement* guiWorst = Ogre::OverlayManager::getSingleton().getOverlayElement("Core/WorstFps");
	Ogre::OverlayElement* guiTris = Ogre::OverlayManager::getSingleton().getOverlayElement("Core/NumTris");
	
	guiCurr->setCaption(currFps + Ogre::StringConverter::toString(mWin->getLastFPS()));
    
    guiAvg->setCaption("MOC - Minimal Ogre Collision");   	
	guiWorst->setCaption(""); 
    guiBest->setCaption("Collision: " + mCollision);    
    guiTris->setCaption("Press 'C' to toggle the Collision");

    Ogre::OverlayElement* guiDbg = Ogre::OverlayManager::getSingleton().getOverlayElement("Core/DebugText");
	guiDbg->setCaption("");
};
