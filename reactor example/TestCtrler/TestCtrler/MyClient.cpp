// MyClient.cpp: implementation of the CMyClient class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyClient.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyClient::CMyClient()
{

}

CMyClient::~CMyClient()
{

}

int CMyClient::SetReactor(ACE_Reactor* mRector)
{
	reactor(mRector);
	return reactor()->register_handler(this,ACE_Event_Handler::READ_MASK);
}

ACE_HANDLE CMyClient::get_handle (void) const
{
	return peer.get_handle();
}

int CMyClient::handle_input (ACE_HANDLE fd /*= ACE_INVALID_HANDLE*/)
{
	char buf[256];
	
	int nsize=peer.recv(buf,256);
	buf[nsize]=0;

	if(nsize==0){return -1;}
	MessageBox(NULL,buf,"Client Data",MB_OK);	
	return 0;
}

int CMyClient::handle_close (ACE_HANDLE handle,
                            ACE_Reactor_Mask close_mask)
{
	reactor()->remove_handler(this,close_mask);
	delete this;
	MessageBox(NULL,"Client Close","Client Close",MB_OK);
	return 0;
}