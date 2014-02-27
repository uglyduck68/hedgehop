// EventStore.H -- 
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
// $Log: EventStore.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:13  ravshank
// Start of Spring 2001
//
// Revision 1.9  2000/11/28 17:26:30  phoebe
// Found what is hopefully the last of the memcpy core dumps and fixed it. Was connected with the numSegs variable (it was being set imporperly). Also restructured some of the stats to get a more accurate picture of where time is being spent. In addition, the SentStore is now doing all flushing and garbageCollecting with threads. Need to change the checkpoint to get rid of threads before saving state.
//
// Revision 1.8  2000/11/21 22:27:10  phoebe
// GarbageCollect in the SentStore is now working async. We changed the logic slightly so that all files are cleaned by one process and we clean when we've heard 3 responses (not necessarily all from different processes...this is ok we think.) Also...our favorite core dump on TakeCkpt (the memcpy one) has crept back in the picture. <grrrr>
//
// Revision 1.7  2000/11/15 22:12:25  phoebe
// Sanity check.
//
// Revision 1.6  2000/10/20 19:28:41  phoebe
// SentLog class is now integrated and works so protocols using the sentLog to store information will now restart on flushing.
//
// Revision 1.1.1.1  2000/09/27 19:32:42  jmn
// Initial revision.
//
// Revision 1.5  2000/08/08 20:57:11  phoebe
// Cleaned up code, and now the never checkpointing again after a fail error is fixed.
//
// Revision 1.4  2000/06/27 13:22:36  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.3  2000/06/23 16:35:26  phoebe
// Cleaning out un-needed data members in classes.
//
// Revision 1.2  2000/06/02 05:47:23  phoebe
// Hash and Sign of EventInfo working and it will restart and check fine. I think the modification I made to EventInfo for Reads (it's commented as a change in the code...I used << and >> instead of the commented out code) is preventing restart. Need to make sure I understand what is going on with that later.
//
// Revision 1.1.1.1  2000/03/06 20:00:15  phoebe
// Sriram's original code with no modifications
//
// $Id: EventStore.H,v 1.1.1.1 2001/02/12 00:00:13 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu May  6 23:22:32 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu Aug 26 10:25:23 1999
// Update Count    : 69
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Modules for storing event information.  It is very similar to DetStore.H

#if defined(__cplusplus) && !defined(_EVENT_STORE_H)
#define _EVENT_STORE_H

#include <fstream>
#include <iostream>

#include "EventInfo.H"
#include "Globals.H"
#include "LogMeta.H"

class EventStore {
public:
  enum EventStoreType {EGIDA_NULL_STORE, EGIDA_VOLATILE_STORE,
		       EGIDA_STABLE_STORE};
  EventStore() { 
    this->id = -1;
    this->numProcs = 0;
    this->LogStableCallback = NULL;
  };

  ~EventStore() { };

  EventStore(int self, int numP);

  virtual void Write(EventInfo *eInfo) = 0;
  virtual int WriteEvInfoList(int source, EventInfo_List &el) = 0;
  virtual void TryRetrieve(int source, int sourceEventId, 
			   int otherProc, EventInfo **eInfo) = 0;
  virtual void Flush(void) = 0;
  virtual void FlushClean(void) { };
  virtual void AsyncFlush(void) = 0;
  virtual void CkptDone(void) = 0;
  virtual void SetLogFileName(const char *baseName) = 0;
  virtual void SetLogStableCallback(void (*stableCallback)(int, int,
							   int, int)) = 0;

  // gc means discard event info e, created by process source such
  // that e.sourceEventId < eventId
  virtual void GarbageCollect(int source, int sourceEventId) = 0;
  virtual void SetGarbageCollectSsn(int source, int sourceEventId) { };
  // gc means discard event info e, created by process source and
  // involving other process otherProc such that e.sourceEventId < eventId
  virtual void GarbageCollect(int source, int sourceEventId, int
			      otherProc) = 0;
  // purge means discard event info e, created by process source such
  // that e.sourceEventId >= eventId  
  virtual void Purge(int source, int eventId) = 0;

