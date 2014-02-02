#include "Thread.h"

#include <signal.h>

NS_X1_START

	/**
	 * @function	Thread::m_Invoker
	 * @brief		invoke function that call user thread
	 */
#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	thread_return_t __stdcall Thread::m_Invoker(void *pThreadCtrlArg)
#else
	thread_return_t (Thread::m_Invoker)(void *pThreadCtrlArg)
#endif
{
	thread_return_t Ret	= NULL;


	ThrCtrlInfo *pThreadArg = (ThrCtrlInfo*)pThreadCtrlArg;
//	TLS::Instance()->SetValue(pThreadArg);

	if(!pThreadArg) 
	{ 
		return 0; 
	}

	if(pThreadArg->m_bTask)
	{
		if (pThreadArg->m_pTask == NULL)
		{
			// INTERNAL ERROR
			printf("Error: pThreadArg->m_pTask is NULL\n");
			
			return NULL;
		}

		/// run user thread
		Ret	= pThreadArg->m_pTask(pThreadArg->m_pTaskArg);

		/// after user thread end, I will clear internal structure
		pThreadArg->m_pThread->Init();

		return Ret;
	}

	return NULL;
}

Thread::Thread()
{
}

Thread::~Thread()
{
}

int		Thread::Init(Thread* pThrd)
{
	pThrd->m_ThreadInfo.m_pTask		= NULL;
	pThrd->m_ThreadInfo.m_pTaskArg	= NULL;

	return X1_OK;
}

int		Thread::Init()
{
	return Init(this);
}

/**
 * adjust thread priority according to the platform
 */
int Thread::AdjustPriority(int nPriority)
{
#if defined(PTHREAD_H)
	/* Supported policy values are SCHED_FIFO, SCHED_RR, SCHED_OTHER,
	SCHED_BATCH, and SCHED_IDLE.
	Linux allows the static priority value range 1 to 99 for SCHED_FIFO
       and SCHED_RR and the priority 0 for SCHED_OTHER, SCHED_BATCH, and
       SCHED_IDLE.
	*/
	//sched_get_priority_min(int policy);
	//sched_get_priority_max(int policy);
#endif
	return nPriority;
}

int	Thread::Spawn(THRDFUNC* pFunc, void* pArg, int nPriority /*= 0*/, int nStackSize /*= -1*/, int nCreateFlag /*= 0*/)
{
	if (pFunc == NULL)
		return X1_FAIL;

	m_ThreadInfo.m_bTask		= (pFunc) ? TRUE : FALSE;
	m_ThreadInfo.m_pThread		= this;
	m_ThreadInfo.m_pTask		= pFunc;
	m_ThreadInfo.m_pTaskArg		= pArg;
	m_ThreadInfo.m_nPriority	= (nPriority == -1? 0: nPriority);//AdjustPriority(nPriority);
	m_ThreadInfo.m_nStackSize	= (nStackSize == -1? 0: nStackSize);
	m_ThreadInfo.m_nCreateFlag	= nCreateFlag;

#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)

	m_ThreadInfo.m_hThread = (thread_t)_beginthreadex(0, 0, m_Invoker, &m_ThreadInfo, 0, &m_ThreadInfo.m_hThreadId);

	if(!m_ThreadInfo.m_hThreadId) 
	{ 
		return X1_FAIL; 
	}
#else

	/* NOTE
	 *	- you MUST set the pthread_attr_t
	 */
	pthread_attr_t				attr;
	struct sched_param			prio;	// priority
	int							nRet;

	nRet = pthread_attr_init(&attr);
	if (nRet != 0)
		return X1_FAIL;

	if (m_ThreadInfo.m_nStackSize >= 0)
	{
		nRet = pthread_attr_setstacksize(&attr, m_ThreadInfo.m_nStackSize);

		if (nRet != 0)
			return X1_FAIL;
	}

	if (m_ThreadInfo.m_nPriority >= 0)
	{
		// set the priority explicitly
		nRet	= pthread_attr_setschedparam(&attr, &prio);

		if (nRet != 0)
			return X1_FAIL;

		// set scheduling parameter
		nRet	= pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	}

	// create thread invoker
	int32_t ret = pthread_create(&m_ThreadInfo.m_hThread, &attr, m_Invoker, &m_ThreadInfo);
	
	nRet = pthread_attr_destroy(&attr);

	if (nRet != 0)
		return X1_FAIL;

	if(ret < 0) 
	{ 
		return X1_FAIL; 
	}

	m_ThreadInfo.m_hThreadId = m_ThreadInfo.m_hThread;
#endif

	return X1_OK;
}


void	Thread::Join(TimeValue *timeout /*= 0*/)
{
#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	WaitForSingleObject(m_ThreadInfo.m_hThread, timeout_msec == 0 ? INFINITE : timeout_msec);
#else
	int32_t	status = 0;
	int		nRet	= 0;
	
	if ((nRet = pthread_join(m_ThreadInfo.m_hThread, (void **)&status)) != 0)
	{
		// INTERNAL ERROR
		switch(nRet)
		{
		case ESRCH:
			printf("Internal error: ESRCH\n");
			break;
		case EINVAL:
			printf("Internal error: EINVAL\n");
			break;
		case EDEADLK:
			printf("Internal error: EDEADLK\n");
			break;
		default:
			break;
		}
	}
#endif

}

int		Thread::Suspend()
{
#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	if(m_hThread != NULL)
	{
		return SuspendThread(m_ThreadInfo.m_hThread)==0xFFFFFFFF?false:true;
	}
#elif defined(_X1_LINUX_)

#endif
	return X1_OK;
}

int		Thread::Resume()
{
	return X1_OK;
}

int		Thread::Kill()
{
#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	if(m_ThreadInfo.m_hThread != NULL)
	{
		::TerminateThread(m_ThreadInfo.m_hThread, uiExitCode);
		m_ThreadInfo.m_hThread = NULL;
	}

	// FIXME: check pthread_kill or pthread_cancel or to use conditional variables
	// -> use pthread_detach & pthread_cancel API
#elif defined(_X1_WINDOWS_) && defined(PTHREAD_H)
	pthread_kill(m_ThreadInfo.m_hThread, SIGTERM);
#elif defined(_X1_LINUX_)
	pthread_kill(m_ThreadInfo.m_hThread, SIGTERM);
#endif
	return X1_OK;
}

thread_id_t	Thread::Self()
{
#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	return GetCurrentThreadId();
#else
	return pthread_self();
#endif

}

int	Thread::GrpId()
{
	return m_ThreadInfo.m_nThreadIdx;
}

NS_X1_END