#pragma once

/** surface elevation that is defined for preventing z-fighting with terrain */
#define	MAX_MSL		100;

class COcean
{
protected:
	Ogre::Entity*				m_pOceanEnt;
	Ogre::MovablePlane*			m_pPlane;
	Ogre::SceneNode*			m_pOcean;
    Ogre::SceneManager*         mSceneMgr;

	Ogre::Real					m_MSL;
public:
	COcean(Ogre::SceneManager*);
	~COcean(void);

	/**
	* create ocean entity
	*/
	void createScene();

	static const int	MAX_WIDTH	= 1000000;
	static const int	MAX_HEIGHT	= 1000000;

	/** max planes tesselation is 65536. max SEGMENT is 255. */
	static const int	XSEGMENT	= 255;
	static const int	YSEGMENT	= 255;

	
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

	Ogre::Real GetSurface()
	{
		return MAX_MSL;
	}
};

