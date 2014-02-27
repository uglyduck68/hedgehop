// LogProtocol.cc -- 
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
// $Log: LogProtocol.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:18  ravshank
// Start of Spring 2001
//
//
// Revision 1.8  2000/11/01 23:24:29  phoebe
// Hash and sign of checkpoints is working. Also as checkpoints are cleaned up, so are the signed hashes corresponding to the checkpoints (this was not done earlier.)
//
// Revision 1.7  2000/09/27 22:03:09  phoebe
// In CkptImpl changed the growing of the heap from a strict monotonically increasing function (using the check that we only grow if size is less than what is needed) to one that can shrink. The reason we can do this is sbrk will take as an argument a negative value, where as malloc cannot.
//
// Revision 1.6  2000/06/27 13:23:10  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.5  2000/06/26 21:31:15  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.4  2000/06/23 02:47:43  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.3  2000/06/22 23:48:59  phoebe
// Changed some names: Egida_Msg_Queue is now MsgQueue and Egida_Msg is now Message. Also, changed the MsgQueue's in Egida_Object.H to be MsgQueue*'s so that it is consistent with all the other data members. One more thing...changed PbLog (and subclasses) to not require the CkptProtocol * for the object (so not a data member and not part of the Initialize method) since PbLog doesn't use this data member (it's used in PbCkpt).
//
// Revision 1.2  2000/06/22 20:59:08  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.1.1.1  2000/03/06 20:00:21  phoebe
// Sriram's original code with no modifications
//
// $Id: LogProtocol.cc,v 1.1.1.1 2001/02/12 00:00:18 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Mon May  3 17:25:12 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu Aug 26 09:43:18 1999
// Update Count    : 90
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <unistd.h>

#include "Egida_p4.h"

