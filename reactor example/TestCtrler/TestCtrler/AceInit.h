// AceInit.h: interface for the CAceInit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACEINIT_H__C6EB6682_EB79_4B78_B9EC_C3B1E53BC4CE__INCLUDED_)
#define AFX_ACEINIT_H__C6EB6682_EB79_4B78_B9EC_C3B1E53BC4CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ace\ACE.h"
#include "ace\INET_Addr.h"
#include "ace\SOCK_Connector.h"
#include "ace\SOCK_Stream.h"


#pragma comment(lib,"ACE.lib")

class CAceInit  
{
public:
	CAceInit();
	virtual ~CAceInit();

};

#endif // !defined(AFX_ACEINIT_H__C6EB6682_EB79_4B78_B9EC_C3B1E53BC4CE__INCLUDED_)
