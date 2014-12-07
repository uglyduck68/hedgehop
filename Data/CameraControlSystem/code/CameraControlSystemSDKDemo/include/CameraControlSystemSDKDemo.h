/* -------------------------------------------------------
Copyright (c) 2012 Alberto G. Salguero (alberto.salguero at uca.es)

Permission is hereby granted, free of charge, to any
person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the
Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the
Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice
shall be included in all copies or substantial portions of
the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
------------------------------------------------------- */

#ifndef __CameraControlSystemSDKDemo_H__
#define __CameraControlSystemSDKDemo_H__

#include "SdkSample.h"

#include <CCSCameraControlSystem.h>
#include "CCSBasicCameraModes.h"
#include "CCSFreeCameraMode.h"
#include "CCSOrbitalCameraMode.h"
#include "CCSSphericCameraMode.h"
#include "OrbitalWithMouseCameraMode.h"

#include <OISMouse.h>


// Let include a custom camera mode
#include "DummyCameraMode.h"

using namespace Ogre;
using namespace OgreBites;

#define PLANE_SIZE 1000.0f

class _OgreSampleClassExport CameraControlSystemSDKDemo : public SdkSample
{
public:

	CameraControlSystemSDKDemo()
	{
		mInfo["Title"] = "Camera Control System demo";
		mInfo["Description"] = "Demo showing the Camera Control System (CCS) plugin.";
		mInfo["Thumbnail"] = "thumb_CameraControlSystemSDKDemo.png";
		mInfo["Category"] = "Plugins";
        mInfo["Help"] = "WASD for the Free/Orbital mode. Move the mouse to the screen borders/use the mouse wheel for the RTS mode.";
	}

protected:

	void setupContent()
	{		
		createScene();
		setupCameraControlSystem();
        setupControls();
	}

    void setupControls()
	{
		SelectMenu* cameraMode = mTrayMgr->createThickSelectMenu(TL_TOPLEFT, "cameraMode", "Camera Mode", 200, 10);
		cameraMode->addItem("Fixed");
		cameraMode->addItem("FixedTracking");		
        cameraMode->addItem("Chase");
		cameraMode->addItem("ChaseFreeYawAxis");
        cameraMode->addItem("FirstPerson");
		cameraMode->addItem("PlaneBinded (XY)");
        cameraMode->addItem("PlaneBinded (XZ)");
		cameraMode->addItem("ThroughTarget");
        cameraMode->addItem("ClosestToTarget");
        cameraMode->addItem("Attached");
        cameraMode->addItem("Free");
		cameraMode->addItem("Fixed direction");
        cameraMode->addItem("Orbital");
        cameraMode->addItem("RTS");
		cameraMode->addItem("Dummy");
		cameraMode->addItem("Orbital + mouse");
		cameraMode->addItem("Spherical");

		mTrayMgr->createCheckBox(TL_TOPLEFT, "animationCheckBox", "Animation", 200)->setChecked( true );

		mTrayMgr->createButton(TL_TOPLEFT, "resetTargetButton", "Reset target", 200)->hide();
		
		mTrayMgr->showCursor();
	}

    void destroySpecificCameraModeElements()
    {
        Widget* w = mTrayMgr->getWidget("tightnessSlider");
        if(w){ mTrayMgr->destroyWidget(w); }
        
        w = mTrayMgr->getWidget("charVisibleCheckBox");
        if(w){ mTrayMgr->destroyWidget(w); }
        
        w = mTrayMgr->getWidget("inverseCheckBox");
        if(w){ mTrayMgr->destroyWidget(w); }

        w = mTrayMgr->getWidget("collisionsCheckBox");
        if(w){ mTrayMgr->destroyWidget(w); }

        w = mTrayMgr->getWidget("pitchSlider");
        if(w){ mTrayMgr->destroyWidget(w); }

        w = mTrayMgr->getWidget("zoomSlider");
        if(w){ mTrayMgr->destroyWidget(w); }

        w = mTrayMgr->getWidget("freeCollisionMode");
        if(w){ mTrayMgr->destroyWidget(w); }

		w = mTrayMgr->getWidget("freeSwitchingMode");
        if(w){ mTrayMgr->destroyWidget(w); }

		w = mTrayMgr->getWidget("resetButton");
        if(w){ mTrayMgr->destroyWidget(w); }

		w = mTrayMgr->getWidget("sphericOuterRadiousSlider");
        if(w){ mTrayMgr->destroyWidget(w); }

		w = mTrayMgr->getWidget("sphericInnerRadiousSlider");
        if(w){ mTrayMgr->destroyWidget(w); }

		w = mTrayMgr->getWidget("sphericYOffsetSlider");
        if(w){ mTrayMgr->destroyWidget(w); }

		w = mTrayMgr->getWidget("sphericAutoResetCheckBox");
        if(w){ mTrayMgr->destroyWidget(w); }
		
    }

