#pragma once


#include <ecila/unittest.h>







US_ECILA


class TestSession
:	public UnitTest
{
public:

	TestSession(): UnitTest("TestSession") {}
	virtual ~TestSession() {}


private:
	virtual void SetUp		();
	virtual void TearDown	();
	virtual void Do			();

};

