#include "net_select.h"

#include "event_handle.h"

#include <memory.h>

namespace wel
{
	CNetSelect::CNetSelect()
		:m_bLoopEvents(false)
		,m_uiMaxFd(0)
	{
		memset( &m_OutputArray, 0, sizeof(m_OutputArray) );
		memset( &m_InputArray, 0, sizeof(m_InputArray) );

		m_pTimeOut  = new timeval;
		memset( m_pTimeOut, 0, sizeof(timeval) );
	}

	CNetSelect::~CNetSelect()
	{
		delete m_pTimeOut;
	}

	INT CNetSelect::RegistHandle( IEventHandle *pEventHandle, UINT uiNetEvents )
	{
		if ( NULL == pEventHandle )
		{
			return NET_ERR;
		}

		if ( pEventHandle->GetHandle() > m_uiMaxFd )
		{
			m_uiMaxFd = (UINT)pEventHandle->GetHandle();
		}

		if ( uiNetEvents & IEventHandle::EVENT_READ
			|| uiNetEvents & IEventHandle::EVENT_ACCEPT )
		{
			m_InputArray.fd_array[m_InputArray.fd_count++] = pEventHandle->GetHandle();
		}

		if ( uiNetEvents & IEventHandle::EVENT_WRITE  )
		{
			m_OutputArray.fd_array[m_OutputArray.fd_count++] = pEventHandle->GetHandle();
		}

		return m_EventScheduler.RegistHandle( pEventHandle, uiNetEvents );
	}

	INT CNetSelect::RemoveHandle( IEventHandle *pEventHandle, UINT uiNetEvents )
	{
		if ( NULL == pEventHandle )
		{
			return NET_ERR;
		}

		if ( NET_OK != RemoveHandle(pEventHandle->GetHandle(), uiNetEvents) )
		{
			return NET_ERR;
		}

		return m_EventScheduler.RemoveHandle( pEventHandle, uiNetEvents );
	}

	INT CNetSelect::RemoveHandle( NET_HANDLE handle, UINT uiNetEvents )
	{
	#define REMOVE_HANDLE(fd, fset) \
		for ( UINT uiIndex=0; uiIndex<m_InputArray.fd_count; uiIndex++ )  \
					{ \
					if ( fd == fset.fd_array[uiIndex] ) \
					{ \
					fset.fd_array[uiIndex] = fset.fd_array[--fset.fd_count]; \
					break; \
				} \
			}

		if ( uiNetEvents & IEventHandle::EVENT_READ
			|| uiNetEvents & IEventHandle::EVENT_ACCEPT )
		{
			REMOVE_HANDLE( handle, m_InputArray );
		}

		if ( uiNetEvents & IEventHandle::EVENT_WRITE  )
		{
			REMOVE_HANDLE( handle, m_OutputArray );
		}

		return NET_OK;
	}

	void  CNetSelect::EventHandle( const INT iCount, fd_set &rSet, fd_set &wSet )
	{
	#ifdef OS_WIN32
		for ( UINT i=0; i<rSet.fd_count; i++ )
		{
			if( m_EventScheduler.HandleInput( rSet.fd_array[i] ) == IEventHandle::RES_REMOVE )
			{
				RemoveHandle( rSet.fd_array[i], IEventHandle::EVENT_READ );
			}
		}//end for

		for ( UINT i=0; i<wSet.fd_count; i++ )
		{
			if( m_EventScheduler.HandleOutput( wSet.fd_array[i] ) == IEventHandle::RES_REMOVE )
			{
				RemoveHandle( wSet.fd_array[i], IEventHandle::EVENT_WRITE );
			}
		}//end for
	#else 
		INT _iCount = iCount;

		for ( UINT i=0; _iCount>0 && i<m_InputArray.fd_count; i++ )
		{
			if ( FD_ISSET(m_InputArray.fd_array[i], &rSet) )
			{
				if( m_EventScheduler.HandleInput( m_InputArray.fd_array[i] ) == IEventHandle::RES_REMOVE )
				{
					RemoveHandle( m_InputArray.fd_array[i], IEventHandle::EVENT_READ );
				}

				_iCount--;
			}
		}//end for


		for ( UINT i=0; _iCount>0 && i<m_OutputArray.fd_count; i++ )
		{
			if ( FD_ISSET(m_OutputArray.fd_array[i], &wSet) )
			{
				m_EventScheduler.HandleOutput( m_OutputArray.fd_array[i] );
				_iCount--;
			}
		}//end for
	#endif 

	}

	INT CNetSelect::CheckEvents(UINT uiTimeOut)
	{
	#define TIME_OUT_RET (0)

		timeval *pTimeOut = NULL;
		if ( -1 != uiTimeOut )
		{
			m_pTimeOut->tv_sec = uiTimeOut;
			pTimeOut = m_pTimeOut;
		}

		fd_set ReadSet,WriteSet;

	#ifdef OS_WIN32
		memcpy( &ReadSet,  &m_InputArray,  sizeof(fd_set) );
		memcpy( &WriteSet, &m_OutputArray, sizeof(fd_set) );
	#else
		FD_ZERO( &ReadSet );
		FD_ZERO( &WriteSet );
		for ( UINT i=0; i<m_InputArray.fd_count; i++ )
		{
			FD_SET( m_InputArray.fd_array[i], &ReadSet );
		}//end for

		for ( UINT i=0; i<m_OutputArray.fd_count; i++ )
		{
			FD_SET( m_OutputArray.fd_array[i], &WriteSet );
		}//end for
	#endif

		INT iRet = ::select(m_uiMaxFd+1, &ReadSet, &WriteSet, NULL, pTimeOut);

		if ( TIME_OUT_RET < iRet )
		{
			EventHandle( iRet, ReadSet, WriteSet );
		}//end if

		return iRet;
	}

	INT CNetSelect::LoopEvents(UINT uiTimeOut)
	{
		m_bLoopEvents = true;

		while ( m_bLoopEvents )
		{
			CheckEvents( uiTimeOut );
		}//end while

		return NET_OK;
	}

	INT CNetSelect::EndLoopEvents()
	{
		m_bLoopEvents = false;

		return NET_OK;
	}
}
