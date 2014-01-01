#include "socket.h"








US_ECILA

Socket::Socket(SOCK_MODE mode)
:	mode_		(mode),
	status_		(STATUS_NONE),
	sock_		(INVALID_SOCKET)
{
}






Socket::~Socket()
{
}






bool_t Socket::IsValidSockMode()
{
	return (mode_ < SOCK_SYNC_TCP || mode_ > SOCK_ASYNC_UDP) ? FALSE : TRUE;
}






int32_t Socket::TranslateSockMode()
{
	return (mode_ == SOCK_SYNC_TCP || mode_ == SOCK_ASYNC_TCP) ? SOCK_STREAM : SOCK_DGRAM;
}








bool_t Socket::Mode(SOCK_MODE mode)
{
	mode_ = mode;
	return TRUE;
}








int32_t Socket::Mode()
{
	return mode_;
}








bool_t Socket::Status(SOCK_STATUS flag)
{
	status_ = flag;
	return TRUE;
}








int32_t Socket::Status()
{
	return status_;
}







bool_t Socket::Open()
{
	bool_t ret = FALSE;

	ret = IsValidSockMode();
	if(!ret) { ECILA_TRACE(); return FALSE; }

	#ifdef OS_WINDOWS
	if(mode_ & SOCK_ASYNC)
	{
		//reused socker handle
		if(sock_ != INVALID_SOCKET) { return TRUE; }

		sock_ = WSASocket(AF_INET, TranslateSockMode(), IPPROTO_TCP, 0, 0, WSA_FLAG_OVERLAPPED);
	}
	else
	{
		sock_ = socket(AF_INET, TranslateSockMode(), 0);
	}
	#else
	sock_ = socket(AF_INET, TranslateSockMode(), 0);
	#endif
	if(sock_ < 0 || sock_ == INVALID_SOCKET) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}






bool_t Socket::Bind(uint16_t port, const char_t *ip)
{
	bool_t ret = FALSE;

	ret = SetReUseAddr(TRUE);
	if(!ret) { ECILA_TRACE(); return FALSE; }


	sockaddr_in *addr = ipaddr_.IpAddr();
	if(!addr) { ECILA_TRACE(); return FALSE; }

	if(!ip)
	{
		ret = ipaddr_.Init(ip, port);
		if(!ret) { ECILA_TRACE(); return FALSE; }
	}
	else
	{
		addr->sin_family      = AF_INET;
		addr->sin_addr.s_addr = htonl(INADDR_ANY);
		addr->sin_port        = htons(port);
	}


	if(bind(sock_, (const sockaddr *)addr, sizeof(struct sockaddr_in)) != 0)
	{
		ECILA_TRACE();

		return FALSE;
	}

	return TRUE;
}






bool_t Socket::Listen(uint16_t backlog)
{
	if(mode_ & SOCK_UDP) { ECILA_TRACE(); return FALSE; }

	if(listen(sock_, backlog) < 0) { ECILA_TRACE(); return FALSE; }

	return TRUE;
}







bool_t Socket::Accept(Socket* sock, char_t *buffer, overlapped_t *overlapped_info)
{
	if(mode_ & SOCK_UDP) { ECILA_TRACE(); return FALSE; }


	int32_t len = sizeof(struct sockaddr_in);
	sockaddr_in *addr = sock->ipaddr_.IpAddr();
	if(!addr) { ECILA_TRACE(); return FALSE; }
	

	#ifdef OS_WINDOWS
	if(mode_ & SOCK_ASYNC)
	{
		ulong_t nbytes = 0;

		if(!overlapped_info) { ECILA_TRACE(); return FALSE; }

		bool_t ret = AcceptEx(sock_,
						  sock->sock_,
						  buffer,
						  0,
						  sizeof( struct sockaddr_in ) + 16,
						  sizeof( struct sockaddr_in ) + 16,
						  &nbytes,
						  overlapped_info);
		if(!ret)
		{
			int32_t wsa_last_errno = WSAGetLastError();
			if( wsa_last_errno != ERROR_IO_PENDING &&
				wsa_last_errno != ERROR_SUCCESS ) { ECILA_TRACE(); return FALSE; }
		}

		return TRUE;
	}
	else
	{
		sock->sock_ = accept(sock_, (sockaddr *)addr, &len);
		if(sock->sock_ == INVALID_SOCKET ) { ECILA_TRACE(); return FALSE; }
	}
	#else
	sock->sock_ = accept(sock_, (sockaddr *)addr, (socklen_t *)&len);
	if(sock->sock_ < 0 ) { ECILA_TRACE(); return FALSE; }
	#endif

	return TRUE;
}






