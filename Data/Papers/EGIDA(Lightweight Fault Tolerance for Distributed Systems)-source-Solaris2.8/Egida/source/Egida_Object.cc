// Egida_Object.cc -- 
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
// $Log: Egida_Object.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:18  ravshank
// Start of Spring 2001
//
// Revision 1.28  2000/11/10 15:48:51  phoebe
// Checkpoint memory leak is now solved, and so is the memcpy core dump on some checkpoints.
//
// Revision 1.27  2000/11/01 16:35:29  phoebe
// Working on getting security to work again with the redesigned system. 
// Message encryption, either full or only egida messages, is working now.
//
// Revision 1.26  2000/10/31 00:22:46  phoebe
// SBP now works with flushing and garbage collection. Before the file out pointers were not being managed properly so after a garbagecollect they were pointing to a non-existant file. So the point of all of this is we have a working SentStore.cc file.
//
// Revision 1.25  2000/10/24 16:32:27  phoebe
// Garbage collection of the sentLog is now happening but sometimes it doesn't recover...think it's a problem with multiple recoveries and not flushing some info. Will check into it. Fixed the memcpy core dump on taking a checkpoint...it was a problem with the fact that we were using a signed int to track the segment size and should have been using an unsigned int so that we didn't get overflow problem.
//
// Revision 1.24  2000/10/20 19:28:45  phoebe
// SentLog class is now integrated and works so protocols using the sentLog to store information will now restart on flushing.
//
// Revision 1.23  2000/10/17 15:02:29  phoebe
// Stable code checkin. RBP is extremely stable except if you kill the master and slave at exactly the same time....it will hang in ReplayDeliver. SBP cannot support concurrent failures due to the lost control messages or hanging in ReplayDeliver. Causal can do +concurrent+ failures as long as control messages are not lost....so the restart must be staggered. Causal seems to suffer the same RBP problem with a master/slave pair, but unsure if this is the problem or if I didn't set numfailures=2...think the later would fix this. All the sentLog protocols (SBP and Causal) suffer from processes dumping core during WriteCkpt if they have been running for a long time since we are not flushing volatile memory at the moment. Should go away with the proper sentLog class fix.
//
// Revision 1.22  2000/10/12 19:50:55  phoebe
// Optimistic is still not working for more than one failure, but the incarnation number is now working correctly, and on the second failure it hangs in exactly the same spot every time. Also...optimistic is now rolling back a checkpoint file instead of doing the exec-ing that it was doing before. Additionally, during some of the debugging process, checkpoints are now shrinking heap sizes correctly (we thought they were doing it before, but they weren't.)
//
// Revision 1.21  2000/10/03 22:56:23  phoebe
// Optimistic will now reliably restart once. Still fails multiple sequential failures.
//
// Revision 1.20  2000/09/29 00:20:12  phoebe
// Optimistic will now recover from the first failure...but not multiple sequential failures.
//
// Revision 1.19  2000/09/27 22:03:06  phoebe
// In CkptImpl changed the growing of the heap from a strict monotonically increasing function (using the check that we only grow if size is less than what is needed) to one that can shrink. The reason we can do this is sbrk will take as an argument a negative value, where as malloc cannot.
//
// Revision 1.18  2000/08/08 20:57:15  phoebe
// Cleaned up code, and now the never checkpointing again after a fail error is fixed.
//
// Revision 1.17  2000/08/08 14:28:55  phoebe
// Can now restart multiple times and kill the master process for Receiver Based Pessimistic logging. Same thing for Sender Based, but with sender based since the recovery logs must be in volatile memory, it will eventually run out of RAM and won't be able to continue or restart (obviously). This is a protocol design bug that will be fixed, but the restart is stable. Also able to restart from an incremental checkpoint (tested with RBP). These restart tests were done without any security turned on.
//
// Revision 1.16  2000/07/11 22:20:04  phoebe
// Did several things: Streamlined DebugTrace so that Egida_Object's RestoreDone didnt' need to call it (got rid of a small memory leak by doing this.) It's less efficient, but then debugging code shouldn't be in the release copy anyway. Two...moved the -recover string to the proper place in the failuredetector so that on a subsequent restart (multiple restarts of one process) it will correctly identify which checkpoint it should be rolling back to. Third...moved growing of the heap in CkptImpl to the RestoreHeapData segs for FullCkpt and put it in the RestoreCkpt for Incremental (in the loop). This is in hopes of being able to restart from in incremental checkpoint. At the moment still can't restart multilple times and can't restart from an incremental checkpoint.
//
// Revision 1.15  2000/06/30 21:22:43  phoebe
// Sanity check before leaving for vacation.
//
// Revision 1.14  2000/06/30 21:00:21  phoebe
// Changed when the FailureDetector is notified of the new checkpoint. It's now in a place where we could delete checkpoint files without any repercussions since the cleanup would be in the pbLog object most likely. Also, the failure detector now re-establishes the socket parameters after a failure whereas before it did not.
//
// Revision 1.13  2000/06/30 20:10:20  phoebe
// Async full checkpoint now working with garbage collection.
//
// Revision 1.12  2000/06/30 19:41:35  phoebe
// Commented out actions in PostCkptActions (Egida class) and can now restart Asynch checkpoint. However, this is still not a correct implementation because it will never clean up det logs.
//
// Revision 1.11  2000/06/27 13:23:02  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.10  2000/06/26 21:31:10  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.9  2000/06/26 19:09:53  phoebe
// Removed all wrapper methods out of Egida_Internal.cc and renamed calls in code to directly call the Egida::Method that would have been called by the Egida_Method call.
//
// Revision 1.8  2000/06/26 16:56:56  phoebe
// Made all the Egida_Object methods and members static. Also moved GetMyId and GetNumProcs out of Egida_Internal and into Egida_Object.
//
// Revision 1.7  2000/06/26 14:56:03  phoebe
// More slight changes. Cleaned up Init.cc by moving path definitions to Egida_Globals.H. There are also some other small changes that I can't remember at the moment.
//
// Revision 1.6  2000/06/23 19:11:01  phoebe
// Moved all the egida object initialization from Init.cc into ProtocolPreInit and ProtocolPostInit methods.
//
// Revision 1.5  2000/06/23 02:47:36  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.4  2000/06/23 00:01:04  phoebe
// Another name change...HandleMsgPoll and NullHandleMsgPoll are now MsgPoll and NullMsgPoll.
//
// Revision 1.3  2000/06/22 23:48:57  phoebe
// Changed some names: Egida_Msg_Queue is now MsgQueue and Egida_Msg is now Message. Also, changed the MsgQueue's in Egida_Object.H to be MsgQueue*'s so that it is consistent with all the other data members. One more thing...changed PbLog (and subclasses) to not require the CkptProtocol * for the object (so not a data member and not part of the Initialize method) since PbLog doesn't use this data member (it's used in PbCkpt).
//
// Revision 1.2  2000/06/22 20:59:01  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.1.1.1  2000/03/06 20:00:19  phoebe
// Sriram's original code with no modifications
//
// $Id: Egida_Object.cc,v 1.1.1.1 2001/02/12 00:00:18 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Wed May  5 17:38:36 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu Aug 26 10:02:40 1999
// Update Count    : 389
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <assert.h>
#include <iostream>

#include "Egida_p4.h"


#include "Determinant.H"
#include "Egida_Object.H"
#include "EventInfo.H"
#include "FailDetect.H"
#include "Globals.H"
#include "Stats.H"
#include "Timer.H"


//static members of Egida class    
int Egida::id = -1;
int Egida::numProcs = 0;
int Egida::esn = 0;
int Egida::stableEsn = 0;
int Egida::asyncStableEsn = 0;

bool Egida::disableTimer = false;
bool Egida::isInitialized = false;
bool Egida::isRecovering = false;
bool Egida::replayMsgAvail = false;
bool Egida::failedOnce = false;

char Egida::programName[EGIDA_FILENAME_LEN];

struct timeval Egida::replayStartTime;

