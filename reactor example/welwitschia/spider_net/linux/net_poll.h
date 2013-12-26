#ifndef __NET_POLL_H__
#define __NET_POLL_H__

#include "net_reactor.h"
#include "../event_scheduler.h"

#ifdef OS_WIN32
	//struct pollfd {
	//	int fd;           /* file descriptor */
	//	short events;     /* requested events */
	//	short revents;    /* returned events */
	//};
#endif // OS_WIN32

namespace wel
{
	class CNetPoll: public INetReactor
	{
	public:
		CNetPoll();

	public:
		virtual INT  RegistHandle( IEventHandle *pEventHandle, UINT uiNetEvents );
		virtual INT  RemoveHandle( IEventHandle *pEventHandle, UINT uiNetEvents );
		virtual INT  CheckEvents(UINT uiTimeOut);
		virtual INT  LoopEvents(UINT uiTimeOut);
		virtual INT  EndLoopEvents();


	protected:
		void   RemoveHandle( UINT uiIndex,UINT uiNetEvents );
		void   EventHandle( INT iNumber );
		void   OnNetEvents( UINT uiIndex );

	protected:
		typedef struct tag_HandleEvent 
		{
			NET_HANDLE  handle;
			UINT      uiNetEvents;   

			tag_HandleEvent()
			{
				handle      = 0;
				uiNetEvents = 0;
			}
		}struHandleEvent;

		bool             m_bLoopEvents;
		UINT           m_uiTotalHandle;
		tag_HandleEvent  m_HandleArray[FD_SETSIZE];
		pollfd           m_PollFdArray[FD_SETSIZE];
		CEventScheduler  m_EventScheduler;
	};
}//end namespace(wel)

#endif
