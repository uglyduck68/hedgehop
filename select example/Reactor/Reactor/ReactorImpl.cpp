#include "X1.h"
#include "ReactorImpl.h"
#include "EventHandler.h"

#include <WinSock2.h>
#include <assert.h>

namespace X1
{
	DemuxTable::DemuxTable()
	{
		memset(m_Table, 0x00, FD_SETSIZE * sizeof(struct Tuple));
	}

	DemuxTable::~DemuxTable()
	{
	}

	/************************************************************************/
	/* Constraints                                                          */
	/************************************************************************/
	int DemuxTable::ConvertToFdSets(fd_set &readset, fd_set &writeset, fd_set &exceptset, X1_HANDLE &max_handle)
	{
		int		nMaxHandle	= -1;

		for(int i = 0; i < FD_SETSIZE; i++)
		{
			if(m_Table[i].m_pEventHandler != NULL)
			{
				//We are interested in this socket, so
				//set max_handle to this socket descriptor
				max_handle	= m_Table[i].m_pEventHandler->GetHandle();

				nMaxHandle	= i;

				if((m_Table[i].m_nEventType & EventHandler::READ_MASK) == EventHandler::READ_MASK)
					FD_SET(i, &readset);
				if((m_Table[i].m_nEventType & EventHandler::WRITE_MASK) == EventHandler::WRITE_MASK)
					FD_SET(i, &writeset);
				if((m_Table[i].m_nEventType & EventHandler::EXCEPT_MASK) == EventHandler::EXCEPT_MASK)
					FD_SET(i, &exceptset);
			}
		}

		return nMaxHandle;
	}

	/************************************************************************/
	/* selector implementation                                              */
	/************************************************************************/

	SelectReactorImpl::SelectReactorImpl()
	{
		FD_ZERO(&m_fsRead);
		FD_ZERO(&m_fsWrite);
		FD_ZERO(&m_fsEx);

		m_nMaxHandle		= 0;
	}

	SelectReactorImpl::~SelectReactorImpl()
	{

	}

	/************************************************************************/
	/* Constraints                                                          */
	/* - X1_HANDLE h has integer serial number in Linux                        */
	/************************************************************************/
	int SelectReactorImpl::RegisterHandler(EventHandler *eh, ET et)
	{
		X1_HANDLE		h	= eh->GetHandle();

		/* NOTE: following method is needed to check */
		m_fsTable.m_Table[h].m_pEventHandler		= eh;
		m_fsTable.m_Table[h].m_nEventType		= et;

		//set maximum handle value
		m_nMaxHandle++;

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
		X1_HANDLE		h	= eh->GetHandle();

		assert(0 < h && h < FD_SETSIZE);

		/* NOTE: following method is *NOT* good */
		m_fsTable.m_Table[h].m_pEventHandler		= NULL;
		m_fsTable.m_Table[h].m_nEventType		= EventHandler::NULL_MASK;

		m_nMaxHandle--;

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
		X1_HANDLE	hMaxHandle;
		fd_set		readset, writeset, exceptset;

		FD_ZERO(&readset);
		FD_ZERO(&writeset);
		FD_ZERO(&exceptset);

		max_handle	= m_fsTable.ConvertToFdSets(readset, writeset, exceptset, hMaxHandle/*max_handle*/);

		if (max_handle <= 0)
		{
			return X1_FAIL;
		}

		int result = select(max_handle+1, &readset, &writeset, &exceptset, (const timeval *)&timeout);

		if(result < 0)	throw /*handle error here*/;

		for(int h = 0; h <= max_handle; h++)
		{
			X1_HANDLE		hh	= m_fsTable.m_Table[h].m_pEventHandler->GetHandle();

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

}