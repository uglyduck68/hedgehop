#include "net_session.h"

#include "net_error.h"

namespace wel
{
	CNetSession::CNetSession()
	{
		m_NetHandle = INVALID_SOCKET;
	}

	CNetSession::~CNetSession()
	{
		Close();
	}

	INT CNetSession::Recv(void *pBuf, UINT uiSize, UINT uiSeconds)
	{
		struct timeval to;
		to.tv_usec = 0;
		to.tv_sec  = uiSeconds;

		INT iRet = NET_ERR;
		if( SOCKET_ERROR != ::setsockopt(m_NetHandle, SOL_SOCKET, SO_RCVTIMEO, (const char*)&to, sizeof(to)) )
		{
			iRet = ::recv( m_NetHandle, (char *)pBuf, uiSize, 0 );
			// «Â≥˝≥¨ ±…Ë÷√
			to.tv_sec = 0;
			::setsockopt(m_NetHandle, SOL_SOCKET, SO_RCVTIMEO, (const char*)&to, sizeof(to));
		}

		return iRet;
	}

	INT CNetSession::Recv(void *pBuf, UINT uiSize)
	{
		return ::recv( m_NetHandle, (char *)pBuf, uiSize, 0 );
	}

	INT CNetSession::Send(void *pBuf, UINT uiSize)
	{
		return ::send( m_NetHandle, (char *)pBuf, uiSize, 0 );
	}

	INT  CNetSession::Close()
	{
		if ( INVALID_SOCKET != m_NetHandle )
		{
			::shutdown( m_NetHandle, SD_BOTH );
			::closesocket( m_NetHandle );

			m_NetHandle = INVALID_SOCKET;
			m_RemoteAddr.Clear();
		}

		return NET_OK;
	}
}//end namespace(wel)
