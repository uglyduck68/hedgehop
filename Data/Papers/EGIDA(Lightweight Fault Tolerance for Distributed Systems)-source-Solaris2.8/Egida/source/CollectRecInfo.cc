// CollectRecInfo.cc -- 
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
// $Log: CollectRecInfo.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:19  ravshank
// Start of Spring 2001
//
// Revision 1.8  2000/11/01 16:35:26  phoebe
// Working on getting security to work again with the redesigned system. Message encryption, either full or only egida messages, is working now.
//
// Revision 1.7  2000/08/08 14:28:52  phoebe
// Can now restart multiple times and kill the master process for Receiver Based Pessimistic logging. Same thing for Sender Based, but with sender based since the recovery logs must be in volatile memory, it will eventually run out of RAM and won't be able to continue or restart (obviously). This is a protocol design bug that will be fixed, but the restart is stable. Also able to restart from an incremental checkpoint (tested with RBP). These restart tests were done without any security turned on.
//
// Revision 1.6  2000/06/26 21:31:05  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.5  2000/06/26 19:09:51  phoebe
// Removed all wrapper methods out of Egida_Internal.cc and renamed calls in code to directly call the Egida::Method that would have been called by the Egida_Method call.
//
// Revision 1.4  2000/06/26 16:56:53  phoebe
// Made all the Egida_Object methods and members static. Also moved GetMyId and GetNumProcs out of Egida_Internal and into Egida_Object.
//
// Revision 1.3  2000/06/23 02:47:31  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.2  2000/06/22 20:58:57  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.1.1.1  2000/03/06 20:00:17  phoebe
// Sriram's original code with no modifications
//
// $Id: CollectRecInfo.cc,v 1.1.1.1 2001/02/12 00:00:19 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun May  9 16:01:13 1999
// Last Modified By: Sriram Rao
// Last Modified On: Wed Aug 18 13:54:46 1999
// Update Count    : 78
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <iostream>
#include <strstream>

