//
// Activity.cpp
//
// $Id: //poco/1.4/Foundation/samples/Activity/src/Activity.cpp#1 $
//
// This sample demonstrates the Activity class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//

#include "Wrapper/Config.h"
#include "Wrapper/Foundation/Activity.h"
#include "Wrapper/Foundation/Thread.h"
#include <iostream>


using X1::Activity;
using X1::Thread;


class ActivityExample
{
public:
	ActivityExample():
		_activity(this, &ActivityExample::runActivity)
	{
	}
	
	void start()
	{
		_activity.start();
	}
	
	void stop()
	{
		_activity.stop();
		_activity.wait();
	}

protected:
	void runActivity()
	{
		while (!_activity.isStopped())
		{
			std::cout << "Activity running." << std::endl;
			X1::Thread::sleep(250);
		}
		std::cout << "Activity stopped." << std::endl;
	}
	
private:
	Activity<ActivityExample> _activity;
};


int main(int argc, char** argv)
{
	ActivityExample example;
	example.start();
	X1::Thread::sleep(2000);
	example.stop();

	example.start();
	example.stop();

	return 0;
}
