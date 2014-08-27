/**
* @file		SelectTimer.h
* @auther	Younghwan Kim<uglyduck68@gmail.com>
* @version	0.1
* @date		20140826
* @brief	interface file for timer that use select API.
*/
#pragma once

#include "X1.h"
#include "timeval.h"
#include "Exception.h"
#include "Thread.h"

#include <queue>
#include <list>
#include <algorithm>
#include <time.h>
#include <sys/timeb.h>
#include <limits>

using namespace	std;

// default sleep time is 100 msec
#define		DFT_SLEEP(tv)	tv.tv_sec=0;tv.tv_usec = 100000

NS_X1_START

	class Timer;


	/**
	 * @class	SelectTimer 
	 * @brief	This class implements the timer using select or Sleep(WIN32) API.
	 *			Use one thread for multiple Timer classes.
	 */
	class DECL_SPEC_DLL SelectTimer :public Thread
	{
	public:
		SelectTimer(void);
		~SelectTimer(void);

		static int	RegisterTimer(Timer* pTimer);

		static int UnregisterTimer(int nID);
		int UnregisterTimer();

		// timer loop that must be executed in an independent thread.
		// this function use select API
//		static void *RunTimerLoop(/*SelectTimer*/void* pThis);
		sp_thread_result_t Run(Thread/*void*/* pThis);

		// run the timer function of timer handler
//		void RunHandler();

		bool IsExpired(Timer* pTimer);

		/**
		 * check the timer queue and run it if expired
		 * @return	# of run timer
		 */
		static int RunTimer() throw();

		/**
		 * compute the next sleep time by check the expire time of timer in queue
		 */
		static int ComputeSleepTime(struct timeval& tv);


		static void Stop()
		{
			m_bStop		= true;

			if (m_TimerQueue.size() > 0)
				DeleteQueue();
		}


	protected:
		int	UpdateExpireTime();



		/**
		 * priority queueu that contains the SelectTimers
		 */
		static list/*priority_queue*/<Timer*>	m_TimerQueue;

		static void DeleteQueue();

		static bool							m_bStop;

		// the count of instance that is used for m_nID
		static int							m_nInstance;

		static int GetID() 
		{
	#ifdef	max
	#undef	max
	#endif
			m_nInstance	= (m_nInstance + 1) % std::numeric_limits<int>::max();

			return m_nInstance;
		}

		/**
		 * debugging functions
		 */
		static void							Debug(char* pMsg);
		static void							PrintQ(char* pMsg);
	};

	class DECL_SPEC_DLL Timer
	{
	public:
		Timer();
		virtual ~Timer(void) {}

		/**
		 * This virtual function is called when the time is expired
		 *
		 * @param	pArg that is registed variable
		 */
		virtual void Run(Timer* pArg)	= 0;

		int ComputerSleepTime(struct timeval& tv);

		static double Now() throw();

		/**
		 * convert double typed time to struct timeval in second
		 */
		static void CvtTime(double ExpireTime, struct timeval& tv)
		{
			tv.tv_sec	= (long)ExpireTime;
			tv.tv_usec	= long((ExpireTime - tv.tv_sec) * 1000000.0);
		}

		/**
		 * convert struct timeval to double type in second
		 */
		static void CvtTime(struct timeval& tv, double& tm)
		{
			tm	= tv.tv_sec + tv.tv_usec / 1000000.0;
		}


		int UpdateExpireTime();

		void SetID(int nId) 
		{
			m_nID	= nId;
		}

		int	GetID()
		{
			return m_nID;
		}

		bool IsExpired();

		/**
		* @param		dExTime is sleep time in second
		*/
		void SetExpireTime(double dExTime)
		{
			m_Period		= dExTime;
			m_ExpireTime	= Now() + m_Period;
		}

		double GetExpireTime()
		{
			return m_ExpireTime;
		}
		/**
		 * comparator for priority queue.
		 * this comparator use m_ExpireTimer for ascending order
		 */
		//bool operator()(Timer* a, Timer* b)
		//{
		//	return Timer::Rank(a, b);
		//}

		//bool operator<(const Timer &t) const throw()
		//{
		//	// This is used for priority queues, so since
		//	// "higher priority" == "smaller timestamp",
		//	// return TRUE if this.time is greater than t.time
		//	return m_ExpireTime < t.m_ExpireTime;
		//}

		static bool Rank(Timer* lhs, Timer* rhs)
		{
			// This is used for priority queues, so since
			// "higher priority" == "smaller timestamp",
			// return TRUE if this.time is greater than t.time
			return lhs->m_ExpireTime < rhs->m_ExpireTime;
		}

		//bool operator==(const Timer& t)
		//{
		//	return m_nID == t.m_nID;
		//}
	protected:
		/**
		 * timer ID
		 */
		int		m_nID;

		/**
		 * expiration time in sec
		 */
		double								m_ExpireTime;

		/// sleep period
		double								m_Period;
	};

	//template<class T>
	//struct PointerPredicate
	//{
	//	bool operator()(T* a, T* b)
	//	{
	//		return Timer::Rank(a, b);
	//	}
	//};

NS_X1_END