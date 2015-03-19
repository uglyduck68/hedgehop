#pragma once

#include "X1.h"
#include "Thread.h"

#include <list>
#include <map>

using namespace std;

NS_X1_START

///////////////////////////////////////////////////////////////////////////////
// disalbe this class
///////////////////////////////////////////////////////////////////////////////
//class DECL_SPEC_DLL ThreadMgr
//{
//private:
//	static	ThreadMgr* volatile m_pThreadMgr;
//
//	/// sort threads on group ID
//	map<int, Thread*>		m_ListThread;
//
//	int	Fini();
//
//public:
//	ThreadMgr(void);
//	~ThreadMgr(void);
//
//	static ThreadMgr* GetInstance();
//
//	void	Push(Thread* pThrd)
//	{
//		m_ListThread.insert(pair<int, Thread*>(pThrd->GrpId(), pThrd));
//	}
//};

NS_X1_END
