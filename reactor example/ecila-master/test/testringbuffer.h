#pragma once


#include <ecila/unittest.h>







US_ECILA


class TestRingBuffer
:	public UnitTest
{
public:

	TestRingBuffer(): UnitTest("TestRingBuffer") {}
	virtual ~TestRingBuffer() {}


private:

	virtual void Do();

};