    void createSpecificCameraModeElements(String cameraModeName)
    {
        CCS::CameraControlSystem::CameraMode* cameraMode = mCameraCS->getCameraMode(cameraModeName);

        if( cameraModeName == "Chase" || cameraModeName == "ChaseFreeYawAxis" || 
            cameraModeName == "PlaneBinded (XY)" || cameraModeName == "PlaneBinded (XZ)" ||
            cameraModeName == "Fixed direction")
        {
            mTrayMgr->createThickSlider(TL_TOPLEFT, "tightnessSlider", "Tightness", 200, 50, 0, 1, 101)
                ->setValue( ((CCS::ChaseCameraMode*)cameraMode)->getCameraTightness() , false);
        }
        if( cameraModeName == "FirstPerson")
        {
            mTrayMgr->createCheckBox(TL_TOPLEFT, "charVisibleCheckBox", "Character visible", 200)
                ->setChecked( ((CCS::FirstPersonCameraMode*)cameraMode)->getCharacterVisible() );
        }
        if( cameraModeName == "ThroughTarget")
        {
            mTrayMgr->createCheckBox(TL_TOPLEFT, "inverseCheckBox", "Inverse", 200)
                ->setChecked( ((CCS::ThroughTargetCameraMode*)cameraMode)->getInverse() );
        }
        if( cameraModeName == "Chase" || cameraModeName == "ChaseFreeYawAxis" ||
            cameraModeName == "Orbital" )
        {
            mTrayMgr->createCheckBox(TL_TOPLEFT, "collisionsCheckBox", "Collisions", 200)
                ->setChecked( ((CCS::CameraControlSystem::CollidableCamera*)cameraMode)->getCollisionsEnabled() );

			if( cameraModeName == "Orbital" )
			{
				mTrayMgr->createButton(TL_TOPLEFT, "resetButton", "Reset", 200);
			}
        }
        if( cameraModeName == "RTS" )
        {
            mTrayMgr->createThickSlider(TL_TOPLEFT, "pitchSlider", "Camera pitch", 200, 50, 0, 90, 91)
                ->setValue( ((CCS::RTSCameraMode*)cameraMode)->getCameraPitch().valueDegrees() , false);

            mTrayMgr->createThickSlider(TL_TOPLEFT, "zoomSlider", "Zoom", 200, 50, 0, 1000, 101)
                ->setValue( ((CCS::RTSCameraMode*)cameraMode)->getZoom(), false);
        }
        if( cameraModeName == "Free" )
        {
            SelectMenu* freeCollisionMode = mTrayMgr->createThickSelectMenu(TL_TOPLEFT, "freeCollisionMode", "Collision mode", 200, 10);
	        freeCollisionMode->addItem("None");
			freeCollisionMode->addItem("Default");
            freeCollisionMode->addItem("AboveGround");
            freeCollisionMode->addItem("ConstantHeight");

			SelectMenu* freeSwitchingMode = mTrayMgr->createThickSelectMenu(TL_TOPLEFT, "freeSwitchingMode", "Switching delegate", 200, 10);
	        freeSwitchingMode->addItem("Current");
			freeSwitchingMode->addItem("Initial");
            freeSwitchingMode->addItem("Last");

			mTrayMgr->createButton(TL_TOPLEFT, "resetButton", "Reset", 200);
        }
		if( cameraModeName == "Spherical" )
        {
            mTrayMgr->createThickSlider(TL_TOPLEFT, "sphericOuterRadiousSlider", "Outer radious", 200, 50, 200, 1200, 101)
                ->setValue( ((CCS::SphericCameraMode*)cameraMode)->getOuterSphereRadious(), false);
			mTrayMgr->createThickSlider(TL_TOPLEFT, "sphericInnerRadiousSlider", "Inner radious", 200, 50, 0, 1000, 101)
                ->setValue( ((CCS::SphericCameraMode*)cameraMode)->getInnerSphereRadious(), false);
			mTrayMgr->createThickSlider(TL_TOPLEFT, "sphericYOffsetSlider", "Height offset", 200, 50, 0, 200, 51)
                ->setValue( ((CCS::SphericCameraMode*)cameraMode)->getOffset().y, false);
			mTrayMgr->createCheckBox(TL_TOPLEFT, "sphericAutoResetCheckBox", "Auto reset", 200)
                ->setChecked( ((CCS::SphericCameraMode*)cameraMode)->getAutoResetTime() != 0 );
        }

		
    }

    void itemSelected(SelectMenu* menu)
	{
		if (menu->getName() == "cameraMode")
		{
            destroySpecificCameraModeElements();

            CCS::CameraControlSystem::CameraMode* cameraMode = mCameraCS->getCameraMode( menu->getSelectedItem() );
            String cameraModeName = mCameraCS->getCameraModeName(cameraMode);

			mCameraCS->setCurrentCameraMode( cameraMode );

            createSpecificCameraModeElements(cameraModeName);
		}
        else if (menu->getName() == "freeCollisionMode")
        {
            CCS::FreeCameraMode* freeCameraMode = (CCS::FreeCameraMode*)mCameraCS->getCurrentCameraMode();

            if(menu->getSelectedItem() == "None")
            {
                freeCameraMode->setCollisionsEnabled(false);
            }
			else if(menu->getSelectedItem() == "Default")
            {
                freeCameraMode->setCollisionsEnabled(true);
                freeCameraMode->setMargin(10);

                freeCameraMode->collisionDelegate = 
                    CCS::CameraControlSystem::CollidableCamera::newCollisionDelegate(
                        freeCameraMode
						, &CCS::CameraControlSystem::CollidableCamera::DefaultCollisionDetectionFunction);
            }
            else if(menu->getSelectedItem() == "AboveGround")
            {
                freeCameraMode->setCollisionsEnabled(true);
                freeCameraMode->setMargin(10);

                freeCameraMode->collisionDelegate = 
                    CCS::CameraControlSystem::CollidableCamera::newCollisionDelegate(
                        freeCameraMode
                        , &CCS::FreeCameraMode::AboveGroundCollisionDetectionFunction);
            }
            else if(menu->getSelectedItem() == "ConstantHeight")
            {
                freeCameraMode->setCollisionsEnabled(true);
                freeCameraMode->setMargin(100);

                freeCameraMode->collisionDelegate 
                    = CCS::CameraControlSystem::CollidableCamera::newCollisionDelegate(
                        freeCameraMode
                        , &CCS::FreeCameraMode::ConstantHeightCollisionDetectionFunction);
            }
        }
		else if (menu->getName() == "freeSwitchingMode")
        {
            CCS::FreeCameraMode* freeCameraMode = (CCS::FreeCameraMode*)mCameraCS->getCurrentCameraMode();

            if(menu->getSelectedItem() == "Current")
            {
				freeCameraMode->setSwitchingMode(CCS::FreeCameraMode::CURRENT_STATE);
            }
			else if(menu->getSelectedItem() == "Initial")
            {
				freeCameraMode->setSwitchingMode(CCS::FreeCameraMode::INITIAL_STATE);
            }
			else if(menu->getSelectedItem() == "Last")
            {
				freeCameraMode->setSwitchingMode(CCS::FreeCameraMode::LAST_STATE);
            }
        }
		
	}

