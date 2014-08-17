/**
* @file		CondVar.h
* @auther	Younghwan Kim (uglyduck68@gmail.com)
* @version	0.1
* @date		20140816
* @brief	interface file for conditional variable
*/
#pragma once

#include	"X1.h"
#include	"Mutex.h"

NS_X1_START
	/**
	* @class	CondVar
	* @brief	This class is wrapper of condition variable
	*/
	class DECL_SPEC_DLL CondVar
	{
	public:
		CondVar(void);
		~CondVar(void);

		/**
		* @function	Wait
		* @return	0 if success
		*			errno if fails
		*/
		int	Wait(Mutex& m);

		/**
		* @function	Signal
		* @return	0 if success
		*			errno if fails
		*/
		int	Signal();

	private:
		sp_thread_cond_t	m_CondVar;
	};
NS_X1_END
