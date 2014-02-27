// DetLog.H -- 
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
// $Log: DetLog.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:12  ravshank
// Start of Spring 2001
//
// Revision 1.3  2000/06/27 13:22:29  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.2  2000/06/23 16:35:22  phoebe
// Cleaning out un-needed data members in classes.
//
// Revision 1.1.1.1  2000/03/06 20:00:13  phoebe
// Sriram's original code with no modifications
//
// $Id: DetLog.H,v 1.1.1.1 2001/02/12 00:00:12 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu May  6 13:33:28 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Jul  5 10:54:06 1999
// Update Count    : 42
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Module for logging determinants

#if defined(__cplusplus) && !defined(_DET_LOG_H)
#define _DET_LOG_H

#include <assert.h>
#include <iostream>
#include <strstream>

#include "Determinant.H"
#include "DetStore.H"
#include "Globals.H"
#include "FlushPolicy.H"
#include "FlushScheduler.H"

class DetLog {
public:
  DetLog() {
    this->detStore = NULL;
    this->flushPolicy = NULL;
  };
  ~DetLog() {
    delete this->detStore;
    delete this->flushPolicy;
  };
  // the type of detStore is either Null, Volatile, or Stable
  // the type of stableDetStore is meaningful only if detStore is Stable
  DetLog(int self, int numP, 
	 DetStore::DetStoreType detStoreType,
	 DetStore::DetStoreType stableDetStoreType,
	 FlushPolicy::FlushPolicyType flushPolicyType,
	 int flushPolicyMsgTag,
	 int flushFreq, FlushScheduler::FlushSchedulerType schedType);
  void Log(Determinant *d);
  void CkptDone(void);
  void SetLogFileName(const char *baseName);
  void SetFlushFreq(int freq);
  void TimerExpired(void);
  bool NeedToFlush(void);
  void Flush(void);
  void FlushClean(void) { detStore->FlushClean(); };
  
  // gc means discard dets d such that d.d_esn < detId
  void GarbageCollect(int procId, int detId);
  // purge means discard dets d such that d.d_esn >= detId
  void Purge(int procId, int detId);

  // This is called when replay has finished 
  void ReplayDone(void);

  // These are needed for recovery of this process
  void Retrieve(int self, int eventId, Determinant **matchingDet);
  void Retrieve(int self, int retrieveStartEventId, int *lastDetId);

  // retrieve determinant d such that d.dest = self and 
  // d.d_esn >= eventId, where d is the closest determinant to eventId
  bool GetNextDet(int self, int eventId, Determinant **matchingDet);

  // This is needed for helping the recovery of a failed process
  void Retrieve(int recoveringProc, int retrieveStartEventId, 
		char **dets, int *detSize);

  // This sets the callback that has to be invoked whenever the
  // contents of the detStore are written out to a backing stable store.
  void SetLogStableCallback(void (*stableCallback)(int));
  
  // Need to re-open the file pointers maintained by the log files.
  void RestartingFromCkpt(void);

  // This is for causal logging protocols.
  void Log(int source, const char *detBuf, int detBufSize, int *detIds);
  // Here knownDetIds[k] = j means that dest knows about all
  // determinants of process upto id j.
  void RetrieveNonstable(int dest, const int *knownDetId, 
			 std::ostrstream &os);
  void RetrieveDetIds(const char *detBuf, int detBufSize, int *detId);
  void MarkStable(int *detId);
  void UpdateLoggedAt(int dest, const int *detId);
  // need this interface during recovery to claim that the entire log
  // is stable
  void MarkLogStable(void);

  void ProcessMsg(int source, int tag, const char *msg, int msgSize);
private:
  DetStore *detStore;
  FlushPolicy *flushPolicy;
};

#endif
