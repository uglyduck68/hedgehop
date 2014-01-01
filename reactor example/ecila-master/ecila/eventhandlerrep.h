#pragma once


#include "eventtype.h"

#include <list>







NS_ECILA_START

class IEventHandler;

//Event Handler Repository : For select demultiplexer
class DECL_SPEC_DLL EventHandlerRep
{
public:
	enum ENUM_MAX { MAX_REPOSITORY = FD_SETSIZE, };
	
	typedef struct {
		IEventHandler	*handler_;
		EVENT_T			eventmask_;
	} DATA_T;


	 EventHandlerRep();
	~EventHandlerRep();

	bool_t			Register		(IEventHandler *h, EVENT_T e);
	bool_t			UnRegister		(IEventHandler *h);

	uint32_t		Capacity		();
	uint32_t		Count			();

	void			MaxDescriptor	(descriptor_t d);
	descriptor_t	MaxDescriptor	();

	DATA_T*			Get(uint32_t idx);



private:

	uint32_t		capacity_;
	uint32_t		cnt_handler_;
	descriptor_t 	max_descriptor_;
	DATA_T			table_[MAX_REPOSITORY];

	bool_t		Initialize();
	bool_t		Finalize();
};

NS_ECILA_END

