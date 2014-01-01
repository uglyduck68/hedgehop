#pragma once


#include "ecila.h"
#include "eventtype.h"








NS_ECILA_START

class EventResult;
class IDemultiplexer;

class DECL_SPEC_DLL IEventHandler
{
public:
			 IEventHandler(IDemultiplexer *demultiplexer);
	virtual ~IEventHandler();

	
	IDemultiplexer*	Demultiplexer();
	bool_t			Demultiplexer(IDemultiplexer *demultiplexer);

	bool_t			Registered();
	bool_t			Registered(bool_t flag);

	serial_t		UIDX();
	bool_t			UIDX(serial_t uidx);

	EVENT_T			InitialEventMask();
	bool_t			InitialEventMask(EVENT_T e);



	virtual handle_t		Handle()					= 0;
	virtual descriptor_t	Descriptor()				= 0;

	virtual bool_t			OnOpen	(EventResult *evr)	= 0;
	virtual bool_t			OnClose	(EventResult *evr)	= 0;
	virtual bool_t			OnRead	(EventResult *evr)	= 0;
	virtual bool_t			OnWrite	(EventResult *evr)	= 0;
	virtual bool_t			OnError	(EventResult *evr)	= 0;
	virtual bool_t			Complete(EventResult *evr)	= 0;


private:
	IDemultiplexer	*demultiplexer_;
	bool_t			b_registered_;
	serial_t		uidx_;
	EVENT_T			init_event_mask_;

};

NS_ECILA_END

