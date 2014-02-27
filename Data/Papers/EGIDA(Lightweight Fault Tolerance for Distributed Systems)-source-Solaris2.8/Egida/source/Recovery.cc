// Recovery.cc -- 
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
// $Log: Recovery.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:16  ravshank
// Start of Spring 2001
//
// Revision 1.11  2000/11/21 22:27:19  phoebe
// GarbageCollect in the SentStore is now working async. We changed the logic slightly so that all files are cleaned by one process and we clean when we've heard 3 responses (not necessarily all from different processes...this is ok we think.) Also...our favorite core dump on TakeCkpt (the memcpy one) has crept back in the picture. <grrrr>
//
// Revision 1.10  2000/11/15 22:12:31  phoebe
// Sanity check.
//
// Revision 1.9  2000/11/01 16:35:31  phoebe
// Working on getting security to work again with the redesigned system. Message encryption, either full or only egida messages, is working now.
//
// Revision 1.8  2000/10/12 19:51:00  phoebe
// Optimistic is still not working for more than one failure, but the incarnation number is now working correctly, and on the second failure it hangs in exactly the same spot every time. Also...optimistic is now rolling back a checkpoint file instead of doing the exec-ing that it was doing before. Additionally, during some of the debugging process, checkpoints are now shrinking heap sizes correctly (we thought they were doing it before, but they weren't.)
//
// Revision 1.7  2000/10/03 22:56:26  phoebe
// Optimistic will now reliably restart once. Still fails multiple sequential failures.
//
// Revision 1.6  2000/09/27 22:03:12  phoebe
// In CkptImpl changed the growing of the heap from a strict monotonically increasing function (using the check that we only grow if size is less than what is needed) to one that can shrink. The reason we can do this is sbrk will take as an argument a negative value, where as malloc cannot.
//
// Revision 1.5  2000/06/27 13:23:13  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.4  2000/06/26 21:31:18  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.3  2000/06/23 02:47:47  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.2  2000/06/22 20:59:09  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.1.1.1  2000/03/06 20:00:22  phoebe
// Sriram's original code with no modifications
//
// $Id: Recovery.cc,v 1.1.1.1 2001/02/12 00:00:16 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun May  9 15:39:25 1999
// Last Modified By: Sriram Rao
// Last Modified On: Wed Aug 18 13:52:03 1999
// Update Count    : 44
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <assert.h>
#include <iostream>
#include <strstream>

#include "Communication.H"
#include "Egida_Object.H"
#include "Recovery.H"
#include "Stats.H"
#include "Timer.H"

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Constructor for the recovery object
// 
// Arguments:
// 	self --- id of this process
//      numF --- # of concurrent failures to be tolerated
//      The remaining arguments have obvious meanings.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

