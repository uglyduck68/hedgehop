#pragma once


#include "eventtype.h"








NS_ECILA_START

class IEventHandler;

class DECL_SPEC_DLL IDemultiplexer
{
public:
	enum ENUM_MAX { MAX_REPOSITORY_SIZE = 4096, };

			 IDemultiplexer() {}
	virtual ~IDemultiplexer() {}

	virtual bool_t HandleEvents		(int32_t timeout_msec)			= 0;
	virtual bool_t RegisterHandler	(IEventHandler *h, EVENT_T e)	= 0;
	virtual bool_t UnRegisterHandler(IEventHandler *h)				= 0;
	virtual bool_t EnableEventMask	(IEventHandler *h, EVENT_T e)	= 0;
	virtual bool_t DisableEventMask	(IEventHandler *h, EVENT_T e)	= 0;
};

NS_ECILA_END

