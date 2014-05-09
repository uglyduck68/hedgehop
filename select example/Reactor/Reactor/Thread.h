/**
 * I will replace this class with OpenThread library.
 *
 */

#pragma once

#include "X1.h"
#include "TimeValue.h"
#include "TLS.h"

#include <pthread.h>

//#if defined(_X1_LINUX_) || defined(PTHREAD)
//typedef void* (THRFUNC)(void *thread_si);
//#elif defined(_X1_WINDOWS)
//typedef uint32_t __stdcall THRFUNC(void *thread_si);
//#endif

NS_X1_START

/**
 * This class is thread wrapper.
 * @class	Thread
 * @brief	thread wrapper class
 */

class DECL_SPEC_DLL Thread
{
private:

	/**
	 * thread function invoker. This function handle preprocessing and 
	 * postprocessing of thread function.
	 */
#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	static uint32_t __stdcall m_Invoker(void *thread_si);
#else
	static void* (m_Invoker)(void *thread_si);
#endif
	//	void*		m_pArg;


public:

	Thread();
	virtual ~Thread();

	static int		Init(Thread* pThrd);

	/**
	 * adjust thread priority according to the platform
	 */
	static int		AdjustPriority(int nPriority);
	int		Init();

	/**
	 * thread creation function
	 * @param pFunc		is thread function pointer
	 * @param pArg		is thread argument
	 * @param nPrioriy	is thread priority that is between 0 and 100.
	 *					0 is lowest priority, 100 is highest priority.
	 *					-1 is default priority.
	 * @param nStackSize	is stack size. 
	 * @param nCreateFlag	is thread createion flag(THR_SUSPENDED, THR_DETACHED)
	 * @retval X1_FAIL	for fail
	 * @retval X1_OK	for success
	 */
	int		Spawn(THRDFUNC* pFunc, void* pArg, int nPriority = -1, int nStackSize = -1, int nCreateFlag = 0);
	void	Join(TimeValue *timeout = 0);
	void	Wait(TimeValue *timeout = 0)
	{
		Join(timeout);
	}

	int		Suspend();
	int		Resume();
	int		Kill();

	/// get thread id
	thread_id_t	Self();

	/// get group id
	int	 GrpId();

protected:

	friend class Threadpool;
	friend class Task;

	/// Thread control information that have thread-specific parameters
	ThrCtrlInfo			m_ThreadInfo;
};

NS_X1_END