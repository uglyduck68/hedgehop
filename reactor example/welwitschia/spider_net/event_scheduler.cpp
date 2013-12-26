#include "event_scheduler.h"
#include "event_handle.h"

namespace wel
{
	CEventScheduler::~CEventScheduler()
	{
		CHandleMap::iterator itor;

		for ( itor=m_HandleMap.begin(); itor != m_HandleMap.end(); ++itor )
		{
			itor->second.pEventHandle->Final();
		}//end for

		m_HandleMap.clear();
	}

	INT CEventScheduler::RegistHandle( IEventHandle *pEventHandle, UINT uiNetEvents )
	{
		if ( NULL == pEventHandle )
		{
			return NET_ERR;
		}

		struHandleEvent &HandleEvent = m_HandleMap[pEventHandle->GetHandle()];

		HandleEvent.pEventHandle = pEventHandle;
		HandleEvent.uiNetEvents |= uiNetEvents;

		return NET_OK;
	}

	INT CEventScheduler::RemoveHandle( IEventHandle *pEventHandle, UINT uiNetEvents )
	{	
		if ( NULL == pEventHandle )
		{
			return NET_ERR;
		}

		CHandleMap::iterator itor = m_HandleMap.find( pEventHandle->GetHandle() );

		if ( m_HandleMap.end() == itor )
		{
			return NET_ERR;
		}

		itor->second.uiNetEvents ^= uiNetEvents;
		if ( IEventHandle::EVENT_NO == itor->second.uiNetEvents )
		{
			pEventHandle->Final();
			m_HandleMap.erase(itor);

			return NET_OK;
		}//end if

		return NET_ERR;
	}

	INT CEventScheduler::HandleInput(NET_HANDLE handle)
	{
		CHandleMap::iterator itor = m_HandleMap.find(handle);

		if ( m_HandleMap.end() == itor  )
		{
			return NET_ERR;
		}

		if ( !(itor->second.uiNetEvents & IEventHandle::EVENT_READ)
			&& !(itor->second.uiNetEvents & IEventHandle::EVENT_ACCEPT) )
		{
			return NET_OK;
		}

		IEventHandle *pEventHandle = itor->second.pEventHandle;
		INT iRet = pEventHandle->OnInput();

		if(	 IEventHandle::RES_REMOVE == iRet )
		{
			RemoveHandle( pEventHandle, IEventHandle::EVENT_READ );
		}

		return iRet;
	}

	INT CEventScheduler::HandleOutput(NET_HANDLE handle)
	{
		return NET_OK;
	}
}//end namespace(wel)
