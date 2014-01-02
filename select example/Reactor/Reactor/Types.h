#pragma	once

#include "os.h"

//#include <stdio.h>

//#if	defined(_X1_WINDOWS_)

//#include <winsock2.h>
//#include <windows.h>
//
//#elif	defined(_X1_LINUX_)
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <poll.h>
//#include <sys/epoll.h>
//#elif	defined(_X1_VXWORKS_)
//#endif

// primitive type
#if defined (_X1_WINDOWS_)
	typedef BOOL					bool_t;
#else
	typedef bool					bool_t;
#endif

#if defined(WIDE_CHARACTER)
	typedef wchar_t					char_t;
	typedef unsigned short			uchar_t;
#else
	typedef char					char_t;
	typedef unsigned char			uchar_t;
#endif
	
	typedef unsigned char			byte_t;
	typedef float					float_t;
	typedef double					double_t;

	typedef short					short_t;
	typedef unsigned short			ushort_t;
	typedef unsigned int			uint_t;
	typedef unsigned long			ulong_t;
	typedef long long				llong_t;
	typedef unsigned long long		ullong_t;

	typedef	short					int16_t;
	typedef	int						int32_t;
	typedef	unsigned short			uint16_t;
	typedef	unsigned int			uint32_t;


// polymorphic type
#if defined (_X1_WINDOWS_)
	typedef INT_PTR			int_ptr;
	typedef UINT_PTR		uint_ptr;
	typedef LONG_PTR		long_ptr;
	typedef ULONG_PTR		ulong_ptr;
#else
	#if   defined (USE_32BIT)
	typedef int				int_ptr;
	typedef unsigned int	uint_ptr;
	typedef long			long_ptr;
	typedef unsigned long	ulong_ptr;
	#elif defined (USE_64BIT)
	typedef int64_t			int_ptr;
	typedef uint64_t		uint_ptr;
	typedef long			long_ptr;
	typedef unsigned long	ulong_ptr;
	#endif
#endif

// compatible type
#if defined(_X1_LINUX_) || defined(PTHREAD_H)	// pthread for WIN32
	typedef void*					handle_t;
	typedef int						socket_t;
	typedef int						descriptor_t;
	typedef uint64_t				serial_t;

	typedef struct _wsabuf
	{
		ulong_t len;
		char_t*	buf;
	} wsabuf_t;

	typedef struct _overlapped
	{
	} overlapped_t;

	typedef pthread_t				thread_t;
	typedef pthread_t				thread_id_t;
	typedef pthread_mutex_t			thread_mutex_t;
	typedef pthread_cond_t			thread_cond_t;
	typedef pthread_key_t			thread_local_storage_t;

	typedef void* (THRDFUNC)(void *thread_si);

	#ifndef INVALID_HANDLE_VALUE
	#define INVALID_HANDLE_VALUE	((handle_t)(ulong_ptr)-1)
	#endif // INVALID_HANDLE_VALUE

	#ifndef INVALID_SOCKET
	#define INVALID_SOCKET			(socket_t)(~0)
	#endif //INVALID_SOCKET

	#ifndef INADDR_ANY
	#define INADDR_ANY              (uint32_t)0x00000000
	#endif // INADDR_ANY

	#ifndef INFINITE
	#define INFINITE				0xFFFFFFFF
	#endif // INFINITE

	#ifndef FALSE
	#define FALSE					0
	#endif // FALSE

	#ifndef TRUE
	#define TRUE					1
	#endif // TRUE

#elif defined (_X1_WINDOWS_)
	typedef HANDLE					handle_t;
	typedef SOCKET					socket_t;
	typedef uint_ptr				descriptor_t;
	typedef uint64_t				serial_t;
	typedef WSABUF					wsabuf_t;
	typedef OVERLAPPED				overlapped_t;
	typedef HANDLE					thread_t;
	typedef uint32_t				thread_id_t;
	typedef CRITICAL_SECTION		thread_mutex_t;
	typedef CONDITION_VARIABLE		thread_cond_t;
	typedef DWORD					thread_local_storage_t;

	typedef uint32_t __stdcall THRDFUNC(void *thread_si);	// for _beginthreadex
#endif

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

