// MsgPoll.H -- 
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
// $Log: MsgPoll.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:14  ravshank
// Start of Spring 2001
//
// Revision 1.2  2000/09/27 22:03:02  phoebe
// In CkptImpl changed the growing of the heap from a strict monotonically increasing function (using the check that we only grow if size is less than what is needed) to one that can shrink. The reason we can do this is sbrk will take as an argument a negative value, where as malloc cannot.
//
// Revision 1.1  2000/06/27 13:22:44  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.3  2000/06/23 16:35:24  phoebe
// Cleaning out un-needed data members in classes.
//
// Revision 1.2  2000/06/23 00:01:03  phoebe
// Another name change...HandleMsgPoll and NullHandleMsgPoll are now MsgPoll and NullMsgPoll.
//
// Revision 1.1.1.1  2000/03/06 20:00:14  phoebe
// Sriram's original code with no modifications
//
// $Id: MsgPoll.H,v 1.1.1.1 2001/02/12 00:00:14 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu May 27 13:38:44 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu Aug 26 10:04:42 1999
// Update Count    : 14
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_MSG_POLL_H)
#define _MSG_POLL_H

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "DetLog.H"

class MsgPoll {
public:
  MsgPoll() { 
    this->id = -1;
    this->detLog = NULL;
  };
  // detStore better be Null store or a stable store
  MsgPoll(int self, int numProcs, DetStore::DetStoreType detStoreType);
  ~MsgPoll() { };
  virtual void RecordResult(int seqNum, int result);
  bool ReplayResult(int seqNum, int *result);
  void PrepareForReplay(int startSeqNum);
  void ReplayDone(int lastSeqNum);
  void CkptDone(void);
  void GarbageCollect(int procId, int detId);
private:
  int id;
  DetLog *detLog;
};


class NullMsgPoll : public MsgPoll {
public:
  NullMsgPoll() : MsgPoll() { };
  // detStore better be Null store or a stable store
  NullMsgPoll(int self, int numProcs, DetStore::DetStoreType
		    detStoreType) : 
    MsgPoll(self, numProcs, detStoreType) { };
    
  ~NullMsgPoll() { };
  virtual void RecordResult(int seqNum, int result) { };
};

#endif
