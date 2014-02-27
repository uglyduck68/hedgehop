// HowToCkpt.cc -- 
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
// $Log: HowToCkpt.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:18  ravshank
// Start of Spring 2001
//
// Revision 1.17  2000/11/21 22:27:17  phoebe
// GarbageCollect in the SentStore is now working async. We changed the logic slightly so that all files are cleaned by one process and we clean when we've heard 3 responses (not necessarily all from different processes...this is ok we think.) Also...our favorite core dump on TakeCkpt (the memcpy one) has crept back in the picture. <grrrr>
//
// Revision 1.16  2000/10/31 00:22:47  phoebe
// SBP now works with flushing and garbage collection. Before the file out pointers were not being managed properly so after a garbagecollect they were pointing to a non-existant file. So the point of all of this is we have a working SentStore.cc file.
//
// Revision 1.15  2000/10/24 16:32:29  phoebe
// Garbage collection of the sentLog is now happening but sometimes it doesn't recover...think it's a problem with multiple recoveries and not flushing some info. Will check into it. Fixed the memcpy core dump on taking a checkpoint...it was a problem with the fact that we were using a signed int to track the segment size and should have been using an unsigned int so that we didn't get overflow problem.
//
// Revision 1.14  2000/10/17 15:02:33  phoebe
// Stable code checkin. RBP is extremely stable except if you kill the master and slave at exactly the same time....it will hang in ReplayDeliver. SBP cannot support concurrent failures due to the lost control messages or hanging in ReplayDeliver. Causal can do +concurrent+ failures as long as control messages are not lost....so the restart must be staggered. Causal seems to suffer the same RBP problem with a master/slave pair, but unsure if this is the problem or if I didn't set numfailures=2...think the later would fix this. All the sentLog protocols (SBP and Causal) suffer from processes dumping core during WriteCkpt if they have been running for a long time since we are not flushing volatile memory at the moment. Should go away with the proper sentLog class fix.
//
// Revision 1.13  2000/10/12 19:50:56  phoebe
// Optimistic is still not working for more than one failure, but the incarnation number is now working correctly, and on the second failure it hangs in exactly the same spot every time. Also...optimistic is now rolling back a checkpoint file instead of doing the exec-ing that it was doing before. Additionally, during some of the debugging process, checkpoints are now shrinking heap sizes correctly (we thought they were doing it before, but they weren't.)
//
// Revision 1.12  2000/09/27 22:03:08  phoebe
// In CkptImpl changed the growing of the heap from a strict monotonically increasing function (using the check that we only grow if size is less than what is needed) to one that can shrink. The reason we can do this is sbrk will take as an argument a negative value, where as malloc cannot.
//
// Revision 1.11  2000/08/08 20:57:18  phoebe
// Cleaned up code, and now the never checkpointing again after a fail error is fixed.
//
// Revision 1.10  2000/08/08 14:28:57  phoebe
// Can now restart multiple times and kill the master process for Receiver Based Pessimistic logging. Same thing for Sender Based, but with sender based since the recovery logs must be in volatile memory, it will eventually run out of RAM and won't be able to continue or restart (obviously). This is a protocol design bug that will be fixed, but the restart is stable. Also able to restart from an incremental checkpoint (tested with RBP). These restart tests were done without any security turned on.
//
// Revision 1.9  2000/06/30 20:10:21  phoebe
// Async full checkpoint now working with garbage collection.
//
// Revision 1.8  2000/06/30 19:41:37  phoebe
// Commented out actions in PostCkptActions (Egida class) and can now restart Asynch checkpoint. However, this is still not a correct implementation because it will never clean up det logs.
//
// Revision 1.7  2000/06/27 20:15:49  phoebe
// Cleaned up Makefiles. Made DebugTrace into a proper class. Fixed the communication tracking part of Stats.cc.
//
// Revision 1.6  2000/06/27 13:23:09  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.5  2000/06/26 21:31:13  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.4  2000/06/23 15:53:43  phoebe
// Cleaned up the CkptImpl class a bit.
//
// Revision 1.3  2000/06/23 02:47:41  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.2  2000/04/28 20:08:19  phoebe
// Got Async Checkpoints to return micro-measurements.
//
// Revision 1.1.1.1  2000/03/06 20:00:21  phoebe
// Sriram's original code with no modifications
//
// $Id: HowToCkpt.cc,v 1.1.1.1 2001/02/12 00:00:18 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Mon May  3 10:22:20 1999
// Last Modified By: Sriram Rao
// Last Modified On: Wed Aug 18 13:53:30 1999
// Update Count    : 53
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <assert.h>
#include <iostream>
#include <poll.h>

#include "Egida_Object.H"
#include "Globals.H"
#include "HowToCkpt.H"
#include "Stats.H"
#include "Timer.H"

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Constructor for HowToCkpt object.
//      Code doesn't compile if this stuff is in the header file.
// 
// Arguments:
// 	self -- id of this process
//      implType --- one of EGIDA_FULL_CKPT or EGIDA_INCR_CKPT
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

