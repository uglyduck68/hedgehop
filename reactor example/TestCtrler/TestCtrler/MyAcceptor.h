// MyAcceptor.h: interface for the CMyAcceptor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYACCEPTOR_H__B3009691_125A_4F20_A64A_9E8D92A52BAD__INCLUDED_)
#define AFX_MYACCEPTOR_H__B3009691_125A_4F20_A64A_9E8D92A52BAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ace\Reactor.h"
#include "ace\Event_Handler.h"
#include "ace\SOCK_Acceptor.h"
#include "MyClient.h"

class CMyAcceptor :public ACE_Event_Handler
{
public:
	int SetReactor(ACE_Reactor* mRector);
	int open(const char* mAddr);
	CMyAcceptor();
	virtual ~CMyAcceptor();

protected:
	virtual ACE_HANDLE get_handle (void) const;
	virtual int handle_input (ACE_HANDLE fd = ACE_INVALID_HANDLE);
    virtual int handle_close (ACE_HANDLE handle,
                            ACE_Reactor_Mask close_mask);

protected:

	ACE_SOCK_Acceptor acceptor_; 




};

#endif // !defined(AFX_MYACCEPTOR_H__B3009691_125A_4F20_A64A_9E8D92A52BAD__INCLUDED_)