bool_t Socket::Connect(const char_t *ip, uint16_t port)
{
	bool_t ret = FALSE;

	sockaddr_in *addr = ipaddr_.IpAddr();
	if(!addr) { ECILA_TRACE(); return FALSE; }
	
	ret = ipaddr_.Init(ip, port);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	if(connect(sock_, (const sockaddr*)addr, sizeof(struct sockaddr_in)) < 0)
	{
		ECILA_TRACE();

		return FALSE;
	}

	return TRUE;
}








bool_t Socket::Connect(const char_t *ip, uint16_t port, int32_t timeout_msec)
{
	bool_t  ret  = FALSE;
	int32_t iret = 0;

	sockaddr_in *addr = ipaddr_.IpAddr();
	if(!addr) { ECILA_TRACE(); return FALSE; }
	
	ret = ipaddr_.Init(ip, port);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = SetNonBlock(TRUE);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	iret = connect(sock_, (const sockaddr*)addr, sizeof(struct sockaddr_in));
	if(iret < 0)
	{
		#ifdef OS_WINDOWS
		int32_t wsa_last_errno = WSAGetLastError();
		if(wsa_last_errno != WSAEWOULDBLOCK)		return FALSE;
		#else
		if(errno != EAGAIN && errno != EWOULDBLOCK)	return FALSE;
		#endif
	}

#ifdef OS_WINDOWS
#pragma warning(push)
#pragma warning(disable : 4127)
#endif

	fd_set rset, wset, eset;
	FD_ZERO(&rset); FD_ZERO(&wset); FD_ZERO(&eset);
	FD_SET(sock_, &rset); FD_SET(sock_, &wset); FD_SET(sock_, &eset);

#ifdef OS_WINDOWS
#pragma warning(pop)
#endif

	struct timeval timeout;
	timeout.tv_sec	=  timeout_msec / 1000;
	timeout.tv_usec = (timeout_msec % 1000) * 1000;

	iret = select(sock_ + 1, &rset, &wset, &eset, ((timeout_msec < 0) ? NULL : &timeout));
	if     (iret <  0) { ECILA_TRACE(); return FALSE; }
	else if(iret == 0) { return FALSE; }
	else
	{
		if(FD_ISSET(sock_, &eset)) { return FALSE; }

		if(FD_ISSET(sock_, &rset) || FD_ISSET(sock_, &wset)) { return TRUE; }

		return FALSE;
	}
}






bool_t Socket::Disconnect(overlapped_t *overlapped_info)
{
	#ifdef OS_WINDOWS

	if(!overlapped_info) { ECILA_TRACE(); return FALSE; }


	bool_t  ret = FALSE;
	int32_t iret = 0;

	if(status_ != STATUS_NONE)
	{
		iret = shutdown(sock_, SD_BOTH);
		if(iret != 0)
		{
			int32_t wsa_last_errno = WSAGetLastError();
			ECILA_ERROR(("[Socket::Disconnect] shutdown() : %d\n", wsa_last_errno));
			return FALSE;
		}
	}	

	ret = TransmitFile(sock_,
					   NULL,
					   0,
					   0,
					   overlapped_info,
					   NULL,
					   TF_DISCONNECT | TF_REUSE_SOCKET);
	if(!ret)
	{
		int32_t wsa_last_errno = WSAGetLastError();
		if(wsa_last_errno != ERROR_IO_PENDING)
		{ 
			ECILA_PRINT(("[Socket::Disconnect] TransmitFile() %d\n", wsa_last_errno));
			return FALSE;
		}
	}
	#endif

	return TRUE;
}