HowToCkpt::HowToCkpt(int self, CkptImpl::CkptImplType implType, 
		     const char *progName)
{
  this->id = self;
  this->type = implType;
  if (implType == CkptImpl::EGIDA_FULL_CKPT) {
    this->ckptImpl = new FullCkpt();
  }
  else if (implType == CkptImpl::EGIDA_INCR_CKPT) {
    this->ckptImpl = new IncrCkpt();
  }
  else {
    std::cout << "unknown checkpoint implementation!" << std::endl;
    _exit(0);
  }
  this->ckptImpl->Initialize(self);
}



bool HowToCkpt::OkToRemoveCkptFiles(void)
{
  return ( this->type == CkptImpl::EGIDA_FULL_CKPT );
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Initialize a HowToCkpt object.
// 
// Arguments:
// 	self --- id of this process
//      c    --- pointer to a checkpoint implementation object.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void HowToCkpt::Initialize(int self, CkptImpl *c)
{
  this->id = self;
  this->ckptImpl = c; 
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Front-end for calling ckptImpl->Terminate
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
void HowToCkpt::Terminate(void)
{
  this->ckptImpl->Terminate();
}


void HowToCkpt::RestoreCkpt(const char *fileName, bool rollback)
{
  assert(this != NULL);
  assert(this->ckptImpl != NULL);
  // don't know what kind of ckpt fileName is---incremental/full.
  // This happens whenever a process has to be restored using a
  // checkpoint and the variable this is junk aka place-holder.
  this->ckptImpl->RestoreCkptFile(fileName, rollback);
}

void HowToCkpt::GarbageCollect()
{

}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Synchronously write out a checkpoint.
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

void SyncCkpt::TakeCkpt()
{
  char ckptFileName[EGIDA_FILENAME_LEN];
  int ofd;

  // Get the name of the next ckpt file
  this->ckptImpl->SetupCkpt(&ofd, ckptFileName);

  if (this->ckptImpl->TakeCkpt(ofd) == 0) {
    std::cout << "Took checkpoint to file: " << ckptFileName << std::endl;
    Egida::PostCkptActions(ckptFileName);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Write out a checkpoint asynchronously.  That is, create a
// 	child process which writes out the checkpoint and dies.
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

void AsyncCkpt::TakeCkpt()
{
  char ckptFileName[EGIDA_FILENAME_LEN];
  int ofd;
  int childPid;

  // Get the name of the next ckpt file
  this->ckptImpl->SetupCkpt(&ofd, ckptFileName);
  // maintain a mapping between the ckpt file name and the id
  // of the child process

  //first record what is stable at this point
  Egida::SetAsyncStableEsn();
  Egida::AsyncSetStableRecdMsg();

  // Create the child process
  if ((childPid = fork()) == 0) {

    // A subtle issue: If TakeCkpt returns a non-zero value, then, it
    // means that state of the process has been restored using the
    // checkpoint.  In that case, need to begin executing.
    if (this->ckptImpl->TakeCkpt(ofd)) {
      return;
    }
    else {
      // A checkpoint has been written out.  
      // Our job is done.
      Stats::AsyncDump();
      _exit(0);
    }
  }
  else {
    // parent doesn't need to keep the file open
    close(ofd);
    this->childInfo_List.push_back(new AsyncCkptChildInfo(childPid, ckptFileName));
    // give the child 15 seconds to write the ckpt.
    Timer::SetTimer(15);
  }
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Called when the timer expires.  Cleans up any child processes
// 	that may have been created.
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
void AsyncCkpt::TimerExpired(void)
{
  struct pollfd pollDesc;
  int childDone, childPid;
  char ckptFileName[EGIDA_FILENAME_LEN];

  if (this->childInfo_List.empty())
    return;

  if ((childPid = waitpid(-1, &childDone, WNOHANG)) > 0) {
    if (WIFEXITED(childDone)) {      
      if(RemoveChildInfo(childPid, ckptFileName)) {
	std::cout << "Took checkpoint to file: " << ckptFileName << std::endl;
	Egida::PostAsyncCkptActions(ckptFileName);
      }
      //else some other async process exited
    }
  }

  if (!this->childInfo_List.empty())
    // interrupt after 15 seconds...
    Timer::SetTimer(15);
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Remove mapping maintained about child, childPid
// 
// Arguments:
// 	childPid --- pid of child whose info has to be removed
//      ckptFileName --- output parameter
// 
// Results:
// 	ckptFileName --- name of the file to which checkpoint was
// 	written out by child, childPid
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

bool AsyncCkpt::RemoveChildInfo(int childPid, char *ckptFileName)
{
  bool retValue = false;
  ChildInfo_ListIterator e;
  AsyncCkptChildInfo *info;

  ckptFileName[0] = '\0';
  for (e = this->childInfo_List.begin(); e !=
	 this->childInfo_List.end(); ++e) {
    info = *e;
    if (info->childPid == childPid) {
      strcpy(ckptFileName, info->ckptFileName);
      delete info;
      this->childInfo_List.erase(e);
      retValue = true;
      break;
    }
  }
  return retValue;
}