  // This is for recovery.
  // Read the data created by source starting from startEventId.
  virtual void Read(int source, int startEventId, int *lastEventIds) =  0;
  // Retrieve eInfo that was created by source such that
  // eInfo.sourceEventId = sourceEventId
  virtual void Read(int source, int sourceEventId, 
		    int otherProc, EventInfo **eInfo) =  0;
  // Read the data logged on behalf of otherProc.  The data was
  // generated by source. This method retrieves the data created by 
  // source from startEventId and return the resut in retrieve_List
  virtual void Read(int otherProc, int source, int startEventId,
		    EventInfo_List *retrieve_List) = 0;
  // Called from volatile store when data has to be read back.  Need
  // to define this here because volatile store's stableStore may be
  // NULL and the compiler complains about Read() getting masked.
  virtual void Read(int source, int startEventId,
		    int *lastEventIds, EventInfo_List *retrieve_List) = 0;
  // Remove any pointers to eInfo from the event store
  virtual void RemovePtr(EventInfo *eInfo) = 0;
  // Re-open any logs on disk when the process is re-started...
  virtual void RestartingFromCkpt(void) = 0;
  virtual void ReplayDone(void) = 0;
  virtual bool IsGarbageCollecting(void) { return false; };
   // Process log-specific control messages
  virtual void ProcessMsg(int source, int tag, const char *msg, int msgSize) = 0;
  virtual EventInfo_ListIterator GetFlushEnd(int proc) { EventInfo_ListIterator crap; return crap; };
  virtual void SetFlushEnd(int proc, EventInfo_ListIterator eInfo) { };
  EventInfo* flushEventInfo[EGIDA_MAX_PROCS];
  int GetSsnInFileHigh(int) { return 0; };

protected:
  int id;
  int numProcs;
  void (*LogStableCallback)(int, int, int, int);
};

class NullEventStore : public EventStore {
private:
  EventInfo_ListIterator flushEnd[EGIDA_MAX_PROCS];
public:
  NullEventStore():
    EventStore() { };

  NullEventStore(int self, int numP):
    EventStore(self, numP) { };

  void Write(EventInfo *eInfo);
  void TryRetrieve(int source, int sourceEventId, 
		   int otherProc, EventInfo **eInfo);
  void Flush(void) { };
  void AsyncFlush(void) { };
  void CkptDone(void) { };

  void GarbageCollect(int source, int sourceEventId) { };
  void GarbageCollect(int source, int sourceEventId, int otherProc) { };
  void Purge(int source, int eventId) { };

  void SetLogFileName(const char *baseName) { };
  void SetLogStableCallback(void (*stableCallback)(int, int, 
						   int, int)) { };
  // This is for recovery
  void Read(int source, int startEventId, int *lastEventIds);
  // Retrieve eInfo that was created by source such that
  // eInfo.sourceEventId = sourceEventId
  void Read(int source, int sourceEventId, 
	    int otherProc, EventInfo **eInfo);
  // Read the data logged on behalf of otherProc.  The data was
  // generated by source.  In this method, retrieve the data crated by 
  // source from startEventId and return the resut in retrieve_List
  void Read(int otherProc, int source, int startEventId,
	    EventInfo_List *retrieve_List);
  void Read(int source, int startEventId,
	    int *lastEventIds, EventInfo_List *retrieve_List);
  // Remove any pointers to eInfo from the event store
  void RemovePtr(EventInfo *eInfo);
  // Re-open any logs on disk when the process is re-started...
  void RestartingFromCkpt(void) { };
  void ReplayDone(void) { };

   // Ignore control messages
  void ProcessMsg(int source, int tag, const char *msg, int msgSize) { };

  int WriteEvInfoList(int source, EventInfo_List &el);
  EventInfo* flushEventInfo[EGIDA_MAX_PROCS];
};

#endif
