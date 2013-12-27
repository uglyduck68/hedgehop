#include "X1.h"
#include "ReactorImpl.h"
#include "ReactorImpl_WIN32_select.h"
#include "EventHandler.h"

#include <WinSock2.h>
#include <assert.h>

namespace X1
{
	DemuxTable_WIN32_select::DemuxTable_WIN32_select()
	{
		memset(m_Table, 0x00, FD_SETSIZE * sizeof(struct Tuple));

		m_nMaxHandle	= 0;
	}

	DemuxTable_WIN32_select::~DemuxTable_WIN32_select()
	{
	}

	/************************************************************************/
	/* Constraints                                                          */
	/************************************************************************/
	int DemuxTable_WIN32_select::ConvertToFdSets(fd_set &readset, fd_set &writeset, fd_set &exceptset, X1_SOCHANDLE &max_handle)
	{
		int		i	= -1;

		for(i = 0; i < m_nMaxHandle/*FD_SETSIZE*/; i++)
		{
			if(m_Table[i].m_pEventHandler != NULL)
			{
				if((m_Table[i].m_nEventType & EventHandler::ACCEPT_MASK) == EventHandler::ACCEPT_MASK)
					FD_SET(m_Table[i].m_h, &readset);

				if((m_Table[i].m_nEventType & EventHandler::READ_MASK) == EventHandler::READ_MASK)
					FD_SET(m_Table[i].m_h, &readset);

				if((m_Table[i].m_nEventType & EventHandler::WRITE_MASK) == EventHandler::WRITE_MASK)
					FD_SET(m_Table[i].m_h, &writeset);

				if((m_Table[i].m_nEventType & EventHandler::EXCEPT_MASK) == EventHandler::EXCEPT_MASK)
					FD_SET(m_Table[i].m_h, &exceptset);
			}
		}

		return i;
	}

	/**
	 * @return	-1 : error return
	 *			n  : index of m_Table array
	 */
	int	DemuxTable_WIN32_select::Insert(EventHandler* eh, X1_SOCHANDLE h, ET et)
	{
		assert(0 <= m_nMaxHandle && m_nMaxHandle < FD_SETSIZE);
		assert(h != NULL);

		if (FD_SETSIZE <= m_nMaxHandle)
			return -1;

		m_Table[m_nMaxHandle].m_pEventHandler		= eh;
		m_Table[m_nMaxHandle].m_h					= h;
		m_Table[m_nMaxHandle].m_nEventType			= et;

		//set maximum handle value
		m_nMaxHandle++;

		return m_nMaxHandle - 1;
	}

	void DemuxTable_WIN32_select::MakeFree(int nIndex)
	{
		memset(&m_Table[nIndex], 0x00, sizeof(struct Tuple));
	}

	int DemuxTable_WIN32_select::Remove(EventHandler* eh, X1_SOCHANDLE h, ET et)
	{
		int			i		= -1;

		for(i = 0; i < m_nMaxHandle; i++)
		{
			if (m_Table[i].m_pEventHandler	== eh)
			{
				m_Table[i].m_pEventHandler	= NULL;
				m_Table[i].m_h				= NULL;
				m_Table[i].m_nEventType		= EventHandler::NULL_MASK;

				// move the last item to deleted position
				if (0 < m_nMaxHandle)
				{
					m_Table[i]	= m_Table[m_nMaxHandle-1];

					MakeFree(m_nMaxHandle-1);
				}

				if (m_nMaxHandle > 0)
					m_nMaxHandle--;
			}
		}

		return i;
	}

	/************************************************************************/
	/* selector implementation                                              */
	/************************************************************************/

	SelectReactorImpl_WIN32_select::SelectReactorImpl_WIN32_select()
	{
		FD_ZERO(&m_fsRead);
		FD_ZERO(&m_fsWrite);
		FD_ZERO(&m_fsEx);
	}

	SelectReactorImpl_WIN32_select::~SelectReactorImpl_WIN32_select()
	{

	}

