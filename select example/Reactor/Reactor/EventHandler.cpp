#pragma once

#include "EventHandler.h"
#include "Reactor.h"

NS_X1_START

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

	int	EventHandler::HandleRead(X1_SOCHANDLE h)
	{
		return X1_OK;
	}

	int EventHandler::HandleWrite(X1_SOCHANDLE h)
	{
		return X1_OK;
	}

	int	EventHandler::HandleException(X1_SOCHANDLE h)
	{
		return X1_OK;
	}

	int EventHandler::HandleClose(X1_SOCHANDLE h /* = INVALID_HANDLE */, EVENT_MASK e /* = ALL_EVENTS_MASK */)
	{
		return X1_OK;
	}

	int EventHandler::HandleTimeout(const TimeValue& tv)
	{
		return X1_OK;
	}

NS_X1_END