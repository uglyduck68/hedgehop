#pragma once


#include <ecila/unittest.h>







US_ECILA


class TestTimer
:	public UnitTest
{
public:

	TestTimer(): UnitTest("TestTimer") {}
	virtual ~TestTimer() {}


private:

	virtual void Do();

};

