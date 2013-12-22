#pragma	once

#include "X1.h"
#include "TimeValue.h"

using namespace	X1;

namespace X1
{
	class Reactor;
	
	class EventHandler
	{
	public:
		enum EVENT_TYPE 
		{  
			NULL_MASK	= 0,
			ACCEPT_MASK	= (1 << 0),
			READ_MASK	= (1 << 1),
			WRITE_MASK	= (1 << 2),
			CONNECT_MASK	= (1 << 3),
			EXCEPT_MASK		= (1 << 4),
			ALL_EVENTS_MASK	= READ_MASK | WRITE_MASK | ACCEPT_MASK | CONNECT_MASK,
			CLOSE_MASK		= (1 << 8),
			DONT_CALL		= (1 << 16)
		};

		virtual	~EventHandler();

		virtual	X1_HANDLE 	GetHandle() const
		{
			return m_h;
		}
		// called when input event occur (e.g., connection or data)
		virtual int		HandleRead(X1_HANDLE h);

		// called when output events are possible
		virtual int 	HandleWrite(X1_HANDLE h);

		virtual int 	HandleException(X1_HANDLE h);

		virtual int 	HandleClose(X1_HANDLE h = INVALID_HANDLE, EVENT_MASK e = ALL_EVENTS_MASK);

		virtual int 	HandleTimeout(const TimeValue& tv);


	protected:

		EventHandler();

		Reactor*	m_pReactor;

		X1_HANDLE		m_h;
	};
}