bool_t Socket::Close()
{
	int32_t ret = 0;

	#ifdef OS_WINDOWS
	ret = shutdown(sock_, SD_BOTH);
	if(ret != 0)
	{
		int32_t wsa_last_errno = WSAGetLastError();
		ECILA_ERROR(("[Socket::Close] shutdown() : %d\n", wsa_last_errno));
		return FALSE;
	}

	ret = closesocket(sock_);
	if(ret != 0)
	{
		int32_t wsa_last_errno = WSAGetLastError();
		ECILA_ERROR(("[Socket::Close] closesocket() : %d\n", wsa_last_errno));
		return FALSE;
	}
	#else
	ret = shutdown(sock_, SHUT_RDWR);
	if(ret != 0)
	{
		ECILA_ERROR(("[Socket::Close] shutdown() : %d\n", errno));
		return FALSE;
	}

	ret = close(sock_);
	if(ret != 0)
	{
		ECILA_ERROR(("[Socket::Close] closesocket() : %d\n", errno));
		return FALSE;
	}
	#endif

	sock_ = INVALID_SOCKET;
	return TRUE;
}








bool_t Socket::SetReUseAddr(bool_t flag)
{
	int32_t value = (flag == TRUE ? 1 : 0);

	#ifdef OS_WINDOWS
	if(setsockopt(sock_, SOL_SOCKET, SO_REUSEADDR,
		(const char_t*)&value, sizeof(value)) < 0 )
	{
		ECILA_TRACE();

		return FALSE;
	}
	#else
	if(setsockopt(sock_, SOL_SOCKET, SO_REUSEADDR,
		(const void*)&value, (socklen_t)sizeof(value)) < 0 )
	{
		ECILA_TRACE();

		return FALSE;
	}
	#endif

	return TRUE;
}








bool_t Socket::SetLinger(bool_t flag, uint16_t sec)
{
	struct linger value;

	value.l_onoff	= (flag == TRUE ? 1 : 0);
	value.l_linger	= sec;

	#ifdef OS_WINDOWS
	if(setsockopt(sock_, SOL_SOCKET, SO_LINGER,
		(const char_t*)&value, sizeof(value)) < 0)
	{
		ECILA_TRACE();

		return FALSE;
	}
	#else
	if(setsockopt(sock_, SOL_SOCKET, SO_LINGER,
		(const void*)&value, (socklen_t)sizeof(value)) < 0)
	{
		ECILA_TRACE();

		return FALSE;
	}
	#endif
	return TRUE;
}








bool_t Socket::SetNonBlock(bool_t flag)
{
	#ifdef OS_WINDOWS
	ulong_t value = (flag == TRUE ? 1 : 0 );
	if(ioctlsocket(sock_, FIONBIO, &value) != 0 ) { ECILA_TRACE(); return FALSE; }
	#else
	int32_t value = fcntl(sock_, F_GETFL);
	if( value < 0 ) { ECILA_TRACE(); return FALSE; }

	if(flag == TRUE)	value |=  O_NONBLOCK;
	else				value &= ~O_NONBLOCK;

	if(fcntl(sock_, F_SETFL, value) < 0) { ECILA_TRACE(); return FALSE; }
	#endif

	return TRUE;
}








bool_t Socket::SetNoDelay(bool_t flag)
{
	int32_t value = (flag == TRUE ? 1 : 0);

	#ifdef OS_WINDOWS
	if(setsockopt(sock_, IPPROTO_TCP, TCP_NODELAY,
		(const char_t*)&value, sizeof(value)) < 0)
	{
		ECILA_TRACE();

		return FALSE;
	}
	#else
	if(setsockopt(sock_, IPPROTO_TCP, TCP_NODELAY,
		(const void*)&value, (socklen_t)sizeof(value)) < 0)
	{
		ECILA_TRACE();

		return FALSE;
	}
	#endif

	return TRUE;
}








bool_t Socket::SetConditionalAccept(bool_t flag)
{
	#ifdef OS_WINDOWS
	int32_t value = (flag == TRUE ? 1 : 0);
	if(setsockopt(sock_, SOL_SOCKET, SO_CONDITIONAL_ACCEPT,
		(const char_t *)&value, sizeof(value)) < 0)
	{
		ECILA_TRACE();

		return FALSE;
	}
	#endif

	return TRUE;
}







bool_t Socket::SetUpdateAcceptContext(Socket *listen_sock)
{
	#ifdef OS_WINDOWS
	int32_t ret = 0;

	ret = setsockopt(sock_, SOL_SOCKET, SO_UPDATE_ACCEPT_CONTEXT, 
			(char *)&listen_sock->sock_, sizeof(listen_sock->sock_));
	if(ret < 0) { ECILA_TRACE(); return FALSE; }
	#endif

	return TRUE;
}








