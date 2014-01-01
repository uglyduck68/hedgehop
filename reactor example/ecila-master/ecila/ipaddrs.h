#pragma once


#include "ecila.h"






NS_ECILA_START

class DECL_SPEC_DLL IPAddrs
{
public:
	enum ENUM_MAX { MAX_IP_LEN = 15, };


private:
	char_t			ip_[MAX_IP_LEN + 1];
	sockaddr_in		addr_;


public:
	 IPAddrs();
	~IPAddrs();

	bool_t			Init(const char_t *ip,  uint16_t port);
	bool_t			Init(uint32_t ip,		uint16_t port);
	bool_t			Init(sockaddr_in *addr);
	const char_t*	Ip();
	uint16_t		Port();
	sockaddr_in*	IpAddr();

	static bool_t	GetHostsByName(const char_t* host, IPAddrs *addrs, int32_t &count);

};

NS_ECILA_END

