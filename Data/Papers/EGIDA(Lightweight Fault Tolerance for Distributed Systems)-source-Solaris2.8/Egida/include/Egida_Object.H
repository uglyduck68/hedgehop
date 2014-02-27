// Egida_Object.H -- 
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
// $Log: Egida_Object.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:13  ravshank
// Start of Spring 2001
//
// Revision 1.15  2000/10/31 00:22:43  phoebe
// SBP now works with flushing and garbage collection. Before the file out pointers were not being managed properly so after a garbagecollect they were pointing to a non-existant file. So the point of all of this is we have a working SentStore.cc file.
//
// Revision 1.14  2000/10/24 16:32:23  phoebe
// Garbage collection of the sentLog is now happening but sometimes it doesn't recover...think it's a problem with multiple recoveries and not flushing some info. Will check into it. Fixed the memcpy core dump on taking a checkpoint...it was a problem with the fact that we were using a signed int to track the segment size and should have been using an unsigned int so that we didn't get overflow problem.
//
// Revision 1.13  2000/09/27 22:02:59  phoebe
// In CkptImpl changed the growing of the heap from a strict monotonically increasing function (using the check that we only grow if size is less than what is needed) to one that can shrink. The reason we can do this is sbrk will take as an argument a negative value, where as malloc cannot.
//
// Revision 1.12  2000/06/30 20:10:18  phoebe
// Async full checkpoint now working with garbage collection.
//
// Revision 1.11  2000/06/27 13:22:33  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.10  2000/06/26 21:31:00  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.9  2000/06/26 19:09:47  phoebe
// Removed all wrapper methods out of Egida_Internal.cc and renamed calls in code to directly call the Egida::Method that would have been called by the Egida_Method call.
//
// Revision 1.8  2000/06/26 16:56:51  phoebe
// Made all the Egida_Object methods and members static. Also moved GetMyId and GetNumProcs out of Egida_Internal and into Egida_Object.
//
// Revision 1.7  2000/06/26 14:56:00  phoebe
// More slight changes. Cleaned up Init.cc by moving path definitions to Egida_Globals.H. There are also some other small changes that I can't remember at the moment.
//
// Revision 1.6  2000/06/23 19:10:59  phoebe
// Moved all the egida object initialization from Init.cc into ProtocolPreInit and ProtocolPostInit methods.
//
// Revision 1.5  2000/06/23 18:48:06  phoebe
// Made Egida_Object_Init.cc a method of the Egida class. It's now called ProtocolSpecificInit.
//
// Revision 1.4  2000/06/23 03:04:49  phoebe
// Changed the isInitialized data member in Egida_Object to a true boolean instead of the int that it used to be.
//
// Revision 1.3  2000/06/23 00:01:02  phoebe
// Another name change...HandleMsgPoll and NullHandleMsgPoll are now MsgPoll and NullMsgPoll.
//
// Revision 1.2  2000/06/22 23:48:52  phoebe
// Changed some names: Egida_Msg_Queue is now MsgQueue and Egida_Msg is now Message. Also, changed the MsgQueue's in Egida_Object.H to be MsgQueue*'s so that it is consistent with all the other data members. One more thing...changed PbLog (and subclasses) to not require the CkptProtocol * for the object (so not a data member and not part of the Initialize method) since PbLog doesn't use this data member (it's used in PbCkpt).
//
// Revision 1.1.1.1  2000/03/06 20:00:14  phoebe
// Sriram's original code with no modifications
//
// $Id: Egida_Object.H,v 1.1.1.1 2001/02/12 00:00:13 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu Apr 29 15:21:21 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Aug 16 18:17:45 1999
// Update Count    : 120
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_EGIDA_OBJECT_H)
#define _EGIDA_OBJECT_H

#include "CausalLogProtocol.H"
#include "CkptProtocol.H"
#include "Communication.H"
#include "DetLog.H"
#include "Globals.H"
#include "EventLog.H"
#include "HowToCkpt.H"
#include "LogProtocol.H"
#include "MsgPoll.H"
#include "MsgQueue.H"
#include "OptLogProtocol.H"
#include "PbCkpt.H"
#include "Recovery.H"
#include "Rollback.H"

class Egida {
public:
  //Remember: No constructor or destructor since this is a static class

  //accessor methods for private members
  static int GetMyId(void);
  static int GetNumProcs(void);
  static void TakeCkpt(void);
  static void LogSentMsg(int dest, int ssn, char *pb,
			 int pbSize, const char *msg,
			 int msgSize);
  static bool FailedOnce(void);
  static bool IsInitialized(void);
  static int GetSourceSequenceNumber(int dest);
  static void DisableTimer(void);
  static void SetAsyncStableEsn(void);
  static void GarbageCollectMsgPoll(int procId, int stable);

  //protocol init functions
  static void ProtocolPreInit(int self, int numP, char * progName);
  static void ProtocolSpecificInit(int logFlushFreq, int ckptFreq, int numFailures);
  static void ProtocolPostInit(int avoidThresh);

  static void Terminate(void);

  static void GetPiggyback(int dest, int sendTag, int ssn, char **pb, int *pbSize);
  static void GetMsgToDeliver(int *source, int *tag,
		       char **msg, int *msgSize);
  static void LogDeliveredMsg(char *msg);

