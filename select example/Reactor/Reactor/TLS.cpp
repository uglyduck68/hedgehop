#include "TLS.h"

NS_X1_START

ThrCtrlInfo::ThrCtrlInfo(void)
{
	m_bStop		= FALSE;
	m_bTask		= FALSE;

//	m_hThread	= 0;	// pthread_t is structure type
//	m_hThreadId	= 0;
	m_nThreadIdx	= 0;

	m_pThread		= 0;
	m_pTask		= 0;
	m_pTaskArg	= 0;
}


ThrCtrlInfo::~ThrCtrlInfo(void)
{
}

thread_local_storage_t TLS::key_  = 0;
TLS* TLS::inst_ = 0;

NS_X1_END