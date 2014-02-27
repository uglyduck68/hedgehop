// DeliveredLog.H -- 
//                This source is provided as is without any express or
//                written warranty.  Permission to use, copy, modify, and 
//                distribute this software for any purpose without fee is
//                hereby granted, provided that this entire notice is 
//                included in all copies of any software which is or includes
//                a copy or modification of this software and in all copies
//                of the supporting documentation for such software.
//                All Rights Reserved.
// $Locker:  $
// $Log: DeliveredStore_modified.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:15  ravshank
// Start of Spring 2001
//
// Revision 1.1  2000/10/20 19:28:39  phoebe
// SentLog class is now integrated and works so protocols using the sentLog to store information will now restart on flushing.
//
// Revision 1.1.1.1  2000/09/27 19:32:42  jmn
// Initial revision.
//
// Revision 1.5  2000/08/08 20:57:11  phoebe
// Cleaned up code, and now the never checkpointing again after a fail error is fixed.
//
// Revision 1.4  2000/06/27 13:22:36  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.3  2000/06/23 16:35:26  phoebe
// Cleaning out un-needed data members in classes.
//
// Revision 1.2  2000/06/02 05:47:23  phoebe
// Hash and Sign of EventInfo working and it will restart and check fine. I think the modification I made to EventInfo for Reads (it's commented as a change in the code...I used << and >> instead of the commented out code) is preventing restart. Need to make sure I understand what is going on with that later.
//
// Revision 1.1.1.1  2000/03/06 20:00:15  phoebe
// Sriram's original code with no modifications
//
// $Id: DeliveredStore_modified.H,v 1.1.1.1 2001/02/12 00:00:15 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu May  6 23:22:32 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu Aug 26 10:25:23 1999
// Update Count    : 69
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Modules for storing event information.  It is very similar to DetStore.H

#if defined(__cplusplus) && !defined(_DELIVERED_LOG_H)
#define _DELIVERED_LOG_H

#include <fstream>
#include <iostream>

#include "Egida_Object.H"
#include "EventStore.H"
#include "Security.H"

class StableDeliveredStore : public EventStore {
public:
  StableDeliveredStore() { 
    this->diskLogBaseName[0] = '\0';
    this->ofs = NULL;
    if(HASH_DETERMINANTS)
      this->sig = NULL;
    this->singleEvInfoCounter = 0;
    this->singleEvInfoHashInit = false;
  };

  StableDeliveredStore(int self, int numP) :
    EventStore(self, numP) {
    
    char fileName[EGIDA_FILENAME_LEN];
    char sigFileName[EGIDA_FILENAME_LEN];

    sprintf(this->diskLogBaseName, "%s/eventLog.%d", EGIDA_LOGS_DIR, self);
    sprintf(fileName, "%s.%d", this->diskLogBaseName,
	    this->lme.logCounter);

    this->ofs = new std::ofstream;
    this->ofs->open(fileName, std::ios::out);

    if(HASH_DETERMINANTS) {
      sprintf(sigFileName, "%s.%s", fileName, "hashes");    
      this->sig = new std::ofstream;
      this->sig->open(sigFileName, std::ios::out);
      this->singleEvInfoHashInit = false;
      this->singleEvInfoCounter = 0;
    }
  };

  ~StableDeliveredStore() {
    char fileName[EGIDA_FILENAME_LEN];
    
    if(this->ofs != NULL) {
      if(this->ofs->is_open()) {
        this->ofs->flush();
        this->ofs->close();
      }
      delete this->ofs;
    }
    if(HASH_DETERMINANTS) {
      if(this->sig != NULL) {
	if(this->sig->is_open()) {
	  this->sig->flush();
	  this->sig->close();
	}
	delete this->sig;
      }
    }
    for (int i = 0; i <= this->lme.logCounter; i++) {
      sprintf(fileName, "%s.%d", this->diskLogBaseName, i);
      // unlink(fileName);
    }
  };

  void Write(EventInfo *eInfo);

   // 	Fetch a previously logged event info. This is needed for
   // 	causal protocols which log sent messages and retrieve a
   // 	message header as part of ack processing.
  void TryRetrieve(int source, int sourceEventId, 
		   int otherProc, EventInfo **eInfo);

  void WriteEvInfoList(int source, EventInfo_List &el);
  void Flush(void) { /*already on disk...nothing to do*/ };
  void CkptDone(void);
  void SetLogFileName(const char *baseName);
  
  // 	Set a callback function that has to be invoked whenever the
  // 	log is written out to stable storage.
  void SetLogStableCallback(void (*stableCallback)(int, int, int, int));

  void GarbageCollect(int source, int sourceEventId);

  void Purge(int source, int eventId);

  // This is for recovery
  void Read(int source, int startEventId, int *lastEventIds);

  // Called from volatile store when data has to be read back.
  void Read(int source, int startEventId,
	    int *lastEventIds, EventInfo_List *retrieve_List);

