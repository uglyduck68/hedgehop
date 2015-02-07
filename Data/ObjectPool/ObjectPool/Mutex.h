/**
 * @file		Mutex.h
 * @author		sean kim <uglyduck68@gmail.com>
 * @brief		file for Lock and Mutex classes
 * @date		2015/02/05
 * @version		1.0
 */
#pragma once

#include <pthread.h>

/**
 * @class		ScopedLock
 * @brief		simple scoped lock class
 */
template <class T> class ScopedLock 
{
protected:
	T& m_obj;  //member

public:
	// lock
	ScopedLock(T& obj):m_obj(obj)
	{
		m_obj.Lock();
	}
	// unlock
	~ScopedLock()
	{
		m_obj.Unlock();
	}
};

/**
 * @class		Mutex
 * @brief		class for POSIX mutex
 */
class Mutex
{
public:
	// default constructor
	Mutex()
	{
		pthread_mutex_init(&m_mMutex, NULL);
	}
	// constructor with recursive param
    Mutex(bool bRecursive)
	{
		if(bRecursive) 
		{
			pthread_mutexattr_t attr;
			pthread_mutexattr_init(&attr);
			pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE);
			pthread_mutex_init(&m_mMutex, &attr);
			pthread_mutexattr_destroy(&attr);
		}
		else 
		{
			pthread_mutex_init(&m_mMutex, NULL);
		}
	}
	
    // destructor
	virtual ~Mutex()
	{
		pthread_mutex_unlock(&m_mMutex);
		pthread_mutex_destroy(&m_mMutex);
	}
	// lock
	int Lock()
	{
		return pthread_mutex_lock(&m_mMutex);
	}
	//unlock
	int Unlock()
	{
		return pthread_mutex_unlock(&m_mMutex);
	}
	// try lock
	int TryLock()
	{
		return pthread_mutex_trylock(&m_mMutex);
	}

	operator pthread_mutex_t*()
	{
		return &m_mMutex;
	}

private:
    pthread_mutex_t m_mMutex;   // pthread mutex
    void operator=(Mutex &m_mMutex) {} // private = operator 
    Mutex( const Mutex &m_mMutex ) {}  // private copy constructor
};
