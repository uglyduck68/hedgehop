#include "thread_kit.h"

#ifdef OS_LINUX
#include <pthread.h>
typedef void* (*START_ROUTINE)(void *); 
#endif

namespace wel
{

	CThreadWrapper::CThreadWrapper()
		:m_dwThreadId(0)
		,m_pParams(NULL)
		,m_ThreadProc(NULL)
		#ifdef OS_WIN32
			,m_hThread(NULL)
		#endif
	{

	}

	CThreadWrapper::~CThreadWrapper()
	{
	#ifdef OS_WIN32
		if ( NULL != m_hThread )
		{
			::CloseHandle( m_hThread );
		}
	#elif defined(OS_LINUX)

	#endif
	}

	CThreadWrapper::CThreadWrapper( const CThreadWrapper &other )
		:m_dwThreadId(0)
		,m_pParams(NULL)
		,m_ThreadProc(NULL)
		#ifdef OS_WIN32
			,m_hThread(NULL)
		#endif
	{
		if ( NULL != m_ThreadProc && Create( other.m_ThreadProc, other.m_pParams ) )
		{
			throw;
		}
	}

	CThreadWrapper& CThreadWrapper::operator = ( const CThreadWrapper &other )
	{
		m_dwThreadId = 0;
		m_pParams    = NULL;
		m_ThreadProc = NULL;

	#ifdef OS_WIN32
		m_hThread    = NULL;
	#elif defined(OS_LINUX)

	#endif

		if ( NULL != m_ThreadProc && Create( other.m_ThreadProc, other.m_pParams ) )
		{
			throw;
		}

		return *this;
	}

	BOOL CThreadWrapper::Create(THREAD_PROC ThreadProc, void *pParams)
	{
		BOOL bRet = FALSE;

	#ifdef OS_WIN32
		m_hThread = ::CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc, 
			pParams, 0, (LPDWORD)&m_dwThreadId );

		if ( NULL != m_hThread )
		{
			bRet = TRUE;
		}
	#elif defined(OS_LINUX)
		if( !pthread_create((pthread_t*)&m_dwThreadId, NULL, (START_ROUTINE)ThreadProc, pParams) )
		{
			bRet = TRUE;
		}
	#endif

		if ( bRet )
		{
			m_pParams    = pParams;
			m_ThreadProc = ThreadProc;
		}
		return bRet;
	}

	///挂起
	BOOL CThreadWrapper::Suspend()
	{
	#ifdef OS_WIN32
		if(m_hThread != NULL)
		{
			return SuspendThread(m_hThread)==0xFFFFFFFF?false:true;
		}
	#elif defined(OS_LINUX)

	#endif
		return true;
	}

	BOOL CThreadWrapper::Resume()
	{
		return false;
	}

	UINT CThreadWrapper::WaitFor(UINT *pRetCode, UINT dwMilliseconds/* =INFINITE */)
	{
		UINT  ret = 0;

	#ifdef OS_WIN32
		if(m_hThread != NULL)
		{
			ret = ::WaitForSingleObject(m_hThread,dwMilliseconds);
			if ( NULL != pRetCode )
			{
				//获取返回值
				::GetExitCodeThread( m_hThread, (LPDWORD)pRetCode );
			}
		}
	#elif defined(OS_LINUX)
		::pthread_join((pthread_t)m_dwThreadId, (void **)pRetCode);
	#endif

		return ret;
	}

	void  CThreadWrapper::Kill(UINT uiExitCode)
	{
	#ifdef OS_WIN32
		if(m_hThread != NULL)
		{
			::TerminateThread(m_hThread, uiExitCode);
			m_hThread = NULL;
		}
	#elif defined(OS_LINUX)

	#endif
	}

	/*BOOL  CThreadWrapper::GetExitCode( UINT &uiExitCode )
	{
	#ifdef OS_WIN32
		return ::GetExitCodeThread( m_hThread, (LPDWORD)&uiExitCode );
	#else
		return FALSE;
	#endif
	}*/

	//========================================================================

	CActiveObject::CActiveObject()
	:m_bWork(FALSE)
	{

	}

	void CActiveObject::Deactive()
	{
		m_bWork = FALSE;
	}

	BOOL CActiveObject::Active()
	{
		// m_bWork 当创建线程的时候(线程执行结束此时m_bWork=FALSE,此时CThreadWrapper::Create未结束)
		// 这时候CThreadWrapper::Create是成功的它返回了TRUE，这时候m_bWork=TRUE。
		return CThreadWrapper::Create( CActiveObject::ThreadProc, this );
	}

	UINT  CActiveObject::ThreadProc(void *pParams)
	{
		CActiveObject *pThis = (CActiveObject *)pParams;

		// 线程真正工作的函数
		pThis->m_bWork = TRUE;
		UINT iRet    = pThis->Work();
		pThis->m_bWork = FALSE;

		// 最后调用的方法
		pThis->Final();

		return iRet;
	}

}//end namespace(wel)
