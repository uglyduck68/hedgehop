// SentStore.cc -- 
//                This source is provided as is without any express or
//                written warranty.  Permission to use, copy, modify, and 
//                distribute this software for any purpose without fee is
//                hereby granted, provided that this entire notice is 
//                included in all copies of any software which is or includes
//                a copy or modification of this software and in all copies
//                of the supporting documentation for such software.
//                All Rights Reserved.
// $Locker:  $
// $Log: SentStore.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:17  ravshank
// Start of Spring 2001
//
//
// Revision 1.8  2000/11/15 22:12:32  phoebe
// Sanity check.
//
// Revision 1.7  2000/11/13 20:57:37  phoebe
// Security had the same memory leak but it's fixed now
//
// Revision 1.6  2000/11/10 15:48:55  phoebe
// Checkpoint memory leak is now solved, and so is the memcpy core dump on some checkpoints.
//
// Revision 1.5  2000/11/06 23:07:13  phoebe
// Encryption of checkpoints is working again. We still have the memcpy problem, but it seems to be less frequent. It's still a bit of a mystery as to why it's happening, and although the core is always dropped on a memcpy in WriteCkpt, it's not deterministic when it happens.
//
// Revision 1.4  2000/11/01 16:35:32  phoebe
// Working on getting security to work again with the redesigned system. Message encryption, either full or only egida messages, is working now.
//
// Revision 1.3  2000/10/31 00:22:50  phoebe
// SBP now works with flushing and garbage collection. Before the file out pointers were not being managed properly so after a garbagecollect they were pointing to a non-existant file. So the point of all of this is we have a working SentStore.cc file.
//
// Revision 1.2  2000/10/24 16:32:31  phoebe
// Garbage collection of the sentLog is now happening but sometimes it doesn't recover...think it's a problem with multiple recoveries and not flushing some info. Will check into it. Fixed the memcpy core dump on taking a checkpoint...it was a problem with the fact that we were using a signed int to track the segment size and should have been using an unsigned int so that we didn't get overflow problem.
//
// Revision 1.1  2000/10/20 19:28:49  phoebe
// SentLog class is now integrated and works so protocols using the sentLog to store information will now restart on flushing.
//
// Revision 1.1.1.1  2000/09/27 19:32:46  jmn
// Initial revision.
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
// $Id: SentStore.cc,v 1.1.1.1 2001/02/12 00:00:17 ravshank Exp $
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
#include <iostream.h>
#include <iostream>
#include <strstream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "Egida_Object.H"
#include "EventStore.H"
#include "Globals.H"
#include "SentStore.H"
#include "Stats.H"
#include "Timer.H"


