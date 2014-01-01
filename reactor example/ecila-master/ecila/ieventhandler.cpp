#include "ieventhandler.h"


US_ECILA






IEventHandler::IEventHandler(IDemultiplexer *demultiplexer)

{
	demultiplexer_		= demultiplexer;
	b_registered_		= FALSE;
	uidx_				= 0;
	init_event_mask_	= EVENT_NONE;
}






IEventHandler::~IEventHandler()
{
}








IDemultiplexer* IEventHandler::Demultiplexer()
{
	return demultiplexer_;
}








bool_t IEventHandler::Demultiplexer(IDemultiplexer *demultiplexer)
{
	demultiplexer_ = demultiplexer;

	return TRUE;
}








bool_t IEventHandler::Registered()
{
	return b_registered_;
}








bool_t IEventHandler::Registered(bool_t flag)
{
	if((b_registered_ == TRUE  && flag == TRUE) ||
	   (b_registered_ == FALSE && flag == FALSE))
	{
		return FALSE;
	}

	b_registered_ = flag;
	return TRUE;
}








serial_t IEventHandler::UIDX()
{
	return uidx_;
}








bool_t IEventHandler::UIDX(serial_t uidx)
{
	uidx_ = uidx;

	return TRUE;
}








EVENT_T IEventHandler::InitialEventMask()
{
	return init_event_mask_;
}








bool_t IEventHandler::InitialEventMask(EVENT_T e)
{
	init_event_mask_ = e;
	return TRUE;
}

