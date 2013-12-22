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
	/*
	 * interface class for reactor demultiplexer
	 */
	class ReactorImpl
	{
	public:
		virtual int	RegisterHandler(EventHandler *eh, ET et) = 0;
		virtual int	RemoveHandler(EventHandler *eh, ET et) = 0;
		virtual int	HandleEvent(TimeValue *timeout = 0) = 0;
	};

	class EventHandler;

	struct Tuple 
	{
		//pointer to Event_Handler that processes the events arriving
		//on the handle
		EventHandler* m_pEventHandler;
		//bitmask that tracks which types of events <Event_Handler>
		//is registered for
		ET		 m_nEventType;
	};

	class DemuxTable 
	{
	public:
		DemuxTable();
		~DemuxTable();
		int ConvertToFdSets(fd_set &readset, fd_set &writeset, fd_set &exceptset, X1_HANDLE &max_handle);

	public:
		//because the number of file descriptors can be demultiplexed by
		//select() is limited by FD_SETSIZE constant so this table is indexed
		//up to FD_SETSIZE
		struct Tuple mTable[FD_SETSIZE];
	};

	class SelectReactorImpl : public ReactorImpl
	{
	public:
		virtual int	RegisterHandler(EventHandler *eh, ET et);
		virtual int	RemoveHandler(EventHandler *eh, ET et);
		virtual int	HandleEvent(TimeValue *timeout = 0);

		SelectReactorImpl();
		virtual ~SelectReactorImpl();

	protected:
#if	defined(_X1_WINDOWS_)
		FD_SET	m_fsRead;	// Windows support only max. 64 fd handles
		FD_SET	m_fsWrite;
		FD_SET	m_fsEx;

		int		m_nMaxHandle;

		DemuxTable		m_fsTable;

#elif	defined(_X1_LINUX_)
#elif	defined(_X1_VXWORKS_)
#endif
	};
}