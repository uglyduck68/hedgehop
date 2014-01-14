#pragma once


#include "X1.h"
#include "Thread.h"

NS_X1_START

/**
 * @class	Task class
 * @brief	This class is used to make thread
 */
class DECL_SPEC_DLL Task
{
public:

			 Task() {}
	virtual ~Task() {}

	int	Spawn(THRDFUNC* pFunc, void* arg, int CreateFlag = 0, int StackSize = -1);

	/**
	 * @param	ThrNum specify the number of thread to be created
	 */
	int	Spawn(THRDFUNC* pFunc, void* arg, int ThrNum, int& GrpId, int CreateFlag = 0, int StackSize = -1);
	void	Join(TimeValue *timeout = 0);
	int		Suspend();
	int		Resume();
	int		Kill();
};

NS_X1_END

