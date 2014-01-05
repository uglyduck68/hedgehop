#include "Thread.h"

#include <signal.h>

NS_X1_START

	/**
	 * @function	Thread::m_Invoker
	 * @brief		invoke function that call user callback
	 */
#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	uint32_t __stdcall Thread::m_Invoker(void *thread_si)
#else
	void* (Thread::m_Invoker)(void *thread_si)
#endif
{
#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	uint32_t Ret
#else
	void* Ret	= NULL;
#endif

	ThrdCtrlInfo *p_thread_si = (ThrdCtrlInfo*)thread_si;
	TLS::Instance()->SetValue(p_thread_si);

	if(!p_thread_si) 
	{ 
		return 0; 
	}

	if(p_thread_si->m_bTask)
	{
		if (p_thread_si->m_pTask == NULL)
		{
			// INTERNAL ERROR
			printf("Error: p_thread_si->m_pTask is NULL\n");
			
			return NULL;
		}

		/// run user thread
		Ret	= p_thread_si->m_pTask(p_thread_si->m_pTaskArg);

		/// after user thread end, I will clear internal structure
		p_thread_si->m_pThread->Init();

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

int		Thread::Start(Task* pTask, void* arg)
{
	return X1_OK;
}

int	Thread::Start(THRDFUNC* pFunc, void* arg)
{
	if (pFunc == NULL)
		return X1_FAIL;

	m_ThreadInfo.m_bTask		= (pFunc) ? TRUE : FALSE;
	m_ThreadInfo.m_pThread		= this;
	m_ThreadInfo.m_pTask		= pFunc;
	m_ThreadInfo.m_pTaskArg	= arg;

#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	m_ThreadInfo.m_hThread = (thread_t)_beginthreadex(0, 0, m_Invoker, &m_ThreadInfo, 0, &m_ThreadInfo.m_hThreadId);

	if(!m_ThreadInfo.m_hThreadId) 
	{ 
		return X1_FAIL; 
	}
#else
	int32_t ret = pthread_create(&m_ThreadInfo.m_hThread, 0, m_Invoker, &m_ThreadInfo);

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
	int32_t status = 0;
	pthread_join(m_ThreadInfo.m_hThread, (void **)&status); 
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
NS_X1_END