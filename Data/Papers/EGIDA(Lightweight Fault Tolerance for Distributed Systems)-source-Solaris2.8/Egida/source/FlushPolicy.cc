// FlushPolicy.cc -- 
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
// $Log: FlushPolicy.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:15  ravshank
// Start of Spring 2001
//
// Revision 1.5  2000/06/27 13:23:08  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.4  2000/06/26 21:31:12  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.3  2000/06/26 16:56:58  phoebe
// Made all the Egida_Object methods and members static. Also moved GetMyId and GetNumProcs out of Egida_Internal and into Egida_Object.
//
// Revision 1.2  2000/06/23 02:47:40  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.1.1.1  2000/03/06 20:00:21  phoebe
// Sriram's original code with no modifications
//
// $Id: FlushPolicy.cc,v 1.1.1.1 2001/02/12 00:00:15 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Wed Jun  9 12:33:51 1999
// Last Modified By: Sriram Rao
// Last Modified On: Wed Jun  9 18:38:02 1999
// Update Count    : 27
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|
#include <assert.h>
#include <iostream>
#include <strstream>

#include "Communication.H"
#include "Egida_Object.H"
#include "FlushPolicy.H"
#include "Globals.H"

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Constructor for the abstract flush policy class.
// 
// Arguments:
// 	schedType --- type of flush scheduler (PERIODIC/RANDOM)
//      freq --- is an argument passed to the flush scheduler
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

FlushPolicy::FlushPolicy(FlushScheduler::FlushSchedulerType schedType,
			 int flushFreq)
{

  switch(schedType) {
  case FlushScheduler::EGIDA_PERIODIC_FLUSH:
    this->flushScheduler = new PeriodicFlushScheduler(flushFreq);
    break;
  case FlushScheduler::EGIDA_RANDOM_FLUSH:
    this->flushScheduler = new RandomFlushScheduler(flushFreq);
    break;
  default:
    assert(0);
    break;
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Front-end that asks the flush scheduler to schedule a flush.
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
void FlushPolicy::ScheduleFlush()
{
  this->flushScheduler->ScheduleFlush();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Front-end that asks the flush scheduler to change the
// 	freq. with flushes are set.
// 
// Arguments:
// 	freq --- the new scheduling frequency.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void FlushPolicy::SetFlushFreq(int flushFreq)
{
  this->flushScheduler->SetFlushFreq(flushFreq);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Implements a flushing policy in which each process flushes
// 	(the parent object---message log, determinant log, checkpoint)
// 	independent of the other processes in the system.
// 
// Arguments:
// 	NONE
// 
// Results:
// 	Returns 1 if the scheduler thinks it is time to flush;
//              0 otherwise.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
int IndepFlushPolicy::NeedToFlush()
{
  return this->flushScheduler->NeedToFlush();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Implements a co-ordinated flushing policy in which process 0
// 	is the co-ordinator that directs other processes to do a flush
// 	(of the parent object---message log, determinant log, checkpoint)
// 
// Arguments:
// 	NONE
// 
// Results:
//      In process 0:
// 	  Returns 1 if the scheduler thinks it is time to flush; in
// 	            this case, use a snapshot algorithm to flush all
// 	            channels and ask other processes to flush their 
//                  parent object.
//                0 otherwise.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
int CoordFlushPolicy::NeedToFlush()
{
  int myId = Egida::GetMyId();
  int numProcs = Egida::GetNumProcs();

  if ((myId == 0) && (this->flushScheduler->NeedToFlush())) {
    memset(this->acksRecd, false, numProcs * sizeof(bool));
    this->FlushAllChannels();
    std::cout << "Doing a co-ord flush" << std::endl;
    this->isFlushing = false;
    return 1;
  }
  else
    return 0;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Use Chandy/Lamport protocol to flush all channels
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
void CoordFlushPolicy::FlushAllChannels()
{
  int i, myId = Egida::GetMyId();
  bool done = false;
  int numProcs = Egida::GetNumProcs();
  std::ostrstream os;

  this->isFlushing = true;
  this->acksRecd[myId] = true;
  
  os << EGIDA_COORD_FLUSH_REQ << ' ' << std::ends;

  for (i = 0; i < numProcs; i++) {
    if (!this->acksRecd[i])
      Communication::SendMsg(i, this->flushMsgTag, os.str(), os.pcount());
  }
  os.rdbuf()->freeze(false);

  while (!done) {
    Communication::DrainMsgs();
    done = true;
    for (i = 0; i < numProcs; i++) 
      if (this->acksRecd[i] == false) {
	done = false;
	break;
      }
  }
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Process a messages sent as part of co-ordinated flushing.
// 
// Arguments:
// 	source --- process that sent the message
//      msg --- containes one of FLUSH_REQ or a FLUSH_ACK
//      msgSize --- size of the message.
//
// Results:
// 	Returns true if a flush request is received; false otherwise.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
bool CoordFlushPolicy::ProcessMsg(int source, const char *msg, int msgSize)
{
  std::istrstream is(msg, msgSize);
  std::ostrstream os;
  int msgType;
  int numProcs = Egida::GetNumProcs();
  bool needToFlush = false;

  is >> msgType;

  switch (msgType) {
  case EGIDA_COORD_FLUSH_REQ:
    if (!this->isFlushing) {
      memset(this->acksRecd, false, numProcs * sizeof(bool));
      this->acksRecd[source] = true;
      os << EGIDA_COORD_FLUSH_ACK << ' ' << std::ends;
      Communication::SendMsg(source, this->flushMsgTag, os.str(),
			     os.pcount());
      os.rdbuf()->freeze(false);
      this->FlushAllChannels();
      needToFlush = true;
      this->isFlushing = false;
    }
    else
      this->acksRecd[source] = true;
    break;
  case EGIDA_COORD_FLUSH_ACK:
    this->acksRecd[source] = true;
    break;
  default:
    assert(0);
    break;
  }
  return needToFlush;
}
