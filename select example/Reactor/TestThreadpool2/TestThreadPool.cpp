/**
 * @file TestThreadPool.cpp
 * @brief	Thread Pool test program
 * @author	Shobhit Gupta
 * @version
 * @date	2008
 * @copyright	see <http://www.gnu.org/licenses/>
 */

#include "stdafx.h"
#include "X1.h"
//#include "pthread.h"
//
//
//#ifdef	WIN32
//#include <Windows.h>
//#elif defined(LINUX)
//#endif

#include <iostream>
#include "threadpool.h"

using namespace std;


#define ITERATIONS 200

// user-defined thread function
typedef void*(*THREADFUNC)(void* pArg);

class SampleWorkerThread : public WorkerThread
{
public:
//	int id;

	virtual void* Run()
	{
		// C-style thread function
		if (m_pFunc)
			return (*m_pFunc)(m_pArg);

#ifdef	WIN32
//		Sleep(2000);

		for (int i = 0; i < 2000; i++)
		{
//			cout << id << ": loop count is " << i << endl;
		}
#elif defined(LINUX)
		sleep(2);
#endif
		// if you use message queue, then I block on this API like GetItemFromMessageQueue(). 
		// So synchronization of threads is achieved !!!

		cout << "I(" << id << ") worked for 2 seconds\n";

		return 0;
	}

	// for C-style thread
	THREADFUNC	m_pFunc;
	void*		m_pArg;

	void Set(THREADFUNC pFunc, void* pArg)
	{
		m_pFunc		= pFunc;
		m_pArg		= pArg;
	}

	SampleWorkerThread(int id) : WorkerThread(id), m_pFunc(NULL), m_pArg(NULL)
	{
	}

	~SampleWorkerThread()
	{
	}
};


int main(int argc, char **argv)
{
	//ThreadPool(N);
	//Create a Threadpool with N number of threads
	ThreadPool* myPool = new ThreadPool(25);


	//We will count time elapsed after initializeThreads()
	time_t t1	= time(NULL);

	//Lets start bullying ThreadPool with tonnes of work !!!
	for(unsigned int i = 0;i < ITERATIONS; i++)
	{
		SampleWorkerThread* myThread = new SampleWorkerThread(i);
		cout << "myThread[" << myThread->id << "] = [" << myThread << "]" << endl;
		myPool->AssignWork(myThread);
	}

	// destroyPool(int maxPollSecs)
	// Before actually destroying the ThreadPool, this function checks if all the pending work is completed.
	// If the work is still not done, then it will check again after maxPollSecs
	// The default value for maxPollSecs is 2 seconds.
	// And of course the user is supposed to adjust it for his needs.

	myPool->DestroyPool(2);

	time_t t2	= time(NULL);
	cout << t2-t1 << " seconds elapsed. start time is " << t1 << ". end time is " << t2 << endl;

	delete myPool;

	return 0;
}


#if 0
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
#endif