	int SelectReactorImpl_WIN32_select::MakeEventMask(ET et, long& lNetworkEvents)
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
	int SelectReactorImpl_WIN32_select::RegisterHandler(EventHandler *eh, ET et)
	{
		X1_SOCHANDLE		h	= eh->GetHandle();

		if (m_fsTable.Insert(eh, h, et) != X1_OK)
			return X1_FAIL;


		//set appropriate bits to FD SETs
		if((et & EventHandler::ACCEPT_MASK) == EventHandler::ACCEPT_MASK)
			FD_SET(h, &m_fsRead);

		if((et & EventHandler::READ_MASK) == EventHandler::READ_MASK)
			FD_SET(h, &m_fsRead);

		if((et & EventHandler::WRITE_MASK) == EventHandler::WRITE_MASK)
			FD_SET(h, &m_fsWrite);

		if((et & EventHandler::EXCEPT_MASK) == EventHandler::EXCEPT_MASK)
			FD_SET(h, &m_fsEx);

		return X1_OK;
	}

	int SelectReactorImpl_WIN32_select::RemoveHandler(EventHandler *eh, ET et)
	{
		X1_SOCHANDLE		h	= eh->GetHandle();

		if (m_fsTable.Remove(eh, h, et) != X1_OK)
			return X1_FAIL;

		//set appropriate bits to FD SETs
		if((et & EventHandler::READ_MASK) == EventHandler::READ_MASK)
			FD_CLR(h, &m_fsRead);

		if((et & EventHandler::WRITE_MASK) == EventHandler::WRITE_MASK)
			FD_CLR(h, &m_fsWrite);

		if((et & EventHandler::EXCEPT_MASK) == EventHandler::EXCEPT_MASK)
			FD_CLR(h, &m_fsEx);

		return X1_OK;
	}

	int SelectReactorImpl_WIN32_select::HandleEvent(TimeValue *timeout /* = 0 */)
	{
		int		nIndex	= 0;
		int		nRet	= 0;
		int		nMaxHandle	= GetMaxHandle();
		X1_SOCHANDLE	hMaxHandle;
		fd_set		readset, writeset, exceptset;

		/// there is no handle to handle
		if (nMaxHandle <= 0)
			return X1_OK;

		FD_ZERO(&readset);
		FD_ZERO(&writeset);
		FD_ZERO(&exceptset);

		m_fsTable.ConvertToFdSets(readset, writeset, exceptset, hMaxHandle);


		int result = select(nMaxHandle, &readset, &writeset, &exceptset, (const timeval *)&timeout);

		if(result < 0)
		{
			return X1_FAIL;
		}

		for(int h = 0; h < nMaxHandle; h++)
		{
			X1_SOCHANDLE		hh	= m_fsTable.m_Table[h].m_pEventHandler->GetHandle();

			//We should check for incoming events in each SOCKET
			if(m_fsTable.m_Table[h].m_pEventHandler && FD_ISSET(hh, &readset))
			{
				if(m_fsTable.m_Table[h].m_pEventHandler)
				{
					/**
					 * FIXME: We should implement HandRead function as a thread of threadpool
					 */
					if (m_fsTable.m_Table[h].m_pEventHandler->HandleRead(hh) == X1_CLOSED)
					{
						m_fsTable.m_Table[h].m_pEventHandler->HandleClose(hh);

						RemoveHandler(m_fsTable.m_Table[h].m_pEventHandler, EventHandler::ALL_EVENTS_MASK);
					}
				}
				else
					LOG_INTERNAL("Error: at(%s:%d)\n", __FILE__, __LINE__);
			}

			if(m_fsTable.m_Table[h].m_pEventHandler && FD_ISSET(hh, &writeset))
			{
				if(m_fsTable.m_Table[h].m_pEventHandler)
				{
					if (m_fsTable.m_Table[h].m_pEventHandler->HandleWrite(hh) == X1_CLOSED)
					{
						m_fsTable.m_Table[h].m_pEventHandler->HandleClose(hh);

						RemoveHandler(m_fsTable.m_Table[h].m_pEventHandler, EventHandler::ALL_EVENTS_MASK);
					}
				}
				else
					LOG_INTERNAL("Error: at(%s:%d)\n", __FILE__, __LINE__);
			}

			if(m_fsTable.m_Table[h].m_pEventHandler && FD_ISSET(hh, &exceptset))
			{
				if(m_fsTable.m_Table[h].m_pEventHandler)
					(m_fsTable.m_Table[h].m_pEventHandler)->HandleException(hh);
				else
					LOG_INTERNAL("Error: at(%s:%d)\n", __FILE__, __LINE__);
			}
		}

		return X1_OK;
	}

}