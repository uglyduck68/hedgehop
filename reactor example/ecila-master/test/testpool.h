#pragma once


#include <ecila/unittest.h>







US_ECILA


class TestPool
:	public UnitTest
{
public:

	TestPool(): UnitTest("TestPool") {}
	virtual ~TestPool() {}


private:

	virtual void Do();

};
