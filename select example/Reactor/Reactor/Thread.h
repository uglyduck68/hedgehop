#pragma once

#include "X1.h"
#include "TimeValue.h"
#include "TLS.h"

#include <pthread.h>

//#if defined(_X1_LINUX_) || defined(PTHREAD)
//typedef void* (THRFUNC)(void *thread_si);
//#elif defined(_X1_WINDOWS)
//typedef uint32_t __stdcall THRFUNC(void *thread_si);
//#endif

NS_X1_START

/**
 * @class	Thread
 * @brief	class for scoped locking
 */

class DECL_SPEC_DLL Thread
{
private:
	THRFUNC*	m_pFunc;
	void*		m_pArg;

public:
	Thread();

	int		Start(THRFUNC* pFunc, void* arg);
	void	Join(TimeValue *timeout = 0);

protected:

	TLS			thread_si_;

};

NS_X1_END