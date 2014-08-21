/**
* @file		Threadpool.cpp
* @auther	Younghwan Kim<uglyduck68@gmail.com>
* @version	0.1
* @date		20140816
* @brief	threadpool implementation file
*/
#include "Threadpool.h"
#include "Exception.h"
#include "Guard.h"
#include "Log.h"

#include <new.h>

NS_X1_USE

///////////////////////////////////////////////////////////////////////////////
// WorkerThread
///////////////////////////////////////////////////////////////////////////////

WorkerThread::WorkerThread(Thread* pThread, Threadpool* pPool) :
	m_pThread(pThread), m_pPool(pPool)
{
}

WorkerThread::~WorkerThread()
{
	m_pThread	= NULL;
	m_pPool		= NULL;
}


///////////////////////////////////////////////////////////////////////////////
// Threadpool Class
///////////////////////////////////////////////////////////////////////////////

Threadpool::Threadpool(int num_threads_in_pool) :
	m_tp_index(0), m_tp_max_index(0), m_tp_stop(0), m_tp_total(0)
{
	if ((num_threads_in_pool <= 0) || (num_threads_in_pool > MAXT_IN_POOL))
		throw  IllegalThreadStateException("num_threads_in_pool is invalid"); 


	m_tp_max_index = num_threads_in_pool;
}

Threadpool::~Threadpool()
{
	Destroy();
}

/**
* @function	SaveThread
* @return	0 if success
*			> 0 if fails
*/
int		Threadpool::SaveThread(WorkerThread* pThread)
{
	int ret = -1;

	// scoped lock
	Guard<Mutex>	guard(m_tp_mutex );

	if( m_tp_index < m_tp_max_index ) 
	{
		m_tp_list[ m_tp_index ] = pThread;
		m_tp_index++;
		ret = 0;

		m_tp_idle.Signal();

		if( m_tp_index >= m_tp_total ) 
		{
			m_tp_full.Signal();
		}
	}

	return ret;
}

sp_thread_result_t SP_THREAD_CALL Threadpool::wrapper_fn( void * arg )
{
	WorkerThread * thread	= (WorkerThread*)arg;
	Threadpool * pool		= (Threadpool*) thread->m_pPool;

	for( ; 0 == ((Threadpool*)thread->m_pPool)->m_tp_stop; ) 
	{
		// run user thread function
		thread->m_pThread->Run( thread->m_pThread );

		if( 0 != ((Threadpool*)thread->m_pPool)->m_tp_stop ) 
			break;

		thread->m_Mutex.Lock( );

		if( 0 == ((Threadpool*)thread->m_pPool)->SaveThread(thread) ) 
		{
			thread->m_Cond.Wait(thread->m_Mutex );
			thread->m_Mutex.UnLock( );
		} 
		else 
		{
			thread->m_Mutex.UnLock( );

			delete thread;

			break;
		}
	}

	((Threadpool*)thread->m_pPool)->m_tp_mutex.Lock( );
	((Threadpool*)thread->m_pPool)->m_tp_total--;

	if( ((Threadpool*)thread->m_pPool)->m_tp_total <= 0 ) 
		((Threadpool*)thread->m_pPool)->m_tp_empty.Signal( );
	((Threadpool*)thread->m_pPool)->m_tp_mutex.UnLock( );

	return 0;
}

/**
* @function	Assign
* @return	0 if success
*			> 0 if fails
*/
int		Threadpool::Assign(Thread* pThread)
{
	int ret = 0;

	Threadpool *pool		= this;
	WorkerThread * thread	= NULL;

	// add your code here to dispatch a thread
	pool->m_tp_mutex.Lock( );

	while( pool->m_tp_index <= 0 && pool->m_tp_total >= pool->m_tp_max_index ) 
	{
		LOG("beofore idle.Wait\n"); PrintStatus();
		pool->m_tp_idle.Wait(pool->m_tp_mutex );
		LOG("after idle.Wait\n"); PrintStatus();
	}

	if( pool->m_tp_index <= 0 ) 
	{
		thread = new (std::nothrow) WorkerThread(pThread, this );

		if (thread == NULL)
			throw IllegalThreadStateException("no memory"); 

		sp_thread_attr_t attr;

		sp_thread_attr_init( &attr );
		sp_thread_attr_setdetachstate( &attr, SP_THREAD_CREATE_DETACHED );

		if( 0 == sp_thread_create( &thread->m_pThread->Self(), &attr, wrapper_fn, thread ) ) 
		{
			pool->m_tp_total++;
			LOG( "Debug: create thread#%ld\n", thread->m_pThread->GetId() );
		} 
		else 
		{
			ret = -1;
			LOG( "Error: cannot create thread\n" );

			delete thread;
		}
	} 
	else 
	{
		pool->m_tp_index--;
		thread = pool->m_tp_list[ pool->m_tp_index ];
		pool->m_tp_list[ pool->m_tp_index ] = NULL;

		// save thread handle
		pThread->Self()		= thread->m_pThread->Self();
		thread->m_pThread	= pThread;
		thread->m_pPool		= pool;

		thread->m_Mutex.Lock( );
		thread->m_Cond.Signal( ) ;
		thread->m_Mutex.UnLock( );
	}

	pool->m_tp_mutex.UnLock( );

	return ret;
}

void	Threadpool::Destroy()
{
	Threadpool *pool = this;
	int			i;

	if( pool->m_tp_stop == 1)
		// already being destroyed
		return;

	pool->m_tp_mutex.Lock( );

	if( pool->m_tp_index < pool->m_tp_total ) 
	{
		LOG( "Debug: waiting for %d thread(s) to finish\n", pool->m_tp_total - pool->m_tp_index );
		pool->m_tp_full.Wait(pool->m_tp_mutex );
	}

	pool->m_tp_stop = 1;

	for( i = 0; i < pool->m_tp_index; i++ ) 
	{
		WorkerThread * thread = pool->m_tp_list[ i ];

		thread->m_Mutex.Lock( );
		thread->m_Cond.Signal( ) ;
		thread->m_Mutex.UnLock( );
	}

	if( pool->m_tp_total > 0 ) 
	{
		LOG( "Debug: waiting for %d thread(s) to exit\n", pool->m_tp_total );
		pool->m_tp_empty.Wait(pool->m_tp_mutex );
	}

	for( i = 0; i < pool->m_tp_index; i++ ) 
	{
		delete( pool->m_tp_list[ i ] );
		pool->m_tp_list[ i ] = NULL;
	}

	pool->m_tp_mutex.UnLock( );

	pool->m_tp_index = 0;

	return;
}

void	Threadpool::PrintStatus()
{
	LOG("index: %d, max_index: %d, total: %d, stop: %d\n",
		m_tp_index, m_tp_max_index, m_tp_total, m_tp_stop);
}
