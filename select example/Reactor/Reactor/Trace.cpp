#include "TRACE.h"
#include "Debug.h"

NS_X1_START

Trace::Trace(char* pMsg, int line/* = 0*/, const char* pFile /*= ""*/)
{
	m_pMsg	= pMsg;

//	LOG_INTERNAL("%s in file '%s' on line %d\n", m_pMsg, pFile, line);

	LOG_DEBUG(pMsg);
}


Trace::~Trace(void)
{
//	LOG_INTERNAL("\t leaving %s\n", m_pMsg);
	LOG_DEBUG("\t leaving %s\n", m_pMsg);
}

NS_X1_END
