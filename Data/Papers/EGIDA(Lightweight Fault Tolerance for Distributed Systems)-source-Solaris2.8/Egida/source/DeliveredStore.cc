// DeliveredStore.cc -- 
//                This source is provided as is without any express or
//                written warranty.  Permission to use, copy, modify, and 
//                distribute this software for any purpose without fee is
//                hereby granted, provided that this entire notice is 
//                included in all copies of any software which is or includes
//                a copy or modification of this software and in all copies
//                of the supporting documentation for such software.
//                All Rights Reserved.
// $Locker:  $
// $Log: DeliveredStore.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:17  ravshank
// Start of Spring 2001
//
// Revision 1.3  2000/11/21 22:27:13  phoebe
// GarbageCollect in the SentStore is now working async. We changed the logic slightly so that all files are cleaned by one process and we clean when we've heard 3 responses (not necessarily all from different processes...this is ok we think.) Also...our favorite core dump on TakeCkpt (the memcpy one) has crept back in the picture. <grrrr>
//
// Revision 1.2  2000/11/15 22:12:27  phoebe
// Sanity check.
//
// Revision 1.1  2000/10/20 19:28:43  phoebe
// SentLog class is now integrated and works so protocols using the sentLog to store information will now restart on flushing.
//
// Revision 1.17  2000/10/17 15:02:31  phoebe
// Stable code checkin. RBP is extremely stable except if you kill the master and slave at exactly the same time....it will hang in ReplayDeliver. SBP cannot support concurrent failures due to the lost control messages or hanging in ReplayDeliver. Causal can do +concurrent+ failures as long as control messages are not lost....so the restart must be staggered. Causal seems to suffer the same RBP problem with a master/slave pair, but unsure if this is the problem or if I didn't set numfailures=2...think the later would fix this. All the sentLog protocols (SBP and Causal) suffer from processes dumping core during WriteCkpt if they have been running for a long time since we are not flushing volatile memory at the moment. Should go away with the proper sentLog class fix.
//
// Revision 1.16  2000/09/27 22:03:07  phoebe
// In CkptImpl changed the growing of the heap from a strict monotonically increasing function (using the check that we only grow if size is less than what is needed) to one that can shrink. The reason we can do this is sbrk will take as an argument a negative value, where as malloc cannot.
//
// Revision 1.15  2000/08/17 21:11:19  phoebe
// Optimistic protocol is now running to completion, but it's still not totally proper in that it still will only recover if we avoid the flush race condition.
//
// Revision 1.14  2000/08/09 15:32:52  phoebe
// Changed the buffer size in CkptImpl.cc to be a #define instead of being hardwired to 4096. Also made fix in DetStore.cc and EventStore.cc that will allow both writing dets one at at time and in lists to be viable when hashing is turned on. Before this would have caused problems.
//
// Revision 1.13  2000/08/08 20:57:16  phoebe
// Cleaned up code, and now the never checkpointing again after a fail error is fixed.
//
// Revision 1.12  2000/08/08 14:28:56  phoebe
// Can now restart multiple times and kill the master process for Receiver Based Pessimistic logging. Same thing for Sender Based, but with sender based since the recovery logs must be in volatile memory, it will eventually run out of RAM and won't be able to continue or restart (obviously). This is a protocol design bug that will be fixed, but the restart is stable. Also able to restart from an incremental checkpoint (tested with RBP). These restart tests were done without any security turned on.
//
// Revision 1.11  2000/07/13 16:47:45  phoebe
// Established that the changes I made to EventStore.cc are not the causes of the failing to restart multiple times or the failing to restart from an incremetal checkpoint. So I got rid of the commented out code from the file.
//
// Revision 1.10  2000/06/27 13:23:06  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.9  2000/06/23 16:35:34  phoebe
// Cleaning out un-needed data members in classes.
//
// Revision 1.8  2000/06/23 02:47:39  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.7  2000/06/22 20:59:05  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.6  2000/06/02 22:43:05  phoebe
// Added Encryption and Hash and Sign handling to PurgeDetsOnDisk subroutine in DetStore.cc but when testing on cg.B.4 with SBP logging it ran out of memory (the famous p4_shmalloc error)...so need to figure out where the leak is.
//
// Revision 1.5  2000/06/02 19:55:08  phoebe
// The code now compiles with the Encryption and the Hash and Sign functionality added to EventStore's PurgeOnDisk subroutine. Still need to test that it will run, and need to add same functionality to DetStore.cc
//
// Revision 1.4  2000/06/02 05:47:26  phoebe
// Hash and Sign of EventInfo working and it will restart and check fine. I think the modification I made to EventInfo for Reads (it's commented as a change in the code...I used << and >> instead of the commented out code) is preventing restart. Need to make sure I understand what is going on with that later.
//
// Revision 1.3  2000/06/02 04:13:16  phoebe
// Encryption of EventInfo now working.
//
// Revision 1.2  2000/03/07 16:58:36  phoebe
// Got optimistic logging to restart, although I really don't understand what it is doing since it seems to be rolling back all processes. To get optimistic logging to restart I had to catch a ofs==NULL error in EventStore.cc
//
// Revision 1.1.1.1  2000/03/06 20:00:20  phoebe
// Sriram's original code with no modifications
//
// $Id: DeliveredStore.cc,v 1.1.1.1 2001/02/12 00:00:17 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu May  6 23:28:34 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu Aug 26 10:40:51 1999
// Update Count    : 212
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <assert.h>
#include <errno.h>
#include <iostream>
#include <strstream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "DeliveredStore.H"
#include "EventStore.H"
#include "Egida_Object.H"
#include "Globals.H"
#include "Stats.H"
#include "Timer.H"
#include "Egida_Object.H"


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Add a event info to the volatile log.
// 
// Arguments:
//      procId --- process for which the event info is being logged for.
// 	eInfo --- pointer to the event info that has to be added.  After
// 	this method call, the caller SHOULD NOT refer to eInfo.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void VolatileDeliveredStore::Write(EventInfo *eInfo)
{  
  struct timeval timeStart;
  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  this->eventInfo[eInfo->source][eInfo->otherProc].push_back(eInfo);

  if(COLLECTING_STATS) {
    struct timeval timeEnd;
    double timeSpent = 0.0;
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_EVENT_INFO_WRITE_STAT, 0, timeSpent);
  }

}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve a previously logged event info.  This is needed for
// 	causal protocols which log sent messages and retrieve a
// 	message header as part of ack processing.  There is no
// 	guarantee that the message being fetched will be in volatile
// 	storage at the time of this call.
// 
// Arguments:
// 	<source, sourceEventId> --- event for which info has to be
// 	    read
//      otherProc --- other process involved in the event
//      eInfo --- output parameter
// 
// Results:
// 	eInfo --- resulting pointer to event info.  The caller of this 
// 	method SHOULD NOT delete eInfo.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void VolatileDeliveredStore::TryRetrieve(int source, int sourceEventId, 
				     int otherProc, EventInfo **eInfo)
{
  int i;
  EventInfo *info;
  EventInfo_ListIterator e;

  *eInfo = NULL;
  for (e = this->eventInfo[source][otherProc].begin(); e !=
	 this->eventInfo[source][otherProc].end(); ++e) {
    info = *e;
    if (info->sourceEventId == sourceEventId) {
      *eInfo = info;
      break;
    }
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Write out all the event info to stable storage.  Garbage
// 	collect the storage for the event info's that were written out.
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


void VolatileDeliveredStore::Flush()
{
  int i, j;
  int flushedSourceEventId = 0;
  EventInfo *eInfo;

  //  std::cout << Egida::GetMyId() << "FLUSH : DeliveredStore flushed"  << std::endl;
  for (i = 0 ; i < this->numProcs; i++) {
    for (j = 0; j < this->numProcs; j++) {
      if (this->eventInfo[i][j].size() > 0) {
	stableStore->WriteEvInfoList(i, this->eventInfo[i][j]);
      }
    }
  }

  for (i = 0 ; i < this->numProcs; i++) {
    for (j = 0; j < this->numProcs; j++) {
      if (this->eventInfo[i][j].size() > 0) {
	flushedSourceEventId = eventInfo[i][j].back()->sourceEventId;
	GarbageCollect_List(i, flushedSourceEventId, j);
      }
    }
  }

}

void VolatileDeliveredStore::FlushClean()
{
  int i, j;
  int flushedSourceEventId = 0;
  EventInfo *eInfo;

  for (i = 0 ; i < this->numProcs; i++) {
    for (j = 0; j < this->numProcs; j++) {
      if (this->eventInfo[i][j].size() > 0) {
	flushedSourceEventId = eventInfo[i][j].back()->sourceEventId;
	GarbageCollect_List(i, flushedSourceEventId, j);
      }
    }
  }

}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Change the name of the file used for logging info. to stable
// 	storage. 
// 
// Arguments:
// 	baseName --- is the base file name (for example, eventLog) from
// 	which other log files of this event store will be constructed.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void VolatileDeliveredStore::SetLogFileName(const char *baseName)
{
  this->stableStore->SetLogFileName(baseName);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Garbage collect event info from storage.
// 
// Arguments:
// 	source, sourceEventId: Discard event info. created by source
// 	     with eInfo->sourceEventId < sourceEventId.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void VolatileDeliveredStore::GarbageCollect(int source, int sourceEventId)
{
  int otherProc;

  this->stableStore->GarbageCollect(source, sourceEventId);

  struct timeval timeStart;
  if(COLLECTING_STATS) { 
    gettimeofday(&timeStart, NULL);
  }

  GarbageCollect_List(source, sourceEventId, Egida::GetMyId());    

  if(COLLECTING_STATS) {
    struct timeval timeEnd;
    double timeSpent = 0.0;
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_LOG_GARBAGE_COLLECT_STAT, 0, timeSpent);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Garbage collect event info from storage.
// 
// Arguments:
//      otherProc: other process on behalf of which data is logged by
//                 this process.
// 	source, sourceEventId: Discard event info. created by source
// 	     with eInfo->sourceEventId < sourceEventId.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void VolatileDeliveredStore::GarbageCollect(int source, int sourceEventId,
					int otherProc)
{
  this->stableStore->GarbageCollect(source, sourceEventId, otherProc);

  struct timeval timeStart;
  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  GarbageCollect_List(source, sourceEventId, otherProc);

  if(COLLECTING_STATS) {
    struct timeval timeEnd;
    double timeSpent = 0.0;
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_LOG_GARBAGE_COLLECT_STAT, 0, timeSpent);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	This is a helper function that is called from the two flavors
// 	of GarbageCollect().
// 
// Arguments:
//      otherProc: other process on behalf of which data is logged by
//                 this process.
// 	source, sourceEventId: Discard event info. created by source
// 	     with eInfo->sourceEventId < sourceEventId.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void VolatileDeliveredStore::GarbageCollect_List(int source, int sourceEventId,
					     int otherProc)
{
  EventInfo_ListIterator e, first;
  EventInfo *eInfo;
  bool needToErase = false;
  int discardedId = -1;

  first = this->eventInfo[source][otherProc].end();
  e = this->eventInfo[source][otherProc].begin(); 

  // Although this loop looks horrible, it is doing something very
  // simple:  Iterate thru the list and discard only those that can be 
  // garbage collected.  The problem is that any call to erase() makes 
  // the list iterator unusable.  So, find a sequence of list elements 
  // that can be erased and then throw them away in one shot.  A
  // detail is that erase doesn't call delete to free up storage.
  // Hence, the elements to be deleted are first deleted by calling
  // "delete" and then the pointers to those objects in the list are
  // erased by calling erase.
  while (e != this->eventInfo[source][otherProc].end()) {
    eInfo = *e;
    if (eInfo->sourceEventId < sourceEventId) {
      discardedId = eInfo->sourceEventId;
      // empty sequence
      if (first == this->eventInfo[source][otherProc].end())
	first = e;
      // aggregate the list of things to be erased
      needToErase = true;
      ++e;
      // free up the buffer that used by eInfo
      delete eInfo;
    }
    else if (needToErase) {
      needToErase = false;
      // Erase removes list elements from first to e - 1.
      this->eventInfo[source][otherProc].erase(first, e);

      // after the erase call, e is no longer usable.  so reset e
      e = this->eventInfo[source][otherProc].begin();
      first = this->eventInfo[source][otherProc].end();
    }
    else
      ++e;
  }

  if (needToErase) {
    needToErase = false;
    this->eventInfo[source][otherProc].erase(first, e);
  }  
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	When the process state is restored from a checkpoint, then the 
// 	meta-data about the log files on disk is out-of-sync.  This
// 	calls the backing store's RestartFromCkpt().
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

void VolatileDeliveredStore::RestartingFromCkpt(void)
{
  this->stableStore->RestartingFromCkpt();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	When the process completes replay, this method should be
// 	called so that any log files stored on disk are re-opened.
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

void VolatileDeliveredStore::ReplayDone(void)
{
  this->stableStore->ReplayDone();
}



// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Throw away event info from storage.
// 
// Arguments:
// 	source, sourceEventId: Discard event info. created by source
// 	     with eInfo->sourceEventId >= sourceEventId.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void VolatileDeliveredStore::Purge(int source, int sourceEventId)
{
  EventInfo_ListIterator e, eraseStart;
  EventInfo *eInfo;

  this->stableStore->Purge(source, sourceEventId);
  for (int i = 0; i < this->numProcs; i++) {
    for (e = this->eventInfo[source][i].begin(); 
	 e != this->eventInfo[source][i].end(); ++e) { 
      eInfo = *e;
      if (eInfo->sourceEventId >= sourceEventId) {
	// start erasing from here
	break;
      }
    }
    eraseStart = e;
    for (; e != this->eventInfo[source][i].end(); ++e) { 
      eInfo = *e;
      delete eInfo;
    }
    this->eventInfo[source][i].erase(eraseStart,
				     this->eventInfo[source][i].end());
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Called after a checkpoint is written out.
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
void VolatileDeliveredStore::CkptDone()
{
  this->stableStore->CkptDone();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve data corresponding to the events that have to be
// 	replayed. 
// 
// Arguments:
// 	self --- id of this process
//      startEventId --- retrieve data d from stable store such that 
//         d.eventId >= startEventId
//      lastEventIds --- output parameter
// 
// Results:
// 	  lastEventIds --- a vector in which lastEventIds[i] is the id of the
// 	   last message m retrieved from stable storage, where m is a
// 	   message that process i sent to this process 
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void VolatileDeliveredStore::Read(int self, int startEventId,
			      int *lastEventIds)
{
  this->stableStore->Read(self, startEventId, lastEventIds);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve the data corresponding to a determinant which has to
// 	be replayed.
// 
// Arguments:
// 	source --- process that created the eInfo 
//      sourceEventId --- event id corresponding to the data that has
//             be read back.
//      otherProc --- other process involved in the event.
//      eInfo --- output parameter
//
// Results:
// 	eInfo --- is a pointer to the matching event info that has
// 	been retrieved. The caller SHOULD NOT free eInfo.  The only
// 	exception to this requirement is that, after this method call, 
// 	the caller SHOULD CALL RemovePtr() method exported by this object.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void VolatileDeliveredStore::Read(int source, int sourceEventId,
			      int otherProc, EventInfo **eInfo)
{
  EventInfo_ListIterator e;
  EventInfo *tempInfo;

  this->stableStore->Read(source, sourceEventId, otherProc, eInfo);
  if (*eInfo != NULL)
    return;

  *eInfo = NULL;

  for (e = this->eventInfo[source][otherProc].begin();
       e != this->eventInfo[source][otherProc].end(); ++e) {
    tempInfo = *e;
    if (tempInfo->sourceEventId == sourceEventId) {
      *eInfo = tempInfo;
      break;
    }
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve data logged on behalf of otherProc. Needed when
// 	Egida is helping otherProc's recovery.  For instance, if the
// 	event store is keeping a log of sent messages, this call
// 	retrieves all the messages sent by source to otherProc. 
// 
// Arguments:
// 	otherProc --- process for whom data has been logged.
//      source --- process that created the eventInfo
//      startEventId --- retrieve beginning from this event id of
//                       source
//      retrieve_List --- output parameter
// 
// Results:
// 	retrieve_List --- list of retrieved event info.  The caller
// 	SHOULD NOT delete the elements of the list.  The caller is
// 	only allowed to call retrieve_List.erase() on the elements of
// 	the list.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void VolatileDeliveredStore::Read(int otherProc, int source, int startEventId,
			      EventInfo_List *retrieve_List)
{
  EventInfo_ListIterator e;
  EventInfo *info;
  
  this->stableStore->Read(otherProc, source, startEventId, retrieve_List);
  for (e = this->eventInfo[source][otherProc].begin();
       e != this->eventInfo[source][otherProc].end(); ++e) {
    info = *e;
    if (info->sourceEventId >= startEventId) {
      retrieve_List->push_back(info);
    }
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve event info. for replay phase of recovery.  This is a
// 	filler function that needs to be defined because the function
// 	with this type signature is declared to be virtual.
// 
// Arguments:
//      source --- retrieve event info created by process source
// 	startEventId --- retrieve event info d such that
//           (d.source = source) && (d.eventId >= startEventId)
//      lastEventIds --- output parameter and is a vector size EGIDA_MAX_PROCS
//      retrieve_List --- output parameter
// 
// Results:
// 	lastEventIds --- lastEventIds[i] is the index of the last
// 	    message process i sent to procId that is available from
// 	    storage.
//      retrieve_List --- since nothing is logged, this is list is unaffected.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void VolatileDeliveredStore::Read(int source, int startEventId,
			      int *lastEventIds, 
			      EventInfo_List *retrieve_List)
{
  memset(lastEventIds, 0, EGIDA_MAX_PROCS * sizeof(int));
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Remove any pointer's to eInfo from the event store.
// 
// Arguments:
// 	eInfo --- object to which any pointers are in the event store
// 	have to be removed.
// 
// Results:
// 	NULL
// 
// Side Effects:
// 	NULL
// 
// /////////////////////////////////////////////////////////////////
void VolatileDeliveredStore::RemovePtr(EventInfo *eInfo)
{
  EventInfo_ListIterator e;

  // If the stable store has it, remove the pointer from there as well.
  this->stableStore->RemovePtr(eInfo);

  for (e = this->eventInfo[eInfo->source][eInfo->otherProc].begin();
       e != this->eventInfo[eInfo->source][eInfo->otherProc].end(); ++e) {
    if (*e == eInfo) {
      this->eventInfo[eInfo->source][eInfo->otherProc].erase(e);
      break;
    }
  }
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Set a callback function that has to be invoked whenever the
// 	log is written out to stable storage.
// 
// Arguments:
// 	stableCallback --- function to callback whenever the contents
// 	of the event log are flushed to stable storage.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void VolatileDeliveredStore::SetLogStableCallback(void (*stableCallback)(int, int, 
								     int, int))
{
  this->stableStore->SetLogStableCallback(stableCallback);
}


// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Add a event info to the log on stable store.
// 
// Arguments:
// 	eInfo --- pointer to the event info that has to be added.  After
// 	this method call, the caller SHOULD NOT refer to eInfo.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void StableDeliveredStore::Write(EventInfo *eInfo)
{
  struct timeval timeStart;
  char fileName[EGIDA_FILENAME_LEN];

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  if(this->ofs == NULL) {
    this->ofs = new std::ofstream;
    sprintf(fileName, "%s.%d", this->diskLogBaseName, this->lme.logCounter);
    this->ofs->open(fileName, std::ios::app);
  }

  if(HASH_DETERMINANTS) {
    this->singleEvInfoCounter += 1;
    if(!this->singleEvInfoHashInit) {
      Security::HashSingleEvInfoInit();
      this->singleEvInfoHashInit = true;
    }
    Security::HashSingleEvInfo(eInfo);
    if(this->singleEvInfoCounter == HASH_LIST_SIZE) {
      unsigned char * digest = new unsigned char[MD5_DIGEST_LENGTH];
      unsigned char * signature = new unsigned char[RSA_BUF_SIZE];
      
      Security::HashSingleEvInfoFinal(digest);
      Security::EncryptWithRSA(MD5_DIGEST_LENGTH, 
			       digest,
			       signature);
      int num = HASH_LIST_SIZE;
      this->sig->write((const char *)&num, sizeof(int));
      this->sig->write((const char *)signature, RSA_BUF_SIZE);
      this->sig->flush();
      
      Security::HashSingleEvInfoInit();
      this->singleEvInfoCounter = 0;

      delete [] digest;
      delete [] signature;
    }
  }


  if(ENCRYPT_DETERMINANTS) {
    EventInfo * temp = new EventInfo();
    Security::EncryptEventInfo(temp, eInfo);

    *(this->ofs) << *temp << std::endl;
    delete temp;
  }
  else {
    *(this->ofs) << *eInfo << std::endl;
  }
  this->ofs->flush();

  fsync(this->ofs->rdbuf()->fd());
  // Update the meta-data about the log file
  if (this->lme.logStartEsn[eInfo->source] < 0)
    this->lme.logStartEsn[eInfo->source] = eInfo->sourceEventId;
  if (eInfo->sourceEventId > this->lme.logEndEsn[eInfo->source])
    this->lme.logEndEsn[eInfo->source] = eInfo->sourceEventId;

  if (this->LogStableCallback) {
    // If this is a log of delivered messages, source, sourceEventId
    // are actually dest, rsn of a message.  This is because, the
    // stuff store in EventStore is created by source and the eventId
    // assigned by source is rsn.  The remaining two values are the
    // "source, ssn" of the message.
    this->LogStableCallback(eInfo->source, eInfo->sourceEventId,
			    eInfo->otherProc, eInfo->otherProcEventId);
  }
  delete eInfo;

  if(COLLECTING_STATS) {
    struct timeval timeEnd;
    double timeSpent = 0.0;
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_EVENT_INFO_WRITE_STAT, 0, timeSpent);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Write out a list of event info to stable store.
// 
// Arguments:
//      source --- process that created the event info's in the event
//      info list that is being passed in.
// 	el --- pointer to the list of event info that have to be added.  
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

int StableDeliveredStore::WriteEvInfoList(int source, EventInfo_List &el)
{
  EventInfo_ListConstIterator e;
  EventInfo *eInfo;
  struct timeval timeStart, timeEnd;
  double timeSpent = 0.0;
  char fileName[EGIDA_FILENAME_LEN];

  if (el.size() <= 0) {
    //nothing to do....
    return -1;
  }

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  if(this->ofs == NULL) {
    this->ofs = new std::ofstream;
    sprintf(fileName, "%s.%d", this->diskLogBaseName, this->lme.logCounter);
    this->ofs->open(fileName, std::ios::app);
  }

  if(HASH_DETERMINANTS) {
    unsigned char * signature = new unsigned char[RSA_BUF_SIZE];
    int num = 0;
    
    //just in case there were single einfos being written to file
    // we should finalize the hash and store this signature first
    // so that the reading of the dets back in will match the order
    // in which they were written.
    if(this->singleEvInfoCounter > 0) {
      unsigned char * digest = new unsigned char[MD5_DIGEST_LENGTH];
      
      Security::HashSingleEvInfoFinal(digest);
      Security::EncryptWithRSA(MD5_DIGEST_LENGTH, 
			       digest,
			       signature);
      int num = this->singleEvInfoCounter;
      this->sig->write((const char *)&num, sizeof(int));
      this->sig->write((const char *)signature, RSA_BUF_SIZE);
      this->sig->flush();
      
      Security::HashSingleEvInfoInit();
      this->singleEvInfoCounter = 0;

      delete [] digest;
    }

    Security::HashAndSignEvInfoList(el, signature, num);

    if(num > 0) {
      this->sig->write((const char *)&num, sizeof(int));
      this->sig->write((const char *)signature, RSA_BUF_SIZE);
      this->sig->flush();
    }
    delete [] signature;
  }


  if(ENCRYPT_DETERMINANTS) {
    EventInfo * temp = new EventInfo();

    for (e = el.begin(); e != el.end(); ++e) {
      eInfo = *e;
      Security::EncryptEventInfo(temp, eInfo);
      *(this->ofs) << *temp << std::endl;
      temp->Clear();
      if (this->lme.logStartEsn[source] < 0)
	this->lme.logStartEsn[source] = eInfo->sourceEventId;
      if (eInfo->sourceEventId > this->lme.logEndEsn[source])
	this->lme.logEndEsn[source] = eInfo->sourceEventId;
    }
    delete temp;
  }
  else {

    for (e = el.begin(); e != el.end(); ++e) {
      eInfo = *e;
      *(this->ofs) << *eInfo << std::endl;
      if (this->lme.logStartEsn[source] < 0)
	this->lme.logStartEsn[source] = eInfo->sourceEventId;
      if (eInfo->eventId > this->lme.logEndEsn[source])
	this->lme.logEndEsn[source] = eInfo->sourceEventId;
    }
  }
  //  this->ofs->write(os.str(), os.pcount());
  this->ofs->flush();
  //  os.rdbuf()->freeze(false);

  eInfo = el.back();

  if ((this->LogStableCallback) && (eInfo)) {
    this->LogStableCallback(eInfo->source, eInfo->sourceEventId,
			    eInfo->otherProc, eInfo->otherProcEventId);
  }
  if(COLLECTING_STATS) {
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_EVENT_INFO_WRITE_STAT, 0, timeSpent);
  }
  return eInfo->sourceEventId ;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Fetch a previously logged event info. This is needed for
// 	causal protocols which log sent messages and retrieve a
// 	message header as part of ack processing.
// 
// Arguments:
// 	<source, sourceEventId> --- event for which info has to be
// 	    read
//      otherProc --- other process involved in the event
// 
// Results:
// 	eInfo --- resulting pointer to event info.  The caller of this 
// 	method SHOULD NOT delete eInfo.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void StableDeliveredStore::TryRetrieve(int source, int sourceEventId, 
				   int otherProc, EventInfo **eInfo)
{
  *eInfo = NULL;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Called after a checkpoint is written out.  Log files are
// 	maintained on a per checkpoint basis (for example, logFile.1.1 maintained 
// 	by process 1 contains the event info from checkpoint 1 to
// 	checkpoint 2).  Close the current log file and open a new one.
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

void StableDeliveredStore::CkptDone()
{
  char fileName[EGIDA_FILENAME_LEN];
  char sigFileName[EGIDA_FILENAME_LEN];

  this->lme_List.push_back(new LogMetaEntry(lme));

  if(this->ofs != NULL) {
    if(this->ofs->is_open()) {
      this->ofs->flush();  
      this->ofs->close();
    }
  }
  else {
    this->ofs = new std::ofstream;
  }


  if(HASH_DETERMINANTS) {
    if(this->sig != NULL) {
      if(this->sig->is_open()) {
	this->sig->flush();  
	this->sig->close();
      }
    }
    else {
      this->sig = new std::ofstream;
    }
  }


  this->lme.Clear();
  this->lme.logCounter++;
  sprintf(fileName, "%s.%d", this->diskLogBaseName, this->lme.logCounter);
  this->ofs->open(fileName, std::ios::out);

  if(HASH_DETERMINANTS) {
    sprintf(sigFileName, "%s.%s", fileName, "hashes");
    this->sig->open(sigFileName, std::ios::out);
    this->singleEvInfoCounter = 0;
    this->singleEvInfoHashInit = false;
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Garbage collect event info from stable store.
// 
// Arguments:
// 	source, sourceEventId: Discard event info. created by source
// 	     with eInfo->sourceEventId < sourceEventId.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void StableDeliveredStore::GarbageCollect(int source, int sourceEventId)
{
  LogMetaEntry_ListIterator e, first;
  LogMetaEntry *l;
  int i;
  bool done = false, needToErase = false;
  char fileName[EGIDA_FILENAME_LEN];
  char sigFileName[EGIDA_FILENAME_LEN];

  struct timeval timeStart;
  if(COLLECTING_STATS) { 
    gettimeofday(&timeStart, NULL);
  }

  if (this->gcEventInfo[source] < sourceEventId)
    this->gcEventInfo[source] = sourceEventId;

  first = this->lme_List.end();
  for (e = this->lme_List.begin(); e != this->lme_List.end(); ++e) {
    l = *e;
    for (i = 0; i < EGIDA_MAX_PROCS; i++) {
      if (l->logEndEsn[i] > this->gcEventInfo[i]) {
	done = true;
	break;
      }
    }
    if (done)
      break;
    // All the event info in this file are no longer needed.
    if (first == this->lme_List.end())
      first = e;
    needToErase = true;

    sprintf(fileName, "%s.%d", this->diskLogBaseName, l->logCounter);
    unlink(fileName);

    //so neither are the signed hashes
    if(HASH_DETERMINANTS) {
      sprintf(sigFileName, "%s.%s", fileName, "hashes");
      unlink(sigFileName);
    }

    delete l;
    //deleting file
  }
  if (needToErase)
    this->lme_List.erase(first, e);

  if(COLLECTING_STATS) {
    struct timeval timeEnd;
    double timeSpent = 0.0;
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_LOG_GARBAGE_COLLECT_STAT, 0, timeSpent);
  }
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Throw away event info from storage---the difference between
// 	this method and garbage collect is that the comparator used
// 	for throwing away event info is different (>= as opposed to <).
// 
// Arguments:
// 	source, sourceEventId: Discard event info. created by source
// 	     with eInfo->sourceEventId >= sourceEventId.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void StableDeliveredStore::Purge(int source, int sourceEventId)
{
  EventInfo_ListIterator e, eraseStart;
  EventInfo *eInfo;
  int otherProc;

  for (otherProc = 0; otherProc < EGIDA_MAX_PROCS; otherProc++) {
    for (e = this->cached_List[source][otherProc].begin(); 
	 e != this->cached_List[source][otherProc].end();
	 ++e) {
      eInfo = *e;
      if (eInfo->sourceEventId >= sourceEventId) {
	// start erasing from here
	break;
      }
    }
    eraseStart = e;
    for (; e != this->cached_List[source][otherProc].end(); ++e) {
      eInfo = *e;
      delete eInfo;
    }
    this->cached_List[source][otherProc].erase(eraseStart, 
					       this->cached_List[source][otherProc].end());
  }

  this->PurgeOnDisk(source, sourceEventId);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Throw away event info from disk---the difference between
// 	this method and garbage collect is that the comparator used
// 	for throwing away event info is different (>= as opposed to <).
// 
// Arguments:
// 	source, sourceEventId: Discard event info. created by source
// 	     with eInfo->sourceEventId >= sourceEventId.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void StableDeliveredStore::PurgeOnDisk(int source, int purgeStartId)
{
  char logFile[EGIDA_FILENAME_LEN], tempFile[EGIDA_FILENAME_LEN];
  char sigFileName[EGIDA_FILENAME_LEN];
  LogMetaEntry_ListIterator e;
  LogMetaEntry *lme_Entry;
  EventInfo m;
  struct stat fileInfo;  
  std::ifstream ifs;
  std::ofstream tempFS;
  int numberOfEvInfo = 0;
  
  // The lme_List contains info. about all the files except the
  // "current" one (the one in this->lme)
  this->lme_List.push_back(new LogMetaEntry(this->lme));
  
  // go thru all the log files and read the ones that are needed
  for (e = this->lme_List.begin(); e !=  this->lme_List.end(); ++e)
    {
      lme_Entry = *e;
      sprintf(logFile, "%s.%d", this->diskLogBaseName,
	      lme_Entry->logCounter);  

      // if lme_Entry is < 0, means re-build meta-data
      if ((lme_Entry->logEndEsn[source] >= 0) && 
	  (lme_Entry->logEndEsn[source] < purgeStartId)) {
	std::cout << "Not purging log file: " << logFile << std::endl;
	continue;
      }
      stat(logFile, &fileInfo);
      if (fileInfo.st_size <= 0) {
	//skip this log file since it is empty
	continue;
      }

      ifs.open(logFile, std::ios::in);
      sprintf(tempFile, "%s.tmp", logFile);
      tempFS.open(tempFile, std::ios::out);
      
      memset(lme_Entry->logStartEsn, 0, this->numProcs * sizeof(int));
      memset(lme_Entry->logEndEsn, 0, this->numProcs * sizeof(int));

      if(HASH_DETERMINANTS) {
	//since we are going to be changing the logfile, 
	//we will need to recompute the hash and signature
	sprintf(sigFileName, "%s.%s", logFile, "hashes");
	unlink(sigFileName);
	Security::RecreateHashEvInfoInit();
      }

      if(ENCRYPT_DETERMINANTS) {
	EventInfo temp;

	while (1) {
	  temp.Clear();
	  m.Clear();
	  ifs >> temp;
	  if((ifs.fail()) || (ifs.eof()))
	    break;

	  Security::DecryptEventInfo(&m, &temp);
	  
	  if((m.source == source) && (m.sourceEventId >= purgeStartId))
	    continue;

	  if(HASH_DETERMINANTS) {
	    Security::RecreateHashSingleEvInfo(&m);
	    numberOfEvInfo ++;
	  }

	  tempFS << temp << std::endl;
	  // rebuild the meta-data if needed...
	  if (lme_Entry->logStartEsn[m.source] <= 0)
	    lme_Entry->logStartEsn[m.source] = m.sourceEventId;
	  if (lme_Entry->logEndEsn[m.source] < m.sourceEventId)
	    lme_Entry->logEndEsn[m.source] = m.sourceEventId;
	}
      }
      else {
	while (1) {
	  m.Clear();
	  ifs >> m;
	  if((ifs.fail()) || (ifs.eof()))
	    break;
	  if((m.source == source) && (m.sourceEventId >= purgeStartId))
	    continue;
	  tempFS << m << std::endl;

	  if(HASH_DETERMINANTS) {
	    Security::RecreateHashSingleEvInfo(&m);
	    numberOfEvInfo ++;
	  }

	  // rebuild the meta-data if needed...
	  if (lme_Entry->logStartEsn[m.source] <= 0)
	    lme_Entry->logStartEsn[m.source] = m.sourceEventId;
	  if (lme_Entry->logEndEsn[m.source] < m.sourceEventId)
	    lme_Entry->logEndEsn[m.source] = m.sourceEventId;
	}
      }
      
      ifs.close();
      tempFS.flush();
      tempFS.close();
      unlink(logFile);
      
      rename(tempFile, logFile);

      if(HASH_DETERMINANTS) {
	sprintf(sigFileName, "%s.%s", logFile, "hashes");
	int fd = open(sigFileName, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	unsigned char * digest = new unsigned char[MD5_DIGEST_LENGTH];
	unsigned char * signature = new unsigned char[RSA_BUF_SIZE];
      
	Security::RecreateHashEvInfoFinal(digest);
	Security::EncryptWithRSA(MD5_DIGEST_LENGTH, 
				 digest,
				 signature);

	write(fd, (const char *)&numberOfEvInfo, sizeof(int));
	write(fd, (const char *)signature, RSA_BUF_SIZE);
	close(fd);
	
	delete [] digest;
	delete [] signature;
      }


    }
  // remove the one we pushed in this method
  lme_Entry = this->lme_List.back();
  // if we rebuilt any of the meta-data, copy  it back.
  this->lme = *lme_Entry;
  this->lme_List.pop_back();
  delete lme_Entry;   
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve data corresponding to the events that have to be
// 	replayed. 
// 
// Arguments:
// 	self --- id of this process
//      startEventId --- retrieve data d from stable store such that 
//         d.eventId >= startEventId
//      lastEventIds --- output parameter
// 
// Results:
// 	  lastEventIds --- a vector in which lastEventIds[i] is the id of the
// 	   last message m retrieved from stable storage, where m is a
// 	   message that process i sent to this process 
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void StableDeliveredStore::Read(int self, int startEventId,
			    int *lastEventIds)
{
  char logFile[EGIDA_FILENAME_LEN];
  LogMetaEntry_ListIterator e;
  LogMetaEntry *lme_Entry;
  EventInfo m;
  struct stat fileInfo;  
  std::ifstream ifs;
  
  // Cache the stuff in memory
  memset(lastEventIds, 0, EGIDA_MAX_PROCS * sizeof(int));
  // The lme_List contains info. about all the files except the
  // "current" one (the one in this->lme)
  this->lme_List.push_back(new LogMetaEntry(this->lme));
  
  // go thru all the log files and read the ones that are needed
  for (e = this->lme_List.begin(); e !=  this->lme_List.end(); ++e)
    {
      lme_Entry = *e;
      sprintf(logFile, "%s.%d", this->diskLogBaseName,
	      lme_Entry->logCounter);  

      // if lme_Entry is < 0, means re-build meta-data
      if ((lme_Entry->logEndEsn[self] >= 0) && 
	  (lme_Entry->logEndEsn[self] < startEventId)) {
	std::cout << "Not opening log file: " << logFile << std::endl;
	continue;
      }
      stat(logFile, &fileInfo);
      if (fileInfo.st_size <= 0) {
	//skip log file because it is empty
	continue;
      }

      
      ifs.open(logFile, std::ios::in);


      if(HASH_DETERMINANTS) {
	//make sure the determinants have not been tampered with
	bool good = Security::VerifyEvInfoChunksInFile(logFile);
	
	if(!good) {
	  std::cout << "Information in file: " << logFile
		    << " have been tampered with." << std::endl; 
	  std::cout << " Abort Playback..." << std::endl;
	  //exit(0);
	}
	else {
	  std::cout << "Information in file: " << logFile
		    << " are fine. Continue playback...." << std::endl;
	}
      }
      
      memset(lme_Entry->logStartEsn, 0, this->numProcs * sizeof(int));
      memset(lme_Entry->logEndEsn, 0, this->numProcs * sizeof(int));

      if(ENCRYPT_DETERMINANTS) {
	EventInfo temp;	
	
	while (1) {
	  m.Clear();
	  temp.Clear();
	  ifs >> temp;
	  if((ifs.fail()) || (ifs.eof()))
	    break;
	  
	  Security::DecryptEventInfo(&m, &temp);
	  
	  this->cached_List[m.source][m.otherProc].push_back(new EventInfo(m));
	  if ((m.source == self) && (m.sourceEventId >= startEventId) &&
	      (lastEventIds[m.otherProc] < m.otherProcEventId))
	    lastEventIds[m.otherProc] = m.otherProcEventId;
	  
	  // rebuild the meta-data if needed...
	  if (lme_Entry->logStartEsn[m.source] <= 0)
	    lme_Entry->logStartEsn[m.source] = m.sourceEventId;
	  if (lme_Entry->logEndEsn[m.source] < m.sourceEventId)
	    lme_Entry->logEndEsn[m.source] = m.sourceEventId;
	}
      }
      else {
	while (1) {
	  m.Clear();
	  ifs >> m;
	  if((ifs.fail()) || (ifs.eof()))
	    break;
	  this->cached_List[m.source][m.otherProc].push_back(new EventInfo(m));
	  if ((m.source == self) && (m.sourceEventId >= startEventId) &&
	      (lastEventIds[m.otherProc] < m.otherProcEventId))
	    lastEventIds[m.otherProc] = m.otherProcEventId;	  
	  // rebuild the meta-data if needed...
	  if (lme_Entry->logStartEsn[m.source] <= 0)
	    lme_Entry->logStartEsn[m.source] = m.sourceEventId;
	  if (lme_Entry->logEndEsn[m.source] < m.sourceEventId)
	    lme_Entry->logEndEsn[m.source] = m.sourceEventId;
	}
      }
      ifs.close();
    }

  // remove the one we pushed in this method
  lme_Entry = this->lme_List.back();
  // if we rebuilt any of the meta-data, copy  it back.
  this->lme = *lme_Entry;
  this->lme_List.pop_back();
  delete lme_Entry;   
  
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve event info. for replay phase of recovery.
// 
// Arguments:
//      source --- retrieve event info created by process source
// 	startEventId --- retrieve event info d such that
//           (d.source = source) && (d.eventId >= startEventId)
//      lastEventIds --- output parameter and is a vector size EGIDA_MAX_PROCS
//      retrieve_List --- output parameter
// 
// Results:
// 	lastEventIds --- lastEventIds[i] is the index of the last
// 	    message process i sent to procId that is available from storage.
//      retrieve_List --- list of event info retrieved from stable 
//           storage.  
//           MAJOR POINT: It is the responsibility of the caller to free
//           the elements of the retrieve_List.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void StableDeliveredStore::Read(int source, int startEventId,
			    int *lastEventIds,
			    EventInfo_List *retrieve_List)
{
  char logFile[EGIDA_FILENAME_LEN];
  LogMetaEntry_ListIterator e;
  LogMetaEntry *lme_Entry;
  EventInfo m;
  std::ifstream ifs;
  struct stat fileInfo;  
  int pos;

  memset(lastEventIds, 0, EGIDA_MAX_PROCS * sizeof(int));
  // The lme_List contains info. about all the files except the
  // "current" one (the one in this->lme)
  this->lme_List.push_back(new LogMetaEntry(this->lme));
  
  // go thru all the log files and read the ones that are needed
  for (e = this->lme_List.begin(); e !=  this->lme_List.end(); ++e)
    {
      lme_Entry = *e;
      sprintf(logFile, "%s.%d", this->diskLogBaseName,
	      lme_Entry->logCounter);  

      // if lme_Entry is < 0, means re-build meta-data
      if ((lme_Entry->logEndEsn[source] >= 0) && 
	  (lme_Entry->logEndEsn[source] < startEventId)) {
	std::cout << "Not opening log file: " << logFile << std::endl;
	continue;
      }
      // read the determinants in this file
      ifs.open(logFile, std::ios::in);

      if (!ifs.is_open()) {
	std::cout << "Trouble opening " << logFile << std::endl;
	assert(0);
      }

      if(HASH_DETERMINANTS) {
	//make sure the determinants have not been tampered with
	bool good = Security::VerifyEvInfoChunksInFile(logFile);
	
	if(!good) {
	  std::cout << "Information in file: " << logFile
		    << " have been tampered with." << std::endl; 
	  std::cout << " Abort Playback..." << std::endl;
	  //exit(0);
	}
	else {
	  std::cout << "Information in file: " << logFile
		    << " are fine. Continue playback...." << std::endl;
	}
      }
      
      memset(lme_Entry->logStartEsn, 0, this->numProcs * sizeof(int));
      memset(lme_Entry->logEndEsn, 0, this->numProcs * sizeof(int));

      if(ENCRYPT_DETERMINANTS) {
	EventInfo temp;	
	
	while (1) {
	  m.Clear();
	  temp.Clear();
	  ifs >> temp;
	  if((ifs.fail()) || (ifs.eof()))
	    break;
	  
	  Security::DecryptEventInfo(&m, &temp);
	  
	  if ((m.source == source) && (m.sourceEventId >= startEventId))
	    lastEventIds[m.otherProc] = m.otherProcEventId;
	  retrieve_List->push_back(new EventInfo(m));
	  // rebuild the meta-data if needed...
	  if (lme_Entry->logStartEsn[m.source] <= 0)
	    lme_Entry->logStartEsn[m.source] = m.sourceEventId;
	  if (lme_Entry->logEndEsn[m.source] < m.sourceEventId)
	    lme_Entry->logEndEsn[m.source] = m.sourceEventId;
	}
      }
      else {
	while (1) {
	  m.Clear();
	  ifs >> m;
	  if((ifs.fail()) || (ifs.eof()))
	    break;
	  if ((m.source == source) && (m.sourceEventId >= startEventId))
	    lastEventIds[m.otherProc] = m.otherProcEventId;
	  retrieve_List->push_back(new EventInfo(m));
	  // rebuild the meta-data if needed...
	  if (lme_Entry->logStartEsn[m.source] <= 0)
	    lme_Entry->logStartEsn[m.source] = m.sourceEventId;
	  if (lme_Entry->logEndEsn[m.source] < m.sourceEventId)
	    lme_Entry->logEndEsn[m.source] = m.sourceEventId;
	}
      }
      ifs.close();
    }
  // remove the one we pushed in this method
  lme_Entry = this->lme_List.back();
  // if we rebuilt any of the meta-data, copy  it back.
  this->lme = *lme_Entry;
  this->lme_List.pop_back();
  delete lme_Entry;   

}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve the data corresponding to a determinant which has to
// 	be replayed.
// 
// Arguments:
// 	source --- process that created the eInfo 
//      sourceEventId --- event id corresponding to the data that has
//             be read back.
//      otherProc --- other process involved in the event.
//      eInfo --- output parameter
//
// Results:
// 	eInfo --- is a pointer to the matching event info that has
// 	been retrieved.  The caller SHOULD NOT free eInfo.  The only
// 	exception to this requirement is that, after this method call, 
// 	the caller SHOULD CALL RemovePtr() method exported by this object.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void StableDeliveredStore::Read(int source, int sourceEventId,
			    int otherProc, EventInfo **eInfo)
{
  EventInfo_ListIterator e;
  EventInfo *tempInfo;

  *eInfo = NULL;
  for (e = this->cached_List[source][otherProc].begin(); 
       e != this->cached_List[source][otherProc].end(); ++e) {
    tempInfo = *e;
    if (tempInfo->sourceEventId == sourceEventId) {
      *eInfo = tempInfo;
      break;
    }
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve data logged on behalf of otherProc. Needed when
// 	Egida is helping otherProc's recovery.  For instance, if the
// 	event store is keeping a log of sent messages, this call
// 	retrieves all the messages sent by source to otherProc. 
// 
// Arguments:
// 	otherProc --- process for whom data has been logged.
//      source --- process that created the eventInfo
//      startEventId --- retrieve beginning from this event id of
//                       source
//      retrieve_List --- output parameter
// 
// Results:
// 	retrieve_List --- list of retrieved event info.  Free'ing the
// 	buffer allocated for this list is a HUGE PROBLEM.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void StableDeliveredStore::Read(int otherProc, int source, int startEventId,
			    EventInfo_List *retrieve_List)
{
  
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Remove any pointer's to eInfo from the event store.
// 
// Arguments:
// 	eInfo --- object to which any pointers are in the event store
// 	have to be removed.
// 
// Results:
// 	NULL
// 
// Side Effects:
// 	NULL
// 
// /////////////////////////////////////////////////////////////////
void StableDeliveredStore::RemovePtr(EventInfo *eInfo)
{
  EventInfo_ListIterator e;

  for (e = this->cached_List[eInfo->source][eInfo->otherProc].begin(); 
       e != this->cached_List[eInfo->source][eInfo->otherProc].end(); ++e) {
    if (*e == eInfo) {
      this->cached_List[eInfo->source][eInfo->otherProc].erase(e);
      break;
    }
  }
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Change the name of the file used for logging info. to stable
// 	storage. 
// 
// Arguments:
// 	baseName --- is the base file name (for example, eventLog) from
// 	which other log files of this event store will be constructed.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void StableDeliveredStore::SetLogFileName(const char *baseName) 
{
   
  char fileName[EGIDA_FILENAME_LEN];
  char sigFileName[EGIDA_FILENAME_LEN];

  this->ofs->close();
  sprintf(fileName, "%s.%d", this->diskLogBaseName, this->lme.logCounter);
  unlink(fileName);


  if(HASH_DETERMINANTS){
    this->sig->close();
    sprintf(sigFileName, "%s.%s", fileName, "hashes");
    unlink(sigFileName);
  }

  sprintf(this->diskLogBaseName, "%s/%s.%d", EGIDA_LOGS_DIR, baseName, 
	  this->id);
  sprintf(fileName, "%s.%d", this->diskLogBaseName, this->lme.logCounter);
  this->ofs->open(fileName, std::ios::out);
  if (!this->ofs->is_open()) {
    std::cout << "trouble opening file: " << fileName << std::endl;
    assert(this->ofs->is_open());
  }

  if(HASH_DETERMINANTS){
    sprintf(sigFileName, "%s.%s", fileName, "hashes");
    this->sig->open(sigFileName, std::ios::out);
    this->singleEvInfoCounter = 0;
    this->singleEvInfoHashInit = false;
  }

}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Set a callback function that has to be invoked whenever the
// 	log is written out to stable storage.
// 
// Arguments:
// 	stableCallback --- function to callback whenever the contents
// 	of the event log are flushed to stable storage.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void StableDeliveredStore::SetLogStableCallback(void (*stableCallback)(int, int,
								   int, int))
{
  this->LogStableCallback = stableCallback;
}

// /////////////////////////////////////////////////////////////////
//
// Purpose:
// 	When the process state is restored from a checkpoint, then the 
// 	meta-data about the log files on disk is out-of-sync.  The
// 	meta-data needs to be rebuilt.  Since the log files will be
// 	accessed as part of Retrieve(), there is no need to do it
// 	here; but, rather re-build occurs as part of Retrieve.
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
void StableDeliveredStore::RestartingFromCkpt(void)
{
  char fileName[EGIDA_FILENAME_LEN];
  std::ofstream tempFs;
  LogMetaEntry_ListIterator first, e;
  LogMetaEntry *lme_Entry;

  this->mmapBuf = NULL;
  this->mmapBufSize = 0;
  // rather than writing all over the place...
  this->ofs = NULL;
  // force a rebuild of the current value of lme
  this->lme.Clear();
  sprintf(fileName, "%s.%d", this->diskLogBaseName,
	  this->lme.logCounter + 1);
  tempFs.open(fileName, std::ios::in);
  if (tempFs.is_open()) {
    this->lme_List.push_back(new LogMetaEntry(this->lme));
    this->lme.logCounter++;
    tempFs.close();
  }

  // Throw away the meta-data for files that don't exist
  first = this->lme_List.end();
  for (e = this->lme_List.begin(); e != this->lme_List.end(); ++e) {
    lme_Entry = *e;
    sprintf(fileName, "%s.%d", this->diskLogBaseName,
	    lme_Entry->logCounter);
    tempFs.open(fileName, std::ios::in);
    if (tempFs.is_open()) {
      tempFs.close();
      break;
    }
    if (first == this->lme_List.end())
      first = e;
    // the corresponding file doesn't exist.
    delete lme_Entry;
  }
  this->lme_List.erase(first, e);
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Called when replay is finished
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

void StableDeliveredStore::ReplayDone()
{
  int i, j;
  EventInfo *m;
  EventInfo_ListIterator e;
  char fileName[EGIDA_FILENAME_LEN];
  char sigFileName[EGIDA_FILENAME_LEN];

  if (this->mmapBufSize > 0) {
    munmap(this->mmapBuf, this->mmapBufSize);
    this->mmapBuf = NULL;
    this->mmapBufSize = 0;
  }
  for (i = 0; i < EGIDA_MAX_PROCS; i++) {
    for (j = 0; j < EGIDA_MAX_PROCS; j++) {
      for (e = this->cached_List[i][j].begin(); e !=
	     this->cached_List[i][j].end(); ++e) {
	m = *e;
	delete m;
      }
      this->cached_List[i][j].clear();
    }
  }
  sprintf(fileName, "%s.%d", this->diskLogBaseName,
	  this->lme.logCounter);
  // This is the STUPID problem with ofstreams.  Since the stream was
  // open at the time of checkpoint, the ofstream object thinks that
  // it has a valid file handle.  But, that is not the case---we have
  // now re-started from a checkpoint.  Close of the ofstream goes and 
  // closes some other file descriptor which has the same fd # as the
  // one maintained in the ofstream.  To avoid this problem, use a new 
  // ofstream (i.e., leak memory) each time this process is restarted
  // after a crash.
  this->ofs = new std::ofstream;
  this->ofs->open(fileName, std::ios::app);
  if (!this->ofs->is_open()) {
    std::cout << "trouble opening file: " << fileName << std::endl;
    assert(0);
  }
  
  if(HASH_DETERMINANTS){
    this->sig = new std::ofstream;
    sprintf(sigFileName, "%s.%s", fileName, "hashes");
    this->sig->open(sigFileName, std::ios::app);
    this->singleEvInfoCounter = 0;
    this->singleEvInfoHashInit = false;
  }
}

