// FlushScheduler.H -- 
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
// $Log: FlushScheduler.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:13  ravshank
// Start of Spring 2001
//
// Revision 1.2  2000/06/27 13:22:39  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.1.1.1  2000/03/06 20:00:15  phoebe
// Sriram's original code with no modifications
//
// $Id: FlushScheduler.H,v 1.1.1.1 2001/02/12 00:00:13 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu Apr 29 23:13:04 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu May 20 23:50:07 1999
// Update Count    : 34
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_FLUSH_SCHEDULER_H)
#define _FLUSH_SCHEDULER_H

#include <assert.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/time.h>

#include "Globals.H"
#include "Timer.H"

class FlushScheduler {
public:
  enum FlushSchedulerType {EGIDA_PERIODIC_FLUSH, EGIDA_RANDOM_FLUSH};

  FlushScheduler() {
    this->frequency = -1;
    this->timeToNextFlush = -1;
    gettimeofday(&this->lastFlushTime, NULL);
  };

  ~FlushScheduler() { };

  FlushScheduler(int freq) {
    this->frequency = freq;
    this->timeToNextFlush = 0;
    gettimeofday(&this->lastFlushTime, NULL);
  };

  virtual void ScheduleFlush(void) = 0;
  virtual void SetFlushFreq(int freq) = 0;
  int NeedToFlush(void);

protected:
  int frequency;
  int timeToNextFlush;
  struct timeval lastFlushTime;
};



class PeriodicFlushScheduler : public FlushScheduler {
public:
  PeriodicFlushScheduler() { };

  PeriodicFlushScheduler(int freq) :
    FlushScheduler(freq) { 
    this->ScheduleFlush();
  };

  void ScheduleFlush(void);
  void SetFlushFreq(int freq);
};



class RandomFlushScheduler : public FlushScheduler {
public:
  RandomFlushScheduler() { };

  RandomFlushScheduler(int freq);

  ~RandomFlushScheduler() {
    this->ifs.close();
  };

  void ScheduleFlush(void);
  void SetFlushFreq(int freq);

private:
  std::ifstream ifs;
};
#endif