#include "CollectRecInfo.H"
#include "Communication.H"
#include "Egida_Object.H"
#include "Timer.H"

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve the determinants and messages needed for the replay
// 	phase of recovery of this process.
// 
// Arguments:
// 	retrieveStartEventId --- event # from which dets. have to be
// 	   retrieved, i.e., dets d such that d.dest = this process and 
// 	   d.d_esn >= retrieveStartEventId
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void CollectRecInfo::Retrieve(int retrieveStartEventId)
{
  int i, myId = Egida::GetMyId();
  int numProcs = Egida::GetNumProcs();

  this->detLog->Retrieve(myId, retrieveStartEventId, &(this->lastDetRetrieved));
  this->eventLog->Retrieve(myId, retrieveStartEventId, this->lastEventIdRetrieved);

  Egida::UpdateMsgsRecd(this->lastEventIdRetrieved);
  for (i = 0; i < numProcs; i++)
    Egida::SetStableRecdMsg(i, this->lastEventIdRetrieved[i]);

  // This is only for the Optimistic protocol. Ensure that it is not used for
  // other protocols
#if 0
  for (int index = 0; index < numProcs; index++)
    Egida::ProcessGetLastControlMsgReq(index);
#endif

  memset(this->recdRecoveryRespBegin, false, numProcs * sizeof(bool));
  memset(this->recdRecoveryRespEnd, false, numProcs * sizeof(bool));

  this->recdRecoveryRespBegin[myId] =
    this->recdRecoveryRespEnd[myId] = true; 

  this->collectingRecInfo = true;

  SendCollectRecInfoMsg();
  // set the timer...
  Timer::SetTimer(60);

  WaitForHelpResp(numProcs);

  // now process all the determinants that were sent with the recovery 
  // begin info message.
  ProcessRecoveryBeginInfo(numProcs);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Wait until all the remaining process have sent an
// 	EGIDA_RECOVERY_RESPONSE_END message.
// 
// Arguments:
// 	numProcs --- # of processes to wait for.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void CollectRecInfo::WaitForHelpResp(int numProcs)
{
  bool done;
  int i;

  while (1) {
    done = true;
    for (i = 0; i < numProcs; i++) 
      if (!this->recdRecoveryRespEnd[i]) {
	done = false;
	break;
      }
    if (done) {
      this->collectingRecInfo = false;
      //received help from all processes
      break;
    }
    Communication::WaitForMsgs();
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Process the determinants that were piggybacked on the
// 	RECOVERY_BEGIN_INFO message.  This method is called AFTER all
// 	the stuff is collected, so that processing won't be in the
// 	critical path.
// 
// Arguments:
// 	numProcs --- # of processes in the application
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void CollectRecInfo::ProcessRecoveryBeginInfo(int numProcs)
{
  int detIds[EGIDA_MAX_PROCS];
  char *msg;
  int i, msgSize;
  MsgBufSize_ListIterator e;
  MsgBufSize *m;

  // process all the determinants
  for (i = 0; i < numProcs; i++) {
    for (e = this->helpBegin_List[i].begin(); e !=
	   this->helpBegin_List[i].end(); ++e) {
      m = *e;
      msg = m->first;
      msgSize = m->second;
      this->detLog->Log(i, msg, msgSize, detIds);
      p4_msg_free(msg);
      delete m;

    }
    this->helpBegin_List[i].clear();
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Used for periodically sending out a collect recovery info
// 	message.  Re-sends are needed because this messsage may get lost if 
// 	the receiving process crashes.
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

void CollectRecInfo::SendCollectRecInfoMsg()
{
  int myId = Egida::GetMyId();
  int numProcs = Egida::GetNumProcs();
  int i;
  std::ostrstream os;

  for (i = 0; i < numProcs; i++) {
    if (this->recdRecoveryRespEnd[i])
      continue;

    os << EGIDA_HELP_RECOVERY << ' ' << myId << ' ' << i << ' ';
    os << this->lastDetRetrieved << ' ' << this->lastEventIdRetrieved[i] << std::ends;

    Egida::SendControlMsg(i, EGIDA_RECOVERY_MSG, os.str(), os.pcount());
    // reset the pointer to the beginning of the buffer
    os.rdbuf()->pubseekoff(0, std::ios::beg, std::ios::out);
    // unfreeze the buffer so that it will get freed when the os'es
    // destructor runs.
    os.rdbuf()->freeze(false);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Handle the timer interrupts that may get generated.  In
// 	response to a timer interrupt, re-send the collect recovery
// 	info message and the set the timer to expire 5 seconds from now.
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

void CollectRecInfo::TimerExpired()
{
  int i, myId = Egida::GetMyId();
  int numProcs = Egida::GetNumProcs();

  if (!this->collectingRecInfo) 
    return;

  SendCollectRecInfoMsg();
  // If we haven't gotten a begin from some process, set a timer so
  // that we can try again.
  for (i = 0; i < numProcs; i++) {
    if (!this->recdRecoveryRespEnd[i]) {
      Timer::SetTimer(5);
      break;
    }
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Process messages received during the phase in which this
// 	process collects the data for replay.
// 
// Arguments:
// 	source --- the process that sent the message
//      actualSource, actualDest --- the "true" source/dest of this
//          message.  For this method, actualSource == source and
//          actualDest == this->id
//      msg, msgSize --- obvious meanings
// 
// Results:
// 	NONE.  
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void CollectRecInfo::ProcessMsg(int source, 
				int actualSource, int actualDest,
				const char *msg, int msgSize)
{
  int myId = Egida::GetMyId();
  int mTag, from;
  char *m1 = NULL, *m2 = NULL;
  int m1Size = 0, m2Size = 0;

  assert(source == actualSource);
  assert(actualDest == myId);

  // The protocol for sending messages during the collect phase is:
  //  Message 1: <EGIDA_RECOVERY_MSG> <actualSource> <actualDest>
  //  Message 2: EGIDA_RECOVERY_<BEGIN/END/NOTIFY/REPLAY> 
  //  Message 3: EGIDA_RECOVERY_REPLAY_MSG <msg data>
  // There will always be message 2; fetch that first and if there is
  // message 3, then that'll get fetched inside the switch statement.
  // Note that message 1 was already retrieved in
  // Egida_ProcessIncomingMsg() and that is how control ended up here.

  from = source;
  mTag = -1; // don't know what the message is going to be...
  Communication::RecvMsg(&from, &mTag, &m1, &m1Size);

  switch(mTag) {
  case EGIDA_RECOVERY_RESPONSE_BEGIN:
    this->recdRecoveryRespBegin[source] = true;
    // delay processing the determinants until all the stuff is here
    // --- look at the code in WaitForHelpResp().
    // this->detLog->Log(source, m1, m1Size, detIds);
    // p4_msg_free(m1);
    this->helpBegin_List[source].push_back(new MsgBufSize(m1,
							  m1Size));
    break;
  case EGIDA_RECOVERY_RESPONSE_END:
    this->recdRecoveryRespEnd[source] = true;
    p4_msg_free(m1);
    break;
  case EGIDA_RECOVERY_REPLAY_MSG:
    // Fetch the message
    Communication::RecvMsg(&from, &mTag, &m2, &m2Size);
    // Though it may seem that the message has to be stored with the
    // event log, however, it is incorrect. This is because at this
    // point in the recovery phase, we donot know the receive sequence 
    // number for this message.  Recall that, messages from
    // deliveredLog are retrieved by passing in the triplet: dest,
    // d_esn, and source.
    Egida::EnqueueReplayMsg(m1, m1Size, m2, m2Size);
    break;
  default:
    // should never happen
    assert(0);
    break;
  }
}
				
// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve the determinants and messages needed for the replay
// 	phase of recovery of this process.
// 
// Arguments:
// 	retrieveStartEventId --- event # from which dets. have to be
// 	   retrieved, i.e., dets d such that d.dest = this process and 
// 	   d.d_esn >= retrieveStartEventId
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void CentralizedCollectRecInfo::Retrieve(int retrieveStartEventId)
{
  int myId = Egida::GetMyId();
  int numProcs = Egida::GetNumProcs();
  struct timeval startTime, endTime;
  double timeSpent;

  this->detLog->Retrieve(myId, retrieveStartEventId, &(this->lastDetRetrieved));
  this->eventLog->Retrieve(myId, retrieveStartEventId, this->lastEventIdRetrieved);

  Egida::UpdateMsgsRecd(this->lastEventIdRetrieved);

  this->recdRecoveryRespBegin[myId] =
    this->recdRecoveryRespEnd[myId] = true; 

  this->collectingRecInfo = true;
  // one request recd from this process itself
  this->numHelpReqRecd = 1;

  ElectLeader();
  if (this->leader == myId) {
    WaitForHelpReq();
    CollectAndDistribute(numProcs);
  }
  else {
    SendHelpToLeader();
    WaitForHelpResp(numProcs);
  }

  // now process all the determinants that were sent with the recovery 
  // begin info message.
  ProcessRecoveryBeginInfo(numProcs);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Process messages received during the phase in which this
// 	process collects the data for replay.
// 
// Arguments:
// 	source --- the process that sent the message
//      actualSource, actualDest --- the "true" source/dest of this
//          message.  Since this method is part of a leader-based
//          collection protocol, actualSource/actualDest could be any
//          process in the system.
//      msg, msgSize --- obvious meanings
// 
// Results:
// 	NONE.  
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void CentralizedCollectRecInfo::ProcessMsg(int source, 
					   int actualSource, int actualDest,
					   const char *msg, int msgSize)
{
  int myId = Egida::GetMyId();
  int numProcs = Egida::GetNumProcs();
  int detIds[EGIDA_MAX_PROCS];
  int mTag, from;
  char *m1 = NULL, *m2 = NULL;
  int m1Size = 0, m2Size = 0;
  int msgTagBufSize = 32;
  char *msg_p4Buf = NULL, *msgTag_p4Buf;

  // The protocol for sending messages during the collect phase is:
  //  Message 1: <EGIDA_RECOVERY_MSG> <actualSource> <actualDest>
  //  Message 2: EGIDA_RECOVERY_<BEGIN/END/NOTIFY/REPLAY> 
  //  Message 3: EGIDA_RECOVERY_REPLAY_MSG <msg data>
  // There will always be message 2; fetch that first and if there is
  // message 3, then that'll get fetched inside the switch statement.
  // Note that message 1 was already retrieved in
  // Egida_ProcessIncomingMsg() and that is how control ended up here.

  from = source;
  mTag = -1; // don't know what the message is going to be...
  Communication::RecvMsg(&from, &mTag, &m1, &m1Size);
  std::cout << " TAG IS " << mTag << std::endl;

  // If the process for which the control message has been received
  // from source, then, make a copy of that message in a p4buffer---so 
  // that, as a leader, this process can forward the message to procId
  if (actualDest != myId) {
    assert(this->leader == myId);
    msg_p4Buf = p4_msg_alloc(msgSize);
    memcpy(msg_p4Buf, msg, msgSize);
    msgTag_p4Buf = p4_msg_alloc(msgTagBufSize);
    sprintf(msgTag_p4Buf, "%d ", mTag);
  }

  switch(mTag) {
  case EGIDA_RECOVERY_RESPONSE_BEGIN:
    if (actualDest == myId) {
      this->recdRecoveryRespBegin[actualSource] = true;
      // this->detLog->Log(actualSource, m1, m1Size, detIds);
      // p4_msg_free(m1);
      // this is similar to the code in Distributed::ProcessMsg
      this->helpBegin_List[actualSource].push_back(new MsgBufSize(m1, m1Size));
      break;
    }
    else {
      assert(this->leader == myId);
      this->helpRec_List[actualDest].push_back(new MsgBufSize(msg_p4Buf, msgSize));
      // remember the message tag!
      this->helpRec_List[actualDest].push_back(new MsgBufSize(msgTag_p4Buf, msgTagBufSize));
      this->helpRec_List[actualDest].push_back(new MsgBufSize(m1, m1Size));
    }
    break;
  case EGIDA_RECOVERY_RESPONSE_END:
    if (actualDest == myId) {
      this->recdRecoveryRespEnd[actualSource] = true;
      p4_msg_free(m1);
    }
    else {
      assert(this->leader == myId);
      this->helpRec_List[actualDest].push_back(new MsgBufSize(msg_p4Buf, msgSize));
      // remember the message tag!
      this->helpRec_List[actualDest].push_back(new MsgBufSize(msgTag_p4Buf, msgTagBufSize));
      this->helpRec_List[actualDest].push_back(new MsgBufSize(m1, m1Size));
    }
    break;
  case EGIDA_RECOVERY_NOTIFICATION:
    // This message is received only by the leader and will be
    // forwarded by the leader to actualDest.  The content of m1 is:
    // <EGIDA_HELP_RECOVERY> <actualSource> <actualDest> ...
    assert(this->leader == myId);
    assert(actualDest != myId);
    this->recAnn_List[actualDest].push_back(new MsgBufSize(m1, m1Size));
    // There is no need to forward the message that source sent.
    if (msg_p4Buf) {
      p4_msg_free(msg_p4Buf);
      p4_msg_free(msgTag_p4Buf);
    }
    break;
  case EGIDA_RECOVERY_NOTIFICATION_END:
    assert(this->leader == myId);
    this->numHelpReqRecd++;
    p4_msg_free(m1);
    break;
  case EGIDA_RECOVERY_REPLAY_MSG:
    // Fetch the message
    Communication::RecvMsg(&from, &mTag, &m2, &m2Size);

    if (actualDest == myId) {
      // Though it may seem that the message has to be stored with the
      // event log, however, it is incorrect. This is because at this
      // point in the recovery phase, we donot know the receive sequence 
      // number for this message.  Recall that, messages from
      // deliveredLog are retrieved by passing in the triplet: dest,
      // d_esn, and source.
      Egida::EnqueueReplayMsg(m1, m1Size, m2, m2Size);
    }
    else {
      assert(this->leader == myId);

      this->helpRec_List[actualDest].push_back(new MsgBufSize(msg_p4Buf, msgSize));
      // remember the message tag!
      this->helpRec_List[actualDest].push_back(new MsgBufSize(msgTag_p4Buf, msgTagBufSize));
      this->helpRec_List[actualDest].push_back(new MsgBufSize(m1, m1Size));
      this->helpRec_List[actualDest].push_back(new MsgBufSize(m2, m2Size));
    }
    break;
  default:
    // should never happen
    assert(0);
    break;
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	This method is called by the recovery leader.
//      Wait until the concurrently recovering processes send
// 	information about the messages/determinants that have to be
// 	collected on their behalf.
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
void CentralizedCollectRecInfo::WaitForHelpReq()
{
  while (1) {
    if (this->numHelpReqRecd >= this->numFailures)
      break;
    Communication::WaitForMsgs();
  }
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	This method is executed by the recovery leader.  In this
// 	method, the leader collects the information needed for the
// 	recovery of other concurrently failed processes and then
// 	distributes that information.
// 
// Arguments:
// 	numProcs --- # of processes in the system
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void CentralizedCollectRecInfo::CollectAndDistribute(int numProcs)
{
  char *msg;
  int i, msgSize, msgType;
  MsgBufSize_ListIterator e;
  MsgBufSize *m;
  
  // First forward the other requests that the leader collected
  for (i = 0; i < numProcs; i++) {
    for (e = this->recAnn_List[i].begin(); e !=
	   this->recAnn_List[i].end(); ++e) {
      m = *e;
      msg = m->first;
      msgSize = m->second;
      Egida::SendControlMsg(i, EGIDA_RECOVERY_MSG, msg, msgSize);
    }
  }
  // Now send a request on behalf of the leader, i.e., this process
  this->SendCollectRecInfoMsg();
  // wait until all responses show up
  this->WaitForHelpResp(numProcs);

  // free up memory used for the recovery announcements
  for (i = 0; i < numProcs; i++) {
    for (e = this->recAnn_List[i].begin(); e !=
	   this->recAnn_List[i].end(); ++e) {
      m = *e;
      msg = m->first;
      msgSize = m->second;
      p4_msg_free(msg);
      delete m;
    }
    this->recAnn_List[i].clear();
  }

  // now do the distribution
  for (i = 0; i < numProcs; i++) {
    e = this->helpRec_List[i].begin();
    // Messages in the helpRec_List are either a pair 
    // <RECOVERY_MSG> <msg data> or a triple 
    // <RECOVERY_REPLAY_MSG> <msg piggyback> <msg data>
    // There will be always be two messages.  Hence, send the first
    // two out and then check if a third message also has to be sent.
    // The "tag" of the second message is stored as a list element.
    // After fetching the first message, the second "message" is the
    // message tag, followed by the message itself.
    while (e != this->helpRec_List[i].end()) {
      m = *e;
      msg = m->first;
      msgSize = m->second;
      Egida::SendControlMsg(i, EGIDA_RECOVERY_MSG, msg, msgSize);
      ++e;
      // get the tag of the message
      m = *e;
      msg = m->first;
      msgSize = m->second;
      {
	std::istrstream is(msg, msgSize);

	is >> msgType;
      }
      ++e;
      // now get the message and send it.
      m = *e;
      msg = m->first;
      msgSize = m->second;
      Egida::SendControlMsg(i, msgType, msg, msgSize);
      if (msgType == EGIDA_RECOVERY_REPLAY_MSG) {
	// What was just sent is the piggyback
	++e;
	m = *e;
	msg = m->first;
	msgSize = m->second;
	// This is the message data
	Egida::SendControlMsg(i, EGIDA_RECOVERY_REPLAY_MSG, msg,
			     msgSize);
      }
      ++e;
    }
    for (e = this->helpRec_List[i].begin(); e !=
	   this->helpRec_List[i].end(); ++e) {
      m = *e;
      p4_msg_free(m->first);
      delete m;
    }
    this->helpRec_List[i].clear();
  }

}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Send a help request message to the leader process which is
// 	responsible for collecting the data.
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

void CentralizedCollectRecInfo::SendHelpToLeader()
{
  int myId = Egida::GetMyId();
  int numProcs = Egida::GetNumProcs();
  int i;
  std::ostrstream os;

  for (i = 0; i < numProcs; i++) {
    if (this->recdRecoveryRespBegin[i])
      continue;

    if (this->leader != i) {
      // This message is sent to the leader and the leader then forwards 
      // this message to process i.  Hence, the actual source/dest of
      // this message are: myId, i.  The message format is:
      //    <msgtype> <actualSource> <actualDest>
      os << EGIDA_COLLECT_RECOVERY_MSG << ' ' << myId << ' ' << i << std::ends;
      // send the help request to the leader
      Egida::SendControlMsg(this->leader, EGIDA_RECOVERY_MSG, os.str(),
			   os.pcount());
      // reset the pointer to the beginning of the buffer
      os.rdbuf()->pubseekoff(0, std::ios::beg, std::ios::out);
      
      // send this message to the leader and ask the leader to forward 
      // this message to process i.
      //    <msgtype> <actualSource> <actualDest>
      os << EGIDA_HELP_RECOVERY << ' ' << myId << ' ' << i << ' ';
      os << this->lastDetRetrieved << ' ' << this->lastEventIdRetrieved[i] << std::ends;
      
      Egida::SendControlMsg(this->leader, EGIDA_RECOVERY_NOTIFICATION, os.str(),
			   os.pcount());
    }
    else {
      // ask the leader to send any information logged on behalf of
      // this process.
      os << EGIDA_HELP_RECOVERY << ' ' << myId << ' ' << i << ' ';
      os << this->lastDetRetrieved << ' ' << this->lastEventIdRetrieved[i] << std::ends;
      
      Egida::SendControlMsg(this->leader, EGIDA_RECOVERY_MSG, os.str(),
			   os.pcount());
    }

    // reset the pointer to the beginning of the buffer
    os.rdbuf()->pubseekoff(0, std::ios::beg, std::ios::out);
    // unfreeze the buffer so that it will get freed when the os'es
    // destructor runs.
    os.rdbuf()->freeze(false);
  }
    //    <msgtype> <actualSource> <actualDest>
  os << EGIDA_COLLECT_RECOVERY_MSG << ' ' << myId << ' ' << this->leader << std::ends;
  // send the help request to the leader
  Egida::SendControlMsg(this->leader, EGIDA_RECOVERY_MSG, os.str(),
		       os.pcount());
  // reset the pointer to the beginning of the buffer
  os.rdbuf()->pubseekoff(0, std::ios::beg, std::ios::out);
  os.rdbuf()->freeze(false);
  Egida::SendControlMsg(this->leader, EGIDA_RECOVERY_NOTIFICATION_END,
		       NULL, 0);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Elect a leader process that collects and distributes the
// 	information needed for the recovery each of the concurrently
// 	recovering processes.
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
void CentralizedCollectRecInfo::ElectLeader(void)
{
  if (this->numFailures == 1) 
    this->leader = Egida::GetMyId();
  else
    // for debug purposes, assume that process 1 is always the leader
    this->leader = 1;
}

void CentralizedCollectRecInfo::TimerExpired()
{

}
