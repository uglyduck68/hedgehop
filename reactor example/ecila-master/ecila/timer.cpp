#include "timer.h"








US_ECILA

///////////////////////////////////////////////////////////////////////////////
//
// Time
//
///////////////////////////////////////////////////////////////////////////////
Time::Time()
{
}








Time::~Time()
{
}







Time::TICK32 Time::Tick32()
{
	#ifdef OS_WINDOWS
	return timeGetTime();
	#else
	struct timeval tv;
	gettimeofday(&tv, 0);
	return (((Time::TICK32)tv.tv_sec * 1000) + ((Time::TICK32)tv.tv_usec / 1000));
	#endif
}








Time::TICK64 Time::Tick64()
{
	#ifdef OS_WINDOWS

	bool_t ret = FALSE;

	LARGE_INTEGER freq;  freq.QuadPart  = 0;
	LARGE_INTEGER count; count.QuadPart = 0;

	ret = QueryPerformanceFrequency(&freq);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	ret = QueryPerformanceCounter(&count);
	if(!ret) { ECILA_TRACE(); return 0; }

	return (Time::TICK64)(count.QuadPart / (freq.QuadPart / 1000000.0f));
	#else
	struct timeval tv;
	gettimeofday(&tv, 0);
	return (((Time::TICK64)tv.tv_sec * 1000000) + (Time::TICK64)tv.tv_usec);
	#endif
}








bool_t Time::GetLocalDateTimeValue(DateTimeValue &dtv)
{

#ifdef OS_WINDOWS
	int32_t ret = 0;
	time_t	cur_time;
	struct tm cur_tm;
	memset(&cur_tm, 0, sizeof(cur_tm));

	time(&cur_time);

	ret = localtime_s(&cur_tm, &cur_time);
	if(ret != 0) { ECILA_TRACE(); return FALSE ; }

	dtv.year_	= cur_tm.tm_year + 1900;
	dtv.mon_	= cur_tm.tm_mon + 1;
	dtv.day_	= cur_tm.tm_mday;
	dtv.hour_	= cur_tm.tm_hour;
	dtv.min_	= cur_tm.tm_min;
	dtv.sec_	= cur_tm.tm_sec;
	dtv.mday_	= cur_tm.tm_mday;
	dtv.wday_	= cur_tm.tm_wday;
#else
	time_t	cur_time;
	struct tm *ret = 0;

	time(&cur_time);

	ret = localtime(&cur_time);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	dtv.year_	= ret->tm_year + 1900;
	dtv.mon_	= ret->tm_mon + 1;
	dtv.day_	= ret->tm_mday;
	dtv.hour_	= ret->tm_hour;
	dtv.min_	= ret->tm_min;
	dtv.sec_	= ret->tm_sec;
	dtv.mday_	= ret->tm_mday;
	dtv.wday_	= ret->tm_wday;
#endif

	//adjust leap second
	if(dtv.sec_ > 60) dtv.sec_ = 59;

	return TRUE;
}








bool_t Time::GetGMTDateTimeValue(DateTimeValue &dtv)
{
#ifdef OS_WINDOWS
	int32_t ret = 0;
	time_t	cur_time;
	struct tm cur_tm;
	memset(&cur_tm, 0, sizeof(cur_tm));

	time(&cur_time);

	ret = gmtime_s(&cur_tm, &cur_time);
	if(ret != 0) { ECILA_TRACE(); return FALSE ; }

	dtv.year_	= cur_tm.tm_year + 1900;
	dtv.mon_	= cur_tm.tm_mon + 1;
	dtv.day_	= cur_tm.tm_mday;
	dtv.hour_	= cur_tm.tm_hour;
	dtv.min_	= cur_tm.tm_min;
	dtv.sec_	= cur_tm.tm_sec;
	dtv.mday_	= cur_tm.tm_mday;
	dtv.wday_	= cur_tm.tm_wday;
#else
	time_t	cur_time;
	struct tm *ret = 0;

	time(&cur_time);

	ret = gmtime(&cur_time);
	if(!ret) { ECILA_TRACE(); return FALSE; }

	dtv.year_	= ret->tm_year + 1900;
	dtv.mon_	= ret->tm_mon + 1;
	dtv.day_	= ret->tm_mday;
	dtv.hour_	= ret->tm_hour;
	dtv.min_	= ret->tm_min;
	dtv.sec_	= ret->tm_sec;
	dtv.mday_	= ret->tm_mday;
	dtv.wday_	= ret->tm_wday;
#endif

	//adjust leap second
	if(dtv.sec_ > 60) dtv.sec_ = 59;

	return TRUE;
}








///////////////////////////////////////////////////////////////////////////////
//
// Timer32
//
///////////////////////////////////////////////////////////////////////////////
Timer32::Timer32()
:	start_tick_	(0),
	end_tick_	(0)
{
}








Timer32::~Timer32()
{
}







void Timer32::Start()
{
	start_tick_ = Tick32();
}








void Timer32::End()
{
	end_tick_ = Tick32();
}








void Timer32::Reset()
{
	start_tick_ = end_tick_ = 0;
}








Time::TICK32 Timer32::ElapsedTick()
{
	if(end_tick_ < start_tick_)
	{
		ECILA_TRACE(); return 0;
	}

	return end_tick_ - start_tick_;
}








Time::TICK32 Timer32::Tick32()
{
#ifdef OS_WINDOWS
	return timeGetTime();
#else
	struct timeval tv;
	gettimeofday(&tv, 0);
	return (((Time::TICK32)tv.tv_sec * 1000) + ((Time::TICK32)tv.tv_usec / 1000));
#endif
}








///////////////////////////////////////////////////////////////////////////////
//
// Timer64
//
///////////////////////////////////////////////////////////////////////////////
Timer64::Timer64()
{
	start_tick_		= 0;
	end_tick_		= 0;

	#ifdef OS_WINDOWS
	freq_.QuadPart	= 0;
	old_core_mask_	= 0;

	old_core_mask_	= SetThreadAffinityMask(GetCurrentThread(), 1);

	InitFrequency();
	#endif
};








Timer64::~Timer64()
{
	#ifdef OS_WINDOWS
	SetThreadAffinityMask(GetCurrentThread(), old_core_mask_);
	#endif
}








void Timer64::Start()
{
	start_tick_ = Tick64();
}








void Timer64::End()
{
	end_tick_ = Tick64();
}








void Timer64::Reset()
{
	start_tick_ = end_tick_ = 0;
}








Time::TICK64 Timer64::ElapsedTick()
{
	if(end_tick_ < start_tick_)
	{
		ECILA_TRACE(); return 0;
	}

	#ifdef OS_WINDOWS
	return (Time::TICK64)((end_tick_ - start_tick_) / (freq_.QuadPart / 1000000.0f));
	#else
	return end_tick_ - start_tick_;
	#endif
}








bool_t Timer64::InitFrequency()
{
#ifdef OS_WINDOWS
	
	bool_t ret = FALSE;

	ret = QueryPerformanceFrequency(&freq_);
	if(!ret) { ECILA_TRACE(); return FALSE; }

#endif
	return TRUE;
}








Time::TICK64 Timer64::Tick64()
{
#ifdef OS_WINDOWS

	bool_t ret = FALSE;

	LARGE_INTEGER count; count.QuadPart = 0;

	ret = QueryPerformanceCounter(&count);
	if(!ret) { ECILA_TRACE(); return 0; }

	return count.QuadPart;
#else
	struct timeval tv;
	gettimeofday(&tv, 0);
	return (((Time::TICK64)tv.tv_sec * 1000000) + (Time::TICK64)tv.tv_usec);
#endif
}

