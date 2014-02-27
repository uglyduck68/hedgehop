// OrphanDetection.H -- 
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
// $Log: OrphanDetection.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:14  ravshank
// Start of Spring 2001
//
// Revision 1.2  2000/06/27 13:22:48  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.1.1.1  2000/03/06 20:00:15  phoebe
// Sriram's original code with no modifications
//
// $Id: OrphanDetection.H,v 1.1.1.1 2001/02/12 00:00:14 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Mon May 10 16:27:03 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Aug 16 17:55:31 1999
// Update Count    : 17
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_ORPHAN_DETECTION_H)
#define _ORPHAN_DETECTION_H

#include "CkptProtocol.H"
#include "LogProtocol.H"
#include "OptLogProtocol.H"

class OrphanDetection {
public:
  enum OrphanDetectionType {EGIDA_OD_NULL, EGIDA_OD_BROADCAST_LC};

  OrphanDetection() { };

  ~OrphanDetection() { };

  OrphanDetection(PbLog *l) { };

  virtual void DetectOrphans(void) = 0;
  virtual void ProcessMsg(int source, int tag, 
			  const char *msg, int msgSize) { };
  virtual void TimerExpired(void) { };
};



class NullOrphanDetection : public OrphanDetection {
public:
  NullOrphanDetection() { };

  NullOrphanDetection(PbLog *l) { };

  ~NullOrphanDetection() { };

  void DetectOrphans(void) { };
};



class OrphanDetectionByBroadcastLC : public OrphanDetection {
public:
  OrphanDetectionByBroadcastLC() {
    this->waitingForAcks = false;
    this->pbVectorClock = NULL;
    memset(this->ackRecd, false, EGIDA_MAX_PROCS * sizeof(bool));
  };

  ~OrphanDetectionByBroadcastLC() { };

  OrphanDetectionByBroadcastLC(PbVectorClock *l) {
    this->waitingForAcks = false;
    this->pbVectorClock = l;
    memset(this->ackRecd, false, EGIDA_MAX_PROCS * sizeof(bool));
  };

  void DetectOrphans(void);
  void ProcessMsg(int source, int tag, 
		  const char *msg, int msgSize);
  void TimerExpired(void);

private:
  bool waitingForAcks;
  bool ackRecd[EGIDA_MAX_PROCS];
  PbVectorClock *pbVectorClock;

  void SendOrphanDetectMsg(void);
};

#endif

