#pragma once

#include	"EventHandler.h"

#define	DATA_BUFSIZE	8192

/**
 * @class	EchoService
 * @brief	This class is just for sample of reactor
 */
class EchoService :public EventHandler
{
protected:
	char recvBuffer[DATA_BUFSIZE + 1];
	char sendBuffer[DATA_BUFSIZE + 1];
	int recvBytes;
	int sendBytes;

public:
	EchoService(void);
	~EchoService(void);

	// called when input event occur (e.g., connection or data)
	virtual int		HandleRead(X1_SOCHANDLE h);

	// called when output events are possible
	virtual int 	HandleWrite(X1_SOCHANDLE h);

	virtual int 	HandleException(X1_SOCHANDLE h);

	virtual int 	HandleClose(X1_SOCHANDLE h = INVALID_HANDLE, EVENT_MASK e = ALL_EVENTS_MASK);

	virtual int 	HandleTimeout(const TimeValue& tv);
};

