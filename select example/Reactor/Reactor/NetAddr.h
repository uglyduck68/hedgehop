#pragma once

#include	"X1.h"

/**
 * @class	NetAddr
 * @brief	NetAddr class encapsulates Internet address structure
 */
class NetAddr 
{
	private:
		struct sockaddr_in m_Addr; //IPv4 structure

	public:
		NetAddr(uint16_t port)
		{
			memset(&m_Addr, 0x00, sizeof(m_Addr));
			
			m_Addr.sin_family		= AF_INET;
			m_Addr.sin_port			= htons(port);
			m_Addr.sin_addr.s_addr	= INADDR_ANY; //listen on all interfaces
		}

		NetAddr(uint16_t port, uint32_t addr) 
		{
			memset(&m_Addr, 0x00, sizeof(m_Addr));

			m_Addr.sin_family		= AF_INET; //choose Internet address
			m_Addr.sin_port			= htons(port);
			m_Addr.sin_addr.s_addr	= htonl(addr); //listen on a particular interfaces
		}

		uint16_t GetPort() 
		{
			return m_Addr.sin_port;
		}

		uint32_t GetIpAddr() 
		{
			return m_Addr.sin_addr.s_addr;
		}

		struct sockaddr* GetAddr() const
		{
			//return reinterpret_cast<struct sockaddr*> (&m_Addr);
			return (struct sockaddr*)&m_Addr;
		}

		int/*socklen_t*/ GetSize() const 
		{
			return sizeof(m_Addr);
		}
};
