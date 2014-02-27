// PbLog.H -- 
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
// $Log: LogProtocol.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:14  ravshank
// Start of Spring 2001
//
// Revision 1.4  2000/09/27 22:03:01  phoebe
// In CkptImpl changed the growing of the heap from a strict monotonically increasing function (using the check that we only grow if size is less than what is needed) to one that can shrink. The reason we can do this is sbrk will take as an argument a negative value, where as malloc cannot.
//
// Revision 1.3  2000/06/27 13:22:42  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.2  2000/06/22 23:48:53  phoebe
// Changed some names: Egida_Msg_Queue is now MsgQueue and Egida_Msg is now Message. Also, changed the MsgQueue's in Egida_Object.H to be MsgQueue*'s so that it is consistent with all the other data members. One more thing...changed PbLog (and subclasses) to not require the CkptProtocol * for the object (so not a data member and not part of the Initialize method) since PbLog doesn't use this data member (it's used in PbCkpt).
//
// Revision 1.1.1.1  2000/03/06 20:00:15  phoebe
// Sriram's original code with no modifications
//
// $Id: LogProtocol.H,v 1.1.1.1 2001/02/12 00:00:14 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu Apr 29 23:16:39 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Aug 16 14:31:54 1999
// Update Count    : 77
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_LOG_PROTOCOL_H)
#define _LOG_PROTOCOL_H

//forward declaration needed here
class PbLog;

#include "CkptProtocol.H"
#include "DetLog.H"
#include "EventLog.H"
#include "MsgQueue.H"

class PbLog {
public:
  PbLog() {
    this->id = -1;
    this->numProcs = 0;
    this->numFailures = 0;
    this->incomingMsgQ = NULL;
    this->detLog = NULL;
    this->sentLog = this->deliveredLog = NULL;
  };

  ~PbLog() { };

  PbLog(int self, int numP, int numF) {
    this->id = self;
    this->numProcs = numP;
    this->numFailures = numF;
    this->incomingMsgQ = NULL;
    this->detLog = NULL;
    this->sentLog = this->deliveredLog = NULL;
  };


  virtual void Initialize(MsgQueue *q,
			  DetLog *detl, EventLog *sl, EventLog *dl);

  virtual void GetPiggyback(int dest, char **pb, int *pbSize);
  virtual bool ProcessPiggyback(int source, int ssn, char *pb, int pbSize);
  virtual bool IsDeliverable(int source, int ssn, char *pb, int pbSize);

  virtual void LogSentMsg(int dest, int ssn, char *pb, 
			  int pbSize, const char *msg, int msgSize);

  virtual void ProcessMsg(int source, int tag, char *msg, int
			  msgSize);

  virtual void LogDeliveredMsg(EventInfo *msg);

  virtual void PreCkptActions(void);
  virtual void PostCkptActions(const char *ckptFileName, int stableEventId);

  // These two are needed for recovery
  virtual void PreReplayActions(int startEsn, bool rb);
  virtual void PostReplayActions(void);
  virtual bool NeedToDetectOrphans(void);

  virtual bool GetRollbackFile(char *fileName);

  virtual void TimerExpired(void);

  virtual void PrepareForCrash(void);
  void Terminate(void);

  // Needed during recovery
  void GetLastAckSent(int source, int *ssn) {
    *ssn = this->lastAckSent[source];
  };
  void UpdateLastAckRecd(int source, int ssn) {
    this->lastAckRecd[source] = ssn;
  };
  virtual void UpdateAvoidLoggingMsg(int source, int ssn) {
    this->avoidLoggingMsg[source] = ssn;
  };

  virtual void CleanUpCkptFiles(char * ckptFileName);

  virtual void SendLastControlMessages();

protected:
  int id;
  int numProcs;
  int numFailures;

  int lastAckRecd[EGIDA_MAX_PROCS], lastAckSent[EGIDA_MAX_PROCS];
  int avoidLoggingMsg[EGIDA_MAX_PROCS];

  char rollbackFilename[EGIDA_FILENAME_LEN];

  MsgQueue *incomingMsgQ;
  DetLog *detLog;
  EventLog *sentLog, *deliveredLog;

  virtual void ProcessAck(int source, int ssn);
};


#endif