    void sliderMoved(Slider* slider)
	{
		if (slider->getName() == "tightnessSlider")
		{
			((CCS::CameraControlSystem::CameraModeWithTightness*)mCameraCS->getCurrentCameraMode())
                ->setCameraTightness(slider->getValue());
		}
        else if (slider->getName() == "pitchSlider")
		{
			((CCS::RTSCameraMode*)mCameraCS->getCurrentCameraMode())
                ->setCameraPitch( Radian(Degree( slider->getValue() )) );
		}
        else if (slider->getName() == "zoomSlider")
		{
			((CCS::RTSCameraMode*)mCameraCS->getCurrentCameraMode())
                ->setZoom( slider->getValue() );
		}
		else if (slider->getName() == "sphericOuterRadiousSlider")
		{
			((CCS::SphericCameraMode*)mCameraCS->getCurrentCameraMode())
                ->setOuterSphereRadious( slider->getValue() );

			// check if valid
			slider->setValue( ((CCS::SphericCameraMode*)mCameraCS->getCurrentCameraMode())
					->getOuterSphereRadious(), false);

			// check if inner radious has been affected
			((Slider*)mTrayMgr->getWidget("sphericInnerRadiousSlider"))
                ->setValue( ((CCS::SphericCameraMode*)mCameraCS->getCurrentCameraMode())
					->getInnerSphereRadious(), false);
		}
		else if (slider->getName() == "sphericInnerRadiousSlider")
		{
			((CCS::SphericCameraMode*)mCameraCS->getCurrentCameraMode())
                ->setInnerSphereRadious( slider->getValue() );

			// check if valid
			slider->setValue( ((CCS::SphericCameraMode*)mCameraCS->getCurrentCameraMode())
					->getInnerSphereRadious(), false);

			// check if outner radious has been affected
			((Slider*)mTrayMgr->getWidget("sphericOuterRadiousSlider"))
                ->setValue( ((CCS::SphericCameraMode*)mCameraCS->getCurrentCameraMode())
					->getOuterSphereRadious(), false);
		}
		else if (slider->getName() == "sphericYOffsetSlider")
		{
			((CCS::SphericCameraMode*)mCameraCS->getCurrentCameraMode())
				->setHeightOffset( slider->getValue() );			
		}
	}

    void checkBoxToggled(CheckBox* box)
	{
        bool checked = box->isChecked();

		if (box->getName() == "charVisibleCheckBox")
		{
            ((CCS::FirstPersonCameraMode*)mCameraCS->getCurrentCameraMode())
                ->setCharacterVisible(checked);
		}
        else if(box->getName() == "inverseCheckBox")
        {
            ((CCS::ThroughTargetCameraMode*)mCameraCS->getCurrentCameraMode())
                ->setInverse(checked);
        }
        else if(box->getName() == "collisionsCheckBox")
        {
            CCS::CameraControlSystem::CameraMode* cameraMode = mCameraCS->getCurrentCameraMode();
            String cameraModeName = mCameraCS->getCameraModeName(cameraMode);

            if( cameraModeName == "Chase" )
            {
                ((CCS::ChaseCameraMode*)mCameraCS->getCurrentCameraMode())
                    ->setCollisionsEnabled(checked);
            }
            else if( cameraModeName == "ChaseFreeYawAxis" )
            {
                ((CCS::ChaseFreeYawAxisCameraMode*)mCameraCS->getCurrentCameraMode())
                    ->setCollisionsEnabled(checked);
            }
            else if( cameraModeName == "Orbital" )
            {
                ((CCS::OrbitalCameraMode*)mCameraCS->getCurrentCameraMode())
                    ->setCollisionsEnabled(checked);
            }
        }
		else if(box->getName() == "animationCheckBox")
        {
            mAnimState->setEnabled(box->isChecked());

			if(mAnimState->getEnabled())
			{
				Widget* w = mTrayMgr->getWidget("resetTargetButton");
				if(w)
					w->hide();
			}
			else
			{
				Widget* w = mTrayMgr->getWidget("resetTargetButton");
				if(w)
					w->show();
			}
        }
		else if(box->getName() == "sphericAutoResetCheckBox")
        {
			if(box->isChecked())
			{
				((CCS::SphericCameraMode*)mCameraCS->getCurrentCameraMode())
					->setAutoResetTime(3.0);
			}
			else
			{
				((CCS::SphericCameraMode*)mCameraCS->getCurrentCameraMode())
					->setAutoResetTime(0); // disable auto reset
			}
        }
		
	}

	void buttonHit(Button* button)
	{
		if (button->getName() == "resetButton")
		{
			CCS::CameraControlSystem::CameraMode* cameraMode = mCameraCS->getCurrentCameraMode();
            String cameraModeName = mCameraCS->getCameraModeName(cameraMode);

            if( cameraModeName == "Orbital" )
            {
                ((CCS::OrbitalCameraMode*)mCameraCS->getCurrentCameraMode())->reset();
            }
			else if( cameraModeName == "Free" )
            {
                ((CCS::FreeCameraMode*)mCameraCS->getCurrentCameraMode())->reset();
            }
			else if( cameraModeName == "Spherical" )
            {
                ((CCS::SphericCameraMode*)mCameraCS->getCurrentCameraMode())->reset(false);
            }
				
		}
		if (button->getName() == "resetTargetButton")
		{
			mCameraCS->getTargetSceneNode()->setPosition(Ogre::Vector3::ZERO);
			mCameraCS->getTargetSceneNode()->setOrientation(Ogre::Quaternion::IDENTITY);
		}
	}

	bool frameRenderingQueued(const FrameEvent& evt)
    {	
		processCameraKeyInput();
		processPlayerKeyInput(evt);
        processUnbufferedMouseInput();

		if( ((CheckBox*)mTrayMgr->getWidget("animationCheckBox"))->isChecked() )
			mAnimState->addTime(evt.timeSinceLastFrame);

		mCameraCS->update(evt.timeSinceLastFrame);

		return SdkSample::frameRenderingQueued(evt); 
    }

