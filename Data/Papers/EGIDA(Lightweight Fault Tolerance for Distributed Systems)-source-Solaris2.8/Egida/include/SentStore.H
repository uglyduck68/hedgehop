// SentLog.H -- 
//                This source is provided as is without any express or
//                written warranty.  Permission to use, copy, modify, and 
//                distribute this software for any purpose without fee is
//                hereby granted, provided that this entire notice is 
//                included in all copies of any software which is or includes
//                a copy or modification of this software and in all copies
//                of the supporting documentation for such software.
//                All Rights Reserved.
// $Locker:  $
// $Log: SentStore.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:13  ravshank
// Start of Spring 2001
//
// Revision 1.6  2000/11/28 17:26:31  phoebe
// Found what is hopefully the last of the memcpy core dumps and fixed it. Was connected with the numSegs variable (it was being set imporperly). Also restructured some of the stats to get a more accurate picture of where time is being spent. In addition, the SentStore is now doing all flushing and garbageCollecting with threads. Need to change the checkpoint to get rid of threads before saving state.
//
// Revision 1.5  2000/11/21 22:27:12  phoebe
// GarbageCollect in the SentStore is now working async. We changed the logic slightly so that all files are cleaned by one process and we clean when we've heard 3 responses (not necessarily all from different processes...this is ok we think.) Also...our favorite core dump on TakeCkpt (the memcpy one) has crept back in the picture. <grrrr>
//
// Revision 1.4  2000/11/10 15:48:49  phoebe
// Checkpoint memory leak is now solved, and so is the memcpy core dump on some checkpoints.
//
// Revision 1.3  2000/10/31 00:22:44  phoebe
// SBP now works with flushing and garbage collection. Before the file out pointers were not being managed properly so after a garbagecollect they were pointing to a non-existant file. So the point of all of this is we have a working SentStore.cc file.
//
// Revision 1.2  2000/10/24 16:32:24  phoebe
// Garbage collection of the sentLog is now happening but sometimes it doesn't recover...think it's a problem with multiple recoveries and not flushing some info. Will check into it. Fixed the memcpy core dump on taking a checkpoint...it was a problem with the fact that we were using a signed int to track the segment size and should have been using an unsigned int so that we didn't get overflow problem.
//
// Revision 1.1  2000/10/20 19:28:42  phoebe
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
// $Id: SentStore.H,v 1.1.1.1 2001/02/12 00:00:13 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu May  6 23:22:32 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu Aug 26 10:25:23 1999
// Update Count    : 69
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Modules for storing event information.  It is very similar to DetStore.H

#if defined(__cplusplus) && !defined(_SENT_LOG_H)
#define _SENT_LOG_H

#include <assert.h>
#include <fstream>
#include <iostream>

#include "EventStore.H"
#include "Egida_Object.H"
#include "Security.H"

//these variables are used to access the ssn ranges in 
//stable and volatile sent store.
#define low 0
#define high 1

//for passing two arguments to a thread from SentStore objects
struct SentStoreThreadArgs {
public:
  SentStoreThreadArgs() {
    object = NULL;
    procId = -1;
  };

  SentStoreThreadArgs(void* obj, int id) {
    object = obj;
    procId = id;
  };

  ~SentStoreThreadArgs() {
    object = NULL;
  }

  void* object;
  int procId;
};



class StableSentStore : public EventStore {
public:
  StableSentStore() { 
    this->diskLogBaseName[0] = '\0';
    for(int i=0; i<EGIDA_MAX_PROCS; i++) {
      ofs[i] = NULL;
      if(HASH_DETERMINANTS)
	sig[i] = NULL;
      ssnInFile[i][low] = -1;
      ssnInFile[i][high] = -1;
      garbageCollectSsn[i] = -1;
      gcThreadId[i] = -1;
    }
    singleEvInfoCounter = 0;
    singleEvInfoHashInit = false;
    fileNameInited = false;
  };

  StableSentStore(int self, int numP) :
    EventStore(self, numP) {
    sprintf(diskLogBaseName, "%s/sentLog.%d", EGIDA_LOGS_DIR, self);
    for(int i=0; i< EGIDA_MAX_PROCS; i++) {
      ofs[i] = NULL;
      sig[i] = NULL;
      garbageCollectSsn[i] = -1;
      gcThreadId[i] = -1;
      //only instantiate the ones we will need
      if(i < numP) {
	CheckLogOutStream(i);
	ssnInFile[i][low] = -1;
	ssnInFile[i][high] = -1;

	if(HASH_DETERMINANTS) {
	  CheckSigOutStream(i);
	  singleEvInfoCounter = 0;
	  singleEvInfoHashInit = false;
	}
      }
    }
    fileNameInited = false;

  };

