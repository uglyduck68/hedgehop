// DetLog.cc -- 
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
// $Log: DetLog.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:15  ravshank
// Start of Spring 2001
//
// Revision 1.3  2000/06/23 16:35:29  phoebe
// Cleaning out un-needed data members in classes.
//
// Revision 1.2  2000/06/23 02:47:33  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.1.1.1  2000/03/06 20:00:17  phoebe
// Sriram's original code with no modifications
//
// $Id: DetLog.cc,v 1.1.1.1 2001/02/12 00:00:15 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu May  6 14:11:04 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Jul  5 10:55:27 1999
// Update Count    : 47
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <assert.h>
#include "DetLog.H"

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Constructor for a determinant log object.  Same old
// 	story---code doesn't compile if this method is in the header.
// 
// Arguments:
// 	self, numP --- usual args: id of this process and # of
//  	    processes in the system
//      detStoreType --- one of Null, Volatile Store, Stable Store
//      stableDetStoreType --- meaningful only if is Volatile Store
//      flushPolicy --- policy for flushing: INDEPENDENT or
//          COORDINATED
//      flushPolicyMsgTag --- tag that the flush policy object should
//          use for sending messages.
//      flushFreq --- freq. of asking event store to flush its
//          contents to stable storage.  If this is -1, data is never
//          flushed.
//      schedType --- PERIODIC or RANDOM
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

