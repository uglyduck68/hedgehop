// DetStore.H -- 
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
// $Log: DetStore.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:12  ravshank
// Start of Spring 2001
//
// Revision 1.5  2000/11/01 19:49:37  phoebe
// Hashing determinants now works again.
//
// Revision 1.4  2000/11/01 16:35:22  phoebe
// Working on getting security to work again with the redesigned system. Message encryption, either full or only egida messages, is working now.
//
// Revision 1.3  2000/06/27 13:22:29  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.2  2000/03/17 18:08:46  phoebe
// Encryption of determinants is now in place. Also I added members to DetStore.H class to handle the upcoming hash and sign hooks that will be needed for that functionality with determinants.
//
// Revision 1.1.1.1  2000/03/06 20:00:13  phoebe
// Sriram's original code with no modifications
//
// $Id: DetStore.H,v 1.1.1.1 2001/02/12 00:00:12 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu May  6 14:47:50 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu Aug 26 09:42:43 1999
// Update Count    : 87
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_DET_STORE_H)
#define _DET_STORE_H

#include <assert.h>
#include <fstream>
#include <iostream>
#include <strstream>

#include "Determinant.H"
#include "Globals.H"
#include "LogMeta.H"
#include "Security.H"

class DetStore {
public:
  enum DetStoreType {EGIDA_NULL_STORE, EGIDA_VOLATILE_STORE,
		     EGIDA_STABLE_STORE};
  DetStore() {
    this->id = -1;
    this->numProcs = 0;
    this->LogStableCallback = NULL;
    this->nextToReplay = NULL;
    this->nextToReplay_List = NULL;
  };
  ~DetStore() { };
  DetStore(int self, int numP) {
    this->id = self;
    this->numProcs = numP;
    this->LogStableCallback = NULL;
    this->nextToReplay = NULL;
  };
  // This is for failure-free execution
  virtual void Write(Determinant *d) = 0;
  virtual void Flush(void) = 0;
  virtual void FlushClean(void) { };
  virtual void CkptDone(void) = 0;
  virtual void SetLogFileName(const char *baseName) = 0;
  virtual void SetLogStableCallback(void (*stableCallback)(int)) { };

  // This is for writing out a list of determinants
  virtual void WriteDetList(const Determinant_List &dl) { };

  // gc means discard dets d such that d.d_esn < detId
  virtual void GarbageCollect(int procId, int detId) = 0;
  // purge means discard dets d such that d.d_esn >= detId
  virtual void Purge(int procId, int detId) = 0;

  virtual void ReplayDone(void) = 0;

  // This is for recovery
  virtual void Read(int self, int eventId, Determinant **matchingDet) = 0;
  virtual void Read(int self, int startEventId, int *lastEventId) = 0;
  // This is for helping the recovery of recovering process
  virtual void Read(int recoveringProc, int startEventId, 
		    char **dets, int *detSize) = 0;
  // Called by the volatile store when it needs some determinants
  // retrieved from the stable store.  Since stable store can be NULL
  // store, as default, don't do anything.
  virtual void Read(int procId, int startEventId, int *lastEventId, 
		    Determinant_List *retrieve_List) = 0;
  // retrieve determinant d such that d.dest = self and 
  // d.d_esn >= eventId, where d is the closest determinant to eventId
  virtual bool GetNextDet(int self, int eventId, 
			  Determinant **matchingDet) = 0;

  // This is for causal logging protocols.
  virtual void Write(int source, const char *detBuf, int detBufSize, int *detIds) = 0;
  virtual void RetrieveNonstable(int dest, const int *knownDetId, 
				 std::ostrstream &os) {
    os << 0 << ' ' << std::ends;
  };
  virtual void RetrieveDetIds(const char *detBuf, int detBufSize, int *detId) {
    memset(detId, 0, EGIDA_MAX_PROCS * sizeof(int));
  };
  virtual void MarkStable(int *detId) { };
  virtual void MarkLogStable(void) { };
  virtual void UpdateLoggedAt(int dest, const int *detId) { };

  virtual void RestartingFromCkpt(void) = 0;
protected:
  int id;
  int numProcs;

