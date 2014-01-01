#include "testsession.h"

#include <ecila/session.h>








void TestSession::SetUp()
{
	Socket::InitWinSock();
}






void TestSession::TearDown()
{
	Socket::FiniWinSock();
}






void TestSession::Do()
{
}

