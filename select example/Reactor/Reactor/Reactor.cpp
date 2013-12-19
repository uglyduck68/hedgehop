#pragma once

#include "ReactorImpl.h"
#include "Reactor.h"

namespace X1
{
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
		return X1_OK;
	}

	int Reactor::RemoveHandler(EventHandler *eh, ET et)
	{
		return X1_OK;
	}

	int Reactor::HandleEvent(TimeValue *timeout /* = 0 */)
	{
		return X1_OK;
	}

	Reactor* Reactor::GetInstance()
	{
		return NULL;
	}
}