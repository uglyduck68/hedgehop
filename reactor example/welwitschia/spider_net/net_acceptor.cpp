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
		// �ж��Ƿ�򿪣�����Ѿ�������ش�����
		if ( IsOpen() )
		{
			return NET_ERR;
		}

		//����һ�������˿�
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

		//��(�˴����п��ܳ��ִ���)
		if(SOCKET_ERROR == ::bind(ListenSocket, (struct sockaddr *)&si, sizeof(si)) )
		{
			::closesocket( ListenSocket );

			return NetGetLastError();
		}

		//����
		INT iRet = NET_OK;
		if ( SOCKET_ERROR == ::listen(ListenSocket, 5) )
		{
			::closesocket( ListenSocket );

			iRet = ERR_LISTEN;
		}
		else
		{
			//�ɹ���������
			m_NetHandle = ListenSocket;
			m_LocalAddr = addr;
		}

		return iRet;
	}

	INT CNetAcceptor::Accept( CNetSession &NetSession )
	{
		// �ж��Ƿ����
		if ( !IsOpen() )
		{
			return NET_ERR;
		}

		NET_HANDLE AcceptSocket;
		int iOutLen = 0;
		sockaddr_in addr;
		memset(&addr, 0, sizeof(addr));
		iOutLen = sizeof(addr);

		//����
		AcceptSocket = ::accept(m_NetHandle, (struct sockaddr *)&addr, (socklen_t *)&iOutLen );

		int iRet = NET_OK;

		if ( INVALID_SOCKET != AcceptSocket )
		{
			// ���ܳɹ�
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
