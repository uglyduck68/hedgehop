#include "ringbuffer.h"








US_ECILA

RingBuffer::RingBuffer(uint32_t size, ENUM_PROP prop)
:	prop_		(prop),
	size_		(0),
	free_size_	(0),
	in_pos_		(0),
	out_pos_	(0),
	data_		(0)
{
	ECILA_ASSERT(size > 0 && size <= MAX_BUFFER_SIZE);
	size_		= size;
	free_size_	= size;

	data_		= new char_t[size_];
	memset(data_, 0, size);
}







RingBuffer::~RingBuffer()
{
}

