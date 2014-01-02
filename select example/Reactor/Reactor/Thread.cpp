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
	ThrdCtrlInfo *p_thread_si = (ThrdCtrlInfo*)thread_si;
	TLS::Instance()->SetValue(p_thread_si);

	if(!p_thread_si) 
	{ 
		return 0; 
	}

	if(p_thread_si->b_task_)
	{
		/// run user callback
		return p_thread_si->task_(p_thread_si->user_ptr_);
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
	pThrd->thread_si_.task_		= NULL;
	pThrd->thread_si_.user_ptr_	= NULL;

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

	thread_si_.b_task_		= (pFunc) ? TRUE : FALSE;
	thread_si_.thread_		= this;
	thread_si_.task_		= pFunc;
	thread_si_.user_ptr_	= arg;

#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	thread_si_.h_thread_ = (thread_t)_beginthreadex(0, 0, m_Invoker, &thread_si_, 0, &thread_si_.thread_id_);

	if(!thread_si_.thread_id_) 
	{ 
		return X1_FAIL; 
	}
#else
	int32_t ret = pthread_create(&thread_si_.h_thread_, 0, m_Invoker, &thread_si_);

	if(ret < 0) 
	{ 
		return X1_FAIL; 
	}

	thread_si_.thread_id_ = thread_si_.h_thread_;
#endif

	return X1_OK;
}


void	Thread::Join(TimeValue *timeout /*= 0*/)
{
#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	WaitForSingleObject(thread_si_.h_thread_, timeout_msec == 0 ? INFINITE : timeout_msec);
#else
	int32_t status = 0;
	pthread_join(thread_si_.h_thread_, (void **)&status); 
#endif

}

int		Thread::Suspend()
{
#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
	if(m_hThread != NULL)
	{
		return SuspendThread(thread_si_.h_thread_)==0xFFFFFFFF?false:true;
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
	if(thread_si_.h_thread_ != NULL)
	{
		::TerminateThread(thread_si_.h_thread_, uiExitCode);
		thread_si_.h_thread_ = NULL;
	}

	// FIXME: check pthread_kill or pthread_cancel or to use conditional variables
	// -> use pthread_detach & pthread_cancel API
#elif defined(_X1_WINDOWS_) && defined(PTHREAD_H)
	pthread_kill(thread_si_.h_thread_, SIGTERM);
#elif defined(_X1_LINUX_)
	pthread_kill(thread_si_.h_thread_, SIGTERM);
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