#pragma once

#include "X1.h"
#include "Reactor.h"

#if	defined(_X1_WINDOWS_)

#include <winsock2.h>
#include <windows.h>
#include <stdio.h>

#elif	defined(_X1_LINUX_)
#include <poll.h>
#include <sys/epoll.h>
#elif	defined(_X1_VXWORKS_)
#endif

namespace X1
{
	class EventHandler;

	struct Tuple_WIN32_select 
	{
		//pointer to Event_Handler that processes the events arriving
		//on the handle
		EventHandler*	m_pEventHandler;
		X1_SOCHANDLE		m_h;

		//bitmask that tracks which types of events <Event_Handler>
		//is registered for
		ET				m_nEventType;
	};

	class DemuxTable_WIN32_select 
	{
	public:
		DemuxTable_WIN32_select();
		~DemuxTable_WIN32_select();
		int ConvertToFdSets(fd_set &readset, fd_set &writeset, fd_set &exceptset, X1_SOCHANDLE &max_handle);

	public:

		// FIXME: upgrade m_Table architecture like RB-tree or Hash table
		//because the number of file descriptors can be demultiplexed by
		//select() is limited by FD_SETSIZE constant so this table is indexed
		//up to FD_SETSIZE
		struct Tuple m_Table[FD_SETSIZE];

		int		m_nMaxHandle;

		int		GetMaxHandle()
		{
			return m_nMaxHandle;
		}

		int	Insert(EventHandler* eh, X1_SOCHANDLE h, ET et);
		int	Remove(EventHandler* eh, X1_SOCHANDLE h, ET et);

		void MakeFree(int nIndex);
	};

	/** 
	 * @class	SelectReactorImpl_WIN32_select
	 * @brief	implementation reactor using select & FD_XXX functions
	 */
	class SelectReactorImpl_WIN32_select : public ReactorImpl
	{
	public:
		virtual int	RegisterHandler(EventHandler *eh, ET et);
		virtual int	RemoveHandler(EventHandler *eh, ET et);
		virtual int	HandleEvent(TimeValue *timeout = 0);

		SelectReactorImpl_WIN32_select();
		virtual ~SelectReactorImpl_WIN32_select();

	protected:
#if	defined(_X1_WINDOWS_)
		FD_SET	m_fsRead;	// Windows support only max. 64 fd handles
		FD_SET	m_fsWrite;
		FD_SET	m_fsEx;

		DemuxTable_WIN32_select		m_fsTable;

		int	GetMaxHandle()
		{
			return m_fsTable.GetMaxHandle();
		}

		int MakeEventMask(ET et, long& lNetworkEvents);

#elif	defined(_X1_LINUX_)
#elif	defined(_X1_VXWORKS_)
#endif
	};
}