inline uint32_t RingBuffer::Size()
{
	return size_;
}








inline bool_t RingBuffer::IsEmpty()
{
	return size_ == free_size_ ? TRUE : FALSE;
}








inline bool_t RingBuffer::Reset()
{
	in_pos_    = out_pos_ = 0;
	free_size_ = size_;

	return TRUE;
}








inline int32_t RingBuffer::Length()
{
	return size_ - free_size_;
}








inline int32_t RingBuffer::Remain()
{
	return free_size_;
}








inline char_t* RingBuffer::GetInPtr()
{
	return &data_[in_pos_];
}








inline char_t* RingBuffer::GetOutPtr()
{
	return &data_[out_pos_];
}








inline bool_t RingBuffer::ForwardInPtr(uint32_t nbytes)
{
	if(nbytes == 0 || nbytes == size_) return TRUE;

	if(nbytes > size_)
	{
		ECILA_TRACE(); return FALSE; 
	}

	if((prop_ & DENY_OVERWRITE) && (free_size_ < nbytes))
	{
		ECILA_TRACE(); return FALSE;
	}

	uint32_t available = GetInBoundary();
	if(available < nbytes)
	{
		in_pos_ = nbytes - available;
	}
	else
	{
		in_pos_ += nbytes;
	}

	AdjFreeSizeAndOutPos(nbytes);
	return TRUE;
}








inline bool_t RingBuffer::RewindInPtr(uint32_t nbytes)
{
	return FALSE;
}








inline bool_t RingBuffer::ForwardOutPtr(uint32_t nbytes)
{
	if(nbytes == 0 || nbytes == size_) return TRUE;

	if(nbytes > size_)
	{
		ECILA_TRACE(); return FALSE; 
	}

	if((prop_ & DENY_OVERREAD) && ((size_ - free_size_) < nbytes))
	{
		ECILA_TRACE(); return FALSE;
	}

	uint32_t available = GetOutBoundary();
	if(available < nbytes)
	{
		out_pos_ = nbytes - available;
	}
	else
	{
		out_pos_ += nbytes;
	}

	AdjFreeSizeAndInPos(nbytes);

	return TRUE;
}








inline bool_t RingBuffer::RewindOutPtr(uint32_t nbytes)
{
	return FALSE;
}








inline bool_t RingBuffer::PutByte(char_t value)
{
	return PutBinary((char_t*)&value, sizeof(char_t));
}








inline bool_t RingBuffer::PutUByte(uchar_t value)
{
	return PutBinary((char_t*)&value, sizeof(uchar_t));
}








inline bool_t RingBuffer::PutInt16(int16_t value)
{
	return PutBinary((char_t*)&value, sizeof(int16_t));
}








inline bool_t RingBuffer::PutUInt16(uint16_t value)
{
	return PutBinary((char_t*)&value, sizeof(uint16_t));
}








inline bool_t RingBuffer::PutInt32(int32_t value)
{
	return PutBinary((char_t*)&value, sizeof(int32_t));
}








inline bool_t RingBuffer::PutUInt32(uint32_t value)
{
	return PutBinary((char_t*)&value, sizeof(uint32_t));
}








inline bool_t RingBuffer::PutInt64(int64_t value)
{
	return PutBinary((char_t*)&value, sizeof(int64_t));
}








inline bool_t RingBuffer::PutUInt64(uint64_t value)
{
	return PutBinary((char_t*)&value, sizeof(uint64_t));
}








inline bool_t RingBuffer::PutFloat(float_t value)
{
	return PutBinary((char_t*)&value, sizeof(float_t));
}








inline bool_t RingBuffer::PutDouble(double_t value)
{
	return PutBinary((char_t*)&value, sizeof(double_t));
}








inline bool_t RingBuffer::GetByte(char_t  &value)
{
	return GetBinary((char_t*)&value, sizeof(char_t));
}








inline bool_t RingBuffer::GetUByte(uchar_t &value)
{
	return GetBinary((char_t*)&value, sizeof(uchar_t));
}








inline bool_t RingBuffer::GetInt16(int16_t &value)
{
	return GetBinary((char_t*)&value, sizeof(int16_t));
}







inline bool_t RingBuffer::GetUInt16(uint16_t &value)
{
	return GetBinary((char_t*)&value, sizeof(uint16_t));
}







inline bool_t RingBuffer::GetInt32(int32_t &value)
{
	return GetBinary((char_t*)&value, sizeof(int32_t));
}








inline bool_t RingBuffer::GetUInt32(uint32_t &value)
{
	return GetBinary((char_t*)&value, sizeof(uint32_t));
}








inline bool_t RingBuffer::GetInt64(int64_t &value)
{
	return GetBinary((char_t*)&value, sizeof(int64_t));
}








inline bool_t RingBuffer::GetUInt64(uint64_t &value)
{
	return GetBinary((char_t*)&value, sizeof(uint64_t));
}








inline bool_t RingBuffer::GetFloat(float_t &value)
{
	return GetBinary((char_t*)&value, sizeof(float_t));
}








inline bool_t RingBuffer::GetDouble(double_t &value)
{
	return GetBinary((char_t*)&value, sizeof(double_t));
}








inline bool_t RingBuffer::PutBinary(char_t *value, uint32_t size)
{
	uint32_t available = GetInBoundary();

	if((prop_ & DENY_OVERWRITE) && (free_size_ < size))
	{
		ECILA_TRACE(); return FALSE;
	}

	if(available < size)
	{
		uint32_t overwrite = size - available;
		memcpy(&data_[in_pos_], value, available);
		memcpy(&data_[0], value + available, overwrite);

		in_pos_ = overwrite;
	}
	else
	{
		memcpy(&data_[in_pos_], value, size);
		in_pos_ += size;
	}

	AdjFreeSizeAndOutPos(size);

	return true;
}








inline bool_t RingBuffer::GetBinary(char_t *value, uint32_t size)
{
	uint32_t available = GetOutBoundary();

	if((prop_ & DENY_OVERREAD) && ((size_ - free_size_) < size))
	{
		ECILA_TRACE(); return FALSE;
	}

	if(available < size)
	{
		uint32_t overread = size - available;
		memcpy(value, &data_[out_pos_], available);
		memcpy(value + available, &data_[0], overread);

		out_pos_ = overread;
	}
	else
	{
		memcpy(value, &data_[out_pos_], size);
		out_pos_ += size;
	}

	AdjFreeSizeAndInPos(size);

	return TRUE;
}








inline uint32_t RingBuffer::GetInBoundary()
{
	if(out_pos_ <= in_pos_)
	{
		return size_ - in_pos_;
	}
	else
	{
		return out_pos_ - in_pos_;
	}
}








inline uint32_t RingBuffer::GetOutBoundary()
{

	if(in_pos_ <= out_pos_)
	{
		return size_ - out_pos_;
	}
	else
	{
		return in_pos_ - out_pos_;
	}
}








inline void RingBuffer::AdjFreeSizeAndInPos(uint32_t size)
{
	if((size_ - free_size_) < size)
	{
		in_pos_    = out_pos_;
		free_size_ = size_;
	}
	else
	{
		free_size_ += size;
	}
}








inline void RingBuffer::AdjFreeSizeAndOutPos(uint32_t size)
{
	if(free_size_ < size)
	{
		out_pos_   = in_pos_;
		free_size_ = 0;
	}
	else
	{
		free_size_ -= size;
	}
}

