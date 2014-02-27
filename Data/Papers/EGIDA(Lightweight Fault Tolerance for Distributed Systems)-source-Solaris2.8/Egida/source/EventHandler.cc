// EventHandler.cc -- 
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
// $Log: EventHandler.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:17  ravshank
// Start of Spring 2001
//
// Revision 1.16  2000/11/21 22:27:14  phoebe
// GarbageCollect in the SentStore is now working async. We changed the logic slightly so that all files are cleaned by one process and we clean when we've heard 3 responses (not necessarily all from different processes...this is ok we think.) Also...our favorite core dump on TakeCkpt (the memcpy one) has crept back in the picture. <grrrr>
//
// Revision 1.15  2000/11/10 15:48:52  phoebe
// Checkpoint memory leak is now solved, and so is the memcpy core dump on some checkpoints.
//
// Revision 1.14  2000/06/27 20:15:48  phoebe
// Cleaned up Makefiles. Made DebugTrace into a proper class. Fixed the communication tracking part of Stats.cc.
//
// Revision 1.13  2000/06/27 13:23:05  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.12  2000/06/26 21:31:11  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.11  2000/06/26 19:09:53  phoebe
// Removed all wrapper methods out of Egida_Internal.cc and renamed calls in code to directly call the Egida::Method that would have been called by the Egida_Method call.
//
// Revision 1.10  2000/06/26 16:56:57  phoebe
// Made all the Egida_Object methods and members static. Also moved GetMyId and GetNumProcs out of Egida_Internal and into Egida_Object.
//
// Revision 1.9  2000/06/26 14:56:04  phoebe
// More slight changes. Cleaned up Init.cc by moving path definitions to Egida_Globals.H. There are also some other small changes that I can't remember at the moment.
//
// Revision 1.8  2000/06/23 15:13:52  phoebe
// Changed Egida_GetMyId() to use the egida object id instead of always polling p4. It will still poll p4 when egida is not initialized.
//
// Revision 1.7  2000/06/23 03:04:51  phoebe
// Changed the isInitialized data member in Egida_Object to a true boolean instead of the int that it used to be.
//
// Revision 1.6  2000/06/23 02:47:38  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.5  2000/06/23 00:18:10  phoebe
// Made namespace Egida_FailDetect into proper class called FailDetect.
//
// Revision 1.4  2000/06/22 22:55:20  phoebe
// Changed the malloc call to grow the heap to sbrk which is better for growing the heap. Also, instead of growing just arbitratily, we grow it by the exact amount (this is all in CkptImpl spec. the CkptImpl::RestoreCkptFile method). Also...added another drain msgs call in the EventHandler::Receive function which could save a loop.
//
// Revision 1.3  2000/06/22 22:23:06  phoebe
// Changed the Timer namespace to a proper class. Put all the global timers into Timer class as private data members.
//
// Revision 1.2  2000/06/22 20:59:04  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.1.1.1  2000/03/06 20:00:20  phoebe
// Sriram's original code with no modifications
//
// $Id: EventHandler.cc,v 1.1.1.1 2001/02/12 00:00:17 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun Apr 25 14:42:47 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Aug 16 17:59:39 1999
// Update Count    : 288
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <assert.h>
#include <iostream>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/utsname.h>

#include "Egida_p4.h"

#include "Egida_API.h"
#include "Egida_Object.H"
#include "EventHandler.H"
#include "Stats.H"
#include "Timer.H"

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Event handler for sending messages.
// 
// Arguments:
// 	dest --- id of the process to which message is being sent
//      tag  --- MPI assigned tag to the message
//      dataType --- MPI datatype is passed uninterpreted to p4.
//      msg, msgSize --- obvious meaning.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	 A copy of the message may be logged on storage.
// 
// /////////////////////////////////////////////////////////////////

