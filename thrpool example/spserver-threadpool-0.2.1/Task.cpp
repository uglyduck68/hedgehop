/**
* @file		Task.cpp
* @auther	Younghwan Kim (uglyduck68@gmail.com)
* @version	0.1
* @date		20140816
* @brief	implementation file for Task
*/
#include "Task.h"

NS_X1_USE

Task::Task(void)
#if	_BUILD_USE_PTHREAD_ == 1 || _BUILD_USE_WIN32_ONLY_ == 1
	: m_h(0)
#endif
{
#if _BUILD_USE_PTHREAD_WIN32_ == 1
	m_h.p	= 0;
#endif	
}


Task::~Task(void)
{
	
}

sp_thread_t&	Task::Self()
{
	return m_h;//sp_thread_self();
}

/*
* @function		GetId()
* @return		return thread id that is printable.
*/
sp_thread_id_t	Task::GetId()
{
	return sp_thread_get_id(m_h);
}
