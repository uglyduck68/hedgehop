#pragma once

/*
* configuration class that has configuration informations
*/

//using namespace Ogre;
using namespace	std;

const int	MAX_TARGETS	= 50;

class CConfig
{
protected:

	Ogre::String					m_strOwnship;

	std::vector<Ogre::String>		m_vecShip;
	std::vector<Ogre::String>		m_vecFighter;
	std::vector<Ogre::String>		m_vecMissile;

	int						m_nModelPlaytime;
	int						m_nModelBreaktime;

	int LoadModels(Ogre::ConfigFile::SettingsMultiMap *settings);
	int LoadIntroview(Ogre::ConfigFile::SettingsMultiMap *settings);
public:
	CConfig(void);
	~CConfig(void);

	int Load( const Ogre::String& filename );
};

