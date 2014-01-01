#pragma	once

#include "X1.h"
#include "TimeValue.h"

using namespace	X1;

NS_X1_START

	class Reactor;
	
	class DECL_SPEC_DLL EventHandler
	{
	public:
		enum  
		{  
			/// event mask values is the same with winsock2
			NULL_MASK	= 0,
			READ_MASK	= (1 << 0),
			WRITE_MASK	= (1 << 1),
			ACCEPT_MASK	= (1 << 3),
			CONNECT_MASK	= (1 << 4),
			CLOSE_MASK		= (1 << 5),
			EXCEPT_MASK		= (1 << 6),
			ALL_EVENTS_MASK	= READ_MASK | WRITE_MASK | CLOSE_MASK /*| ACCEPT_MASK | CONNECT_MASK*/,
			DONT_CALL		= (1 << 16)
		};

		virtual	~EventHandler();

		virtual	X1_SOCHANDLE 	GetHandle() const
		{
			return m_h;
		}

		void SetHandle(X1_SOCHANDLE& h)
		{
			m_h	= h;
		}

		// called when input event occur (e.g., connection or data)
		virtual int		HandleRead(X1_SOCHANDLE h);

		// called when output events are possible
		virtual int 	HandleWrite(X1_SOCHANDLE h);

		virtual int 	HandleException(X1_SOCHANDLE h);

		virtual int 	HandleClose(X1_SOCHANDLE h = INVALID_HANDLE, EVENT_MASK e = ALL_EVENTS_MASK);

		virtual int 	HandleTimeout(const TimeValue& tv);


	protected:

		EventHandler();

		Reactor*	m_pReactor;

		X1_SOCHANDLE		m_h;
	};

NS_X1_END