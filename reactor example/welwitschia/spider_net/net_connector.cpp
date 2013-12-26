#include "net_connector.h"

#include "net_error.h"

namespace wel
{
	namespace CNetConnector
	{
		INT  OpenByTcp( CNetSession &NetSession, const char *szIp, UINT16 uiPort )
		{
			if ( NULL == szIp )
			{
				return NET_ERR;
			}

			CNetAddr addr(szIp, uiPort);
			return OpenByTcp( NetSession, addr );
		}

		INT  OpenByTcp( CNetSession &NetSession, const CNetAddr &NetAddr )
		{
			struct sockaddr_in server;
			server.sin_addr.s_addr = inet_addr(NetAddr.GetStrAddress().c_str());
			server.sin_port        = htons(NetAddr.GetPort());
			server.sin_family      = AF_INET;

			INT iRetCode = NET_OK;

			//创建一个socket
			NET_HANDLE soc = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if( INVALID_SOCKET == soc )
			{
				iRetCode = ERR_CREATE_SOCKET;
			}

			//建立连接
			if( NET_OK == iRetCode &&
				SOCKET_ERROR == ::connect(soc, (sockaddr *)&server, sizeof(sockaddr)) )
			{
				::closesocket(soc);
				iRetCode = NetGetLastError();
			}
		
			//成功建立连接
			if( NET_OK == iRetCode )
			{
				NetSession.SetHandle( soc );
				NetSession.SetRemote( NetAddr );
			}

			return iRetCode;
		}
	}
}//end namespace(wel)