bool_t Socket::SetSendBuffSize(uint32_t size)
{
	#ifdef OS_WINDOWS
	if(setsockopt(sock_, SOL_SOCKET, SO_SNDBUF,
		(const char_t *)&size, sizeof(size)) < 0)
	{
		ECILA_TRACE();

		return FALSE;
	}
	#else
	if(setsockopt(sock_, SOL_SOCKET, SO_SNDBUF,
		(const void *)&size, (socklen_t)sizeof(size)) < 0)
	{
		ECILA_TRACE();

		return FALSE;
	}
	#endif

	return TRUE;
}








bool_t Socket::SetRecvBuffSize(uint32_t size)
{
	#ifdef OS_WINDOWS
	if(setsockopt(sock_, SOL_SOCKET, SO_RCVBUF,
		(const char_t *)&size, sizeof(size)) < 0)
	{
		ECILA_TRACE();

		return FALSE;
	}
	#else
	if(setsockopt(sock_, SOL_SOCKET, SO_RCVBUF,
		(const void *)&size, (socklen_t)sizeof(size)) < 0)
	{
		ECILA_TRACE();

		return FALSE;
	}
	#endif

	return TRUE;
}








bool_t Socket::GetSendBuffSize(uint32_t &size)
{
	int32_t len = sizeof(int32_t);
	#ifdef OS_WINDOWS
	if(getsockopt(sock_, SOL_SOCKET, SO_SNDBUF,
		(char_t *)&size, (int32_t *)&len) < 0)
	{
		ECILA_TRACE();

		return FALSE;
	}
	#else
	if(getsockopt(sock_, SOL_SOCKET, SO_SNDBUF,
		(void *)&size, (socklen_t *)&len) < 0)
	{
		ECILA_TRACE();

		return FALSE;
	}
	#endif

	return TRUE;
}








bool_t Socket::GetRecvBuffSize(uint32_t &size)
{
	int32_t len = sizeof(int32_t);
	#ifdef OS_WINDOWS
	if(getsockopt(sock_, SOL_SOCKET, SO_RCVBUF,
		(char_t *)&size, (int32_t *)&len) < 0)
	{
		ECILA_TRACE();

		return FALSE;
	}
	#else
	if(getsockopt(sock_, SOL_SOCKET, SO_RCVBUF,
		(void *)&size, (socklen_t *)&len) < 0)
	{
		ECILA_TRACE();

		return FALSE;
	}
	#endif

	return TRUE;
}








int32_t Socket::SendAll(char_t *buff, int32_t size)
{
	int32_t total = 0;

	while(total < size)
	{
		int32_t result = Send(&buff[total], size - total);
		if(result < 0) { return -1;	}

		total += result;
	}

	return total;
}








int32_t Socket::RecvAll(char_t *buff, int32_t size)
{
	int32_t total = 0;

	while(total < size)
	{
		int32_t result = Recv(&buff[total], size - total);
		if(result < 0) { return -1; }

		total += result;
	}

	return 0;
}








int32_t Socket::Send(char_t* buff, int32_t size, wsabuf_t *wsabuf, overlapped_t *overlapped_info)
{
	int32_t result = 0;

	if(mode_ & SOCK_ASYNC)
	{
		#ifdef OS_WINDOWS
		
		if(!overlapped_info) { ECILA_TRACE(); return FALSE; }

		wsabuf->buf		= buff;
		wsabuf->len		= size;
		ulong_t nbytes	= 0;

		result = WSASend(sock_,
						 wsabuf,
						 1,
						 &nbytes,
						 0,
						 overlapped_info,
						 0);
		if(result == SOCKET_ERROR)
		{
			int32_t wsa_last_errno = WSAGetLastError();
			if( wsa_last_errno != ERROR_IO_PENDING &&
				wsa_last_errno != ERROR_SUCCESS ) { return ERR_TRANSFER; }
		}

		result = nbytes;
		#else
		return -1;
		#endif
	}
	else
	{
		result = send(sock_, buff, size, 0);
		if(result == 0) { return ERR_TRANSFER; }
		if(result < 0)
		{
			#ifdef OS_WINDOWS
			int32_t wsa_last_errno = WSAGetLastError();
			if(wsa_last_errno == WSAEWOULDBLOCK)		return ERR_NONE;
			else										return ERR_TRANSFER;
			#else
			if(errno == EAGAIN || errno == EWOULDBLOCK)	return ERR_NONE;
			else										return ERR_TRANSFER;
			#endif
		}
	}

	return result;
}








