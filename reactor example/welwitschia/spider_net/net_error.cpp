#include "net_error.h"

namespace wel
{
	INT  NetGetLastError()
	{
		INT  iErrorCode = NET_ERR;

	#ifdef OS_WIN32
		iErrorCode = WSAGetLastError();
		switch( iErrorCode )
		{
		case WSAEADDRNOTAVAIL:
			iErrorCode = ERR_INVALID_ADDRESS;
			break;

		case WSAECONNREFUSED:
			iErrorCode = ERR_REMOTE_REFUSE;
			break;

		case WSAEADDRINUSE:
			iErrorCode = ERR_PORT_IN_USE;
			break;
		}//end switch
	#else
		iErrorCode = errno;
		switch( iErrorCode )
		{
		case ECONNREFUSED:
			iErrorCode = ERR_REMOTE_REFUSE;
			break;

		case 99:
			iErrorCode = ERR_INVALID_ADDRESS;
			break;

		case 98:
			iErrorCode = ERR_PORT_IN_USE;
			break;
		}//end switch
	#endif

		return iErrorCode;
	}

#ifdef OS_LINUX
	INT  NetOpenGetLastError()
	{
		INT  iErrorCode = NET_ERR;

		iErrorCode = errno;
		switch( iErrorCode )
		{
		case 99:
			iErrorCode = ERR_INVALID_ADDRESS;
			break;

		case 98:
			iErrorCode = ERR_PORT_IN_USE;
			break;
		}//end switch

		return iErrorCode;
	}
#endif
}//end namespace(wel)

