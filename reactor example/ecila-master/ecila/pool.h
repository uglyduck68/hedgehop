#pragma once


#include "ecila.h"
#include <list>
#include <queue>







NS_ECILA_START

template <typename T>
class Pool
{
public:
	enum
	{
		DEFAULT_CAPACITY = 1024,
		DEFAULT_INC_SIZE = DEFAULT_CAPACITY * 2,
	};

	typedef std::list< T* >				LIST_T;
	typedef typename LIST_T::iterator 	ITER_T;


public:

	 Pool();
	~Pool();

	bool_t Initialize	(uint32_t capacity = DEFAULT_CAPACITY, uint32_t inc_size = DEFAULT_INC_SIZE);
	bool_t Finalize		();

	T*		Acquire(const char_t* func, int32_t line);
	bool_t	Release(T *t);

	uint32_t Capacity();
	uint32_t Remain();


private:
	uint32_t	capacity_;
	uint32_t	inc_size_;

	LIST_T		reps_list_;
	LIST_T		free_list_;
	

#if defined(USE_DEBUG_MODE)

#endif
	
};

#include "pool.inl"

NS_ECILA_END

