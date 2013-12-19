#pragma once

#include "EventHandler.h"
#include "Reactor.h"

namespace X1
{

	EventHandler::EventHandler()
	{
		m_pReactor	= NULL;
		m_h			= NULL;
	}

	EventHandler::~EventHandler()
	{
		if (m_pReactor)
		{
			DEL(m_pReactor);
		}
	}
	HANDLE	EventHandler::GetHandle() const
	{
		return m_h;
	}

	int	EventHandler::HandleRead(HANDLE h)
	{
		return X1_OK;
	}

	int EventHandler::HandleWrite(HANDLE h)
	{
		return X1_OK;
	}

	int	EventHandler::HandleException(HANDLE h)
	{
		return X1_OK;
	}

	int EventHandler::HandleClose(HANDLE h /* = INVALID_HANDLE */, EVENT_MASK e /* = ALL_EVENTS_MASK */)
	{
		return X1_OK;
	}

	int EventHandler::HandleTimeout(const TimeValue& tv)
	{
		return X1_OK;
	}
}