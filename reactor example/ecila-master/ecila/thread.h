#pragma once

#include "ecila.h"
#include "node.h"
#include "itask.h"
#include "threadspecdata.h"







NS_ECILA_START

class DECL_SPEC_DLL Thread
:	public Node
{
public:

			 Thread();
	virtual ~Thread();

	CLASSNAME("Thread");

	#ifdef OS_WINDOWS
	static uint32_t __stdcall Invoker(void *thread_si)
	#else
	static void* (Invoker)(void *thread_si)
	#endif
	{
		ThreadSpecData *p_thread_si = (ThreadSpecData*)thread_si;
		ThreadLocalStorageKey::Instance()->SetValue(p_thread_si);

		if(!p_thread_si) { ECILA_TRACE(); return 0; }

		if(p_thread_si->b_task_)
		{
			ITask *task = (ITask *)p_thread_si->task_;
			if(!task)			{ ECILA_TRACE(); return 0; }
			if(!task->Run())	{ ECILA_TRACE(); return 0; }
		}
		else
		{
			Thread *thread = (Thread*)p_thread_si->thread_;
			if(!thread)			{ ECILA_TRACE(); return 0; }
			if(!thread->Run())	{ ECILA_TRACE(); return 0; }
		}

		return 0;
	}



	bool_t	Start		(ITask *task = 0, void *arg = 0);
	void	Join		(int32_t timeout_msec = 0);
	void	ThreadIDX	(uint32_t thread_idx);
	void	ForceStop()	{ thread_si_.b_stop_ = TRUE; }


	static void*		UserPtr		();
	static thread_id_t	Self		();
	static uint32_t		ThreadIDX	();
	static bool_t		IsStop		();
	static void			Stop		();


	virtual bool_t Run()	{ return TRUE; }


protected:

	ThreadSpecData thread_si_;
};

NS_ECILA_END
