// MyClient.h: interface for the CMyClient class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCLIENT_H__EB4F56A6_59AD_4379_819C_D1883951D4CD__INCLUDED_)
#define AFX_MYCLIENT_H__EB4F56A6_59AD_4379_819C_D1883951D4CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ace\Reactor.h"
#include "ace\SOCK_Stream.h"
#include "ace\Event_Handler.h"

class CMyClient:public ACE_Event_Handler  
{
public:
	CMyClient();
	virtual ~CMyClient();

    ACE_SOCK_Stream& get_peer(){return peer;}

	int SetReactor(ACE_Reactor* mRector);

protected:
	ACE_HANDLE get_handle (void) const;
	virtual int handle_input (ACE_HANDLE fd = ACE_INVALID_HANDLE);
	virtual int handle_close (ACE_HANDLE handle,
                            ACE_Reactor_Mask close_mask);

protected:
	ACE_SOCK_Stream peer;


};

#endif // !defined(AFX_MYCLIENT_H__EB4F56A6_59AD_4379_819C_D1883951D4CD__INCLUDED_)