    // overriden
    virtual bool keyPressed(const OIS::KeyEvent& evt)
	{
		if (evt.key == OIS::KC_H || evt.key == OIS::KC_F1)   // toggle visibility of help dialog
		{
			if (!mTrayMgr->isDialogVisible() && mInfo["Help"] != "") mTrayMgr->showOkDialog("Help", mInfo["Help"]);
			else mTrayMgr->closeDialog();
		}

		if (mTrayMgr->isDialogVisible()) return true;   // don't process any more keys if dialog is up

		if (evt.key == OIS::KC_F)   // toggle visibility of advanced frame stats
		{
			mTrayMgr->toggleAdvancedFrameStats();
		}
		else if (evt.key == OIS::KC_G)   // toggle visibility of even rarer debugging details
		{
			if (mDetailsPanel->getTrayLocation() == TL_NONE)
			{
				mTrayMgr->moveWidgetToTray(mDetailsPanel, TL_TOPRIGHT, 0);
				mDetailsPanel->show();
			}
			else
			{
				mTrayMgr->removeWidgetFromTray(mDetailsPanel);
				mDetailsPanel->hide();
			}
		}
		else if (evt.key == OIS::KC_T)   // cycle polygon rendering mode
		{
			Ogre::String newVal;
			Ogre::TextureFilterOptions tfo;
			unsigned int aniso;

			switch (mDetailsPanel->getParamValue(9).asUTF8()[0])
			{
			case 'B':
				newVal = "Trilinear";
				tfo = Ogre::TFO_TRILINEAR;
				aniso = 1;
				break;
			case 'T':
				newVal = "Anisotropic";
				tfo = Ogre::TFO_ANISOTROPIC;
				aniso = 8;
				break;
			case 'A':
				newVal = "None";
				tfo = Ogre::TFO_NONE;
				aniso = 1;
				break;
			default:
				newVal = "Bilinear";
				tfo = Ogre::TFO_BILINEAR;
				aniso = 1;
			}

			Ogre::MaterialManager::getSingleton().setDefaultTextureFiltering(tfo);
			Ogre::MaterialManager::getSingleton().setDefaultAnisotropy(aniso);
			mDetailsPanel->setParamValue(9, newVal);
		}
		else if (evt.key == OIS::KC_R)   // cycle polygon rendering mode
		{
			Ogre::String newVal;
			Ogre::PolygonMode pm;

			switch (mCamera->getPolygonMode())
			{
			case Ogre::PM_SOLID:
				newVal = "Wireframe";
				pm = Ogre::PM_WIREFRAME;
				break;
			case Ogre::PM_WIREFRAME:
				newVal = "Points";
				pm = Ogre::PM_POINTS;
				break;
			default:
				newVal = "Solid";
				pm = Ogre::PM_SOLID;
			}

			mCamera->setPolygonMode(pm);
			mDetailsPanel->setParamValue(10, newVal);
		}
		else if(evt.key == OIS::KC_F5)   // refresh all textures
		{
			Ogre::TextureManager::getSingleton().reloadAll();
		}
		else if (evt.key == OIS::KC_SYSRQ)   // take a screenshot
		{
			mWindow->writeContentsToTimestampedFile("screenshot", ".png");
		}

#ifdef USE_RTSHADER_SYSTEM		
		// Toggle schemes.			
		else if (evt.key == OIS::KC_F2)
		{	
			Ogre::Viewport* mainVP = mCamera->getViewport();
			const Ogre::String& curMaterialScheme = mainVP->getMaterialScheme();

			if (curMaterialScheme == Ogre::MaterialManager::DEFAULT_SCHEME_NAME)
			{							
				mainVP->setMaterialScheme(Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);
				mDetailsPanel->setParamValue(11, "On");
			}
			else if (curMaterialScheme == Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME)
			{
				mainVP->setMaterialScheme(Ogre::MaterialManager::DEFAULT_SCHEME_NAME);
				mDetailsPanel->setParamValue(11, "Off");
			}														
		}			

#ifdef RTSHADER_SYSTEM_BUILD_EXT_SHADERS

		// Toggles per pixel per light model.
		else if (evt.key == OIS::KC_F3)
		{
			static bool usePerPixelLighting = true;					
							
			// Grab the scheme render state.												
			Ogre::RTShader::RenderState* schemRenderState = mShaderGenerator->getRenderState(Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);

			
			// Add per pixel lighting sub render state to the global scheme render state.
			// It will override the default FFP lighting sub render state.
			if (usePerPixelLighting)
			{
				Ogre::RTShader::SubRenderState* perPixelLightModel = mShaderGenerator->createSubRenderState(Ogre::RTShader::PerPixelLighting::Type);
				
				schemRenderState->addTemplateSubRenderState(perPixelLightModel);					
			}

			// Search the per pixel sub render state and remove it.
			else
			{
				const Ogre::RTShader::SubRenderStateList& subRenderStateList = schemRenderState->getTemplateSubRenderStateList();
				Ogre::RTShader::SubRenderStateListConstIterator it = subRenderStateList.begin();
				Ogre::RTShader::SubRenderStateListConstIterator itEnd = subRenderStateList.end();
					
				for (; it != itEnd; ++it)
				{
					Ogre::RTShader::SubRenderState* curSubRenderState = *it;

					// This is the per pixel sub render state -> remove it.
					if (curSubRenderState->getType() == Ogre::RTShader::PerPixelLighting::Type)
					{
						schemRenderState->removeTemplateSubRenderState(*it);
						break;
					}
				}
			}

			// Invalidate the scheme in order to re-generate all shaders based technique related to this scheme.
			mShaderGenerator->invalidateScheme(Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);


			// Update UI.
			if (usePerPixelLighting)
				mDetailsPanel->setParamValue(12, "Pixel");
			else
				mDetailsPanel->setParamValue(12, "Vertex");
			usePerPixelLighting = !usePerPixelLighting;				
		}	
#endif

		// Switch vertex shader outputs compaction policy.
		else if (evt.key == OIS::KC_F4)   
		{
			switch (mShaderGenerator->getVertexShaderOutputsCompactPolicy())
			{
			case Ogre::RTShader::VSOCP_LOW:
				mShaderGenerator->setVertexShaderOutputsCompactPolicy(Ogre::RTShader::VSOCP_MEDIUM);
				mDetailsPanel->setParamValue(13, "Medium");
				break;

			case Ogre::RTShader::VSOCP_MEDIUM:
				mShaderGenerator->setVertexShaderOutputsCompactPolicy(Ogre::RTShader::VSOCP_HIGH);
				mDetailsPanel->setParamValue(13, "High");
				break;

			case Ogre::RTShader::VSOCP_HIGH:
				mShaderGenerator->setVertexShaderOutputsCompactPolicy(Ogre::RTShader::VSOCP_LOW);
				mDetailsPanel->setParamValue(13, "Low");
				break;
			}
			
			// Invalidate the scheme in order to re-generate all shaders based technique related to this scheme.
			mShaderGenerator->invalidateScheme(Ogre::RTShader::ShaderGenerator::DEFAULT_SCHEME_NAME);
		}	
#endif

		//mCameraMan->injectKeyDown(evt); Use the CCS pluging instead
		return true;
	}

	// Overriden
	virtual bool keyReleased(const OIS::KeyEvent& evt)
	{
		//mCameraMan->injectKeyUp(evt); Use the CCS pluging instead

		return true;
	}

