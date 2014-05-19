//#include "StdAfx.h"
#ifdef _WIN32
#include <Windows.h>
#endif

#include "OSAL.h"

OSAL::OSAL(void)
{
}

OSAL::~OSAL(void)
{
}

//////////////////////////////////////////////////////////////////////////
// Function: sleep
// Parameters:
//	nsec: second 
//////////////////////////////////////////////////////////////////////////
void	OSAL::sleep(int nsec)
{
#ifdef _WIN32
	Sleep(nsec * 1000); 
#else	// POSIX
	sleep(1); 
#endif
}