  ~StableSentStore() {
    for(int i=0; i< EGIDA_MAX_PROCS; i++) {
      if(ofs[i] != NULL) {
        ofs[i]->close();
        delete ofs[i];
      }
      if(HASH_DETERMINANTS) {
	if(sig[i] != NULL) {
	  sig[i]->close();
	  delete sig[i];
	}
      }
    }
  };

  void Write(EventInfo *eInfo);
  
   // 	Fetch a previously logged event info. This is needed for
   // 	causal protocols which log sent messages and retrieve a
   // 	message header as part of ack processing.
  void TryRetrieve(int source, int sourceEventId, 
		   int otherProc, EventInfo **eInfo);
  
  int WriteEvInfoList(int source, EventInfo_List &el);
  void Flush(void) { };
  void AsyncFlush(void) { };
  void CkptDone(void);
  void SetLogFileName(const char *baseName);
  
   // 	Set a callback function that has to be invoked whenever the
   // 	log is written out to stable storage.
  void SetLogStableCallback(void (*stableCallback)(int, int, int, int))
    //{ LogStableCallback = stableCallback; };
    { LogStableCallback = NULL; } ;
  void GarbageCollect(int source, int sourceEventId);
  void SetGarbageCollectSsn(int source, int gcSSN);

  void GarbageCollect(int source, int sourceEventId, int otherProc) 
    { GarbageCollect(otherProc, sourceEventId); };
  void Purge(int source, int eventId);

  // This is for recovery
  void Read(int source, int startEventId, int *lastEventIds)
    { assert(0); };

  // Called from volatile store when data has to be read back.
  void Read(int source, int startEventId,
	    int *lastEventIds, EventInfo_List *retrieve_List)
    { assert(0); };

  // Retrieve eInfo that was created by source such that
  // eInfo.sourceEventId = sourceEventId
  void Read(int source, int sourceEventId, 
	    int otherProc, EventInfo **eInfo)
    { assert(0); };

  // Read the data logged on behalf of otherProc.  The data was
  // generated by source.  This method retrieves the data created by 
  // source from startEventId and returns the resut in retrieve_List
  void Read(int otherProc, int source, int startEventId,
	    EventInfo_List *retrieve_List);

  // Remove any pointers to eInfo from the event store
  void RemovePtr(EventInfo *eInfo);

  // Re-open any logs on disk when the process is re-started...
  void RestartingFromCkpt(void);

  void ReplayDone(void);

  void ProcessMsg(int source, int tag, const char *msg, int msgSize);
  
  void ResetGCThreadId(int source);

  EventInfo* flushEventInfo[EGIDA_MAX_PROCS];
  int GetSsnInFileHigh(int source);

private:

  void CheckLogOutStream(int id);
  void SetupLogFileName(char **buf, int count);

  void CheckSigOutStream(int id);
  void SetupSigFileName(char **buf, int otherProc);

  //this array contains the spread of ssn's for each process
  //that we have in file.
  char diskLogBaseName[EGIDA_FILENAME_LEN];
  int ssnInFile[EGIDA_MAX_PROCS][2];
  pthread_t gcThreadId[EGIDA_MAX_PROCS];
  int garbageCollectSsn[EGIDA_MAX_PROCS];
  std::ofstream * ofs[EGIDA_MAX_PROCS];
  std::ofstream * sig[EGIDA_MAX_PROCS];
  bool singleEvInfoHashInit;
  int singleEvInfoCounter;
  bool fileNameInited;

  void UpdateSsnInFileCount(int otherProc, int seid);
};

class VolatileSentStore : public EventStore {
public:
  VolatileSentStore() {
    this->stableStore = NULL;
    isFlushing = false;
    flushThreadId = -1;
    for(int i=0; i < EGIDA_MAX_PROCS; i++) {
      ssnInMemory[i][low] = -1;
      ssnInMemory[i][high] = -1;
      flushSsn[i] = -1;
      isGarbageCollecting[i] = false;
      gcThreadId[i] = -1;
      garbageCollectMemorySsn[i] = -1;
    }    
   };
  
  VolatileSentStore(int self, int numP) :
    EventStore(self, numP) {    
    this->stableStore = new StableSentStore(self, numP);
    isFlushing = false;
    flushThreadId = -1;
    for(int i=0; i < numP; i++) {
      ssnInMemory[i][low] = -1;
      ssnInMemory[i][high] = -1;
      flushSsn[i] = -1;
      isGarbageCollecting[i] = false;
      gcThreadId[i] = -1;
      garbageCollectMemorySsn[i] = -1;
    }
  };
  
