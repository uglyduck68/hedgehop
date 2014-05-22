/**
 * @file	Thread.h
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 * @date	2014-05-14
 * @version	0.3
 *
 * This is interface of Thread class that is wrapper of pthread or OpenThreads.
 */
#ifndef _THREAD_H_ 
#define _THREAD_H_ 

#include "X1.h"

// The library used with X1 package is included in config.h through X1.h.
//#include <pthread.h> 
#include <string> 
#include <stdexcept> 

using namespace std; 

#pragma once

NS_X1_START

/**
 * @class	Thread
 * 
 * I design the class by refer to the thread class of Java originally.
 * This class provides thread interfaces and 
 * For compatability of this and OpenThreads 
 * I change some interfaces of OpenThreads to
 * follow the name convention of X1 packages.
 */
class Thread
{
public:
	Thread(void);
	virtual ~Thread(); 
	void Init();
	int Start(); 

	/**
	 * This Join function is implemented differently with Join of OpenThreads.
	 * This Join use condition variable internally, But Join of OpenThreads just
	 * call pthread_join API.
	 */
	int Join(); 
	int Join(unsigned long msec); 
	int GetThreadId() 	{ return m_nId; }

	// for compatability with OpenThreads
	int getThreadId() { return GetThreadId();}

	ret_t Interrupt(); 
	bool IsInterrupted(); 
	bool IsAlive(); 


private: 
	enum STATE_THREAD 
	{
		INIT = 0, 
		STARTED = 1, 
		DIED = -1
	} ;
	STATE_THREAD			m_state; 
	bool					m_joinning; 
	bool					m_isInterrupted; 

	/// mutex used with m_condJoin
	thread_mutex_t			m_mutexJoin; 

	/// condition variable to wake up the blocked threads in Join
	thread_cond_t			m_condJoin; 
	thread_mutex_t			m_mutexSync; 
	static thread_attr_t	m_attr; 
	thread_t				m_thread; 
	static long				m_id; 
	long					m_nId;


	static void* ThreadHandler(void* arg); 
	static void InterruptHandler(int sigInt); 
	

//	virtual void run() = 0;	
	virtual void Run() = 0; 

};

class InterruptedException : public exception  
{ 
public: 
	explicit InterruptedException(const string&  message) 
		: m_message(message) 
	{} 

	virtual ~InterruptedException() throw() 
	{} 

	virtual const char* what() const throw() 
	{ 
		return m_message.c_str(); 
	} 

private: 
	string m_message; 

}; 


class IllegalThreadStateException : public exception  
{ 
public: 
	explicit IllegalThreadStateException(const string&  message) 
		: m_message(message) 
	{} 

	virtual ~IllegalThreadStateException() throw() 
	{} 

	virtual const char* what() const throw() 
	{ 
		return m_message.c_str(); 
	} 

private: 
	string m_message; 

}; 

NS_X1_END

#endif