/**
* @file		CondVar.cpp
* @auther	Younghwan Kim<uglyduck68@gmail.com>
* @version	0.1
* @date		20140816
* @brief	implementation file for conditional variable class
*/
#include "CondVar.h"

NS_X1_USE

CondVar::CondVar(void)
{
	sp_thread_cond_init(&m_CondVar, NULL);
}


CondVar::~CondVar(void)
{
	sp_thread_cond_destroy(&m_CondVar);
}

/**
* @function	Wait
* @return	0 if success
*			errno if fails
*/
int	CondVar::Wait(Mutex& m)
{
	return sp_thread_cond_wait(&m_CondVar, &m.m_Mutex);
}

/**
* @function	Signal
* @return	0 if success
*			errno if fails
*/
int	CondVar::Signal()
{
	return sp_thread_cond_signal(&m_CondVar);
}