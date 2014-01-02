#pragma once

#include "X1.h"

NS_X1_START

class Thread;
class Task;

/**
 * @class	ThrdCtrlInfo
 * @brief	information of thread control
 */
class DECL_SPEC_DLL ThrdCtrlInfo
{
public:
	ThrdCtrlInfo(void);
	~ThrdCtrlInfo(void);

	bool_t		b_stop_;		//stop yn flag
	bool_t		b_task_;		//association task yn

	thread_t	h_thread_;		//thread id (handle)
	thread_id_t	thread_id_;		//thread index (setup by os : windows)
	uint32_t	thread_idx_;	//thread index (setup by user)

	Thread		*thread_;		//thread instance pointer
//	Task		*task_;			//assocation task pointer
	THRDFUNC		*task_;			//assocation task pointer
	void		*user_ptr_;		//user data pointer
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



	static void SetValue(ThrdCtrlInfo *thread_si)
	{
#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
		TlsSetValue(key_, thread_si);
#else
		pthread_setspecific(key_, thread_si);
#endif
	}



	static ThrdCtrlInfo* GetValue()
	{
#if defined(_X1_WINDOWS_) && !defined(PTHREAD_H)
		return (ThrdCtrlInfo*)TlsGetValue(key_);
#else
		return (ThrdCtrlInfo*)pthread_getspecific(key_);
#endif
	}


private:
	static thread_local_storage_t	key_;
	static TLS	*inst_;
};

NS_X1_END