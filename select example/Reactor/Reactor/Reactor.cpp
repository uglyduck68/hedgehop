#pragma once
#include "X1.h"

#if	defined(_X1_WINDOWS_)
#include "ReactorImpl_WIN32.h"
#include "ReactorImpl_WIN32_select.h"
#elif	defined(_LINUX_)
#include "ReactorImpl.h"
#endif
#include "Reactor.h"
#include "Mutex.h"
#include "Guard.h"

NS_X1_START

Reactor* volatile Reactor::m_pReactor	= NULL;

Reactor::Reactor()
{
	m_pImpl	= NULL;

	// FIXME: by default use select implementation
	// but should support various implementation
//		m_pImpl	= new SelectReactorImpl_WIN32();
	m_pImpl	= new SelectReactorImpl_WIN32_select();
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
		Mutex				mutex;
		Guard<Mutex>		lock(mutex);

		if (m_pReactor == NULL)
			m_pReactor	= new Reactor;
	}

	return m_pReactor;
}

NS_X1_END