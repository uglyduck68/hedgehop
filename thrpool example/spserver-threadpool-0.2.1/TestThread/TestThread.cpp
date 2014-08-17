// TestThread.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Thread.h"

NS_X1_USE

class MyThread : public Thread
{
  public:
	  MyThread() {}

    sp_thread_result_t	Run(Task* pArg) 
	{
		MyThread*	pThread	= static_cast<MyThread*>(pArg);

        for (int i = 0; i < 5; i++) 
		{
#if	_BUILD_USE_PTHREAD_WIN32_ == 1
			printf("thread %lu running - %d\n",  (long unsigned int)pThread->GetId(), i+1);
#else
			// Linuex
			printf("thread %lu running - %d\n",  (long unsigned int)pThread->GetId(), i+1);
#endif
            sp_sleep(2);
        }
#if	_BUILD_USE_PTHREAD_WIN32_ == 1
		printf("thread done %lu\n", (long unsigned int)pThread->GetId());
#else
		printf("thread done %lu\n", (long unsigned int)pThread->GetId());
#endif

        return NULL;
    }
};

/*
* pthread-win32 don't work well sometimes.
* Join function waits infinitely because 
* Send signal firse before wait.
*/
int _tmain(int argc, _TCHAR* argv[])
{
    MyThread* thread1 = new MyThread();
    MyThread* thread2 = new MyThread();
    thread1->Start();
    thread2->Start();
    thread1->Join();
    thread2->Join();
    printf("main done\n");

	delete thread1;
	delete thread2;

    exit(0);
	
	return 0;
}

