#pragma once

#include "ace/INET_Addr.h"

class Option
{
public:
	Option(void);
	~Option(void);

	int		LoadConfiguration(char* pcPath);
	int				m_nClientNum;		// number of clients
	ACE_INET_Addr	m_ClientIP[256];	// addr of clients
	int		m_nTestDuration;	// 시험 시간 (초)
	int		m_nPayLoad;			// packet payload (Byte)
};

