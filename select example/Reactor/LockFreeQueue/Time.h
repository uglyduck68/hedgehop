#pragma once

#ifdef	WIN32
// for timezone
struct timezone
{
	int  tz_minuteswest; /* minutes W of Greenwich */
	int  tz_dsttime;     /* type of dst correction */
};
// struct timeval is defined in WinSock.h on Windows
#endif

class Time
{
public:
	Time(void);
	~Time(void);

	static int gettimeofday(struct timeval *tv, struct timezone *tz);
};

