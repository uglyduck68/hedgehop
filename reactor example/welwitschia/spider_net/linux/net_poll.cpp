#include "net_poll.h"

namespace wel
{
	#ifdef OS_WIN32

	/*#define  POLLIN  1
	#define  POLLOUT 2*/
	int poll(struct pollfd *ufds, unsigned int nfds, int timeout)
	{
		return 0;
	}

	#endif // OS_WIN32

	CNetPoll::CNetPoll()
		:m_uiTotalHandle(0)
		,m_bLoopEvents(false)
	{

	}

	INT CNetPoll::RegistHandle( IEventHandle *pEventHandle, UINT uiNetEvents )
	{
		if ( FD_SETSIZE == m_uiTotalHandle || NULL == pEventHandle )
		{
			return NET_ERR;
		}

		short events = IEventHandle::EVENT_NO;

		//接受事件
		if ( uiNetEvents & IEventHandle::EVENT_READ || 
			uiNetEvents & IEventHandle::EVENT_ACCEPT )
		{
			events = POLLIN;
		}

		//写事件
		if ( uiNetEvents & IEventHandle::EVENT_WRITE )
		{
			events = events | POLLOUT;
		}

		if ( IEventHandle::EVENT_NO == events )
		{
			return NET_ERR;
		}

		m_HandleArray[m_uiTotalHandle].uiNetEvents = uiNetEvents;
		m_HandleArray[m_uiTotalHandle].handle      = pEventHandle->GetHandle(); 

		m_PollFdArray[m_uiTotalHandle].events      = events;
		m_PollFdArray[m_uiTotalHandle].fd          = pEventHandle->GetHandle();
		m_PollFdArray[m_uiTotalHandle].revents     = 0;

		m_uiTotalHandle++;

		return m_EventScheduler.RegistHandle( pEventHandle, uiNetEvents );
	}


	INT CNetPoll::RemoveHandle( IEventHandle *pEventHandle, UINT uiNetEvents )
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


	void CNetPoll::RemoveHandle( UINT uiIndex, UINT uiNetEvents )
	{
		if ( uiIndex >= m_uiTotalHandle )
		{
			return;
		}

		m_HandleArray[uiIndex].uiNetEvents = m_HandleArray[uiIndex].uiNetEvents ^ uiNetEvents;
		if ( IEventHandle::EVENT_NO == m_HandleArray[uiIndex].uiNetEvents )
		{
			m_uiTotalHandle--;
			m_HandleArray[uiIndex]  = m_HandleArray[m_uiTotalHandle];
			m_PollFdArray[uiIndex]  = m_PollFdArray[m_uiTotalHandle];
		}
	}

	void  CNetPoll::OnNetEvents( UINT uiIndex )
	{
		pollfd &fd = m_PollFdArray[uiIndex];
		if ( fd.revents & POLLIN )
		{
			if( m_EventScheduler.HandleInput( fd.fd ) == IEventHandle::RES_REMOVE )
			{
				RemoveHandle( uiIndex, m_HandleArray[uiIndex].uiNetEvents );
			}
		}
		else if ( fd.revents & POLLOUT )
		{
			if( m_EventScheduler.HandleOutput( fd.fd ) == IEventHandle::RES_REMOVE )
			{
				RemoveHandle( uiIndex, m_HandleArray[uiIndex].uiNetEvents );
			}
		}
	}

	void  CNetPoll::EventHandle( INT iNumber )
	{
		for ( UINT i=0 ; iNumber > 0; i++ )
		{
			if ( 0 != m_PollFdArray[i].revents )
			{
				// 有网络事件
				OnNetEvents( i );
				iNumber--;
			}
		}//end for
	}

	INT CNetPoll::CheckEvents(UINT uiTimeOut)
	{
	#define TIME_OUT_RET (0)

		INT iRet = poll( m_PollFdArray, m_uiTotalHandle, uiTimeOut );

		if ( TIME_OUT_RET < iRet )
		{
			EventHandle( iRet );
		}

		return NET_OK;
	}

	INT CNetPoll::LoopEvents(UINT uiTimeOut)
	{
		m_bLoopEvents = true;

		while ( m_bLoopEvents )
		{
			CheckEvents( uiTimeOut );
		}//end while

		return NET_OK;
	}

	INT CNetPoll::EndLoopEvents()
	{
		m_bLoopEvents = false;

		return NET_OK;
	}
}//end namespace(wel)