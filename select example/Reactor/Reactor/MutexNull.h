#pragma once

#include "X1.h"
#include <pthread.h>

NS_X1_START

class DECL_SPEC_DLL MutexNull
{
public:
	MutexNull(void)		{}
	~MutexNull(void)	{}

	void Acquire()		{}


	void Release()		{}

	friend class Cond;
};

NS_X1_END