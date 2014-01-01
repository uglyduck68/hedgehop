#pragma once


#include "ipaddrs.h"






NS_ECILA_START

class DECL_SPEC_DLL Socket
{
private:

	enum SOCK_OPTION
	{
		SOCK_TCP	= 1 << 0, 
		SOCK_UDP	= 1 << 1,
		SOCK_SYNC	= 1 << 2,
		SOCK_ASYNC	= 1 << 3,
	};

	int32_t			mode_;
	int32_t			status_;
	socket_t		sock_;
	IPAddrs			ipaddr_;

	bool_t	IsValidSockMode();
	int32_t	TranslateSockMode();


public:

	enum SOCK_MODE 
	{
		SOCK_SYNC_TCP	= SOCK_TCP | SOCK_SYNC,
		SOCK_SYNC_UDP	= SOCK_UDP | SOCK_SYNC,
		SOCK_ASYNC_TCP	= SOCK_TCP | SOCK_ASYNC,
		SOCK_ASYNC_UDP	= SOCK_UDP | SOCK_ASYNC,
	};

	enum SOCK_STATUS
	{
		STATUS_NONE			= 0,
		STATUS_OPENED		= 1 << 0,
		STATUS_CONNECTED	= 1 << 1,
		STATUS_CLOSED		= 1 << 2,
	};

	enum SOCK_ERR
	{
		ERR_NONE        = 0,
		ERR_TRANSFER    = -1,
		ERR_TIMEOUT     = -2,
	};

	 Socket(SOCK_MODE mode = SOCK_SYNC_TCP);
	~Socket();

	bool_t	Mode				(SOCK_MODE mode);
	int32_t Mode				();

	bool_t	Status				(SOCK_STATUS flag);
	int32_t Status				();

	bool_t Open					();
	bool_t Bind					(uint16_t port, const char_t *ip = 0);
	bool_t Listen				(uint16_t backlog);
	bool_t Accept				(Socket* sock, char_t *buffer = 0, overlapped_t *overlapped_info = 0);
	bool_t Connect				(const char_t *ip, uint16_t port);
	bool_t Connect				(const char_t *ip, uint16_t port, int32_t timeout_msec);
	bool_t Disconnect			(overlapped_t *overlapped_info);
	bool_t Close				();


	bool_t SetReUseAddr			(bool_t flag);
	bool_t SetLinger			(bool_t flag, uint16_t sec);
	bool_t SetNonBlock			(bool_t flag);
	bool_t SetNoDelay			(bool_t flag);
	bool_t SetConditionalAccept	(bool_t flag);
	bool_t SetUpdateAcceptContext(Socket *listen_sock /* listen socket */);


	bool_t SetSendBuffSize		(uint32_t size);
	bool_t SetRecvBuffSize		(uint32_t size);
	bool_t GetSendBuffSize		(uint32_t &size);
	bool_t GetRecvBuffSize		(uint32_t &size);
	

	int32_t SendAll				(char_t *buff, int32_t size);
	int32_t RecvAll				(char_t *buff, int32_t size);
	int32_t Send				(char_t *buff, int32_t size, wsabuf_t *wsabuf = 0, overlapped_t *overlapped_info = 0);
	int32_t Recv				(char_t *buff, int32_t size, wsabuf_t *wsabuf = 0, overlapped_t *overlapped_info = 0);
	int32_t SendTo				(char_t *buff, int32_t size, IPAddrs &addr, void *overlapped_info = 0);
	int32_t RecvFrom			(char_t *buff, int32_t size, IPAddrs &addr, void *overlapped_info = 0);


	socket_t&	GetSocket		();
	int32_t		GetSockMode		();
	IPAddrs*	GetIpAddrs		();

	static bool_t InitWinSock();
	static bool_t FiniWinSock();
};

NS_ECILA_END

