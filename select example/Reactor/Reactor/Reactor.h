#pragma once

#include "X1.h"

#include "EventHandler.h"

NS_X1_START

class ReactorImpl;

class DECL_SPEC_DLL Reactor
{
public:
	int	RegisterHandler(EventHandler *eh, ET et);
	int	RemoveHandler(EventHandler *eh, ET et);

	/**
		* @retval	X1_OK : successfully return
		* @retval	X1_CLOSED : IO closed
		* @retval	X1_FAIL : error return
		*/
	int	HandleEvent(TimeValue *timeout = 0);

	static Reactor* GetInstance();

	Reactor();
	virtual ~Reactor();

protected:

	/// bridge pattern for demultiplexer implementation
	ReactorImpl*	m_pImpl;

	/// m_pReactor is static for singleton 
	static Reactor*	volatile m_pReactor;

};

NS_X1_END