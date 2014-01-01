#include "X1.h"
#include "ReactorImpl_WIN32.h"
#include "EventHandler.h"
#include "Log.h"

#include <WinSock2.h>
#include <assert.h>

NS_X1_START

	DemuxTable_WIN32::DemuxTable_WIN32()
	{
		memset(m_Table, 0x00, WSA_MAXIMUM_WAIT_EVENTS * sizeof(struct Tuple));
		memset(m_aEvent, 0x00, WSA_MAXIMUM_WAIT_EVENTS * sizeof(WSAEVENT));

		m_nMaxHandle	= 0;
	}

	DemuxTable_WIN32::~DemuxTable_WIN32()
	{
	}

	/************************************************************************/
	/* Constraints                                                          */
	/************************************************************************/
	//int DemuxTable_WIN32::ConvertToFdSets(fd_set &readset, fd_set &writeset, fd_set &exceptset, X1_SOCHANDLE &max_handle)
	//{
	//	int		nMaxHandle	= -1;

	//	for(int i = 0; i < m_nMaxHandle/*FD_SETSIZE*/; i++)
	//	{
	//		if(m_Table[i].m_pEventHandler != NULL)
	//		{
	//			if((m_Table[i].m_nEventType & EventHandler::READ_MASK) == EventHandler::READ_MASK)
	//				FD_SET(m_Table[i].m_h, &readset);
	//			if((m_Table[i].m_nEventType & EventHandler::WRITE_MASK) == EventHandler::WRITE_MASK)
	//				FD_SET(m_Table[i].m_h, &writeset);
	//			if((m_Table[i].m_nEventType & EventHandler::EXCEPT_MASK) == EventHandler::EXCEPT_MASK)
	//				FD_SET(m_Table[i].m_h, &exceptset);
	//		}
	//	}

	//	return m_nMaxHandle;
	//}

	int	DemuxTable_WIN32::Insert(EventHandler* eh, X1_SOCHANDLE h, ET et)
	{
		assert(0 <= m_nMaxHandle && m_nMaxHandle < WSA_MAXIMUM_WAIT_EVENTS);
		assert(h != NULL);

		if (WSA_MAXIMUM_WAIT_EVENTS <= m_nMaxHandle)
			return X1_FAIL;

		WSAEVENT		hEvent	= WSACreateEvent();

		if(hEvent == WSA_INVALID_EVENT)
		{
			return X1_FAIL;
		}

		m_Table[m_nMaxHandle].m_pEventHandler		= eh;
		m_Table[m_nMaxHandle].m_h					= h;
		m_Table[m_nMaxHandle].m_nEventType			= et;
		
		m_aEvent[m_nMaxHandle]						= hEvent;

		//set maximum handle value
		m_nMaxHandle++;

		return m_nMaxHandle - 1;
	}

	void DemuxTable_WIN32::MakeFree(int nIndex)
	{
		memset(&m_Table[nIndex], 0x00, sizeof(struct Tuple));
		m_aEvent[nIndex]	= NULL;
	}

	int DemuxTable_WIN32::Remove(EventHandler* eh, X1_SOCHANDLE h, ET et)
	{
		int			i		= -1;

		for(i = 0; i < m_nMaxHandle; i++)
		{
			// FIXME: when does m_Table[i].m_pEventHandler is deleted?
			if (m_Table[i].m_pEventHandler	== eh)
			{
				m_Table[i].m_pEventHandler	= NULL;
				m_Table[i].m_h				= NULL;
				m_Table[i].m_nEventType		= EventHandler::NULL_MASK;

				if (WSACloseEvent(m_aEvent[i]) == FALSE)
					return X1_FAIL;

				// move the last item to deleted position
				if (0 < m_nMaxHandle)
				{
					m_Table[i]	= m_Table[m_nMaxHandle-1];
					m_aEvent[i]	= m_aEvent[m_nMaxHandle-1];

					MakeFree(m_nMaxHandle-1);
				}

				m_nMaxHandle--;
			}
		}

		return i;
	}

	/************************************************************************/
	/* selector implementation                                              */
	/************************************************************************/

	SelectReactorImpl_WIN32::SelectReactorImpl_WIN32()
	{
		//FD_ZERO(&m_fsRead);
		//FD_ZERO(&m_fsWrite);
		//FD_ZERO(&m_fsEx);
	}

	SelectReactorImpl_WIN32::~SelectReactorImpl_WIN32()
	{

	}

	int SelectReactorImpl_WIN32::MakeEventMask(ET et, long& lNetworkEvents)
	{
		lNetworkEvents	= 0L;

		if((et & EventHandler::ACCEPT_MASK) == EventHandler::ACCEPT_MASK)
			lNetworkEvents	|= FD_ACCEPT;

		if((et & EventHandler::READ_MASK) == EventHandler::READ_MASK)
			lNetworkEvents	|= FD_READ;

		if((et & EventHandler::WRITE_MASK) == EventHandler::WRITE_MASK)
			lNetworkEvents	|= FD_WRITE;

		if((et & EventHandler::CONNECT_MASK) == EventHandler::CONNECT_MASK)
			lNetworkEvents	|= FD_CONNECT;

		if((et & EventHandler::CLOSE_MASK) == EventHandler::CLOSE_MASK)
			lNetworkEvents	|= FD_CLOSE;

		return X1_OK;
	}

	/************************************************************************/
	/* Constraints                                                          */
	/* - X1_SOCHANDLE h has integer serial number in Linux                        */
	/************************************************************************/
	int SelectReactorImpl_WIN32::RegisterHandler(EventHandler *eh, ET et)
	{
		X1_SOCHANDLE		h		= eh->GetHandle();
		WSAEVENT		hEvent;
		int				nIndex;
		int				nRet;
		long			lNetworkEvents	= 0;

		LOG_INFO("SelectReactorImpl_WIN32::RegisterHandler: Handle ID: %d\n", h);

		if ((nIndex = m_fsTable.Insert(eh, h, et)) < 0)
			return X1_FAIL;

		hEvent	= m_fsTable.GetEvent(nIndex);

		if (hEvent == NULL || hEvent == WSA_INVALID_EVENT)
		{
			LOG_ERROR("hEvent is NULL\n");

			return X1_FAIL;
		}

		/// FIXME: make OS-specific network event mask from our mask
		MakeEventMask(et, lNetworkEvents);

		nRet	= WSAEventSelect(h, hEvent, lNetworkEvents);

		if (nRet == SOCKET_ERROR)
		{
			LOG_ERROR("WSAEventSelect fails\n");

			return X1_FAIL;
		}


		return X1_OK;
	}

	int SelectReactorImpl_WIN32::RemoveHandler(EventHandler *eh, ET et)
	{
		X1_SOCHANDLE		h	= eh->GetHandle();

		if (m_fsTable.Remove(eh, h, et) != X1_OK)
			return X1_FAIL;

		return X1_OK;
	}

	int SelectReactorImpl_WIN32::HandleEvent(TimeValue *timeout /* = 0 */)
	{
		int		nIndex	= 0;
		int		nRet	= 0;
		int		nMaxHandle	= GetMaxHandle();

		assert(0 < nMaxHandle && nMaxHandle <= WSA_MAXIMUM_WAIT_EVENTS);

		WSANETWORKEVENTS	NetworkEvents;
#if	0
		for(int i = 0; i < nMaxHandle; i++)
			printf("sock[%d]: %d, event[%d] value: %d, # of handle: %d\n", 
			i, m_fsTable.m_Table[i].m_h, i, m_fsTable.m_aEvent[i], nMaxHandle);
#endif

		/// WSAWaitForMultipleEvents wait for WSA_INFINITE and *NOT* occur FD_WRITE event
		nIndex	= WSAWaitForMultipleEvents(nMaxHandle, m_fsTable.m_aEvent, FALSE, WSA_INFINITE, FALSE);

		if (nIndex == WSA_WAIT_FAILED)
		{
			LOG_ERROR("WSAWaitForMultipleEvents fails\n");

			return X1_FAIL;
		}
		else if (nIndex == WSA_WAIT_TIMEOUT)
		{
			return X1_OK;
		}
		        
		// Reset the signaled event
        nRet	= WSAResetEvent(m_fsTable.m_aEvent[nIndex - WSA_WAIT_EVENT_0]);
        if (nRet == FALSE) 
		{
            LOG_ERROR("WSAResetEvent failed with error = %d\n", WSAGetLastError());

			return X1_FAIL;
        }

		nIndex	-= WSA_WAIT_EVENT_0;

		nRet	= WSAEnumNetworkEvents( m_fsTable.m_Table[nIndex].m_h, m_fsTable.m_aEvent[nIndex], &NetworkEvents);

		if(nRet == SOCKET_ERROR)
		{
			LOG_ERROR("WSAEnumNetworkEvents fails\n");

			return X1_FAIL;
		}

		if (NetworkEvents.lNetworkEvents & FD_ACCEPT)
		{
			if (NetworkEvents.iErrorCode[FD_ACCEPT_BIT] != 0)
			{
				LOG_WARNING("iErrorCode[FD_ACCEPT_BIT] is *NOT* 0\n");
//				continue;
			}

			m_fsTable.m_Table[nIndex].m_pEventHandler->HandleRead(m_fsTable.m_Table[nIndex].m_h);

			LOG_INFO("FD_ACCEPT: Handle ID: %d, nIndex: %d, # of handles: %d\n", m_fsTable.m_Table[nIndex].m_h, nIndex, nMaxHandle);
		}

		else if (NetworkEvents.lNetworkEvents & FD_READ)
		{
			if (NetworkEvents.iErrorCode[FD_READ_BIT] != 0)
			{
				LOG_WARNING("iErrorCode[FD_READ_BIT] is *NOT* 0\n");
//				continue;
			}

			m_fsTable.m_Table[nIndex].m_pEventHandler->HandleRead(m_fsTable.m_Table[nIndex].m_h);

			LOG_INFO("FD_READ: Handle ID: %d, nIndex: %d, # of handles: %d\n", m_fsTable.m_Table[nIndex].m_h, nIndex, nMaxHandle);
		}

		else if (NetworkEvents.lNetworkEvents & FD_WRITE)
		{
			if (NetworkEvents.iErrorCode[FD_WRITE_BIT] != 0)
			{
				LOG_WARNING("iErrorCode[FD_WRITE_BIT] is *NOT* 0\n");
//				continue;
			}

			m_fsTable.m_Table[nIndex].m_pEventHandler->HandleWrite(m_fsTable.m_Table[nIndex].m_h);

			LOG_INFO("FD_WRITE: Handle ID: %d, nIndex: %d, # of handles: %d\n", m_fsTable.m_Table[nIndex].m_h, nIndex, nMaxHandle);
		}

		else if (NetworkEvents.lNetworkEvents & FD_CLOSE)
		{
			if (NetworkEvents.iErrorCode[FD_WRITE_BIT] != 0)
			{
				LOG_WARNING("iErrorCode[FD_WRITE_BIT] is *NOT* 0\n");
//				continue;
			}

			m_fsTable.m_Table[nIndex].m_pEventHandler->HandleClose(m_fsTable.m_Table[nIndex].m_h);

			LOG_INFO("FD_CLOSE: Handle ID: %d, nIndex: %d, # of handles: %d\n", m_fsTable.m_Table[nIndex].m_h, nIndex, nMaxHandle);
		}
		else
		{
			LOG_INFO("FD_XXX: Handle ID: %d, nIndex: %d, # of handles: %d\n", m_fsTable.m_Table[nIndex].m_h, nIndex, nMaxHandle);
		}

		return X1_OK;
	}

NS_X1_END