int32_t Socket::Recv(char_t *buff, int32_t size, wsabuf_t *wsabuf, overlapped_t *overlapped_info)
{
	int32_t result = 0;

	if(mode_ & SOCK_ASYNC)
	{
		#ifdef OS_WINDOWS

		if(!overlapped_info) { ECILA_TRACE(); return FALSE; }

		wsabuf->buf		= buff;
		wsabuf->len		= size;
		ulong_t nbytes	= 0;
		ulong_t flag	= 0;

		result = WSARecv(sock_,
						 wsabuf,
						 1,
						 &nbytes,
						 &flag,
						 overlapped_info,
						 0);
		if(result == SOCKET_ERROR)
		{
			int32_t wsa_last_errno = WSAGetLastError();
			if( wsa_last_errno != ERROR_IO_PENDING &&
				wsa_last_errno != ERROR_SUCCESS ) { return ERR_TRANSFER; }
		}

		result = nbytes;
		#else
		return -1;
		#endif
	}
	else
	{
		result = recv(sock_, buff, size, 0);
		if(result == 0) { return ERR_TRANSFER; }
		if(result < 0)
		{
			#ifdef OS_WINDOWS
			int32_t wsa_last_errno = WSAGetLastError();
			if(wsa_last_errno == WSAEWOULDBLOCK)		return ERR_NONE;
			else										return ERR_TRANSFER;
			#else
			if(errno == EAGAIN || errno == EWOULDBLOCK)	return ERR_NONE;
			else										return ERR_TRANSFER;
			#endif
		}
	}

	return result;
}






int32_t Socket::SendTo(char_t *buff, int32_t size, IPAddrs &addr, void *overlapped_info)
{
	sockaddr_in *ipadr = addr.IpAddr();
	int32_t addr_len = sizeof(*ipadr);

	#ifdef OS_WINDOWS
	int32_t result = sendto(sock_, buff, size, 0, (const sockaddr *)ipadr, addr_len);
	#else
	int32_t result = sendto(sock_, buff, size, 0, (sockaddr *)ipadr, (socklen_t)addr_len);
	#endif

	if(result < 0)
	{
		#ifdef OS_WINDOWS
		int32_t wsa_last_errno = WSAGetLastError();
		if(wsa_last_errno == WSAEWOULDBLOCK)		return 0;
		else										return -1;
		#else
		if(errno == EAGAIN || errno == EWOULDBLOCK)	return 0;
		else										return -1;
		#endif
	}

	return result;
}






int32_t Socket::RecvFrom(char_t *buff, int32_t size, IPAddrs &addr, void *overlapped_info)
{
	sockaddr_in *ipadr = addr.IpAddr();
	int32_t addr_len = sizeof(*ipadr);

	#ifdef OS_WINDOWS
	int32_t result = recvfrom(sock_, buff, size, 0, (sockaddr *)ipadr, &addr_len);
	#else
	int32_t result = recvfrom(sock_, buff, size, 0, (sockaddr *)ipadr, (socklen_t *)&addr_len);
	#endif

	if(result < 0)
	{
		#ifdef OS_WINDOWS
		int32_t wsa_last_errno = WSAGetLastError();
		if(wsa_last_errno == WSAEWOULDBLOCK)		return 0;
		else										return -1;
		#else
		if(errno == EAGAIN || errno == EWOULDBLOCK)	return 0;
		else										return -1;
		#endif
	}

	return result;
}






socket_t& Socket::GetSocket()
{
	return sock_;
}






int32_t Socket::GetSockMode()
{
	return mode_;
}






IPAddrs* Socket::GetIpAddrs()
{
	return &ipaddr_;
}







bool_t Socket::InitWinSock()
{
	#ifdef OS_WINDOWS
	WSADATA wsaData;

	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) { ECILA_TRACE(); return FALSE; }
	#endif

	return TRUE;
}






bool_t Socket::FiniWinSock()
{
	#ifdef OS_WINDOWS
	if( WSACleanup() != 0 ) { ECILA_TRACE(); return FALSE; }
	#endif

	return TRUE;
}

