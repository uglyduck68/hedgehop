#include "net_acceptor.h"

#include "net_error.h"

#include <memory.h>

namespace wel
{
	CNetAcceptor::CNetAcceptor()
	{
		m_NetHandle = INVALID_SOCKET;
	}

	CNetAcceptor::~CNetAcceptor()
	{
		Close();
	}

	INT CNetAcceptor::Open( const char *szIp, UINT16 uiPort )
	{
		if (  NULL == szIp )
		{
			return NET_ERR;
		}

		CNetAddr addr(szIp ,uiPort);

		return Open( addr );
	}

	INT CNetAcceptor::Open( const CNetAddr &addr )
	{
		// 判断是否打开，如果已经打错，返回错误码
		if ( IsOpen() )
		{
			return NET_ERR;
		}

		//创建一个监听端口
		NET_HANDLE ListenSocket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		if( INVALID_SOCKET == ListenSocket)
		{
			return ERR_CREATE_SOCKET;
		}

		sockaddr_in si;
		memset(&si, 0, sizeof(si));
		si.sin_family      = AF_INET;
		si.sin_port        = ::htons( addr.GetPort() );
		si.sin_addr.s_addr = addr.GetIntAddress();

		//绑定(此处最有可能出现错误)
		if(SOCKET_ERROR == ::bind(ListenSocket, (struct sockaddr *)&si, sizeof(si)) )
		{
			::closesocket( ListenSocket );

			return NetGetLastError();
		}

		//监听
		INT iRet = NET_OK;
		if ( SOCKET_ERROR == ::listen(ListenSocket, 5) )
		{
			::closesocket( ListenSocket );

			iRet = ERR_LISTEN;
		}
		else
		{
			//成功创建监听
			m_NetHandle = ListenSocket;
			m_LocalAddr = addr;
		}

		return iRet;
	}

	INT CNetAcceptor::Accept( CNetSession &NetSession )
	{
		// 判断是否打开了
		if ( !IsOpen() )
		{
			return NET_ERR;
		}

		NET_HANDLE AcceptSocket;
		int iOutLen = 0;
		sockaddr_in addr;
		memset(&addr, 0, sizeof(addr));
		iOutLen = sizeof(addr);

		//接受
		AcceptSocket = ::accept(m_NetHandle, (struct sockaddr *)&addr, (socklen_t *)&iOutLen );

		int iRet = NET_OK;

		if ( INVALID_SOCKET != AcceptSocket )
		{
			// 接受成功
			NetSession.SetSelf( m_LocalAddr );
			NetSession.SetRemote( CNetAddr(addr.sin_addr.s_addr, addr.sin_port) );
			NetSession.SetHandle( AcceptSocket );
		}
		else
		{
			iRet = ERR_ACCEPT;
		}

		return iRet;
	}

	INT CNetAcceptor::Close()
	{
		if ( INVALID_SOCKET != m_NetHandle )
		{
			::closesocket( m_NetHandle );

			m_NetHandle = INVALID_SOCKET;
			m_LocalAddr.Clear();
		}

		return NET_OK;
	}
}//end namespace(wel)
