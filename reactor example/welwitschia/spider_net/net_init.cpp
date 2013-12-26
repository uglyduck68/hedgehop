#include "net_init.h"

namespace wel
{
	CSocketInit::CSocketInit()
	{
	#ifdef OS_WIN32
		// ≥ı ºªØWS2_32.dll
		WSADATA wsaData;
		::WSAStartup(MAKEWORD(2, 2), &wsaData);
	#endif
	}

	CSocketInit::~CSocketInit()
	{
	#ifdef OS_WIN32
		::WSACleanup();
	#endif
	}
}//namespace(wel)
