// DetStore.cc -- 
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
// $Log: DetStore.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:17  ravshank
// Start of Spring 2001
//
// Revision 1.20  2000/11/13 20:57:34  phoebe
// Security had the same memory leak but it's fixed now
//
// Revision 1.19  2000/11/01 19:49:39  phoebe
// Hashing determinants now works again.
//
// Revision 1.18  2000/11/01 16:35:27  phoebe
// Working on getting security to work again with the redesigned system. Message encryption, either full or only egida messages, is working now.
//
// Revision 1.17  2000/10/17 15:02:28  phoebe
// Stable code checkin. RBP is extremely stable except if you kill the master and slave at exactly the same time....it will hang in ReplayDeliver. SBP cannot support concurrent failures due to the lost control messages or hanging in ReplayDeliver. Causal can do +concurrent+ failures as long as control messages are not lost....so the restart must be staggered. Causal seems to suffer the same RBP problem with a master/slave pair, but unsure if this is the problem or if I didn't set numfailures=2...think the later would fix this. All the sentLog protocols (SBP and Causal) suffer from processes dumping core during WriteCkpt if they have been running for a long time since we are not flushing volatile memory at the moment. Should go away with the proper sentLog class fix.
//
// Revision 1.16  2000/10/12 19:50:53  phoebe
// Optimistic is still not working for more than one failure, but the incarnation number is now working correctly, and on the second failure it hangs in exactly the same spot every time. Also...optimistic is now rolling back a checkpoint file instead of doing the exec-ing that it was doing before. Additionally, during some of the debugging process, checkpoints are now shrinking heap sizes correctly (we thought they were doing it before, but they weren't.)
//
// Revision 1.15  2000/08/09 15:32:51  phoebe
// Changed the buffer size in CkptImpl.cc to be a #define instead of being hardwired to 4096. Also made fix in DetStore.cc and EventStore.cc that will allow both writing dets one at at time and in lists to be viable when hashing is turned on. Before this would have caused problems.
//
// Revision 1.14  2000/08/08 20:57:14  phoebe
// Cleaned up code, and now the never checkpointing again after a fail error is fixed.
//
// Revision 1.13  2000/08/08 14:28:53  phoebe
// Can now restart multiple times and kill the master process for Receiver Based Pessimistic logging. Same thing for Sender Based, but with sender based since the recovery logs must be in volatile memory, it will eventually run out of RAM and won't be able to continue or restart (obviously). This is a protocol design bug that will be fixed, but the restart is stable. Also able to restart from an incremental checkpoint (tested with RBP). These restart tests were done without any security turned on.
//
// Revision 1.12  2000/06/27 13:22:59  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.11  2000/06/26 21:31:06  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.10  2000/06/23 02:47:34  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.9  2000/06/22 20:58:58  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.8  2000/06/02 22:43:02  phoebe
// Added Encryption and Hash and Sign handling to PurgeDetsOnDisk subroutine in DetStore.cc but when testing on cg.B.4 with SBP logging it ran out of memory (the famous p4_shmalloc error)...so need to figure out where the leak is.
//
// Revision 1.7  2000/06/02 19:55:07  phoebe
// The code now compiles with the Encryption and the Hash and Sign functionality added to EventStore's PurgeOnDisk subroutine. Still need to test that it will run, and need to add same functionality to DetStore.cc
//
// Revision 1.6  2000/06/02 04:13:14  phoebe
// Encryption of EventInfo now working.
//
// Revision 1.5  2000/04/11 19:49:33  phoebe
// pound defined the loop iteration print statement off.
//
// Revision 1.4  2000/03/17 21:37:16  phoebe
// Hashing and signing determinants working now. All security hooks should be done and reintegrated.
//
// Revision 1.3  2000/03/17 18:08:50  phoebe
// Encryption of determinants is now in place. Also I added members to DetStore.H class to handle the upcoming hash and sign hooks that will be needed for that functionality with determinants.
//
// Revision 1.2  2000/03/07 16:24:52  phoebe
// Was able to restart causal logging by slightly modifying the Egida_Object_Init.cc file to distributed recovery and by tweaking StableDetStore::CkptDone function in DetStore.cc to check whether ofs was NULL before flushing. I restarted the causal protocol after the fourth loop iteration.
//
// Revision 1.1.1.1  2000/03/06 20:00:18  phoebe
// Sriram's original code with no modifications
//
// $Id: DetStore.cc,v 1.1.1.1 2001/02/12 00:00:17 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu May  6 15:04:28 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu Aug 26 10:06:10 1999
// Update Count    : 231
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <strstream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "DetStore.H"
#include "Stats.H"
#include "Timer.H"
#include "Egida_Object.H"

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Write a list of determinants to a stream.
// 
// Arguments:
// 	detList --- list of dets that have to be written to ostream os.
//      os --- output parameter 
//
// Results:
// 	os --- is a stream that contains the determinants from detList.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void DetStore::PrintDetList(const Determinant_List &detList, 
			    std::ostrstream &os)
{
  Determinant_ListConstIterator e;
  Determinant *d;

  for (e = detList.begin(); e != detList.end(); ++e) {
    d = *e;
    os << *d;
  }
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Method for logging determinants to storage.
// 
// Arguments:
// 	d --- pointer to the determinant that has to be added.  After
// 	this method call, the caller SHOULD NOT refer to d.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void NullDetStore::Write(Determinant *d)
{
  // since there is nothing to log, just free the determinant.
  delete d;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Add a determinant to the volatile log.
// 
// Arguments:
// 	d --- pointer to the determinant that has to be added.  After
// 	this method call, the caller SHOULD NOT refer to d.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void VolatileDetStore::Write(Determinant *d)
{
  struct timeval timeStart;
  if(COLLECTING_STATS) { 
    gettimeofday(&timeStart, NULL);
  }

  this->nonStable[d->dest].push_back(d);

  if(COLLECTING_STATS) {
    struct timeval timeEnd;
    double timeSpent = 0.0;
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_DET_WRITE_STAT, 0, timeSpent);
  }

}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Write out all the determinants to stable storage.
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

void VolatileDetStore::Flush()
{
  int i, detId = -1;
  Determinant *d;

  //  std::cout << Egida::GetMyId() << "FLUSH : Determinant Log flushed" << std::endl;

  for (i = 0 ; i < this->numProcs; i++) {
    this->stableStore->WriteDetList(this->stable[i]);
    this->stableStore->WriteDetList(this->nonStable[i]);
  }

  for (i = 0 ; i < this->numProcs; i++) {
    if (this->stable[i].size() > 0)
      d = this->stable[i].back();
    else
      d = NULL;

    if (d != NULL) 
      detId = d->d_esn;

    if (this->nonStable[i].size() > 0)
      d = this->nonStable[i].back();
    else
      d = NULL;

    if ((d != NULL) && (d->d_esn > detId))
      detId = d->d_esn;

    GarbageCollect(i, detId);
  }
}


void VolatileDetStore::FlushClean()
{
  int i, detId = -1;
  Determinant *d;

  for (i = 0 ; i < this->numProcs; i++) {
    if (this->stable[i].size() > 0)
      d = this->stable[i].back();
    else
      d = NULL;

    if (d != NULL) 
      detId = d->d_esn;

    if (this->nonStable[i].size() > 0)
      d = this->nonStable[i].back();
    else
      d = NULL;

    if ((d != NULL) && (d->d_esn > detId))
      detId = d->d_esn;

    GarbageCollect(i, detId);
  }

}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Change the name of the file used for logging dets. to stable
// 	storage. 
// 
// Arguments:
// 	baseName --- is the base file name (for example, detLog) from
// 	which other log files of this event store will be constructed.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void VolatileDetStore::SetLogFileName(const char *baseName)
{
  this->stableStore->SetLogFileName(baseName);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Garbage collect determinants from storage.
// 
// Arguments:
// 	procId, detId: Discard dets with d->dest == procId such that
// 	               d->d_esn < detId.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void VolatileDetStore::GarbageCollect(int procId, int detId)
{
  Determinant_ListIterator e, first;
  Determinant *d;
  bool needToErase = false;

  this->stableStore->GarbageCollect(procId, detId);
  
  struct timeval timeStart;
  if(COLLECTING_STATS) { 
    gettimeofday(&timeStart, NULL);
  }

  // first take care of the stable list
  first = this->stable[procId].end();
  e = this->stable[procId].begin(); 
  while (e != this->stable[procId].end()) {
    d = *e;
    if (d->d_esn < detId) {

      delete d;
      if (first == this->stable[procId].end())
	first = e;
      needToErase = true;
      // aggregate the list of things to be erased
      ++e;
    }
    else if (needToErase) {
      needToErase = false;
      // Erase removes list elements from first to e - 1.
      this->stable[procId].erase(first, e);
      // after the erase call, e is no longer usable.  so reset e
      e = this->stable[procId].begin(); 
      first = this->stable[procId].end();
    }
    else
      ++e;
  }
  if (needToErase) {
    needToErase = false;
    this->stable[procId].erase(first, e);
  }

  // now the non-stable stuff
  needToErase = false;
  first = this->nonStable[procId].end();
  e = this->nonStable[procId].begin(); 
  while (e != this->nonStable[procId].end()) {
    d = *e;
    if (d->d_esn < detId) {

      delete d;
      if (first == this->nonStable[procId].end())
	first = e;
      needToErase = true;
      // aggregate the list of things to be erased
      ++e;
    }
    else if (needToErase) {
      needToErase = false;
      // Erase removes list elements from first to e - 1.
      this->nonStable[procId].erase(first, e);
      // after the erase call, e is no longer usable.  so reset e
      e = this->nonStable[procId].begin(); 
      first = this->nonStable[procId].end();
    }
    else
      ++e;
  }
  if (needToErase) {
    needToErase = false;
    this->nonStable[procId].erase(first, e);
  }

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
// 	Throw away determinants from storage---the difference between
// 	this method and garbage collect is that the comparator used
// 	for throwing away dets is different (>= as opposed to <).
// 
// Arguments:
// 	procId, detId: Discard dets with d->dest == procId such that
// 	               d->d_esn >= detId.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void VolatileDetStore::Purge(int procId, int detId)
{
  Determinant_ListIterator e, eraseStart;
  Determinant *d;

  this->stableStore->Purge(procId, detId);
  for (e = this->stable[procId].begin();
       e != this->stable[procId].end(); ++e) {
    d = *e;
    if (d->d_esn >= detId)
      // begin erasing from here
      break;
  }
  eraseStart = e;
  for (; e != this->stable[procId].end(); ++e) {
    d = *e;

    delete d;
  }
  this->stable[procId].erase(eraseStart, this->stable[procId].end());

  for (e = this->nonStable[procId].begin();
       e != this->nonStable[procId].end(); ++e) {
    d = *e;
    if (d->d_esn >= detId)
      // begin erasing from here
      break;
  }
  eraseStart = e;
  for (; e != this->nonStable[procId].end(); ++e) {
    d = *e;
    
    delete d;
  }
  this->nonStable[procId].erase(eraseStart, this->nonStable[procId].end());
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Called after replay phase of recovery is finished.  If the
// 	stable store is maintaining any log files on disk, then, they
// 	have to be re-opened in write mode.
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
void VolatileDetStore::ReplayDone()
{
  this->stableStore->ReplayDone();
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
void VolatileDetStore::CkptDone()
{
  this->stableStore->CkptDone();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Log a set of determinants in the buffer on to storage.
// 
// Arguments:
//      source --- the process that sent the determinants that have to 
//        be logged.
//      detId --- output parameter.
// 	detBuf --- pointer to a buffer of determinants.
//        Note that unlike Log(d), the caller of this method is
//        responsible for free'ing the passed input buffer.
// 
// Results:
// 	detId --- detId[i] is the index of the
//        highest determinant of process i that was logged.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void VolatileDetStore::Write(int source, const char *detBuf, int detBufSize,
			     int *detIds)
{
  std::istrstream is(detBuf, detBufSize);
  int prevDest = -1, numDets;
  Determinant d;
  Determinant_List dets;
  int numResBytes;

  struct timeval timeStart;
  if(COLLECTING_STATS) { 
    gettimeofday(&timeStart, NULL);
  }

  // The format of a detBuf: 
  //  <# of reserved bytes> <reserved byte data> <# of dets> <dets>
  // Skip past the reserved stuff
  is >> numResBytes;
  if (numResBytes > 0) {
    is.rdbuf()->pubseekoff(numResBytes + 1, std::ios::cur, std::ios::in);
  }

  memset(detIds, 0, EGIDA_MAX_PROCS * sizeof(int));
  is >> numDets;
  while (numDets > 0) {
    d.Clear();
    is >> d;

    numDets--;
    assert((0 <= d.dest) && (d.dest < EGIDA_MAX_PROCS));
    if (d.d_esn > detIds[d.dest])
      detIds[d.dest] = d.d_esn;

    if (d.dest != prevDest) {
      if (prevDest >= 0) 
	this->MergeDets(source, prevDest, dets);
      dets.clear();
      prevDest = d.dest;
    }
    d.UpdateLoggedAt(source);
    d.UpdateLoggedAt(d.dest);
    d.UpdateLoggedAt(this->id);
    if (d.d_esn >= this->stableDets[d.dest])
      // log only the non-stable ones
      dets.push_back(new Determinant(d));
  }
  if (prevDest >= 0) {
    this->MergeDets(source, prevDest, dets);
    dets.clear();
  }
  
  if(COLLECTING_STATS) {
    struct timeval timeEnd;
    double timeSpent = 0.0;
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_DET_WRITE_STAT, 0, timeSpent);
  }

}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Merge the determinants in the determinant list with the 
// 	non-stable determinants.
// 
// Arguments:
//      source --- process that sent the dets in determinant list
// 	dest --- process that created the dets in determinant list
//      dl --- the list of determinants to be merged
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void VolatileDetStore::MergeDets(int source, int dest, 
				 Determinant_List &dl)
{
  Determinant *d1, *d2;
  Determinant_ListIterator oldDets, newDets;

  // Assume that dl and this->nonStable[dest] lists
  // are sorted by increasing d_esn's.
  oldDets = this->nonStable[dest].begin();
  for (newDets = dl.begin(); newDets != dl.end(); ++newDets) {
    d1 = *newDets;
    if (d1->d_esn <= this->stableDets[dest]) {
      //not logging determinant
      continue;
    }

    while (oldDets != this->nonStable[dest].end()) {
      d2 = *oldDets;
      assert(d1->dest == d2->dest);
      if (d2->d_esn == d1->d_esn) {
        d2->UpdateLoggedAt(source);
	break;
      }
      else if (d2->d_esn < d1->d_esn)
        ++oldDets;
      else {
	// (d2->d_esn > d1->d_esn)
	// insert d1 just before d2
	this->nonStable[dest].insert(oldDets, d1);
	// reset
	oldDets = this->nonStable[dest].begin();
	break;
      }
	
    }
    if (oldDets == this->nonStable[dest].end()) 
    // Go about merging the stuff now...
       break;
  }
  
  // Merge the remaining ones
  for ( ; newDets != dl.end(); ++newDets) {
    d1 = *newDets;
    this->nonStable[dest].push_back(d1);
    //log this determinant
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve non-stable determinants
// 
// Arguments:
// 	dest --- process to which non-stable determinants are to be
// 	         sent to.
//      knownDetId --- knownDet[i] = j, means that dest knows about
//                determinants d created by process i such that
//                d.d_esn <= j. 
//      os --- an output stream buffer into which the determinants are 
//             going to be written to.
// 
// Results:
// 	os contains all the non-stable determinants.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void VolatileDetStore::RetrieveNonstable(int dest, const int *knownDetId, 
					 std::ostrstream &os)
{
  Determinant_List retrievedList;
  Determinant_ListIterator e;
  Determinant *d;
  int i;
  int psn[EGIDA_MAX_PROCS];

  memset(psn, 0, EGIDA_MAX_PROCS * sizeof(int));
  for (i = 0; i < EGIDA_MAX_PROCS; i++) {
    for (e = this->nonStable[i].begin(); e != this->nonStable[i].end(); ++e) { 
      d = *e;
      // Send only those that dest hasn't seen before.
      if (d->d_esn > knownDetId[i]) {
	retrievedList.push_back(d);
	if (d->d_esn > psn[d->dest])
	  psn[d->dest] = d->d_esn;
      }
    }
  }

  // The information about psn is needed for causal logging
  // protocols.  Store this info. in the "reserved" part of the
  // ostream. The # of "reserved" bytes is EGIDA_MAX_PROCS * sizeof(int).
  os << EGIDA_MAX_PROCS * sizeof(int) << ' ';
  os.write((char *) psn, EGIDA_MAX_PROCS * sizeof(int));
  os << ' ';
  os << retrievedList.size() << ' ';
  for (e = retrievedList.begin(); e != retrievedList.end(); ++e) { 
    d = *e;
    os << *d << ' ';
  }
  retrievedList.clear();
  os << std::ends;
}

// /////////////////////////////////////////////////////////////////
//
// Purpose:
// 	Retrieve determinant id's from a previously created detBuf.
// 	The input buffer was created by a call to
// 	RetrieveNonstable().  For the format of detBuf, look at the
// 	code for RetrieveNonstable(). 
// 	This method is needed for causal logging protocols.
// 
// Arguments:
// 	detBuf --- a buffer of determinants that was created in a
// 	           previous call to RetrieveNonstable.
//                 The first EGIDA_MAX_PROCS * sizeof(int) bytes of
//                 detBuf contain the determinant id's (see
//                 RetrieveNonstable). 
//      detBufSize --- size of detBuf
//      detId --- output parameter ---> assume that detId[] of size
//                 EGIDA_MAX_PROCS. 
// 
// Results:
// 	detId[j] = k --- is the sequence # of the highest determinant d
// 	created by process j (d.dest = j) that is present in detBuf.
//
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void VolatileDetStore::RetrieveDetIds(const char *detBuf,
				      int detBufSize, int *detId)
{
  std::istrstream is(detBuf, detBufSize);
  int numResBytes;

  is >> numResBytes;
  // skip past the ' ' after numResBytes
  is.get();
  assert(numResBytes == (EGIDA_MAX_PROCS * sizeof(int)));
  is.read((char *) detId, numResBytes);
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Mark a set of determinants as stable.
// 
// Arguments:
// 	detId --- detId[j] = k means that all determinants d such that 
// 	          d.dest = j and d.d_esn <= k are now stable.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void VolatileDetStore::MarkStable(int *detId)
{
  Determinant_ListIterator e, first;
  Determinant *d;
  int i;

  for (i = 0; i < EGIDA_MAX_PROCS; i++) {
    if (detId[i] > this->stableDets[i])
      this->stableDets[i] = detId[i];

    first = this->nonStable[i].end();
    for (e = this->nonStable[i].begin(); e != this->nonStable[i].end(); ++e) { 
      d = *e;
      if (d->d_esn <= detId[i]) {
	if (first == this->nonStable[i].end())
	  first = e;
	this->stable[i].push_back(d);
      }
      else if (first != this->nonStable[i].end()) {
	this->nonStable[i].erase(first, e);
	first = this->nonStable[i].end();
      }
    }
    if (first != this->nonStable[i].end())
      this->nonStable[i].erase(first, e);
  }
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Mark the entire log as stable.
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

void VolatileDetStore::MarkLogStable(void)
{
  Determinant_ListIterator e;
  Determinant *d;
  int i;

  for (i = 0; i < EGIDA_MAX_PROCS; i++) {
    // Move everything from non-stable to stable
    for (e = this->nonStable[i].begin(); e != this->nonStable[i].end(); ++e) { 
      d = *e;
      if (d->d_esn >= this->stableDets[i])
	this->stableDets[i] = d->d_esn;

      this->stable[i].push_back(d);
    }
    this->nonStable[i].clear();
  }
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
//      Add dest to the loggedAt set of determinants in detId.
// 
// Arguments:
//      detId --- id of the determinants that have to be updated
// 	dest --- process that has to be addeed to the logged at set of 
// 	         each determinant d such that d.d_esn <= detId[d.dest]
//
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void VolatileDetStore::UpdateLoggedAt(int dest, const int *detId)
{
  Determinant_ListIterator e;
  Determinant *d;
  int i;

  for (i = 0; i < EGIDA_MAX_PROCS; i++) {
    for (e = this->nonStable[i].begin(); e != this->nonStable[i].end(); ++e) { 
      d = *e;
      if (d->d_esn <= detId[i]) {
	d->UpdateLoggedAt(dest);
      }
    }
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve determinants for replay phase of recovery of this
// 	process. 
// 
// Arguments:
//      self --- id of this process
// 	startEventId --- retrieve dets d such that
//           d.d_esn >= startEventId
//      lastDetId --- output parameter
// 
// Results:
// 	lastDetId --- d_esn of the last determinant that was read
// 	     from storage.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void VolatileDetStore::Read(int self, int startEventId, int *lastDetId)
{
  this->stableStore->Read(self, startEventId, lastDetId,
			  &(this->stable[self]));
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve a determinant that has to be replayed.
// 
// Arguments:
//      self --- id of this process
// 	eventId --- id of the event for which a det. has to be
// 	retrieved.
//      matchingDet --- output parameter
// 
// Results:
// 	matchingDet --- if a matching determinant exists, then, this is a pointer
// 	    to that determinant.  The caller of this method SHOULD NOT
// 	    delete matchingDet.
//          Otherwise, this is set to NULL.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void VolatileDetStore::Read(int self, int eventId, Determinant **matchingDet)
{
  Determinant_ListIterator e;
  Determinant *d;
  struct timeval startTime, endTime;
  double timeSpent;

  if(COLLECTING_STATS) {
    gettimeofday(&startTime, NULL);
  }

  if ((this->nextToReplay) && (this->nextToReplay->d_esn == eventId)) {
    *matchingDet = this->nextToReplay;
    ++this->nextToReplay_Iterator;
    if (this->nextToReplay_Iterator != this->nextToReplay_List->end())
      this->nextToReplay = *(this->nextToReplay_Iterator);
    else
      this->nextToReplay = NULL;
    return;
  }
 
  *matchingDet = NULL;
  for (e = this->stable[self].begin(); e != this->stable[self].end(); ++e) { 
    d = *e;
    if (d->d_esn == eventId) {
      *matchingDet = d;
      this->nextToReplay_Iterator = e;
      ++this->nextToReplay_Iterator;
      this->nextToReplay_List = &(this->stable[self]);
      if (this->nextToReplay_Iterator != this->stable[self].end())
	this->nextToReplay = *(this->nextToReplay_Iterator);
      else
	this->nextToReplay = NULL;
      // got it

      if(COLLECTING_STATS) {
	gettimeofday(&endTime, NULL);
	Timer::ComputeTimeDiff(&timeSpent, startTime, endTime);
	Stats::Update(EGIDA_RECOVERY_DETSTORE_MISS_STAT, 0, timeSpent);
      }

      return;
    }
    if (d->d_esn > eventId) {
      // trouble...
      std::cout << "stable matching determinant for event: " << eventId 
		<< " doesn't exist!" << std::endl;
      std::cout << "found det: " << *d << std::endl;
      assert(0);
    }
  }

  for (e = this->nonStable[self].begin(); e != this->nonStable[self].end(); ++e) { 
    d = *e;
    if (d->d_esn == eventId) {
      *matchingDet = d;
      this->nextToReplay_Iterator = e;
      ++this->nextToReplay_Iterator;
      this->nextToReplay_List = &(this->stable[self]);
      if (this->nextToReplay_Iterator != this->nonStable[self].end())
	this->nextToReplay = *(this->nextToReplay_Iterator);
      else
	this->nextToReplay = NULL;
      break;
    }
    if (d->d_esn > eventId) {
      // trouble...
      std::cout << "non-stable matching determinant for event: " << eventId 
		<< " doesn't exist!" << std::endl;
      assert(0);
    }
  }

  if(COLLECTING_STATS) {
    gettimeofday(&endTime, NULL);
    Timer::ComputeTimeDiff(&timeSpent, startTime, endTime);
    Stats::Update(EGIDA_RECOVERY_DETSTORE_MISS_STAT, 0, timeSpent);
  }
}

// /////////////////////////////////////////////////////////////////
//
// Purpose:
//      This is for helping the recovery of recovering process
//
// Arguments:
// 	recoveringProc --- id of the recovering process.
//      startDetId --- determinants d such that
//           d.dest = recoveringProc and d.d_esn >= startDetId
//           will be returned.
//      dets, detSize --- output parameter
// 
// Results:
// 	dets --- buffer containing the determinants for the recovering
// 	   process.  It is the responsibility of the caller of this
// 	   method to free the storage allocated for dets by calling
// 	   delete.
//      detSize --- size of the dets buffer.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void VolatileDetStore::Read(int recoveringProc, int startDetId,
			    char **dets, int *detSize)
{
  Determinant_List diskRetrieve_List, memRetrieve_List;
  Determinant_ListIterator e;
  Determinant *d;
  std::ostrstream os;
  int i, lastDetId;

  this->stableStore->Read(recoveringProc, startDetId, &lastDetId, 
			  &diskRetrieve_List);

  for (i = 0; i < this->numProcs; i++) {
    for (e = this->stable[i].begin(); e != this->stable[i].end(); ++e)
      {
	d = *e;
	if (((d->dest == recoveringProc) && (d->d_esn >= startDetId))
	    || (d->IsLoggedAt(recoveringProc))) {
	  memRetrieve_List.push_back(d);
	}
      }
    for (e = this->nonStable[i].begin(); e != this->nonStable[i].end(); ++e)
      {
	d = *e;
	if (((d->dest == recoveringProc) && (d->d_esn >= startDetId))
	    || (d->IsLoggedAt(recoveringProc))) {
	  memRetrieve_List.push_back(d);
	}
      }
  }

  // The # of bytes of "reserved" data is 0.
  os << 0 << ' ';
  os << diskRetrieve_List.size() + memRetrieve_List.size() << ' ';

  this->PrintDetList(diskRetrieve_List, os);
  this->PrintDetList(memRetrieve_List, os);
  os << std::ends;
  *dets = os.str();
  *detSize = os.pcount();
  
  // free the storage for dets retrieved from disk
  for (e = diskRetrieve_List.begin(); e != diskRetrieve_List.end();
       ++e) {
    d = *e;

    delete d;
  }
  // remove pointers to all dets in the list
  diskRetrieve_List.clear();
  // remove pointers to all dets in the list
  memRetrieve_List.clear();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Try to find a determinant that is "closest" to eventId.  This
// 	method is needed for Optimistic protocols in which the
// 	recovering process tries to compute the state to which it can
// 	recover.
// 
// Arguments:
//      self --- id of this process
// 	eventId --- id of the event for which a det. has to be
// 	retrieved.
//      matchingDet --- output parameter
// 
// Results:
// 	matchingDet --- if a matching determinant exists, then, this is a pointer
// 	    to that determinant.  The caller of this method SHOULD NOT
// 	    delete matchingDet.
//          Otherwise, this is set to NULL.
//      Returns (matchingDet != NULL)
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
bool VolatileDetStore::GetNextDet(int self, int eventId, 
				  Determinant **matchingDet) 
{
  Determinant_ListIterator e;
  Determinant *d;

  *matchingDet = NULL;
  for (e = this->stable[self].begin(); e != this->stable[self].end(); ++e) { 
    d = *e;
    if (d->d_esn >= eventId) {
      *matchingDet = d;
      return true;
    }
  }

  for (e = this->nonStable[self].begin(); e != this->nonStable[self].end(); ++e) { 
    d = *e;
    if (d->d_esn >= eventId) {
      *matchingDet = d;
      return true;
    }
  }
  return false;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Set a callback function that has to be invoked whenever the
// 	log is written out to stable storage.
// 
// Arguments:
// 	stableCallback --- function to callback whenever the contents
// 	of the det log are flushed to stable storage.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void VolatileDetStore::SetLogStableCallback(void (*stableCallback)(int))
{
  this->stableStore->SetLogStableCallback(stableCallback);
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

void VolatileDetStore::RestartingFromCkpt(void)
{
  this->stableStore->RestartingFromCkpt();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Add a determinant to the log on stable store.
// 
// Arguments:
// 	d --- pointer to the determinant that has to be added.  After
// 	this method call, the caller SHOULD NOT refer to d.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void StableDetStore::Write(Determinant *d)
{
  char fileName[EGIDA_FILENAME_LEN];

  struct timeval timeStart;
  if(COLLECTING_STATS) { 
    gettimeofday(&timeStart, NULL);
  }

  if(this->ofs == NULL) {
    this->ofs = new std::ofstream;
    sprintf(fileName, "%s.%d", this->diskLogBaseName, this->lme.logCounter);
    this->ofs->open(fileName, std::ios::app);
  }

  if(HASH_DETERMINANTS) {
    this->singleDetCounter += 1;
    if(!this->singleDetHashInit) {
      Security::HashSingleDetInit();
      this->singleDetHashInit = true;
    }

    Security::HashSingleDet(d);

    if(this->singleDetCounter == HASH_LIST_SIZE) {
      unsigned char * digest = new unsigned char[MD5_DIGEST_LENGTH];
      unsigned char * signature = new unsigned char[RSA_BUF_SIZE];
      
      Security::HashSingleDetFinal(digest);
      Security::EncryptWithRSA(MD5_DIGEST_LENGTH, 
			       digest,
			       signature);
      int num = HASH_LIST_SIZE;
      this->sigFd->write((const char *)&num, sizeof(int));
      this->sigFd->write((const char *)signature, RSA_BUF_SIZE);
      this->sigFd->flush();
      
      Security::HashSingleDetInit();
      this->singleDetCounter = 0;

      delete [] digest;
      delete [] signature;
    }
  }


  if(ENCRYPT_DETERMINANTS) {
    Determinant * temp = new Determinant();
    Security::EncryptDeterminant(temp, d);
    *(this->ofs) << *temp << std::endl;
    delete temp;
  }
  else {
    *(this->ofs) << *d << std::endl;
  }

  this->ofs->flush();
  fsync(this->ofs->rdbuf()->fd());
  // Update the meta-data about the log file
  if (this->lme.logStartEsn[d->dest] < 0)
    this->lme.logStartEsn[d->dest] = d->d_esn;
  if (d->d_esn > this->lme.logEndEsn[d->dest])
    this->lme.logEndEsn[d->dest] = d->d_esn;
  if ((this->LogStableCallback) && (d->dest == this->id))
    this->LogStableCallback(d->d_esn);

  delete d;

  if(COLLECTING_STATS) {
    struct timeval timeEnd;
    double timeSpent = 0.0;
    gettimeofday(&timeEnd, NULL);
    Timer::ComputeTimeDiff(&timeSpent, timeStart, timeEnd);
    Stats::Update(EGIDA_DET_WRITE_STAT, 0, timeSpent);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Write out a list of determinants to stable store.
// 
// Arguments:
// 	dl --- pointer to the list of determinant that have to be added.  
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void StableDetStore::WriteDetList(const Determinant_List &dl)
{
  Determinant_ListConstIterator e;
  Determinant *d;
  char fileName[EGIDA_FILENAME_LEN];

  if(this->ofs == NULL) {
    this->ofs = new std::ofstream;
    sprintf(fileName, "%s.%d", this->diskLogBaseName, this->lme.logCounter);
    this->ofs->open(fileName, std::ios::app);
  }

  if(HASH_DETERMINANTS) {
    unsigned char * signature = new unsigned char[RSA_BUF_SIZE];
    int num = 0;

    //just in case there were single dets being written to file
    // we should finalize the hash and store this signature first
    // so that the reading of the dets back in will match the order
    // in which they were written.
    if(this->singleDetCounter > 0) {
      unsigned char * digest = new unsigned char[MD5_DIGEST_LENGTH];

      Security::HashSingleDetFinal(digest);
      Security::EncryptWithRSA(MD5_DIGEST_LENGTH, 
			       digest,
			       signature);
      num = this->singleDetCounter;
      this->sigFd->write((const char *)&num, sizeof(int));
      this->sigFd->write((const char *)signature, RSA_BUF_SIZE);
      this->sigFd->flush();
      
      Security::HashSingleDetInit();
      this->singleDetCounter = 0;

      delete [] digest;
    }

    Security::HashAndSignDetList(dl, signature, num);

    if(num > 0) {
      this->sigFd->write((const char *)&num, sizeof(int));
      this->sigFd->write((const char *)signature, RSA_BUF_SIZE);
      this->sigFd->flush();
    }
    delete [] signature;
  }

  if(ENCRYPT_DETERMINANTS) {
    Determinant * temp = new Determinant();
    
    for (e = dl.begin(); e != dl.end(); ++e) {
      d = *e;
      Security::EncryptDeterminant(temp, d);
      *(this->ofs) << *temp << std::endl;
      temp->Clear();
      if (this->lme.logStartEsn[d->dest] < 0)
	this->lme.logStartEsn[d->dest] = d->d_esn;
      if (d->d_esn > this->lme.logEndEsn[d->dest])
	this->lme.logEndEsn[d->dest] = d->d_esn;
    }
    delete temp;
  }
  else {
    for(e = dl.begin(); e != dl.end(); ++e) {
      d = *e;
      *(this->ofs) << *d << std::endl;
      
      if (this->lme.logStartEsn[d->dest] < 0)
	this->lme.logStartEsn[d->dest] = d->d_esn;
      if (d->d_esn > this->lme.logEndEsn[d->dest])
	this->lme.logEndEsn[d->dest] = d->d_esn;
    }
  }

  if (dl.size() > 0) {
    d = dl.back();
    this->ofs->flush();
    fsync(this->ofs->rdbuf()->fd());
  }
  else
    d = NULL;

  if ((this->LogStableCallback) && (d != NULL) && (d->dest == this->id))
    this->LogStableCallback(d->d_esn);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Called after a checkpoint is written out.  Log files are
// 	maintained on a per checkpoint basis (for example, logFile.1.1 maintained 
// 	by process 1 contains the determinants from checkpoint 1 to
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

void StableDetStore::CkptDone()
{
  char fileName[EGIDA_FILENAME_LEN];
  char sigFileName[EGIDA_FILENAME_LEN];

  this->lme_List.push_back(new LogMetaEntry(this->lme));

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
    if(this->sigFd != NULL) {
      if(this->sigFd->is_open()) {
	this->sigFd->flush();  
	this->sigFd->close();
      }
    }
    else {
      this->sigFd = new std::ofstream;
    }
  }

  this->lme.Clear();
  this->lme.logCounter++;

  sprintf(fileName, "%s.%d", this->diskLogBaseName, this->lme.logCounter);
  this->ofs->open(fileName, std::ios::out);

  if(HASH_DETERMINANTS) {
    sprintf(sigFileName, "%s.%s", fileName, "hashes");
    this->sigFd->open(sigFileName, std::ios::out);
    this->singleDetCounter = 0;
    this->singleDetHashInit = false;
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Garbage collect determinants from stable store.
// 
// Arguments:
// 	procId, detId: Discard dets with d->dest == procId such that
// 	               d->d_esn < detId.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void StableDetStore::GarbageCollect(int procId, int detId)
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

  if (this->gcDets[procId] < detId)
    this->gcDets[procId] = detId;

  first = this->lme_List.end();
  for (e = this->lme_List.begin(); e != this->lme_List.end(); ++e) {
    l = *e;
    for (i = 0; i < EGIDA_MAX_PROCS; i++) {
      if (l->logEndEsn[i] > this->gcDets[i]) {
	done = true;
	break;
      }
    }
    if (done)
      break;
    if (first == this->lme_List.end())
      first = e;
    needToErase = true;

    // All the determinants in this file are no longer needed.
    sprintf(fileName, "%s.%d", this->diskLogBaseName, l->logCounter);
    unlink(fileName);
    
    //so neither are the signed hashes
    if(HASH_DETERMINANTS) {
      sprintf(sigFileName, "%s.%s", fileName, "hashes");
      unlink(sigFileName);
    }

    delete l;
    //delete the file
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
// 	Throw away determinants from storage---the difference between
// 	this method and garbage collect is that the comparator used
// 	for throwing away dets is different (>= as opposed to <).
// 
// Arguments:
// 	procId, detId: Discard dets with d->dest == procId such that
// 	               d->d_esn >= detId.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void StableDetStore::Purge(int procId, int detId)
{
  Determinant_ListIterator e, eraseStart;
  Determinant *d;

  for (e = this->cached_List.begin(); e != this->cached_List.end(); ++e) 
    {
      d = *e;
      if (d->d_esn >= detId)
      // begin erasing from here
      break;
    }
  eraseStart = e;
  for (; e != this->cached_List.end(); ++e) {
    d = *e;

    delete d;
  }
  this->cached_List.erase(eraseStart, this->cached_List.end());
  

  // Purge the stuff on disk
  PurgeDetsOnDisk(procId, detId);
}

// /////////////////////////////////////////////////////////////////
//
// 	Throw away determinants from storage---the difference between
// 	this method and garbage collect is that the comparator used
// 	for throwing away dets is different (>= as opposed to <).
// 
// Arguments:
// 	procId, purgeStartDet: Discard dets with d->dest == procId such that
// 	               d->d_esn >= purgeStartDet
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void StableDetStore::PurgeDetsOnDisk(int procId, int purgeStartDet)
{
  char logFile[EGIDA_FILENAME_LEN];
  char sigFileName[EGIDA_FILENAME_LEN];
  Determinant d, *saveDet, temp;
  Determinant_List save_List;
  Determinant_ListIterator save_List_Iter;
  LogMetaEntry_ListIterator e, eraseStart;
  LogMetaEntry *lme_Entry;
  bool needToErase = false;
  char *detBuf;
  int ifd;
  struct stat fileInfo;
  std::ofstream tempFS;
  int numDets = 0;

  // The lme_List contains info. about all the files except the
  // "current" one (the one in this->lme)
  this->lme_List.push_back(new LogMetaEntry(this->lme));

  eraseStart = this->lme_List.end();
  // go thru all the log files and read the ones that are needed
  for (e = this->lme_List.begin(); e !=  this->lme_List.end(); ++e)
    {
      lme_Entry = *e;
      sprintf(logFile, "%s.%d", this->diskLogBaseName,
	      lme_Entry->logCounter);

      // if lme_Entry is < 0, means re-build meta-data
      if ((lme_Entry->logEndEsn[procId] >= 0) &&
	  (lme_Entry->logEndEsn[procId] < purgeStartDet)) {
	std::cout << "Not purging log file: " << logFile << std::endl;
	std::cout << "End esn = " << lme_Entry->logEndEsn[procId] 
		  <<" Purge start = " << purgeStartDet << std::endl;
	continue;
      }

      // read the determinants in this file
      if ((ifd = open(logFile, O_RDONLY, S_IRUSR | S_IWUSR)) < 0) {
	std::cout << "Trouble opening log file: " << logFile << ' ' 
		  <<errno << std::endl;
	assert(0);
      }
      stat(logFile, &fileInfo);
      if (fileInfo.st_size <= 0) {
	// skip this log file because it is empty
	continue;
      }

      memset(lme_Entry->logStartEsn, 0, this->numProcs * sizeof(int));
      memset(lme_Entry->logEndEsn, 0, this->numProcs * sizeof(int));
      // read it in one shot
      detBuf = mmap(NULL, fileInfo.st_size, PROT_READ, MAP_PRIVATE, ifd, 0);
      {
	// This is block is due to the silly problem with istrstream
	// constructor which allows a char buffer to be attached only thru
	// the constructor.
	std::istrstream is(detBuf, fileInfo.st_size);

	if(ENCRYPT_DETERMINANTS) {

	  while (1) {
	    temp.Clear();
	    d.Clear();

	    is >> temp;

	    if (is.fail())
	      break;

	    Security::DecryptDeterminant(&d, &temp);
	    
	    if ((d.dest == procId) && (d.d_esn >= purgeStartDet)) 
	      continue;
	    
	    save_List.push_back(new Determinant(d));
	    
	    // re-build the meta-data if needed...
	    if (lme_Entry->logStartEsn[d.dest] <= 0)
	      lme_Entry->logStartEsn[d.dest] = d.d_esn;
	    if (d.d_esn > lme_Entry->logEndEsn[d.dest])
	      lme_Entry->logEndEsn[d.dest] = d.d_esn;
	  }
	}
	else {
	  while (1) {
	    d.Clear();
	    is >> d;
	    if (is.fail())
	      break;
	    
	    if ((d.dest == procId) && (d.d_esn >= purgeStartDet)) 
	      continue;
	    
	    save_List.push_back(new Determinant(d));
	    
	    // re-build the meta-data if needed...
	    if (lme_Entry->logStartEsn[d.dest] <= 0)
	      lme_Entry->logStartEsn[d.dest] = d.d_esn;
	    if (d.d_esn > lme_Entry->logEndEsn[d.dest])
	      lme_Entry->logEndEsn[d.dest] = d.d_esn;
	  }
	}

	// freeze the buffer so that is's destructor won't free it
	is.rdbuf()->freeze(true);
      }
      munmap(detBuf, fileInfo.st_size);
      close(ifd);
      if (save_List.size() <= 0) {
	//	unlink(logFile);  <---need to fix this...isn't working properly

	if(HASH_DETERMINANTS) {
	  //since we are getting rid of the logfile, 
	  //we don't need the signatures
	  sprintf(sigFileName, "%s.%s", logFile, "hashes");
	  unlink(sigFileName);
	} 

	if (!needToErase) {
	  needToErase = true;
	  eraseStart = e;
	}
      }
      else {
	tempFS.open(logFile, std::ios::out);

	if(HASH_DETERMINANTS) {
	  //since we are going to be changing the logfile, 
	  //we will need to recompute the hash and signature
	  sprintf(sigFileName, "%s.%s", logFile, "hashes");
	  unlink(sigFileName);
	  Security::RecreateHashDetInit();
	} 


	for (save_List_Iter = save_List.begin(); save_List_Iter !=
	       save_List.end(); ++save_List_Iter) {
	  saveDet = *save_List_Iter;
	  
	  if(HASH_DETERMINANTS) {
	    Security::RecreateHashSingleDet(saveDet);
	    numDets ++;
	  }
	  
	  if(ENCRYPT_DETERMINANTS) {
	    temp.Clear();
	    Security::EncryptDeterminant(&temp, saveDet);
	    tempFS << temp << std::endl;
	  }
	  else { 
	    tempFS << *saveDet << std::endl;
	  }

	}

	//make sure any info we have in dets are released
	temp.Clear();
	d.Clear();
	saveDet->Clear();
	
	//close out the temporary file
	tempFS.flush();
	tempFS.close();
	
	if(HASH_DETERMINANTS) {
	  int fd = open(sigFileName, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	  unsigned char * digest = new unsigned char[MD5_DIGEST_LENGTH];
	  unsigned char * signature = new unsigned char[RSA_BUF_SIZE];
      
	  Security::RecreateHashDetFinal(digest);
	  Security::EncryptWithRSA(MD5_DIGEST_LENGTH, 
				   digest,
				   signature);

	  write(fd, (const char *)&numDets, sizeof(int));
	  write(fd, (const char *)signature, RSA_BUF_SIZE);
	  close(fd);
	
	  delete [] digest;
	  delete [] signature; 
	}
	
      }
    }
  // remove the one we pushed in this method
  lme_Entry = this->lme_List.back();
  // if we rebuilt any of the meta-data, copy  it back.
  this->lme = *lme_Entry;
  // Erase the ones that are no longer needed
  if (needToErase) {
    e = eraseStart;
    for (; e != this->lme_List.end(); ++e) {

      delete *e;
    }
    this->lme_List.erase(eraseStart, this->lme_List.end());
  } 
  else {
    // This is then entry that was pushed at the top of this method.
    this->lme_List.pop_back();

    delete lme_Entry;
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve determinants for replay phase of recovery of this
// 	process.  Since this is the NFS stable store object, the
// 	determinants retrieved are cached in memory.
// 
// Arguments:
//      self --- id of this process.
// 	startEventId --- retrieve dets d such that
//           d.d_esn >= startEventId
//      lastDetId --- output parameter
// 
// Results:
// 	lastDetId --- d_esn of the last determinant that was read
// 	     from storage.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void StableDetStore::Read(int self, int startEventId, int *lastDetId)
{
  // cache the determinants in memory
  this->Read(self, startEventId, lastDetId,
	     &(this->cached_List));
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve determinants for replay phase of recovery.
// 
// Arguments:
//      procId --- retrieve dets created by process procId.
// 	startEventId --- retrieve dets d such that
//           (d.dest = procId) && (d.d_esn >= startEventId)
//      lastDetId --- output parameter
//      retrieveDetList --- output parameter
// 
// Results:
// 	lastDetId --- d_esn of the last determinant that was read
// 	     from storage.
//      retrieveDetList --- list of determinants retrieved from stable 
//           storage.  It is the responsibility of the caller to free
//           the storage space allocated for the determinants by
//           calling delete on each item of the list.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void StableDetStore::Read(int procId, int startEventId, 
			  int *lastDetId,
			  Determinant_List *retrieve_List)
{
  char logFile[EGIDA_FILENAME_LEN];
  Determinant d;
  LogMetaEntry_ListIterator e;
  LogMetaEntry *lme_Entry;
  char *detBuf;
  int ifd;
  struct stat fileInfo;

  *lastDetId = 0;
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
      if ((lme_Entry->logEndEsn[procId] >= 0) &&
	  (lme_Entry->logEndEsn[procId] < startEventId)) {
	std::cout << "Not opening log file: " << logFile << std::endl;
	continue;
      }

      // read the determinants in this file
      if ((ifd = open(logFile, O_RDONLY, S_IRUSR | S_IWUSR)) < 0) {
	std::cout << "Trouble opening log file: " << logFile << ' '
		  <<errno << std::endl;
	assert(0);
      }
      stat(logFile, &fileInfo);
      if (fileInfo.st_size <= 0) {
	//skip this log file since it has a size of 0
	continue;
      }
      
      memset(lme_Entry->logStartEsn, 0, this->numProcs * sizeof(int));
      memset(lme_Entry->logEndEsn, 0, this->numProcs * sizeof(int));
      // read it in one shot
      detBuf = mmap(NULL, fileInfo.st_size, PROT_READ, MAP_PRIVATE, ifd, 0);
      {
	// This is block is due to the silly problem with istrstream
	// constructor which allows a char buffer to be attached only thru
	// the constructor.
	std::istrstream is(detBuf, fileInfo.st_size);


	if(HASH_DETERMINANTS) {
	  //make sure the determinants have not been tampered with
	  bool good = Security::VerifyDetChunksInFile(logFile);

	  if(!good) {
	    std::cout << "Determinants  in file: " << logFile
		      << " have been tampered with." << std::endl; 
	    std::cout << " Abort Playback..." << std::endl;
	    //exit(0);
	  }
	  else {
	    std::cout << "Determinants in file: " << logFile
		      << " are fine. Continue playback...." << std::endl;
	  }
	}


	if(ENCRYPT_DETERMINANTS) {
	  Determinant temp;

	  while (1) {
	    d.Clear();
	    temp.Clear();
	    is >> temp;	    
	    
	    if (is.fail())
	      break;
	    
	    Security::DecryptDeterminant(&d, &temp);
	    
	    if ((d.dest == procId) && (d.d_esn >= startEventId)) {
	      *lastDetId = d.d_esn;
	      retrieve_List->push_back(new Determinant(d));
	    }
	    // re-build the meta-data if needed...
	    if (lme_Entry->logStartEsn[d.dest] <= 0)
	      lme_Entry->logStartEsn[d.dest] = d.d_esn;
	    if (d.d_esn > lme_Entry->logEndEsn[d.dest])
	      lme_Entry->logEndEsn[d.dest] = d.d_esn;
	  }
	}
	else {
	  while (1) {
	    d.Clear();
	    is >> d;
	    
	    if (is.fail())
	      break;
	    
	    if ((d.dest == procId) && (d.d_esn >= startEventId)) {
	      *lastDetId = d.d_esn;
	      retrieve_List->push_back(new Determinant(d));
	    }
	    // re-build the meta-data if needed...
	    if (lme_Entry->logStartEsn[d.dest] <= 0)
	      lme_Entry->logStartEsn[d.dest] = d.d_esn;
	    if (d.d_esn > lme_Entry->logEndEsn[d.dest])
	      lme_Entry->logEndEsn[d.dest] = d.d_esn;
	  }
	
	}
	// freeze the buffer so that is's destructor won't free it
	is.rdbuf()->freeze(true);
      }
      munmap(detBuf, fileInfo.st_size);
      close(ifd);
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
// 	Retrieve a determinant that has to be replayed.
// 
// Arguments:
//      self --- id of this process
// 	eventId --- id of the event for which a det. has to be
// 	retrieved.
//      matchingDet --- output parameter
// 
// Results:
// 	matchingDet --- if a matching determinant exists, then, this is a pointer
// 	    to that determinant.  The caller of this method SHOULD NOT
// 	    delete matchingDet.
//          Otherwise, this is set to NULL.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void StableDetStore::Read(int self, int eventId, Determinant **matchingDet)
{
  Determinant_ListIterator e;
  Determinant *d;

  if ((this->nextToReplay) && (this->nextToReplay->d_esn == eventId)) {
    *matchingDet = this->nextToReplay;
    ++this->nextToReplay_Iterator;
    if (this->nextToReplay_Iterator != this->cached_List.end())
      this->nextToReplay = *(this->nextToReplay_Iterator);
    else
      this->nextToReplay = NULL;
    return;
  }
  
  *matchingDet = NULL;
  for (e = this->cached_List.begin(); e != this->cached_List.end(); ++e) { 
    d = *e;
    if (d->d_esn == eventId) {
      *matchingDet = d;
      this->nextToReplay_Iterator = e;
      ++this->nextToReplay_Iterator;
      if (this->nextToReplay_Iterator != this->cached_List.end())
	this->nextToReplay = *(this->nextToReplay_Iterator);
      else
	this->nextToReplay = NULL;
      break;
    }
    if (d->d_esn > eventId) {
      // trouble...
      std::cout << "matching determinant for event: " << eventId 
		<< " doesn't exist!" << std::endl;
      assert(0);
    }
  }
}

// /////////////////////////////////////////////////////////////////
//
// Purpose:
//      This is for helping the recovery of recovering process
//
// Arguments:
// 	recoveringProc --- id of the recovering process.
//      startDetId --- determinants d such that
//           d.dest = recoveringProc and d.d_esn >= startDetId
//           will be returned.
//      dets, detSize --- output parameter
// 
// Results:
// 	dets --- buffer containing the determinants for the recovering
// 	     process.  It is the responsibility of the caller of this
// 	     method to free the storage allocated for dets by calling
// 	     delete.
//      detSize --- size of the dets buffer.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void StableDetStore::Read(int recoveringProc, int startDetId,
			  char **dets, int *detSize)
{
  Determinant_List diskRetrieve_List;
  Determinant_ListIterator e;
  Determinant *d;
  std::ostrstream os;
  int lastDetId;

  this->Read(recoveringProc, startDetId, &lastDetId, 
	     &diskRetrieve_List);

  // The # of bytes of "reserved" data is 0.
  os << 0 << ' ';
  os << diskRetrieve_List.size() << ' ';
  this->PrintDetList(diskRetrieve_List, os);
  os << std::ends;
  *dets = os.str();
  *detSize = os.pcount();
  
  // free the storage for dets retrieved from disk
  for (e = diskRetrieve_List.begin(); e != diskRetrieve_List.end();
       ++e) {
    d = *e;

    delete d;
  }
  // remove pointers to all dets in the list
  diskRetrieve_List.clear();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Try to find a determinant that is "closest" to eventId.  This
// 	method is needed for Optimistic protocols in which the
// 	recovering process tries to compute the state to which it can
// 	recover.
// 
// Arguments:
//      self --- id of this process
// 	eventId --- id of the event for which a det. has to be
// 	retrieved.
//      matchingDet --- output parameter
// 
// Results:
// 	matchingDet --- if a matching determinant exists, then, this is a pointer
// 	    to that determinant.  The caller of this method SHOULD NOT
// 	    delete matchingDet.
//          Otherwise, this is set to NULL.
//      Returns (matchingDet != NULL)
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
bool StableDetStore::GetNextDet(int self, int eventId, 
				Determinant **matchingDet) 
{
  Determinant_ListIterator e;
  Determinant *d;

  *matchingDet = NULL;
  for (e = this->cached_List.begin(); e != this->cached_List.end(); ++e) { 
    d = *e;
    if (d->d_esn >= eventId) {
      *matchingDet = d;
      return true;
    }
  }
  return false;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Set a callback function that has to be invoked whenever the
// 	log is written out to stable storage.
// 
// Arguments:
// 	stableCallback --- function to callback whenever the contents
// 	of the det log are flushed to stable storage.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void StableDetStore::SetLogStableCallback(void (*stableCallback)(int))
{
  this->LogStableCallback = stableCallback;
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
void StableDetStore::SetLogFileName(const char *baseName) 
{
  char fileName[EGIDA_FILENAME_LEN];
  char sigFileName[EGIDA_FILENAME_LEN];

  sprintf(this->diskLogBaseName, "%s/%s.%d", EGIDA_LOGS_DIR, baseName, 
	  this->id);

  assert(ofs != NULL);
  this->ofs->close();
  sprintf(fileName, "%s.%d", this->diskLogBaseName, this->lme.logCounter);
  unlink(fileName);

  if(HASH_DETERMINANTS){
    assert(sigFd != NULL);
    this->sigFd->close();
    sprintf(sigFileName, "%s.%s", fileName, "hashes");
    unlink(sigFileName);
  }

  sprintf(fileName, "%s.%d", this->diskLogBaseName, this->lme.logCounter);
  this->ofs->open(fileName, std::ios::out);

  if(HASH_DETERMINANTS){
    sprintf(sigFileName, "%s.%s", fileName, "hashes");
    this->sigFd->open(sigFileName, std::ios::out);
    this->singleDetCounter = 0;
    this->singleDetHashInit = false;
  }
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
void StableDetStore::RestartingFromCkpt(void)
{
  char fileName[EGIDA_FILENAME_LEN];
  std::ofstream tempFs;
  LogMetaEntry_ListIterator first, e;
  LogMetaEntry *lme_Entry;

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
      std::cout << "Found file: " << fileName << std::endl;
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
// 
// Purpose:
// 	Called after replay phase of recovery is finished.  If the
// 	stable store is maintaining any log files on disk, then, they
// 	have to be re-opened in write mode.
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
void StableDetStore::ReplayDone()
{
  Determinant_ListIterator e;
  Determinant *d;
  char fileName[EGIDA_FILENAME_LEN];
  char sigFileName[EGIDA_FILENAME_LEN];
  
  this->nextToReplay = NULL;
  this->nextToReplay_List = NULL;

  for (e = this->cached_List.begin(); e != this->cached_List.end();
       ++e) {
    d = *e;

    delete d;
  }
  this->cached_List.clear();

  sprintf(fileName, "%s.%d", this->diskLogBaseName, this->lme.logCounter);

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
    this->sigFd = new std::ofstream;
    sprintf(sigFileName, "%s.%s", fileName, "hashes");
    this->sigFd->open(sigFileName, std::ios::app);
    this->singleDetCounter = 0;
    this->singleDetHashInit = false;
  }

}
