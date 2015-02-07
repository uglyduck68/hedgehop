#ifndef MUTEX_H
#define MUTEX_H
///////////////////////////////////////////////////////////////////////////////
// Mutex.h
// Rohit Joshi
// It implements the mutex for unix/linx os
//////////////////////////////////////////////////////////////////////////////
#include <pthread.h>

// Lock class
template <class T> class Lock 
{
	T& obj_;  //member
public:
	// lock
	Lock(T& obj):obj_(obj)
	{
		obj_.Lock();
	}
	// unlock
	~Lock()
	{
		obj_.Unlock();
	}
};
// mutex class for unix/linux
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
		if(bRecursive) {
			pthread_mutexattr_t attr;
			pthread_mutexattr_init(&attr);
			pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE);
			pthread_mutex_init(&m_mMutex, &attr);
			pthread_mutexattr_destroy(&attr);
		}else {
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

private:
    pthread_mutex_t m_mMutex;   // pthread mutex
    void operator=(Mutex &m_mMutex) {} // private = operator 
    Mutex( const Mutex &m_mMutex ) {}  // private copy constructor
};




#endif // MUTEX_H
