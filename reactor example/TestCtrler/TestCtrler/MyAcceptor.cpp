// MyAcceptor.cpp: implementation of the CMyAcceptor class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyAcceptor.h"
#include "ace/INET_Addr.h" 
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyAcceptor::CMyAcceptor()
{

}

CMyAcceptor::~CMyAcceptor()
{

}

int CMyAcceptor::open(const char *mAddr)
{
	return acceptor_.open(ACE_INET_Addr(mAddr));
}

int CMyAcceptor::SetReactor(ACE_Reactor* mRector)
{
	reactor(mRector);
	return reactor()->register_handler(this,ACE_Event_Handler::ACCEPT_MASK);
}

ACE_HANDLE CMyAcceptor::get_handle (void) const
{
	return acceptor_.get_handle();
}

int CMyAcceptor::handle_input (ACE_HANDLE fd /*= ACE_INVALID_HANDLE*/)
{
	CMyClient* mClient;
	mClient= new CMyClient;

	if( acceptor_.accept(mClient->get_peer()) ==-1){
		delete mClient;
		return 0;
	}
	if (mClient->SetReactor(reactor()) ==-1){delete mClient;}	
	return 0;
}

int CMyAcceptor::handle_close (ACE_HANDLE handle,
                            ACE_Reactor_Mask close_mask)
{
	reactor()->remove_handler(this,close_mask);
	delete this;
	return 0;
}