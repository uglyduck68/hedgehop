#ifndef __NET_EVENT_SELECT_H__
#define __NET_EVENT_SELECT_H__

#include "net_reactor.h"

#include "../event_scheduler.h"

namespace wel
{
	class CNetEventSelect: public INetReactor
	{
	public:
		CNetEventSelect();

	public:
		virtual INT  RegistHandle( IEventHandle *pEventHandle, UINT uiNetEvents );
		virtual INT  RemoveHandle( IEventHandle *pEventHandle, UINT uiNetEvents );
		virtual INT  CheckEvents(UINT uiTimeOut);
		virtual INT  LoopEvents(UINT uiTimeOut);
		virtual INT  EndLoopEvents();

	protected:
		void   RemoveHandle( UINT uiIndex,UINT uiNetEvents );
		INT  OnNetEvents( UINT uiIndex );

	protected:
		typedef struct tag_HandleEvent 
		{
			NET_HANDLE  handle;
			UINT      uiNetEvents;   

			tag_HandleEvent()
			{
				handle      = NULL;
				uiNetEvents = 0;
			}
		}struHandleEvent;

		bool             m_bLoopEvents;
		UINT           m_uiTotalHandle;
		tag_HandleEvent  m_HandleArray[WSA_MAXIMUM_WAIT_EVENTS];
		WSAEVENT         m_EventArray[WSA_MAXIMUM_WAIT_EVENTS];
		CEventScheduler  m_EventScheduler;
	};
}//end namespace(wel)

#endif //__NET_EVENT_SELECT_H__