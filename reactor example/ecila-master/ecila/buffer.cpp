#include "buffer.h"








US_ECILA

Buffer::Buffer(uint32_t size)
:	uidx_		(0),
	size_		(0),
	in_pos_		(0),
	out_pos_	(0),
	data_		(0)
{
	ECILA_ASSERT(size > 0 && size <= MAX_BUFFER_SIZE);
	size_		= size;

	data_		= new char_t[size_];
	memset(data_, 0, size);
}








Buffer::~Buffer()
{
	ECILA_SAFE_DELETE_ARRAY(data_);
}
