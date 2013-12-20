#pragma once

#include "ReactorImpl.h"
#include "Reactor.h"
#include "Lock.h"

namespace X1
{
	Reactor* volatile Reactor::m_pReactor	= NULL;

	Reactor::Reactor()
	{
		m_pImpl	= NULL;
	}

	Reactor::~Reactor()
	{
		DEL(m_pImpl);
	}

	int Reactor::RegisterHandler(EventHandler *eh, ET et)
	{
		if (m_pImpl)
			return m_pImpl->RegisterHandler(eh, et);

		return X1_FAIL;
	}

	int Reactor::RemoveHandler(EventHandler *eh, ET et)
	{
		if (m_pImpl)
			return m_pImpl->RemoveHandler(eh, et);

		return X1_FAIL;
	}

	int Reactor::HandleEvent(TimeValue *timeout /* = 0 */)
	{
		if (m_pImpl)
			return m_pImpl->HandleEvent(timeout);

		return X1_FAIL;
	}

	Reactor* Reactor::GetInstance()
	{
		if (m_pReactor == NULL)
		{
			Lock		lock;	// scoped locking -> change to use Guard
			if (m_pReactor == NULL)
				m_pReactor	= new Reactor;
		}

		return m_pReactor;
	}
}