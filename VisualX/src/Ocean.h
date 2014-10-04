#pragma once
class Ocean
{
protected:
	Ogre::Entity*				m_pOceanEnt;
    Ogre::SceneManager*         mSceneMgr;

public:
	Ocean(Ogre::SceneManager*);
	~Ocean(void);

	/**
	* create ocean entity
	*/
	void createScene();

	static const int	MAX_WIDTH	= 1000;//000;
	static const int	MAX_HEIGHT	= 1000;//000;
};