Recovery::Recovery(int self, int numF, DetLog *dl, EventLog *sl, 
		   EventLog *delL, PbLog *lp, 
		   OrphanDetection *od,
		   CollectRecInfo::CollectRecInfoType collectRecInfoType)
{
  this->id = self;
  this->detLog = dl;
  this->sentLog = sl;
  this->deliveredLog = delL;
  this->pbLog = lp;
  this->orphanDetection = od;
  if (collectRecInfoType == CollectRecInfo::EGIDA_DISTRIBUTED_COLLECT_REC_INFO)
    this->collectRecInfo = new CollectRecInfo(dl, delL, numF);
  else if (collectRecInfoType == CollectRecInfo::EGIDA_CENTRALIZED_COLLECT_REC_INFO)
    this->collectRecInfo = new CentralizedCollectRecInfo(dl, delL,
							 numF);
  else {
    // whoa...
    assert(0);
    _exit(0);
  }
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Handle messages directed to the recovery object---these have a 
// 	tag of EGIDA_RECOVERY_MSG
// 
// Arguments:
// 	source --- process that sent the message.
//      tag --- must be EGIDA_RECOVERY_MSG
//      msg, msgSize --- obvious...
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void Recovery::ProcessMsg(int source, int tag, const char *msg, 
			  int msgSize)
{
  std::istrstream is(msg, msgSize);
  int msgType;
  int actualSource, actualDest;
  int lastDet, lastSentMsg;

  assert(tag == EGIDA_RECOVERY_MSG);
  is >> msgType;
  is >> actualSource;
  is >> actualDest;

  switch (msgType) {
  case EGIDA_HELP_RECOVERY:
    // Need to inform collect object of a failure during the collect
    // phase.
    is >> lastDet;
    is >> lastSentMsg;
    assert(actualDest == this->id);
    this->HelpRecovery(source, actualSource, lastDet, lastSentMsg);
    break;
  case EGIDA_COLLECT_RECOVERY_MSG:
    this->collectRecInfo->ProcessMsg(source, actualSource, actualDest, 
				     msg, msgSize);
    break;
  default:
    std::cout << "Unknown recovery message type: " << msgType << std::endl;
    assert(0);
  }
  
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Method for executing the actions before roll-forward can be
// 	initiated by the recovering process.
// 
// Arguments:
// 	esn --- event seq. # corresponding to the event from which
// 	        recovery will be initiated.
//      rollback --- a boolean if recovery is due to a rollback.  This 
//              argument is handed to the logging protocol.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Recovery::DoRecovery(int esn, bool rollback)
{
  struct timeval startTime, endTime;
  double timeSpent;
  // the order here is critical --- the pre-replay actions must be
  // done before a process can do orphan detection.  This is because
  // the logging protocol may have logged information on stable
  // storage (e.g., incarnation #) which has to be retrieved before
  // computing the recoverable state/detecting orphans.

  if(COLLECTING_STATS) {
    gettimeofday(&startTime, NULL);
  }

  this->collectRecInfo->Retrieve(esn);

  if(COLLECTING_STATS) {
    gettimeofday(&endTime, NULL);
    Timer::ComputeTimeDiff(&timeSpent, startTime, endTime);
    Stats::Update(EGIDA_RECOVERY_LOG_ACQUIRE_STAT, 0, timeSpent);
  }
 
  this->pbLog->PreReplayActions(esn, rollback);

  if(this->pbLog->NeedToDetectOrphans()) {
    this->orphanDetection->DetectOrphans();
    std::cout << "Orphan Detection message sent." << std::endl;
  }

}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Send determinants and data needed by the recovering process.
// 
// Arguments:
// 	msg --- buffer containing the "help" request
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void Recovery::HelpRecovery(int dest, int recoveringProc, 
			    int lastDet, int lastSentMsg)
{
  int detSize = 0;
  char *dets;
  EventInfo_List msgList;
  EventInfo_ListIterator e;
  EventInfo *m;
  std::ostrstream os;

  this->detLog->Retrieve(recoveringProc, lastDet, &dets, &detSize);
  this->sentLog->Retrieve(this->id, lastSentMsg, recoveringProc, &msgList);

  // send the stuff...
  os << EGIDA_COLLECT_RECOVERY_MSG << ' ' << this->id << ' ' <<
    recoveringProc << ' ' << std::ends;
  Egida::SendControlMsg(dest, EGIDA_RECOVERY_MSG,
		       os.str(), os.pcount());
  
  Egida::SendControlMsg(dest, EGIDA_RECOVERY_RESPONSE_BEGIN,
		       dets, detSize);

  for (e = msgList.begin(); e != msgList.end(); ++e) {
    m = *e;
    Egida::SendControlMsg(dest, EGIDA_RECOVERY_MSG,
			 os.str(), os.pcount());

    Egida::SendControlMsg(dest, EGIDA_RECOVERY_REPLAY_MSG,
			 m->pb, m->pbSize);
    Egida::SendControlMsg(dest, EGIDA_RECOVERY_REPLAY_MSG,
			 m->info, m->infoSize);
    // No deletion since we don't do a deep copy anymore
    //    delete m;
  }
  Egida::SendControlMsg(dest, EGIDA_RECOVERY_MSG,
		       os.str(), os.pcount());
  Egida::SendControlMsg(dest, EGIDA_RECOVERY_RESPONSE_END, NULL, 0);

  // unfreeze the buffer so that it'll get freed
  os.rdbuf()->freeze(false);

  msgList.clear();
  delete [] dets;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Handle the timer interrupts that get generated.  This module
// 	just informs OrphanDetection, CollectRecInfo module's that the 
// 	timer has gone off.
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
void Recovery::TimerExpired()
{
  this->collectRecInfo->TimerExpired();
  this->orphanDetection->TimerExpired();
}

