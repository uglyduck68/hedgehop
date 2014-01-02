#pragma once

#include "X1.h"
#include "Thread.h"

NS_X1_START

class THRDPOOL_QUEUE
{
public:
	unsigned int head;
	unsigned int tail;

	unsigned int num_of_cells;

	// FIXME: change to dynamic allocation
	void *cells[THREAD_POOL_QUEUE_SIZE];

	THRDPOOL_QUEUE();

	int	Init();
	int	Enqueue(void* pData);
	void*	Dequeue();
	int	IsEmpty()
	{
		return (num_of_cells == 0 ? 1: 0);
	}

	int	GetSize()
	{
		return num_of_cells;
	}
};

class THRDPOOL
{
public:
	THRDPOOL_QUEUE tasks_queue;
	THRDPOOL_QUEUE free_tasks_queue;

	// FIXME: change to dynamic allocation
	Thread tasks[THREAD_POOL_QUEUE_SIZE];

	// FIXME thr_arr must be integrated with tasks
	thread_t *thr_arr;

	unsigned short				num_of_threads;
	volatile unsigned short		stop_flag;

	thread_mutex_t				free_tasks_mutex;
	thread_mutex_t				mutex;
	thread_cond_t				free_tasks_cond;
	thread_cond_t				cond;

	THRDPOOL();

	int	Init();
	int	Init(Thread* pThrd);

	Thread*	GetTask();
};

class Threadpool
{
protected:
	
	THRDPOOL*	m_pPool;

public:
	Threadpool(void);
	virtual ~Threadpool(void);

	static void *worker_thr_routine(void *data);
	static void *stop_worker_thr_routines_cb(void *ptr);

	int	Init(int num_of_threads);
	int	Add(THRDFUNC, void* pArg, int nBlocking);
	int	Fin(int nBlocking);
};

NS_X1_END