void EventHandler::Send(int dest, int tag, char *msg, int msgSize, int dataType)
{
  char *pb = NULL;
  int pbSize = 0;
  int sendTag, ssn, self = Egida::GetMyId();
  struct timeval timeStart;

  if (!Egida::IsInitialized()) {
    Communication::SendMsg(dest, tag, msg, msgSize);
    return;
  }

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  // A checkpoint should not occur in the midst of a send.
  Timer::BlockTimerInterrupt();


  Communication::DrainMsgs();

  // All messages sent thru p4 have to be tagged.  Egida control
  // messages are assigned tags from 0 to EGIDA_MAX_TAG.  Need to make sure
  // that application messages have a tag that is > EGIDA_MAX_TAG.
  sendTag = EGIDA_TAG_SEND_APPLICATION_MESSAGE(tag);

  assert(!((0 <= sendTag) && (sendTag <= EGIDA_MAX_TAG)));

  ssn = Egida::GetSourceSequenceNumber(dest);
  Egida::GetPiggyback(dest, sendTag, ssn, &pb, &pbSize);

  // For all protocols, avoid sending messages that will be
  // discarded as duplicates by their corresponding receiver.
  // These duplicates arise during the roll-forward phase of a
  // recovering process.
  if (Egida::NeedToSendMsg(dest, ssn)) {
    // if the header can't be sent, then DON'T send the data
    if (Communication::SendMsg(dest, sendTag, pb, pbSize) < 0)
      std::cout << self << " couldn't send to: " << dest <<
	std::endl;
    else {
      Communication::SendMsg(dest, sendTag, msg, msgSize);
      //      std::cout << Egida::GetMyId() << " sent message to " << dest <<
      //	" ssn : " << ssn << std::endl;
    }
  }
  // The order here is crucial.  A copy of the message is made
  // AFTER the message is sent, so that, the copy is not in the
  // critical path of the send.

  // The buffers that are logged are p4 buffers for both the pb
  // and the msg
  Egida::LogSentMsg(dest, ssn, pb, pbSize, msg,	msgSize);
    
  Timer::UnblockTimerInterrupt();

  if(COLLECTING_STATS) {
    struct timeval timeEnd;
    double timeSpent = 0.0;
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_SEND_STAT, msgSize, timeSpent);
    Stats::UpdateMsgStat(EGIDA_SEND_STAT, dest, msgSize);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Event handler for intercepting MPI broadcasts.
// 
// Arguments:
//      tag  --- MPI assigned tag to the message
//      dataType --- MPI datatype is passed uninterpreted to p4.
//      msg, msgSize --- obvious meaning.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	 A copy of the message may be logged on storage.
// 
// /////////////////////////////////////////////////////////////////


void EventHandler::Broadcast(int tag, char *msg, int msgSize, int dataType)
{
  char *pb = NULL;
  int pbSize = 0;
  int dest, ssn, sendTag;
  int self = Egida::GetMyId(), numProcs = Egida::GetNumProcs();
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;

  if (!Egida::IsInitialized()) {
    Communication::Broadcast(tag, msg, msgSize);
    return;
  }

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  // Again, we don't want checkpoints in the middle of a broadcast.
  Timer::BlockTimerInterrupt();
  Communication::DrainMsgs();

  sendTag = EGIDA_TAG_SEND_APPLICATION_MESSAGE(tag);
  assert(!((0 <= sendTag) && (sendTag <= EGIDA_MAX_TAG)));

  for (dest = 0; dest < numProcs; dest++) {
    // The information piggybacked on the message depends on the
    // process to which the message is sent to.  So, get the
    // piggyback data and do a point-to-point send.

    ssn = Egida::GetSourceSequenceNumber(dest);
    Egida::GetPiggyback(dest, sendTag, ssn, &pb, &pbSize);

    // For all protocols, avoid sending messages that will be
    // discarded as duplicates by their corresponding receiver.
    // These duplicates arise during the roll-forward phase of a
    // recovering process.
    if (Egida::NeedToSendMsg(dest, ssn)) {
      Communication::SendMsg(dest, sendTag, pb, pbSize);
      Communication::SendMsg(dest, sendTag, msg, msgSize);
    }
    // The order here is crucial.  A copy of the message is made
    // AFTER the message is sent, so that, the copy is not in the
    // critical path of the send.
    Egida::LogSentMsg(dest, ssn, pb, pbSize, msg, msgSize);
    // don't worry about freeing pb.  That'll get taken care of by
    // log sent message.
  }
  Timer::UnblockTimerInterrupt();

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_BROADCAST_STAT, msgSize, timeSpent);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Event handler for receiving messages.  Receives in Egida are
// 	blocking in the sense that, when this function call returns, a 
// 	message is returned to the caller.
//
//      The message returned as result is a buffer that is allocated
//      by p4.  It is the caller's responsibility to ensure that the
//      buffer is appropriately freed.
// 
// Arguments:
// 	source, tag: input/output parameters
//          These allow the application process to specify the
//          particular message that the process is trying to receive.
//          If either parameter is a -1, then, that means that the
//          application process has no preference on the resulting
//          message that will be returned.
//      msg, msgSize --- obvious meaning.
//
// Results:
//      If a message is received, source, tag are modified to reflect
//          information about the message that is returned as result.
// 	A pointer to the message is returned in msg
//      The size of the message is returned in msgSize
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void EventHandler::Receive(int *source, int *tag, char **msg, int *msgSize)
{
  int recdTag, askedTag = *tag;
  struct timeval timeStart, timeEnd;
  struct timeval drainStart, drainEnd;
  double timeSpent = 0.0;

  if (!Egida::IsInitialized()) {
    Communication::RecvMsg(source, tag, msg, msgSize);
    return;
  }
  
  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  while (1) {
    // Since we modified the MPI tag on a send, we need to
    // appropriately modify the MPI tag of the message that the
    // application is trying to receive.
    recdTag = (askedTag == -1) ? askedTag : 
      EGIDA_TAG_SEND_APPLICATION_MESSAGE(askedTag);

    Timer::BlockTimerInterrupt();
    Egida::GetMsgToDeliver(source, &recdTag, msg, msgSize);
    Timer::UnblockTimerInterrupt();
    if (*msg)
      break;
    else {
      // Since no message is available, try to drain messages from
      // the underlying socket.
      Timer::BlockTimerInterrupt();
      Communication::DrainMsgs();
      Timer::UnblockTimerInterrupt();
    }
  }
    
  *tag = EGIDA_TAG_RECV_APPLICATION_MESSAGE(recdTag);

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_RECV_STAT, *msgSize, timeSpent);
    Stats::UpdateMsgStat(EGIDA_RECV_STAT, *source, *msgSize);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Log a copy of the message delivered from the last call to
// 	Egida_Receive.  In Egida_Receive, the buffer for a message was 
// 	allocated by p4.  A pointer to that buffer is passed to this
// 	function.  After a copy of the message is logged, that buffer
// 	is freed by Egida.
// 
//      This function exists because of MPICH.  MPICH uses p4 to
//      retrieve a message from the network and then makes a copy of
//      the message.  The message is returned back to p4.  To avoid an 
//      extra copy, MPICH returns the buffer to Egida; the message is
//      logged by Egida and eventually freed by Egida.
//
// Arguments:
// 	msg --- A pointer to a p4 buffer.
//          The caller of this function SHOULD NOT dereference msg.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void EventHandler::LogDeliveredMsg(char *msg)
{
  struct timeval timeStart, timeEnd;
  double timeSpent;
  
  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  if (!Egida::IsInitialized())
    p4_msg_free(msg);
  else {
    Timer::BlockTimerInterrupt();
    Egida::LogDeliveredMsg(msg);
    Timer::UnblockTimerInterrupt();
  }

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_LOG_DELIVERED_MSG_STAT, 0, timeSpent);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
//      Check if any messages are available from the network.
// 
// Arguments:
// 	from, tag --- information about a message that may be available
// 
// Results:
// 	If any messages are available, then, 
//        from --- is the id of the process from which a message is
//                 available 
//        tag  --- is the MPICH tag of the available message.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

int EventHandler::Msgs_Avail(int *from, int *tag)
{
  int egidaTag;
  int avail;
  struct timeval timeStart, timeEnd;
  double timeSpent;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  if (Egida::IsInitialized()) {
    egidaTag = (*tag == -1) ? *tag :
      EGIDA_TAG_SEND_APPLICATION_MESSAGE(*tag);
    Timer::BlockTimerInterrupt();

    avail = Egida::IsMsgAvail(from, &egidaTag);

    Timer::UnblockTimerInterrupt();
  }
  else {
    std::cout << "calling check for messages before init'ing egida" <<
      std::endl;
    avail = p4_messages_available(tag, from);
  }

  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_MSGS_AVAIL_STAT, 0, timeSpent);
  }
  return avail;
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Event handler for handling checkpoint events.
// 
// Arguments:
// 	NONE
// 
// Results:
// 	Uses the checkpoint protocol module to write out a
// 	checkpoint.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void EventHandler::Checkpoint()
{
  Egida::TakeCkpt();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Rollback the process state to a previous checkpoint.
// 
// Arguments:
// 	ckptFileName --- name of the file to which the process is
// 	     rolled back to.
// 	rollback --- is an argument that is handed to RestoreCkpt
// 	     method, which will hand it back to the Event handler after the 
// 	     process state is restored to the checkpoint.  Depending on
// 	     this argument, logging protocols do recovery differently.
//
// Results:
// 	NONE
// 
// Side Effects:
// 	Global variables will be reset to the state recorded in the
// 	checkpoint. 
// 
// /////////////////////////////////////////////////////////////////

void EventHandler::Failure(char *ckptFileName, bool rollback)
{
  FullCkpt temp;

  temp.RestoreCkptFile(ckptFileName, rollback);
}
