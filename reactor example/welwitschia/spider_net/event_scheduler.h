#ifndef __EVENT_SCHEDULER_H__
#define __EVENT_SCHEDULER_H__

#include "net_platform.h"
#include "event_handle.h"
#include <map>

namespace wel
{
	class CEventScheduler
	{
	public:
		~CEventScheduler();

	public:
		INT  RegistHandle( IEventHandle *pEventHandle, UINT uiNetEvents );
		INT  RemoveHandle( IEventHandle *pEventHandle, UINT uiNetEvents );

	public:
		INT  HandleInput(NET_HANDLE handle);
		INT  HandleOutput(NET_HANDLE handle);


	protected:
		void  Clear();


	protected:
		typedef struct tag_HandleEvent
		{
			IEventHandle *pEventHandle;
			UINT       uiNetEvents;   

			tag_HandleEvent()
			{
				pEventHandle = NULL;
				uiNetEvents  = 0;
			}
		}struHandleEvent;

		typedef std::map<NET_HANDLE, struHandleEvent> CHandleMap;

		CHandleMap  m_HandleMap;
	};
}//end namespace(wel)

#endif //__EVENT_SCHEDULER_H__
