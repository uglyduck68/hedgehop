#pragma once

#include	"X1.h"

#include <assert.h>

/**
 * @class	NetAddr
 * @brief	NetAddr class encapsulates Internet address structure
 */
NS_X1_START

	class DECL_SPEC_DLL NetAddr 
	{
		private:
			struct sockaddr_in m_Addr; //IPv4 structure

			void	Init()
			{
				memset(&m_Addr, 0x00, sizeof(m_Addr));
			}
		public:
			NetAddr()
			{
				Init();
			}

			NetAddr(uint16_t port)
			{
				Init();
			
				m_Addr.sin_family		= AF_INET;
				m_Addr.sin_port			= htons(port);
				m_Addr.sin_addr.s_addr	= INADDR_ANY; //listen on all interfaces
			}

			NetAddr(uint16_t port, uint32_t addr) 
			{
				Init();

				m_Addr.sin_family		= AF_INET; //choose Internet address
				m_Addr.sin_port			= htons(port);
				m_Addr.sin_addr.s_addr	= htonl(addr); //listen on a particular interfaces
			}

			int		SetAddr(X1_SOCHANDLE h)
			{
				int		nAddrLength	= GetSize();

				if (getpeername(h, (SOCKADDR*)&m_Addr, &nAddrLength) != 0)
					return X1_FAIL;

				assert(nAddrLength == sizeof(m_Addr));

				return X1_OK;
			}

			uint16_t GetPort() 
			{
				return m_Addr.sin_port;
			}

			uint32_t GetIpAddr() 
			{
				return m_Addr.sin_addr.s_addr;
			}

			operator in_addr()
			{
				return m_Addr.sin_addr;
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

NS_X1_END