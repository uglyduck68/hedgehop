#include "TLS.h"

NS_X1_START

ThrdCtrlInfo::ThrdCtrlInfo(void)
{
	b_stop_		= FALSE;
	b_task_		= FALSE;

//	h_thread_	= 0;	// pthread_t is structure type
//	thread_id_	= 0;
	thread_idx_	= 0;

	thread_		= 0;
	task_		= 0;
	user_ptr_	= 0;
}


ThrdCtrlInfo::~ThrdCtrlInfo(void)
{
}

thread_local_storage_t TLS::key_  = 0;
TLS* TLS::inst_ = 0;

NS_X1_END