	// Overriden
	virtual bool mouseMoved(const OIS::MouseEvent& evt)
	{
		if (mTrayMgr->injectMouseMove(evt)) return true;

		//mCameraMan->injectMouseMove(evt);
		CCS::CameraControlSystem::CameraMode* cameraMode = mCameraCS->getCurrentCameraMode();
		String cameraModeName = mCameraCS->getCameraModeName(cameraMode);
        if( cameraModeName == "Orbital + mouse" )
		{
			static_cast<OrbitalWithMouseCameraMode*>(cameraMode)->injectMouseMoved(evt);
		}

		return true;
	}

	// Overriden
	virtual bool mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
	{
		if (mTrayMgr->injectMouseDown(evt, id)) return true;
        
		/*if (mDragLook && id == OIS::MB_Left)
		{
			mCameraMan->setStyle(CS_FREELOOK);
			mTrayMgr->hideCursor();
		}

		mCameraMan->injectMouseDown(evt, id);*/

		return true;
	}

	// Overriden
	virtual bool mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
	{
		if (mTrayMgr->injectMouseUp(evt, id)) return true;
        
		/*if (mDragLook && id == OIS::MB_Left)
		{
			mCameraMan->setStyle(CS_MANUAL);
			mTrayMgr->showCursor();
		}

		mCameraMan->injectMouseUp(evt, id);*/

		return true;
	}

	void createScene(void)
    {
        // Set ambient light
        mSceneMgr->setAmbientLight(ColourValue(0.75, 0.75, 0.75));

        // Create a light
        Light* l = mSceneMgr->createLight("MainLight");
        // Accept default settings: point light, white diffuse, just set position
        // NB I could attach the light to a SceneNode if I wanted it to move automatically with
        //  other objects, but I don't
        l->setPosition(200,700,100);

        mSceneMgr->setShadowTechnique(SHADOWTYPE_TEXTURE_MODULATIVE);

        // Create a skydome
        mSceneMgr->setSkyDome(true, "Examples/CloudySky", 30, 5);

        // Put in a bit of fog for the hell of it
        mSceneMgr->setFog(FOG_EXP, ColourValue::White, 0.0001, 0.5);

		// Define a floor plane mesh
        Plane p;
        p.normal = Vector3::UNIT_Y;
        p.d = 180;
        MeshManager::getSingleton().createPlane("FloorPlane",
            ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
            p,PLANE_SIZE*1000,PLANE_SIZE*1000,20,20,true,1,50,50,Vector3::UNIT_Z);

        Entity *ent = mSceneMgr->createEntity("floorEntity", "FloorPlane");
        ent->setMaterialName("Examples/RustySteel");
        ent->setCastShadows(false);
        SceneNode *floorNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("floorSceneNode");
		floorNode->attachObject(ent);

        // Add a head, give it it's own node
        // The Ogre head faces to Z
        headNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("headSceneNode");
        ent = mSceneMgr->createEntity("head", "ogrehead.mesh");
        ent->setCastShadows(true);
        headNode->attachObject(ent);

        atheneNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("atheneSceneNode");
        //Entity *Athene = mSceneMgr->createEntity( "Razor", "razor.mesh" );
        Entity *Athene = mSceneMgr->createEntity( "Athene", "athene.mesh" );
        Athene->setMaterialName("Examples/Athene/NormalMapped");
        Athene->setCastShadows(true);
        atheneNode->attachObject( Athene );
        atheneNode->setPosition(Ogre::Vector3(500,-100,500));

        // Obstacle for collisions detection
	    SceneNode* barrelNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("barrelSceneNode");
        Entity *barrel = mSceneMgr->createEntity( "barrel", "barrel.mesh" );
        barrel->setCastShadows(true);
        barrelNode->attachObject( barrel );
        barrelNode->setPosition(Ogre::Vector3(1300,-100,500));
	    barrelNode->scale(40,40,40);

		// Create light node
        SceneNode* lightNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("lightSceneNode");
		lightNode->attachObject(l);

        // set up spline animation of node
        Animation* anim = mSceneMgr->createAnimation("HeadTrack", 20);
        // Spline it for nice curves
        anim->setInterpolationMode(Animation::IM_SPLINE);
        // Create a track to animate the camera's node
        NodeAnimationTrack* track = anim->createNodeTrack(0, headNode);
        // Setup keyframes
        TransformKeyFrame* key = track->createNodeKeyFrame(0); // startposition
        key->setTranslate(Vector3(0,0,0));
        key->setRotation(Ogre::Quaternion::IDENTITY);
        key = track->createNodeKeyFrame(2.5);
        key->setTranslate(Vector3(0,0,1000));
        key->setRotation(Vector3::UNIT_Z.getRotationTo(Vector3(1000,0,1000)));
        key = track->createNodeKeyFrame(5);
        key->setTranslate(Vector3(1000,0,1000));
        key->setRotation(Vector3::UNIT_Z.getRotationTo(Vector3(1000,0,0)));
        key = track->createNodeKeyFrame(7.5);
        key->setTranslate(Vector3(1000,0,0));
        key->setRotation(Vector3::UNIT_Z.getRotationTo(Vector3::NEGATIVE_UNIT_X));
        key = track->createNodeKeyFrame(10);
        key->setTranslate(Vector3(0,0,0));

        // Second round
        key = track->createNodeKeyFrame(11);
        key->setTranslate(Vector3(0,0,400));
        key->setRotation(Quaternion(Radian(3.14/4.0),Vector3::UNIT_Z));
        key = track->createNodeKeyFrame(11.5);
        key->setTranslate(Vector3(0,0,600));
        key->setRotation(Quaternion(Radian(-3.14/4.0),Vector3::UNIT_Z));
        key = track->createNodeKeyFrame(12.5);
        key->setTranslate(Vector3(0,0,1000));
        key->setRotation(Vector3::UNIT_Z.getRotationTo(Vector3(500,500,1000)));
        key = track->createNodeKeyFrame(13.25);
        key->setTranslate(Vector3(500,500,1000));
        key->setRotation(Vector3::UNIT_Z.getRotationTo(Vector3(1000,-500,1000)));
        key = track->createNodeKeyFrame(15);
        key->setTranslate(Vector3(1000,0,1000));
        key->setRotation(Vector3::UNIT_Z.getRotationTo(Vector3(1000,0,-500)));
        key = track->createNodeKeyFrame(16);
        key->setTranslate(Vector3(1000,0,500));
        key = track->createNodeKeyFrame(16.5);
        key->setTranslate(Vector3(1000,0,600));
        key = track->createNodeKeyFrame(17.5);
        key->setTranslate(Vector3(1000,0,0));
        key->setRotation(Vector3::UNIT_Z.getRotationTo(Vector3(-500,500,0)));
        key = track->createNodeKeyFrame(118.25);
        key->setTranslate(Vector3(500,500,0));
        key->setRotation(Quaternion(Radian(3.14),Vector3::UNIT_X) * Vector3::UNIT_Z.getRotationTo(Vector3(-500,-500,0)));
        key = track->createNodeKeyFrame(20);
        key->setTranslate(Vector3(0,0,0));
		key = track->createNodeKeyFrame(2000);
        key->setTranslate(Vector3(-20000000,0,0));

        // Create a new animation state to track this
        mAnimState = mSceneMgr->createAnimationState("HeadTrack");
        mAnimState->setEnabled(true);

    }

