/*!	@file ThreadMgr.h
 *	@brief 스레드 매니저
 *	@author 박현(hyunpark@endcs.net)
 *	@date 2014-11-10
 */

#pragma once
#include <vector>
#include "common/Refptr.hpp"
#include <functional>
typedef std::function<void()> Work;
class TaskThreadPool;
/************************************************************************
 * 쓰레드 풀 타입														
 * POOL_USER : User Thread Pool
 * POOL_NETWORK : Network Thread Pool
*************************************************************************/
typedef enum {
	POOL_USER,
	POOL_NETWORK
} ThreadPoolType;

/*!	@class	ThreadMgr
 *	@brief	스레드 매니저
 *	@author	박현(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class ThreadMgr
{
public:
	/** 스레드 매니저를 반환한다.
		\ 싱글턴 인터페이스	*/
	static ThreadMgr& GetThread();
	/** 스레드 매니저를 메모리에서 제거한다.
		\ 싱글턴 해제	*/
	static void ReleaseThreadMgr();
	/// 생성자
	ThreadMgr();
	/// 소멸자
	~ThreadMgr(void);
	/** 작업을 추가한다.
		@param work : 스레드풀에서 수행할 작업
		@param Type : 풀 타입(기본값은 POOL_USER )*/
	void AddTask(Work work,int Type = POOL_USER);
	/// 스레드 재개
	void Resume();
	/// 스레드 일시정지
	void Suspend();

private:

	ThreadMgr(const ThreadMgr&);
	ThreadMgr& operator=(const ThreadMgr&);

	std::vector<RefPtr<TaskThreadPool>> pool;
};

