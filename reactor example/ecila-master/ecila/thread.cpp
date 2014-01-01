#include "thread.h"








US_ECILA

Thread::Thread()
{
}








Thread::~Thread()
{
}








bool_t Thread::Start(ITask* task, void *arg)
{

	thread_si_.b_task_		= (task) ? TRUE : FALSE;
	thread_si_.thread_		= this;
	thread_si_.task_		= task;
	thread_si_.user_ptr_	= arg;

	#ifdef OS_WINDOWS
	thread_si_.h_thread_ = (thread_t)_beginthreadex(0, 0, Invoker, &thread_si_, 0, &thread_si_.thread_id_);
	if(!thread_si_.thread_id_) { ECILA_TRACE(); return FALSE; }
	#else
	int32_t ret = pthread_create(&thread_si_.h_thread_, 0, Invoker, &thread_si_);
	if(ret < 0) { ECILA_TRACE(); return FALSE; }

	thread_si_.thread_id_ = thread_si_.h_thread_;
	#endif

	return TRUE;
}








void Thread::Join(int32_t timeout_msec)
{
	#ifdef OS_WINDOWS
	WaitForSingleObject(thread_si_.h_thread_, timeout_msec == 0 ? INFINITE : timeout_msec);
	#else
	int32_t status = 0;
	pthread_join(thread_si_.h_thread_, (void **)&status); 
	#endif
}








void Thread::ThreadIDX(uint32_t thread_idx)
{
	thread_si_.thread_idx_ = thread_idx;
}







void* Thread::UserPtr()
{
	ThreadSpecData *p_thread_si = ThreadLocalStorageKey::Instance()->GetValue();
	if(!p_thread_si) { ECILA_TRACE(); return 0; }

	return p_thread_si->user_ptr_;
}






thread_id_t Thread::Self()
{
	/*
	ThreadSpecData *p_thread_si = ThreadLocalStorageKey::Instance()->GetValue();
	if(!p_thread_si) { ECILA_TRACE(); return 0; }

	return p_thread_si->h_thread_;
	*/

	#ifdef OS_WINDOWS
	return GetCurrentThreadId();
	#else
	return pthread_self();
	#endif

}








uint32_t Thread::ThreadIDX()
{
	ThreadSpecData *p_thread_si = ThreadLocalStorageKey::Instance()->GetValue();
	if(!p_thread_si) { ECILA_TRACE(); return 0; }

	return p_thread_si->thread_idx_;
}








bool_t Thread::IsStop()
{
	ThreadSpecData *p_thread_si = ThreadLocalStorageKey::Instance()->GetValue();
	if(!p_thread_si) { ECILA_TRACE(); return 0; }

	return p_thread_si->b_stop_;
}








void Thread::Stop()
{
	ThreadSpecData *p_thread_si = ThreadLocalStorageKey::Instance()->GetValue();
	if(!p_thread_si) { ECILA_TRACE(); return; }

	p_thread_si->b_stop_ = TRUE;
}


