#pragma	once

#include <stdio.h>

#if	defined(_X1_WINDOWS_)

#include <winsock2.h>
#include <windows.h>

#elif	defined(_X1_LINUX_)
#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>
#include <sys/epoll.h>
#elif	defined(_X1_VXWORKS_)
#endif

typedef	unsigned short	uint16_t;
typedef	unsigned int	uint32_t;

namespace X1
{

	const int				INVALID_HANDLE	= -1;
	typedef unsigned long	EVENT_MASK;
	
#if	defined(_X1_LINUX_)

typedef	int		X1_SOCHANDLE;

#elif	defined(_X1_VXWORKS_)

typedef	int		X1_SOCHANDLE;

#elif	defined(_X1_WINDOWS_)
	typedef	SOCKET				X1_SOCHANDLE;	// SOCKET is defined as UINT_PTR
#endif
}

//struct timeval {
//	long    tv_sec;         /* seconds */
//	long    tv_usec;        /* and microseconds */
//};

// for timezone
struct timezone
{
	int  tz_minuteswest; /* minutes W of Greenwich */
	int  tz_dsttime;     /* type of dst correction */
};

enum RET_TYPE
{
	X1_CLOSED		= -1,
	X1_OK			= 0,
	X1_FAIL			= 1,
	X1_EFILEOPEN	= 2,
	X1_ENETINIT		= 3,
	X1_ENULLOBJECT	= 4
};

enum DEMUX_TYPE
{
	X1_SELECT	= 1,
	X1_POLL,
	X1_EPOLL,
	X1_DEVPOLL,
	X1_KQUEUE,
};