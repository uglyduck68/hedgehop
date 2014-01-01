#include "eventhandlerrep.h"
#include "ieventhandler.h"






US_ECILA

EventHandlerRep::EventHandlerRep()
{
	Initialize();
}






EventHandlerRep::~EventHandlerRep()
{
	Finalize();
}






bool_t EventHandlerRep::Register(IEventHandler *h, EVENT_T e)
{
	ECILA_ASSERT(h);

	if(cnt_handler_ >= capacity_) { ECILA_TRACE(); return FALSE; }

	for(uint32_t i=0; i<capacity_; i++)
	{
		if(table_[i].handler_ == 0)
		{
			table_[i].handler_		= h;
			table_[i].eventmask_	= e;
			cnt_handler_++;
			break;
		}
	}

	return TRUE;
}






bool_t EventHandlerRep::UnRegister(IEventHandler *h)
{
	ECILA_ASSERT(h);

	if(cnt_handler_ == 0) { ECILA_TRACE(); return FALSE; }

	for(uint32_t i=0; i<capacity_; i++)
	{
		if(table_[i].handler_ == h)
		{
			table_[i].handler_		 = 0;
			table_[i].eventmask_	 = EVENT_NONE;
			cnt_handler_--;
			
			return TRUE;
		}
	}

	return FALSE;
}








uint32_t EventHandlerRep::Capacity()
{
	return capacity_;
}








uint32_t EventHandlerRep::Count()
{
	return cnt_handler_;
}








void EventHandlerRep::MaxDescriptor(descriptor_t d)
{
	if(max_descriptor_ < d) { max_descriptor_ = d; }
}








descriptor_t EventHandlerRep::MaxDescriptor()
{
	return max_descriptor_;
}








EventHandlerRep::DATA_T* EventHandlerRep::Get(uint32_t idx)
{
	if(idx > capacity_) { ECILA_TRACE(); return 0; }

	return &table_[idx];
}








bool_t EventHandlerRep::Initialize()
{
	capacity_			= MAX_REPOSITORY;
	cnt_handler_		= 0;
	max_descriptor_		= 0;
	memset(table_, 0, sizeof(table_));

	return TRUE;
}








bool_t EventHandlerRep::Finalize()
{
	capacity_		= 0;
	cnt_handler_	= 0;
	max_descriptor_ = 0;

	return TRUE;
}