  Determinant *nextToReplay;
  Determinant_ListIterator nextToReplay_Iterator;
  Determinant_List *nextToReplay_List;

  // This is a utility function.
  void PrintDetList(const Determinant_List &detList, std::ostrstream
		    &os);
  void (*LogStableCallback)(int);
};

class NullDetStore : public DetStore {
public:
  NullDetStore() { };
  NullDetStore(int self, int numP) :
    DetStore(self, numP) { };
  void Write(Determinant *d);
  void Write(int source, const char *detBuf, int detBufSize, int *detIds) { 
    memset(detIds, 0, EGIDA_MAX_PROCS * sizeof(int));
  };
  void Flush(void) { };
  void CkptDone(void) { };
  void GarbageCollect(int procId, int detId) { };
  void Purge(int procId, int detId) { };
  void SetLogFileName(const char *baseName) { };

  void ReplayDone(void) { };

  void Read(int self, int eventId, Determinant **matchingDet) {
    *matchingDet = NULL;
  };
  void Read(int self, int startEventId, int *lastEventId) {
    *lastEventId = 0;
  };
  // This is for helping the recovery of recovering process
  void Read(int recoveringProc, int startEventId, char **dets, int *detSize) {
    *dets = NULL;
    *detSize = 0;
  };
  void Read(int procId, int startEventId, int *lastEventId, 
	    Determinant_List *retrieve_List) {
    *lastEventId = startEventId;
  };
  // this is needed during recovery of this process.
  bool GetNextDet(int self, int eventId, Determinant **matchingDet) {
    return false;
  };

  void RestartingFromCkpt(void) { };
};



class StableDetStore : public DetStore {
public:

  StableDetStore() { 
    this->diskLogBaseName[0] = '\0';
    memset(this->gcDets, 0, EGIDA_MAX_PROCS * sizeof(int));
    this->ofs = NULL;
    this->sigFd = NULL;
    this->singleDetCounter = 0;
    this->singleDetHashInit = false;
  };

  StableDetStore(int self, int numP) :
    DetStore(self, numP) {
    char fileName[EGIDA_FILENAME_LEN];

    memset(this->gcDets, 0, EGIDA_MAX_PROCS * sizeof(int));
    sprintf(this->diskLogBaseName, "%s/detLog.%d", EGIDA_LOGS_DIR, self);
    sprintf(fileName, "%s.%d", this->diskLogBaseName, this->lme.logCounter);

    this->ofs = new std::ofstream;
    this->ofs->open(fileName, std::ios::out);  

    if(HASH_DETERMINANTS) {
      char sigFileName[EGIDA_FILENAME_LEN];
      sprintf(sigFileName, "%s.%s", fileName, "hashes");

      this->sigFd = new std::ofstream;
      this->sigFd->open(sigFileName, std::ios::out);
      
      this->singleDetHashInit = false;
      this->singleDetCounter = 0;
    }
  };

  ~StableDetStore() {
    if(this->ofs != NULL) {
      if(this->ofs->is_open()) {
	this->ofs->flush();
	this->ofs->close();
      }
      delete this->ofs;
    }

    if(this->sigFd != NULL) {
      if(this->sigFd->is_open()) {
	this->sigFd->flush();
	this->sigFd->close();
      }
      delete this->sigFd;
    }
  };

  void Write(Determinant *d);

  // Ths is for causal logging
  void Write(int source, const char *detBuf, int detBufSize, int *detIds) { 
    memset(detIds, 0, EGIDA_MAX_PROCS * sizeof(int));
  };

  // This is for flushing dets from volatile store to stable store
  void WriteDetList(const Determinant_List &dl);
  void Flush(void) { };
  void CkptDone(void);
  void GarbageCollect(int procId, int detId);
  void Purge(int procId, int detId);

  void ReplayDone(void);

  void SetLogFileName(const char *baseName);
  void SetLogStableCallback(void (*stableCallback)(int));
  
  // This is for recovery
  void Read(int self, int eventId, Determinant **matchingDet);
  void Read(int self, int startEventId, int *lastEventId);

  // This is for helping the recovery of recovering process
  void Read(int recoveringProc, int startEventId, char **dets, int *detSize);
  
  // This is needed for the recovery of this process
  bool GetNextDet(int self, int eventId, Determinant **matchingDet);

