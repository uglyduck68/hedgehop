#pragma once


#include <ecila/unittest.h>







US_ECILA


class TestNode
:	public UnitTest
{
public:

	TestNode(): UnitTest("TestNode") {}
	virtual ~TestNode() {}


private:

	virtual void Do();

};
