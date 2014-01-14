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

	int	Spawn(THRDFUNC* pFunc, void* arg, int StackSize[], int CreateFlag = 0);

	/**
	 * @param	ThrNum specify the number of thread to be created
	 */
	int	Spawn(THRDFUNC* pFunc, void* arg, int ThrNum, int& GrpId, int StackSize[], int CreateFlag = 0);
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

