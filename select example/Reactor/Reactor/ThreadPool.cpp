/**
 * @file ThreadPool.cpp
 * @brief	Thread Pool implementation for unix / linux environments
 * @author	Shobhit Gupta
 * @version
 * @date	2008
 * @copyright	see <http://www.gnu.org/licenses/>
 */


#include "X1.h"

#include <stdlib.h>
#include "threadpool.h"

using namespace std;

Mutex ThreadPool::mutexSync;
Mutex ThreadPool::mutexWorkCompletion;



ThreadPool::ThreadPool()
{
	ThreadPool(2);
}

ThreadPool::ThreadPool(int maxThreads)
{
   if (maxThreads < 1)  
	   maxThreads	= 1;
     
   mutexSync.Lock();

   this->m_nMaxThreads		= maxThreads;
   this->m_nQueueSize		= maxThreads;

   WorkerQueue.resize(maxThreads, NULL);
   WorkerIDQueue.resize(maxThreads);
   
   m_nTopIndex				= 0;
   m_nBottomIndex			= 0;
   m_nIncompleteWork		= 0;

   availableWork.Init(0, 0);
   availableThreads.Init(0, m_nQueueSize);
   
   mutexSync.Unlock();

   // create threads for pool
   InitializeThreads();
}

void ThreadPool::InitializeThreads()
{
	for(int i = 0; i < m_nMaxThreads; ++i)
	{
		pthread_t tempThread;

		pthread_create(&tempThread, NULL, &ThreadPool::ThreadExecute, (void *) this);

		// detach the thread for resource release without pthread_join
		pthread_detach(tempThread);

		WorkerIDQueue[i]	= tempThread;
	}

}

ThreadPool::~ThreadPool()
{
   WorkerQueue.clear();
   WorkerIDQueue.clear();
}



void ThreadPool::DestroyPool(int maxPollSecs = 2)
{
	// polling loop to wait for all threads to complete
	while( m_nIncompleteWork > 0 )
	{
		cout << "Work is still incomplete=" << m_nIncompleteWork << endl;
#ifdef	WIN32
		Sleep(maxPollSecs*1000);
#elif defined(LINUX)
		sleep(maxPollSecs);
#endif
	}

	if (availableWork.Destroy() != X1_OK)
	{
		// sem_destroy fails. errno is [EINVAL], [ENOSYS], [EBUSY]
		cout << "Error: sem_destroy(availableWork) fails. errno is " << errno << endl;

		// The value of semaphore get to under the zero in Windows pthread library
		int		sval;

		if (availableWork.GetValue(&sval) != X1_OK)
			cout << "\tError: sem_getvalue fails." << endl;
		else
			cout << "\tavailableWork is " << sval << endl;

	}

	if (availableThreads.Destroy() != X1_OK)
	{
		// sem_destroy fails. errno is [EINVAL], [ENOSYS], [EBUSY]
		cout << "Error: sem_destroy(availableThreads) fails. errno is " << errno << endl;
	}

	int		ecode	= 0;

    if ((ecode = mutexSync.Destroy()) != X1_OK)
	{
		// ecode is [EBUSY], [EINVAL]
		cout << "Error: pthread_mutex_destroy(mutexSync) fails. errno is " << ecode << endl;
	}

    if ((ecode = mutexWorkCompletion.Destroy()) != X1_OK)
	{
		// ecode is [EBUSY], [EINVAL]
		cout << "Error: pthread_mutex_destroy(mutexWorkCompletion) fails. errno is " << ecode << endl;
	}

}

/**
 * Assign the worker to thread queue
 */
