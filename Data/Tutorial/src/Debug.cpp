#include "StdAfx.h"
#include "Debug.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

int	MakeDebugConsole()
{
#if defined _DEBUG
   AllocConsole();
   freopen("CONOUT$", "wb", stdout);
#endif
   
   return 0;
}

static const int	MAX_MSG	= 1000;

void DebugPrintf(const char* pFormat, ...)
{
#if defined(_DEBUG)
	char	caTemp[MAX_MSG];

	va_list list;
	va_start(list, pFormat);
	printf(pFormat, list);

	vsprintf(caTemp, pFormat, list);
	va_end(list);

	Ogre::LogManager::getSingletonPtr()->logMessage(caTemp);
#endif
}
