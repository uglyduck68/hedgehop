/*
 * =====================================================================================
 *  FILENAME	:  SimpleTimer.h
 *  DESCRIPTION	:  Simulate multiple timers using advanced Posix timer. This class 
 *  			   is intended to use for SIP timers.
 *  VERSION		:  1.0
 *  CREATED		:  01/18/2011 10:39:50 AM
 *  REVISION	:  none
 *  COMPILER	:  g++
 *  AUTHOR		:  Ngoc Son
 *  COPYRIGHT	:  Copyright (c) 2011, Ngoc Son
 *
 * =====================================================================================
 */
#ifndef SIMPLE_TIMER_H
#define SIMPLE_TIMER_H 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <list>
#include <string.h>

#define MIN_EXPIRE_TIME_MS	500 //minimum input expiration time
#define COMMON_STEP			250	//each 250 ms, posix timer will fires
#define INITIAL_TV_SEC	1
#define INITIAL_TV_NSEC	0
#define INTERVAL_TV_SEC	0
#define INTERVAL_TV_NSEC	(COMMON_STEP * 1000000)

using namespace std;
typedef enum TimerType {
	TimerType_Sip_T1 = 0,	//500 miliseconds
	TimerType_Sip_T2,		//4 seconds
	TimerType_Sip_T4,		//5 seconds
	TimerType_Sip_A,		//initially T1
	TimerType_Sip_B,		//64 * T1
	TimerType_Sip_D,		// >32 seconds for UDP | 0 second for TCP, SCTP
	TimerType_Sip_E,		//initially T1
	TimerType_Sip_F,		//64 * T1
	TimerType_Sip_G,		//initially T1
	TimerType_Sip_H,		//64 * T1
	TimerType_Sip_I,		//T4 for UDP | 0 second for TCP, SCTP
	TimerType_Sip_J,		//64 * T1 for UDP | 0 second for TCP, SCTP
	TimerType_Sip_K			//T4 for UDP | 0 second for TCP, SCTP
} TimerType;

typedef struct SingleTimer {
	int		mRemainTime; /* in milisecond */
	TimerType	mType;
} SingleTimer;

typedef void (*TimerHandler) (TimerType type);

class TimerList {

	private:
		static TimerList* mInstance;
		list<SingleTimer>	mList;
		timer_t			mTimerId;
		TimerHandler	mHandler;
		
	private:
		TimerList();
		~TimerList();

	public:
		static TimerList* mGetInstance();
		bool mRegisterHandler(TimerHandler handler);
		static void mListener(int signo);
		bool mAdd(int firedTime, TimerType type);
		void mDelete(int index);
		void mRun();
};

#endif
