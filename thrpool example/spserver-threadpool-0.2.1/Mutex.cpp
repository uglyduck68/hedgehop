/**
* @file		Mutex.cpp
* @auther	Younghwan Kim<uglyduck68@gmail.com>
* @version	0.1
* @date		20140816
* @brief	implementation file for Mutex class
*/

#include "Mutex.h"

NS_X1_USE

Mutex::Mutex(void)
{
	sp_thread_mutex_init(&m_Mutex, NULL);
}


Mutex::~Mutex(void)
{
	sp_thread_mutex_destroy(&m_Mutex);
}

/**
* @function	Lock
* @return	0 if success
*			errno if fails
*/
int	Mutex::Lock()
{
	return sp_thread_mutex_lock(&m_Mutex);
}

/**
* @function	UnLock
* @return	0 if success
*			errno if fails
*/
int	Mutex::UnLock()
{
	return sp_thread_mutex_unlock(&m_Mutex);
}