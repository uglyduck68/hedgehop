#include "net_event_select.h"

#include "event_handle.h"

namespace wel
{
	CNetEventSelect::CNetEventSelect()
		:m_uiTotalHandle(0)
		,m_bLoopEvents(false)
	{

	}

	INT CNetEventSelect::RegistHandle( IEventHandle *pEventHandle, UINT uiNetEvents )
	{
		if ( WSA_MAXIMUM_WAIT_EVENTS == m_uiTotalHandle || NULL == pEventHandle )
		{
			return NET_ERR;
		}

		UINT lNetworkEvents = 0;
		//接受事件
		if ( uiNetEvents & IEventHandle::EVENT_ACCEPT )
		{
			lNetworkEvents = FD_ACCEPT;
		}

		//读事件
		if ( uiNetEvents & IEventHandle::EVENT_READ )
		{
			lNetworkEvents = lNetworkEvents | FD_READ;
			lNetworkEvents = lNetworkEvents | FD_CLOSE;
		}

		//写事件
		if ( uiNetEvents & IEventHandle::EVENT_WRITE )
		{
			lNetworkEvents = lNetworkEvents | FD_WRITE;
		}

		if ( IEventHandle::EVENT_NO == lNetworkEvents )
		{
			return NET_ERR;
		}

		WSAEVENT hEvent = ::WSACreateEvent();
		if ( WSA_INVALID_EVENT == hEvent )
		{
			return NET_ERR;
		}

		if ( SOCKET_ERROR == ::WSAEventSelect( pEventHandle->GetHandle(), hEvent, lNetworkEvents ) )
		{
			::WSACloseEvent( hEvent );
			return NET_ERR;
		}

		m_HandleArray[m_uiTotalHandle].uiNetEvents = uiNetEvents;
		m_HandleArray[m_uiTotalHandle].handle      = pEventHandle->GetHandle(); 
		m_EventArray[m_uiTotalHandle]              = hEvent;
		m_uiTotalHandle++;

		return m_EventScheduler.RegistHandle( pEventHandle, uiNetEvents );
	}

	INT CNetEventSelect::RemoveHandle( IEventHandle *pEventHandle, UINT uiNetEvents )
	{
		if ( NULL == pEventHandle )
		{
			return NET_ERR;
		}

		if ( NET_OK != m_EventScheduler.RemoveHandle( pEventHandle, uiNetEvents ) )
		{
			return NET_ERR;
		}

		for ( UINT i=0; i<m_uiTotalHandle; i++ )
		{
			if ( m_HandleArray[i].handle == pEventHandle->GetHandle() )
			{
				RemoveHandle( i, uiNetEvents );
				break;
			}
		}//end for

		return NET_OK;
	}

	void CNetEventSelect::RemoveHandle( UINT uiIndex,UINT uiNetEvents )
	{
		if ( uiIndex >= m_uiTotalHandle )
		{
			return;
		}

		m_HandleArray[uiIndex].uiNetEvents = m_HandleArray[uiIndex].uiNetEvents ^ uiNetEvents;
		if ( IEventHandle::EVENT_NO == m_HandleArray[uiIndex].uiNetEvents )
		{
			m_uiTotalHandle--;
			m_HandleArray[uiIndex] = m_HandleArray[m_uiTotalHandle];
			m_EventArray[uiIndex]  = m_EventArray[m_uiTotalHandle];
		}
	}

	INT CNetEventSelect::OnNetEvents( UINT uiIndex )
	{
		WSANETWORKEVENTS NetworkEvents;

		::WSAEnumNetworkEvents( m_HandleArray[uiIndex].handle, m_EventArray[uiIndex], 
			&NetworkEvents );

		if( NetworkEvents.lNetworkEvents & FD_READ ||
			NetworkEvents.lNetworkEvents & FD_CLOSE )
		{
			if( m_EventScheduler.HandleInput( m_HandleArray[uiIndex].handle ) == IEventHandle::RES_REMOVE )
			{
				RemoveHandle( uiIndex, IEventHandle::EVENT_READ );
			}
		}
		else if ( NetworkEvents.lNetworkEvents & FD_ACCEPT )
		{
			if( m_EventScheduler.HandleInput( m_HandleArray[uiIndex].handle ) == IEventHandle::RES_REMOVE )
			{
				RemoveHandle( uiIndex, IEventHandle::EVENT_ACCEPT );
			}
		}
		else
		{
		}

		return NET_OK;
	}

	INT CNetEventSelect::CheckEvents( UINT uiTimeOut )
	{
		UINT uiIndex = ::WSAWaitForMultipleEvents( m_uiTotalHandle, m_EventArray, 
			FALSE, uiTimeOut, FALSE );

		// 超时
		if ( WSA_WAIT_TIMEOUT == uiIndex )
		{
			return NET_OK;
		}

		if ( WSA_WAIT_FAILED == uiIndex )
		{
			return NET_ERR;
		}	

		return OnNetEvents( uiIndex - WSA_WAIT_EVENT_0 );
	}

	INT CNetEventSelect::EndLoopEvents()
	{
		m_bLoopEvents = false;

		return NET_OK;
	}

	INT CNetEventSelect::LoopEvents( UINT uiTimeOut )
	{
		m_bLoopEvents = true;

		while ( m_bLoopEvents )
		{
			CheckEvents( uiTimeOut );
		}//end while

		return NET_OK;
	}
}//end namespace(wel)
