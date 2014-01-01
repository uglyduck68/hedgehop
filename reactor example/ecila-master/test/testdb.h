#pragma once


#include <ecila/unittest.h>







US_ECILA


class TestDb
:	public UnitTest
{
public:

	TestDb(): UnitTest("TestDb") {}
	virtual ~TestDb() {}


private:

	virtual void Do();

};
