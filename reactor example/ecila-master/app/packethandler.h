#pragma once


#include <ecila/ipackethandler.h>
#include <ecila/session.h>
#include <ecila/msgqueue.h>
#include <ecila/bufferpool.h>








class PacketHandler
:	public NS_ECILA::IPacketHandler
{
public:

			 PacketHandler();
	virtual ~PacketHandler();
	
	virtual bool_t HandleEvents(serial_t uidx, NS_ECILA::Session *sess, NS_ECILA::EVENT_T e);
	virtual void   CacheNode();

private:

	NS_ECILA::MsgQueue   *dispatch_q_;
	NS_ECILA::BufferPool *buff_pool_;

	bool_t OnOpen	(serial_t uidx, NS_ECILA::Session* sess);
	bool_t OnClose	(serial_t uidx, NS_ECILA::Session* sess);
	bool_t OnRead	(serial_t uidx, NS_ECILA::Session* sess);
	bool_t OnWrite	(serial_t uidx, NS_ECILA::Session* sess);

	int32_t HttpReqComplete(const char_t *context, int32_t context_len);

};

