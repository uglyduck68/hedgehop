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

	class Exception : public std::exception 
	{
	public:
		Exception() throw();
		Exception(const std::string &error) throw();
		Exception(const Exception &e) throw();
		virtual ~Exception() throw();
    
		/*
		 * Grab the optional error message from the exception.
		 */
		virtual std::string getMessage(void) const throw();
    
		/*
		 * Make our messages more useful for std::exception
		 */
		virtual const char *what(void) const throw()	
		{
			return m_ErrorMsg.c_str();
		}
    
		/*
		 * Just in case you wanted to set the message, also.
		 */
		virtual void setMessage(const std::string &msg) throw();
    
		/*
		 * Output an error message.
		 */
		friend std::ostream &operator<<(std::ostream &o, const Exception &e) throw();
    
	protected:
		std::string m_ErrorMsg;
	};

	class InterruptedException : public Exception  
	{ 
	public: 
		InterruptedException() throw();
		InterruptedException(const string&  message) throw();

	}; 

	/**
	* @class	IllegalThreadStateException
	* @brief	has all exceptions related with Thread.
	*/
	class IllegalThreadStateException : public Exception  
	{ 
	public: 
		IllegalThreadStateException() throw();
		IllegalThreadStateException(const string&  message) throw();
	}; 


	class IllegalArgumentException : public Exception 
	{
	public:
		IllegalArgumentException() throw();
		IllegalArgumentException(const std::string &msg) throw();
	};
	class MemoryException : public Exception 
	{
	public:
		MemoryException() throw();
		MemoryException(const std::string &error) throw();
	};

	class NullPointerException : public MemoryException 
	{
	public:
		NullPointerException() throw();
		NullPointerException(const std::string &msg) throw();
	};

	class NoMemoryException : public MemoryException 
	{
	public:
		NoMemoryException() throw();
	};

	class FileException : public Exception 
	{
	public:
		typedef enum {
			DFT_ERROR,      // The default
			READ_ERROR, // Can't read the file
		} type_t;
    
		FileException() throw();
		FileException(const std::string &msg) throw();
		FileException(type_t type, const std::string &msg) throw();
    
		virtual type_t getType(void) const throw();
    
	protected:
		type_t m_type;
	};

	class NotFoundException : public Exception 
	{
	public:
		NotFoundException() throw();
		NotFoundException(const std::string &msg) throw();
	};

	class XMLException : public Exception 
	{
	public:
		typedef enum {
			DFT_ERROR,             // Something bad happened.
			READ_ERROR,        // We can't read the source data
			PARSE_ERROR,       // The parser bit it.
			INTERNAL_ERROR,    // Some strange libxml error occurred.
			INVALID_XML,       // "Your input was valid XML but wasn't schema valid"
			MISSING_ATTRIBUTE, // Missing attrs on some element
		} type_t;

		XMLException() throw();
		XMLException(type_t type) throw();
		XMLException(type_t type, const std::string &error) throw();
    
		virtual type_t getType(void) const throw();
    
	protected:
		type_t m_type;
	};

	class ExperimentException : public Exception 
	{
	public:
		ExperimentException() throw();
	};

	class ProcessException : public Exception {
	public:
		ProcessException() throw();
		ProcessException(const std::string &message) throw();
	};

	class MessageException : public Exception 
	{
	public:
		typedef enum {
		READ_ERROR,       // We can't read some data, or can't read enough data.
		READ_INCOMPLETE,  // Can't read enough data.
		WRITE_ERROR,      // Ditto, but for writes.
		WRITE_INCOMPLETE, // Can't write enough data.
		INVALID_MESSAGE,  // Tried to send a message without initializing all fields.
		ILLEGAL_ARGUMENT, // Somewhere in the middle we called a function poorly.
		DATA_CORRUPTION,  // We got garbage, and we know it.
		} type_t;
    
		MessageException(type_t type) throw();
		MessageException(type_t type, const std::string &error) throw();
    
		virtual type_t getType(void) const throw();

	protected:
		type_t m_type;
	};

	class MeshException : public Exception 
	{
	public:
		typedef enum {
		/* Generic badness */
		DFT_ERROR,
		/* Called invite() on someone who we're already talking to. */
		ALREADY_CONNECTED,
		/* Lookup failed */
		UNKNOWN_NODE,
		/* Unable to get auth to the thingy, or don't know the user name. */
		NO_PRINCIPALS,
		/* (IllegalArgument) You called a root function as non-root. */
		NOT_ROOT,
		/* Some part of the "connecting" process failed. */
		INVITE_FAILURE,
		/* No progress can be made. */
		FATAL,
		} type_t;
    
		MeshException(type_t type) throw();
		MeshException(const std::string &msg) throw();
		MeshException(type_t type, const std::string &msg) throw();
    
		virtual type_t getType(void) const throw();
    
	private:
		type_t m_type;
	};

	/*
	 * class DataException
	 *
	 * Exceptions that are due to some internal class data corruption,
	 * incorrectness, etc.
	 */
	class DataException : public Exception 
	{
	public:
		DataException() throw();
		DataException(const std::string &error) throw();
	};

	/*
	 * class UnimplementedException
	 *
	 * For all those annoying things we haven't gotten to yet.
	 */
	class UnimplementedException : public Exception 
	{
	public:
		UnimplementedException() throw();
		UnimplementedException(const std::string &error) throw();
	};



NS_X1_END