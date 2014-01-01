#include "X1.h"
#include "ReactorImpl.h"
#include "EventHandler.h"

#include <WinSock2.h>
#include <assert.h>

NS_X1_START

	DemuxTable::DemuxTable()
	{
		memset(m_Table, 0x00, FD_SETSIZE * sizeof(struct Tuple));

		m_nMaxHandle	= 0;
	}

	DemuxTable::~DemuxTable()
	{
	}

	/************************************************************************/
	/* Constraints                                                          */
	/************************************************************************/
	int DemuxTable::ConvertToFdSets(fd_set &readset, fd_set &writeset, fd_set &exceptset, X1_SOCHANDLE &max_handle)
	{
		int		nMaxHandle	= -1;

		for(int i = 0; i < m_nMaxHandle/*FD_SETSIZE*/; i++)
		{
			if(m_Table[i].m_pEventHandler != NULL)
			{
				if((m_Table[i].m_nEventType & EventHandler::READ_MASK) == EventHandler::READ_MASK)
					FD_SET(m_Table[i].m_h, &readset);
				if((m_Table[i].m_nEventType & EventHandler::WRITE_MASK) == EventHandler::WRITE_MASK)
					FD_SET(m_Table[i].m_h, &writeset);
				if((m_Table[i].m_nEventType & EventHandler::EXCEPT_MASK) == EventHandler::EXCEPT_MASK)
					FD_SET(m_Table[i].m_h, &exceptset);
			}
		}

		return m_nMaxHandle;
	}

	int	DemuxTable::Insert(EventHandler* eh, X1_SOCHANDLE h, ET et)
	{
		//assert(0 <= m_nMaxHandle && m_nMaxHandle < FD_SETSIZE);
		assert(h != NULL);

		if (FD_SETSIZE <= m_nMaxHandle)
			return X1_FAIL;

		m_Table[m_nMaxHandle].m_pEventHandler		= eh;
		m_Table[m_nMaxHandle].m_h					= h;
		m_Table[m_nMaxHandle].m_nEventType			= et;

		//set maximum handle value
		m_nMaxHandle++;

		return X1_OK;
	}

	int DemuxTable::Remove(EventHandler* eh, X1_SOCHANDLE h, ET et)
	{
		RET_TYPE	ret		= X1_FAIL;

		for(int i = 0; i < m_nMaxHandle; i++)
		{
			if (m_Table[i].m_h	== h)
			{
				m_Table[i].m_pEventHandler	= NULL;
				m_Table[i].m_h				= NULL;
				m_Table[i].m_nEventType		= EventHandler::NULL_MASK;

				// move the last item to deleted position
				if (0 < m_nMaxHandle)
					m_Table[i]	= m_Table[m_nMaxHandle-1];

				m_nMaxHandle--;

				ret		= X1_OK;
			}
		}

		return ret;
	}

	/************************************************************************/
	/* selector implementation                                              */
	/************************************************************************/

	SelectReactorImpl::SelectReactorImpl()
	{
		FD_ZERO(&m_fsRead);
		FD_ZERO(&m_fsWrite);
		FD_ZERO(&m_fsEx);
	}

	SelectReactorImpl::~SelectReactorImpl()
	{

	}

	/************************************************************************/
	/* Constraints                                                          */
	/* - X1_SOCHANDLE h has integer serial number in Linux                        */
	/************************************************************************/
	int SelectReactorImpl::RegisterHandler(EventHandler *eh, ET et)
	{
		X1_SOCHANDLE		h	= eh->GetHandle();

		if (m_fsTable.Insert(eh, h, et) != X1_OK)
			return X1_FAIL;


		assert(0 <= h && h < FD_SETSIZE);

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

	int SelectReactorImpl::RemoveHandler(EventHandler *eh, ET et)
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

	int SelectReactorImpl::HandleEvent(TimeValue *timeout /* = 0 */)
	{
		int			max_handle;
		X1_SOCHANDLE	hMaxHandle;
		fd_set		readset, writeset, exceptset;

		FD_ZERO(&readset);
		FD_ZERO(&writeset);
		FD_ZERO(&exceptset);

		max_handle	= m_fsTable.ConvertToFdSets(readset, writeset, exceptset, hMaxHandle/*max_handle*/);

		if (max_handle <= 0)
		{
			return X1_FAIL;
		}

		int result = select(max_handle, &readset, &writeset, &exceptset, (const timeval *)&timeout);

		if(result < 0)
		{
			return X1_FAIL;
		}

		for(int h = 0; h < max_handle; h++)
		{
			X1_SOCHANDLE		hh	= m_fsTable.m_Table[h].m_pEventHandler->GetHandle();

			//We should check for incoming events in each SOCKET
			if(FD_ISSET(hh, &readset))
			{
				if(m_fsTable.m_Table[h].m_pEventHandler)
					/**
					 * NOTE: We should implement HandRead function as a thread of threadpool
					 */
					(m_fsTable.m_Table[h].m_pEventHandler)->HandleRead(hh);
				else
					LOG_INTERNAL("Error: at(%s:%d)\n", __FILE__, __LINE__);

				continue;
			}

			if(FD_ISSET(hh, &writeset))
			{
				if(m_fsTable.m_Table[h].m_pEventHandler)
					(m_fsTable.m_Table[h].m_pEventHandler)->HandleWrite(hh);
				else
					LOG_INTERNAL("Error: at(%s:%d)\n", __FILE__, __LINE__);

				continue;
			}

			if(FD_ISSET(hh, &exceptset))
			{
				if(m_fsTable.m_Table[h].m_pEventHandler)
					(m_fsTable.m_Table[h].m_pEventHandler)->HandleException(hh);
				else
					LOG_INTERNAL("Error: at(%s:%d)\n", __FILE__, __LINE__);

				continue;
			}
		}

		return X1_OK;
	}

NS_X1_END