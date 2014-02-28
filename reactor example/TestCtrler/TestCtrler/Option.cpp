#include "StdAfx.h"
#include "Option.h"
#include "Error.h"

Option::Option(void)
{
}


Option::~Option(void)
{
}

int		Option::LoadConfiguration(char* pcPath)
{
	char	caErrMsg[256];

	if ((m_nClientNum = GetPrivateProfileInt("client", "number", 0, pcPath)) == 0)
	{
		sprintf(caErrMsg, "Error: fail to read %s", pcPath);

		Error::Set(caErrMsg);

		return -1;
	}
	else
	{
		char	caItem[256];
		char	caIp[256];
		DWORD	dwRet;

		for (int i = 1; i <= m_nClientNum; i++)
		{
			sprintf(caItem, "client%d", i);

			if ((dwRet = GetPrivateProfileString(caItem, "ip", 0, caIp, 256, pcPath)) == 0)
			{
				Error::Set("Error: fail to read ip(%s)", caItem);
				return -1;
			}

			if ((dwRet = GetPrivateProfileInt(caItem, "port", 0, pcPath)) == 0)
			{
				Error::Set("Error: fail to read port(%d)", caItem);
				return -1;
			}

			// set IP & port
			m_ClientIP[i].set(htons(dwRet), inet_addr(caIp));
		}
	}

	return 0;
}
