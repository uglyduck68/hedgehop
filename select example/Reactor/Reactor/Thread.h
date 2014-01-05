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
 * @class	Thread
 * @brief	thread wrapper class
 */

class DECL_SPEC_DLL Thread
{
private:

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
	int		Init();
	int		Start(Task* pTask, void* arg);
	int		Start(THRDFUNC* pFunc, void* arg);
	void	Join(TimeValue *timeout = 0);
	int		Suspend();
	int		Resume();
	int		Kill();

	/// get thread id
	thread_id_t	Self();

protected:

	friend class Threadpool;

	/// Thread control information that have thread-specific parameters
	ThrdCtrlInfo			m_ThreadInfo;

};

NS_X1_END