  VolatileSentStore(int self, int numP, 
		    EventStore::EventStoreType StableSentStoreType)
    :EventStore(self, numP) {
    switch(StableSentStoreType) {
    case EventStore::EGIDA_STABLE_STORE:
      this->stableStore = new StableSentStore(self, numP);
      break;
    case EventStore::EGIDA_NULL_STORE:
      this->stableStore = new NullEventStore(self, numP);
      break;
    default:
      assert(0);
    }
    isFlushing = false;
    flushThreadId = -1;
    for(int i=0; i < numP; i++) {
      ssnInMemory[i][low] = -1;
      ssnInMemory[i][high] = -1;
      flushSsn[i] = -1;
      isGarbageCollecting[i] = false;
      gcThreadId[i] = -1;
      garbageCollectMemorySsn[i] = -1;
    }
  };
  
  ~VolatileSentStore() {
    EventInfo_ListIterator e;
    EventInfo *eInfo;
    
    for (int i = 0; i < this->numProcs; i++) {
      for (e = this->eventInfo[i].begin(); 
	   e != this->eventInfo[i].end(); ++e) {
	eInfo = *e;
	this->eventInfo[i].erase(e);
	delete eInfo;
      }
      this->eventInfo[i].clear();
    }
    delete this->stableStore;
  };
  
  // 	Add a event info to the volatile log.
  void Write(EventInfo *eInfo);
  
  int WriteEvInfoList(int source, EventInfo_List &el) {return -1; };
  
  // Used by causal protocols to retrieve message headers for
  // processing causal protocol ack's
  void TryRetrieve(int source, int sourceEventId, 
		   int otherProc, EventInfo **eInfo);
  void Flush(void);
  void FlushClean(void);
  void AsyncFlush(void){};

  // 	Called after a checkpoint is written out.
  void CkptDone(void);
  
   // 	Change the name of the file used for logging info. to stable
   // 	storage. 
  void SetLogFileName(const char *baseName)
    { stableStore->SetLogFileName(baseName); };

   // 	Set a callback function that has to be invoked whenever the
   // 	log is written out to stable storage.
  void SetLogStableCallback(void (*stableCallback)(int, int, 
						   int, int))
    { stableStore->SetLogStableCallback(stableCallback); };

   // 	Garbage collect event info from storage.
  void GarbageCollect(int source, int sourceEventId);

   // 	Garbage collect event info from storage.
  void GarbageCollect(int source, int sourceEventId, int otherProc)
    { GarbageCollect(otherProc, sourceEventId); };

  void Purge(int source, int eventId);

   // 	Retrieve data corresponding to the events that have to be
   // 	replayed. 
  // This is for recovery
  void Read(int source, int startEventId, int *lastEventIds)
    { stableStore->Read(Egida::GetMyId(), startEventId, lastEventIds); };

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
	    int *lastEventIds, EventInfo_List *retrieve_List)
    { memset(lastEventIds, 0, EGIDA_MAX_PROCS * sizeof(int)); };

  // Remove any pointers to eInfo from the event store
  void RemovePtr(EventInfo *eInfo);

   // 	When the process state is restored from a checkpoint, then the 
   // 	meta-data about the log files on disk is out-of-sync.  This
   // 	calls the backing store's RestartFromCkpt().
  // Re-open any logs on disk when the process is re-started...
  void RestartingFromCkpt(void);

   // 	When the process completes replay, this method should be
   // 	called so that any log files stored on disk are re-opened.
  void ReplayDone(void)
    { stableStore->ReplayDone(); };

   // Purge msgs from log for source
  void ProcessMsg(int source, int tag, const char *msg, int msgSize);

  void ResetGCThreadId(int source);
  void ResetFlushThreadId(void);

  bool IsFlushing() { return isFlushing; };
  void setFlushing() { isFlushing = true; };

  bool IsGarbageCollecting(int proc) { return isGarbageCollecting[proc]; };
  void setGarbageCollecting(int proc) { isGarbageCollecting[proc] = true; };

  int ssnInMemory[EGIDA_MAX_PROCS][2];
  int flushSsn[EGIDA_MAX_PROCS];
  // eventInfo[j] -- j is the process to which the msg was sent (dest)
  EventInfo_List eventInfo[EGIDA_MAX_PROCS];
  EventStore *stableStore;
  EventInfo* flushEventInfo[EGIDA_MAX_PROCS];

private:
  pthread_t flushThreadId;
  bool isFlushing;
  pthread_t gcThreadId[EGIDA_MAX_PROCS];
  bool isGarbageCollecting[EGIDA_MAX_PROCS];
  int garbageCollectMemorySsn[EGIDA_MAX_PROCS];
  EventInfo* gcEventInfo[EGIDA_MAX_PROCS];
};


#endif // _SENT_LOG_H

