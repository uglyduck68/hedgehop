#pragma once


#include "ecila.h"







NS_ECILA_START

class DECL_SPEC_DLL RingBuffer
{
public:
	enum ENUM_PROP
	{
		DENY_OVERWRITE = 1 << 0,
		DENY_OVERREAD  = 1 << 1,
		DENY_BOTH      = DENY_OVERWRITE | DENY_OVERREAD,
	};

	enum ENUM_DEFAULT
	{
		DEFAULT_BUFFER_SIZE = 4096,
		MAX_BUFFER_SIZE		= DEFAULT_BUFFER_SIZE * 8,
	};


private:

	ENUM_PROP prop_;
	uint32_t size_;
	uint32_t free_size_;
	uint32_t in_pos_;
	uint32_t out_pos_;
	char_t   *data_;


public:
	 RingBuffer(uint32_t size = DEFAULT_BUFFER_SIZE, ENUM_PROP prop = DENY_BOTH);
	~RingBuffer();

	uint32_t Size		();

	bool_t	IsEmpty		();
	bool_t	Reset		();

	int32_t	Length		();
	int32_t Remain		();

	char_t*	GetInPtr	();
	char_t*	GetOutPtr	();

	bool_t	ForwardInPtr	(uint32_t nbytes);
	bool_t	RewindInPtr		(uint32_t nbytes);

	bool_t	ForwardOutPtr	(uint32_t nbytes);
	bool_t	RewindOutPtr	(uint32_t nbytes);
	
	bool_t	PutByte		(char_t		value);
	bool_t	PutUByte	(uchar_t	value);
	bool_t	PutInt16	(int16_t	value);
	bool_t	PutUInt16	(uint16_t	value);
	bool_t	PutInt32	(int32_t	value);
	bool_t	PutUInt32	(uint32_t	value);
	bool_t	PutInt64	(int64_t	value);
	bool_t	PutUInt64	(uint64_t	value);
	bool_t	PutFloat	(float_t	value);
	bool_t	PutDouble	(double_t	value);

	bool_t	GetByte		(char_t		&value);
	bool_t	GetUByte	(uchar_t	&value);
	bool_t	GetInt16	(int16_t	&value);
	bool_t	GetUInt16	(uint16_t	&value);
	bool_t	GetInt32	(int32_t	&value);
	bool_t	GetUInt32	(uint32_t	&value);
	bool_t	GetInt64	(int64_t	&value);
	bool_t	GetUInt64	(uint64_t	&value);
	bool_t	GetFloat	(float_t	&value);
	bool_t	GetDouble	(double_t	&value);

	bool_t	PutBinary	(char_t *value, uint32_t size);
	bool_t	GetBinary	(char_t *value, uint32_t size);



private:

	uint32_t GetInBoundary	();
	uint32_t GetOutBoundary	();

	void AdjFreeSizeAndInPos (uint32_t data_size);
	void AdjFreeSizeAndOutPos(uint32_t data_size);
};

#include "ringbuffer.inl"

NS_ECILA_END

