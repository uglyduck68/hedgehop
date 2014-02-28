// Admin.h: interface for the CAdmin class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADMIN_H__5A9860E2_2C95_4430_8171_4D4102E4A708__INCLUDED_)
#define AFX_ADMIN_H__5A9860E2_2C95_4430_8171_4D4102E4A708__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ace\Reactor.h"
#include "ace\Event_Handler.h"


class CAdmin :public ACE_Event_Handler
{
public:
	CAdmin();
	virtual ~CAdmin();

	int SetReactor(ACE_Reactor* mRector);
protected:
	virtual int handle_exception (ACE_HANDLE fd = ACE_INVALID_HANDLE);
	virtual int handle_close (ACE_HANDLE handle,
		ACE_Reactor_Mask close_mask);

};

#endif // !defined(AFX_ADMIN_H__5A9860E2_2C95_4430_8171_4D4102E4A708__INCLUDED_)
