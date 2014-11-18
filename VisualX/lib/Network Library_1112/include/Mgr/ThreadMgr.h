/*!	@file ThreadMgr.h
 *	@brief ������ �Ŵ���
 *	@author ����(hyunpark@endcs.net)
 *	@date 2014-11-10
 */

#pragma once
#include <vector>
#include "common/Refptr.hpp"
#include <functional>
typedef std::function<void()> Work;
class TaskThreadPool;
/************************************************************************
 * ������ Ǯ Ÿ��														
 * POOL_USER : User Thread Pool
 * POOL_NETWORK : Network Thread Pool
*************************************************************************/
typedef enum {
	POOL_USER,
	POOL_NETWORK
} ThreadPoolType;

/*!	@class	ThreadMgr
 *	@brief	������ �Ŵ���
 *	@author	����(hyunpark@endcs.net)
 *	@date	2014-11-10
 */
class ThreadMgr
{
public:
	/** ������ �Ŵ����� ��ȯ�Ѵ�.
		\ �̱��� �������̽�	*/
	static ThreadMgr& GetThread();
	/** ������ �Ŵ����� �޸𸮿��� �����Ѵ�.
		\ �̱��� ����	*/
	static void ReleaseThreadMgr();
	/// ������
	ThreadMgr();
	/// �Ҹ���
	~ThreadMgr(void);
	/** �۾��� �߰��Ѵ�.
		@param work : ������Ǯ���� ������ �۾�
		@param Type : Ǯ Ÿ��(�⺻���� POOL_USER )*/
	void AddTask(Work work,int Type = POOL_USER);
	/// ������ �簳
	void Resume();
	/// ������ �Ͻ�����
	void Suspend();

private:

	ThreadMgr(const ThreadMgr&);
	ThreadMgr& operator=(const ThreadMgr&);

	std::vector<RefPtr<TaskThreadPool>> pool;
};

