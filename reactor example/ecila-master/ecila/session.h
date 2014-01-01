#pragma once


#include "ieventhandler.h"
#include "socket.h"







NS_ECILA_START

class RingBuffer;
class IPacketHandler;

class DECL_SPEC_DLL Session
:	public IEventHandler
{
public:

			 Session(IDemultiplexer *demultiplexer = 0);
	virtual ~Session();

	virtual handle_t		Handle();
	virtual descriptor_t	Descriptor();

	bool_t Open		();
	bool_t Connect	();
	bool_t Close	(bool_t force = FALSE);
	bool_t Recv		(char_t *buffer, uint32_t &size);
	bool_t Send		(char_t *buffer, uint32_t &size);

	bool_t			PKTHandler(IPacketHandler *pkt_handler);
	IPacketHandler*	PKTHandler();

	RingBuffer*			RecvBuffer();
	RingBuffer*			SendBuffer();


protected:

	Socket			sock_;
	RingBuffer		*recv_buffer_;
	RingBuffer		*send_buffer_;
	IPacketHandler	*pkt_handler_;
};

NS_ECILA_END