#include "Communication.H"
#include "Egida_Object.H"
#include "EventLog.H"
#include "LogProtocol.H"
#include "Security.H"
#include "Stats.H"
#include "Timer.H"

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Initialize the log protocol object.  The default logging
// 	protocol is a NULL protocol.
// 
// Arguments:
// 	Pointers to a ckptProtocol, msg_Q, and sent/delivered log objects
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void PbLog::Initialize(MsgQueue *q,
		       DetLog *detL, EventLog *sl, EventLog *dl)
{
  this->incomingMsgQ = q;
  this->detLog = detL;
  this->sentLog = sl;
  this->deliveredLog = dl;
  memset(this->lastAckRecd, 0, EGIDA_MAX_PROCS * sizeof(int));
  memset(this->lastAckSent, 0, EGIDA_MAX_PROCS * sizeof(int));
  memset(this->avoidLoggingMsg, 0, EGIDA_MAX_PROCS * sizeof(int));
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	On a dependency generating event (e.g., message send), logging 
// 	protocols piggyback some information.  This method returns the 
// 	piggybacked information.
// 
//      In a NULL logging protocol, there is nothing to piggyback.
//
// Arguments:
// 	dest --- process to which a message is sent
//      pb, pbSize --- data that has to be piggybacked on the
//      out-going message and the size of the piggybacked data.
// 
// Results:
// 	Sets pb, pbSize to 0.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void PbLog::GetPiggyback(int dest, char **pb, int *pbSize)
{
  *pb = NULL;
  *pbSize = 0;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Process the piggybacked data on an incoming message.
// 
//      In a NULL logging protocol, since nothing was piggybacked,
//      there is nothing to process.
//
// Arguments:
// 	source --- process that sent the message 
//      ssn --- send sequence number
//      pb, pbSize --- piggybacked info.
// 
// Results:
// 	Returns true if the message can be delivered to the application;
// 	false otherwise.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

bool PbLog::ProcessPiggyback(int source, int ssn, char *pb, int pbSize)
{
  return true;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
//      Called to check whether an incoming message can be delivered.
//      In the default case, all messages can be delivered.  The
//      non-default case usually arises in optimistic protocols.
//
// Arguments:
// 	source --- process that sent the message 
//      ssn --- send sequence number
//      pb, pbSize --- piggybacked info.
// 
// Results:
// 	Returns true if the message can be delivered to the application;
// 	false otherwise.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

bool PbLog::IsDeliverable(int source, int ssn, char *pb, int pbSize)
{
  return true;
}



// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Log a copy of a sent message.
// 
// Arguments:
// 	Have obvious meanings and they are different pieces of a
// 	message.
//        pb --- is the piggyback in a p4 buffer.  The caller SHOULD
//        NOT keep a reference to the buffer this method call.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void PbLog::LogSentMsg(int dest, int ssn, char *pb,
			     int pbSize, const char *msg,
			     int msgSize)
{
  char *msg_p4Buf = NULL;
  EventInfo *eInfo;

  if (dest == this->id) {
    // don't log messages sent to self
    p4_msg_free(pb);
    return;
  }

  struct timeval startTime;
  if(COLLECTING_STATS) {
    gettimeofday(&startTime, NULL);
  }
  if (this->avoidLoggingMsg[dest] > ssn) {
    p4_msg_free(pb);
    return;
  }

  if (msgSize > 0) {
    msg_p4Buf = p4_msg_alloc(msgSize);
    memcpy(msg_p4Buf, msg, msgSize);
  }
  // we don't know what the rsn is going to be.
  eInfo = new EventInfo(this->id, ssn, dest, -1, 
			pb, pbSize, msg_p4Buf, msgSize);
  this->sentLog->Log(eInfo);
  if (this->lastAckRecd[dest] > ssn)
    this->ProcessAck(dest, ssn);

  if(COLLECTING_STATS) {
    struct timeval endTime;
    double timeSpent = 0.0;
    gettimeofday(&endTime, NULL);
    Timer::ComputeTimeDiff(&timeSpent, startTime, endTime);
    Stats::Update(EGIDA_LOG_SENT_MSG_STAT, msgSize, timeSpent);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Handler for messages sent by logging protocol.
// 
// Arguments:
// 	source --- the process that sent the protocol message
//      tag --- type of the protocol message
//      msg, msgSize --- the message itself.  msg is a p4 buffer.
//
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void PbLog::ProcessMsg(int source, int tag, 
			     char *msg, int msgSize)
{

}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Handle acks.
// 
// Arguments:
// 	source --- the process that sent the ack.
//      ssn --- sequence # of message m such that m.dest = source
//
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void PbLog::ProcessAck(int source, int ssn)
{
  this->lastAckRecd[source] = ssn;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Log a copy of the last message that was delivered.
// 
// Arguments:
// 	msg --- an event info buffer containing the message that was last
// 	   delivered.  The caller of this method SHOULD NOT free the
// 	   buffer. 
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void PbLog::LogDeliveredMsg(EventInfo *msg)
{
  this->deliveredLog->Log(msg);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Protocol-specific actions that have to be executed just before 
// 	a checkpoint is taken.
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

void PbLog::PreCkptActions(void)
{
  Egida::SetStateStable();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Protocol-specific actions that have to be executed just after
// 	a checkpoint is taken.  Any meta-data about the process state
// 	that was saved when PreCkptActions() was called can now be
// 	made permanent.  That is, create a mapping between
// 	ckptFileName and protocol specific meta-data recorded in
// 	PreCkptActions. 
// 
// Arguments:
// 	ckptFileName --- name of the file in which the checkpoint is
// 	   written to.  
//      stableEventId --- esn of the last event executed by this
//         process when  the checkpoint (ckptFileName) was taken.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void PbLog::PostCkptActions(const char *ckptFileName, 
				  int stableEventId)
{
  this->detLog->GarbageCollect(this->id, stableEventId);
  this->deliveredLog->GarbageCollect(this->id, stableEventId);
  Egida::GarbageCollectMsgPoll(this->id, stableEventId);
}



void PbLog::CleanUpCkptFiles(char * ckptFileName)
{
  char baseName[EGIDA_FILENAME_LEN];
  char oldFile[EGIDA_FILENAME_LEN];
  char *p, *q;
  int ckptCounter = 0;

  strcpy(baseName, ckptFileName);
  
  p = rindex(baseName, '.');
  q = p+1;
  *p = '\0';  // truncate baseName at the last "."
  
  ckptCounter = atoi(q);

  sprintf(oldFile, "%s.%d", baseName, ckptCounter - 1);
  unlink(oldFile);
  //if we are throwing away the checkpoint, we don't need 
  //the signed hash either.
  if(HASH_AND_SIGN_CKPT || PARTIAL_HASH_AND_SIGN_CKPT) {
    char oldSigFile[EGIDA_FILENAME_LEN];
    sprintf(oldSigFile, "%s.hash", oldFile); 
    unlink(oldSigFile);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Handle timer interrupts.
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

void PbLog::TimerExpired()
{

}

void PbLog::PrepareForCrash()
{

}

void PbLog::Terminate()
{

}

void PbLog::PreReplayActions(int startEsn, bool rb)
{

}

void PbLog::PostReplayActions()
{

}

bool PbLog::NeedToDetectOrphans()
{
  return false;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Determine the checkpoint which is consistent with the
// 	recoverable state of the crashed process to which this process 
// 	should rollback to.
// 
// Arguments:
// 	fileName --- output parameter
// 
// Results:
//      fileName --- name of the file to rollback to; this method
//             doesn't modify this parameter.
// 	Returns false --- by default, this protocol doesn't know which 
// 	checkpoint constitutes a consistent global state.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

bool PbLog::GetRollbackFile(char *fileName)
{
  return false;
}


void PbLog::SendLastControlMessages() {
}
