/**
* @file		Exception.h
* @auther	Younghwan Kim<uglyduck68@gmail.com>
* @version	0.1
* @date		20140816
* @brief	interface file for exception classes
*/
#pragma once

#include	"X1.h"
#include	<stdexcept> 

using namespace std; 

NS_X1_START

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

	/**
	* @class	IllegalThreadStateException
	* @brief	has all exceptions related with Thread.
	*/
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