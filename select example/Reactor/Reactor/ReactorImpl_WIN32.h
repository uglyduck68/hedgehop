#pragma once

#define	_REACTORIMPL_WIN32_H_

#include "X1.h"
#include "Reactor.h"
#include "ReactorImpl.h"

#if	defined(_X1_WINDOWS_)

#include <winsock2.h>
#include <windows.h>
#include <stdio.h>

#elif	defined(_X1_LINUX_)
#include <poll.h>
#include <sys/epoll.h>
#elif	defined(_X1_VXWORKS_)
#endif

NS_X1_START

	class EventHandler;

	struct Tuple_WIN32 
	{
		//pointer to Event_Handler that processes the events arriving
		//on the handle
		EventHandler*	m_pEventHandler;
		X1_SOCHANDLE		m_h;

		//bitmask that tracks which types of events <Event_Handler>
		//is registered for
		ET				m_nEventType;
	};

	class DemuxTable_WIN32 
	{
	public:
		DemuxTable_WIN32();
		~DemuxTable_WIN32();
		int ConvertToFdSets(fd_set &readset, fd_set &writeset, fd_set &exceptset, X1_SOCHANDLE &max_handle);

	public:

		// FIXME: upgrade m_Table architecture like RB-tree or Hash table
		//because the number of file descriptors can be demultiplexed by
		//select() is limited by FD_SETSIZE constant so this table is indexed
		//up to FD_SETSIZE
		struct Tuple_WIN32	m_Table[WSA_MAXIMUM_WAIT_EVENTS];
		WSAEVENT			m_aEvent[WSA_MAXIMUM_WAIT_EVENTS];

		int		m_nMaxHandle;

		int		GetMaxHandle()
		{
			return m_nMaxHandle;
		}

		int	Insert(EventHandler* eh, X1_SOCHANDLE h, ET et);
		int	Remove(EventHandler* eh, X1_SOCHANDLE h, ET et);

		WSAEVENT	GetEvent(int i)
		{
			return m_aEvent[i];
		}

		void MakeFree(int nIndex);
	};

	/** 
	 * @class	SelectReactorImpl_WIN32
	 * @brief	implementation reactor using WSAWaitMultipleObjects
	 */
	class DECL_SPEC_DLL SelectReactorImpl_WIN32 : public ReactorImpl
	{
	public:
		virtual int	RegisterHandler(EventHandler *eh, ET et);
		virtual int	RemoveHandler(EventHandler *eh, ET et);
		virtual int	HandleEvent(TimeValue *timeout = 0);

		SelectReactorImpl_WIN32();
		virtual ~SelectReactorImpl_WIN32();

	protected:

#if	defined(_X1_WINDOWS_)
		//FD_SET	m_fsRead;	// Windows support only max. 64 fd handles
		//FD_SET	m_fsWrite;
		//FD_SET	m_fsEx;

		DemuxTable_WIN32		m_fsTable;

		int	GetMaxHandle()
		{
			return m_fsTable.GetMaxHandle();
		}

		int MakeEventMask(ET et, long& lNetworkEvents);


#elif	defined(_X1_LINUX_)
#elif	defined(_X1_VXWORKS_)
#endif
	};

NS_X1_END