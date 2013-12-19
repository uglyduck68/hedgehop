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
		int	HandleEvent(TimeValue *timeout = 0);

		Reactor* GetInstance();

		Reactor();
		virtual ~Reactor();

	protected:
		ReactorImpl*	m_pImpl;
	};
}