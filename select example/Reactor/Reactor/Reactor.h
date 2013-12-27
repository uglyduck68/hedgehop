#pragma once

#include "X1.h"

#include "EventHandler.h"

namespace X1
{
	class ReactorImpl;

	class Reactor
	{
	public:
		int	RegisterHandler(EventHandler *eh, ET et);
		int	RemoveHandler(EventHandler *eh, ET et);

		/**
		 * @return	X1_OK : successfully return
		 *			X1_CLOSED : IO closed
		 *			X1_FAIL : error return
		 */
		int	HandleEvent(TimeValue *timeout = 0);

		static Reactor* GetInstance();

		Reactor();
		virtual ~Reactor();

	protected:

		/// bridge pattern for demultiplexer implementation
		ReactorImpl*	m_pImpl;

		/// m_pReactor is static for signleton 
		static Reactor*	volatile m_pReactor;

	};
}