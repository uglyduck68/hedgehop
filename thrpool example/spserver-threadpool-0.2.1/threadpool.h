/**
* @file		Threadpool.h
* @auther	Younghwan Kim<uglyduck68@gmail.com>
* @version	0.1
* @date		20140816
* @brief	interface file for threadpool
*/
#pragma once

#include	"X1.h"
#include	"Task.h"
#include	"Mutex.h"
#include	"CondVar.h"

NS_X1_START

	// maximum number of threads allowed in a pool
	#define MAXT_IN_POOL 200
typedef void (*dispatch_fn)(void *);

	class DECL_SPEC_DLL Threadpool;

	/**
	* @class	WorkerThread
	* @brief	WorkerThread class is only for threadpool
	*/
	class WorkerThread
	{
	public:
		WorkerThread(Task* pThread, Threadpool* pPool);
		~WorkerThread();

		/** thread handle */
		sp_thread_t		m_Id;

	protected:
		Mutex			m_Mutex;
		CondVar			m_Cond;

		// pointer to user thread
		Task*			m_pThread;

		// pointer to threadpool
		Threadpool*		m_pPool;

		friend class Threadpool;
	};

	/**
	* @class	Threadpool
	* @brief	This class is for threadpool
	*/
	class DECL_SPEC_DLL Threadpool
	{
	public:
		Threadpool(int num_threads_in_pool);
		~Threadpool(void);

		/**
		* @function	Assign
		* @return	0 if success
		*			> 0 if fails
		*/
		int		Assign(Task* pThread);
		void	Destroy();

	protected:


		/**
		* @function	SaveThread
		* @return	0 if success
		*			> 0 if fails
		*/
		int		SaveThread(WorkerThread* pThread);
		static sp_thread_result_t SP_THREAD_CALL wrapper_fn( void * arg );

		void	PrintStatus();

	protected:
		Mutex			m_tp_mutex;
		CondVar			m_tp_idle;
		CondVar			m_tp_full;
		CondVar			m_tp_empty;
		WorkerThread*	m_tp_list[MAXT_IN_POOL];

		int				m_tp_index;
		int				m_tp_max_index;
		int				m_tp_stop;

		int				m_tp_total;
	};

NS_X1_END