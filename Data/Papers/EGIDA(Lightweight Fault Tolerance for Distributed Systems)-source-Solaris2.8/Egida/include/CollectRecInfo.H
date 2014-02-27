// CollectRecInfo.H -- 
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
// $Log: CollectRecInfo.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:12  ravshank
// Start of Spring 2001
//
// Revision 1.1.1.1  2000/03/06 20:00:13  phoebe
// Sriram's original code with no modifications
//
// $Id: CollectRecInfo.H,v 1.1.1.1 2001/02/12 00:00:12 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun May  9 15:53:12 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu Jul  8 17:19:33 1999
// Update Count    : 25
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_COLLECT_REC_INFO_H)
#define _COLLECT_REC_INFO_H

#include <utility>

#include "DetLog.H"
#include "EventLog.H"

typedef std::pair<char *, int> MsgBufSize;
typedef std::list<MsgBufSize*> MsgBufSize_List;
typedef std::list<MsgBufSize*>::iterator MsgBufSize_ListIterator;

class CollectRecInfo {
public:
  enum CollectRecInfoType {EGIDA_DISTRIBUTED_COLLECT_REC_INFO,
			   EGIDA_CENTRALIZED_COLLECT_REC_INFO};

  CollectRecInfo() {

    this->numFailures = 0;
    this->collectingRecInfo = false;
    this->detLog = NULL;
    this->eventLog = NULL;
    memset(this->recdRecoveryRespBegin, false, EGIDA_MAX_PROCS * sizeof(bool));
    memset(this->recdRecoveryRespEnd, false, EGIDA_MAX_PROCS * sizeof(bool));

    this->lastDetRetrieved = 0;
    memset(this->lastEventIdRetrieved, 0, EGIDA_MAX_PROCS * sizeof(int));
  };
  ~CollectRecInfo() { };
  CollectRecInfo(DetLog *dl, EventLog *el, int numF) {
    int i;

    this->numFailures = numF;
    this->collectingRecInfo = false;
    this->detLog = dl;
    this->eventLog = el;
    for (i = 0; i < EGIDA_MAX_PROCS; i++)
      this->recdRecoveryRespBegin[i] =
	this->recdRecoveryRespEnd[i] = false;
    this->lastDetRetrieved = 0;
    memset(this->lastEventIdRetrieved, 0, EGIDA_MAX_PROCS * sizeof(int));
  };
  virtual void Retrieve(int eventId);
  virtual void ProcessMsg(int source, int actualSource, int actualDest,
			  const char *msg, int msgSize);

  virtual void TimerExpired(void);
protected:
  int numFailures;
  bool collectingRecInfo;
  int lastDetRetrieved;
  int lastEventIdRetrieved[EGIDA_MAX_PROCS];

  MsgBufSize_List helpBegin_List[EGIDA_MAX_PROCS];
  
  bool recdRecoveryRespBegin[EGIDA_MAX_PROCS];
  bool recdRecoveryRespEnd[EGIDA_MAX_PROCS];
  DetLog *detLog;
  EventLog *eventLog;

  virtual void SendCollectRecInfoMsg(void);
  void WaitForHelpResp(int numProcs);
  void ProcessRecoveryBeginInfo(int numProcs);
};


class CentralizedCollectRecInfo : public CollectRecInfo {
public:
  CentralizedCollectRecInfo() {
    this->leader = -1;
    this->numHelpReqRecd = 0;
  };
  CentralizedCollectRecInfo(DetLog *dl, EventLog *el, int numF) :
    CollectRecInfo(dl, el, numF) {

    this->leader = -1;
    this->numHelpReqRecd = 0;
  };
  void Retrieve(int eventId);
  void ProcessMsg(int source, int actualSource, int actualDest,
		  const char *msg, int msgSize);
  void TimerExpired(void);

private:
  int leader;
  int numHelpReqRecd;

  MsgBufSize_List helpRec_List[EGIDA_MAX_PROCS];
  MsgBufSize_List recAnn_List[EGIDA_MAX_PROCS];
  
  void ElectLeader(void);
  void SendHelpToLeader(void);
  void WaitForHelpReq(void);
  void CollectAndDistribute(int numProcs);
};



#endif
