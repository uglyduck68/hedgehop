#pragma once

class COcean
{
protected:
	Ogre::Entity*				m_pOceanEnt;
    Ogre::SceneManager*         mSceneMgr;

public:
	COcean(Ogre::SceneManager*);
	~COcean(void);

	/**
	* create ocean entity
	*/
	void createScene();

	static const int	MAX_WIDTH	= 1000000;
	static const int	MAX_HEIGHT	= 1000000;
	static const int	XSEGMENT	= 200;
	static const int	YSEGMENT	= 200;

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
};

