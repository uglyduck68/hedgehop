
#include <iostream>

#include "./Foundation/Notification.h"
#include "./Foundation/NotificationQueue.h"
#include "./Foundation/ThreadPool.h"
#include "./Foundation/Thread.h"
#include "./Foundation/Runnable.h"
#include "./Foundation/Mutex.h"
#include "./Foundation/Random.h"
#include "./Foundation/AutoPtr.h"

using X1::Notification;
using X1::NotificationQueue;
using X1::ThreadPool;
using X1::Thread;
using X1::Runnable;
using X1::FastMutex;
using X1::AutoPtr;


class WorkNotification: public Notification
{
public:
	typedef AutoPtr<WorkNotification> Ptr;
	
	WorkNotification(int data):
		_data(data)
	{
	}
	
	int data() const
	{
		return _data;
	}

private:
	int _data;
};


class Worker: public Runnable
	// A worker thread that gets work items
	// from a NotificationQueue.
{
public:
	Worker(const std::string& name, NotificationQueue& queue):
		_name(name),
		_queue(queue)
	{
	}
	
	void run()
	{
		Poco::Random rnd;
		for (;;)
		{
			Notification::Ptr pNf(_queue.waitDequeueNotification());
			if (pNf)
			{
				WorkNotification::Ptr pWorkNf = /*(AutoPtr<WorkNotification>)*/pNf.cast<WorkNotification>();

				if (pWorkNf)
				{
					{
						FastMutex::ScopedLock lock(_mutex);
						std::cout << _name << " got work notification " << pWorkNf->data() << std::endl;
					}
					Thread::sleep(rnd.next(200));
				}
			}
			else break;
		}
	}
	
private:
	std::string        _name;
	NotificationQueue& _queue;
	static FastMutex   _mutex;
};


FastMutex Worker::_mutex;


int main(int argc, char** argv)
{
	NotificationQueue queue;
	
	// create some worker threads
	Worker worker1("Worker 1", queue);
	Worker worker2("Worker 2", queue);
	Worker worker3("Worker 3", queue);

	// start worker threads
	ThreadPool::defaultPool().start(worker1);
	ThreadPool::defaultPool().start(worker2);
	ThreadPool::defaultPool().start(worker3);

	// distribute some work
	for (int i = 0; i < 50; ++i)
	{
		queue.enqueueNotification(new WorkNotification(i));
	}
	
	// wait until queue is empty and all threads are 
	// waiting for new work.
	while (!queue.empty()) Thread::sleep(200);
	Thread::sleep(500);
	
	// stop all worker threads
	queue.wakeUpAll();
	ThreadPool::defaultPool().joinAll();
	
	return 0;
}
