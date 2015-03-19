#pragma once

#include "X1.h"

#include <pthread.h>

NS_X1_START

class Thread;
class Task;

/**
 * @class	ThrCtrlInfo
 * @brief	information of thread control
 */
class DECL_SPEC_DLL ThrCtrlInfo
{
public:
	ThrCtrlInfo(void);
	~ThrCtrlInfo(void);

	bool_t		m_bStop;		//stop yn flag
	bool_t		m_bTask;		//association task yn

	thread_t	m_hThread;		//thread id (handle)
	thread_id_t	m_hThreadId;		//thread index (setup by os : windows)
	uint32_t	m_nThreadIdx;	//thread index (setup by user)

	Thread		*m_pThread;		//thread instance pointer
//	Task		*m_pTask;			//assocation task pointer
	THRDFUNC		*m_pTask;			//assocation task pointer
	void		*m_pTaskArg;		//user data pointer
	int			m_nPriority;		// priority of thread function
	int			m_nStackSize;		// stack size of thread
	int			m_nCreateFlag;		// creation flag of thread
#if defined(PTHREAD_H)
	pthread_mutex_t		m_SuspendMutex;
	pthread_cond_t		m_ResumeCond;
#endif
};

/**
 * @class	TLS
 * @brief	Thread local storage management class
 */
class DECL_SPEC_DLL TLS
{
private:
	TLS()
	{
		key_	= 0;
		inst_	= 0;
	}

public:

	~TLS()
	{

	}



	static TLS* Instance()
	{
		/*
		 * FIXME: double checked locking
		 */
		if(!inst_)
		{
			try 
			{
				inst_ = new TLS();
				if(!inst_) 
					return 0; 

				#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
				key_ = TlsAlloc();
				#else
				int i = pthread_key_create(&key_, 0);

				// pthread_key_create fails if i is not zero
				assert (i == 0);
				#endif

			}
			catch(...)
			{
				X1_TRACE();
				return 0;
			}
		}

		return inst_;
	}



	static void Destory()
	{
		#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
		TlsFree(key_);	key_ = 0;
		#else
		pthread_key_delete(key_); key_ = 0;
		#endif

		DEL(inst_);
	}



	static void SetValue(ThrCtrlInfo *thread_si)
	{
#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
		TlsSetValue(key_, thread_si);
#else
		pthread_setspecific(key_, thread_si);
#endif
	}



	static ThrCtrlInfo* GetValue()
	{
#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
		return (ThrCtrlInfo*)TlsGetValue(key_);
#else
		return (ThrCtrlInfo*)pthread_getspecific(key_);
#endif
	}


private:
	static thread_local_storage_t	key_;
	static TLS	*inst_;
};

NS_X1_END