  static bool NeedToSendMsg(int dest, int ssn);
  static bool IsDeliverable(char *pb, int pbSize, int *ssn);
  static void RemoveNonDeliverableMsgs(void);

  static int IsMsgAvail(int *source, int *tag);
  
  static void PreCkptActions(void);
  static void PostCkptActions(const char *ckptFileName);
  static void PostAsyncCkptActions(const char *ckptFileName);

  static void FetchPiggybackLog(char *pb, char **pbLog, int *pbLogSize);
  static void GetMsgTag(const char *pb, int *tag);
  static void GetMsgSsn(const char *pb, int *ssn);
  static void GetMsgSrcTag(const char *pb, int *src, int *tag);

  static void ProcessGetLastControlMsgReq(int source);
  static void ProcessGetLastControlMsgResp(int source, const char *msg);
  static int SendLastControlMessages();

  static void GetLastRecdMsg(int source, int *ssn);
  static void UpdateLastSentMsg(int source, int ssn);
  static void UpdateLastRecdMsg(int source, int ssn);

  static void SetStableEsn(void);
  static void SetStableEsn(int stableE);
  static void SetStableRecdMsg(void);
  static void AsyncSetStableRecdMsg(void);
  static void SetStableRecdMsg(int dest, int rsn, int source, int ssn);
  static void SetStableRecdMsg(int source, int ssn);

  static void GarbageCollect(int source, int tag, const char *msg, int msgSize);
  
  static void DoRecovery(bool rolledback);
  static void Rollback(void);

  static void ResendMsgs(int source, int tag, const char *msg, int msgSize);
  static void SendControlMsg(int dest, int type, char *msg, int msgSize);
  static void TimerExpired(void);
  static void RestoreDone(int rollback);
  static void ProcessIncomingMsg(int source, int tag, char *msg, int msgSize);
  static void UpdateMsgsRecd(const int *lastMsgRecd);
  static void EnqueueReplayMsg(char *pb, int pbSize, char *msg, int msgSize);
  static void SetStateStable(void);
  static void InternallyFail(void);

private:

  static int id;
  static int numProcs;
  static int esn;
  static int stableEsn;
  static int asyncStableEsn;

  static bool isInitialized;
  static bool isRecovering;
  static bool replayMsgAvail;
  static bool failedOnce;
  static bool disableTimer;

  static char programName[EGIDA_FILENAME_LEN];

  static struct timeval replayStartTime;

  static EventInfo *lastDeliveredMsg;
  static MsgPoll *msgPoll;
  static DetLog *detLog;
  static EventLog *sentLog, *deliveredLog;
  static MsgQueue *incomingMsgQ, *replayMsgQ;
  static PbLog *pbLog;
  static PbCkpt *pbCkpt;
  static CkptProtocol *ckptProtocol;
  static HowToCkpt *howToCkpt;
  static Recovery *recovery;
  static RollbackActions *rollbackActions;
  static RollbackActions *rollforwardActions;
  static OrphanDetection *orphanDetection;
  
  // keep the send seq # on a per-process basis.  in some mpi
  // applications, messages are delivered out-of-order and this wrecks 
  // havoc on logging and garbage collection.
  static int sendSeqNum[EGIDA_MAX_PROCS];
  // lastGCSent[i] is the ssn of the last message from process i for
  // which a garbage collect message has been sent.
  static int lastGCSent[EGIDA_MAX_PROCS];
  static int lastMsgDelivered[EGIDA_MAX_PROCS];
  static int stableRecdMsg[EGIDA_MAX_PROCS];
  static int asyncStableRecdMsg[EGIDA_MAX_PROCS];
  static int lastMsgSent[EGIDA_MAX_PROCS];
  static int lastMsgRecd[EGIDA_MAX_PROCS];
  
  static bool msgsDelivered[EGIDA_MAX_PROCS][EGIDA_MAX_APPL_MSGS];


  static void SendGarbageCollectMsg(void);
  static void SendGarbageCollectMsg(int procId);
  static void AsyncSendGarbageCollectMsg(void);
  static void AsyncSendGarbageCollectMsg(int procId);
  static void SendGarbageCollectMsg(int procId, int ssn);

  static void MergePiggyback(int dest, int sendTag, int source, int ssn, 
			     char **pb, int *pbSize,
			     const char *pbCkpt, int pbCkptSize,
			     const char *pbLog, int pbLogSize);  
  static void SplitPiggyback(int *dest, int *source, int *ssn, 
			     char *pb, int pbSize,
			     char **pbCkpt, int *pbCkptSize,
			     char **pbLog, int *pbLogSize);
  static bool ProcessPiggyback(char *pb, int pbSize, int *ssn);

  static bool DuplicateMsg(int source, int ssn);
  static void CollectLostMsgs(void);

  static bool GetReplayMsgFromQ(MsgQueue *msgQ, const Determinant *replayDet,
				int *source, int *tag, 
				char **pb, int *pbSize,
				char **msg, int *msgSize);
  static bool ReplayDeliver(int *source, int *tag, char **pb, int *pbSize, 
			    char **msg, int *msgSize);

};

#endif
