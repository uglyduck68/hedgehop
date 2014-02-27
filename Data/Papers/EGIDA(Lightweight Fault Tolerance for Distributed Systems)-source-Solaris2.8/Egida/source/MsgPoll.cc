// MsgPoll.cc -- 
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
// $Log: MsgPoll.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:16  ravshank
// Start of Spring 2001
//
// Revision 1.3  2000/09/27 22:03:09  phoebe
// In CkptImpl changed the growing of the heap from a strict monotonically increasing function (using the check that we only grow if size is less than what is needed) to one that can shrink. The reason we can do this is sbrk will take as an argument a negative value, where as malloc cannot.
//
// Revision 1.2  2000/06/27 20:15:51  phoebe
// Cleaned up Makefiles. Made DebugTrace into a proper class. Fixed the communication tracking part of Stats.cc.
//
// Revision 1.1  2000/06/27 13:23:12  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.5  2000/06/23 16:35:32  phoebe
// Cleaning out un-needed data members in classes.
//
// Revision 1.4  2000/06/23 02:47:37  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.3  2000/06/23 00:01:05  phoebe
// Another name change...HandleMsgPoll and NullHandleMsgPoll are now MsgPoll and NullMsgPoll.
//
// Revision 1.2  2000/06/22 20:59:02  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.1.1.1  2000/03/06 20:00:19  phoebe
// Sriram's original code with no modifications
//
// $Id: MsgPoll.cc,v 1.1.1.1 2001/02/12 00:00:16 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu May 27 13:50:54 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu Aug 26 10:03:36 1999
// Update Count    : 19
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include "Globals.H"
#include "MsgPoll.H"
#include "Stats.H"
#include "Timer.H"

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Constructor for handling message poll events
// 
// Arguments:
// 	self, numProcs --- the usual meanings
//      detStoreType --- should be one of NULL_STORE or STABLE_STORE
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

MsgPoll::MsgPoll(int self, int numProcs, 
			     DetStore::DetStoreType detStoreType)
{
  this->id = self;
  if ((detStoreType == DetStore::EGIDA_NULL_STORE) ||
      (detStoreType == DetStore::EGIDA_STABLE_STORE)) {
    this->detLog = new DetLog(self, numProcs, detStoreType,
			      detStoreType,
			      FlushPolicy::EGIDA_INDEP_FLUSH,
			      -1, /* Tag here doesn't matter */
			      -1, FlushScheduler::EGIDA_PERIODIC_FLUSH);

  }
  else
    assert(0);
  
  char msgPollFilename[] = "msgPoll";
  this->detLog->SetLogFileName(msgPollFilename);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Create a determinant and record the result of a poll event.
// 
// Arguments:
// 	seqNum, result --- Sequence number and result of a poll event
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void MsgPoll::RecordResult(int seqNum, int result)
{
  Determinant *d;
  struct timeval startTime, endTime;
  double timeSpent;

  if(COLLECTING_STATS) {
    gettimeofday(&startTime, NULL);
  }

  d = new Determinant(this->id, seqNum, this->id, seqNum, 
		      (char *) &result, sizeof(int));
  this->detLog->Log(d);

  if(COLLECTING_STATS) {
    gettimeofday(&endTime, NULL);
    Timer::ComputeTimeDiff(&timeSpent, startTime, endTime);
    Stats::Update(EGIDA_POLL_RECORD_STAT, 0, timeSpent);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Replay the result of a poll event.
// 
// Arguments:
// 	seqNum --- the poll for which a result has to be replayed
//      result --- output parameter
// 
// Results:
//      result --- result of a poll event if a matching determinant
//                  exists.
// 	Returns true on success; false on failure.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

bool MsgPoll::ReplayResult(int seqNum, int *result)
{
  Determinant *d;
  struct timeval startTime, endTime;
  double timeSpent;

  if(COLLECTING_STATS) {
    gettimeofday(&startTime, NULL);
  }

  *result = 0;

  this->detLog->GetNextDet(this->id, seqNum, &d);
  if ((d != NULL) && (d->d_esn == seqNum)) {
    d->GetEventSpecific((char *) result);

    if(COLLECTING_STATS) {
      gettimeofday(&endTime, NULL);
      Timer::ComputeTimeDiff(&timeSpent, startTime, endTime);
      Stats::Update(EGIDA_RECOVERY_POLL_REPLAY_STAT, 0, timeSpent);
    }
    return true;
  }
  else
    return false;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve determinants that have to be replayed
// 
// Arguments:
// 	startSeqNum --- sequence # from which to start replay of determinants
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void MsgPoll::PrepareForReplay(int startSeqNum)
{
  int lastSeqNum;

  this->detLog->RestartingFromCkpt();
  this->detLog->Retrieve(this->id, startSeqNum, &lastSeqNum);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Execute actions at the end of replay.  In the case of this
// 	module, this involves re-opening the file maintained by the detLog.
// 
// Arguments:
// 	lastSeqNum --- last event seq # that was replayed.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void MsgPoll::ReplayDone(int lastSeqNum)
{
  this->detLog->Purge(this->id, lastSeqNum);
  this->detLog->ReplayDone();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Execute actions after a checkpoint is written out.
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

void MsgPoll::CkptDone()
{
  this->detLog->CkptDone();
}


void MsgPoll::GarbageCollect(int procId, int detId) 
{
  this->detLog->GarbageCollect(procId, detId);
}
