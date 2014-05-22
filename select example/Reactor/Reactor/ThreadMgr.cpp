#include "ThreadMgr.h"
#include "Mutex.h"
#include "Guard.h"

NS_X1_START

///////////////////////////////////////////////////////////////////////////////
// disalbe this class
///////////////////////////////////////////////////////////////////////////////

//ThreadMgr* volatile ThreadMgr::m_pThreadMgr	= NULL;
//
//ThreadMgr::ThreadMgr(void)
//{
//}
//
//
//ThreadMgr::~ThreadMgr(void)
//{
//	Fini();
//
//	DEL(m_pThreadMgr);
//}
//
//
//int	ThreadMgr::Fini()
//{
//	return X1_OK;
//}
//
//ThreadMgr* ThreadMgr::GetInstance()
//{
//	/**
//	* NOTE: should apply Double Checked Locking
//	*/
//	if (m_pThreadMgr == NULL)
//	{
//		Mutex				mutex;
//		Guard<Mutex>		lock(mutex);
//
//		if (m_pThreadMgr == NULL)
//			m_pThreadMgr	= new ThreadMgr;
//	}
//
//	return m_pThreadMgr;
//}

NS_X1_END
