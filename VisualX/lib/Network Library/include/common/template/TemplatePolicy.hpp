#pragma once
#include <memory>
//////////////////////////////////////////////////////
// policy											//
//////////////////////////////////////////////////////
template <typename T>
class create_using_new
{
public:
	static T* create()
	{
		return new T();
	}
	static void destroy(T* p)
	{
		if(p)
		{
			delete p;
			p = NULL;
		}
	}
};
template <typename T>
class create_using_static
{
public:
	static T* create()
	{
		static static_memory t;
		return new (&t) T;
	}
	static void destroy(T *p)
	{
		p->~T();
	}
private:
	union static_memory
	{
		char temp_[sizeof(T)];
	};
};
template <typename T>
class create_using_shared
{
public:
	static std::shared_ptr<T> create()
	{
		return std::make_shared<T>(new T);
	}
	static void destroy(std::shared_ptr<T>& p)
	{
		if(p) p.reset();
	}
};
typedef void(*atexit_pfn_t)();

template <typename T, typename MT>
class single_thread
{
public:
	struct locker
	{
		locker() {}
		explicit locker(const single_thread&){}
		explicit locker(const single_thread*){}
		void wait(int cycle = 0)
		{
		}
		void wake()
		{
		}
	};

	typedef T* volatile_ptr_t;
};

template <typename T, typename MT>
class multi_thread
{
public:
	typedef T* volatile_ptr_t;
public:
	struct locker
	{
		~locker()
		{
			mt_.un_lock();
		}
		locker()
		{
			mt_.lock();
		}
		void wait(int cycle = 0)
		{
			mt_.wait(cycle);
		}
		void wake()
		{
			mt_.wake();
		}
	};

private:
	static MT mt_;
};
template <typename T, typename MT>
MT multi_thread<T,MT>::mt_;

//////////////////////////////////////////////////////
// mutex											//
//////////////////////////////////////////////////////
#if defined(WIN32) || defined(WIN64)
#include <windows.h>

class default_mutex
{
private:
	default_mutex(const default_mutex&);
	default_mutex& operator=(const default_mutex&);

public:
	virtual ~default_mutex()
	{
		DeleteCriticalSection(&cs);
	}
	default_mutex()
	{
		InitializeConditionVariable(&cv);
		InitializeCriticalSectionAndSpinCount(&cs,0x80000400);
	}
	void wait(int cycle = 0)
	{
		SleepConditionVariableCS(&cv,&cs,(cycle == 0) ?INFINITE : cycle);
	}
	void wake()
	{
		WakeConditionVariable(&cv);
	}
	bool trylock()
	{
		return (TryEnterCriticalSection(&cs))?true:false;
	}
	void lock()
	{
		EnterCriticalSection(&cs);
	}
	void un_lock()
	{
		LeaveCriticalSection(&cs);
	}
private:
	CRITICAL_SECTION cs;
	CONDITION_VARIABLE cv;
};
template <typename T>
bool CAS(int *address,T oldValue, T newValue)
{
	atomic{
		if (*address == oldValue)
			*address = newValue
			return true
		else
			return false
	}
}
#endif
template <typename T,class mtx = default_mutex>
class locker : public T,public mtx
{
public:
	locker()
	{
		lock();
	}
	virtual ~locker()
	{
		un_lock();
	}
};
//////////////////////////////////////////////////////
// timer											//
//////////////////////////////////////////////////////
class ITimerPolicy
{
public:
	virtual bool getPolicy() = 0;
};
class timerpolicy_looper : public ITimerPolicy
{
private:
	bool isLooper;

public:
	timerpolicy_looper(bool looper) : isLooper(looper){}
	virtual ~timerpolicy_looper(){}
	virtual bool getPolicy(){return isLooper;}
};

class timerpolicy_counter : public ITimerPolicy
{
private:
	int use;
	int counter;
public:
	timerpolicy_counter(int _counter) : counter(_counter),use(0){}
	virtual ~timerpolicy_counter(){}
	virtual bool getPolicy(){
		++use;
		return use != counter;
	}
};