  // Retrieve eInfo that was created by source such that
  // eInfo.sourceEventId = sourceEventId
  void Read(int source, int sourceEventId, 
	    int otherProc, EventInfo **eInfo);

  // Should only be called for sendLog?
  void Read(int otherProc, int source, int startEventId,
	    EventInfo_List *retrieve_List);

  // Remove any pointers to eInfo from the event store
  void RemovePtr(EventInfo *eInfo);

  // Re-open any logs on disk when the process is re-started...
  void RestartingFromCkpt(void);

  void ReplayDone(void);

   // Ignore control messages
  void ProcessMsg(int source, int tag, const char *msg, int msgSize)
    {return;};

private:
  void CheckLogOutStream(void);
  void CheckSigOutStream(void);

  char diskLogBaseName[EGIDA_FILENAME_LEN];
  LogMetaEntry  lme;
  LogMetaEntry_List lme_List;
  std::ofstream *ofs;
  std::ofstream *sig;
  bool singleEvInfoHashInit;
  int singleEvInfoCounter;
  //cached_list contains the messages pertaining to determinants that we will
  //need to replay in our rollforward phase.
  EventInfo_List cached_List[EGIDA_MAX_PROCS];
};


class VolatileDeliveredStore : public EventStore {
public:
  VolatileDeliveredStore() {
    this->stableStore = NULL;
  };

  VolatileDeliveredStore(int self, int numP) :
    EventStore(self, numP) {    
    this->stableStore = new StableDeliveredStore(self, numP);
  };

  VolatileDeliveredStore(int self, int numP, 
		     EventStore::EventStoreType StableDeliveredStoreType)
    :EventStore(self, numP) {
    switch(StableDeliveredStoreType) {
    case EventStore::EGIDA_STABLE_STORE:
      this->stableStore = new StableDeliveredStore(self, numP);
      break;
    case EventStore::EGIDA_NULL_STORE:
      this->stableStore = new NullEventStore(self, numP);
      break;
    default:
      assert(0);
    }
  };

  ~VolatileDeliveredStore() {
    EventInfo_ListIterator e;
    EventInfo *eInfo;

    for (e = eventInfo[i][j].begin(); 
	 e != eventInfo[i][j].end(); ++e) {
      eInfo = *e;
      delete eInfo;
    }
    eventInfo.clear();
    delete stableStore;
  };

  // 	Add a event info to the volatile log.
  void Write(EventInfo *eInfo);
  void WriteEvInfoList(int source, EventInfo_List &el)
    { /*volatile will only write msgs one at a time*/ };
  
  // Used by causal protocols to retrieve message headers for
  // processing causal protocol ack's
  void TryRetrieve(int source, int sourceEventId, 
		   int otherProc, EventInfo **eInfo);
  
  void Flush(void);
  
  // 	Called after a checkpoint is written out.
  void CkptDone(void);
  
  
  // 	Change the name of the file used for logging info. to stable
  // 	storage. 
  void SetLogFileName(const char *baseName);
  
  // 	Set a callback function that has to be invoked whenever the
  // 	log is written out to stable storage.
  void SetLogStableCallback(void (*stableCallback)(int, int, int, int));
  
  // 	Garbage collect event info from storage.
  void GarbageCollect(int source, int sourceEventId);
  
  void Purge(int source, int eventId);
  
  // 	Retrieve data corresponding to the events that have to be
  // 	replayed. 
  // This is for recovery
  void Read(int source, int startEventId, int *lastEventIds);
  
  // Retrieve eInfo that was created by source such that
  // eInfo.sourceEventId = sourceEventId
  void Read(int source, int sourceEventId, 
	    int otherProc, EventInfo **eInfo);
  // Read the data logged on behalf of otherProc.  The data was
  // generated by source.  This method retrieves the data created by 
  // source from startEventId and returns the resut in retrieve_List
  void Read(int otherProc, int source, int startEventId,
	    EventInfo_List *retrieve_List);

   // 	Retrieve event info. for replay phase of recovery.  This is a
   // 	filler function that needs to be defined because the function
   // 	with this type signature is declared to be virtual.
  void Read(int source, int startEventId,
	    int *lastEventIds, EventInfo_List *retrieve_List);

  // Remove any pointers to eInfo from the event store
  void RemovePtr(EventInfo *eInfo);

   // 	When the process state is restored from a checkpoint, then the 
   // 	meta-data about the log files on disk is out-of-sync.  This
   // 	calls the backing store's RestartFromCkpt().
  // Re-open any logs on disk when the process is re-started...
  void RestartingFromCkpt(void);

   // 	When the process completes replay, this method should be
   // 	called so that any log files stored on disk are re-opened.
  void ReplayDone(void);

   // Ignore control messages
  void ProcessMsg(int source, int tag, const char *msg, int msgSize)
    {return;};
private:
  //eventInfo contains the messages we have delivered.
  EventInfo_List   eventInfo;
  EventStore *stableStore;
};

#endif





