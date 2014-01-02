#include "Threadpool.h"

NS_X1_START

/************************************************************************/
/* THRDPOOL_QUEUE                                                       */
/************************************************************************/
int	THRDPOOL_QUEUE::Init()
{
	head	= 0;
	tail	= 0;
	num_of_cells	= 0;

	for(int i = 0; i < THREAD_POOL_QUEUE_SIZE; i++)
	{
		cells[i]	= NULL;
	}

	return X1_OK;
}

THRDPOOL_QUEUE::THRDPOOL_QUEUE()
{
	Init();
}

/**
 * This function adds data to the tail of the queue.
 */
int	THRDPOOL_QUEUE::Enqueue(void* pData)
{
	if (num_of_cells == THREAD_POOL_QUEUE_SIZE)
		return X1_FAIL;

	if (cells[tail] != NULL)
		return X1_FAIL;

	cells[tail]		= pData;

	num_of_cells++;
	tail++;

	if (tail == THREAD_POOL_QUEUE_SIZE)
		tail	= 0;

	return X1_OK;
}

/**
 * This function removes and returns the head data element in the queue.
 * @return	NULL : no element in queue or fail, 
 */
void*	THRDPOOL_QUEUE::Dequeue()
{
	void*	pData	= NULL;

	if (num_of_cells == 0)
		return 0;

	pData	= cells[head];

	num_of_cells--;

	if (num_of_cells == 0)
	{
		head	= 0;
		tail	= 0;
	}
	else
	{
		head++;

		if (head == THREAD_POOL_QUEUE_SIZE)
			head	= 0;
	}

	return pData;
}

/************************************************************************/
/* THRDPOOL                                                             */
/************************************************************************/
int	THRDPOOL::Init()
{
	num_of_threads		= 0;

	free_tasks_mutex	= PTHREAD_MUTEX_INITIALIZER;
	mutex				= PTHREAD_MUTEX_INITIALIZER;
	free_tasks_cond		= PTHREAD_COND_INITIALIZER;
	cond				= PTHREAD_COND_INITIALIZER;

	for(int i = 0; i < THREAD_POOL_QUEUE_SIZE; i++)
		tasks[i].Init();

	return X1_OK;
}

THRDPOOL::THRDPOOL()
{
	Init();
}

int THRDPOOL::Init(Thread* pThrd)
{
	return pThrd->Init();
}

Thread*	THRDPOOL::GetTask()
{
	Thread* task;

	if (stop_flag) 
	{
		/* The pool should shut down return NULL. */
		return NULL;
	}

	/* Obtain a task */
	if (pthread_mutex_lock(&(mutex))) 
	{
		return NULL;
	}

	while (tasks_queue.IsEmpty() && !stop_flag) 
	{
		/* Block until a new task arrives. */
		if (pthread_cond_wait(&(cond), &(mutex))) 
		{
			if (pthread_mutex_unlock(&(mutex))) 
			{
				// perror("pthread_mutex_unlock: ");
			}

			return NULL;
		}
	}

	if (stop_flag) 
	{
		/* The pool should shut down return NULL. */
		if (pthread_mutex_unlock(&(mutex))) 
		{
			perror("pthread_mutex_unlock: ");
		}
		return NULL;
	}

	if ((task = (Thread*)tasks_queue.Dequeue()) == NULL) 
	{
		/* Since task is NULL returning task will return NULL as required. */
		//REPORT_ERROR("Failed to obtain a task from the jobs queue.");
	}

	if (pthread_mutex_unlock(&(mutex))) 
	{
		return NULL;
	}

	return task;
}

/************************************************************************/
/* Threadpool                                                           */
/************************************************************************/

Threadpool::Threadpool(void)
{
}


Threadpool::~Threadpool(void)
{
}



/**
 * This is the routine the worker threads do during their life.
 *
 * @param data Contains a pointer to the threadpool structure.
 * @return NULL.
 */
