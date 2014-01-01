inline uint32_t Buffer::Size()
{
	return size_;
}








inline bool_t Buffer::IsEmpty()
{
	if(in_pos_ == 0 || in_pos_ == out_pos_)	return TRUE;
	else									return FALSE;
}








inline bool_t Buffer::Reset()
{
	in_pos_ = out_pos_ = 0;

	return TRUE;
}








inline int32_t	Buffer::Length()
{
	return in_pos_ - out_pos_;
}







inline int32_t Buffer::Remain()
{
	return size_ - in_pos_;
}









inline char_t*	Buffer::GetInPtr()
{
	return &data_[in_pos_];
}







inline char_t*	Buffer::GetOutPtr()
{
	return &data_[out_pos_];
}








inline bool_t Buffer::ForwardInPtr(uint32_t nbytes)
{
	if(nbytes == 0) return TRUE;

	if(IsInBoundary(nbytes))
	{
		ECILA_TRACE(); return FALSE;
	}

	in_pos_ += nbytes;
	return TRUE;
}







inline bool_t Buffer::RewindInPtr(uint32_t nbytes)
{
	if(nbytes == 0) return TRUE;

	if((uint32_t)Length() < nbytes)
	{
		ECILA_TRACE(); return FALSE;
	}

	in_pos_ -= nbytes;
	return TRUE;
}







inline bool_t Buffer::ForwardOutPtr(uint32_t nbytes)
{
	if(nbytes == 0) return TRUE;

	if(IsOutBoundary(nbytes))
	{
		ECILA_TRACE(); return FALSE;
	}

	out_pos_ += nbytes;
	return TRUE;
}







inline bool_t Buffer::RewindOutPtr(uint32_t nbytes)
{
	if(nbytes == 0) return TRUE;

	if(out_pos_ < nbytes)
	{
		ECILA_TRACE(); return FALSE;
	}

	out_pos_ -= nbytes;
	return TRUE;
}








inline bool_t Buffer::PutByte(char_t value)
{
	return PutBinary(&value, sizeof(char_t));
}








inline bool_t Buffer::PutUByte(uchar_t value)
{
	return PutBinary((char_t*)&value, sizeof(uchar_t));
}








inline bool_t Buffer::PutInt16(int16_t value)
{
	return PutBinary((char_t*)&value, sizeof(int16_t));
}








inline bool_t Buffer::PutUInt16(uint16_t value)
{
	return PutBinary((char_t*)&value, sizeof(uint16_t));
}








inline bool_t Buffer::PutInt32(int32_t value)
{
	return PutBinary((char_t*)&value, sizeof(int32_t));
}








inline bool_t Buffer::PutUInt32(uint32_t value)
{
	return PutBinary((char_t*)&value, sizeof(uint32_t));
}








inline bool_t Buffer::PutInt64(int64_t value)
{
	return PutBinary((char_t*)&value, sizeof(int64_t));
}








inline bool_t Buffer::PutUInt64(uint64_t value)
{
	return PutBinary((char_t*)&value, sizeof(uint64_t));
}








inline bool_t Buffer::PutFloat(float_t value)
{
	return PutBinary((char_t*)&value, sizeof(float_t));
}








inline bool_t Buffer::PutDouble(double_t value)
{
	return PutBinary((char_t*)&value, sizeof(double_t));
}








inline bool_t Buffer::GetByte(char_t  &value)
{
	return GetBinary(&value, sizeof(char_t));
}








inline bool_t Buffer::GetUByte(uchar_t &value)
{
	return GetBinary((char_t*)&value, sizeof(uchar_t));
}








inline bool_t Buffer::GetInt16(int16_t &value)
{
	return GetBinary((char_t*)&value, sizeof(int16_t));
}







inline bool_t Buffer::GetUInt16(uint16_t &value)
{
	return GetBinary((char_t*)&value, sizeof(uint16_t));
}







inline bool_t Buffer::GetInt32(int32_t &value)
{
	return GetBinary((char_t*)&value, sizeof(int32_t));
}








inline bool_t Buffer::GetUInt32(uint32_t &value)
{
	return GetBinary((char_t*)&value, sizeof(uint32_t));
}








inline bool_t Buffer::GetInt64(int64_t &value)
{
	return GetBinary((char_t*)&value, sizeof(int64_t));
}








inline bool_t Buffer::GetUInt64(uint64_t &value)
{
	return GetBinary((char_t*)&value, sizeof(uint64_t));
}








inline bool_t Buffer::GetFloat(float_t &value)
{
	return GetBinary((char_t*)&value, sizeof(float_t));
}








inline bool_t Buffer::GetDouble(double_t &value)
{
	return GetBinary((char_t*)&value, sizeof(double_t));
}








inline bool_t Buffer::PutBinary(char_t *value, uint32_t size)
{
	if(IsInBoundary(size))
	{
		ECILA_TRACE(); return FALSE;
	}

	memcpy(&data_[in_pos_], value, size);
	in_pos_ += size;

	return TRUE;
}








inline bool_t Buffer::GetBinary(char_t *value, uint32_t size)
{
	if(IsOutBoundary(size))
	{
		ECILA_TRACE(); return FALSE;
	}

	memcpy(value, &data_[out_pos_], size);
	out_pos_ += size;

	return TRUE;
}








inline bool_t Buffer::IsInBoundary(uint32_t n)
{
	if(size_ >= in_pos_ + n) { return FALSE; }

	return TRUE;
}








inline bool_t Buffer::IsOutBoundary(uint32_t n)
{
	if(in_pos_ >= out_pos_ + n) { return FALSE; }

	return TRUE;
}