EventInfo * Egida::lastDeliveredMsg = NULL;
MsgPoll * Egida::msgPoll = NULL;
DetLog * Egida::detLog = NULL;
EventLog * Egida::sentLog = NULL;
EventLog * Egida::deliveredLog = NULL;
MsgQueue * Egida::incomingMsgQ = NULL;
MsgQueue * Egida::replayMsgQ = NULL;;
PbLog * Egida::pbLog = NULL;
PbCkpt * Egida::pbCkpt = NULL;
CkptProtocol * Egida::ckptProtocol = NULL;
HowToCkpt * Egida::howToCkpt = NULL;
Recovery * Egida::recovery = NULL;
RollbackActions * Egida::rollbackActions = NULL;
RollbackActions * Egida::rollforwardActions = NULL;
OrphanDetection * Egida::orphanDetection = NULL;

int Egida::sendSeqNum[EGIDA_MAX_PROCS];
int Egida::lastGCSent[EGIDA_MAX_PROCS];
int Egida::lastMsgDelivered[EGIDA_MAX_PROCS];
int Egida::stableRecdMsg[EGIDA_MAX_PROCS];
int Egida::asyncStableRecdMsg[EGIDA_MAX_PROCS];
int Egida::lastMsgSent[EGIDA_MAX_PROCS];
int Egida::lastMsgRecd[EGIDA_MAX_PROCS];
bool Egida::msgsDelivered[EGIDA_MAX_PROCS][EGIDA_MAX_APPL_MSGS];


//Initialization method for non-protocol dependent aspects of 
// Egida...must be called BEFORE ProtocolSpecificInit

void Egida::ProtocolPreInit(int self, int numP, char * name)
{
  id = self;
  numProcs = numP;
  strcpy(programName, name);

  incomingMsgQ = new MsgQueue();
  replayMsgQ = new MsgQueue();
  incomingMsgQ->Initialize(self, numP);
  replayMsgQ->Initialize(self, numP);

  msgPoll = new MsgPoll(self, numP, DetStore::EGIDA_STABLE_STORE);

  memset(sendSeqNum, 0, EGIDA_MAX_PROCS * sizeof(int));
  memset(lastGCSent, 0, EGIDA_MAX_PROCS * sizeof(int));
  memset(stableRecdMsg, 0, EGIDA_MAX_PROCS * sizeof(int));
  memset(lastMsgSent, 0, EGIDA_MAX_PROCS * sizeof(int));
  memset(lastMsgRecd, 0, EGIDA_MAX_PROCS * sizeof(int));
  memset(lastMsgDelivered, 0, EGIDA_MAX_PROCS * sizeof(int));

  for (int i = 0; i < EGIDA_MAX_PROCS; i++) 
    memset(msgsDelivered[i], false, EGIDA_MAX_APPL_MSGS *
	   sizeof(bool));
}



//Initialization method for non-protocol dependent aspects of 
// Egida...must be called AFTER ProtocolSpecificInit
void Egida::ProtocolPostInit(int avoidThresh)
{
  detLog->SetLogFileName("detLog");
  // This is sets the callback that has to be invoked whenever the
  // contents of the determinant log are written out to a backing
  // stable storage.
  detLog->SetLogStableCallback(SetStableEsn);

  sentLog->SetLogFileName("sentLog");

  deliveredLog->SetLogFileName("deliveredLog");
  deliveredLog->SetLogStableCallback(SetStableRecdMsg);

  pbLog->Initialize(incomingMsgQ, detLog, sentLog, deliveredLog);

  ckptProtocol->Initialize(pbLog, howToCkpt);
  ckptProtocol->SetAvoidThreshold(avoidThresh);

  isInitialized = true;
}



void Egida::GarbageCollectMsgPoll(int procId, int stable)
{
  msgPoll->GarbageCollect(procId, stable);
}


void Egida::Terminate()
{
  pbLog->Terminate();
  ckptProtocol->Terminate();
  howToCkpt->Terminate();
  isInitialized = false;
}



//accessor methods for Egida data members
void Egida::TakeCkpt()
{
  struct timeval timeStart;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }
  ckptProtocol->TakeCkpt();

  if(COLLECTING_STATS) {
    struct timeval timeEnd;
    double timeSpent = 0.0;
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_CKPT_TIME_STAT, 0, timeSpent);
  }

}

void Egida::LogSentMsg(int dest, int ssn, char *pb,
		       int pbSize, const char *msg,
		       int msgSize)
{
  pbLog->LogSentMsg(dest, ssn, pb, pbSize, msg, msgSize);
}


bool Egida::FailedOnce()
{
  return failedOnce;
}


bool Egida::IsInitialized()
{
  return isInitialized;
}


int Egida::GetSourceSequenceNumber(int dest)
{
  sendSeqNum[dest]++;
  return sendSeqNum[dest];
}


void Egida::DisableTimer()
{
  disableTimer = true;
}