  // Called by the volatile store when it needs some determinants retrieved
  void Read(int procId, int startEventId, int *lastEventId, 
	    Determinant_List *retrieve_List);

  // Need to reset the meta-data entries after a restart...
  void RestartingFromCkpt(void);

private:
  // gcDets[i] contains the determinant Id of process i that can be
  // thrown away.  Since each log file on disk corresponds to a
  // checkpoint, a file can be discarded only when all determinants in 
  // that file can be garbage collected. 
  int gcDets[EGIDA_MAX_PROCS];
  char diskLogBaseName[EGIDA_FILENAME_LEN];
  LogMetaEntry  lme;
  LogMetaEntry_List lme_List;
  Determinant_List cached_List;
  std::ofstream *ofs;
  std::ofstream *sigFd;
  bool singleDetHashInit;
  int singleDetCounter;
  void PurgeDetsOnDisk(int procId, int purgeStartDet);
};

class VolatileDetStore : public DetStore {
public:
  VolatileDetStore() {
    this->stableStore = NULL;
    memset(this->stableDets, 0, EGIDA_MAX_PROCS * sizeof(int));
  };
  VolatileDetStore(int self, int numP) :
    DetStore(self, numP) {
    this->stableStore = new StableDetStore(self, numP);
    memset(this->stableDets, 0, EGIDA_MAX_PROCS * sizeof(int));
  };
  VolatileDetStore(int self, int numP, DetStore::DetStoreType stableDetStoreType) :
    DetStore(self, numP) {
    switch(stableDetStoreType) {
    case DetStore::EGIDA_STABLE_STORE:
      this->stableStore = new StableDetStore(self, numP);
      break;
    case DetStore::EGIDA_NULL_STORE:
      this->stableStore = new NullDetStore(self, numP);
      break;
    default:
      assert(0);
    }
    memset(this->stableDets, 0, EGIDA_MAX_PROCS * sizeof(int));
  };
  ~VolatileDetStore() {
    int i;
    Determinant_ListIterator e;
    Determinant *d;

    for (i = 0; i < this->numProcs; i++) {
      for (e = this->nonStable[i].begin(); e != this->nonStable[i].end(); ++e) {
	d = *e;
	delete d;
      }
      for (e = this->stable[i].begin(); e != this->stable[i].end(); ++e) {
	d = *e;
	delete d;
      }
      this->stable[i].clear();
      this->nonStable[i].clear();
    }
    delete this->stableStore;
    
  };
  // This is for failure-free execution
  void Write(Determinant *d);
  void Flush(void);
  void FlushClean(void);
  void CkptDone(void);

  void GarbageCollect(int procId, int detId);
  void Purge(int procId, int detId);

  void SetLogFileName(const char *baseName);
  void SetLogStableCallback(void (*stableCallback)(int));

  void ReplayDone(void);

  // This is for recovery
  void Read(int self, int eventId, Determinant **matchingDet);
  void Read(int self, int startEventId, int *lastEventId);
  // This is for helping the recovery of recovering process
  void Read(int recoveringProc, int startDetId, char **dets, int
	    *detSize);
  void Read(int procId, int startEventId, int *lastEventId, 
	    Determinant_List *retrieve_List) {
    *lastEventId = startEventId;
  };

  // This is needed for the recovery of this process
  bool GetNextDet(int self, int eventId, Determinant **matchingDet);

  // This is for causal logging 
  void Write(int source, const char *detBuf, int detBufSize, int *detIds);
  void RetrieveNonstable(int dest, const int *knownDetId, 
			 std::ostrstream &os);
  void RetrieveDetIds(const char *detBuf, int detBufSize, int *detId);
  void MarkStable(int *detId);
  void MarkLogStable(void);
  void UpdateLoggedAt(int dest, const int *detId);

  // Need to reset the meta-data entries after a restart...
  void RestartingFromCkpt(void);

private:
  int stableDets[EGIDA_MAX_PROCS];
  Determinant_List nonStable[EGIDA_MAX_PROCS], stable[EGIDA_MAX_PROCS];
  DetStore *stableStore;

  void MergeDets(int source, int dest, Determinant_List &dl);
};

#endif
