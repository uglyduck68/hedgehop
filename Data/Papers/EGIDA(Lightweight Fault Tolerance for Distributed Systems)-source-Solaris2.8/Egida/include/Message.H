// Message.H -- 
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
// $Log: Message.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:14  ravshank
// Start of Spring 2001
//
// Revision 1.1  2000/06/27 13:22:43  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.2  2000/06/22 23:48:52  phoebe
// Changed some names: Egida_Msg_Queue is now MsgQueue and Egida_Msg is now Message. Also, changed the MsgQueue's in Egida_Object.H to be MsgQueue*'s so that it is consistent with all the other data members. One more thing...changed PbLog (and subclasses) to not require the CkptProtocol * for the object (so not a data member and not part of the Initialize method) since PbLog doesn't use this data member (it's used in PbCkpt).
//
// Revision 1.1.1.1  2000/03/06 20:00:14  phoebe
// Sriram's original code with no modifications
//
// $Id: Message.H,v 1.1.1.1 2001/02/12 00:00:14 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun May  2 10:48:03 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu May  6 15:31:04 1999
// Update Count    : 13
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Queue of incoming application messages.

#if defined(__cplusplus) && !defined(_MESSAGE_H)
#define _MESSAGE_H

#include <assert.h>
#include <stdio.h>
#include <sys/stat.h>

#include <list>

class Message {
public:
  Message(int tag, char *m, int size) {
    this->msgTag = tag;
    this->msg = m;
    this->msgSize = size;
  };
  ~Message() {
    this->msg = NULL;
  };
  int MatchingTag(int tag) {
    return (tag == -1) ? 1 : (this->msgTag == tag);
  };
  void GetMsg(int *t, char **m, int *s) {
    *t = this->msgTag;
    *m = this->msg;
    *s = this->msgSize;
  };
  int GetMsgTag() const {
    return this->msgTag;
  };
private:
  int msgTag;
  char *msg;
  int msgSize;
};


typedef std::list<Message*> Msg_List;
typedef std::list<Message*>::iterator Msg_ListIterator;


#endif
