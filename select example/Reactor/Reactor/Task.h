#pragma once

/**
 * @file Task.h
 *
 * @author sean <uglyduck68@gmail.com>
 *
 * Define user thread class
 * 
 */

#include "X1.h"
#include "Thread.h"

NS_X1_START

/**
 * @class	Task class
 * @brief	This class is used to make thread
 * This class is the base class for user thread.
 */
class DECL_SPEC_DLL Task
{
public:

			 Task() {}
	virtual ~Task() {}

	/// spawn a thread
	int	Spawn(THRDFUNC* pFunc, void* pArg, thread_id_t* pThreadId, int nStackSize, int nCreateFlag, int nPriority);


	/**
	 * @param	ThrNum specify the number of thread to be created
	 */
	int	Spawn(THRDFUNC* pFunc, void* pArg, int nThrNum, int& GrpId, thread_id_t* pThreadId[], int nStackSize, int nCreateFlag, int nPriority);
	void	Join(TimeValue *timeout = 0);
	void	Wait(TimeValue *timeout = 0)
	{
		Join(timeout);
	}
	int		Suspend();
	int		Resume();
	int		Kill();
};

NS_X1_END