    void setupCameraControlSystem()
    {
        // Ogre::camera points to -Z by default

        // Create the camera system using the previously created ogre camera.
		mCameraCS = new CCS::CameraControlSystem(mSceneMgr, "CameraControlSystem", mCamera);

        // -------------------------------------------------------------------------------------
        // Register a "Fixed" camera mode. In this mode the camera position and orientation
        // never change.

        CCS::FixedCameraMode* camMode1;
        camMode1 = new CCS::FixedCameraMode(mCameraCS);
        //mCameraCS->registerCameraMode("Fixed (2)",camMode1);
        mCameraCS->registerCameraMode("Fixed",camMode1);
        camMode1->setCameraPosition(Ogre::Vector3(-500,0,-500));
        float roll = 0; float yaw = 225; float pitch = 10;
        camMode1->setCameraOrientation( Quaternion(Radian(Degree(roll)),Vector3::UNIT_Z)
            * Quaternion(Radian(Degree(yaw)),Vector3::UNIT_Y)
            * Quaternion(Radian(Degree(pitch)),Vector3::UNIT_X));

        // -------------------------------------------------------------------------------------
        // Register a "FixedTracking" camera mode. In this mode the camera position is fixed
        // and the camera always points to the target.

        CCS::FixedTrackingCameraMode* camMode2;
        camMode2 = new CCS::FixedTrackingCameraMode(mCameraCS);
        mCameraCS->registerCameraMode("FixedTracking",camMode2);
        camMode2->setCameraPosition(Ogre::Vector3(500,0,-100));

        // -------------------------------------------------------------------------------------
        // Register a "Chase" camera mode with default tightness (0.01). In
        // this mode the camera follows the target. The second parameter is the relative position
        // to the target. The orientation of the camera is fixed by a yaw axis (UNIT_Y by default).

        CCS::ChaseCameraMode* camMode3;
        camMode3 = new CCS::ChaseCameraMode(mCameraCS,Ogre::Vector3(0,0,-200));
        //mCameraCS->registerCameraMode("Chase(0.01 tightness)",camMode3);
        mCameraCS->registerCameraMode("Chase",camMode3);

        // -------------------------------------------------------------------------------------
        // Register a "ChaseFreeYawAxis" camera mode with max tightness. This mode is
        // similar to "Chase" camera mode but the camera orientation is not fixed by
        // a yaw axis. The camera orientation will be the same as the target.

        camMode3 = new CCS::ChaseFreeYawAxisCameraMode(mCameraCS,Ogre::Vector3(0,0,-200)
            , Ogre::Radian(0),Ogre::Radian(Ogre::Degree(180)),Ogre::Radian(0));
        mCameraCS->registerCameraMode("ChaseFreeYawAxis",camMode3);
        camMode3->setCameraTightness(0.05);

        // -------------------------------------------------------------------------------------
        // Register a "FirstPerson" camera mode.

        //CCS::FirstPersonCameraMode* camMode4 = new CCS::FirstPersonCameraMode(mCameraCS,Ogre::Vector3(0,17,-16)
        CCS::FirstPersonCameraMode* camMode4 = new CCS::FirstPersonCameraMode(mCameraCS,Ogre::Vector3(0,6,-20)
            , Ogre::Radian(0),Ogre::Radian(Ogre::Degree(180)),Ogre::Radian(0));
        mCameraCS->registerCameraMode("FirstPerson",camMode4);
		camMode4->setCharacterVisible(false);

        // -------------------------------------------------------------------------------------
        // Register a "PlaneBinded" camera mode. In this mode the camera is constrained to the
		// limits of a plane. The camera always points to the target, perpendicularly to the plane.

        Ogre::Plane* mPlane = new Ogre::Plane(Ogre::Vector3::UNIT_Z, Ogre::Vector3(0,0,-200));
        CCS::PlaneBindedCameraMode* camMode5 = new CCS::PlaneBindedCameraMode(mCameraCS, *mPlane);
        mCameraCS->registerCameraMode("PlaneBinded (XY)",camMode5);

        // -------------------------------------------------------------------------------------
        // Register another "PlaneBinded" camera mode using a top point of view.

        mPlane = new Ogre::Plane(Ogre::Vector3::UNIT_Y, Ogre::Vector3(0,1000,0));
        camMode5 = new CCS::PlaneBindedCameraMode(mCameraCS, *mPlane, Ogre::Vector3::UNIT_Z);
        mCameraCS->registerCameraMode("PlaneBinded (XZ)",camMode5);

        // -------------------------------------------------------------------------------------
        // Register a "ThroughTarget" camera mode. In this mode the camera points to a given
        // position (the "focus") throuh the target. The camera orientation is fixed by a yaw axis.

        CCS::ThroughTargetCameraMode* camMode6 = new CCS::ThroughTargetCameraMode(mCameraCS, 400);
        mCameraCS->registerCameraMode("ThroughTarget",camMode6);
        //camMode6->setCameraFocusPosition(atheneNode->_getDerivedPosition() - Ogre::Vector3(0,100,0));
        camMode6->setCameraFocusPosition(atheneNode->_getDerivedPosition() + Ogre::Vector3(0,100,0));

        // -------------------------------------------------------------------------------------
        // Register a "ClosestToTarget" camera mode. In this camera mode the position of the
        // camera is chosen to be the closest to the target of a given list. The camera
        // orientation is fixed by a yaw axis.

        CCS::ClosestToTargetCameraMode* camMode7 = new CCS::ClosestToTargetCameraMode(mCameraCS);
        mCameraCS->registerCameraMode("ClosestToTarget",camMode7);

        Ogre::Vector3* camPos1 = new Ogre::Vector3(-400,0,-400);
        Ogre::Vector3* camPos2 = new Ogre::Vector3(-400,0,1400);
        Ogre::Vector3* camPos3 = new Ogre::Vector3(1400,0,1400);

        camMode7->addCameraPosition(*camPos1);
        camMode7->addCameraPosition(*camPos2);
        camMode7->addCameraPosition(*camPos3);

        // -------------------------------------------------------------------------------------
        // Register an "Attached" camera mode. In this mode the camera node is attached to the
        // target node as a child.

        CCS::AttachedCameraMode* camMode8 = new CCS::AttachedCameraMode(mCameraCS,Ogre::Vector3(200,0,0)
            , Ogre::Radian(0),Ogre::Radian(Ogre::Degree(90)),Ogre::Radian(0));
        //mCameraCS->registerCameraMode("Attached (lateral)",camMode8);
        mCameraCS->registerCameraMode("Attached",camMode8);

        // -------------------------------------------------------------------------------------
        // Register a "Free" camera mode. In this mode the camera is controlled by the user.
        // The camera orientation is fixed to a yaw axis.

		yaw = 225; pitch = -10;
		CCS::FreeCameraMode* camMode9 = new CCS::FreeCameraMode(mCameraCS, Ogre::Vector3::ZERO, Ogre::Degree(yaw), Ogre::Degree(pitch)
			, CCS::FreeCameraMode::CURRENT_STATE);
        mCameraCS->registerCameraMode("Free",camMode9);
        camMode9->setMoveFactor(30);

        // -------------------------------------------------------------------------------------
        // Register a "FixedDirection" camera mode. In this mode the
		// target is always seen from the same point of view.

        CCS::FixedDirectionCameraMode* camMode10 = new CCS::FixedDirectionCameraMode(mCameraCS, Ogre::Vector3(-1,-1,-1), 1000);
        mCameraCS->registerCameraMode("Fixed direction",camMode10);
		camMode10->setCameraTightness(0.01);

		// -------------------------------------------------------------------------------------
        // Register an "Orbital" camera mode. This is basically an attached camera mode where the user
	    // can mofify the camera position. If the scene focus is seen as the center of a sphere, the camera rotates arount it.
		// The last parameter indicates if the camera should be reset to its initial position when this mode is selected.

		CCS::OrbitalCameraMode* camMode12 = new CCS::OrbitalCameraMode(mCameraCS, 200, Ogre::Radian(0), Ogre::Radian(0), false);
        mCameraCS->registerCameraMode("Orbital",camMode12);
		camMode12->setZoomFactor(100);
		camMode12->setRotationFactor(50);
		// ** Uncomment for custom collisions calculation. By default the collisions are based on ogre basic raycast feature **
		//camMode12->collisionDelegate = CCS::CollidableCamera::newCollisionDelegate(this
		//	, &CameraControlSystemDemo::CustomCollisionDetectionFunction);
		
        // -------------------------------------------------------------------------------------
        // Register a RTS camera mode.
		//

		CCS::RTSCameraMode* camMode13 = new CCS::RTSCameraMode(mCameraCS,
            Ogre::Vector3(500, 1300, 1000)
            , Ogre::Vector3::NEGATIVE_UNIT_Z
            , Ogre::Vector3::NEGATIVE_UNIT_X
            , Ogre::Radian(Ogre::Degree(70))
            , 0, 1000);
        mCameraCS->registerCameraMode("RTS",camMode13);
        camMode13->setMoveFactor(20);

		// -------------------------------------------------------------------------------------
        // Register the custom "Dummy" camera mode defined previously. It basically goes forward
		// and backward constantly

        DummyCameraMode* camMode14 = new DummyCameraMode(mCameraCS, 400);
        mCameraCS->registerCameraMode("Dummy",(CCS::CameraControlSystem::CameraMode*)camMode14);

		// -------------------------------------------------------------------------------------
        // Register an "OrbitalWithMouse" camera mode. 

		OrbitalWithMouseCameraMode* camMode15 = new OrbitalWithMouseCameraMode(mCameraCS, OIS::MB_Left, 200);
        mCameraCS->registerCameraMode("Orbital + mouse",camMode15);
		camMode15->setZoomFactor(3);		
		camMode15->setRotationFactor(10);

		// -------------------------------------------------------------------------------------
        // Register a spheric camera mode. 

		Ogre::Vector3 relativePositionToCameraTarget(0,50,-300);
		
		// THIS IS NOT NECESSARY. just needed for the demo showing integer values in the sliders
		relativePositionToCameraTarget = relativePositionToCameraTarget.normalisedCopy() * 300;
		
		CCS::SphericCameraMode* camMode16 = new CCS::SphericCameraMode(mCameraCS, relativePositionToCameraTarget, 700);
		// outer radious = inner radious = relativePositionToCameraTarget.length() for a perfect sphere
		camMode16->setHeightOffset(50);
        mCameraCS->registerCameraMode("Spherical",camMode16);

        // Set the camera target
        mCameraCS->setCameraTarget(headNode);

        mCameraCS->setCurrentCameraMode(camMode1);
    }

