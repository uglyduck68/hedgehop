// EventInfo.H -- 
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
// $Log: EventInfo.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:13  ravshank
// Start of Spring 2001
//
// Revision 1.7  2000/11/21 22:27:09  phoebe
// GarbageCollect in the SentStore is now working async. We changed the logic slightly so that all files are cleaned by one process and we clean when we've heard 3 responses (not necessarily all from different processes...this is ok we think.) Also...our favorite core dump on TakeCkpt (the memcpy one) has crept back in the picture. <grrrr>
//
// Revision 1.6  2000/11/15 22:12:24  phoebe
// Sanity check.
//
// Revision 1.5  2000/11/10 15:48:47  phoebe
// Checkpoint memory leak is now solved, and so is the memcpy core dump on some checkpoints.
//
// Revision 1.4  2000/06/22 20:58:52  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.3  2000/06/02 19:55:05  phoebe
// The code now compiles with the Encryption and the Hash and Sign functionality added to EventStore's PurgeOnDisk subroutine. Still need to test that it will run, and need to add same functionality to DetStore.cc
//
// Revision 1.2  2000/06/02 04:13:12  phoebe
// Encryption of EventInfo now working.
//
// Revision 1.1.1.1  2000/03/06 20:00:15  phoebe
// Sriram's original code with no modifications
//
// $Id: EventInfo.H,v 1.1.1.1 2001/02/12 00:00:13 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu May  6 23:05:15 1999
// Last Modified By: Sriram Rao
// Last Modified On: Sun Jul  4 15:52:02 1999
// Update Count    : 24
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Module for specifying the structure of event related
// 	information.  Currently, event info is for logging messages.

#if defined(__cplusplus) && !defined(_EVENT_INFO_H)
#define _EVENT_INFO_H

#include <assert.h>
#include <list>
#include <iostream>
#include <iterator>

// Buffer for an event info is allocated using p4---p4 does memory
// management already.  Let us take advantage of it.

#include "Egida_p4.h"

class EventInfo {
public:
  EventInfo() {
    this->source = 0;
    this->sourceEventId = 0;
    // other process involved in the event (dep. gen./non-det.)
    // for a dep. gen. event---message send, otherProc is the
    //  destination
    // for a non-det. event---message receive, otherProc is the source
    this->otherProc = 0;
    this->otherProcEventId = 0;
    this->pbSize = this->infoSize = 0;
    this->pb = this->info = NULL;
  };
  ~EventInfo() {
    if (this->pbSize > 0 && this->pb) 
      p4_msg_free(this->pb);
    if (this->infoSize > 0 && this->info)
      p4_msg_free(this->info);
    this->info = this->pb = NULL;
    this->pbSize = this->infoSize = 0;
  };
  EventInfo(int s, int seId, int op, int opId, char *pback, int pbackSize,
	    char *data, int dataSize) {
    this->source = s;
    this->sourceEventId = seId;
    this->otherProc = op;
    this->otherProcEventId = opId;
    this->pbSize = pbackSize;
    this->infoSize = dataSize;
    this->pb = pback;
    this->info = data;
  };

  EventInfo(const EventInfo &m) {
    this->source = m.source;
    this->sourceEventId = m.sourceEventId;
    this->otherProc = m.otherProc;
    this->otherProcEventId = m.otherProcEventId;
    this->pbSize = m.pbSize;
    this->infoSize = m.infoSize;
    //this is a shallow copy
    this->pb = m.pb;
    this->info = m.info;
  };



  EventInfo(const EventInfo &m, int dummy) {
    this->source = m.source;
    this->sourceEventId = m.sourceEventId;
    this->otherProc = m.otherProc;
    this->otherProcEventId = m.otherProcEventId;
    this->pbSize = m.pbSize;
    this->infoSize = m.infoSize;
    //this is a deep copy
    if(this->pbSize > 0) {
      pb = p4_msg_alloc(m.pbSize);
      memcpy(pb, m.pb, m.pbSize);
    }
    if(this->infoSize > 0) {
      info = p4_msg_alloc(m.infoSize);
      memcpy(info, m.info, m.infoSize);
    }
  };

