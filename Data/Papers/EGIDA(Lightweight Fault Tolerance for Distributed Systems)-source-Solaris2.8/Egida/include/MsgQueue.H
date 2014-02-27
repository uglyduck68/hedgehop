// Egida_Msg.H -- 
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
// $Log: MsgQueue.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:14  ravshank
// Start of Spring 2001
//
// Revision 1.1  2000/06/27 13:22:45  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.2  2000/06/22 23:48:52  phoebe
// Changed some names: Egida_Msg_Queue is now MsgQueue and Egida_Msg is now Message. Also, changed the MsgQueue's in Egida_Object.H to be MsgQueue*'s so that it is consistent with all the other data members. One more thing...changed PbLog (and subclasses) to not require the CkptProtocol * for the object (so not a data member and not part of the Initialize method) since PbLog doesn't use this data member (it's used in PbCkpt).
//
// Revision 1.1.1.1  2000/03/06 20:00:14  phoebe
// Sriram's original code with no modifications
//
// $Id: MsgQueue.H,v 1.1.1.1 2001/02/12 00:00:14 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun May  2 10:48:03 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu May  6 15:31:04 1999
// Update Count    : 13
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Queue of incoming application messages.

#if defined(__cplusplus) && !defined(_MSG_QUEUE_H)
#define _MSG_QUEUE_H

#include <assert.h>
#include <stdio.h>
#include <sys/stat.h>

#include "Message.H"

class MsgQueue {
public:
  MsgQueue() {
    this->numQ = 0;
    this->recdMsgs = NULL;
  };
  ~MsgQueue() {
    delete [] this->recdMsgs;
  };
  MsgQueue(int numQs) {
    assert(numQs > 0);
    this->numQ = numQs;
    this->recdMsgs = new Msg_List[numQs];
  };
  void Initialize(int self, int numQs);
  void Enqueue(int source, int tag, char *msg, int msgSize);
  void Enqueue2(int source, int tag, char *pb, int pbSize,
		char *msg, int msgSize);
  // a message was taken out of the queue; it needs to be put back at
  // the head of the queue.
  void Prepend2(int source, int tag, char *pb, int pbSize,
		char *msg, int msgSize);
  void Dequeue(int *source, int *tag, char **msg, int *msgSize);
  int IsMsgAvail(int *source, int *tag);
  // discard all queued messages from all queues.
  void ClearAllQueues(void);
private:
  int id;
  Msg_List * recdMsgs;
  int numQ;
};

#endif