bool ThreadPool::AssignWork(WorkerThread *workerThread)
{
	int		rc	= 0;

	if ((rc = mutexWorkCompletion.Lock()) != X1_OK)
	{
		cout << "Error: pthread_mutex_lock fails. file is " << __FILE__ << "line no is " <<  __LINE__ << endl;
		return false;
	}

	m_nIncompleteWork++;

	if ((rc = mutexWorkCompletion.Unlock()) != X1_OK)
	{
		cout << "Error: pthread_mutex_unlock fails. file is " << __FILE__ << "line no is " <<  __LINE__ << endl;
		return false;
	}

	// wait if no available threads
	if (availableThreads.Wait() != X1_OK)
	{
		cout << "Error: sem_wait(availableThreads) fails. errno is " << errno << " file is " << __FILE__ << "line no is " <<  __LINE__ << endl;
		return false;
	}

	if ((rc = mutexSync.Lock()) != X1_OK)
	{
		cout << "Error: pthread_mutex_lock fails. file is " << __FILE__ << "line no is " <<  __LINE__ << endl;
		return false;
	}

	WorkerQueue[m_nTopIndex] = workerThread;
	
	if(m_nQueueSize != 1 )
		m_nTopIndex = (m_nTopIndex+1) % m_nQueueSize;

	if (availableWork.Post() != X1_OK)
	{
		cout << "Error: sem_post(availableWork) fails. errno is " << errno << " file is " << __FILE__ << "line no is " <<  __LINE__ << endl;
		return false;
	}

	if ((rc = mutexSync.Unlock()) != X1_OK)
	{
		cout << "Error: pthread_mutex_unlock fails. file is " << __FILE__ << "line no is " <<  __LINE__ << endl;
		return false;
	}

	return true;
}

bool ThreadPool::FetchWork(WorkerThread **workerArg)
{
	int		rc	= 0;

	// wait the available work 
	if (availableWork.Wait() != X1_OK)
	{
		cout << "Error: sem_wait fails. errno is " << errno << " file is " << __FILE__ << "line no is " <<  __LINE__ << endl;
		return false;
	}

	if ((rc = mutexSync.Lock()) != X1_OK)
	{
		cout << "Error: pthread_mutex_lock fails. file is " << __FILE__ << "line no is " <<  __LINE__ << endl;
		return false;
	}

	WorkerThread * workerThread = WorkerQueue[m_nBottomIndex];

	// delete work from queue
	WorkerQueue[m_nBottomIndex]	= NULL;

//	pthread_t		t = {(void*)-1, NULL};
//	WorkerIDQueue[m_nBottomIndex]	= t;

	*workerArg = workerThread;

	if(m_nQueueSize != 1 )
		m_nBottomIndex = (m_nBottomIndex+1) % m_nQueueSize;

	if (availableThreads.Post() != X1_OK)
	{
		cout << "Error: sem_post fails. errno is " << errno << " file is " << __FILE__ << "line no is " <<  __LINE__ << endl;
		return false;
	}

	if ((rc = mutexSync.Unlock()) != X1_OK)
	{
		cout << "Error: pthread_mutex_unlock fails. file is " << __FILE__ << "line no is " <<  __LINE__ << endl;
		return false;
	}

	return true;
}

void *ThreadPool::ThreadExecute(void *param)
{
	int		rc	= 0;
	WorkerThread *worker = NULL;

	while(((ThreadPool *)param)->FetchWork(&worker))
	{
		if(worker)
		{
			// run user thread function
			worker->Run();

			delete worker;
			worker = NULL;
		}

		if ((rc = ((ThreadPool *)param)->mutexWorkCompletion.Lock()) != X1_OK)
		{
			cout << "Error: pthread_mutex_unlock fails. file is " << __FILE__ << "line no is " <<  __LINE__ << endl;
		}

		((ThreadPool *)param)->m_nIncompleteWork--;

		if ((rc = ((ThreadPool *)param)->mutexWorkCompletion.Unlock()) != X1_OK)
		{
			cout << "Error: pthread_mutex_unlock fails. file is " << __FILE__ << "line no is " <<  __LINE__ << endl;
		}
	}

	return 0;
}

