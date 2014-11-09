#pragma once

#include "baseapplication.h"
#include "OgreOggSound.h"

class SoundTutorial :
	public BaseApplication
{
public:
	SoundTutorial(void);
	~SoundTutorial(void);

protected:
	virtual void createScene(void); // Override me!
    virtual bool keyPressed(const OIS::KeyEvent &arg);
    virtual bool keyReleased(const OIS::KeyEvent &arg);

protected:
	OgreOggSound::OgreOggSoundManager *mSoundManager;
	OgreOggSound::OgreOggISound* sound;

};

