// Timer.cc -- 
//  Copyright (c) Sriram Rao
//                This source is provided as is without any express or
//                written warranty.  Permission to use, copy, modify, and 
//                distribute this software for any purpose without fee is
//                hereby granted, provided that this entire notice is 
//                included in all copies of any software which is or includes
//                a copy or modification of this software and in all copies
//                of the supporting documentation for such software.
//                All Rights Reserved.
// $Locker:  $
// $Log: Timer.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:16  ravshank
// Start of Spring 2001
//
// Revision 1.6  2000/06/27 13:23:17  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.5  2000/06/26 21:31:18  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.4  2000/06/23 02:47:49  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.3  2000/06/22 22:23:08  phoebe
// Changed the Timer namespace to a proper class. Put all the global timers into Timer class as private data members.
//
// Revision 1.2  2000/06/22 20:59:12  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.1.1.1  2000/03/06 20:00:22  phoebe
// Sriram's original code with no modifications
//
// $Id: Timer.cc,v 1.1.1.1 2001/02/12 00:00:16 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun Apr 25 16:10:54 1999
// Last Modified By: Sriram Rao
// Last Modified On: Fri Jul 16 12:50:54 1999
// Update Count    : 75
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <assert.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <iostream>
#include <list>
#include <sys/time.h>

#include "Egida_Object.H"
#include "Globals.H"
#include "Timer.H"


//static members of the Timer class
struct timeval Timer::appStart;
struct timeval Timer::appEnd;
struct timeval Timer::rollForwardStart;
struct timeval Timer::rollForwardEnd; 
int Timer::timeNow = 0;
Int_List Timer::req_List;

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Install the SIGALRM handler for handling timer interrupts
// 
// Arguments:
// 	NONE
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Timer::Initialize()
{
  struct sigaction act;

  req_List.clear();
  timeNow = 0;
  act.sa_handler = Expired;
  sigemptyset(&act.sa_mask);
  act.sa_flags = SA_RESTART;
  if (sigaction(EGIDA_TIMER_SIGNAL, &act, NULL) < 0) {
    std::cout << "trouble with sigaction: " << errno << std::endl;
    _exit(0);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Cancel any pending SIGALRM's
// 
// Arguments:
// 	NONE
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Timer::Terminate()
{
  // cancel any pending alarms
  alarm(0);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
//      Signal handler for handling timer interrupts.
// 
// Arguments:
// 	code --- is the signal # that is passed to this method by the OS.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Timer::Expired(int code)
{
  int tNext;

  timeNow = req_List.front();
  req_List.pop_front();

  Egida::TimerExpired();
  while (!req_List.empty()) {
    tNext = req_List.front();
    if (tNext - timeNow > 0) {
      // Go ahead and set the next alarm
      alarm(tNext - timeNow);
      break;
    }
    else {
      // this is a duplicate---tNext < tNow is not possible
      assert((tNext - timeNow) == 0);
      // if we are going to remove it, then set-off the timer again
      Egida::TimerExpired();
      req_List.pop_front();
    }
  }
  // if there are no requests, throw in one
  if (req_List.empty())
    SetTimer(15);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Request that a timer interrupt after nSec elapse.
// 
// Arguments:
// 	nSec --- # of seconds after which the next interrupt should
// 	         occur. 
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Timer::SetTimer(int nSec)
{
  int tNext = timeNow + nSec;

  if (!req_List.empty()) {
    if (tNext < req_List.front()) {
      alarm(0);
      req_List.push_front(tNext);
      alarm(nSec);
    }
    else {
      req_List.push_back(tNext);
      req_List.sort();
    }
  }
  else {
    alarm(0);
    req_List.push_front(tNext);
    alarm(nSec);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Blocks Egida's timer interrupt from being generated.
// 
// Arguments:
// 	NONE
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void Timer::BlockTimerInterrupt()
{
  sighold(EGIDA_TIMER_SIGNAL);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Enables Egida's timer signal to be delivered to the process.
// 
// Arguments:
// 	NONE
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void Timer::UnblockTimerInterrupt()
{
  sigrelse(EGIDA_TIMER_SIGNAL);
}



void Timer::AppStart()
{
  gettimeofday(&appStart, NULL);
}

void Timer::AppEnd()
{
  gettimeofday(&appEnd, NULL);
}

double Timer::AppTimeSpent()
{
  double timeSpent = 0.0;
  ComputeTimeDiff(&timeSpent, appStart, appEnd);
  return timeSpent;
}



void Timer::RollForwardStart()
{
  gettimeofday(&rollForwardStart, NULL);
}

void Timer::RollForwardEnd()
{
  gettimeofday(&rollForwardEnd, NULL);
}

double Timer::RollForwardTimeSpent()
{
  double timeSpent = 0.0;
  ComputeTimeDiff(&timeSpent, rollForwardStart, rollForwardEnd);
  return timeSpent;
}


//returns the number of seconds between the start of the application
//  and the current time.
double Timer::CurrentElapsedTime()
{
  double timeSpent = 0.0;
  struct timeval temp;
  
  gettimeofday(&temp, NULL);
  ComputeTimeDiff(&timeSpent, appStart, temp);
  return timeSpent;
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Computes the difference between two struct timeval's.
// 
// Arguments:
// 	diff --- output parameter that contains the result.
//      t1, t2 --- input parameter's that have been set.
// 
// Results:
// 	*diff = (t2 - t1) in seconds
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Timer::ComputeTimeDiff(double *diff, 
		     const struct timeval &t1,
		     const struct timeval &t2)
{
  int numSec = t2.tv_sec - t1.tv_sec;

  // This is simple arithmetic: to compute 15 - 7, need to "borrow"
  // from tens place, blah, blah.  This code is doing that!
  if (t2.tv_usec > t1.tv_usec)
    *diff = (double) (t2.tv_sec - t1.tv_sec) +
      (double) ((t2.tv_usec - t1.tv_usec) * 1e-6);
  else {
    *diff = (double) (t2.tv_sec - t1.tv_sec - 1) +
      (double) (((1e6 + t2.tv_usec) - t1.tv_usec) * 1e-6);
    numSec--;
  }

  // floating point problems---on pentiums returns -NaN at times
  if (((int) *diff) != numSec)
    *diff = (double) numSec;
}

