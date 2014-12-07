#ifndef _OrbitalWithMouseCameraMode_H_
#define _OrbitalWithMouseCameraMode_H_

#include <CCSCameraControlSystem.h>
#include <OIS/OIS.h>
#include <OISMouse.h>

// This is a second example of how a custom camera mode can be implemented

class OrbitalWithMouseCameraMode : public CCS::OrbitalCameraMode
{
public:
	OrbitalWithMouseCameraMode(CCS::CameraControlSystem* cam
			, OIS::MouseButtonID activateButton
			, Ogre::Real initialZoom = 1
			, Ogre::Radian initialHorizontalRotation = Ogre::Radian(0)
			, Ogre::Radian initialVerticalRotation = Ogre::Radian(0))
			: CCS::OrbitalCameraMode(cam, initialZoom, initialHorizontalRotation, initialVerticalRotation)
			, mActivateButton(activateButton)
	{ }

	~OrbitalWithMouseCameraMode(){};

	bool injectMouseMoved( const OIS::MouseEvent &e )
	{
		if(e.state.buttonDown(mActivateButton))
		{			
			this->yaw(e.state.X.rel);
			this->pitch(e.state.Y.rel);
		}
		this->zoom(-e.state.Z.rel);

		return true;
	}

protected:

	OIS::MouseButtonID mActivateButton;

};

#endif
