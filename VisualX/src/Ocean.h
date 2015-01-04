#pragma once

#include "MaterialControls.h"

/** surface elevation that is defined for preventing z-fighting with terrain */
#define	MAX_MSL		20;

using namespace Ogre;
using namespace OgreBites;

#define		WAVEFX_INC		0
#define		WAVEFX_DEC		1

class COcean
{
protected:
	Ogre::Entity*				m_pOceanEnt;
	Ogre::Plane					m_Plane;
	Ogre::SceneNode*			m_pOcean;
    Ogre::SceneManager*         mSceneMgr;

	Ogre::Real					m_MSL;

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

public:
	int ChangeFragmentVertexValue(int nIndex, Real& TargetValue, Real Value);
	int ControlWaveFreq( int nInc, Real MultiConst );
	int ControlWaveAmp( int nInc, Real MultiConst );

public:
	COcean(Ogre::SceneManager*);
	~COcean(void);

	/**
	* create ocean entity
	*/
	void createScene();

	void setVisible(bool v)
	{
		m_pOcean->setVisible(v);
	}
	static const int	MAX_WIDTH	= 1000000;
	static const int	MAX_HEIGHT	= 1000000;

	/** max planes tesselation is 65536. max SEGMENT is 255. */
	static const int	XSEGMENT	= 1;
	static const int	YSEGMENT	= 1;

	
	/**
	*@function	Width
	*@brief		return the width of battle field
	*/
	int Width()
	{ 
		return MAX_WIDTH;
	}

	/**
	*@function	Height
	*@brief		return the width of battle field
	*/
	int Height()
	{
		return MAX_HEIGHT;
	}

	static Ogre::Real GetSurface()
	{
		return MAX_MSL;
	}

	Ogre::Plane& GetPlane()
	{
		return m_Plane;
	}

	/**
	* @function		isCollision
	* check the collision of Ray and ocean plane
	*/
	bool IsCollision( Ogre::Ray& ray, Ogre::Real* CollDist )
	{
		std::pair<bool, Ogre::Real>	ret;

		ret		= ray.intersects( GetPlane( ));

		if( ret.first )
			*CollDist	= ret.second;

		return ret.first;
	}
};

