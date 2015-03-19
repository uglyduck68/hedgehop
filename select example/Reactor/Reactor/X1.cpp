#include	"X1.h"

namespace X1
{
	int Lib::Init()
	{
#if	defined(_X1_WINDOWS_)
	WSADATA		wsaData;
	int			Ret;

	if ((Ret = WSAStartup(0x0202, &wsaData)) != 0)
	{
		return X1_ENETINIT;
	}

#elif defined(_X1_LINUX_)
#endif
		return X1_OK;
	}

	int Lib::Fin()
	{
		WSACleanup();

		return X1_OK;
	}
}