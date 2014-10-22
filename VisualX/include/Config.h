#pragma once

/*
* configuration class that has configuration informations
*/

using namespace Ogre;
using namespace	std;

const int	MAX_TARGETS	= 50;

class CConfig
{
protected:

	String					m_strOwnship;

	std::vector<String>		m_vecShip;
	std::vector<String>		m_vecFighter;
	std::vector<String>		m_vecMissile;

	int						m_nModelPlaytime;
	int						m_nModelBreaktime;

	int LoadModels(ConfigFile::SettingsMultiMap *settings);
	int LoadIntroview(ConfigFile::SettingsMultiMap *settings);
public:
	CConfig(void);
	~CConfig(void);

	int Load( const String& filename );
};

