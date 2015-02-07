#ifndef MUTEX_H
#define MUTEX_H
///////////////////////////////////////////////////////////////////////////////
// Mutex.h
// Rohit Joshi
// It implements the mutex for windows
//////////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <process.h>

// Lock class
template <class T > class Lock 
{
	T& obj_; // type object
public:
    // Lock
	Lock(T& obj):obj_(obj)
	{
		obj_.Lock();
	}
	// Unlock
	~Lock()
	{
		obj_.Unlock();
	}
};
// Mutex class for windows
class Mutex
{
public:
	// constructor
    Mutex()
	{
		InitializeCriticalSection(&m_mMutex);
	}
    // destructor
	virtual ~Mutex()
	{
		DeleteCriticalSection(&m_mMutex);
	}
	// lock
	bool Lock()
	{
		EnterCriticalSection(&m_mMutex);
		return true;
	}
	// unlock
	bool Unlock()
	{
		LeaveCriticalSection(&m_mMutex);
		return true;
	}
	// try lock
	bool TryLock()
	{
		/*
		if(TryEnterCriticalSection(&m_mMutex)) {
			return true;
		}else {
		    return false;
		}
		*/
		
	}

private:
    CRITICAL_SECTION  m_mMutex;  // critical section as mutex
    void operator=(Mutex &m_mMutex) {} // private = operator
    Mutex( const Mutex &m_mMutex ) {} // private copy constructor
};




#endif // MUTEX_H
