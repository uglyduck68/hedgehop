// FlushPolicy.H -- 
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
// $Log: FlushPolicy.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:13  ravshank
// Start of Spring 2001
//
// Revision 1.2  2000/06/27 13:22:38  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.1.1.1  2000/03/06 20:00:15  phoebe
// Sriram's original code with no modifications
//
// $Id: FlushPolicy.H,v 1.1.1.1 2001/02/12 00:00:13 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Wed Jun  9 12:33:56 1999
// Last Modified By: Sriram Rao
// Last Modified On: Wed Jun  9 17:47:34 1999
// Update Count    : 13
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_FLUSH_POLICY_H)
#define _FLUSH_POLICY_H

#include "FlushScheduler.H"

class FlushPolicy {
public:
  enum FlushPolicyType {EGIDA_INDEP_FLUSH, EGIDA_COORD_FLUSH};

  FlushPolicy() {
    this->flushScheduler = NULL;
  };

  ~FlushPolicy() {
    delete this->flushScheduler;
  };

  FlushPolicy(FlushScheduler::FlushSchedulerType schedType, int flushFreq);

  void ScheduleFlush(void);
  void SetFlushFreq(int flushFreq);
  virtual int NeedToFlush(void) = 0;
  virtual bool ProcessMsg(int source, const char *msg, int msgSize) { 
    return false;
  };
  void SetFlushPolicyMsgTag(int tag) {
    this->flushMsgTag = tag;
  };

protected:
  FlushScheduler *flushScheduler;
  int flushMsgTag;
};

class IndepFlushPolicy : public FlushPolicy {
public:
  IndepFlushPolicy() : FlushPolicy() { };
  ~IndepFlushPolicy() { };
  IndepFlushPolicy(FlushScheduler::FlushSchedulerType schedType, 
		   int freq) : FlushPolicy(schedType, freq) { };
  int NeedToFlush(void);
};

class CoordFlushPolicy : public FlushPolicy {
public:
  CoordFlushPolicy() : FlushPolicy() { 
    this->isFlushing = false;
  };
  ~CoordFlushPolicy() { };
  CoordFlushPolicy(FlushScheduler::FlushSchedulerType schedType, 
		   int freq) : FlushPolicy(schedType, freq) { 
    this->isFlushing = false;
  };
  int NeedToFlush(void);
  bool ProcessMsg(int source, const char *msg, int msgSize);
private:
  int isFlushing;
  bool acksRecd[EGIDA_MAX_PROCS];
  
  void FlushAllChannels(void);
};

#endif
