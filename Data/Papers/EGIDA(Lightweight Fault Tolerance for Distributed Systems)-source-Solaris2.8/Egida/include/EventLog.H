// EventLog.H -- 
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
// $Log: EventLog.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:15  ravshank
// Start of Spring 2001
//
// Revision 1.4  2000/10/20 19:28:40  phoebe
// SentLog class is now integrated and works so protocols using the sentLog to store information will now restart on flushing.
//
// Revision 1.3  2000/06/27 13:22:35  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.2  2000/06/23 16:35:25  phoebe
// Cleaning out un-needed data members in classes.
//
// Revision 1.1.1.1  2000/03/06 20:00:15  phoebe
// Sriram's original code with no modifications
//
// $Id: EventLog.H,v 1.1.1.1 2001/02/12 00:00:15 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu May  6 22:57:31 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Jul 12 15:24:50 1999
// Update Count    : 37
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Module for logging event data.  In my case, sent/delivered messages.

#if defined(__cplusplus) && !defined(_EVENT_LOG_H)
#define _EVENT_LOG_H

#include <assert.h>
#include <iostream>
#include "EventInfo.H"
#include "EventStore.H"
#include "Globals.H"
#include "FlushPolicy.H"
#include "FlushScheduler.H"

class EventLog {
public:
  EventLog() {
    this->eventStore = NULL;
    this->flushPolicy = NULL;
  };

  ~EventLog() {
    delete this->eventStore;
    delete this->flushPolicy;
  };

  // the type of eventStore is either Null, Volatile, or Stable
  // the type of stableEventStore is meaningful only if eventStore is Stable
  EventLog(int self, int numP, 
	   EventStore::EventStoreType eventStoreType,
	   EventStore::EventStoreType stableEventStoreType,
	   FlushPolicy::FlushPolicyType flushPolicyType,
	   int flushPolicyMsgTag,
	   int flushFreq, FlushScheduler::FlushSchedulerType schedType);

  void Log(EventInfo *eInfo);
  void TryRetrieve(int source, int sourceEventId, 
		   int otherProc, EventInfo **eInfo);
  void CkptDone(void);
  void SetFlushFreq(int freq);

  // gc means discard event info e, created by process source such
  // that e.sourceEventId < eventId
  void GarbageCollect(int source, int eventId);
  // gc means discard event info e, created by process source and
  // involving other process otherProc such that e.sourceEventId < eventId
  void GarbageCollect(int source, int eventId, int otherProc);
  // purge means discard event info e, created by process source such
  // that e.sourceEventId >= eventId
  void Purge(int source, int eventId);

  void SetLogFileName(const char *baseName);
  void SetLogStableCallback(void (*stableCallback)(int, int, int, int));

  void TimerExpired(void);
  bool NeedToFlush(void);
  void Flush(void);
  void FlushClean(void) { eventStore->FlushClean(); };

  // For recovery of this process
  void Retrieve(int self, int startEventId, int *eventIds);
  void Retrieve(int self, int eventId, int otherProc,
		EventInfo **eInfo);
  // For helping the recovery of recoveringProc
  void Retrieve(int self, int eventId, int recoveringProc,
		EventInfo_List *eInfo_List);

  void RemovePtr(EventInfo *eInfo);
  // Need to re-open the file pointers maintained by the log files.
  void RestartingFromCkpt(void);
  void ReplayDone(void);
  
  void ProcessMsg(int source, int tag, const char *msg, int msgSize);

private:
  EventStore *eventStore;
  FlushPolicy *flushPolicy;
};

#endif
