#pragma once

#include "os.h"






// primitive type
#if defined (OS_WINDOWS)
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








// polymorphic type
#if defined (OS_WINDOWS)
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
#if defined (OS_WINDOWS)
	typedef HANDLE					handle_t;
	typedef SOCKET					socket_t;
	typedef uint_ptr				descriptor_t;
	typedef uint64_t				serial_t;
	typedef WSABUF					wsabuf_t;
	typedef OVERLAPPED				overlapped_t;
	typedef HANDLE					thread_t;
	typedef uint32_t				thread_id_t;
	typedef CRITICAL_SECTION		thread_mutex_t;
	typedef CONDITION_VARIABLE		thread_condition_t;
	typedef DWORD					thread_local_storage_t;
#else
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
	typedef pthread_cond_t			thread_condition_t;
	typedef pthread_key_t			thread_local_storage_t;

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
#endif
