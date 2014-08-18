/**
* @file		Task.h
* @auther	Younghwan Kim (uglyduck68@gmail.com)
* @version	0.1
* @date		20140816
* @brief	interface file for task
*/
#pragma once

#include	"X1.h"

NS_X1_START
	/**
	* @class	Task
	* @brief	This class is wrapper of basic function
	*/
	class DECL_SPEC_DLL Task
	{
	public:
		Task(void);
		virtual ~Task(void);

		virtual sp_thread_result_t	Run(Task* pArg)	= 0;

		/*
		* @function		Self
		* @return		return thread handle. Not thread ID.
		*/
		sp_thread_t&	Self();

		/*
		* @function		GetId()
		* @return		return thread id that is printable.
		*/
		sp_thread_id_t	GetId();

	protected:
		/** contains the thread handle */
		sp_thread_t		m_h;
	};

NS_X1_END