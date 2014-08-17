/**
* @file		sphtread.cpp
* @auther	Younghwan Kim<uglyduck68@gmail.com>
* @version	0.1
* @date		20140816
* @brief	implementation file for potability.
*/
#include	"spthread.h"
#include <stdio.h>

#if _BUILD_USE_PTHREAD_ == 1

sp_thread_id_t	sp_thread_get_id(sp_thread_t hThread)
{
	sp_thread_id_np_t   tid;
	sp_thread_t         self;
	self = pthread_self();
	pthread_getunique_np(&self, &tid);

	return tid;
}

#elif _BUILD_USE_PTHREAD_ == 1 || _BUILD_USE_PTHREAD_WIN32_ == 1

/**
* @function		sp_thread_get_id
* @brief		This function is used only with pthread-win32
*/
sp_thread_id_t	sp_thread_get_id(sp_thread_t hThread)
{
	return GetThreadId(pthread_getw32threadhandle_np(hThread));
}

#elif	_BUILD_USE_WIN32_ONLY_ == 1

int sp_thread_mutex_init( sp_thread_mutex_t * mutex, void * attr )
{
	*mutex = CreateMutex( NULL, FALSE, NULL );
	return NULL == * mutex ? GetLastError() : 0;
}

int sp_thread_mutex_destroy( sp_thread_mutex_t * mutex )
{
	int ret = CloseHandle( *mutex );

	return 0 == ret ? GetLastError() : 0;
}

int sp_thread_mutex_lock( sp_thread_mutex_t * mutex )
{
	int ret = WaitForSingleObject( *mutex, INFINITE );
	return WAIT_OBJECT_0 == ret ? 0 : GetLastError();
}

int sp_thread_mutex_unlock( sp_thread_mutex_t * mutex )
{
	int ret = ReleaseMutex( *mutex );
	return 0 != ret ? 0 : GetLastError();
}

int sp_thread_cond_init( sp_thread_cond_t * cond, void * attr )
{
	*cond = CreateEvent( NULL, FALSE, FALSE, NULL );
	return NULL == *cond ? GetLastError() : 0;
}

int sp_thread_cond_destroy( sp_thread_cond_t * cond )
{
	int ret = CloseHandle( *cond );
	return 0 == ret ? GetLastError() : 0;
}

/*
Caller MUST be holding the mutex lock; the
lock is released and the caller is blocked waiting
on 'cond'. When 'cond' is signaled, the mutex
is re-acquired before returning to the caller.
*/
int sp_thread_cond_wait( sp_thread_cond_t * cond, sp_thread_mutex_t * mutex )
{
	int ret = 0;

	sp_thread_mutex_unlock( mutex );

	ret = WaitForSingleObject( *cond, INFINITE );

	sp_thread_mutex_lock( mutex );

	return WAIT_OBJECT_0 == ret ? 0 : GetLastError();
}

int sp_thread_cond_signal( sp_thread_cond_t * cond )
{
	int ret = SetEvent( *cond );
	return 0 == ret ? GetLastError() : 0;
}

/**
* [NOTE] [20140815] sean, change
*	GetCurrentThreadId return DWORD thread ID.
*	But I force to cast it to sp_thread_t type for compatiblity.
*/
sp_thread_t sp_thread_self()
{
	return (sp_thread_t)GetCurrentThreadId();
}

int sp_thread_attr_init( sp_thread_attr_t * attr )
{
	*attr = 0;
	return 0;
}

int sp_thread_attr_setdetachstate( sp_thread_attr_t * attr, int detachstate )
{
	*attr |= detachstate;
	return 0;
}

int sp_thread_create( sp_thread_t * thread, sp_thread_attr_t * attr,
		sp_thread_func_t myfunc, void * args )
{
	unsigned int	nThreadID;

	// _beginthreadex returns 0 on an error
	*thread = (HANDLE)_beginthreadex( NULL, 0, myfunc, args, 0, &nThreadID );

	return *thread > 0 ? 0 : GetLastError();
}

/** [20140815] sean, add 
* always success because Windows don't have Detached or Joinable status.
*/
int	sp_thread_detach(sp_thread_t thread)
{
	return 0;
}

int	sp_thread_cancel(sp_thread_t thread)
{
	return TerminateThread(thread,(DWORD)-1);
}

int	sp_thread_join(sp_thread_t thread, void** retval)
{
	if (WaitForSingleObject( (HANDLE)thread,INFINITE ) == WAIT_OBJECT_0)
	{
		if (retval)
			GetExitCodeThread( (HANDLE)thread, (LPDWORD)*retval );

		return 0;
	}

	return GetLastError();
}

int sp_thread_attr_destroy(sp_thread_attr_t* attr)
{
	*attr	= 0;

	return 0;
}

sp_thread_id_t	sp_thread_get_id(sp_thread_t hThread)
{
	return GetThreadId(hThread);
}

void sp_thread_destroy(sp_thread_t h)
{
	CloseHandle(h);
}
#endif