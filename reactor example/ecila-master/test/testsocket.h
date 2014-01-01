#pragma once


#include <ecila/unittest.h>







US_ECILA

class TestSocket
:	public UnitTest
{
public:

	TestSocket(): UnitTest("TestSocket") {}
	virtual ~TestSocket() {}


private:

	virtual void SetUp		();
	virtual void TearDown	();
	virtual void Do			();


	void testOpenAndClose	();
	void testConnection		();



};

