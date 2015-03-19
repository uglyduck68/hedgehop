/**
 * @file ThreadPool.h
 * @brief	Thread Pool implementation for unix / linux environments
 * @author	Shobhit Gupta
 * @version
 * @date	2008
 * @copyright	see <http://www.gnu.org/licenses/>
 */


/* Improvements
 *
 * 1. add function to terminate all threads
 * 2. add function to wait for the end of all threads
 *
 */
#pragma once


#include <iostream>
#include <vector>

#include "semaphore.h"
#include "Mutex.h"

NS_X1_USE

using namespace std;


/**
 * WorkerThread class
 * This class needs to be sub classed by the user.
 */
class WorkerThread
{
public:
    int id;

    virtual void* Run()	= 0;

    WorkerThread(int id) : id(id) {}
    virtual ~WorkerThread(){}

};


/**
 * ThreadPool class manages all the ThreadPool related activities. 
 * This includes keeping track of idle threads and synchronizations between all threads.
 */
class ThreadPool
{
public:
    ThreadPool();
    ThreadPool(int maxThreadsTemp);
    virtual ~ThreadPool();
	
	void DestroyPool(int maxPollSecs);

    bool AssignWork(WorkerThread *worker);
    bool FetchWork(WorkerThread **worker);

	void InitializeThreads();
	
    
private:
     static void *ThreadExecute(void *param);
    
    static /*thread_mutex_t*/Mutex mutexSync;
	static /*thread_mutex_t*/Mutex mutexWorkCompletion;

	int m_nMaxThreads;

	// # of available works
    Semaphore			availableWork;

	// # of available threads in queue
    Semaphore			availableThreads;

	// thread queue
    vector<WorkerThread *>	WorkerQueue;
	vector<thread_t>		WorkerIDQueue;

    int m_nTopIndex;
    int m_nBottomIndex;
	
	int m_nIncompleteWork;

    
    int m_nQueueSize;

};





