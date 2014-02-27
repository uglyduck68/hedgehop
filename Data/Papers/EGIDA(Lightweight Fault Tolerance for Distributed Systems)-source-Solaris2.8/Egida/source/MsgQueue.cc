// MsgQueue.cc -- 
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
// $Log: MsgQueue.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:16  ravshank
// Start of Spring 2001
//
// Revision 1.1  2000/06/27 13:23:12  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.2  2000/06/22 23:48:56  phoebe
// Changed some names: Egida_Msg_Queue is now MsgQueue and Egida_Msg is now Message. Also, changed the MsgQueue's in Egida_Object.H to be MsgQueue*'s so that it is consistent with all the other data members. One more thing...changed PbLog (and subclasses) to not require the CkptProtocol * for the object (so not a data member and not part of the Initialize method) since PbLog doesn't use this data member (it's used in PbCkpt).
//
// Revision 1.1.1.1  2000/03/06 20:00:19  phoebe
// Sriram's original code with no modifications
//
// $Id: MsgQueue.cc,v 1.1.1.1 2001/02/12 00:00:16 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun May  2 10:53:58 1999
// Last Modified By: Sriram Rao
// Last Modified On: Wed May  5 18:18:29 1999
// Update Count    : 19
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <stdlib.h>

#include "MsgQueue.H"

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Initialize the message queue data structure
// 
// Arguments:
// 	self: id (in 0..n - 1) of this process
//      numQs: number of queues that need to be created
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void MsgQueue::Initialize(int self, int numQs)
{
  assert(numQs > 0);
  this->id = self;
  this->numQ = numQs;
  delete [] this->recdMsgs;
  this->recdMsgs = new Msg_List[numQs];
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Append a message to the list of messages sent by source.
// 
// Arguments:
// 	msg --- A pointer to the message buffer is enqueued.  The
// 	caller of this method SHOULD NOT free/reference this pointer
// 	after the method call.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void MsgQueue::Enqueue(int source, int tag, char *msg, int msgSize)
{
  Message *m = new Message(tag, msg, msgSize);

  assert((0 <= source) && (source < this->numQ));
  this->recdMsgs[source].push_back(m);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Application messages in Egida come as a pair: <piggyback, msg>
//      This method provides a way of enqueueing the pair in one shot.
//
// Arguments:
// 	pb, msg: Pointers to these buffers are enqueued.  The caller
// 	SHOULD NOT reference/free these buffers after this method call.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void MsgQueue::Enqueue2(int source, int tag, char *pb, int pbSize,
			       char *msg, int msgSize)
{
  Message *m1 = new Message(tag, pb, pbSize);
  Message *m2 = new Message(tag, msg, msgSize);

  assert((0 <= source) && (source < this->numQ));
  this->recdMsgs[source].push_back(m1);
  this->recdMsgs[source].push_back(m2);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Messages is removed from the middle of each queue.  This
// 	method provides the interface for putting back the messages at 
// 	the front of the queue that were not consumed.
// 
// Arguments:
// 	pb, msg: Pointers to these buffers are enqueued.  The caller
// 	SHOULD NOT reference/free these buffers after this method call.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void MsgQueue::Prepend2(int source, int tag, char *pb, int pbSize,
			       char *msg, int msgSize)
{
  Message *m1 = new Message(tag, pb, pbSize);
  Message *m2 = new Message(tag, msg, msgSize);

  assert((0 <= source) && (source < this->numQ));
  // first put the data back
  this->recdMsgs[source].push_front(m2);
  // now throw in the header
  this->recdMsgs[source].push_front(m1);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Remove a message from the queue of incoming messages.
// 
// Arguments:
// 	source, tag: input/output parameters
//        If both are -1, then, a message at the head of one of the
//          queues is returned; source, tag are modified to reflect the
//          values corresponding to the message that is returned.
//        Otherwise, a message that matches the request (either from
//          the specific source or specific tag or both) is returned.
//       msg: A pointer to a message buffer is returned; it is the
//          caller's responsibility to de-allocate the message buffer.
// Results:
//      source, tag, msg, msgSize are modified to reflect the result
//          that is returned.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void MsgQueue::Dequeue(int *source, int *tag, 
			      char **msg, int *msgSize)

{
  int from = *source;
  int found = 0;
  Msg_ListIterator i;
  Message *m;

  *msg = NULL;
  *msgSize = 0;

  if (from != -1) {
    assert((0 <= from) && (from < this->numQ));

    for (i = this->recdMsgs[from].begin(); i !=
	   this->recdMsgs[from].end(); ++i) {
      m = *i;
      if (m->MatchingTag(*tag)) {
	m->GetMsg(tag, msg, msgSize);
	// remove it from the list
	this->recdMsgs[from].erase(i);
	delete m;
	break;
      }
    }
  }
  else {
    for (from = 0; (from < this->numQ) && !found; from++) {
      for (i = this->recdMsgs[from].begin(); i !=
	     this->recdMsgs[from].end(); ++i) {
	m = *i;
	if (m->MatchingTag(*tag)) {
	  // Get message will modify tag.
	  m->GetMsg(tag, msg, msgSize);
	  // remove it from the list
	  this->recdMsgs[from].erase(i);
	  delete m;
	  found = 1;
	  *source = from;
	  break;
	}
      }
    }
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Check if a message has been received
// 
// Arguments:
// 	source, tag: input/output parameters
//        If both are -1, then, a message at the head of one of the
//          queues is returned; source, tag are modified to reflect the
//          values corresponding to the message that is available.
//        Otherwise, a message that matches the request (either from
//          the specific source or specific tag or both) is available.
//
// Results:
// 	source, tag are modified to reflect the result
//          that is returned.
//      This method returns 1 if a matching message is available; 0 otherwise.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

int MsgQueue::IsMsgAvail(int *source, int *tag)
{
  int found = 0, from = *source;
  Msg_ListIterator i;
  Message *m;

  if (from != -1) {
    // look only in the specific queue
    assert((0 <= from) && (from < this->numQ));

    for (i = this->recdMsgs[from].begin(); i !=
	   this->recdMsgs[from].end(); ++i) {
      m = *i;
      if (m->MatchingTag(*tag)) {
	*tag = m->GetMsgTag();
	found = 1;
	break;
      }
    }
  }
  else {
    // look in all queues
    for (from = 0; (from < this->numQ) && !found; from++) {
      for (i = this->recdMsgs[from].begin(); i !=
	     this->recdMsgs[from].end(); ++i) {
	m = *i;
	if (m->MatchingTag(*tag)) {
	  *tag = m->GetMsgTag();
	  *source = from;
	  found = 1;
	  break;
	}
      }
    }
  }
  return found;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Destroy any message in each queue.
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

void MsgQueue::ClearAllQueues()
{
  int i;
  Message *m;

  for (i = 0; i < this->numQ; i++) {
    while (!this->recdMsgs[i].empty()) {
      m = this->recdMsgs[i].front();
      this->recdMsgs[i].pop_front();
      delete m;

    }
    this->recdMsgs[i].clear();
  }
}