void Egida::SetAsyncStableEsn()
{
  asyncStableEsn = stableEsn;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Provide the p4 id of this process to any of Egida's objects.
// 
// Arguments:
// 	NONE
// 
// Results:
// 	Returns the p4 id of this process.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

int Egida::GetMyId()
{
  if(isInitialized) {
    return id;
  }
  else {
    return Communication::GetProcessId();
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Provide the # of application processes to any of Egida's objects.
// 
// Arguments:
// 	NONE
// 
// Results:
// 	Returns the # of application processes participating in the computation.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
int Egida::GetNumProcs()
{

  if(isInitialized) {
    return numProcs;
  }
  else {
    return Communication::GetNumberOfProcesses();
  }
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Return the information that has to be piggybacked on out-going 
// 	messages.
// 
// Arguments:
// 	dest --- process to which message is sent
//      sendTag --- MPI assigned tag to the out-going message.
//      pb, pbSize --- output parameters about the piggybacked data.
// 
// Results:
// 	pb --- holds the piggybacked data.  It is the caller's
// 	responsibility to free the buffer by calling delete.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::GetPiggyback(int dest, int sendTag, 
			 int ssn, char **pb, int *pbSize)
{
  char *pbLogBuf = NULL, *pbCkptBuf = NULL;
  int pbLogBufSize = 0, pbCkptBufSize = 0;
  struct timeval startTime, endTime;
  double timeSpent;

  if(COLLECTING_STATS) {
    gettimeofday(&startTime, NULL);
  }

  pbLog->GetPiggyback(dest, &pbLogBuf, &pbLogBufSize);
  pbCkpt->GetPiggyback(dest, &pbCkptBuf, &pbCkptBufSize);
  MergePiggyback(dest, sendTag, id, ssn, pb, pbSize,
		       pbCkptBuf, pbCkptBufSize, pbLogBuf, pbLogBufSize);

  if(COLLECTING_STATS) {
    gettimeofday(&endTime, NULL);
    Timer::ComputeTimeDiff(&timeSpent, startTime, endTime);
    Stats::Update(EGIDA_GET_PIGGYBACK_STAT, 0, timeSpent);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Determine if an application message has to be sent.  This
// 	issue arises because we are doing sender-based suppressing of
// 	duplicates.  Duplicate messages may arise during the
// 	roll-forward phase of a recovering process.  This method
// 	determines if the message that is about to be sent out will be 
// 	discarded as a duplicate by the receiver.
// 
// Arguments:
// 	dest --- id of the message receiver
//      ssn --- seq # of the message that is to be sent
// 
// Results:
// 	Returns 1 if a message has to be sent out.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

bool Egida::NeedToSendMsg(int dest, int ssn)
{
  if (lastMsgSent[dest] <= ssn) {
    lastMsgSent[dest] = ssn;
    return true;
  }
  return false;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Check if a message is available in the message queue.
// 
// Arguments:
// 	source, tag: input/output parameters 
//          source, tag: if either is -1, then, that is don't care
//            value.  either a message from any source or any tag.
//          otherwise, they specify the source or a message of a
//          certain tag whose availability is being checked in the queue.
// 
// Results:
// 	Returns 1 if a matching message is available and 0 otherwise.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

int Egida::IsMsgAvail(int *source, int *tag)
{
  int result;

  Communication::DrainMsgs();
  // Several cases here:
  // 1. isRecovering = TRUE:
  //      read from the file is
  //       (a) successful --- return that result
  //       (b) fails --- go look in the socket
  // 2. isRecovering = FALSE:
  //      This is the wierd case when all the determinants have been
  //      replayed, but, there may still be some more poll events to
  //      be replayed.  To ensure that, the content of the file still
  //      read, the boolean replayMsgAvail is SET until:
  //       (a) read from the file fails
  //       (b) the result from the file read is a success---by doing this,
  //       results of all the poll events that failed until the first
  //       successful one AFTER the last determinant was replayed are replayed.
  if (replayMsgAvail) {
    if (msgPoll->ReplayResult(esn + 1, &result)) {
      // Case 2(b) is causing problems: After all determinants
      // replayed, trying to replay any  polls that occurred after the 
      // last one may not be correct.  The poll may have returned 1
      // during failure-free execution; but, during recovery there is
      // no guarantee that if 1 is returned, a message is available on 
      // the socket---the message on the socket may all be duplicates
      // and the process may hang.
      // if ((isRecovering) || (result == 0)) {
      if (isRecovering) {
	esn++;
	return result;
      }
      RemoveNonDeliverableMsgs();
      // else !isRecovering and result == 1---we are finished with
      // reading the file
    }
    replayMsgAvail = false;
    msgPoll->ReplayDone(esn);
  }
  result = incomingMsgQ->IsMsgAvail(source, tag);
  esn++;
  msgPoll->RecordResult(esn, result);
  return result;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Returns the message that has to be delivered to the application.
// 
// Arguments:
// 	source, tag: input/output parameters
//          source, tag: if either is -1, then, that is don't care
//            value.  either a message from any source or any tag.
//          otherwise, they specify the source or a message of a
//          certain tag which the application is asking for delivery.
//       msg, msgSize: output parameters for the result of this method.
// 
// Results:
// 	msg --- if non-NULL, then, it is an application message stored 
// 	  in a p4 buffer.  It is the responsibility of the caller to
// 	  free the buffer by calling p4_msg_free.
//      msgSize, source, tag --- will be modified to reflect the message that
//        is being returned.
//
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::GetMsgToDeliver(int *source, int *tag,
			    char **msg, int *msgSize)
{
  int i, pbSize = 0, ssn;
  bool sendAck;
  char *pb = NULL;
  Determinant *d;
  int origSource = *source;
  int origTag = *tag;

  if (isRecovering) {
    double timeSpent;
    struct timeval endTime;
    struct timeval startTime;
    if(COLLECTING_STATS) {
      gettimeofday(&startTime, NULL);
    }

    if (ReplayDeliver(source, tag, &pb, &pbSize, msg, msgSize)) {
      // replay was successful
      assert((0 <= *source) && (*source < numProcs));
      esn++;

      memcpy(&ssn, pb + EGIDA_FIXED_HEADER_SSN, sizeof(int));
      lastDeliveredMsg = new EventInfo(id, esn, *source, ssn, pb, pbSize,
				       *msg, *msgSize);
      assert(ssn < EGIDA_MAX_APPL_MSGS);
      msgsDelivered[*source][ssn] = true;

      if ((lastMsgDelivered[*source] + 1 ==  ssn)) {
	lastMsgDelivered[*source] = ssn;
	// if any messages were delivered out of order, then,
	// appropriately update the lastMsgDelivered
	for (i = lastMsgDelivered[*source];
	     ((i < EGIDA_MAX_APPL_MSGS) &&
	      (msgsDelivered[*source][i])); i++) 
	  lastMsgDelivered[*source] = i;
      }
      if(COLLECTING_STATS) {
	gettimeofday(&endTime, NULL);
	Timer::ComputeTimeDiff(&timeSpent, startTime, endTime);
	Stats::Update(EGIDA_RECOVERY_REPLAY_DELIVER_STAT, 0, timeSpent);
      }
      // I am using lastMsgDelivered[*source] instead of ssn
      // because: if messages may be delivered out of order, then
      // garbage collection can be done only until
      // lastMsgDelivered[*source] and *NOT* ssn.
      if (stableRecdMsg[*source] >= lastMsgDelivered[*source]) {
	if (lastMsgDelivered[*source] - lastGCSent[*source] >= 20) {
	  SendGarbageCollectMsg(*source, lastMsgDelivered[*source]);
	  lastGCSent[*source] = lastMsgDelivered[*source];
	}
      }
      return;
    }
    else {
      std::cout << id << " Replay done with esn: " << esn << std::endl;

      if(COLLECTING_STATS) {
	gettimeofday(&endTime, NULL);
	Timer::ComputeTimeDiff(&timeSpent, replayStartTime, endTime);
	Stats::Update(EGIDA_RECOVERY_LOG_REPLAY_STAT, 0, timeSpent);
      }
      memcpy(lastMsgRecd, lastMsgDelivered, 
	     EGIDA_MAX_PROCS * sizeof(int));

      // This is only for the Optimistic protocol. Ensure that it is not used 
      // for the other protocols. There is no way to distinguish between
      // protocols. Hence, the only way is to put a method in each of the
      // Log protocol classes call it and the right method is going to get
      // called. Only the optimistic protocol will do this and the rest of them
      // do nothing

      pbLog->SendLastControlMessages();

#if 0
      for (int index = 0; index < numProcs; index++)
	Egida::ProcessGetLastControlMsgReq(index);
#endif

      // send all messages from here onwards
      memset(lastMsgSent, 0, numProcs * sizeof(int));

      // throw away the messages that'll never be replayed---since we
      // are doing this, each sender should now begin sending messages
      // since the lastMsgRecd[].  This means that in ResendMsgs(),
      // lastMsgSent[] should be updated.
      replayMsgQ->ClearAllQueues();

      isRecovering = false;
      // throw dets from this esn onwards...
      detLog->Purge(id, esn + 1);
      // throw away messages too...
      deliveredLog->Purge(id, esn + 1);

      pbLog->PostReplayActions();

      detLog->ReplayDone();
      deliveredLog->ReplayDone();

      *msg = NULL;
      *msgSize = 0;
      *source = origSource;
      *tag = origTag;

      // Send a request asking for "lost" messages
      CollectLostMsgs();  //Optimistic does not need to do this, but it helps
                          // with recovery time.

      Stats::Dump();
      disableTimer = false;

    }
  }
  
  incomingMsgQ->Dequeue(source, tag, &pb, &pbSize);
  if (pb) {
    while (1) {
      incomingMsgQ->Dequeue(source, tag, msg, msgSize);
      if (*msg != NULL) {
	assert(*msgSize > 0);
	break;
      }
    }
    assert(pbSize > 0);

    if (!ProcessPiggyback(pb, pbSize, &ssn)) {
      p4_msg_free(pb);
      p4_msg_free(*msg);
      *msg = NULL;
      *msgSize = 0;
      *source = origSource;
      *tag = origTag;
      return;
    }
    esn++;

    d = new Determinant(*source, ssn, id, esn, NULL, 0);
    //    std::cout << Egida::GetMyId() << " Recd msg from " << *source <<
    //      " ssn : " << ssn << std::endl;
    detLog->Log(d);
    lastDeliveredMsg = new EventInfo(id, esn,
				     *source, ssn, pb, pbSize,
				     *msg, *msgSize);
    assert(ssn < EGIDA_MAX_APPL_MSGS);
    msgsDelivered[*source][ssn] = true;

    if ((lastMsgDelivered[*source] + 1 ==  ssn)) {
      lastMsgDelivered[*source] = ssn;
      // if any messages were delivered out of order, then,
      // appropriately update the lastMsgDelivered
      for (i = lastMsgDelivered[*source];
	     ((i < EGIDA_MAX_APPL_MSGS) &&
	      (msgsDelivered[*source][i])); i++) 
	lastMsgDelivered[*source] = i;
    }

  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Log a copy of a previously delivered message.
// 
// Arguments:
// 	msg --- pointer to the last message that was delivered.  The
// 	caller of this method SHOULD NOT refer msg after this method call.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::LogDeliveredMsg(char *msg)
{
  if (isRecovering &&
      (stableRecdMsg[lastDeliveredMsg->otherProc] >=
       lastDeliveredMsg->otherProcEventId)) {
    // During recovery, avoid logging stable messages
    delete lastDeliveredMsg;
    return;
  }
  
  pbLog->LogDeliveredMsg(lastDeliveredMsg);
  return;

}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Method that is called before a checkpoint is taken.
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

void Egida::PreCkptActions()
{
  pbCkpt->PreCkptActions();
  pbLog->PreCkptActions();
  
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Execute protocol actions after a checkpoint is written out.
// 
// Arguments:
// 	ckptFileName --- file to which a checkpoint is written out.
// 	  Note that meta-data about the state saved in ckptFileName
// 	  was "recorded" in the last call to PreCkptActions().
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::PostCkptActions(const char *ckptFileName)
{
  struct stat statBuf;
  
  if(COLLECTING_STATS) {
    memset(&statBuf, 0, sizeof(struct stat));
    if (stat(ckptFileName, &statBuf) == 0) {
      Stats::Update(EGIDA_CKPT_SIZE_STAT, statBuf.st_size, 0.0);
    }
  }

  msgPoll->CkptDone();
  detLog->CkptDone();
  deliveredLog->CkptDone();
  sentLog->CkptDone();
  
  ckptProtocol->CkptDone();

  pbLog->PostCkptActions(ckptFileName, stableEsn);  

  FailDetect::SendCkptFileName(ckptFileName);
  
  SendGarbageCollectMsg();
  
  if(howToCkpt->OkToRemoveCkptFiles())
    pbLog->CleanUpCkptFiles((char*)ckptFileName);
  
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Execute protocol actions after a checkpoint is written out.
// 
// Arguments:
// 	ckptFileName --- file to which a checkpoint is written out.
// 	  Note that meta-data about the state saved in ckptFileName
// 	  was "recorded" in the last call to PreCkptActions().
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::PostAsyncCkptActions(const char *ckptFileName)
{
  struct stat statBuf;
  
  if(COLLECTING_STATS) {
    memset(&statBuf, 0, sizeof(struct stat));
    if (stat(ckptFileName, &statBuf) == 0) {
      Stats::Update(EGIDA_CKPT_SIZE_STAT, statBuf.st_size, 0.0);
    }
  }

  msgPoll->CkptDone();
  detLog->CkptDone();
  deliveredLog->CkptDone();
  ckptProtocol->CkptDone();
  sentLog->CkptDone();

  pbLog->PostCkptActions(ckptFileName, asyncStableEsn);

  FailDetect::SendCkptFileName(ckptFileName);
    
  AsyncSendGarbageCollectMsg();

  if(howToCkpt->OkToRemoveCkptFiles())
    pbLog->CleanUpCkptFiles((char*)ckptFileName);

}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Send out a message asking other processes to garbage collect
// 	data they may have logged on behalf of this process.
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
void Egida::SendGarbageCollectMsg()
{
  int i;

  for (i = 0; i < numProcs; i++) {
    if (i == id)
      continue;
    SendGarbageCollectMsg(i);
  }
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Send out a message asking other processes to garbage collect
// 	data they may have logged on behalf of this process.
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
void Egida::AsyncSendGarbageCollectMsg()
{
  int i;

  for (i = 0; i < numProcs; i++) {
    if (i == id)
      continue;
    AsyncSendGarbageCollectMsg(i);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Send out a message to procId asking it to garbage collect
// 	data they may have logged on behalf of this process.
//      Called after a sync checkpoint.
// Arguments:
// 	procId --- process to which a garbage collect message is sent.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void Egida::SendGarbageCollectMsg(int procId)
{
  std::ostrstream os;

  os << stableEsn << ' ';
  os << stableRecdMsg[procId] << ' ' << std::ends;
  SendControlMsg(procId, EGIDA_GARBAGE_COLLECT_MSG,
		       os.str(), os.pcount());
  // unfreeze the buffer so that it gets freed
  os.rdbuf()->freeze(false);
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Send out a message to procId asking it to garbage collect
// 	data they may have logged on behalf of this process.
//      Called after an async checkpoint.
// Arguments:
// 	procId --- process to which a garbage collect message is sent.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void Egida::AsyncSendGarbageCollectMsg(int procId)
{
  std::ostrstream os;

  os << asyncStableEsn << ' ';
  os << asyncStableRecdMsg[procId] << ' ' << std::ends;
  SendControlMsg(procId, EGIDA_GARBAGE_COLLECT_MSG,
		       os.str(), os.pcount());
  // unfreeze the buffer so that it gets freed
  os.rdbuf()->freeze(false);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Send out a message to procId asking it to garbage collect
// 	data they may have logged on behalf of this process.
//      This is called after the Receive of a message.
// Arguments:
// 	procId --- process to which a garbage collect message is sent.
//      ssn --- sequence # of the last stable message recd. from procId 
//
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void Egida::SendGarbageCollectMsg(int procId, int ssn)
{
  std::ostrstream os;

  os << esn << ' ';
  os << ssn << ' ' << std::ends;
  SendControlMsg(procId, EGIDA_GARBAGE_COLLECT_MSG,
		       os.str(), os.pcount());
  // unfreeze the buffer so that it gets freed
  os.rdbuf()->freeze(false);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Record the esn that is "stable".  This method optimistically
// 	records the current esn as stable---this method may get called as
// 	part of PreCkptActions().  Garbage collection can be done only 
// 	when the checkpoint is written out.
// 
// Arguments:
// 	NONE --- Here, the esn that is marked as stable is the esn at
// 	the time of the checkpoint.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void Egida::SetStableEsn()
{
  stableEsn = esn;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Record the esn that is "stable".  This means that the
// 	determinants upto stableEsn have been written out to stable
// 	storage and they can be garbage collected.  This method is a
// 	callback analogous to SetStableRecdMsg(d, r, s, s);
// 
// Arguments:
// 	stableE --- is the id of the latest determinant d such that
// 	d.dest = this process.  For each d', such that d'.dest =
// 	d.dest, d'.d_esn < d.d_esn, d' is stable.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void Egida::SetStableEsn(int stableE)
{
  stableEsn = stableE;
}

// /////////////////////////////////////////////////////////////////
//
// Purpose:
// 	Mark a set of received messages as "stable".  This method optimistically
// 	records the last received message from each process as
// 	stable---this method may get called as 
// 	part of PreCkptActions().  Garbage collection can be done only 
// 	when the checkpoint is written out
// 
// Arguments:
// 	NONE --- Here, the messages that are marked as stable are
// 	those that have been received and/or delivered at the time of
// 	the checkpoint.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void Egida::SetStableRecdMsg()
{
  memcpy(stableRecdMsg, lastMsgDelivered, EGIDA_MAX_PROCS * sizeof(int));
}


// /////////////////////////////////////////////////////////////////
//
// Purpose:
// 	Mark a set of received messages as "stable".  This method optimistically
// 	records the last received message from each process as
// 	stable---this method may get called as 
// 	part of PreCkptActions().  Garbage collection can be done only 
// 	when the checkpoint is written out
// 
// Arguments:
// 	NONE --- Here, the messages that are marked as stable are
// 	those that have been received and/or delivered at the time of
// 	the checkpoint.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void Egida::AsyncSetStableRecdMsg()
{
  memcpy(asyncStableRecdMsg, stableRecdMsg, EGIDA_MAX_PROCS * sizeof(int));
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Re-mark a set of received messages as "stable".  This method
// 	gets called when the state of the process is restored from a
// 	checkpoint. 
// 
// Arguments:
//      source, ssn --- are the values for the latest message m such 
//      that m is stable.  That is, for each m', m'.source = source and m'.dest = m.dest,
//      m'.ssn < m.ssn, m' is stable.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void Egida::SetStableRecdMsg(int source, int ssn)
{
  stableRecdMsg[source] = ssn;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Mark a set of received messages as "stable".  This means that
// 	the corresponding sender's are free to garbage collect these
// 	messages from their sent logs.  This method is a callback
// 	function that gets called whenever the delivered log object
// 	flushes a set of messages to stable store.
// 
// Arguments:
//      source, ssn, dest, rsn --- are the values for the latest message m such 
//      that m is stable.  That is, for each m', m'.source = source and m'.dest = m.dest,
//      m'.ssn < m.ssn, m' is stable.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void Egida::SetStableRecdMsg(int dest, int rsn, int source, int ssn)
{
  stableRecdMsg[source] = ssn;
  // Now, it is safe to garbage collect.
  SendGarbageCollectMsg(source);

  // shouldn't clean sentLog here ... 
  // since one should clean the sentLog based on somebody else's checkpoint
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Garbage collect logged data.
// 
// Arguments:
// 	source --- process that sent the gc message
//      msg --- buffer which specifies the data to be gc'ed.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void Egida::GarbageCollect(int source, int tag, const char *msg, 
			   int msgSize)
{
  std::istrstream is(msg, msgSize);
  int stableEventId, stableSsn;

  is >> stableEventId;
  is >> stableSsn;
  detLog->GarbageCollect(source, stableEventId);
  // discard the messages from the sent log.
  sentLog->GarbageCollect(id, stableSsn, source);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Process the data piggybacked on an application message
// 
// Arguments:
// 	pb, pbSize --- piggybacked info/size
//      ssn --- output parameter 
// 
// Results:
// 	ssn --- for messages, the send sequence number
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
bool Egida::ProcessPiggyback(char *pb, int pbSize, int *ssn)
{
  int dest, src, pbCkptBufSize, pbLogBufSize;
  char *pbCkptBuf, *pbLogBuf;
  
  SplitPiggyback(&dest, &src, ssn,
		       pb, pbSize,
		       &pbCkptBuf, &pbCkptBufSize, &pbLogBuf, &pbLogBufSize);
  if (DuplicateMsg(src, *ssn)) {
    std::cout << id << " Got duplicate from: " << src << ' ' << *ssn << std::endl;
    return false;
  }
      
  // after processing the piggyback, if the logging protocol says
  // don't deliver the message, then, return false.
  if (!pbLog->ProcessPiggyback(src, *ssn, pbLogBuf,
				     pbLogBufSize))
    return false;

  pbCkpt->ProcessPiggyback(src, pbCkptBuf, pbCkptBufSize);
  
  return true;
  
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Discard non-deliverable messages from the queue of incoming
// 	messages.  This method is called at the end of recovery.
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

void Egida::RemoveNonDeliverableMsgs()
{
  int i, ssn;
  int source, tag;
  char *pb, *msg;
  int pbSize, msgSize;
  EventInfo *tempInfo;
  EventInfo_List temp_List;
  EventInfo_ListIterator e;

  for (i = 0; i < numProcs; i++) {
    source = i;
    while (1) {
      msg = pb = NULL;
      msgSize = pbSize = 0;
      tag = -1;

      incomingMsgQ->Dequeue(&source, &tag, &pb, &pbSize);
      if (pb == NULL)
	break;
      while (1) {
	incomingMsgQ->Dequeue(&source, &tag, &msg, &msgSize);
	if (msg == NULL) {
	  Communication::DrainMsgs();
	  continue;
	}
	else
	  break;
      }
      if (IsDeliverable(pb, pbSize, &ssn)) {
	tempInfo = new EventInfo(id, -1, source, ssn, pb,
				 pbSize, msg, msgSize);
	temp_List.push_front(tempInfo);
      }
      else {
	std::cout << "Discarding non-deliverable from: " << source <<
	  ' ' << ssn << std::endl;
	p4_msg_free(pb);
	p4_msg_free(msg);
      }
    }

    // put back all the deliverables 
    for (e = temp_List.begin(); e != temp_List.end(); ++e) {
      tempInfo = *e;
      GetMsgTag(tempInfo->pb, &tag);
      incomingMsgQ->Prepend2(tempInfo->otherProc, tag,
				  tempInfo->pb, tempInfo->pbSize,
				  tempInfo->info, tempInfo->infoSize);
      tempInfo->info = NULL;
      tempInfo->pb = NULL;
      tempInfo->infoSize = tempInfo->pbSize = 0;
      delete tempInfo;
    }
    temp_List.clear();
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Determine if the message can be replayed during recovery.
// 
// Arguments:
// 	pb, pbSize --- piggybacked info/size
//      ssn --- output parameter 
// 
// Results:
// 	ssn --- for messages, the send sequence number
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
bool Egida::IsDeliverable(char *pb, int pbSize, int *ssn)
{
  int dest, src, pbCkptBufSize, pbLogBufSize;
  char *pbCkptBuf, *pbLogBuf;
  
  SplitPiggyback(&dest, &src, ssn,
		       pb, pbSize,
		       &pbCkptBuf, &pbCkptBufSize, &pbLogBuf, &pbLogBufSize);
  if (DuplicateMsg(src, *ssn)) {
    //got duplicate msg
    return false;
  }
      
  // after looking at the piggyback, if the logging protocol says
  // don't deliver the message, then, return false.
  if (!pbLog->IsDeliverable(src, *ssn, pbLogBuf,
					pbLogBufSize))
    return false;
  return true;
  
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Called for handling the message with type: EGIDA_GET_LAST_RECD_MSG
// 
// Arguments:
// 	source --- id of the process that wants to know the last
// 	           message it has sent to this process
//      ssn --- output parameter
// 
// Results:
// 	ssn --- is the ssn of the last message received from source
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::GetLastRecdMsg(int source, int *ssn)
{
  *ssn = lastMsgRecd[source];
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Called for handling the message with type:
// 	EGIDA_RESP_LAST_RECD_MSG.  This will happen during
// 	recovery since we are doing sender-based suppressing of
// 	duplicates, i.e., if a message is going to be discarded as a
// 	duplicate, then don't send it.  To know the duplicates, a
// 	process i needs to know from each process j the ssn of the
// 	last message i sent to j.
// 
// Arguments:
// 	source --- id of the process that wants to know the last
// 	           message it has sent to this process
//      ssn --- id of the last message source received from this process
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::UpdateLastSentMsg(int source, int ssn)
{
  lastMsgSent[source] = ssn;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Called for updating the last message recd by this process from 
// 	process source.
// 
// Arguments:
// 	source, ssn: obvious meanings
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::UpdateLastRecdMsg(int source, int ssn)
{
  if (lastMsgRecd[source] < ssn)
    lastMsgRecd[source] = ssn;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Combine the piggyback data from logging and checkpointing
// 	protocols into a single buffer.
// 
// Arguments:
// 	All of them have the obvious meanings.
//      pb --- is the resulting buffer for which space will be
//      allocated (in a p4_buffer) by this method
// 
// Results:
// 	pb --- buffer that contains the complete piggybacked
// 	       information.  The caller of this function is 
//             responsible for freeing the buffer by calling p4_free().
// 
//      pbSize --- size of the piggybacked data 
//
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::MergePiggyback(int dest, int sendTag, int source, int ssn, 
			   char **pb, int *pbSize,
			   const char *pbCkptBuf, int pbCkptBufSize,
			   const char *pbLogBuf, int pbLogBufSize)
{
  char *buf;
  int start, padLog, padCkpt;

  padLog = padCkpt = 0;

  if (pbCkptBufSize % sizeof(int) != 0)
    padCkpt = sizeof(int) - (pbCkptBufSize % sizeof(int));

  if (pbLogBufSize % sizeof(int) != 0)
    padLog = sizeof(int) - (pbLogBufSize % sizeof(int));

  *pbSize = EGIDA_FIXED_HEADER + pbCkptBufSize + pbLogBufSize + padLog + padCkpt;
  *pb = p4_msg_alloc(*pbSize);
  buf = *pb;

  // memset(buf, 0, *pbSize);
  memcpy(buf + EGIDA_FIXED_HEADER_DEST, &dest, sizeof(int));
  memcpy(buf + EGIDA_FIXED_HEADER_SOURCE, &source, sizeof(int));
  memcpy(buf + EGIDA_FIXED_HEADER_SSN, &ssn, sizeof(int));
  memcpy(buf + EGIDA_FIXED_HEADER_TAG, &sendTag, sizeof(int));
  memcpy(buf + EGIDA_FIXED_HEADER_CKPT_SIZE, &pbCkptBufSize,
	 sizeof(int));
  if (pbCkptBufSize > 0) {
    start = EGIDA_FIXED_HEADER;
    memcpy(buf + EGIDA_FIXED_HEADER_CKPT_START, &start,
	   sizeof(int));
    memcpy(buf + start, pbCkptBuf, pbCkptBufSize);
  }
  memcpy(buf + EGIDA_FIXED_HEADER_LOG_SIZE, &pbLogBufSize, sizeof(int));
  if (pbLogBufSize > 0) {
    start = EGIDA_FIXED_HEADER + pbCkptBufSize + padCkpt;
    memcpy(buf + EGIDA_FIXED_HEADER_LOG_START, &start,
	   sizeof(int));
    memcpy(buf + start, pbLogBuf, pbLogBufSize);
  }

  //we no longer need the individual buffers so delete them.
  delete [] pbLogBuf;
  delete [] pbCkptBuf;
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Does the inverse of merge.
// 
// Arguments:
// 	All of them have the obvious meanings.
//      pbCkptBuf, pbLogBuf --- are pointers to data inside pb.
//           The caller SHOULD NOT free pbCkptBuf, pbLogBuf.
//      pb --- Can't declare this as const char * --> compiler
//      complains when we set pbCkptBuf = pb + ... 
//
// Results:
//      The piggybacked information is appropriately filled in to each 
//      of the values.
//
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::SplitPiggyback(int *dest, int *source, int *ssn, 
			   char *pb, int pbSize,
			   char **pbCkptBuf, int *pbCkptBufSize,
			   char **pbLogBuf, int *pbLogBufSize)
{
  int start;

  *pbLogBuf = *pbCkptBuf = NULL;

  memcpy(dest, pb + EGIDA_FIXED_HEADER_DEST, sizeof(int));
  memcpy(source, pb + EGIDA_FIXED_HEADER_SOURCE,  sizeof(int));
  memcpy(ssn, pb + EGIDA_FIXED_HEADER_SSN, sizeof(int));
  memcpy(pbCkptBufSize, pb + EGIDA_FIXED_HEADER_CKPT_SIZE, sizeof(int));
  if (*pbCkptBufSize > 0) {
    memcpy(&start, pb + EGIDA_FIXED_HEADER_CKPT_START, 
	   sizeof(int));
    *pbCkptBuf = pb + start;
  }
  memcpy(pbLogBufSize, pb + EGIDA_FIXED_HEADER_LOG_SIZE, sizeof(int));
  if (*pbLogBufSize > 0) {
    memcpy(&start, pb + EGIDA_FIXED_HEADER_LOG_START, 
	   sizeof(int));
    *pbLogBuf = pb + start;
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve the tag assigned by Egida to an application message.
// 
// Arguments:
// 	pb --- piggyback of the message whose tag has to be retrieved
//      tag --- output parameter
// 
// Results:
// 	tag --- of the message which has the pb that is passed in.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::GetMsgTag(const char *pb, int *tag)
{
  memcpy(tag, pb + EGIDA_FIXED_HEADER_TAG, sizeof(int));
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve the ssn assigned by Egida to an application message.
// 
// Arguments:
// 	pb --- piggyback of the message whose tag has to be retrieved
//      ssn --- output parameter
// 
// Results:
// 	ssn --- of the message which has the pb that is passed in.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::GetMsgSsn(const char *pb, int *ssn)
{
  memcpy(ssn, pb + EGIDA_FIXED_HEADER_SSN, sizeof(int));
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve the source/tag assigned by Egida to an application message.
// 
// Arguments:
// 	pb --- piggyback of the message whose tag has to be retrieved
//      src, tag --- output parameter
// 
// Results:
//      src --- id of the process which sent the pb that is passed in.
// 	tag --- of the message which has the pb that is passed in.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::GetMsgSrcTag(const char *pb, int *src, int *tag)
{
  memcpy(src, pb + EGIDA_FIXED_HEADER_SOURCE, sizeof(int));
  memcpy(tag, pb + EGIDA_FIXED_HEADER_TAG, sizeof(int));
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Fetches only the data piggybacked by the logging protocol.
// 
// Arguments:
//      pb -- buffer that was created in MergePiggyback
//      pbLogBuf --- output parameter and will be a  pointer to data
//                inside pb.  As always, the caller SHOULD NOT delete
//                pbLogBuf pointer. 
//      pbLogBufSize --- size of data in the pbLogBuf buffer.
// 
// Results:
//      The piggybacked information is appropriately filled in to each 
//      of the values.
//
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::FetchPiggybackLog(char *pb, char **pbLogBuf, int *pbLogBufSize)
{
  int start;

  *pbLogBuf = NULL;

  memcpy(pbLogBufSize, pb + EGIDA_FIXED_HEADER_LOG_SIZE, sizeof(int));
  if (*pbLogBufSize > 0) {
    memcpy(&start, pb + EGIDA_FIXED_HEADER_LOG_START, 
	   sizeof(int));
    *pbLogBuf = pb + start;
  }
}

void Egida::ProcessGetLastControlMsgReq(int source)
{
  int resp[3];

  GetLastRecdMsg(source, &resp[0]);
  pbLog->GetLastAckSent(source, &resp[1]);
  resp[2] = stableRecdMsg[source];
  Communication::SendMsg(source, EGIDA_RESP_LAST_CONTROL_MSG,
			 (char *) resp, 3 * sizeof(int));
}

void Egida::ProcessGetLastControlMsgResp(int source, const char *msg)
{
  int *resp = (int *) msg;

  UpdateLastSentMsg(source, resp[0]);
  pbLog->UpdateLastAckRecd(source, resp[1]);
  pbLog->UpdateAvoidLoggingMsg(source, resp[2]);
}

int Egida::SendLastControlMessages()
{
  int status = 0;
  for (int i = 0; i < numProcs; i++) {
    if (Communication::SendMsg(i, EGIDA_GET_LAST_CONTROL_MSG, NULL, 0) < 0)
      status = -1;
  }
  return status;
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Execute egida level actions before roll-forward phase of
// 	recovery begins.
// 
// Arguments:
// 	rolledback --- a boolean to indicate that the process is
// 	starting roll-forward after a rollback.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::DoRecovery(bool rolledback)
{
  struct timeval startTime, endTime;
  double timeSpent;
  int i;

  if(COLLECTING_STATS) {
    gettimeofday(&startTime, NULL);
  }
  
  std::cout << GetMyId() << ": Collecting recovery info..." << std::endl;
  
  failedOnce = true;
  isRecovering = true;
  replayMsgAvail = true;

  msgPoll->PrepareForReplay(esn);

  detLog->RestartingFromCkpt();
  deliveredLog->RestartingFromCkpt();
  sentLog->RestartingFromCkpt();
  
  // Order here is important
  for (i = 0; i < numProcs; i++) {
    // if (i == id)
    //  continue;
    // Ask each process to send back control messages---look at the
    // code in ProcessIncomingMsg() to know what is coming back.
    Communication::SendMsg(i, EGIDA_GET_LAST_CONTROL_MSG, NULL, 0);
  }

  recovery->DoRecovery(esn, rolledback);
  
  if(COLLECTING_STATS) {
    gettimeofday(&endTime, NULL);
    Timer::ComputeTimeDiff(&timeSpent, startTime, endTime);
    Stats::Update(EGIDA_RECOVERY_PRE_ROLL_FORWARD_STAT, 0, timeSpent);
    gettimeofday(&replayStartTime, NULL);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Rollback the process state to a previous checkpoint.
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
void Egida::Rollback()
{
  char rollbackFile[EGIDA_FILENAME_LEN];
  std::ostrstream os;

  Communication::RollbackActions();  

  // stop the timer
  Timer::Terminate();

  rollbackActions->RbActions();

  // get the name of the checkpoint file to rollback to
  if (!pbLog->GetRollbackFile(rollbackFile))
    ckptProtocol->GetRollbackFile(rollbackFile);

  // Need to tell the failuredetector that we are going to be rolling
  // back.
  FailDetect::SendRollbackMsg(rollbackFile);


  // do the rollback.  the last argument "true" is used to signify
  // that this process has been rolled back.
  Communication::Reconnect();
  howToCkpt->RestoreCkpt(rollbackFile, true);

  //we won't get back after this....
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Replay a message deliver event during recovery.
// 
// Arguments:
// 	source, tag: input/output parameters
//           If there is a message for replay, then, source, tag will
//           be modified to reflect the value of the message that is
//           returned; otherwise, source/tag are unmodified.
//       pb, pbSize: output parameters for the result of this method.
//       msg, msgSize: output parameters for the result of this method.
// 
// Results:
// 	pb, msg --- if non-NULL, then, it is a piggyback/an
// 	  application message, respectively, stored in a p4 buffer.  
//        It is the responsibility of the caller to
// 	  free the buffer by calling p4_msg_free.
//      msgSize, source, tag --- will be modified to reflect the message that
//        is being returned.
//      Returns true if there is a message to replay; false otherwise.
//
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

bool Egida::ReplayDeliver(int *source, int *tag,
			  char **pb, int *pbSize,
			  char **msg, int *msgSize)
{
  Determinant *replayDet = NULL, *nextDet = NULL;
  char *replayMsg = NULL, *replayPb = NULL;
  int ssn, replaySource, replayTag = -1, replayMsgSize, replayPbSize;
  EventInfo *tempInfo = NULL;
  struct timeval startTime, endTime;
  double timeSpent;
  
  if(COLLECTING_STATS) {
    gettimeofday(&startTime, NULL);
  }
  replayMsgSize = replayPbSize = 0;  
  detLog->Retrieve(id, esn + 1, &replayDet);

  if(COLLECTING_STATS) {
    gettimeofday(&endTime, NULL);
    Timer::ComputeTimeDiff(&timeSpent, startTime, endTime);
    Stats::Update(EGIDA_RECOVERY_DETLOG_RETRIEVE_STAT, 0, timeSpent);
  }

  if (replayDet == NULL) {
    return false;
  }

  // Try and retrieve the data from the logs
  deliveredLog->Retrieve(replayDet->dest, replayDet->d_esn,
			       replayDet->source, &tempInfo);
  if (tempInfo) {
    // remove any pointers that delivered log may have to info that is 
    // to be replayed.
    deliveredLog->RemovePtr(tempInfo);
    replaySource = replayDet->source;
    replayPb = tempInfo->pb;
    replayPbSize = tempInfo->pbSize;
    replayMsg = tempInfo->info;
    replayMsgSize = tempInfo->infoSize;
    GetMsgTag(tempInfo->pb, &replayTag);
  }
  else {
    while (1) {
      if (GetReplayMsgFromQ(replayMsgQ, replayDet,
				  &replaySource, &replayTag,
				  &replayPb, &replayPbSize,
				  &replayMsg, &replayMsgSize))
	break;
      if (GetReplayMsgFromQ(incomingMsgQ, replayDet,
				  &replaySource, &replayTag,
				  &replayPb, &replayPbSize,
				  &replayMsg, &replayMsgSize))
	break;

      Communication::DrainMsgs();
    }
  }

  // pull out any messages from the network
  Communication::DrainMsgs();

  if(COLLECTING_STATS) {
    gettimeofday(&startTime, NULL);
  }

  if (IsDeliverable(replayPb, replayPbSize, &ssn)) {
    *source = replaySource;
    *tag = replayTag;
    *pb = replayPb;
    *pbSize = replayPbSize;
    *msg = replayMsg;
    *msgSize = replayMsgSize;

    if(COLLECTING_STATS) {
      gettimeofday(&endTime, NULL);
      Timer::ComputeTimeDiff(&timeSpent, startTime, endTime);
      Stats::Update(EGIDA_RECOVERY_PB_PROC_STAT, 0, timeSpent);
    }
    return true;
  }
  else {
    // replay is done..
    p4_msg_free(replayPb);
    p4_msg_free(replayMsg);
    *pb = *msg = NULL;
    *pbSize = *msgSize = 0;
    return false;
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Fetch the message that matches the determinant that has to be
// 	replayed from a message queue.
// 
// Arguments:
// 	msgQ --- queue from which the message has to be fetched.
//      replayDet --- the determinant that is to be replayed
//      source, tag, pb, pgSize, msg, msgSize --- are output parameters
// 
// Results:
// 	source, tag, pb, pgSize, msg, msgSize --- are the usual values 
// 	   that define everything about a message.
//      This method returns TRUE on success; FALSE on failure.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

bool Egida::GetReplayMsgFromQ(MsgQueue *msgQ, 
			      const Determinant *replayDet,
			      int *source, int *tag, 
			      char **pb, int *pbSize,
			      char **msg, int *msgSize)
{
  int ssn, tempTag;
  EventInfo_List temp_List;
  EventInfo_ListIterator e;
  EventInfo *tempInfo;

  *pb = *msg = NULL;
  *msgSize = *pbSize = 0;
  
  while (1) {
    *source = replayDet->source;
    *tag = -1;
    msgQ->Dequeue(source, tag, pb, pbSize);
    if (*pb == NULL) {
      break;
    }
    
    while (1) {
      msgQ->Dequeue(source, tag, msg, msgSize);
      if (*msg == NULL) {
	Communication::DrainMsgs();
	continue;
      }
      else
	break;
    }
    GetMsgSsn(*pb, &ssn);
    if (ssn == replayDet->s_esn)
      // got the one we are looking for
      break;
    tempInfo = new EventInfo(id, -1,
			     *source, ssn, *pb, *pbSize, *msg, *msgSize);
    *pb = *msg = NULL;
    *msgSize = *pbSize = 0;
			     
    // keep this in a temporary list.  What is pushed into this list
    // first is the message that has to be pushed back into the front
    // of the incoming message queue.
    temp_List.push_front(tempInfo);
  }
  // take each message in the list and push it to the front of the
  // queue of incoming messages.
  for (e = temp_List.begin(); e != temp_List.end(); ++e) {
    tempInfo = *e;
    GetMsgTag(tempInfo->pb, &tempTag);
    msgQ->Prepend2(tempInfo->otherProc, tempTag,
		  tempInfo->pb, tempInfo->pbSize,
		  tempInfo->info, tempInfo->infoSize);
    tempInfo->info = NULL;
    tempInfo->pb = NULL;
    tempInfo->infoSize = tempInfo->pbSize = 0;
    delete tempInfo;
  }
  temp_List.clear();
  return (*pb != NULL);
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Check if the message to be delivered is a duplicate
// 
// Arguments:
// 	pb --- data piggybacked on the application message
// 
// Results:
// 	true if message is duplicate; false otherwise
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
bool Egida::DuplicateMsg(int source, int ssn)
{
  assert((0 <= source) && (source < numProcs));
  assert(ssn < EGIDA_MAX_APPL_MSGS);
  return msgsDelivered[source][ssn];
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Collect "lost" messages---these are messages that were sent to 
// 	this process when this process was recovering.
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

void Egida::CollectLostMsgs()
{
  int i, lastMsg;

  for (i = 0; i < numProcs; i++) {
    if (i != id) {
      // Out of order delivery of message is causing havoc.  Have to
      // change ssn's to per process ssn.
      lastMsg = lastMsgDelivered[i] - 20;
      SendControlMsg(i, EGIDA_COLLECT_LOST_MSG,
			   (char *) &(lastMsg),
			   sizeof(int));
    }
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Re-send lost messages.  This method is the handler for
// 	processing EGIDA_COLLECT_LOST_MSG.
// 
// Arguments:
// 	source --- process asking for lost messages
//       tag --- better be EGIDA_COLLECT_LOST_MSG
//       msg --- contains the ssn of the last message received by
//       process source from this process.
// 
// Results:
// 	NONE returned.  Sends to process source message m such that
// 	m.ssn > the ssn sent in msg.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::ResendMsgs(int source, int tag, const char *msg,
		       int msgSize)
{
  int lastMsg = *(int *) msg;
  int mTag, ssn;
  EventInfo_List msgList;
  EventInfo_ListIterator e;
  EventInfo *m;

  assert(tag == EGIDA_COLLECT_LOST_MSG);
  
  sentLog->Retrieve(id, lastMsg, source, &msgList);
  for (e = msgList.begin(); e != msgList.end(); ++e) {
    m = *e;
    GetMsgTag(m->pb, &mTag);
    GetMsgSsn(m->pb, &ssn);
    if (ssn <= lastMsg)
      continue;
    Communication::SendMsg(source, mTag, m->pb, m->pbSize);
    Communication::SendMsg(source, mTag, m->info, m->infoSize);
  }
  msgList.clear();
}



// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Internal function called from other Egida modules for sending
// 	Egida control messages to other processes.
// 
// Arguments:
//      tag  --- Egida assigned tag to the message
//      msg, msgSize --- obvious meaning.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::SendControlMsg(int dest, int tag, char *msg, int msgSize)
{
  if (isInitialized) {
    Communication::SendMsg(dest, tag, msg, msgSize);
  }
  else {
    // Should not call here if Egida is not initialized.
    assert(0);
  }
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	This method lets each Egida object know that a timer interrupt 
// 	has occurred.
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

void Egida::TimerExpired()
{
  if (disableTimer)
    return;

  recovery->TimerExpired();
  howToCkpt->TimerExpired();
  sentLog->TimerExpired();
  deliveredLog->TimerExpired();
  detLog->TimerExpired();
  pbLog->TimerExpired();
  ckptProtocol->TimerExpired();
}



// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	This method gets called whenever 
// 	the state of the process is restored from the checkpoint.
// 
// Arguments:
// 	rollback --- This argument was passed to checkpoint
// 	   implementation module's RestoreCkpt and that module is handing 
// 	   back that argument.
// 	   
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::RestoreDone(int rollback)
{
  struct timeval startTime, endTime;
  double timeSpent;

  if(COLLECTING_STATS) {
    gettimeofday(&startTime, NULL);
  }

  // Re-setup the timer 
  Timer::Initialize();

  //  std::cout << Egida::GetMyId() << " Waiting : Attach Debugger" << std::endl;
  //  sleep(30);

  // First connect up with every process
  p4_DoRecovery();

  FailDetect::Resetup_FailureDetector();
  
  if(COLLECTING_STATS) {
    gettimeofday(&endTime, NULL);
    Timer::ComputeTimeDiff(&timeSpent, startTime, endTime);
    Stats::Update(EGIDA_RECOVERY_ROLL_BACK_OVERHEAD_STAT, 0, timeSpent);
  }
  
  std::cout << "Time spent from restore done to p4's recovery done: "
	    << timeSpent << std::endl;

  //  std::cout << "Waiting : Attach the debugger " << std::endl;
  //  sleep(30);
  
  // Do the recovery actions
  DoRecovery(rollback);
  Timer::RollForwardStart();
  Timer::AppStart();
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Handler for processing messages retrieved from the socket.  
//      The handler assumes that TimerInterrupt has already been blocked.
// 
// Arguments:
// 	source --- process that sent the message
//      tag --- Egida tag of the message assigned by source
//      msg, msgSize --- message in a p4 buffer and its size.  
//      The caller of this method SHOULD NOT refer to msg after this call.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::ProcessIncomingMsg(int source, int tag, 
			      char *msg, int msgSize)
{
  char *data = NULL;
  int dataSize = 0;
  int ssn = 0;

  // wait until egida is initialized
  while (!isInitialized) {
    std::cout << "waiting for egida to be initialized" << std::endl;
    std::cout.flush();
    sleep(1);
  }

  if ((0 <= tag) && (tag <= EGIDA_MAX_TAG)) {
    // Is an egida control message
    switch(tag) {
    case EGIDA_CKPT_PROTOCOL_MSG:
      ckptProtocol->ProcessMsg(source, tag, msg, msgSize);
      break;
    case EGIDA_DET_LOG_MSG:
      detLog->ProcessMsg(source, tag, msg, msgSize);
      break;
    case EGIDA_DELIVERED_LOG_MSG:
      deliveredLog->ProcessMsg(source, tag, msg, msgSize);
      break;
    case EGIDA_SENT_LOG_MSG:
      sentLog->ProcessMsg(source, tag, msg, msgSize);
      break;
    case EGIDA_LOG_PROTOCOL_MSG:
      pbLog->ProcessMsg(source, tag, msg, msgSize);
      break;
    case EGIDA_GARBAGE_COLLECT_MSG:
      //      std::cout << GetMyId() << " Garbage Collect called " << std::endl;
      GarbageCollect(source, tag, msg, msgSize);
      break;
    case EGIDA_RECOVERY_MSG:
      recovery->ProcessMsg(source, tag, msg, msgSize);
      break;
    case EGIDA_ORPHAN_DETECTION_MSG:
      //      std::cout << GetMyId() << " : Orphan Detection message from " << source << std::endl;
      //      sleep(30);
      orphanDetection->ProcessMsg(source, tag, msg, msgSize);
      break;
    case EGIDA_COLLECT_LOST_MSG:
      ResendMsgs(source, tag, msg, msgSize);
      break;
    case EGIDA_GET_LAST_CONTROL_MSG:
      ProcessGetLastControlMsgReq(source);
      break;
    case EGIDA_RESP_LAST_CONTROL_MSG:
      ProcessGetLastControlMsgResp(source, msg);
      break;
    default:
      std::cout << "unknown message type: " << tag << std::endl;
      assert(0); 
    }
    p4_msg_free(msg);
  }
  else {

    int checkFrom = source, checkTag = tag;
    if(!p4_messages_available(&checkTag, &checkFrom)) {
      sleep(1);
      checkFrom = source;
      checkTag = tag;
      if(!p4_messages_available(&checkTag, &checkFrom)) {
	sleep(2);
	checkFrom = source;
	checkTag = tag;
	if(!p4_messages_available(&checkTag, &checkFrom)) {
	  sleep(10);
	  checkFrom = source;
	  checkTag = tag;
	  if(!p4_messages_available(&checkTag, &checkFrom)) {
	    return;
	  }
	}
      }
    }

    // Is an application message.  What is passed in is the header.  
    // Fetch the message content and then put it in the queue.
    if (Communication::RecvMsg(&source, &tag, &data, &dataSize) < 0) {
      std::cout << id << " Detected a dead connection to: " << source << std::endl; 
      p4_msg_free(msg);
    }
    else {
      if (IsDeliverable(msg, msgSize, &ssn)) {
	UpdateLastRecdMsg(source, ssn);
	incomingMsgQ->Enqueue2(source, tag, msg, msgSize,
						 data, dataSize);
      }
      else {
	p4_msg_free(msg);
	p4_msg_free(data);
      }
    }
  }
}



// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Update the id of the last message received by this process
// 	from the remaining processes.
// 
// Arguments:
// 	lastMsgs[i]---is the ssn of the last message recd. by this
// 	process from process i
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::UpdateMsgsRecd(const int *lastMsgs)
{
  for (int i = 0; i < numProcs; i++)
    UpdateLastRecdMsg(i, lastMsgs[i]);
}


// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Enqueue an application message that is received during the
// 	phase of recovery in which this process is collecting the
// 	messages that have to be replayed.
// 
// Arguments:
// 	source --- process that is sending the message.
//      tag --- Egida assigned tag to the application message.
//      pb, pbSize, msg, msgSize --- have the obvious meanings.
// 
// Results:
// 	NONE.  The caller of this method SHOULD NOT maintain any
// 	reference to pb/msg after this method call.  It is also
// 	assumed that the storage for pb/msg is allocated thru p4.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::EnqueueReplayMsg(char *pb, int pbSize,
			    char *msg, int msgSize)
{
  int source, tag;
  int ssn;

  GetMsgSrcTag(pb, &source, &tag);
  GetMsgSsn(pb, &ssn);
  UpdateLastRecdMsg(source, ssn);
  replayMsgQ->Enqueue2(source, tag, pb, pbSize, msg, msgSize);
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Mark the current state as "stable".  The information recorded
// 	as "stable" can be used to initiate garbage collection.
// 
// Arguments:
// 	NONE --- Records the current esn and the current set of
// 	received messages as stable. 
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida::SetStateStable()
{
  SetStableEsn();
  SetStableRecdMsg();
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Gracefully crash the application process.
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

void Egida::InternallyFail()
{

  if (failedOnce) {
    disableTimer = false;
    return;
  }

  // Crash the process if it has not failed once already.
  pbLog->PrepareForCrash();
  ckptProtocol->PrepareForCrash();

  Timer::AppEnd();
  std::cout << "Parent is failing intentionally..." << std::endl;
  std::cout.flush();
  _exit(0);
}