void VolatileSentStore::Write(EventInfo *eInfo)
{ 
  struct timeval timeStart;
  
  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  eventInfo[eInfo->otherProc].push_back(eInfo); 
  if(ssnInMemory[eInfo->otherProc][low] < 0) 
    ssnInMemory[eInfo->otherProc][low] = eInfo->sourceEventId;
  ssnInMemory[eInfo->otherProc][high] = eInfo->sourceEventId;

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

void VolatileSentStore::TryRetrieve(int source, int sourceEventId, 
				     int otherProc, EventInfo **eInfo)
{
  EventInfo * info;

  //...this search should be made to be faster.
  *eInfo = NULL;

  if(ssnInMemory[otherProc][low] > sourceEventId 
     || sourceEventId > ssnInMemory[otherProc][high]
     || ssnInMemory[otherProc][low] < 0) {
    //we don't have it...

    return;
  }
  for (EventInfo_ListIterator e = eventInfo[otherProc].begin();
       e != eventInfo[otherProc].end(); ++e) {
    info = *e;
    if (info->sourceEventId == sourceEventId) {
      *eInfo = info;
      break;
    }
  }

  return;
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
void VolatileSentStore::Flush()
{

  //  std::cout << Egida::GetMyId() << "FLUSH : SentStore flushed" << std::endl;

  for (int i = 0 ; i < Egida::GetNumProcs(); i++) {
    // write log to stable store
    stableStore->WriteEvInfoList(i, eventInfo[i]);
  }

  //show that we are about to clean volatile memory
  for (int i = 0 ; i < Egida::GetNumProcs(); i++) {
    ssnInMemory[i][low] = ssnInMemory[i][high] = -1;

    EventInfo_ListIterator e;
    EventInfo * eInfo;
    
    for(e = eventInfo[i].begin(); 
	*e != flushEventInfo[i]; e++) {
      eInfo = *e;
      delete eInfo;
    }
    eventInfo[i].clear();
  }
}


void VolatileSentStore::FlushClean() 
{
  //show that we are about to clean volatile memory
  for (int i = 0 ; i < Egida::GetNumProcs(); i++) {
    ssnInMemory[i][low] = ssnInMemory[i][high] = -1;

    EventInfo_ListIterator e;
    EventInfo * eInfo;
    
    for(e = eventInfo[i].begin(); 
	*e != flushEventInfo[i]; e++) {
      eInfo = *e;
      delete eInfo;
    }
    eventInfo[i].clear();
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
void VolatileSentStore::GarbageCollect(int otherProc, int sourceEventId)
{
  //  std::cout << Egida::GetMyId() << 
  //    " Sent Store Garbage Collect called : Proc ID = " << otherProc <<
  //    " EventId = " << sourceEventId << std::endl;

  garbageCollectMemorySsn[otherProc] = sourceEventId;
  stableStore->GarbageCollect(otherProc, garbageCollectMemorySsn[otherProc]);

  EventInfo_ListIterator end;
  EventInfo * eInfo;

  if(ssnInMemory[otherProc][high] < garbageCollectMemorySsn[otherProc])
    ssnInMemory[otherProc][low] = ssnInMemory[otherProc][high] = -1;
  else
    ssnInMemory[otherProc][low] = garbageCollectMemorySsn[otherProc];

  for(end = eventInfo[otherProc].begin(); 
      end != eventInfo[otherProc].end(); end++) {
    eInfo = *end;
    if(eInfo->sourceEventId < garbageCollectMemorySsn[otherProc]) {
      delete eInfo;
    }
    else
      break;
  }
  eventInfo[otherProc].erase(eventInfo[otherProc].begin(), end); 
  return;
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

void VolatileSentStore::Purge(int otherProc, int sourceEventId)
{
  stableStore->Purge(otherProc, sourceEventId);

  if(ssnInMemory[otherProc][high] < sourceEventId 
     || ssnInMemory[otherProc][low] < 0)
    {
      //nothing to do...
      return;
    }

  //there is something to purge
  if(ssnInMemory[otherProc][low] >= sourceEventId) 
     //need to erase the whole banana
    ssnInMemory[otherProc][low] = ssnInMemory[otherProc][high] = -1;
  else
    // only end of the list needs to disappear
    ssnInMemory[otherProc][high] = sourceEventId;

  EventInfo_List::reverse_iterator rfirst;
  for(rfirst = eventInfo[otherProc].rbegin();
      rfirst != eventInfo[otherProc].rend(); rfirst++) {
    EventInfo *eInfo = *rfirst;
    if(eInfo->sourceEventId < sourceEventId) {
      break;
    }
    delete eInfo;
  }
  // convert reverse to iterator. base() points to next element
  //   in forward order traversal and thus the first element
  //   that we want to delete! erase only deletes elements from
  //   first to end-1.
  eventInfo[otherProc].erase(rfirst.base(), eventInfo[otherProc].end());

  return;
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

void VolatileSentStore::Read(int source, int sourceEventId,
			      int otherProc, EventInfo **eInfo)
{
  //this function should never be used for the sentStore...always give
  //requesting process a list of messages to replay
  return;
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

void VolatileSentStore::Read(int otherProc, int source, int startEventId,
			      EventInfo_List *retrieve_List)
{
  //earlier events are in stableStore so get them first
  stableStore->Read(otherProc, source, startEventId, retrieve_List);

  //first check that we have something to give to this process
  //from volatile memory
  if(ssnInMemory[otherProc][high] < startEventId
     || this->ssnInMemory[otherProc][low] < 0) {
    //nope...nothing in memory for this process later than or equal to the start point
    return;
  }

  EventInfo * info;
  //yep...we have something to give this process
  for (EventInfo_ListIterator e = eventInfo[otherProc].begin();
       e != eventInfo[otherProc].end(); ++e) {
    info = *e;
    if (info->sourceEventId >= startEventId) {
      // this is a total hack to make a deep copy as opposed to shallow
      //      retrieve_List->push_back(new EventInfo(*info, 1));
      retrieve_List->push_back(new EventInfo(*info));
    }
  }

  return;
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
void VolatileSentStore::RemovePtr(EventInfo *eInfo)
{
  //shouldn't do this...either call GarbageCollect or call Purge
  return;
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	
// 
// Arguments:
// 	
// 
// Results:
// 	NULL
// 
// Side Effects:
// 	
// 
// /////////////////////////////////////////////////////////////////

void VolatileSentStore::ProcessMsg(int source, int tag, const char *msg, int msgSize)
{
  //there are no class specific messages to process for this class
  return;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
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

void VolatileSentStore::CkptDone()
{
  stableStore->CkptDone();
  return;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
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

void VolatileSentStore::RestartingFromCkpt(void)
{ 
  stableStore->RestartingFromCkpt(); 
  return;
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 
// Arguments:
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

int StableSentStore::GetSsnInFileHigh(int source)
{
  return ssnInFile[source][high];
}


void StableSentStore::TryRetrieve(int source, int sourceEventId, 
				  int otherProc, EventInfo **eInfo)
{
  //this function is not needed since the SentLog is not kept for our own
  //recovery, but rather the recovery of other processes.
  *eInfo = NULL;
  return;
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

void StableSentStore::Write(EventInfo *eInfo)
{
  struct timeval timeStart;

  //due to the fact that we are keeping information for other 
  //processes...and they may have failed...we may already have
  //logged this eInfo so check to see if we need to write it first
  if(ssnInFile[eInfo->otherProc][low] <= eInfo->sourceEventId &&
     eInfo->sourceEventId <= ssnInFile[eInfo->otherProc][high]) {
    //we already have this one in file
    delete eInfo;
    return;
  }

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  int procId = eInfo->otherProc;
  CheckLogOutStream(procId);

  if(HASH_DETERMINANTS) {
    singleEvInfoCounter += 1;
    if(!singleEvInfoHashInit) {
      Security::HashSingleEvInfoInit();
      singleEvInfoHashInit = true;
    }
    Security::HashSingleEvInfo(eInfo);
    if(singleEvInfoCounter == HASH_LIST_SIZE) {
      unsigned char * digest = new unsigned char[MD5_DIGEST_LENGTH];
      unsigned char * signature = new unsigned char[RSA_BUF_SIZE];
      CheckSigOutStream(procId);
      
      Security::HashSingleEvInfoFinal(digest);
      Security::EncryptWithRSA(MD5_DIGEST_LENGTH, 
			       digest,
			       signature);
      int num = HASH_LIST_SIZE;
      sig[procId]->write((const char *)&num, sizeof(int));
      sig[procId]->write((const char *)signature, RSA_BUF_SIZE);
      sig[procId]->flush();

      Security::HashSingleEvInfoInit();
      singleEvInfoCounter = 0;

      delete [] digest;
      delete [] signature;
    }
  }


  if(ENCRYPT_DETERMINANTS) {
    EventInfo * temp = new EventInfo();
    Security::EncryptEventInfo(temp, eInfo);

    (*ofs[procId]) << *temp << std::endl;
    delete temp;
  }
  else {
    (*ofs[procId]) << *eInfo << std::endl;
  }

  // Wait for data to be written...
  ofs[procId]->flush();
  
  UpdateSsnInFileCount(eInfo->otherProc, eInfo->sourceEventId);
  delete eInfo;

  if(COLLECTING_STATS) {
    struct timeval timeEnd;
    double timeSpent = 0.0;
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_EVENT_INFO_WRITE_STAT, 0, timeSpent);
  }

  return;
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 
// Arguments:
// 
// Results:
// 
// Side Effects:
// 
// /////////////////////////////////////////////////////////////////
void StableSentStore::UpdateSsnInFileCount(int otherProc, int seid)
{
  if(ssnInFile[otherProc][low] < 0)
    //then the file is empty at the moment
    ssnInFile[otherProc][low] = ssnInFile[otherProc][high] = seid;
  else
    //we better be in order or we are hosed.
    ssnInFile[otherProc][high] ++;

  return;
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

int StableSentStore::WriteEvInfoList(int source, EventInfo_List &el)
{
  EventInfo *eInfo;
  struct timeval timeStart;

  // nothing to do.
  if(el.empty())
    return -1;

  if(COLLECTING_STATS) {
    gettimeofday(&timeStart, NULL);
  }

  CheckLogOutStream(source);

  if(HASH_DETERMINANTS) {
    unsigned char * signature = new unsigned char[RSA_BUF_SIZE];
    int num = 0;
    
    Security::HashAndSignEvInfoList(el, signature, num);

    if(num > 0) {
      CheckSigOutStream(source);
      sig[source]->write((const char *)&num, sizeof(int));
      sig[source]->write((const char *)signature, RSA_BUF_SIZE);
      sig[source]->flush();
    }
    delete [] signature;
  }

  EventInfo_ListIterator e;

  if(ENCRYPT_DETERMINANTS) {
    EventInfo * temp = new EventInfo();

    // Write events in list out to file
    for (e = el.begin(); *e != flushEventInfo[source]; ++e) {
      eInfo = *e;

      //due to the fact that we are keeping information for other 
      //processes...and they may have failed...we may already have
      //logged this eInfo so check to see if we need to write it first
      if(ssnInFile[source][low] <= eInfo->sourceEventId &&
	 eInfo->sourceEventId <= ssnInFile[source][high])
	//we already have this one in file
	continue;

      Security::EncryptEventInfo(temp, eInfo);
       // encrypted EventInfo
      (*ofs[source]) << *temp << std::endl;
      temp->Clear();
      UpdateSsnInFileCount(source, eInfo->sourceEventId);
    }
    delete temp;
  }
  else {
 
    for (e = el.begin(); *e != flushEventInfo[source]; ++e) {
      eInfo = *e;
      
      //due to the fact that we are keeping information for other 
      //processes...and they may have failed...thus we may already have
      //logged this eInfo so check to see if we need to write it first
      if(ssnInFile[source][low] <= eInfo->sourceEventId &&
	 eInfo->sourceEventId <= ssnInFile[source][high])
	//we already have this one in file
	continue;
      
      // write EventInfo
      (*ofs[source]) << *eInfo << std::endl;
      UpdateSsnInFileCount(source, eInfo->sourceEventId);
    }
  }

  ofs[source]->flush();

  if(COLLECTING_STATS) {
    struct timeval timeEnd;
    double timeSpent = 0.0;
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_EVENT_INFO_WRITE_STAT, 0, timeSpent);
  }
  //eInfo has not been modified since the for loop so it's the last element we wrote
  return (eInfo->sourceEventId);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
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

void StableSentStore::CkptDone()
{
  return;
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
void StableSentStore::SetGarbageCollectSsn(int source, int gcSSN)
{
  garbageCollectSsn[source] = gcSSN;
}


void StableSentStore::GarbageCollect(int source, int startId)
{
  garbageCollectSsn[source] = startId;

  std::ofstream tempFS;
  int numberOfEvInfo = 0;
  char * logFile = NULL;  
  char * tempFile = NULL;
  
  SetupLogFileName(&logFile, source);

  int temp_len = strlen(logFile);
  tempFile = new char[temp_len+5]; // +".tmp" +null
  sprintf(tempFile,"%s.tmp",logFile);
  tempFS.open(tempFile, std::ios::out);  

  if(ssnInFile[source][high] < garbageCollectSsn[source]) 
    //we will be cleaning the whole file
    ssnInFile[source][low] = ssnInFile[source][high] = -1;
  else
    //set to what will be the lowest EventInfo after we are done
    ssnInFile[source][low] = garbageCollectSsn[source];
    
  if(HASH_DETERMINANTS) {
    char *sigFileName = NULL;
    //since we are going to be changing the logfile, 
    //we will need to recompute the hash and signature
    SetupSigFileName(&sigFileName, source);
    sig[source]->close();
    unlink(sigFileName);
    delete [] sigFileName;
    Security::RecreateHashEvInfoInit();
  }
  
  EventInfo m;
  std::ifstream ifs;
  
  ifs.open(logFile, std::ios::in);
  
  if(ENCRYPT_DETERMINANTS) {
    EventInfo temp;
    
    while (1) {
      temp.Clear();
      m.Clear();
      ifs >> temp;
      if((ifs.fail()) || (ifs.eof()))
	break;
      
      Security::DecryptEventInfo(&m, &temp);
      
      if(m.sourceEventId < garbageCollectSsn[source])
	//don't write this one to the new file
	continue;
      
      if(HASH_DETERMINANTS) {
	Security::RecreateHashSingleEvInfo(&m);
	numberOfEvInfo ++;
      }      
      tempFS << temp << std::endl;
    }
  }
  else {
    
    while (1) {
      m.Clear();
      ifs >> m;
      if((ifs.fail()) || (ifs.eof()))
	break;
      if(m.sourceEventId < garbageCollectSsn[source])
	continue;
      tempFS << m << std::endl;
      
      if(HASH_DETERMINANTS) {
	Security::RecreateHashSingleEvInfo(&m);
	numberOfEvInfo ++;
      }
    }
  }
  
  tempFS.flush();
  tempFS.close();
  
  ofs[source]->close();
  unlink(logFile);      
  //now rename the file
  rename(tempFile, logFile);
  
  if(HASH_DETERMINANTS) {
    char *sigFile = NULL; 
    SetupSigFileName(&sigFile, source);
    int fd = open(sigFile, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
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
    delete [] sigFile;
  }

  delete [] logFile;
  delete [] tempFile;
  
  return;
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
void StableSentStore::Purge(int source, int purgeStartId)
{

  //check to see if we need to open the file
  if(ssnInFile[source][high] < purgeStartId 
     || ssnInFile[source][low] < 0) {
    //the file has no "dets" to be purged or is empty
    return;
  }

  int numberOfEvInfo = 0;
  char * logFile = NULL;
  SetupLogFileName(&logFile, source);
  
  struct stat fileInfo;  
  stat(logFile, &fileInfo);

  //generally we won't need to purge the whole file,
  //so we skip that extra check 
  std::ifstream ifs;
  ifs.open(logFile, std::ios::in);

  int temp_len = strlen(logFile);
  char * tempFile = new char[temp_len+5]; // +".tmp" +null
  sprintf(tempFile,"%s.tmp",logFile);
  std::ofstream tempFS;
  tempFS.open(tempFile, std::ios::out);
      
  if(HASH_DETERMINANTS) {
    char *sigFileName = NULL;
    //since we are going to be changing the logfile, 
    //we will need to recompute the hash and signature
    SetupSigFileName(&sigFileName, source);
    sig[source]->close();
    unlink(sigFileName);
    CheckSigOutStream(source);
    delete [] sigFileName;
    Security::RecreateHashEvInfoInit();
  }

  //for the file pointers...we _do_ need to check if the whole file
  //is going to go
  if(purgeStartId <= ssnInFile[source][low]) {
    //the whole file will go
    ssnInFile[source][low] = ssnInFile[source][high] = -1;
  }
  else
    //we will be getting rid of anything greater or equal to purgeStartId
    ssnInFile[source][high] = purgeStartId - 1;

  EventInfo m;
  if(ENCRYPT_DETERMINANTS) {
    EventInfo temp;  
    while (1) {
      temp.Clear();
      m.Clear();
      ifs >> m;
      if((ifs.fail()) || (ifs.eof()))
	break;
      
      Security::DecryptEventInfo(&m, &temp);
      
      if(m.sourceEventId >= purgeStartId)
	//don't write this one to the new file
	continue;
      
      if(HASH_DETERMINANTS) {
	Security::RecreateHashSingleEvInfo(&temp);
	numberOfEvInfo ++;
      }      
    }
  }
  else {
    while (1) {
      m.Clear();
      ifs >> m;
      if((ifs.fail()) || (ifs.eof()))
	break;
      if(m.sourceEventId >= purgeStartId)
	continue;
      tempFS << m << std::endl;

      if(HASH_DETERMINANTS) {
	Security::RecreateHashSingleEvInfo(&m);
	numberOfEvInfo ++;
      }
    }
  }

  ifs.close();
  
  tempFS.flush();
  tempFS.close();
  
  ofs[source]->close();
  unlink(logFile);      
  //now rename the file
  rename(tempFile, logFile);
  CheckLogOutStream(source);

  delete [] logFile;
  delete [] tempFile;
  
  if(HASH_DETERMINANTS) {
    char *sigFile = NULL;
    
    SetupSigFileName(&sigFile,  source);
    int fd = open(sigFile, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
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
    delete [] sigFile;
  }
  return;
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

void StableSentStore::Read(int otherProc, int source, int startEventId,
			    EventInfo_List *retrieve_List)
{

  if(ssnInFile[otherProc][high] < startEventId 
     || ssnInFile[otherProc][low] < 0) {
    //nothing to give
    return;
  }

  char *logFile = NULL;
  SetupLogFileName(&logFile, otherProc); 

  struct stat fileInfo;  
  stat(logFile, &fileInfo);
  if (fileInfo.st_size <= 0) {
    //skip log file because it is empty
    //and by a freak of nature we didn't know this...so know it!
    ssnInFile[otherProc][low] = ssnInFile[otherProc][high] = -1;
    delete [] logFile;
    return;
  }

  // read the messages in this file
  std::ifstream ifs;
  ifs.open(logFile, std::ios::in);

  if(HASH_DETERMINANTS) {
    //make sure the determinants have not been tampered with
    bool good = Security::VerifyEvInfoChunksInFile(logFile);
    if(!good) {
      std::cout << "Information in file: " << logFile
		<< " has been tampered with." << std::endl; 
      std::cout << " Abort Playback..." << std::endl;
      //exit(0);
    }
    else {
      std::cout << "Information in file: " << logFile
		<< " is fine. Continue playback...." << std::endl;
    }
  }
  delete [] logFile;
  

  EventInfo m;
  if(ENCRYPT_DETERMINANTS) {
    EventInfo temp;	  
    while (!ifs.eof()) {
      ifs >> temp;      
      if(ifs.fail())
	break;
      
      Security::DecryptEventInfo(&m, &temp);
      if(m.sourceEventId >= startEventId)
	retrieve_List->push_back(new EventInfo(m));
      else {
	m.Clear();
	temp.Clear();
      }
	
    }
  }
  else {
    while (!ifs.eof()) {
      ifs >> m;
      if(ifs.fail())
	break;
      if(m.sourceEventId >= startEventId)
	//shallow copy
	retrieve_List->push_back(new EventInfo(m));
      else
	m.Clear();
    }
  }

  ifs.close();

  return;
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
void StableSentStore::RemovePtr(EventInfo *eInfo)
{
  //shouldn't do...just need to call garbagecollect or purge
  return;
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
void StableSentStore::SetLogFileName(const char *baseName) 
{
  // Ignore multiple calls
  if(fileNameInited)
    return;

  int i;
  for(i=0; i < Egida::GetNumProcs(); i++) {
    if(NULL != ofs[i]) {
      ofs[i]->close();
    }

    // Remove any previous log (might be inconsistent/empty)
    char *fileName = NULL;
    SetupLogFileName(&fileName, i);
    unlink(fileName);
    delete [] fileName;

    if(HASH_DETERMINANTS) {
      if(NULL != sig[i]) {
        sig[i]->close();
      }

      char *sigFileName = NULL;
      SetupSigFileName(&sigFileName, i);
      unlink(sigFileName);
      delete [] sigFileName;
    }
  }

  for(i=0; i<Egida::GetNumProcs(); i++) {
     // Actually try to open the file to set stream pointer
    CheckLogOutStream(i);

    if(HASH_DETERMINANTS){
       // reset sig stream
      CheckSigOutStream(i);
      singleEvInfoCounter = 0;
      singleEvInfoHashInit = false;
    }
  }
  fileNameInited = true;

  return;
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
void StableSentStore::RestartingFromCkpt(void)
{
  char *logFile = NULL;
  std::ifstream ifs;


  // This is the STUPID problem with ofstreams.  Since the stream was
  // open at the time of checkpoint, the ofstream object thinks that
  // it has a valid file handle.  But, that is not the case---we have
  // now re-started from a checkpoint.  Close of the ofstream goes and 
  // closes some other file descriptor which has the same fd # as the
  // one maintained in the ofstream.  To avoid this problem, use a new 
  // ofstream (i.e., leak memory) each time this process is restarted
  // after a crash.

  for(int k=0; k < Egida::GetNumProcs(); k++) {
    ofs[k] = NULL;
    // reset log output stream
    CheckLogOutStream(k);

    //also need to re-establish what is out on file to set
    // the ssnInFile pointers
    // XXX....can find a better way to do this?
    SetupLogFileName(&logFile, k);

    //we are going to recreate the file pointers...
    ssnInFile[k][low] = ssnInFile[k][high] = -1;

    struct stat fileInfo;  
    stat(logFile, &fileInfo);

    if (fileInfo.st_size <= 0)
      {
	continue;
      }
    ifs.open(logFile, std::ios::in);
    
    EventInfo m;
    if(ENCRYPT_DETERMINANTS) {
      EventInfo temp;
      while (1) {
	temp.Clear();
	m.Clear();
	ifs >> m;
	if((ifs.fail()) || (ifs.eof()))
	  break;
	
	Security::DecryptEventInfo(&m, &temp);

	UpdateSsnInFileCount(k, m.sourceEventId);
      }
    }
    else {
      while (1) {
	m.Clear();
	ifs >> m;
	if((ifs.fail()) || (ifs.eof()))
	  break;

	UpdateSsnInFileCount(k, m.sourceEventId);
      }
    }
    
    ifs.close();
    
    //if we are doing hashing reset the hash file pointers
    if(HASH_DETERMINANTS){
      sig[k] = NULL;
      // reset signature output stream
      CheckSigOutStream(k);
      singleEvInfoCounter = 0;
      singleEvInfoHashInit = false;
    }
  }
  delete [] logFile;
  
  return;
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

void StableSentStore::ReplayDone()
{
  return;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	
// 
// Arguments:
// 	
// 
// Results:
// 	NULL
// 
// Side Effects:
// 	
// 
// /////////////////////////////////////////////////////////////////

void StableSentStore::ProcessMsg(int source, int tag, const char *msg, int msgSize)
{
  return;
}


// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	
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

void StableSentStore::CheckLogOutStream(int i)
{
  if(NULL == ofs[i]) {
    ofs[i] = new std::ofstream;
    if(NULL == ofs[i]) {
      cout << "Error creating new log output stream: " << endl;
      assert(0);
    }
  }

  if(!ofs[i]->is_open()) {
    char *fileName = NULL;
    SetupLogFileName(&fileName, i);
    ofs[i]->open(fileName, std::ios::app);

    if (!ofs[i]->is_open()) {
      std::cout << "trouble opening log file: " 
                << fileName << std::endl;
      assert(0);
    }
    delete [] fileName;
  }

  return;
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	
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

void StableSentStore::CheckSigOutStream(int i)
{
  if(NULL == sig[i]) {
    sig[i] = new std::ofstream;
    if(NULL == sig[i]) {
      cout << "Error creating new signature output stream." << endl;
      assert(0);
    }
  }

  if(!sig[i]->is_open()) {
    char *fileName = NULL;
    SetupSigFileName(&fileName, i);
    sig[i]->open(fileName, std::ios::app);

    if (!sig[i]->is_open()) {
      std::cout << "trouble opening signature file: "
                << fileName << std::endl;
      assert(0);
    }
    delete [] fileName;
  }

  return;
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	
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

void StableSentStore::SetupLogFileName(char **buf, int otherProc)
{
  if(NULL == *buf) {
     // sum ( len(base) + '.' + null + len(number)
    int len = strlen(diskLogBaseName) + 2 + 13;
    *buf = (char *)new char[len];
    if(NULL == *buf) {
      cout << "Couldn't create log filename." << endl;
      assert(0);
    }
  }

  sprintf(*buf, "%s.%d", diskLogBaseName, otherProc);
  return;
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	
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

void StableSentStore::SetupSigFileName(char **buf, int otherProc)
{
  if(NULL == *buf) {
     // sum ( len(base) + '..hashes' + null + len(number)
    int len = strlen(diskLogBaseName) + 9 + 13;
    *buf = (char *)new char[len];
    if(NULL == *buf) {
      cout << "Couldn't create signature filename." << endl;
      assert(0);
    }
  }

  sprintf(*buf, "%s.%d.hashes", diskLogBaseName, otherProc);
  return;
}














