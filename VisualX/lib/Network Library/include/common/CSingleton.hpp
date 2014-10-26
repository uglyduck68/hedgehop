#pragma once
#include "common/template/TemplatePolicy.hpp"
//////////////////////////////////////////////////////
// policy											//
//////////////////////////////////////////////////////
template <typename T>
class default_life_time
{
public:
	static void on_dead_reference()
	{
		throw std::logic_error("dead reference");
	}
	static void schedule_destruction(T *, atexit_pfn_t pfn)
	{
		std::atexit(pfn);
	}
};
template <typename T>
class phoenix_life_time
{
public:
	static void on_dead_referce()
	{

	}

	static void schedule_destruction(T *,atexit_pfn_t pfn)
	{
		std::atexit(pfn);
	}
};
//////////////////////////////////////////////////////
// holder											//
//////////////////////////////////////////////////////
template <typename T,
	template <class> class creation_policy = create_using_new,
	template <class> class life_time_policy = default_life_time,
	template <class,class> class thread_policy = single_thread,
	typename MUTEX_T = default_mutex
>
class CSingleton
{
public:
	~CSingleton()
	{
	}
	CSingleton()
	{
	}
public:
	static void destroy_singleton()
	{
		creation_policy<T>::destroy(p_instance);
		p_instance = NULL;
		destroyed = true;
	}
	static T& Instance()
	{
		if(NULL == p_instance){
			typename thread_policy<T,MUTEX_T>::locker guard;
			(void)guard;

			if(NULL == p_instance)
			{
				if( true == destroyed)
				{
					default_life_time<T>::on_dead_reference();
					//destroyed = false;
				}
				p_instance = creation_policy<T>::create();
				life_time_policy<T>::schedule_destruction(p_instance,destroy_singleton);
			}
		}
		return *p_instance;
	}
private:
	typedef typename thread_policy<T,MUTEX_T>::volatile_ptr_t instance_ptr_t;
	static instance_ptr_t p_instance;
	static bool destroyed;
};

template <typename T,
	template <class> class C,
	template <class> class L,
	template <class,class> class TM,
	typename MT>
	typename CSingleton<T, C, L, TM, MT>::instance_ptr_t CSingleton<T, C, L, TM, MT>::p_instance = 0;

template <typename T,
	template <class> class C,
	template <class> class L,
	template <class,class> class TM,
	typename MT>
	bool CSingleton<T, C, L, TM, MT>::destroyed = false;
