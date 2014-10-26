/*!	@file	rmWinThread.h
 *	@brief	스레드 클래스를 상속받아 windows 에 맞게 구현한 클래스 선언
 *	@author	이현우 (hwlee@endcs.net)
 *	@date	2014-2-6
 */

#ifndef RM_INCLUDE_RMWINTHREAD_H_
#define RM_INCLUDE_RMWINTHREAD_H_

#include "common/rmThread.h"

#include <Windows.h>
#include <process.h>

//--------------------------------------------------------------------------
class rmWinThread : public rmThread
{
private:
	rmWinThread(const rmWinThread&);
	rmWinThread& operator=(const rmWinThread&);
public:
	rmWinThread();
	virtual ~rmWinThread();
	virtual void Start();
	virtual void Stop();

private:	
	HANDLE m_hThread;
	unsigned int m_threadid;
};

#endif // RM_INCLUDE_RMWINTHREAD_H_