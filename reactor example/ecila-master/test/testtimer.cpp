#include "testtimer.h"

#include <ecila/timer.h>








void TestTimer::Do()
{
	
	DateTimeValue local_dtv;
	DateTimeValue gmt_dtv;

	assertEquals(TRUE, Time::GetLocalDateTimeValue(local_dtv));
	assertEquals(TRUE, Time::GetGMTDateTimeValue(gmt_dtv));


	Timer32 t32;
	Timer64 t64;

	t32.Start();
	ecila_msleep(1000);
	t32.End();
	assertEquals((Time::TICK32)1000, t32.ElapsedTick());



	t64.Start();
	ecila_msleep(2000);
	t64.End();
	assertEquals((Time::TICK64)2000000, t64.ElapsedTick());
}

