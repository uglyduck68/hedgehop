/**
* @file		Mutex.h
* @auther	Younghwan Kim<uglyduck68@gmail.com>
* @version	0.1
* @date		20140816
* @brief	This file has Mutex class.
*/
#pragma once

#include	"Defines.h"
#include	"spthread.h"

NS_X1_START
	/**
	* @class	Mutex
	* @brief	This class is wrapper of mutex
	*/
	class DECL_SPEC_DLL Mutex
	{
	public:
		Mutex(void);
		~Mutex(void);
		
		/**
		* @function	Lock
		* @return	0 if success
		*			errno if fails
		*/
		int	Lock();

		/**
		* @function	UnLock
		* @return	0 if success
		*			errno if fails
		*/
		int	UnLock();

	private:
		sp_thread_mutex_t	m_Mutex;

		friend class CondVar;
	};
NS_X1_END
