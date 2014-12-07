/**
* @file		OceanTest.h
* @remarks		바다 특수효과를 테스트하기 위함.
*				MAX_WIDTH, MAX_HEIGHT, XSEGMENT, YSEGMENT 값에 따라
*				특수 효과가 이상하게 적용된다.
*/

#pragma once
#include "baseapplication.h"
#include "MaterialControls.h"

using namespace	Ogre;


///////////////////////////////////////////////////////////////////////////////
// WIDTH & HEIGHT, SEGMENT 값이 wave Fx 효과에 영향을 많이 미친다.
///////////////////////////////////////////////////////////////////////////////

#define	MAX_WIDTH		1000
#define	MAX_HEIGHT		1000

// SEGMENT 값이 높을 수록 너울이 부드럽게 디스플레이된다
#define	XSEGMENT		255		
#define	YSEGMENT		255

#define	MAX_MSL			20


class OceanTest :
	public BaseApplication
{
public:
	OceanTest(void);
	~OceanTest(void);

	Ogre::Entity*				m_pOceanEnt;
	Ogre::Plane					m_Plane;
	Ogre::SceneNode*			m_pOcean;

	Ogre::Real					m_MSL;

	static Ogre::Real GetSurface()
	{
		return MAX_MSL;
	}

	Ogre::Plane& GetPlane()
	{
		return m_Plane;
	}
	///////////////////////////////////////////////////////////////////////////
	// wave Fx
	///////////////////////////////////////////////////////////////////////////
	Ogre::MaterialPtr	  mActiveMaterial;
	Ogre::Pass*			  mActivePass;
	Ogre::GpuProgramPtr	  mActiveFragmentProgram;
	Ogre::GpuProgramPtr	  mActiveVertexProgram;
	Ogre::GpuProgramParametersSharedPtr mActiveFragmentParameters;
	Ogre::GpuProgramParametersSharedPtr mActiveVertexParameters;
	Real				  mRotateSpeed;
	
	ShaderControlsContainer    mShaderControlContainer;
    MaterialControlsContainer mMaterialControlsContainer;

	size_t					mCurrentMaterial;

	Real					m_fWaveFreq;	// 0 ~ 0.05
	Real					m_fWaveAmp;		// 0 ~ 25

	int ChangeFragmentVertexValue(int nIndex, Real& TargetValue, Real Value);

protected:
    virtual void createScene(void); // Override me!
    virtual bool keyPressed(const OIS::KeyEvent &arg);
    virtual bool keyReleased(const OIS::KeyEvent &arg);

};

