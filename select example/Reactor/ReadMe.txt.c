/*
Mutex ���� ����
1. iperf 2.0.5 version�� ���� Mutex.h�� HAVE_POSIX_THREAD, HAVE_WIN32_THREAD macro������ init, lock, unlock, uninit�� ��������.
	�� ����� ������ NullMutex��(template) ����� �� ���Ե�.

2. HAVE_WIN32_THREAD ���� lock�� WaitForSingleObject, unlock�� ReleaseMutex�� �������. ���� ��쿣
	EnterCriticalSection & LeaveCriticalSection�� �������. �������� ����?

	CRITICAL_SECTION is user object But Mutex is kernel object that can be shared across processes.

*/