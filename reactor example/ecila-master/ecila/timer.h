#pragma once


#include "ecila.h"








NS_ECILA_START

class DECL_SPEC_DLL DateTimeValue
{
public:
	int32_t year_, mon_, day_;
	int32_t hour_, min_, sec_;
	int32_t mday_, wday_;

	DateTimeValue()
	:	year_(0), mon_(0), day_(0),
		hour_(0), min_(0), sec_(0),
		mday_(0), wday_(0)
	{
	}

	~DateTimeValue()
	{
	}
};








class DECL_SPEC_DLL TimeValue
{
public:
	uint64_t sec_;		// sec_		= (t_usec_ / 1000000)
	uint64_t msec_;		// msec_	= ((t_usec_ / 1000) % 1000)
	uint64_t usec_;		// usec_	= (t_usec_ % 1000)

	uint64_t t_usec_;	//total usec

	TimeValue()
	:	sec_(0), msec_(0), usec_(0), t_usec_(0)
	{
	}

	~TimeValue() {}
};








class DECL_SPEC_DLL Time
{
public:
	typedef uint32_t TICK32;
	typedef uint64_t TICK64;

	 Time();
	~Time();

	static TICK32 Tick32();
	static TICK64 Tick64();

	static bool_t GetLocalDateTimeValue(DateTimeValue &dtv);
	static bool_t GetGMTDateTimeValue  (DateTimeValue &dtv);
};








//for msec tick
class DECL_SPEC_DLL Timer32
{
private:
	Time::TICK32	start_tick_;
	Time::TICK32	end_tick_;


public:
	 Timer32();
	~Timer32();

	void			Start();
	void			End();
	void			Reset();
	Time::TICK32	ElapsedTick();


private:
	Time::TICK32	Tick32();
};








//for usec tick
class DECL_SPEC_DLL Timer64
{
private:
	#ifdef OS_WINDOWS
	LARGE_INTEGER	freq_;
	DWORD			old_core_mask_;
	#endif
	Time::TICK64	start_tick_;
	Time::TICK64	end_tick_;




public:
	 Timer64();
	~Timer64();

	void			Start();
	void			End();
	void			Reset();
	Time::TICK64	ElapsedTick();


private:
	bool_t			InitFrequency();
	Time::TICK64	Tick64();
};

NS_ECILA_END

