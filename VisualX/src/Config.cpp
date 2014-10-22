#include "StdAfx.h"
#include "..\include\Config.h"


CConfig::CConfig(void)
{
}


CConfig::~CConfig(void)
{
}

int CConfig::LoadModels(Ogre::ConfigFile::SettingsMultiMap *settings)
{
    Ogre::String typeName, archName;
       
	Ogre::ConfigFile::SettingsMultiMap::iterator i;

    for (i = settings->begin(); i != settings->end(); ++i)
    {
        typeName = i->first;
        archName = i->second;

		if( typeName == "ownship" )
			m_strOwnship	= archName;
		else if( typeName == "ship" )
			m_vecShip.push_back( archName );
		else if( typeName == "fighter" )
			m_vecFighter.push_back( archName );
		else if( typeName == "missile" )
			m_vecMissile.push_back( archName );
		else
			// error logging
			DebugPrintf("Error: LoadModels read wrong type name('%s')", typeName.c_str());

    }

	return true;
}

int CConfig::LoadIntroview(ConfigFile::SettingsMultiMap *settings)
{
    Ogre::String typeName, archName;
       
	Ogre::ConfigFile::SettingsMultiMap::iterator i;

    for (i = settings->begin(); i != settings->end(); ++i)
    {
        typeName = i->first;
        archName = i->second;

		if( typeName == "modelplaytime" )
			m_nModelPlaytime	= atoi( archName.c_str());
		else if( typeName == "modelchangetime" )
			m_nModelBreaktime	= atoi( archName.c_str());
		else
			// error logging
			DebugPrintf("Error: LoadIntroview read wrong type name('%s')", typeName.c_str());
    }

	return true;
}


/* resource file format 
*[Essential]
*Zip=../../Media/packs/SdkTrays.zip
*/

int CConfig::Load( const String& filename )
{
	Ogre::ConfigFile		cf;

	cf.load( filename );

    // Go through all sections & settings in the file
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

    Ogre::String secName, typeName, archName;

    while (seci.hasMoreElements())
    {
        secName = seci.peekNextKey();

        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        Ogre::ConfigFile::SettingsMultiMap::iterator i;

		if( secName == "model" )
		{
			LoadModels( settings );
		}
		else if( secName == "introview" )
		{
			LoadIntroview( settings );
		}
    }
	return true;
}