DetLog::DetLog(int self, int numP, 
	       DetStore::DetStoreType detStoreType,
	       DetStore::DetStoreType stableDetStoreType,
	       FlushPolicy::FlushPolicyType flushPolicyType,
	       int flushPolicyMsgTag,
	       int flushFreq, FlushScheduler::FlushSchedulerType schedType)
{

  switch(detStoreType) {
  case DetStore::EGIDA_NULL_STORE:
    this->detStore = new NullDetStore(self, numP);
    break;
  case DetStore::EGIDA_VOLATILE_STORE:
    this->detStore = new VolatileDetStore(self, numP, stableDetStoreType);
    break;
  case DetStore::EGIDA_STABLE_STORE:
    this->detStore = new StableDetStore(self, numP);
    break;
  default:
    assert(0);
    break;
  }

  switch(flushPolicyType) {
  case FlushPolicy::EGIDA_INDEP_FLUSH:
    this->flushPolicy = new IndepFlushPolicy(schedType, flushFreq);
    break;
  case FlushPolicy::EGIDA_COORD_FLUSH:
    this->flushPolicy = new CoordFlushPolicy(schedType, flushFreq);
    break;
  default:
    assert(0);
    break;
  }
  this->flushPolicy->SetFlushPolicyMsgTag(flushPolicyMsgTag);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Log a determinant on to storage.
// 
// Arguments:
// 	d --- pointer to a determinant structure.
//           The caller of this method SHOULD NOT keep a reference to
//           d after this method call.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void DetLog::Log(Determinant *d)
{
  this->detStore->Write(d);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Log a set of determinants in the buffer on to storage.
// 
// Arguments:
//      source --- process that sent detBuf.
//      detIds --- output parameter.
// 	detBuf --- pointer to a buffer of determinants.
//        Note that unlike Log(d), the caller of this method is
//        responsible for free'ing the passed input buffer.
//      detBufSize --- size of detBuf
// 
// Results:
// 	detIds --- detId[i] is the index of the
//        highest determinant of process i that was logged.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void DetLog::Log(int source, const char *detBuf, int detBufSize, int *detIds)
{
  this->detStore->Write(source, detBuf, detBufSize, detIds);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Flush the contents of the determinant log to stable storage.
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
void DetLog::Flush()
{
  this->detStore->Flush();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve the next determinant after eventId.  This method is
// 	used by optimistic protocols for discarding
// 	determinants/messages that will never be replayed.
// 
// Arguments:
// 	self: id of this process
//      eventId: Retreive determinant d such that d.dest = self and
//        d.d_esn >= eventId and d is the first such determinant.
//      matchingDet: output parameter
// 
// Results:
// 	matchingDet: The matching determinant is returned in
// 	matchingDet.  The caller of this method SHOULD NOT free the
// 	storage allocated for matchingDet.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

bool DetLog::GetNextDet(int self, int eventId, Determinant **matchingDet)
{
  return this->detStore->GetNextDet(self, eventId, matchingDet);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve non-stable determinants
// 
// Arguments:
// 	dest --- process to which non-stable determinants are to be
// 	         sent to.
//      knownDetId --- knownDet[i] = j, means that dest knows about
//                determinants d created by process i such that
//                d.d_esn <= j. 
//      os --- an output stream buffer into which the determinants are 
//             going to be written to.
// 
// Results:
// 	os contains all the non-stable determinants.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void DetLog::RetrieveNonstable(int dest, const int *knownDetId, 
			       std::ostrstream &os)
{
  this->detStore->RetrieveNonstable(dest, knownDetId, os);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve determinant id's from a previously created detBuf.
// 	This method is needed for causal logging protocols.
// 
// Arguments:
// 	detBuf --- a buffer of determinants that was created in a
// 	           previous call to RetrieveNonstable
//      detBufSize --- size of the detBuf
//      detId --- output parameter ---> assume that detId[] of size
//                 EGIDA_MAX_PROCS. 
// 
// Results:
// 	detId[j] = k --- is the sequence # of the highest determinant d
// 	created by process j (d.dest = j) that is present in detBuf.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void DetLog::RetrieveDetIds(const char *detBuf, int detBufSize, int *detId)
{
  this->detStore->RetrieveDetIds(detBuf, detBufSize, detId);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Mark a set of determinants as stable.
// 
// Arguments:
// 	detId --- detId[j] = k means that all determinants d such that 
// 	          d.dest = j and d.d_esn <= k are now stable.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void DetLog::MarkStable(int *detId)
{
  this->detStore->MarkStable(detId);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Mark the entire detStore as stable.
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

void DetLog::MarkLogStable(void)
{
  this->detStore->MarkLogStable();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
//      Add dest to the loggedAt set of determinants in detId.
// 
// Arguments:
//      detId --- id of the determinants that have to be updated
// 	dest --- process that has to be addeed to the logged at set of 
// 	         each determinant d such that d.d_esn <= detId[d.dest]
//
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void DetLog::UpdateLoggedAt(int dest, const int *detId)
{
  this->detStore->UpdateLoggedAt(dest, detId);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Garbage collect determinants from the detStore.
// 
// Arguments:
// 	procId, detId: Discard dets with d->dest == procId such that
// 	               d->d_esn < detId.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void DetLog::GarbageCollect(int procId, int detId)
{
  this->detStore->GarbageCollect(procId, detId);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Throw away determinants from the detStore.
// 
// Arguments:
// 	procId, detId: Discard dets with d->dest == procId such that
// 	               d->d_esn >= detId.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void DetLog::Purge(int procId, int detId)
{
  this->detStore->Purge(procId, detId);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	At the end of replay phase of recovery, this method is
// 	called.  If there are any log files on disk, then, those files 
// 	need to re-opened in write mode.
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

void DetLog::ReplayDone()
{
  this->detStore->ReplayDone();
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Front-end for detStore's ckptDone method.
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

void DetLog::CkptDone()
{
  this->detStore->CkptDone();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Periodically flush the contents of volatile det store to
// 	stable storage.
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
void DetLog::TimerExpired()
{
  if (this->flushPolicy->NeedToFlush()) {
    this->detStore->Flush();
    this->flushPolicy->ScheduleFlush();
  }
}

bool DetLog::NeedToFlush()
{
  if (this->flushPolicy->NeedToFlush()) {
    flushPolicy->ScheduleFlush();
    return true;
  }
  return false;
}

// /////////////////////////////////////////////////////////////////
//
// Purpose:
// 	During recovery, retrieve a determinant for an event whose
// 	result has to be replayed.
// 
// Arguments:
//      self --- id of this process.
// 	eventId --- id of the event for which a determinant is to be
// 	        retrieved. 
//      matchingDet --- output parameter
// 
// Results:
// 	matchingDet --- a pointer to the determinant d created by this 
// 	   process such that d.d_esn = eventId.
//      If such a matchingDet doesn't exist, matchingDet is set to NULL.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void DetLog::Retrieve(int self, int eventId, Determinant **matchingDet)
{
  this->detStore->Read(self, eventId, matchingDet);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve determinants for replay phase of recovery of this
// 	process. 
// 
// Arguments:
//      self --- id of this process
// 	retrieveStartEventId --- retrieve dets d created by this
// 	     process such that d.d_esn >= retrieveStartEventId
//      lastDetId --- output parameter
// 
// Results:
// 	lastDetId --- d_esn of the last determinant that was read
// 	     from storage.  lastDetId is assumed to be an array
// 	     of int's of size EGIDA_MAX_PROCS.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void DetLog::Retrieve(int self, int retrieveStartEventId, int *lastDetId)
{
  this->detStore->Read(self, retrieveStartEventId, lastDetId);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve determinants for helping the recovery of recoveringProc
// 
// Arguments:
//      recoveringProc --- id of the recovering process
// 	retrieveStartEventId --- retrieve dets: (1) d created by the
// 	     recovering process such that d.d_esn >=
// 	     retrieveStartEventId and (2) d such that recoveringProc
// 	     is in d.loggedAt
//      dets, detSize --- output parameter
// 
// Results:
// 	dets --- a buffer containing the determinants for the
// 	    recovering process.  It is the responsibility of the caller to 
// 	    free the buffer by calling delete.
//      detSize --- size of dets buffer.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void DetLog::Retrieve(int recoveringProc, int retrieveStartEventId, 
		      char **dets, int *detSize)
{
  this->detStore->Read(recoveringProc, retrieveStartEventId, dets, detSize);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Set the frequency with which data in volatile log is flushed
// 	to stable storage.
// 
// Arguments:
// 	freq --- flush frequency in seconds.  If it is < 0, then, data 
// 	is never flushed out.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void DetLog::SetFlushFreq(int freq)
{
  this->flushPolicy->SetFlushFreq(freq);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Change the default file name for the log file on a file system
// 
// Arguments:
// 	baseName --- base file name for the log on a file system
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void DetLog::SetLogFileName(const char *baseName)
{
  this->detStore->SetLogFileName(baseName);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Set a callback function that has to be invoked whenever the
// 	log is written out to stable storage.
// 
// Arguments:
// 	stableCallback --- function to callback whenever the contents
// 	of the det log are flushed to stable storage.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void DetLog::SetLogStableCallback(void (*stableCallback)(int))
{
  this->detStore->SetLogStableCallback(stableCallback);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Front-end for calling detStore's RestartingFromCkpt method.
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

void DetLog::RestartingFromCkpt()
{
  this->detStore->RestartingFromCkpt();
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Handle messages sent by the flush policy object.
// 
// Arguments:
// 	source --- process that sent the message
//      tag --- better be DET_LOG_MSG
//      msg --- containes one of FLUSH_REQ or a FLUSH_ACK
//      msgSize --- size of the message.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void DetLog::ProcessMsg(int source, int tag, const char *msg, int msgSize)
{
  if (this->flushPolicy->ProcessMsg(source, msg, msgSize)) 
    this->detStore->Flush();
}
