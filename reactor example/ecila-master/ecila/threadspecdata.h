#pragma once

#include "ecila.h"







NS_ECILA_START

class ITask;
class Thread;

//thread specific infomation
class DECL_SPEC_DLL ThreadSpecData
{
public:
	bool_t		b_stop_;		//stop yn flag
	bool_t		b_task_;		//association task yn

	thread_t	h_thread_;		//thread id (handle)
	thread_id_t	thread_id_;		//thread index (setup by os : windows)
	uint32_t	thread_idx_;	//thread index (setup by user)

	Thread		*thread_;		//thread instance pointer
	ITask		*task_;			//assocation task pointer
	void		*user_ptr_;		//user data pointer

	ThreadSpecData()
	{
		b_stop_		= FALSE;
		b_task_		= FALSE;

		h_thread_	= 0;
		thread_id_	= 0;
		thread_idx_	= 0;

		thread_		= 0;
		task_		= 0;
		user_ptr_	= 0;
	}

	~ThreadSpecData() {}
};








class DECL_SPEC_DLL ThreadLocalStorageKey
{
private:
	ThreadLocalStorageKey()
	{
		key_	= 0;
		inst_	= 0;
	}

public:

	~ThreadLocalStorageKey()
	{

	}



	static ThreadLocalStorageKey* Instance()
	{
		if(!inst_)
		{
			try 
			{
				inst_ = new ThreadLocalStorageKey();
				if(!inst_) { return 0; }

				#ifdef OS_WINDOWS
				key_ = TlsAlloc();
				#else
				key_ = pthread_key_create(&key_, 0);
				#endif

			}
			catch(...)
			{
				ECILA_TRACE();
				return 0;
			}
		}

		return inst_;
	}



	static void Destory()
	{
		#ifdef OS_WINDOWS
		TlsFree(key_);	key_ = 0;
		#else
		pthread_key_delete(key_); key_ = 0;
		#endif

		ECILA_SAFE_DELETE(inst_);
	}



	static void SetValue(ThreadSpecData *thread_si)
	{
		#ifdef OS_WINDOWS
		TlsSetValue(key_, thread_si);
		#else
		pthread_setspecific(key_, thread_si);
		#endif
	}



	static ThreadSpecData* GetValue()
	{
		#ifdef OS_WINDOWS
		return (ThreadSpecData*)TlsGetValue(key_);
		#else
		return (ThreadSpecData*)pthread_getspecific(key_);
		#endif
	}


private:
	static thread_local_storage_t	key_;
	static ThreadLocalStorageKey	*inst_;
};


NS_ECILA_END

