#include "ipaddrs.h"







US_ECILA

IPAddrs::IPAddrs()
{
	memset(ip_,    0, sizeof(ip_));
	memset(&addr_, 0, sizeof(addr_));
}








IPAddrs::~IPAddrs()
{
}







bool_t IPAddrs::Init(const char_t *ip, uint16_t port)
{

#ifdef OS_WINDOWS

	uint32_t ipdata = inet_addr(ip);
	if(ipdata == INADDR_NONE)
	{
		if(ecila_strncmp(ip, "255.255.255.255", IPAddrs::MAX_IP_LEN) != 0)
		{
			ECILA_TRACE();
			return FALSE;
		}
	}

	addr_.sin_family      = AF_INET;
	addr_.sin_addr.s_addr = ipdata;
	addr_.sin_port        = htons(port);

	ecila_strncpy(ip_, ip, IPAddrs::MAX_IP_LEN);

#else

	int32_t ret = inet_aton(ip, (struct in_addr *)&addr_);
	if(ret == 0)
	{
		ECILA_TRACE();
		return FALSE;
	}

	addr_.sin_family = AF_INET;
	addr_.sin_port   = htons(port);
	ecila_strncpy(ip_, ip, IPAddrs::MAX_IP_LEN);

#endif

	return TRUE;
}








bool_t IPAddrs::Init(uint32_t ip, uint16_t port)
{
	addr_.sin_family		= AF_INET;
	addr_.sin_addr.s_addr	= htonl(ip);
	addr_.sin_port			= htons(port);

	if(ip == INADDR_NONE)
	{
		ecila_strncpy(ip_, "255.255.255.255", IPAddrs::MAX_IP_LEN);
	}
	else
	{
		struct in_addr in;
		in.s_addr = ip;

		ecila_strncpy(ip_, inet_ntoa(in), IPAddrs::MAX_IP_LEN);
	}

	return TRUE;
}






bool_t IPAddrs::Init(sockaddr_in *addr)
{
	if(!addr) { ECILA_TRACE(); return false; }

	uint32_t ip = addr->sin_addr.s_addr;
	memcpy(&addr_, addr, sizeof(sockaddr_in));

	if(ip == INADDR_NONE)
	{
		ecila_strncpy(ip_, "255.255.255.255", IPAddrs::MAX_IP_LEN);
	}
	else
	{
		struct in_addr in;
		in.s_addr = ip;

		ecila_strncpy(ip_, inet_ntoa(in), IPAddrs::MAX_IP_LEN);
	}

	return TRUE;
}








const char_t* IPAddrs::Ip()
{
	return ip_;
}








uint16_t IPAddrs::Port()
{
	return ntohs(addr_.sin_port);
}








sockaddr_in* IPAddrs::IpAddr()
{
	return &addr_;
}








bool_t IPAddrs::GetHostsByName(const char_t* host, IPAddrs *addrs, int32_t &count)
{
	COMPILE_LOG("gethostbyname -> getaddrinfo");

	if(!host) { ECILA_TRACE(); return FALSE; }

	hostent *ent = gethostbyname(host);
	if(!ent) { ECILA_TRACE(); return FALSE; }

	for(int32_t i=0; ent->h_addr_list[i]; i++)
	{
		addrs[i].Init(inet_ntoa(*(struct in_addr*)ent->h_addr_list[i]), htons(0));
		count++;
	}

	return TRUE;
}

