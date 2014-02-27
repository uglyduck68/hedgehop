// OrphanDetection.cc -- 
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
// $Log: OrphanDetection.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:16  ravshank
// Start of Spring 2001
//
// Revision 1.6  2000/10/12 19:50:58  phoebe
// Optimistic is still not working for more than one failure, but the incarnation number is now working correctly, and on the second failure it hangs in exactly the same spot every time. Also...optimistic is now rolling back a checkpoint file instead of doing the exec-ing that it was doing before. Additionally, during some of the debugging process, checkpoints are now shrinking heap sizes correctly (we thought they were doing it before, but they weren't.)
//
// Revision 1.5  2000/06/26 21:31:17  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.4  2000/06/26 19:09:55  phoebe
// Removed all wrapper methods out of Egida_Internal.cc and renamed calls in code to directly call the Egida::Method that would have been called by the Egida_Method call.
//
// Revision 1.3  2000/06/26 16:57:01  phoebe
// Made all the Egida_Object methods and members static. Also moved GetMyId and GetNumProcs out of Egida_Internal and into Egida_Object.
//
// Revision 1.2  2000/06/23 02:47:45  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.1.1.1  2000/03/06 20:00:22  phoebe
// Sriram's original code with no modifications
//
// $Id: OrphanDetection.cc,v 1.1.1.1 2001/02/12 00:00:16 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Tue May 11 16:38:09 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Aug 16 17:55:49 1999
// Update Count    : 20
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <assert.h>
#include <iostream>
#include <strstream>

#include "Communication.H"
#include "Egida_Object.H"
#include "OrphanDetection.H"
#include "VectorClock.H"

void OrphanDetectionByBroadcastLC::DetectOrphans(void)
{
  int i, myId = Egida::GetMyId();
  int numProcs = Egida::GetNumProcs();
  bool done = false;

  for (i = 0; i < numProcs; i++)
    this->ackRecd[i] = false;
  this->ackRecd[myId] = true;

  this->waitingForAcks = true;

  SendOrphanDetectMsg();

  Timer::SetTimer(15);
  
  return;
  
  while (1) {
    done = true;
    for (i = 0; i < numProcs; i++) 
      if (!this->ackRecd[i]) {
	done = false;
	break;
      }
    if (done) {
      this->waitingForAcks = false;
      //we've heard from everyone
      break;
    }
    Communication::WaitForMsgs();
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Handle the timer interrupt that gets generated when this
// 	process is doing orphan detection.  For the orphan detection
// 	message that was sent out, this process expects an ack from
// 	all of the remaining processes.  If an ack hasn't been
// 	received, then, a timer interrupt is scheduled for 5 seconds
// 	from now.
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
void OrphanDetectionByBroadcastLC::TimerExpired(void)
{
  int numProcs = Egida::GetNumProcs();

  if (this->waitingForAcks) {
    Communication::DrainMsgs();
    this->SendOrphanDetectMsg();
    for (int i = 0; i < numProcs; i++) 
      if (!this->ackRecd[i]) {
	Timer::SetTimer(5);
	break;
      }
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Broadcast an orphan detection message.
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

void OrphanDetectionByBroadcastLC::SendOrphanDetectMsg(void)
{
  VCComponent lc;
  int numProcs = Egida::GetNumProcs();
  std::ostrstream os;

  this->pbVectorClock->GetRecoverableState(&lc);
  os << EGIDA_FAILURE_ANNOUNCEMENT_MSG << ' ';
  os << lc << std::ends;
  for (int i = 0; i < numProcs; i++) {
    if (this->ackRecd[i])
      continue;
    Egida::SendControlMsg(i, EGIDA_ORPHAN_DETECTION_MSG, 
			 os.str(), os.pcount());
  }
  // unfreeze the buffer so that it'll get freed
  os.rdbuf()->freeze(false);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Process messages sent as part of the orphan detection protocol.
// 
// Arguments:
// 	source --- process that sent this message.
//      tag --- should be EGIDA_ORPHAN_DETECTION_MSG
//      msg, msgSize --- obvious
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void OrphanDetectionByBroadcastLC::ProcessMsg(int source, int tag, 
					      const char *msg, int msgSize)
{
  std::istrstream is(msg, msgSize);
  int msgType;
  VCComponent lc;
  std::ostrstream os;

  assert(tag == EGIDA_ORPHAN_DETECTION_MSG);
  is >> msgType;

  // Send an ack
  switch (msgType) {
  case EGIDA_ACK:
    this->ackRecd[source] = true;
    break;
  case EGIDA_FAILURE_ANNOUNCEMENT_MSG:
    os << EGIDA_ACK << std::ends;
    Egida::SendControlMsg(source, EGIDA_ORPHAN_DETECTION_MSG, 
			 os.str(), os.pcount());
    os.rdbuf()->freeze(false);
    is >> lc;
    this->pbVectorClock->ProcessFailureAnnouncement(source, lc);
    if (this->pbVectorClock->IsOrphan(source, lc)) {
      std::cout << Egida::GetMyId() << ": I'm an orphan..." << std::endl;
      Egida::Rollback();
    }
    else {
      //don't need to rollback
      std::cout << Egida::GetMyId() << ": I'm NOT an orphan..." << std::endl;
    }
    break;
  default:
    assert(0);
    _exit(0);
  }
}
