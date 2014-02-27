// Timer.H -- 
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
// $Log: Timer.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:15  ravshank
// Start of Spring 2001
//
// Revision 1.3  2000/06/22 22:23:03  phoebe
// Changed the Timer namespace to a proper class. Put all the global timers into Timer class as private data members.
//
// Revision 1.2  2000/06/22 20:58:54  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.1.1.1  2000/03/06 20:00:16  phoebe
// Sriram's original code with no modifications
//
// $Id: Timer.H,v 1.1.1.1 2001/02/12 00:00:15 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Mon May  3 12:46:26 1999
// Last Modified By: Sriram Rao
// Last Modified On: Fri May  7 18:23:34 1999
// Update Count    : 16
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_TIMER_H)
#define _TIMER_H

#include <sys/time.h>
#include <list>

typedef std::list<int> Int_List;

class Timer {
public:
  static void Initialize(void);
  static void Terminate(void);
  static double CurrentElapsedTime(void);

  static void AppStart(void);
  static void AppEnd(void);
  static double AppTimeSpent(void);

  static void RollForwardStart(void);
  static void RollForwardEnd(void);
  static double RollForwardTimeSpent(void);

  static void SetTimer(int nSec);
  static void Expired(int code);

  static void BlockTimerInterrupt();
  static void UnblockTimerInterrupt();
  
  static void ComputeTimeDiff(double *diff, 
			      const struct timeval &t1,
			      const struct timeval &t2);

private:

  static struct timeval appStart;
  static struct timeval appEnd;
  static struct timeval rollForwardStart;
  static struct timeval rollForwardEnd; 
  static int timeNow;
  static Int_List req_List;
};

#endif
