#include "testsocket.h"


#include <ecila/socket.h>








void TestSocket::SetUp()
{
	Socket::InitWinSock();
}






void TestSocket::TearDown()
{
	Socket::FiniWinSock();
}








void TestSocket::Do()
{
	testOpenAndClose();
	testConnection();
}






void TestSocket::testOpenAndClose()
{
	Socket s;

	assertEquals(TRUE, s.Open());
	assertEquals(TRUE, s.Close());
}






void TestSocket::testConnection()
{
	Socket svr, cli, tmp;

	assertEquals(TRUE, svr.Open());
	assertEquals(TRUE, svr.SetNonBlock(TRUE));
	assertEquals(TRUE, svr.Bind(8080, "127.0.0.1"));
	assertEquals(TRUE, svr.Listen(5));
	

	assertEquals(TRUE, cli.Open());
	assertEquals(TRUE, cli.SetNonBlock(TRUE));
	assertEquals(TRUE, cli.Connect("127.0.0.1", 8080));
	

	assertEquals(TRUE, svr.Accept(&tmp, 0, 0));


	assertEquals(TRUE, cli.Close());
	assertEquals(TRUE, tmp.Close());
	assertEquals(TRUE, svr.Close());
}

