// Recovery.H -- 
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
// $Log: Recovery.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:14  ravshank
// Start of Spring 2001
//
// Revision 1.2  2000/06/27 13:22:51  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.1.1.1  2000/03/06 20:00:16  phoebe
// Sriram's original code with no modifications
//
// $Id: Recovery.H,v 1.1.1.1 2001/02/12 00:00:14 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun May  9 15:23:24 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Aug 16 17:56:29 1999
// Update Count    : 20
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_RECOVERY_H)
#define _RECOVERY_H

#include "CollectRecInfo.H"
#include "DetLog.H"
#include "EventLog.H"
#include "LogProtocol.H"
#include "OrphanDetection.H"

class Recovery {
public:
  Recovery() { 
    this->id = -1;
    this->detLog = NULL;
    this->sentLog = NULL;
    this->deliveredLog = NULL;
    this->pbLog = NULL;
    this->collectRecInfo = NULL;
    this->orphanDetection = NULL;
  };

  ~Recovery() { };

  Recovery (int self, int numF, DetLog *dl, EventLog *sl, EventLog *delL, 
	    PbLog *lp, OrphanDetection *od,
	    CollectRecInfo::CollectRecInfoType collectRecInfoType);

  void ProcessMsg(int source, int tag, const char *msg, int msgSize);
  void DoRecovery(int esn, bool rollback);
  void HelpRecovery(int dest, int recoveringProc, int lastDet, int lastSentMsg);
  void TimerExpired(void);

protected:
  int id;
  CollectRecInfo *collectRecInfo;
  DetLog *detLog;
  EventLog *sentLog, *deliveredLog;
  PbLog *pbLog;
  OrphanDetection *orphanDetection;  
};

#endif
