/**
 * @file	TestThread.cpp
 * @author	Kim Young Hwan <uglyduck68@gmail.com>
 * @date	2014-05-14
 *
 * This program is to test the Thread class of X1 package.
 */
// TestThread.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

// All header files associated with OS are *NOT* included.
// These are handled by X1 package.
//#include <Windows.h>

//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}

#include <iostream> 

#include "Thread.h" 
#include "OSAL.h"

using namespace std; 
using namespace X1;

class Test1 : public THREAD 
{ 
private: 
	void Run() 
	{ 
		int name = getThreadId(); 
		for (int i = 0; i < 10; i++) 
		{ 
			try 
			{ 
				cout << name << ":" << i << endl; 

				OSAL::sleep(1); 
			} 
			catch (InterruptedException& e) 
			{ 
				cout << name << ": " << e.what(); 
				cout << " but continue" << endl; 
			} 
		} 
		cout << name << " ending" << endl; 
	} 
}; 


class Test2 : public THREAD 
{ 
private: 
	void Run() 
	{ 
		int name = getThreadId(); 

		for (int i = 0; i < 10; i++) 
		{ 
			cout << name << ":" << i << endl; 

			OSAL::sleep(1); 
		} 
		cout << name << " ending" << endl; 
	} 
}; 

class Test3 : public THREAD 
{ 
private: 
	Thread& _t; 

	void Run() 
	{ 
		cout << getThreadId() << " is joinning " << _t.getThreadId() << endl; 
		_t.Join(); 
		cout << getThreadId() << " is ending" << endl; 
	} 

public: 
	Test3(Thread& t) 
		: _t(t) {} 
}; 

void checkAlive(THREAD& thread) 
{ 
	int name = thread.getThreadId(); 

	if (thread.IsAlive()) 
	{ 
		cout << name << " is alive" << endl; 
	} 
	else 
	{ 
		cout << name << " is died" << endl; 
	} 
} 


void checkInterrupt(THREAD& thread) 
{ 
	int name = thread.getThreadId(); 

	if (thread.IsInterrupted()) 
	{ 
		cout << name << " is interrupted" << endl; 
	} 
	else 
	{ 
		cout << name << " is not interrupted" << endl; 
	} 
} 

int main() 
{ 
	try 
	{ 
		Test1	t1; 
		Test2	t2; 

		int t1Name = t1.getThreadId(); 
		int t2Name = t2.getThreadId(); 

		t1.Start(); 
		t2.Start(); 

		// main thread sleep for 2 sec.
		OSAL::sleep(2); 

		cout << "Now joinning " << t1Name << " until 2 sec" << endl; 

//		t1.Join();		// is success
		t1.Join(2000);	// fails at pthread_cond_timedwait
		
		checkAlive(t1); 
		checkAlive(t2); 
		
		try 
		{ 
			cout << "Now tring restart " << t1Name << endl; 
			t1.Start(); 
		} 
		catch (exception& e) 
		{ 
			cerr << typeid(e).name() << ": " << e.what() << endl; 
		} 

		OSAL::sleep(2); 

		cout << "Now interrupt " << t1Name << endl; 
		cout << "Now interrupt " << t2Name << endl; 
		
		if (t1.Interrupt() != X1_OK)
			cout << "fail to Interrupt " << t1Name << endl;

		if (t2.Interrupt() != X1_OK)
			cout << "fail to Interrupt " << t2Name << endl;

		OSAL::sleep(2); 

		checkAlive(t1); 
		checkAlive(t2); 

		cout << "Now joinning " << t2Name << endl; 

		t2.Join(); 

		Test3 t3(t1); 
		t3.Start(); 

		OSAL::sleep(1); 

		cout << "Now joinning " << t1Name << endl; 
		
		t1.Join(); 
		
		checkAlive(t1); 
		checkAlive(t2); 
		checkAlive(t3); 

		checkInterrupt(t1); 
		checkInterrupt(t2); 
		checkInterrupt(t3); 

		OSAL::sleep(1); 

		cout << "Now restart " << t2Name << endl; 

		t2.Start(); 
	} 
	catch (IllegalThreadStateException& e) 
	{ 
		cerr << typeid(e).name() << ": " << e.what() << endl; 
	} 

	OSAL::sleep(1); 

	cout << "Main thread ending" << endl; 

	return 0; 
} 


/* 실행 결과
Thread-0 
Second Thread 
Thread-0 
Second Thread 
Thread-0 
Now joinning Thread-0 until 2 sec 
Second Thread 
Thread-0 
Second Thread 
Thread-0 
Thread-0 is alive 
Second Thread is alive 
Now tring restart Thread-0 
27IllegalThreadStateException: Thread already started 
Second Thread 
Thread-0 
Second Thread 
Thread-0 
Now interrupt Thread-0 
Now interrupt Second Thread 
Thread-0: Thread interrupted but continue 
Thread-0 
Thread-0 
Thread-0 is alive 
Second Thread is died 
Now joinning Second Thread 
Third Thread is joinning Thread-0 
Thread-0 
Now joinning Thread-0 
Thread-0 ending 
Third Thread is ending 
Thread-0 is died 
Second Thread is died 
Third Thread is died 
Thread-0 is not interrupted 
Second Thread is interrupted 
Third Thread is not interrupted 
Now restart Second Thread 
27IllegalThreadStateException: Thread had been started 
Main thread ending 

*/