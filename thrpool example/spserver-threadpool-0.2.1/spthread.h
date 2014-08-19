/*
* @file		Types.h
* @author	Younghwan Kim<uglyduck68@gmail.com>
* @version	0.1
* @date		20140816
* @brief	define data types for each build envirionment and platform
*/

#include "Config.h"

#include <stdlib.h>


#ifdef	WIN32	// this is same with _BUILD_USE_WIN32_ONLY_ == 1 || _BUILD_USE_PTHREAD_WIN32_ == 1 condition.
#include <winsock2.h>
#include <process.h>
#include <Windows.h>

///////////////////////////////////////////////////////////////////////////////
// timeval
///////////////////////////////////////////////////////////////////////////////

typedef	long	suseconds_t;

// struct timeval is defined in winsock2.h
//struct timeval {
//	time_t    tv_sec;         /* seconds */
//	long    tv_usec;        /* and microseconds */
//};

// for timezone
struct timezone
{
	int  tz_minuteswest; /* minutes W of Greenwich */
	int  tz_dsttime;     /* type of dst correction */
};
#endif

#pragma once

///////////////////////////////////////////////////////////////////////////////
// Type Definition related to platform
///////////////////////////////////////////////////////////////////////////////
#ifdef	WIN32
	typedef BOOL					bool_t;

#elif defined(LINUX)
	typedef bool					bool_t;

#endif

///////////////////////////////////////////////////////////////////////////////
// Type Definition related to threading
///////////////////////////////////////////////////////////////////////////////

#if _BUILD_USE_PTHREAD_ == 1

typedef	pthread_id_np_t	sp_thread_id_t;		/** integral type thread id */

#elif _BUILD_USE_PTHREAD_ == 1 || _BUILD_USE_PTHREAD_WIN32_ == 1

/// pthread

#include <pthread.h>
//#include <unistd.h>

typedef void * sp_thread_result_t;
typedef pthread_mutex_t sp_thread_mutex_t;
typedef pthread_cond_t  sp_thread_cond_t;
typedef pthread_t       sp_thread_t;
#ifdef	WIN32
typedef	DWORD			sp_thread_id_t;
#endif
typedef pthread_attr_t  sp_thread_attr_t;

#define sp_thread_mutex_init(m,a)   pthread_mutex_init(m,a)
#define sp_thread_mutex_destroy(m)  pthread_mutex_destroy(m)
#define sp_thread_mutex_lock(m)     pthread_mutex_lock(m)
#define sp_thread_mutex_unlock(m)   pthread_mutex_unlock(m)

#define sp_thread_cond_init(c,a)    pthread_cond_init(c,a)
#define sp_thread_cond_destroy(c)   pthread_cond_destroy(c)
#define sp_thread_cond_wait(c,m)    pthread_cond_wait(c,m)
#define sp_thread_cond_signal(c)    pthread_cond_signal(c)

#define sp_thread_attr_init(a)        pthread_attr_init(a)
#define sp_thread_attr_setdetachstate pthread_attr_setdetachstate
#define SP_THREAD_CREATE_DETACHED     PTHREAD_CREATE_DETACHED

#define sp_thread_self    pthread_self
#define sp_thread_create  pthread_create

/** [20140815] sean, add */
#define	sp_thread_detach	pthread_detach
#define	sp_thread_cancel	pthread_cancel
#define	sp_thread_join		pthread_join
#define	sp_thread_attr_destroy	pthread_attr_destroy
#define	sp_thread_destroy


#define SP_THREAD_CALL
typedef sp_thread_result_t ( * sp_thread_func_t )( void * args );

/**
* @function		sp_thread_get_id
* @brief		This function is used only with pthread-win32
*/
extern	sp_thread_id_t	sp_thread_get_id(sp_thread_t hThread);

#ifdef	WIN32
#define	sp_sleep(x)	Sleep(x * 1000)
#else
#define sp_sleep(x) sleep(x)
#endif

#elif _BUILD_USE_WIN32_ONLY_ == 1 ///////////////////////////////////////////////////////////////////////

// win32 thread


/** [20140815] sean, change */
//typedef unsigned sp_thread_t;	/** sp_thread_t has thread ID */
typedef HANDLE	sp_thread_t;	/** sp_thread_t has thread handle */
typedef	DWORD	sp_thread_id_t;		/** integral type thread id */

typedef unsigned sp_thread_result_t;
#define SP_THREAD_CALL __stdcall
typedef sp_thread_result_t ( __stdcall * sp_thread_func_t )( void * args );

typedef HANDLE  sp_thread_mutex_t;
typedef HANDLE  sp_thread_cond_t;
typedef DWORD   sp_thread_attr_t;

#define SP_THREAD_CREATE_DETACHED 1
#define sp_sleep(x) Sleep(1000*x)

extern int sp_thread_mutex_init( sp_thread_mutex_t * mutex, void * attr );

extern int sp_thread_mutex_destroy( sp_thread_mutex_t * mutex );

extern int sp_thread_mutex_lock( sp_thread_mutex_t * mutex );

extern int sp_thread_mutex_unlock( sp_thread_mutex_t * mutex );

extern int sp_thread_cond_init( sp_thread_cond_t * cond, void * attr );

extern int sp_thread_cond_destroy( sp_thread_cond_t * cond );

/*
Caller MUST be holding the mutex lock; the
lock is released and the caller is blocked waiting
on 'cond'. When 'cond' is signaled, the mutex
is re-acquired before returning to the caller.
*/
extern int sp_thread_cond_wait( sp_thread_cond_t * cond, sp_thread_mutex_t * mutex );

extern int sp_thread_cond_signal( sp_thread_cond_t * cond );

/**
* [NOTE] [20140815] sean, change
*	GetCurrentThreadId return DWORD thread ID.
*	But I force to cast it to sp_thread_t type for compatiblity.
*/
extern sp_thread_t sp_thread_self();

extern int sp_thread_attr_init( sp_thread_attr_t * attr );

extern int sp_thread_attr_setdetachstate( sp_thread_attr_t * attr, int detachstate );

extern int sp_thread_create( sp_thread_t * thread, sp_thread_attr_t * attr,
		sp_thread_func_t myfunc, void * args );

/** 
* [20140815] sean, add 
* thread cancellation on Windows is *NOT* implemented.
*/
extern	int	sp_thread_detach(sp_thread_t thread);
extern	int	sp_thread_cancel(sp_thread_t thread);
extern	int	sp_thread_join(sp_thread_t thread, void** retval);
extern	int sp_thread_attr_destroy(sp_thread_attr_t*);
extern	sp_thread_id_t	sp_thread_get_id(sp_thread_t hThread);
extern	void sp_thread_destroy(sp_thread_t h);



#endif