	void processCameraKeyInput()
	{
		if(mCameraCS->getCameraModeName(mCameraCS->getCurrentCameraMode()) == "Free")
        {
            CCS::FreeCameraMode* freeCameraMode = (CCS::FreeCameraMode*)mCameraCS->getCameraMode("Free");

			if(mKeyboard->isKeyDown(OIS::KC_A))
				//mTranslateVector.x = -mMoveScale;	// Move camera left
				freeCameraMode->goLeft();

			if(mKeyboard->isKeyDown(OIS::KC_D))
				//mTranslateVector.x = mMoveScale;	// Move camera RIGHT
				freeCameraMode->goRight();

			if(mKeyboard->isKeyDown(OIS::KC_W) )
				//mTranslateVector.z = -mMoveScale;	// Move camera forward
				freeCameraMode->goForward();

			if(mKeyboard->isKeyDown(OIS::KC_S) )
				//mTranslateVector.z = mMoveScale;	// Move camera backward
				freeCameraMode->goBackward();

			if(mKeyboard->isKeyDown(OIS::KC_PGUP))
				//mTranslateVector.y = mMoveScale;	// Move camera up
				freeCameraMode->goUp();

			if(mKeyboard->isKeyDown(OIS::KC_PGDOWN))
				//mTranslateVector.y = -mMoveScale;	// Move camera down
				freeCameraMode->goDown();

			if(mKeyboard->isKeyDown(OIS::KC_RIGHT))
				//mCamera->yaw(-mRotScale);
				freeCameraMode->yaw(-1);

			if(mKeyboard->isKeyDown(OIS::KC_LEFT))
				//mCamera->yaw(mRotScale);
				freeCameraMode->yaw(1);
		}
		else if(mCameraCS->getCameraModeName(mCameraCS->getCurrentCameraMode()) == "Orbital"
			|| mCameraCS->getCameraModeName(mCameraCS->getCurrentCameraMode()) == "Orbital (collidable)")
		{
			CCS::OrbitalCameraMode* orbitalCameraMode;

			if(mCameraCS->getCameraModeName(mCameraCS->getCurrentCameraMode()) == "Orbital")
			{
				orbitalCameraMode = (CCS::OrbitalCameraMode*)mCameraCS->getCameraMode("Orbital");
			}
			else
			{
				orbitalCameraMode = (CCS::OrbitalCameraMode*)mCameraCS->getCameraMode("Orbital (collidable)");
			}

			if(mKeyboard->isKeyDown(OIS::KC_A))
                orbitalCameraMode->yaw(1);

			if(mKeyboard->isKeyDown(OIS::KC_D))
                orbitalCameraMode->yaw(-1);

			if(mKeyboard->isKeyDown(OIS::KC_W))
                orbitalCameraMode->pitch(1);

			if(mKeyboard->isKeyDown(OIS::KC_S))
                orbitalCameraMode->pitch(-1);

			if(mKeyboard->isKeyDown(OIS::KC_PGUP))
                orbitalCameraMode->zoom(-1);

			if(mKeyboard->isKeyDown(OIS::KC_PGDOWN))
                orbitalCameraMode->zoom(1);
		}
	}

