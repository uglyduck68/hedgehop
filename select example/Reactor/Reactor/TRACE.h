#pragma once

#include "X1.h"

NS_X1_START

class DECL_SPEC_DLL Trace
{
protected:
	const char*	m_pMsg;

public:
	Trace(char* pMsg, int line = 0, const char* pFile = "");
	~Trace(void);
};

NS_X1_END