  void Clear(void) {
    this->source = 0;
    this->sourceEventId = 0;
    this->otherProc = 0;
    this->otherProcEventId = 0;
    /*
      The event infos are retrieved from the file and put into the cached list
      structure for later when it is used during the replay. clear() is used
      in this context. Hence if we delete this here, it will just put it into
      the list and then immediately delete it from there and the pb and the msg
      won't be available during the replay. This manifests itself as 2 things.
      One, the p4_alloc says that it is deleting something it doesn't own (since
      we free it here) and second, even before it comes to that stage, somebody
      might try to read the junk in it and produce an assertion failure if there
      are assertions
    */

#if 0
    if((this->pbSize > 0) && (this->pb != NULL))
      p4_msg_free(this->pb);
    if((this->infoSize > 0) && (this->info != NULL))
      p4_msg_free(this->info);
#endif // #if 0

    this->pb = this->info = NULL;
    this->pbSize = this->infoSize = 0;
  };

  void ReadNonDataFields(std::istream &is) {
    is >> this->source;
    is >> this->sourceEventId;
    is >> this->otherProc;
    is >> this->otherProcEventId;
    is >> this->pbSize;
    is.get();  // skip the ' ' after this->pbSize
    if (this->pbSize > 0) {
      this->pb = p4_msg_alloc(this->pbSize);
      is.read(this->pb, this->pbSize);
    }
    else
      this->pb = NULL;
    is >> this->infoSize;
    is.get();  // skip the ' ' after this->infoSize
    this->info = NULL;
  };

  friend std::ostream & operator << (std::ostream &os, const EventInfo &eInfo) {
    os << eInfo.source << ' ';
    os << eInfo.sourceEventId << ' ';
    os << eInfo.otherProc << ' ';
    os << eInfo.otherProcEventId << ' ';
    os << eInfo.pbSize << ' ';
    if (eInfo.pbSize > 0) {
      os.write(eInfo.pb, eInfo.pbSize);
      os << ' ';
    }
    os << eInfo.infoSize << ' ';
    if (eInfo.infoSize > 0) {
      os.write(eInfo.info, eInfo.infoSize);
      os << ' ';
    }
    return os;
  };
  friend std::istream & operator >> (std::istream &is, EventInfo
				     &eInfo) {
    is >> eInfo.source;
    is >> eInfo.sourceEventId;
    is >> eInfo.otherProc;
    is >> eInfo.otherProcEventId;
    is >> eInfo.pbSize;
    is.get();  // skip the ' ' after eInfo.pbSize
    if (eInfo.pbSize > 0) {
      eInfo.pb = p4_msg_alloc(eInfo.pbSize);
      is.read(eInfo.pb, eInfo.pbSize);
    }
    else
      eInfo.pb = NULL;
    is >> eInfo.infoSize;
    is.get();  // skip the ' ' after eInfo.infoSize
    if (eInfo.infoSize > 0) {
      eInfo.info = p4_msg_alloc(eInfo.infoSize);
      is.read(eInfo.info, eInfo.infoSize);
    }
    else 
      eInfo.info = NULL;
    return is;
  };

  // source is the process that created this eventInfo structure.
  // sourceEventId is the event id of the source when this eventInfo
  // structure was created.
  int source, sourceEventId;
  // otherProc is the other process that is involved in the event.
  // For a non-deterministic event such as message receive, otherProc 
  // is the message destination.
  // For a dependency generating event such as message send, otherProc 
  // is the message source and otherProcEventId is the send seq. #
  int otherProc, otherProcEventId;
  int eventId;
  char *pb, *info;
  int pbSize, infoSize;
};

typedef std::list<EventInfo*> EventInfo_List;
typedef std::list<EventInfo*>::iterator EventInfo_ListIterator;
typedef std::list<EventInfo*>::const_iterator EventInfo_ListConstIterator;

#endif


