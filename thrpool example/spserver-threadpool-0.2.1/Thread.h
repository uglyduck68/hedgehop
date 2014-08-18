/**
* @file		Thread.h
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

	class DECL_SPEC_DLL Thread :public Task
	{
	public:
		Thread(void);
		virtual	~Thread(void);

		int	Start();

		int	Join();

		int	Detach();


//		virtual sp_thread_result_t	Run(Thread* pArg)	= 0;

		enum STATS { NOT_CREATED = 0, RUNNING = 1, DEAD = 2 };

		/** flag that is 0 when the thread is *NOT* running or 1 when it is */
		STATS		m_Running;

	protected:

		/** flag that is 1 when thread wait the signal */
		int			m_nJoinable;

		/** flag that is 0 when the thread is *NOT* detached or 1 when it is */
		int			m_Detached;

		/** thread argument */
		void*		m_pArg;


	public:
		/// pthread for emulation of join
		Mutex		m_MutexJoin;
		CondVar		m_CondJoin;

		/** conditional variable that send signal */
		int	Signal();


		/** conditional variable that wait */
		int	Wait();


	};

NS_X1_END