#include "./Foundation/ActiveMethod.h"
#include "./Foundation/ActiveResult.h"
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
