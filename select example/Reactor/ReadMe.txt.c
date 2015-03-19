/*
Mutex 관련 내용
1. iperf 2.0.5 version을 보니 Mutex.h에 HAVE_POSIX_THREAD, HAVE_WIN32_THREAD macro만으로 init, lock, unlock, uninit을 정의했음.
	이 방법도 좋으나 NullMutex를(template) 사용할 수 없게됨.

2. HAVE_WIN32_THREAD 에서 lock을 WaitForSingleObject, unlock을 ReleaseMutex를 사용했음. 나의 경우엔
	EnterCriticalSection & LeaveCriticalSection를 사용했음. 차이점이 뭐지?

	CRITICAL_SECTION is user object But Mutex is kernel object that can be shared across processes.

*/