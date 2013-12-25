#pragma once

#include "X1.h"
#include "NetAddr.h"
#include "Reactor.h"
#include "EventHandler.h"

using namespace	X1;

namespace X1
{
	/**
	 * @class	Acceptor class
	 * @brief	TCP accept class
	 */

	/// FIXME: change template to general function
#ifdef	USE_TEMPLATE
	template<typename T>
#endif
	class Acceptor : public EventHandler
	{
	protected:
#ifdef	USE_TEMPLATE
		T*	m_pSvc;
#else
		EventHandler*	m_pSvc;
#endif
	public:
		Acceptor(void);
		~Acceptor(void);

		/// this function will replace the template
		int SetSvc(EventHandler *pClient)
		{
			if (pClient)
				m_pSvc	= pClient;
			else
				return X1_ENULLOBJECT;

			return X1_OK;
		}

		EventHandler*	GetSvr()
		{
			return m_pSvc;
		}

		int	Open(NetAddr addr, Reactor* pReactor);

		X1_SOCHANDLE 	GetHandle() const
		{
			return m_h;
		}

		/// called when input event occur (e.g., connection or data)
		int		HandleRead(X1_SOCHANDLE h);

		/// called when output events are possible
		int 	HandleWrite(X1_SOCHANDLE h);

		int 	HandleException(X1_SOCHANDLE h);

		int 	HandleClose(X1_SOCHANDLE h = INVALID_HANDLE, EVENT_MASK e = ALL_EVENTS_MASK);

		int 	HandleTimeout(const TimeValue& tv);

	};

}

/// prevent linking error of template functions
#ifdef	USE_TEMPLATE
#include "Acceptor.cpp"
#endif