void *Threadpool::worker_thr_routine(void *data)
{
	THRDPOOL *pool = (THRDPOOL*)data;
	Thread *task;

	while (1) 
	{
		task = pool->GetTask();

		if (task == NULL) 
		{
			if (pool->stop_flag) 
			{
				/* Worker thr needs to exit (thread pool was shutdown). */
				break;
			}
			else 
			{
				/* An error has occurred. */
//				REPORT_ERROR("Warning an error has occurred when trying to obtain a worker task.");
//				REPORT_ERROR("The worker thread has exited.");
				break;
			}
		}

		/* Execute routine (if any). */
		if (task->thread_si_.task_) 
		{
			task->thread_si_.task_(task->thread_si_.user_ptr_);

			/* Release the task by returning it to the free_task_queue. */
			task->Init();
			
			if (pthread_mutex_lock(&(pool->free_tasks_mutex))) 
			{
//				perror("pthread_mutex_lock: ");
//				REPORT_ERROR("The worker thread has exited.");
				break;
			}

			if (pool->free_tasks_queue.Enqueue(task) != X1_OK) 
			{
//				REPORT_ERROR("Failed to enqueue a task to free tasks queue.");
				if (pthread_mutex_unlock(&(pool->free_tasks_mutex))) 
				{
//					perror("pthread_mutex_unlock: ");
				}

//				REPORT_ERROR("The worker thread has exited.");
				break;
			}

			if (pool->free_tasks_queue.GetSize() == 1) 
			{
				/* Notify all waiting threads that new tasks can added. */
				if (pthread_cond_broadcast(&(pool->free_tasks_cond))) 
				{
					perror("pthread_cond_broadcast: ");
					
					if (pthread_mutex_unlock(&(pool->free_tasks_mutex))) 
					{
						perror("pthread_mutex_unlock: ");
					}

					break;
				}
			}

			if (pthread_mutex_unlock(&(pool->free_tasks_mutex))) 
			{
				perror("pthread_mutex_unlock: ");
//				REPORT_ERROR("The worker thread has exited.");
				break;
			}
		}
	}

	return NULL;
}

/**
 * This callback function does the following steps:
 * 1. It raises a flag that notifies the worker threads to stop working.
 * 2. It waits until all worker threads are done with their execution.
 * 3. It frees all the allocated memory of the threadpool struct.
 *
 * @return 0.
 */
void *Threadpool::stop_worker_thr_routines_cb(void *ptr)
{
	int i;
	THRDPOOL *pool = (THRDPOOL*)ptr;

	pool->stop_flag = 1;

	/* Wakeup all worker threads (broadcast operation). */
	if (pthread_mutex_lock(&(pool->mutex))) 
	{
		perror("pthread_mutex_lock: ");
//		REPORT_ERROR("Warning: Memory was not released.");
//		REPORT_ERROR("Warning: Some of the worker threads may have failed to exit.");
		return NULL;
	}

	if (pthread_cond_broadcast(&(pool->cond))) 
	{
		perror("pthread_cond_broadcast: ");
//		REPORT_ERROR("Warning: Memory was not released.");
//		REPORT_ERROR("Warning: Some of the worker threads may have failed to exit.");
		return NULL;
	}

	if (pthread_mutex_unlock(&(pool->mutex))) 
	{
		perror("pthread_mutex_unlock: ");
//		REPORT_ERROR("Warning: Memory was not released.");
//		REPORT_ERROR("Warning: Some of the worker threads may have failed to exit.");
		return NULL;
	}

	/* Wait until all worker threads are done. */
	for (i = 0; i < pool->num_of_threads; i++) 
	{
		if (pthread_join(pool->thr_arr[i],NULL)) 
		{
			perror("pthread_join: ");
		}
	}

	/* Free all allocated memory. */
	DEL_A(pool->thr_arr);
	DEL(pool);

	return NULL;
}

int	Threadpool::Init(int num_of_threads)
{
	int i;

	/* Create the thread pool struct. */
	if ((m_pPool = new (nothrow)THRDPOOL) == NULL) 
	{
		//perror("malloc: ");
		return NULL;
	}

	m_pPool->stop_flag = 0;

	/* Init the jobs queue. */
	m_pPool->tasks_queue.Init();

	/* Init the free tasks queue. */
	m_pPool->free_tasks_queue.Init();

	/* Add all the free tasks to the free tasks queue. */
	for (i = 0; i < THREAD_POOL_QUEUE_SIZE; i++) 
	{
		if (m_pPool->free_tasks_queue.Enqueue(&(m_pPool->tasks[i])) != X1_OK)
		{
			//REPORT_ERROR("Failed to a task to the free tasks queue during initialization.");
			DEL(m_pPool);
			return X1_FAIL;
		}
	}

	/* Create the thr_arr. */
	if ((m_pPool->thr_arr = new (nothrow) thread_t[num_of_threads]) == NULL) 
	{
//		perror("malloc: ");
		DEL(m_pPool);
		return X1_FAIL;
	}

	/* Start the worker threads. */
	for (m_pPool->num_of_threads = 0; m_pPool->num_of_threads < num_of_threads; (m_pPool->num_of_threads)++) 
	{
		if (pthread_create(&(m_pPool->thr_arr[m_pPool->num_of_threads]),NULL,worker_thr_routine,m_pPool)) 
		{
			perror("pthread_create:");

			Fin(0);

			return NULL;
		}
	}

	return X1_OK;
}

