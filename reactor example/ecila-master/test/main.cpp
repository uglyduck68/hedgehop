#include "main.h"


#include <ecila/unittestsuite.h>


// test case
#include "testipaddrs.h"
#include "testsocket.h"
#include "testtimer.h"
#include "testpool.h"
#include "testsession.h"
#include "testnode.h"
#include "testtokenizer.h"
#include "testdb.h"
#include "testringbuffer.h"




int32_t main(int32_t argc, char_t* argv[])
{
	UnitTestSuite suite("Infra UnitTestSuite");
//	suite.Register(new TestIPAddrs());
//	suite.Register(new TestSocket());
//	suite.Register(new TestTimer());
//	suite.Register(new TestPool());
	suite.Register(new TestDb());
//	suite.Register(new TestSession());
//	suite.Register(new TestNode());
//	suite.Register(new TestTokenizer());
//	suite.Register(new TestRingBuffer());
	suite.Run();

	return 0;
}

