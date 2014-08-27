/**
* @file		SelectTimer.cpp
* @auther	Younghwan Kim<uglyduck68@gmail.com>
* @version	0.1
* @date		20140826
* @brief	implementation file for timer that use select API.
*/

#include	"SelectTimer.h"
#include	"Exception.h"
#include	<queue>
#include	<errno.h>


using namespace std;
NS_X1_USE

///////////////////////////////////////////////////////////////////////////////
// Timer class
///////////////////////////////////////////////////////////////////////////////

Timer::Timer() : m_nID(-1),
	m_ExpireTime(0), m_Period(0)
{
}

/**
* @return	current time in second
*/
double Timer::Now(void) throw()
{
    struct timeval		tv;

    gettimeofday(&tv);
    
    return tv.tv_sec + (double)tv.tv_usec/1000000.0;
}


int Timer::UpdateExpireTime()
{
	// set m_ExpireTime using user set sleep time

	m_ExpireTime	= (Now() + m_Period);

	return 0;
}

///////////////////////////////////////////////////////////////////////////////
// SelectTimer class
///////////////////////////////////////////////////////////////////////////////

/**
 * static variables
 */
list<Timer*> SelectTimer::m_TimerQueue;
bool						SelectTimer::m_bStop		= false;
int							SelectTimer::m_nInstance	= 0;

SelectTimer::SelectTimer(void)
{
}

SelectTimer::~SelectTimer(void)
{
	DeleteQueue();
}

/**
 * delete all in timer queue
 */
void SelectTimer::DeleteQueue()
{
	while(!m_TimerQueue.empty())
	{
		m_TimerQueue.pop_front();
	}
}


/**
 * Add timer to internal queue
 *
 * @param	timer pointer
 * @return	timer id if success
 *			-1 if fails
 * @exception	OutOfMemory
 */

int	SelectTimer::RegisterTimer(Timer* pTimer)
{
	if ( pTimer->GetExpireTime() <= 0)
		return -1;

	m_TimerQueue.push_back(pTimer);

	m_TimerQueue.sort(pTimer->Rank);

	int		nID	= GetID();

	pTimer->SetID( nID );

	return nID;
}

/**
 * unregister the timer
 * @return	0 if success
 */
int SelectTimer::UnregisterTimer(int nID)
{
	int		nRet	= 1;

	for (list<Timer*>::iterator itr = m_TimerQueue.begin(); itr != m_TimerQueue.end(); itr++)
	{
		if ((*itr)->GetID() == nID)
		{
			itr	= m_TimerQueue.erase(itr);
			break;
		}
	}

	return nRet;
}

/**
 * run the timer function of timer handler of Timer
 */
//void SelectTimer::RunHandler()
//{
//	try
//	{
//		if (m_pHandler)
//			// call the timer function
//			m_pHandler->Expired(this);
//	}
//	catch (Exception e)
//	{
//		// print exception message
//		e.getMessage().c_str();
//	}
//	catch (...)
//	{
//		// unknown exception
//	}
//}

bool Timer::IsExpired()
{
	return (Now() > GetExpireTime());
}


/**
 * check the timer queue and run it if expired
 * @return	# of run timer
 */
int SelectTimer::RunTimer() throw()
{
	int		nRunTimer	= 0;

	for (list<Timer*>::iterator itr = m_TimerQueue.begin(); itr != m_TimerQueue.end(); itr++)
	{
		if ((*itr)->IsExpired())
		{
			// run timer handler
			(*itr)->Run(*itr);

			// update the time of timer
			(*itr)->UpdateExpireTime();

			nRunTimer++;
		}
	}

	list<Timer*>::iterator itr = m_TimerQueue.begin();

	// update priority_queue
	m_TimerQueue.sort( (*itr)->Rank);

	return nRunTimer;
}

/**
* FIX: change timeval to double for convenience
*/
int Timer::ComputerSleepTime(struct timeval& tv)
{
    double remaining = m_ExpireTime - Timer::Now();

	tv.tv_sec		= 0;
	tv.tv_usec		= 0;

    if (remaining < 0.0) 
	{
		remaining = 0.0;

		return 1;
    }
	else
	{
		// convert remaining to struct timeval
		CvtTime(remaining, tv);
	}

	return 0;
}

/**
 * compute the next sleep time by check the expire time of timer in queue
 */
int SelectTimer::ComputeSleepTime(struct timeval& tv)
{
	if (m_TimerQueue.empty()) 
	{
		DFT_SLEEP(tv);
	} 
	else 
	{
		if (m_TimerQueue.front()->ComputerSleepTime(tv) == 1)
//		if (tv.tv_sec > 0 || tv.tv_usec > 100000) 
		{
			DFT_SLEEP(tv);
		}
	}

	return 0;
}

#ifdef	WIN32
/**
 * Get error message from errno or WSAGetLastError()
 * @param	dw is errno or WSAGetLastError
 * @return	error message that must be free
 */
void* GetErrorMessage(DWORD dw)
{
    LPVOID lpMsgBuf;

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL );

//    LocalFree(lpMsgBuf);

	return lpMsgBuf;
}
#endif

sp_thread_result_t SelectTimer::Run(Thread/*void*/* pThis)
{
#ifdef	_DEBUG
	Debug("RunTimerLoop");
#endif


	m_bStop	= false;

	while(!m_bStop)
	{
		struct timeval	tv;

		// check timer queue and run the handler
		SelectTimer::RunTimer();

		// compute the sleep time
		SelectTimer::ComputeSleepTime(tv);

//		time	= Now();

#ifdef	WIN32
			double	SleepTime;

			Timer::CvtTime(tv, SleepTime);

			printf("sleep time: %d\n", (int)(SleepTime * 1000));

			Sleep(DWORD(SleepTime * 1000));
#else


		int		n;
		double	time;

		do
		{
			// sleep here
			tv.tv_sec	= 0;
			tv.tv_usec	= 0;

			/**
			 * On Windows
			 * select(0, NULL, NULL, NULL, ...) always fails.
			 * error code is 10022(WSAEINVAL)
			 */
			n	= select(0, NULL, NULL, NULL, &tv);
#ifdef	_DEBUG
		printf("Sleep(%d, %d, %d) time: %ld, %ld -> %lf\n", n, errno, EINTR, tv.tv_sec, tv.tv_usec, tv.tv_sec + (double)tv.tv_usec/1000000.0);
#endif
			if (n == SOCKET_ERROR)
			{
				void*	pMsg;

				pMsg	= GetErrorMessage(WSAGetLastError());

				printf("Error Msg is '%s'\n", pMsg);

				LocalFree(pMsg);

				return NULL;
			}

		} while((n == -1) && (errno == EINTR));
#endif
	}

	return NULL;
}

/**
 * debugging functions
 */
void SelectTimer::Debug(char* pMsg)
{
	struct timeval	tv;

	gettimeofday(&tv);

	printf("%s: %8.3lf sec\n", pMsg, tv.tv_sec + (double)tv.tv_usec/1000000.0);
}

void SelectTimer::PrintQ(char* pMsg)
{
	printf("%s\n", pMsg);

	for (list<Timer*>::iterator itr = m_TimerQueue.begin(); itr != m_TimerQueue.end(); itr++)
	{
		printf("timer ID: %d,   expire time: %lf\n", (*itr)->GetID(), (*itr)->GetExpireTime());
	}

	return;
}
