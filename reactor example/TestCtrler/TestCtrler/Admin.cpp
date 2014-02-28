// Admin.cpp: implementation of the CAdmin class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Admin.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdmin::CAdmin()
{

}

CAdmin::~CAdmin()
{

}

int CAdmin::SetReactor(ACE_Reactor* mRector)
{
	reactor(mRector);
	return 0;
}

int CAdmin::handle_exception (ACE_HANDLE fd /*= ACE_INVALID_HANDLE*/)
{
	reactor()->end_reactor_event_loop();
	return 0;
}

int CAdmin::handle_close (ACE_HANDLE handle,
                            ACE_Reactor_Mask close_mask)
{
	reactor()->remove_handler(this,close_mask);
	delete this;
	return 0;
}