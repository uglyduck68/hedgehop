#include "net_reactor.h"

#include "net_select.h"

#ifdef OS_WIN32
	#include "windows/net_event_select.h"
#else
	#include "linux/net_poll.h"
#endif // OS_WIN

namespace wel
{
	INT CreateNetReactor(INetReactor *&pNetEngine, EN_NET_REACTOR_TYPE EnReactorType)
	{
		switch (EnReactorType)
		{
		case NET_REACTOR_SELECT:
			pNetEngine = new CNetSelect();
			break;

		case  NET_REACTOR_EVENT:
	#ifdef OS_WIN32
			pNetEngine = new CNetEventSelect();
	#else
			pNetEngine = new CNetPoll();
	#endif
			break;

		default:
			pNetEngine = NULL;
			break;
		}//end switch

		return pNetEngine!=NULL?NET_OK:NET_ERR;
	}

	void  ReleaseNetReactor(INetReactor *&pNetEngine)
	{
		if ( NULL != pNetEngine )
		{
			delete pNetEngine;

			pNetEngine = NULL;
		}//end if
	}
}