	void processUnbufferedMouseInput()
	{
		const OIS::MouseState &ms = mMouse->getMouseState();

        CCS::CameraControlSystem::CameraMode* cameraMode = mCameraCS->getCurrentCameraMode();
        String cameraModeName = mCameraCS->getCameraModeName(cameraMode);

        if(cameraModeName == "Free")
        {
            CCS::FreeCameraMode* freeCameraMode = (CCS::FreeCameraMode*)cameraMode;

			freeCameraMode->yaw(ms.X.rel);
            freeCameraMode->pitch(ms.Y.rel);
        }
        else if(cameraModeName == "RTS")
        {
            CCS::RTSCameraMode* rtsCameraMode = (CCS::RTSCameraMode*)cameraMode;

            Real borderWidthPercentage = 0.1; // 10%
            int leftBorder = ms.width * borderWidthPercentage;
            int rightBorder = ms.width - (ms.width * borderWidthPercentage);
            int topBorder = ms.height * borderWidthPercentage;
            int bottomBorder = ms.height - (ms.height * borderWidthPercentage);

            Widget* w = mTrayMgr->getWidget("zoomSlider");
            Ogre::Real bottomWidgetOverlays = w->getOverlayElement()->getTop() + w->getOverlayElement()->getHeight();
            Ogre::Real rightWidgetOverlays = w->getOverlayElement()->getWidth();

            if(ms.X.abs < leftBorder)
            {
                if(ms.Y.abs > bottomWidgetOverlays) // Avoid the widget area
                {
			        rtsCameraMode->goLeft((leftBorder - ms.X.abs) / (Real)leftBorder); // the closer to the border, the faster is the movement
                }
            }
            else if(ms.X.abs > rightBorder)
            {
			    rtsCameraMode->goRight((ms.X.abs - rightBorder) / (Real)leftBorder); // the closer to the border, the faster is the movement
            }

            if(ms.Y.abs < topBorder)
            {
                if(ms.X.abs > rightWidgetOverlays) // Avoid the widget area
                {
			        rtsCameraMode->goUp((topBorder - ms.Y.abs) / (Real)topBorder); // the closer to the border, the faster is the movement
                }
            }
            else if(ms.Y.abs > bottomBorder)
            {
			    rtsCameraMode->goDown((ms.Y.abs - bottomBorder) / (Real)topBorder); // the closer to the border, the faster is the movement
            }

            if(ms.Z.rel != 0)
            {
                rtsCameraMode->zoomIn(Math::Sign(ms.Z.rel)*2);
                ((Slider*)w)->setValue( rtsCameraMode->getZoom(), false);
            }
        }
	}

	void processPlayerKeyInput(const FrameEvent& evt)
	{
		if(! ((CheckBox*)mTrayMgr->getWidget("animationCheckBox"))->isChecked() )
        {
			Ogre::Real movingFactor = 300.0f;
			Ogre::Real rotatingFactor = 2.0f;

			if(mKeyboard->isKeyDown(OIS::KC_UP) || mKeyboard->isKeyDown(OIS::KC_I) )
				headNode->translate(evt.timeSinceLastFrame * movingFactor * Ogre::Vector3::UNIT_Z, Ogre::Node::TS_LOCAL);

			if(mKeyboard->isKeyDown(OIS::KC_DOWN) || mKeyboard->isKeyDown(OIS::KC_K) )
				headNode->translate(evt.timeSinceLastFrame * movingFactor * Ogre::Vector3::NEGATIVE_UNIT_Z, Ogre::Node::TS_LOCAL);

			if(mKeyboard->isKeyDown(OIS::KC_RIGHT) || mKeyboard->isKeyDown(OIS::KC_L) )
				headNode->yaw(Ogre::Radian(evt.timeSinceLastFrame * -rotatingFactor), Ogre::Node::TS_LOCAL);

			if(mKeyboard->isKeyDown(OIS::KC_LEFT) || mKeyboard->isKeyDown(OIS::KC_J) )
				headNode->yaw(Ogre::Radian(evt.timeSinceLastFrame * rotatingFactor), Ogre::Node::TS_LOCAL);
		}
	}

	void destroyScene()
	{
		mCameraCS->deleteAllCameraModes();
	}

	Ogre::Vector3 CustomCollisionDetectionFunction(Ogre::Vector3 cameraTargetPosition, Ogre::Vector3 cameraPosition)
	{
		// Here you have to implement your custom collision code.
		// The returning value is the desired camera position.
		// In this method you usually have to calculate (using OgreNewt, NxOgre, OgreODE, OgreBullet... code)
		// the first intersection between the camera target and the camera (in this order).

		return cameraPosition;
	}

protected:

	SceneNode *headNode ;
	SceneNode* atheneNode;
	AnimationState* mAnimState;

	CCS::CameraControlSystem* mCameraCS;

};

#endif
