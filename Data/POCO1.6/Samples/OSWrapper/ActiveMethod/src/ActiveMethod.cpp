//
// ActiveMethod.cpp
//
// $Id: //poco/1.4/Foundation/samples/ActiveMethod/src/ActiveMethod.cpp#1 $
//
// This sample demonstrates the ActiveMethod and ActiveResult classes.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//

#include "Wrapper/Config.h"
#include "Wrapper/Foundation/ActiveMethod.h"
#include "Wrapper/Foundation/ActiveResult.h"
#include <iostream>


using X1::ActiveMethod;
using X1::ActiveResult;


class ActiveMethodExample
{
public:
	struct AddArgs
	{
		int a;
		int b;
	};
	
	ActiveMethodExample():
		activeAdd(this, &ActiveMethodExample::activeAddImp)
	{
	}
	
	ActiveMethod<int, AddArgs, ActiveMethodExample> activeAdd;
	
private:
	int activeAddImp(const AddArgs& args)
	{
		return args.a + args.b;
	}
};


int main(int argc, char** argv)
{
	ActiveMethodExample example;
	
	ActiveMethodExample::AddArgs args = {1, 2};
	ActiveResult<int> result = example.activeAdd(args);
	result.wait();
	std::cout << result.data() << std::endl;
	
	return 0;
}
