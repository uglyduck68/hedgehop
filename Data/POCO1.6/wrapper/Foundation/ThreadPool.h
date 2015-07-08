#ifndef X1_ThreadPool_INCLUDED
#define X1_ThreadPool_INCLUDED


#include "../../Foundation/include/Poco/ThreadPool.h"


namespace X1 {

class ThreadPool : public Poco::ThreadPool
{
public:
	ThreadPool(int minCapacity = 2,
		int maxCapacity = 16,
		int idleTime = 60,
		int stackSize = POCO_THREAD_STACK_SIZE) : Poco::ThreadPool(minCapacity, maxCapacity, idleTime, stackSize)
		{}

	ThreadPool(const std::string& name,
		int minCapacity = 2,
		int maxCapacity = 16,
		int idleTime = 60,
		int stackSize = POCO_THREAD_STACK_SIZE) : Poco::ThreadPool(name, minCapacity, maxCapacity, idleTime, stackSize)
		{}

	virtual ~ThreadPool()
	{}


private:
	ThreadPool(const ThreadPool& pool)
	{}
	ThreadPool& operator = (const ThreadPool& pool)
	{}

};



} // namespace X1


#endif // Foundation_ThreadPool_INCLUDED
