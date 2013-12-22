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

	int	EventHandler::HandleRead(X1_HANDLE h)
	{
		return X1_OK;
	}

	int EventHandler::HandleWrite(X1_HANDLE h)
	{
		return X1_OK;
	}

	int	EventHandler::HandleException(X1_HANDLE h)
	{
		return X1_OK;
	}

	int EventHandler::HandleClose(X1_HANDLE h /* = INVALID_HANDLE */, EVENT_MASK e /* = ALL_EVENTS_MASK */)
	{
		return X1_OK;
	}

	int EventHandler::HandleTimeout(const TimeValue& tv)
	{
		return X1_OK;
	}
}