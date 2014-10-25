#pragma once

/** surface elevation that is defined for preventing z-fighting with terrain */
#define	MAX_MSL		20;

class COcean
{
protected:
	Ogre::Entity*				m_pOceanEnt;
	Ogre::Plane					m_Plane;
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

