#ifndef __NET_SELECT_H__
#define __NET_SELECT_H__

#include "net_reactor.h"
#include "event_scheduler.h"

namespace wel
{
	class CNetSelect: public INetReactor
	{
	public:
		CNetSelect();
		~CNetSelect();

	public:
		virtual INT  RegistHandle( IEventHandle *pEventHandle, UINT uiNetEvents );
		virtual INT  RemoveHandle( IEventHandle *pEventHandle, UINT uiNetEvents );
		virtual INT  CheckEvents(UINT uiTimeOut);
		virtual INT  LoopEvents(UINT uiTimeOut);
		virtual INT  EndLoopEvents();

	protected:
		INT RemoveHandle( NET_HANDLE handle, UINT uiNetEvents );
		void  EventHandle( const INT iCount, fd_set &rSet, fd_set &wSet );

	protected:
		typedef struct socket_sd {
			UINT      fd_count;               /* how many are SET? */
			NET_HANDLE  fd_array[FD_SETSIZE];   /* an array of SOCKETs */
		} socket_sd;

		CEventScheduler  m_EventScheduler;
		socket_sd  m_InputArray;
		socket_sd  m_OutputArray;

		timeval *m_pTimeOut;
		UINT  m_uiMaxFd;

		bool   m_bLoopEvents;
	};
}//end namespace(wel)

#endif //__NET_SELECT_H__
