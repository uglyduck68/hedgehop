#pragma once
#ifndef OGRESTATOVERLAY_H
#define OGRESTATOVERLAY_H

#pragma warning (disable : 4530)

#include "Ogre.h"

using namespace Ogre;

class OgreStatOverlay {
public:
	OgreStatOverlay(RenderWindow *window);
	~OgreStatOverlay();

	void updateStats();
	void showDebugOverlay(bool show);
	
	bool mVisible;
	
	String mCollision;

private:
	RenderWindow *mWin;
};
#endif