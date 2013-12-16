#pragma	once

#include	"Types.h"

namespace X1
{
	class Reactor;
	
	class EventHandler
	{
	public:
		enum  
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

		virtual	HANDLE 	GetHandle() const;

		// called when input event occur (e.g., connection or data)
		virtual int		HandleRead(HANDLE h);

		// called when output events are possible
		virtual int 	HandleWrite(HANDLE h);

		virtual int 	HandleException(HANDLE h);

		virtual int 	HandleClose(HANDLE h = INVALID_HANDLE, EVENT_MASK e = ALL_EVENTS_MASK);

		virtual int 	HandleTimeout(const TimeValue& tv);


	protected:

		EventHandler();

		Reactor*	m_pReactor;


	};
}