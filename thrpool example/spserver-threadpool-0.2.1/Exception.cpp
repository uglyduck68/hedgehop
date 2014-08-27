/**
* @file		Exception.cpp
* @auther	Younghwan Kim<uglyduck68@gmail.com>
* @version	0.1
* @date		20140826
* @brief	implementation file for exception class
*/

#include <string>
#include "exception.h"


using namespace std;
NS_X1_USE

/**********************************************************************
 * class Exception
 **********************************************************************/
Exception::Exception() throw()
{
}

Exception::Exception(const string &error) throw() :
    m_ErrorMsg(error)
{
}

Exception::Exception(const Exception &e) throw()
{
    m_ErrorMsg = e.m_ErrorMsg;

}

Exception::~Exception() throw()
{

}

string Exception::getMessage(void) const throw ()
{
    return m_ErrorMsg;
}

void Exception::setMessage(const string &msg) throw()
{
    m_ErrorMsg = msg;
}

ostream &operator<<(ostream &o, const Exception &e) throw()
{
    o << e.getMessage();
    return o;
}

/**********************************************************************
 * class InterruptedException
 **********************************************************************/
InterruptedException::InterruptedException()  throw() :
    Exception("Interrupted to function") { }

InterruptedException::InterruptedException(const string &msg)  throw() :
    Exception(msg) { }

/**********************************************************************
 * class IllegalThreadStateException
 **********************************************************************/
IllegalThreadStateException::IllegalThreadStateException()  throw() :
    Exception("ill legal to function") { }

IllegalThreadStateException::IllegalThreadStateException(const string &msg)  throw() :
    Exception(msg) { }

/**********************************************************************
 * class IllegalArgumentException
 **********************************************************************/
IllegalArgumentException::IllegalArgumentException(void) throw() :
    Exception("Illegal argument to function") { }

IllegalArgumentException::IllegalArgumentException(const string &msg)
    throw() : Exception(msg) { }

/**********************************************************************
 * class MemoryException
 **********************************************************************/
MemoryException::MemoryException(void) throw() :
    Exception("Unspecified memory error") { }

MemoryException::MemoryException(const string &error) throw() :
    Exception(error) { }

/**********************************************************************
 * class NullPointerException
 **********************************************************************/
NullPointerException::NullPointerException(void) throw() :
    MemoryException("Unexpected NULL pointer") { }

NullPointerException::NullPointerException(const string &msg) throw() :
    MemoryException("NullPointerException: "+msg) { }

/**********************************************************************
 * class NoMemoryException
 **********************************************************************/
NoMemoryException::NoMemoryException(void) throw() :
    MemoryException("Out of memory.") { }

/**********************************************************************
 * class FileException
 **********************************************************************/
FileException::FileException(void) throw() :
    Exception("File error"), m_type(DFT_ERROR) { }

FileException::FileException(const string &msg) throw() :
    Exception(msg), m_type(DFT_ERROR) { }

FileException::FileException(type_t type, const string &msg) throw() :
    Exception(msg), m_type(type) { }

FileException::type_t FileException::getType(void) const throw() {
    return m_type;
}

/**********************************************************************
 * class NotFoundException
 **********************************************************************/
NotFoundException::NotFoundException(void) throw() :
    Exception("Object Not Found") { }

NotFoundException::NotFoundException(const string &message) throw() :
    Exception("Object Not Found: " + message) { }

/**********************************************************************
 * class XMLException
 **********************************************************************/
XMLException::XMLException(void) throw() :
    Exception("XML parsing or data format error"), m_type(DFT_ERROR) { }

XMLException::XMLException(type_t type) throw() :
    Exception("XML parsing or data format error"), m_type(type) { }

XMLException::XMLException(type_t type, const string &error) throw() :
    Exception(error), m_type(type) { }

XMLException::type_t XMLException::getType(void) const throw () {
    return m_type;
}

/**********************************************************************
 * class ExperimentException
 **********************************************************************/
ExperimentException::ExperimentException(void) throw() :
    Exception("Unspecified experiment exception (missing data?)") { }

/**********************************************************************
 * class ProcessException
 **********************************************************************/
ProcessException::ProcessException(void) throw() :
    Exception("Unspecified process exception (process in wrong state?)") { }

ProcessException::ProcessException(const string &message) throw() :
    Exception(message) { }

/**********************************************************************
 * class MessageException
 **********************************************************************/
MessageException::MessageException(type_t type) throw() :
    Exception(), m_type(type)
{
    switch(m_type) {
    case READ_ERROR:
	setMessage("Could not read (enough) data.");
	break;
    case READ_INCOMPLETE:
	setMessage("Could not read all the data.");
	break;
    case WRITE_ERROR:
	setMessage("Could not write (enough) data.");
	break;
    case WRITE_INCOMPLETE:
	setMessage("Could not write all the data.");
	break;
    case INVALID_MESSAGE:
	setMessage("Unable to send uninitialized message.");
	break;
    case ILLEGAL_ARGUMENT:
	setMessage("Illegal argument to a message function.");
	break;
    case DATA_CORRUPTION:
	setMessage("Message data corruption.");
	break;
    }
}

MessageException::MessageException(type_t type, const string &error) throw() :
    Exception(error), m_type(type) { }

MessageException::type_t MessageException::getType(void) const throw() {
    return m_type;
}

/**********************************************************************
 * class MeshException
 **********************************************************************/
MeshException::MeshException(type_t type) throw() :
    Exception(), m_type(type)
{
    switch(m_type) {
    case DFT_ERROR:
	setMessage("Unspecified error with the Mesh.");
	break;
    case ALREADY_CONNECTED:
	setMessage("PLuSH is already connected to the given host.");
	break;
    case UNKNOWN_NODE:
	setMessage("PLuSH does not know about requested node.");
	break;
    case NO_PRINCIPALS:
	setMessage("Unable to find suitable resource principals to connect.");
	break;
    case NOT_ROOT:
	setMessage("A root-only function was called from this host, which is non-root.");
	break;
    case INVITE_FAILURE:
	setMessage("Unable to invite a new mesh member.");
	break;
    case FATAL:
	setMessage("Unspecified fatal error.");
	break;
    }
}

MeshException::MeshException(const string &msg) throw() :
    Exception(msg), m_type(DFT_ERROR) { }

MeshException::MeshException(type_t type, const string &error) throw() :
    Exception(error), m_type(type) { }

MeshException::type_t MeshException::getType(void) const throw() {
    return m_type;
}

/**********************************************************************
 * class DataException
 **********************************************************************/
DataException::DataException(void) throw() :
    Exception("Unspecified corrupted or incorrect data in a class.") { }

DataException::DataException(const string& msg) throw() :
    Exception(msg) { }

/**********************************************************************
 * class UnimplementedException
 **********************************************************************/
UnimplementedException::UnimplementedException(void) throw() :
    Exception("Sorry, we haven't implemented that feature yet.") { }

UnimplementedException::UnimplementedException(const string &error) throw() :
    Exception("UnimplementedException: "+error) { }
