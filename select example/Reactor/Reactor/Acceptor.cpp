#include "Acceptor.h"
#include "Log.h"

namespace X1
{
#ifdef	USE_TEMPLATE
	template<typename T>
	Acceptor<T>
#else
	Acceptor
#endif
		::Acceptor(void)
	{
		m_pSvc	= NULL;
	}


#ifdef	USE_TEMPLATE
	template<typename T>
	Acceptor<T>
#else
	Acceptor
#endif
		::~Acceptor(void)
	{
		this->HandleClose();
	}

#ifdef	USE_TEMPLATE
	template<typename T>
	int Acceptor<T>
#else
	int Acceptor
#endif
		::Open(NetAddr addr, Reactor* pReactor)
	{

		if ((m_h = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET) 
//		if ((m_h = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET) 
		{
			printf("WSASocket() failed with error %d\n", WSAGetLastError());

			return X1_FAIL;
		}
		else
			printf("WSASocket() is OK!\n");


		if (bind(GetHandle(), (PSOCKADDR) addr.GetAddr(), addr.GetSize()) == SOCKET_ERROR)
		{
			printf("bind() failed with error %d\n", WSAGetLastError());

			return X1_FAIL;
		}
		else
			printf("bind() is OK!\n");


		if (listen(GetHandle(), SOMAXCONN))
		{
			printf("listen() failed with error %d\n", WSAGetLastError());

			return X1_FAIL;
		}
		else
			printf("listen() is OK!\n");


		// Change the socket mode on the listening socket from blocking to
		// non-block so the application will not block waiting for requests

		u_long	NonBlock = 1;

		if (ioctlsocket(GetHandle(), FIONBIO, &NonBlock) == SOCKET_ERROR)
		{
			printf("ioctlsocket() failed with error %d\n", WSAGetLastError());

			return X1_FAIL;
		}
		else
			printf("ioctlsocket() is OK!\n");

		/// register accept event handler
		if (Reactor::GetInstance()->RegisterHandler(this, EventHandler::ACCEPT_MASK | EventHandler::CLOSE_MASK) != X1_OK)
		{
			LOG_FATAL("RegisterHandler fails\n");

			return X1_FAIL;
		}

		return X1_OK;
	}

	/// called when input event occur (e.g., connection or data)
#ifdef	USE_TEMPLATE
	template<typename T>
	int Acceptor<T>
#else
	int Acceptor
#endif
		::HandleRead(X1_SOCHANDLE h)
	{
		X1_SOCHANDLE		AcceptSocket;
		NetAddr			SocAddr;
		int				nAddrLeng = SocAddr.GetSize();

		/// accept the client and get client IP address
		if ((AcceptSocket = accept(GetHandle(), SocAddr.GetAddr(), &nAddrLeng)) != INVALID_SOCKET)
		{
			LOG_INFO("Accpet: Client is IP: %s, Port:%d\n", inet_ntoa(SocAddr), ntohs(SocAddr.GetPort()));

			// Set the accepted socket to non-blocking mode so the server will
			// not get caught in a blocked condition on WSASends

			u_long		NonBlock = 1;

			if (ioctlsocket(AcceptSocket, FIONBIO, &NonBlock) == SOCKET_ERROR)
			{

				printf("ioctlsocket(FIONBIO) failed with error %d\n", WSAGetLastError());

				return X1_FAIL;

			}
			else
				printf("ioctlsocket(FIONBIO) is OK!\n");

		}	// end of accept
		else
		{
			LOG_FATAL("accept fails\n");

			return X1_FAIL;
		}

		m_pSvc->SetHandle(AcceptSocket);

		/// register service event handler
		if (Reactor::GetInstance()->RegisterHandler(m_pSvc, EventHandler::ALL_EVENTS_MASK) < 0)
		{
			LOG_ERROR("RegisterHandler fails\n");

			return X1_FAIL;
		}


		return X1_OK;
	}

	/// called when output events are possible
#ifdef	USE_TEMPLATE
	template<typename T>
	int Acceptor<T>
#else
	int Acceptor
#endif
		::HandleWrite(X1_SOCHANDLE h)
	{
		return X1_OK;
	}

#ifdef	USE_TEMPLATE
	template<typename T>
	int Acceptor<T>
#else
	int Acceptor
#endif
		::HandleException(X1_SOCHANDLE h)
	{
		return X1_OK;
	}

#ifdef	USE_TEMPLATE
	template<typename T>
	int Acceptor<T>
#else
	int Acceptor
#endif
		::HandleClose(X1_SOCHANDLE h /*= INVALID_HANDLE*/, EVENT_MASK e /*= ALL_EVENTS_MASK*/)
	{
		return X1_OK;
	}

#ifdef	USE_TEMPLATE
	template<typename T>
	int Acceptor<T>
#else
	int Acceptor
#endif
		::HandleTimeout(const TimeValue& tv)
	{
		return X1_OK;
	}

}