int	Threadpool::Add(THRDFUNC pData, void* pArg, int nBlocking)
{
	Thread *task;

	if (m_pPool == NULL) 
	{
//		REPORT_ERROR("The threadpool received as argument is NULL.");
		return X1_FAIL;
	}

	if (pthread_mutex_lock(&(m_pPool->free_tasks_mutex))) 
	{
		perror("pthread_mutex_lock: ");
		return -1;
	}

	/* Check if the free task queue is empty. */
	while (m_pPool->free_tasks_queue.IsEmpty()) 
	{
		if (!nBlocking) 
		{
			/* Return immediately if the command is non blocking. */
			if (pthread_mutex_unlock(&(m_pPool->free_tasks_mutex))) {
				perror("pthread_mutex_unlock: ");
				return -1;
			}

			return -2;
		}

		/* blocking is set to 1, wait until free_tasks queue has a task to obtain. */
		if (pthread_cond_wait(&(m_pPool->free_tasks_cond),&(m_pPool->free_tasks_mutex))) 
		{
			perror("pthread_cond_wait: ");
			if (pthread_mutex_unlock(&(m_pPool->free_tasks_mutex))) 
			{
				perror("pthread_mutex_unlock: ");
			}

			return -1;
		}
	}

	/* Obtain an empty task. */
	if ((task = (Thread*)m_pPool->free_tasks_queue.Dequeue()) == NULL) 
	{
//		REPORT_ERROR("Failed to obtain an empty task from the free tasks queue.");
		if (pthread_mutex_unlock(&(m_pPool->free_tasks_mutex))) {
			perror("pthread_mutex_unlock: ");
		}

		return -1;
	}

	if (pthread_mutex_unlock(&(m_pPool->free_tasks_mutex))) 
	{
		perror("pthread_mutex_unlock: ");
		return -1;
	}

	task->thread_si_.user_ptr_	= pArg;
	task->thread_si_.task_		= pData;

	/* Add the task, to the tasks queue. */
	if (pthread_mutex_lock(&(m_pPool->mutex))) 
	{
		perror("pthread_mutex_lock: ");
		return -1;
	}

	if (m_pPool->tasks_queue.Enqueue(task)) 
	{
//		REPORT_ERROR("Failed to add a new task to the tasks queue.");
		if (pthread_mutex_unlock(&(m_pPool->mutex))) 
		{
			perror("pthread_mutex_unlock: ");
		}
		return -1;
	}

	if (m_pPool->tasks_queue.GetSize() == 1) 
	{
		/* Notify all worker threads that there are new jobs. */
		if (pthread_cond_broadcast(&(m_pPool->cond))) 
		{
			perror("pthread_cond_broadcast: ");
			if (pthread_mutex_unlock(&(m_pPool->mutex))) 
			{
				perror("pthread_mutex_unlock: ");
			}

			return -1;
		}
	}

	if (pthread_mutex_unlock(&(m_pPool->mutex))) 
	{
		perror("pthread_mutex_unlock: ");
		return -1;
	}


	return X1_OK;
}

int	Threadpool::Fin(int nBlocking)
{
	pthread_t thr;

	if (nBlocking) 
	{
		stop_worker_thr_routines_cb(m_pPool);
	}
	else 
	{
		if (pthread_create(&thr, NULL, stop_worker_thr_routines_cb, m_pPool)) 
		{
			perror("pthread_create: ");
//			REPORT_ERROR("Warning! will not be able to free memory allocation. This will cause a memory leak.");
			m_pPool->stop_flag = 1;
		}
	}

	return X1_OK;
}

NS_X1_END
