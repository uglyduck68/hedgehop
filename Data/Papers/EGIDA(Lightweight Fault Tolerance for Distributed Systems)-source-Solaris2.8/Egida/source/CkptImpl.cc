// CkptImpl.cc -- 
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
// $Log: CkptImpl.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:17  ravshank
// Start of Spring 2001
//
// Revision 1.36  2000/11/06 23:07:11  phoebe
// Encryption of checkpoints is working again. We still have the memcpy problem, but it seems to be less frequent. It's still a bit of a mystery as to why it's happening, and although the core is always dropped on a memcpy in WriteCkpt, it's not deterministic when it happens.
//
// Revision 1.35  2000/11/01 23:24:28  phoebe
// Hash and sign of checkpoints is working. Also as checkpoints are cleaned up, so are the signed hashes corresponding to the checkpoints (this was not done earlier.)
//
// Revision 1.34  2000/11/01 16:35:24  phoebe
// Working on getting security to work again with the redesigned system. Message encryption, either full or only egida messages, is working now.
//
// Revision 1.33  2000/10/31 00:22:45  phoebe
// SBP now works with flushing and garbage collection. Before the file out pointers were not being managed properly so after a garbagecollect they were pointing to a non-existant file. So the point of all of this is we have a working SentStore.cc file.
//
// Revision 1.32  2000/10/24 16:32:25  phoebe
// Garbage collection of the sentLog is now happening but sometimes it doesn't recover...think it's a problem with multiple recoveries and not flushing some info. Will check into it. Fixed the memcpy core dump on taking a checkpoint...it was a problem with the fact that we were using a signed int to track the segment size and should have been using an unsigned int so that we didn't get overflow problem.
//
// Revision 1.31  2000/10/12 19:50:52  phoebe
// Optimistic is still not working for more than one failure, but the incarnation number is now working correctly, and on the second failure it hangs in exactly the same spot every time. Also...optimistic is now rolling back a checkpoint file instead of doing the exec-ing that it was doing before. Additionally, during some of the debugging process, checkpoints are now shrinking heap sizes correctly (we thought they were doing it before, but they weren't.)
//
// Revision 1.30  2000/10/03 22:56:22  phoebe
// Optimistic will now reliably restart once. Still fails multiple sequential failures.
//
// Revision 1.29  2000/09/27 22:03:04  phoebe
// In CkptImpl changed the growing of the heap from a strict monotonically increasing function (using the check that we only grow if size is less than what is needed) to one that can shrink. The reason we can do this is sbrk will take as an argument a negative value, where as malloc cannot.
//
// Revision 1.28  2000/08/15 16:48:17  phoebe
// Sanity check...moved declaration of variables in FullCkpt::WriteCkpt to top to be more consistent with stack allocation.
//
// Revision 1.27  2000/08/09 15:32:50  phoebe
// Changed the buffer size in CkptImpl.cc to be a #define instead of being hardwired to 4096. Also made fix in DetStore.cc and EventStore.cc that will allow both writing dets one at at time and in lists to be viable when hashing is turned on. Before this would have caused problems.
//
// Revision 1.26  2000/08/08 20:57:13  phoebe
// Cleaned up code, and now the never checkpointing again after a fail error is fixed.
//
// Revision 1.25  2000/08/08 14:28:51  phoebe
// Can now restart multiple times and kill the master process for Receiver Based Pessimistic logging. Same thing for Sender Based, but with sender based since the recovery logs must be in volatile memory, it will eventually run out of RAM and won't be able to continue or restart (obviously). This is a protocol design bug that will be fixed, but the restart is stable. Also able to restart from an incremental checkpoint (tested with RBP). These restart tests were done without any security turned on.
//
// Revision 1.24  2000/07/11 22:20:02  phoebe
// Did several things: Streamlined DebugTrace so that Egida_Object's RestoreDone didnt' need to call it (got rid of a small memory leak by doing this.) It's less efficient, but then debugging code shouldn't be in the release copy anyway. Two...moved the -recover string to the proper place in the failuredetector so that on a subsequent restart (multiple restarts of one process) it will correctly identify which checkpoint it should be rolling back to. Third...moved growing of the heap in CkptImpl to the RestoreHeapData segs for FullCkpt and put it in the RestoreCkpt for Incremental (in the loop). This is in hopes of being able to restart from in incremental checkpoint. At the moment still can't restart multilple times and can't restart from an incremental checkpoint.
//
// Revision 1.23  2000/06/29 20:10:30  phoebe
// By commenting out the std::cout's in the Full RestoreSegment method, Egida is now able to restart once again!
//
// Revision 1.22  2000/06/27 13:22:56  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.21  2000/06/26 21:31:03  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.20  2000/06/23 16:35:28  phoebe
// Cleaning out un-needed data members in classes.
//
// Revision 1.19  2000/06/23 15:53:41  phoebe
// Cleaned up the CkptImpl class a bit.
//
// Revision 1.18  2000/06/23 15:01:44  phoebe
// Took the FullCkpt data member out of IncrCkpt class. It was never instantiated and just used a a variable, so I put the variable in the methods it was needed, but took it out of the class.
//
// Revision 1.17  2000/06/23 02:47:29  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.16  2000/06/22 22:55:19  phoebe
// Changed the malloc call to grow the heap to sbrk which is better for growing the heap. Also, instead of growing just arbitratily, we grow it by the exact amount (this is all in CkptImpl spec. the CkptImpl::RestoreCkptFile method). Also...added another drain msgs call in the EventHandler::Receive function which could save a loop.
//
// Revision 1.15  2000/06/22 20:58:55  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.14  2000/04/20 21:05:53  phoebe
// Fixed the signature file name problem...it was only writing signatures to --.sig.n.1   i.e. the last number remained 1 and didn't increment.
//
// Revision 1.13  2000/04/17 16:55:07  phoebe
// Rearranged Stats functions to do both Pre and Post Init (in init.cc) and now checkpoint encryption is working. Right now have Sriram's init file for optimistic which will only run for the short programs...this time it ran to completion on cg but it will not run to completion for sp.
//
// Revision 1.12  2000/03/17 18:08:48  phoebe
// Encryption of determinants is now in place. Also I added members to DetStore.H class to handle the upcoming hash and sign hooks that will be needed for that functionality with determinants.
//
// Revision 1.11  2000/03/16 21:36:09  phoebe
// Hash and signing of checkpoints now back online. Both partial and full hash and sign.
//
// Revision 1.10  2000/03/16 17:17:59  phoebe
// Re-integrated the hash and sign functions into CkptImpl and Security files. Did not turn on any of the hooks for these functions. Just put the code in and made sure that things were still going to run.
//
// Revision 1.9  2000/03/16 16:35:02  phoebe
// Changed the writes in WriteCkpt to capture memory dumps in a buffer before writing to file. Memory changes between the initiatiation and termination of a call to write so to be able to hash appropriate values the write function and the hash function should not look directly at memory dumps but rather fixed buffer values.
//
// Revision 1.8  2000/03/16 16:13:39  phoebe
// Can now encrypt only the first checkpoint (the full ckpt) and none of the incremental checkpoints.
//
// Revision 1.7  2000/03/15 17:57:18  phoebe
// Partial checkpoint encryption is working. Tested with all three segment types. Still get the weird assert failing on EventStore.cc but generally it does not happen on loop 4...and when it does you can fail on loop 5 and it seems to be fine.
//
// Revision 1.6  2000/03/15 16:16:20  phoebe
// Full encryption of checkpoints is working.
//
// Revision 1.5  2000/03/15 15:56:55  phoebe
// Changed CkptImpl to redirect READ to one that will allow security redirection in both full and incremental.
//
// Revision 1.4  2000/03/15 15:43:12  phoebe
// Changed IncrCkpt to have the special WRITE function in its writeckpt routine.
//
// Revision 1.3  2000/03/15 15:33:39  phoebe
// Redirected the WRITE function in CkptImpl.cc so that it could be modified for including security hooks. Had to restart after 4 loop counts or else got a strange null file pointer assert that came up in EventStore.cc. Went away without modification when I waited for 4 full loop counts.
//
// Revision 1.2  2000/03/07 00:10:43  phoebe
// Channel Encryption now working. Init now does Security::Init and Security::Reinit. Communication.cc modified to call security functions (obviously). Tested with normal run and restart of Egida_Object_Init-default.cc.
//
// $Id: CkptImpl.cc,v 1.1.1.1 2001/02/12 00:00:17 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun May  2 15:43:48 1999
// Last Modified By: Sriram Rao
// Last Modified On: Sat Jul 17 13:55:58 1999
// Update Count    : 183
// Status          : Unknown, Use with caution!
// PURPOSE
// 	This module contains an implementation of checkpointing
// 	(save/restore) for solaris processes.  It is advisable to read 
// 	the man page about the /proc file system (man -s4 proc).
//
//      Basic idea in saving a checkpoint: A process virtual address
//      space consists of three segments (stack, heap, and global data 
//      area).  For a given executable, these three segments begin at
//      fixed virtual addresses; the global data area comprising of
//      initialized and uninitialized globals is always fixed
//      in size;  the size of the remaining two segments depends on
//      the process state at the time of the checkpoint.  
//       -- Saving a full checkpoint is simple --- it is necessary to know the
//          beginning virtual address of a segment and the size of the
//          segment.  From this information, each segment can be saved.
//       -- Saving an incremental checkpoint is a bit of work.  The
//       /proc file system maintains per page statistics
//       (accessed/modified) and this information has to be retrieved to
//       determine if a page has to be saved.  For details about
//       obtaining this info. from /proc, read man page.
//
//       Restoring a checkpoint: Restoring global data area and heap
//       are trivial.  In each case, using the virtual address and
//       size saved in the checkpoint file, the corresponding segment
//       can be simply read back.  The only detail is that before the
//       heap is restored, the heap has to be grown (via a malloc
//       call) to the desired size.
//       Restoring a stack is non-trivial.  During a process
//       execution, when a context switch occurs, the o/s saves state
//       on the process stack.  Therefore, if the area in which the
//       kernel has saved state is overwritten with the data from the
//       checkpoint, a core dump is virtually certain.  This can be
//       avoided by growing the stack to the desired size---a recursive 
//       function with a large array being allocated on the stack will 
//       work.  However, this is slow.  The other approach is to use
//       signals.  Solaris allows a signal handler to execute on a
//       stack that is different from the main stack.  In this module, 
//       we use this approach.  The alternate stack is located in the
//       global data area.  When the main stack has to be restored, an 
//       alternate stack is installed for a signal handler for SIGUSR2.
//       The process sends itself SIGUSR2 and in the handler the main
//       stack is read back---the same virtual address, size stuff.  
//
//       The final issue is restoring pc, stack pointer, etc.  We do
//       this using a sigsetjmp/siglongjmp system calls.  For details
//       on how these calls work, read the man page.
//
//   A note about incremental checkpointing:
//   In the current implementation, the first checkpoint is a full
//   checkpoint aka master checkpoint.  Increments are taken after
//   that.  The master checkpoint file has the name
//   <baseName>.<processId>.1.  Increments have the name
//   <baseName>.<processId>.2.  
//   For the purposes of restore, the RestoreCkpt determines the type
//   of checkpoint to restore from (full/incremental) by looking at
//   the cookie defined in the checkpoint file's header.  Assume that
//   chkpt.1.6 is an incremental checkpoint.  To restore the process
//   to that checkpoint, incremental checkpoint's RestoreCkpt first
//   looks for the file chkpt.1.1 (the master file), restores the
//   process heap/data segment from it; then, the heap/data from
//   increments chkpt.1.2 to chkpt.1.6 are restored.  After this, the
//   same procedure is followed to restore the stack and finally the
//   longjmp happens
//   ASSUMPTION: In incremental checkpointing, I am assuming that the
//   heap size doesn't shrink from one increment to the next.

#include <iostream>

#include "CkptImpl.H"
#include "DebugTrace.H"
#include "Egida_Object.H"
#include "Security.H"
#include "Stats.H"
#include "Timer.H"

//this is used to define the write blocks for writing
// a checkpoint to file.
#define BUF_SIZE 4096

//static data members of CkptImpl
int CkptImpl::ckptCounter = 0;
char CkptImpl::ckptFileName[EGIDA_FILENAME_LEN];


// keep this variable initialized.  the initialized and the
// uninitialized segments are in 2 different regions.  to identify
// each of those regions, we need one global variable in that
// corresponding region.  for the initialized segment, we use this variable.
static int _initializedGlobal = 10;
static int _unInitializedGlobal;

// This variable stores the file descriptor when the stack is being restored.
static int _restoreFd;

// A large temporary stack for saving/restoring the main stack.
const int _tempStackSize = 10 * SIGSTKSZ;
static char _tempStack[_tempStackSize];

// When the stack is restored, the value on the stack will be
// lost. This variable is used for saving an argument that may be
// needed after the stack is restored.
static int _savedArgs;

static int _lastIncrCtr = -1;
// needed to record the time at which restore was started. used mainly 
// for collecting statistics.
struct timeval _restoreStartTime;

static CkptImpl *_ckptImpl = NULL;





//private funciton that will decide what to hash and sign
void hash(void * buf, size_t nbyte, int segTag) {
  if (HASH_AND_SIGN_CKPT) {
    Security::HashUpdate(buf, nbyte);
  }
  else if (PARTIAL_HASH_AND_SIGN_CKPT) {
    if(segTag == SIGNED_CKPT_SEG) {
      Security::HashUpdate(buf, nbyte);
    }
  }
}


//private write function used to call security functions
int WRITE(int fd, void * buf, size_t nbyte, int segTag, int marker)
{
  int retVal = 0;

  if(ENCRYPT_FULL_CKPTS_ONLY) {
    if(marker == FULL_CKPT_MARKER) {
      retVal = Security::EncryptWrite(fd, buf, nbyte);
    }
    else {
      retVal = write(fd, buf, nbyte);
    }
  }
  else if(TOTAL_CKPT_ENCRYPT) {
    retVal = Security::EncryptWrite(fd, buf, nbyte);
  }
  else if(PARTIAL_CKPT_ENCRYPT){
    if(segTag == PRIVATE_CKPT_SEG) {
      retVal = Security::EncryptWrite(fd, buf, nbyte);
    }
    else {
      retVal = write(fd, buf, nbyte);
    }
  }
  else {
    retVal = write(fd, buf, nbyte);
  }

  hash(buf, nbyte, segTag);
  return(retVal);
}


//private read function used to call security functions
int READ(int fd, void * buf, size_t nbyte, int segTag, int marker)
{
  int retVal = 0;

  if(ENCRYPT_FULL_CKPTS_ONLY) {
    if (marker == FULL_CKPT_MARKER) {
      retVal = Security::DecryptRead(fd, buf, nbyte);
    }
    else {
      retVal = read(fd, buf, nbyte);
    }
  }
  else if(TOTAL_CKPT_ENCRYPT) {
    retVal = Security::DecryptRead(fd, buf, nbyte);
  }
  else if(PARTIAL_CKPT_ENCRYPT){
    if(segTag == PRIVATE_CKPT_SEG) {
      retVal = Security::DecryptRead(fd, buf, nbyte);
    }
    else {
      retVal = read(fd, buf, nbyte);
    }
  }
  else {
    retVal = read(fd, buf, nbyte);
  }
  return(retVal);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Initialize ckptImpl data structures and signal handlers.
// 
// Arguments:
// 	progName --- name of the executable used for running this process
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	The global _ckptImpl gets initialized.
// 
// /////////////////////////////////////////////////////////////////

void CkptImpl::Initialize(int self)
{
  struct sigaction act;
  struct utsname machineName;

  _ckptImpl = this;

  uname(&machineName);
  //set the static ckptFileName prefix for this machine
  sprintf(ckptFileName, "%s/%s.Dir/chkpt.%d", 
	  EGIDA_CKPT_DIR, machineName.nodename, self);

  // mask out the timer signal when we are rolling back
  sigemptyset(&act.sa_mask);
  sigaddset(&act.sa_mask, EGIDA_TIMER_SIGNAL);
  act.sa_flags = SA_RESTART;

  if (sigaction(EGIDA_ROLLBACK_SIGNAL, &act, NULL) < 0) {
    std::cout << "trouble with sigaction for rollback: " << errno << std::endl;
    exit(0);
  }

  // For doing incremental checkpointing, open the PD file.
  if ((this->pageDataFd = open("/proc/self/pagedata", O_RDONLY)) < 0) {
    std::cout << "open of page data failed!: " << errno << std::endl;
    exit(0);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Re-initialize the ckptImpl data structures and signal handlers 
// 	when the process state has been rolled back to a previous checkpoint.
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

void CkptImpl::ReInitialize()
{
  struct sigaction act;

  // mask out the signal when we are reading back a checkpoint
  sigemptyset(&act.sa_mask);
  sigaddset(&act.sa_mask, EGIDA_TIMER_SIGNAL);
  act.sa_flags = SA_RESTART;

  if (sigaction(EGIDA_ROLLBACK_SIGNAL, &act, NULL) < 0) {
    std::cout << "trouble with siaction for read: " << errno << std::endl;
    exit(0);
  }

  // For doing incremental checkpointing, open the PD file.
  if ((this->pageDataFd = open("/proc/self/pagedata", O_RDONLY)) < 0) {
    std::cout << "piocopenpd failed!: " << errno << std::endl;
    exit(0);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	When the process terminates, clean up all the checkpoint files 
// 	that were created.
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

void CkptImpl::Terminate()
{
  char ckptFile[EGIDA_FILENAME_LEN];
  char sigFile[EGIDA_FILENAME_LEN];

  close(this->pageDataFd);
  for (int i = 0; i <= ckptCounter; i++) {
    sprintf(ckptFile, "%s.%d", this->ckptFileName, i);
    unlink(ckptFile);

    if(HASH_AND_SIGN_CKPT || PARTIAL_HASH_AND_SIGN_CKPT) {
      sprintf(sigFile, "%s.hash", ckptFile);
      unlink(sigFile);
    }
  }
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Rollback a process state to a previous checkpoint.
// 
// Arguments:
// 	fileName --- name of the checkpoint file to which the state of 
// 	    the process is rolled back to
//      saveArg --- is an argument that will be passed back to
//          Egida's recovery event handler after the process state is
//          restored to the checkpoint.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	The variable ckptImpl will be restored to the value from the
// 	checkpoint file.
// 
// /////////////////////////////////////////////////////////////////

void CkptImpl::RestoreCkptFile(const char *fileName, int saveArg)
{
  // subtle issue: keep ifd as a stack variable when the data segment
  // and the heap are restored; when the stack has to be restored,
  // store ifd in a global variable.
  int ifd;
  unsigned int cookie;
  unsigned long base, size;

  //figure out if it's a full or incremental checkpoint to 
  // be restored
  if ((ifd = open(fileName, O_RDONLY, S_IRUSR, S_IWUSR)) < 0) {
    std::cout << "Unable to open file:" << fileName << std::endl;
    exit(0);
  }

  READ(ifd, &cookie, sizeof(unsigned int), SEGMENT_TAG, BOTH_CKPT_MARKER);

  close(ifd);

  if (cookie == EGIDA_CKPT_FULL_MAGIC_COOKIE) {
    FullCkpt fullCkpt;
    fullCkpt.RestoreCkpt(fileName, saveArg);
  }
  else if (cookie == EGIDA_CKPT_INCR_MAGIC_COOKIE) {
    IncrCkpt incrCkpt;
    incrCkpt.RestoreCkpt(fileName, saveArg);
  }
  else {
    std::cout << "Found unknown checkpoint type!" << std::endl;
    exit(0);
  }
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Restoring stack is a bit tricky and is done using a signal
// 	handler.  The process installs an alternate stack on which the 
// 	signal handler should run and in the handler, the main stack
// 	is read back from the checkpoint.  If we don't do this way,
// 	then, modifying a stack while the process is running is sure
// 	to cause a core-dump.
// 
// Arguments:
// 	NONE
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	Process stack is restored using the checkpoint.
// 
// /////////////////////////////////////////////////////////////////

void CkptImpl::RestoreStackPreamble()
{
  stack_t signalStack;
  struct sigaction act;
  sigset_t blockedSet;

  // unblock sigusr2
  sigemptyset(&blockedSet);
  sigaddset(&blockedSet, EGIDA_READ_STACK_SIGNAL);
  sigprocmask(SIG_UNBLOCK, &blockedSet, NULL);

  // This is the temporary stack
  signalStack.ss_flags = 0;
  signalStack.ss_size = _tempStackSize;
  signalStack.ss_sp = _tempStack;
  // install the stack.
  this->altStack.ss_sp = signalStack.ss_sp;
  this->altStack.ss_size = signalStack.ss_size;
  
  if (sigaltstack(&signalStack, (stack_t *) NULL) < 0) {
    std::cout << "error installing signal stack: " << errno << std::endl;
    exit(0);
  }
  // install a signal handler
  act.sa_handler = RestoreStack;
  sigemptyset(&act.sa_mask);
  act.sa_flags = SA_ONSTACK;
  if (sigaction(EGIDA_READ_STACK_SIGNAL, &act, NULL) < 0) {
    std::cout << "error in sig action: " << errno << std::endl;
    exit(0);
  }
  // send the signal
  if (sigsend(P_PID, P_MYID, EGIDA_READ_STACK_SIGNAL) < 0) {
    std::cout << "trouble sending signal usr2: " << errno << std::endl;
    exit(0);
  }
  while (1)
    // we are never coming back here
    sigpause(0);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Signal handler that restores the process stack.
// 
// Arguments:
// 	code --- is the signal # that was passed to this function
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	Stack is restored from the checkpoint
// 
// /////////////////////////////////////////////////////////////////

void RestoreStack(int code)
{
  _ckptImpl->RestoreStackSegment(_restoreFd);
  std::cout << "restore stack is done... jumping back..." << std::endl;
  _ckptImpl->JumpBack();
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Read the /proc/self/{map, status} files and determine where
// 	the stack, heap, and global data segments of a process are located.
// 
// Arguments:
// 	result: Output parameter for obtaining the prmap information
//      numSegs: Output parameter
// 
// Results:
// 	result: A buffer that contains the mapping information.  It is 
// 	    dynamically allocated inside this function and has to be freed 
// 	    by the caller.
// 	numSegs: Contains the number of segments in the address space
// 	    of this process.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void CkptImpl::IdentifySegs(prmap_t **result, int *numSegs)
{
  struct stat statBuf;
  int procFileFd, i;
  prmap_t *memMap;
  pstatus_t processInfo;

  // For the layout of /proc/self/map, lookup: man -s4 proc
  // first get the address map
  procFileFd = open("/proc/self/map", O_RDONLY);
  fstat(procFileFd, &statBuf);
  // need to make sure statBuf.st_size is evenly divisible by
  // sizeof(prmap_t) or we add on another element for the partial
  // map.
  if((statBuf.st_size % sizeof(prmap_t)) == 0) {
    //it's already "aligned"
    *numSegs = (statBuf.st_size / sizeof(prmap_t));
  }
  else {
    //we need to accomodate the partial page
    *numSegs = (statBuf.st_size / sizeof(prmap_t)) + 1;
  }
  memMap = new prmap_t [*numSegs];  
  // get the mappings.
  read(procFileFd, memMap, statBuf.st_size);
  close(procFileFd);

  // figure out the process stack/heap
  procFileFd = open("/proc/self/status", O_RDONLY);
  read(procFileFd, &processInfo, sizeof(pstatus_t));
  close(procFileFd);

  this->heapBase = (unsigned long) processInfo.pr_brkbase;
  this->heapSize = processInfo.pr_brksize;
  this->stackBase = (unsigned long) processInfo.pr_stkbase;
  this->stackSize = processInfo.pr_stksize;
  
  // Figure out where the initialized global area begins.  The process 
  // state is set as: <exec> <init globals> <un-init globals> <heap>
  for (i = 0; i < *numSegs; i++) {
    if (((unsigned long) memMap[i].pr_vaddr <= (unsigned long) &_initializedGlobal) &&
	((unsigned long) &_initializedGlobal <= (unsigned long) memMap[i].pr_vaddr +
	 memMap[i].pr_size)) {
      // we are assuming one big data segment.
      this->dataBase = (unsigned long) memMap[i].pr_vaddr;
      this->dataSize = memMap[i].pr_size;
      //std::cout << "Init globals: " << this->dataBase << ' ' << this->dataSize << std::endl;

      //this is a total hack, but sometimes mriga (of course) is getting 
      //  two data segments of which the second one is incorrect.
      break;
    }
  }
  *result = memMap;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Given a virtual address, returns the segment (stack, heap, or
// 	global data area) in which the address lives.
// 
// Arguments:
// 	vaddr: address that has to be classified
//      segSize: size of the segment in which vaddr is located
// 
// Results:
// 	segmentType: will be set depending on the segment in which
// 	    vaddr lives.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void CkptImpl::ClassifySegment(unsigned long vaddr, 
			       int segSize,
			       int *segmentType) const
{
  *segmentType = 0;

  if (((this->heapBase <= vaddr) && (vaddr < this->heapBase +
				    this->heapSize)) ||
      ((vaddr <= this->heapBase) && (this->heapBase < vaddr + segSize)))
    *segmentType = EGIDA_HEAP_SEG;

  // this is for the initialized static stuff
  if (((this->dataBase <= vaddr) && (vaddr < this->dataBase +
				     this->dataSize)) ||
      ((vaddr <= this->dataBase) && (this->dataBase < vaddr +
				     segSize))) {
    if (!(*segmentType & EGIDA_HEAP_SEG))
      // don't mix up heap and data segments...
      *segmentType = *segmentType | EGIDA_DATA_SEG;
  }

  // this is for the uninitialized segment
  if ((vaddr <= (unsigned long) &_unInitializedGlobal) && 
      ((unsigned long) &_unInitializedGlobal < vaddr + segSize)) {
    if (!(*segmentType & EGIDA_HEAP_SEG))
      // don't mix up heap and data segments...
      *segmentType = *segmentType | EGIDA_DATA_SEG;
  }

  if (((this->stackBase <= vaddr) && (vaddr < this->stackBase +
				     this->stackSize)) ||
      ((vaddr <= this->stackBase) && (this->stackBase < vaddr + segSize)))
    *segmentType = *segmentType | EGIDA_STACK_SEG;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Align a file pointer to a page boundary.
// 
// Arguments:
// 	fd: file pointer that has to be suitably aligned.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void CkptImpl::SeekToPageBoundary(int fd)
{
  int offset, toAlign;
  long pageSize = sysconf(_SC_PAGESIZE);

  offset = lseek(fd, 0, SEEK_CUR);
  // This is how much the fd needs to be shifted by
  toAlign = pageSize - (offset % pageSize);
  if (offset % pageSize)
    lseek(fd, toAlign, SEEK_CUR);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Setup the file descriptor to which the checkpoint has to be
// 	written to.
// 
// Arguments:
// 	ofd --- output parameter that corresponds to file descriptor
// 	     to which the checkpoint has to be written.
//      resultFileName --- output parameter that contains the name of
//           the file to which the checkpoint has to be written. 
//
// Results:
// 	ofd --- file descriptor to which the checkpoint has to be
// 	   written to.
//      resultFileName --- will be set to the name of the file to
//         which the checkpoint has to be written.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void CkptImpl::SetupCkpt(int *ofd, char *resultFileName)
{
  ckptCounter++;
  sprintf(resultFileName, "%s.%d", this->ckptFileName, ckptCounter);
  if ((*ofd = open(resultFileName, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR)) < 0) {
    std::cout << "Unable to open file:" << resultFileName 
	      << ' ' << errno << std::endl;
    _exit(0);
  }
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Save the process state in a full checkpoint.
// 
// Arguments:
// 	ofd --- fd to which the checkpoint has to be written out.
// 
// Results:
//      Returns 0 if a checkpoint has to be written; 
//              1 if the process state is restored from a checkpoint. 
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

int FullCkpt::TakeCkpt(int ofd)
{
  stack_t signalStack;
  struct timeval endTime, startTime;
  double timeSpent;

  if(COLLECTING_STATS) {
    gettimeofday(&startTime, NULL);
  }

  // Record the pc, stack pointer, and other registers.  If sigsetjmp
  // returns 0, then, it means that the env variables have been saved.
  if (sigsetjmp(this->env, 0) != 0) { 
    std::cout << "Full's jump back is done..." << std::endl;
    // If control enters here, then, it is because of a longjmp
    // disable the temporary stack
    signalStack.ss_flags = SS_DISABLE;
    if (sigaltstack(&signalStack, (stack_t *) NULL) < 0) {
      std::cout << "error disabling alt stack: " << errno << std::endl;
      _exit(0);
    }
    if(COLLECTING_STATS) {
      gettimeofday(&endTime, NULL);
      Timer::ComputeTimeDiff(&timeSpent, _restoreStartTime, endTime);
      Stats::Update(EGIDA_RECOVERY_STATE_RESTORE_STAT, 0, timeSpent);
    }
    std::cout << "Full's State Restore: " << timeSpent << std::endl;
    std::cout.flush();
    
    if (this != _ckptImpl) 
      return 1;

    ReInitialize();
    Egida::RestoreDone(_savedArgs);
    return 1;
  }
  else {
    if (this != _ckptImpl) {
      // Make a copy of the siglongjmp_buf
      // This method may be called from 
      // an Incremental checkpoint (the first checkpoint there is a
      // full checkpoint.  During recovery, siglongjmp uses the info
      // present in _ckptImpl->env.  That better be what is primed
      // above; otherwise, chaos is guaranteed
      _ckptImpl->SetLongJmpBuf(this->env);
    }

    if(HASH_AND_SIGN_CKPT || PARTIAL_HASH_AND_SIGN_CKPT) {
      Security::HashInit();

      WriteCkpt(ofd);

      char sigFile[EGIDA_FILENAME_LEN];
      sprintf(sigFile, "%s.%d.hash", this->ckptFileName, this->ckptCounter);
      Security::SignAndRecordHash(sigFile); //this does the HashFinal()
    }
    else {
      WriteCkpt(ofd);
    }

    fsync(ofd);
    close(ofd);

    if(COLLECTING_STATS) {
      gettimeofday(&endTime, NULL);
      Timer::ComputeTimeDiff(&timeSpent, startTime, endTime);
      Stats::Update(EGIDA_FULL_CKPT_STAT, 0, timeSpent);
    }

    return 0;
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Writes out a full checkpoint to a file.
// 
// Arguments:
// 	ofd: File descriptor to which the checkpoint has to be written 
// 	   to.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void FullCkpt::WriteCkpt(int ofd)
{
  int numSegs, segType, i;
  unsigned char buf[BUF_SIZE];
  unsigned long long offset, bytesToGo;
  prmap_t *memMap;

  // This call determines where the base and size of the stack, heap, 
  // and global data area segments are located.
  this->IdentifySegs(&memMap, &numSegs);

  // This is the header for the checkpoint file
  i = EGIDA_CKPT_FULL_MAGIC_COOKIE;
  WRITE(ofd, &i, sizeof(unsigned int), SEGMENT_TAG, BOTH_CKPT_MARKER);
  WRITE(ofd, &(this->heapBase), sizeof(unsigned long), EGIDA_HEAP_SEG, BOTH_CKPT_MARKER);
  WRITE(ofd, &(this->heapSize), sizeof(unsigned long), EGIDA_HEAP_SEG, BOTH_CKPT_MARKER);

  SeekToPageBoundary(ofd);

  // In Solaris, stack, heap, and global data area are 3 different
  // segments.  Write those regions to the file.
  for (i = 0; i < numSegs; i++) {
    this->ClassifySegment((unsigned long) memMap[i].pr_vaddr,
			  memMap[i].pr_size,
			  &segType);

    if ((segType == 0) || (memMap[i].pr_size == 0))
      continue;

    WRITE(ofd, &segType, sizeof(int), SEGMENT_TAG, FULL_CKPT_MARKER);
    WRITE(ofd, &memMap[i], sizeof(prmap_t), segType, FULL_CKPT_MARKER);
    // align it at a page boundary
    SeekToPageBoundary(ofd);

    //memory changes between write and hash calls so capture memory dump first
    offset = memMap[i].pr_vaddr;
    bytesToGo = memMap[i].pr_size;

    while (1) {
      if(bytesToGo > BUF_SIZE) {
	memcpy(buf, (void *) offset, BUF_SIZE);
	WRITE(ofd, buf, BUF_SIZE, segType, FULL_CKPT_MARKER);
	offset += BUF_SIZE;
	bytesToGo -= BUF_SIZE;
      }
      else{
	if(bytesToGo > 0) {
	  memcpy(buf, (void *) offset, bytesToGo);
	  WRITE(ofd, buf, bytesToGo, segType, FULL_CKPT_MARKER);
	}
	break;
      }
    }

    SeekToPageBoundary(ofd);
  }
  delete [] memMap;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Restore a process state from a full checkpoint.
// 
// Arguments:
//      fileName --- file from which to restore the checkpoint
//      saveArg --- is an argument that has to be handed back to the
//         Event handler module after the process state is restored from
//         the checkpoint.
// Results:
// 	NONE
// 
// Side Effects:
// 	Global variables are restored from the checkpoint.
// 
// /////////////////////////////////////////////////////////////////

void FullCkpt::RestoreCkpt(const char *fileName, int saveArg)
{
  int ifd, cookie;
  struct timeval startTime;

  if(COLLECTING_STATS) {
    gettimeofday(&startTime, NULL);
  }
  
  if(HASH_AND_SIGN_CKPT || PARTIAL_HASH_AND_SIGN_CKPT) {
    char sigFile[EGIDA_FILENAME_LEN];
    sprintf(sigFile, "%s.hash", fileName);

    bool match = Security::ReadAndVerifySignature((char *)fileName, true, sigFile);

    if(match){
      std::cout << "Ckpt file uncorrupted...continue roll forward" << std::endl;
    } 
    else {
      std::cout << "Ckpt file CORRUPTED! Aborting roll forward" << std::endl;
      //exit(0);
    }
  }

  //we know the file can be opened since we had to read the cookie info
  // in the restore ckpt file routine before this.
  ifd = open(fileName, O_RDONLY, S_IRUSR, S_IWUSR);
  
  RestoreHeapDataSegs(ifd);
  // the variable startTime is on stack; _restoreStartTime is in the
  // global data area.  Since, we have restored the global segment, at 
  // this point, it is safe to copy over the startTime value to the
  // global variable.
  if(COLLECTING_STATS) {
    memcpy(&_restoreStartTime, &startTime, sizeof(struct timeval));
  }

  // The stack is going to be restored next.
  _restoreFd = ifd;
  _savedArgs = saveArg;
  //  std::cout << "about to restore stack..." << std::endl;
  _ckptImpl->RestoreStackPreamble();
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Restore the heap and data segments from a full checkpoint.
// 
// Arguments:
// 	ifd --- file from which the heap/data segments have to be restored
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void FullCkpt::RestoreHeapDataSegs(int ifd)
{
  unsigned long base, size;
  int cookie;
  long pageSize = sysconf(_SC_PAGESIZE);
  int procFileFd;
  pstatus_t processInfo;

  // figure out the process heap size
  procFileFd = open("/proc/self/status", O_RDONLY);
  read(procFileFd, &processInfo, sizeof(pstatus_t));
  close(procFileFd);


  lseek(ifd, 0, SEEK_SET);
  // the cookie info. has already been read in...
  READ(ifd, (char *) &cookie, sizeof(unsigned int), SEGMENT_TAG, BOTH_CKPT_MARKER);
  // here is the heap---we need to grow the heap here
  READ(ifd, (char *) &base, sizeof(unsigned long), EGIDA_HEAP_SEG, BOTH_CKPT_MARKER);
  READ(ifd, (char *) &size, sizeof(unsigned long), EGIDA_HEAP_SEG, BOTH_CKPT_MARKER);

  SeekToPageBoundary(ifd);
  
  // add some space at the end for reading page info...
  size = ((size / pageSize) + 10) * pageSize;


  // We grow the heap when we need to...
  // otherwise we shrink the heap by the appropriate amount.
  if (processInfo.pr_brksize < size) {
    std::cout << "Growing the heap by : " << 
      (size - processInfo.pr_brksize) << std::endl;
    if (sbrk((size - processInfo.pr_brksize) * sizeof(char)) == NULL) {
      std::cout << "trouble with sbrk:" << errno << std::endl;
      exit(0);
    }
  }
  else {
    //processInfo.pr_brksize is an unsigned long so need to put it
    // in a signed long first. Then figure out the size to shrink by
    long shrinkSize = processInfo.pr_brksize;
    shrinkSize = size - shrinkSize;
    std::cout << "Shrank the heap by : " << shrinkSize
	      << std::endl;
    
    sbrk(shrinkSize * sizeof(char));
  }

  // Order here is critical.  this will point to some junk stuff after 
  // the heap is restored.  Instead, use _ckptImpl which has been
  // restored from the checkpoint file.
  RestoreSegment(ifd, EGIDA_HEAP_SEG);
  RestoreSegment(ifd, EGIDA_DATA_SEG);
  // The heap size is what we allocated above.
  _ckptImpl->SetHeapSize(size);
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	This is a virtual function---in the case of FullCkpt, it is
// 	just a front-end for calling restore segment
// 
// Arguments:
// 	ifd --- file from which the stack has to be read back
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	Restores the stack
// 
// /////////////////////////////////////////////////////////////////

void FullCkpt::RestoreStackSegment(int ifd)
{
  RestoreSegment(ifd, EGIDA_STACK_SEG);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Restore a segment from a full checkpoint.
// Caution: Inside the method, DON'T USE variables stored in the
// segment that is being restored.  This is because when the segment
// is restored, those variables WILL get corrupted.
// 
// Arguments:
// 	ifd --- a stack variable that stores the file descriptor of
// 	    the checkpoint file to which the process state is rolled back to.
//      segType --- is one of HEAP, DATA, STACK
//
// Results:
// 	NONE
// 
// Side Effects:
// 	Global variables are set to the value stored in the checkpoint 
// 	file.
// 
// /////////////////////////////////////////////////////////////////
void FullCkpt::RestoreSegment(int ifd, int segType)
{
  unsigned int segmentType;
  prmap_t memMap;
  unsigned long base, size;

  lseek(ifd, sysconf(_SC_PAGESIZE), SEEK_SET);
  // Read the segment from the file.
  while (1) {
    if (READ(ifd, &segmentType, sizeof(int), SEGMENT_TAG, FULL_CKPT_MARKER) != sizeof(int))
      break;
    if (READ(ifd, &memMap, sizeof(prmap_t), segmentType, FULL_CKPT_MARKER) != sizeof(prmap_t))
      break;
    SeekToPageBoundary(ifd);
    // Skip past the segments that don't match what is asked for.
    if ((segmentType & segType) == 0) {
      lseek(ifd, memMap.pr_size, SEEK_CUR);
      continue;
    }

    //need to read in the same way we wrote out (esp for encryption/decryption)
    unsigned long offset = 0;
    long bytesToGo = memMap.pr_size;

    while (1) {
      if(bytesToGo > BUF_SIZE) {
	READ(ifd, (void *) (memMap.pr_vaddr + offset), BUF_SIZE, segmentType, FULL_CKPT_MARKER);
	offset += BUF_SIZE;
	bytesToGo -= BUF_SIZE;
      }
      else{
	if(bytesToGo > 0) {
	  READ(ifd, (void *) (memMap.pr_vaddr + offset), bytesToGo, segmentType, FULL_CKPT_MARKER);
	}
	break;
      }
    }

    SeekToPageBoundary(ifd);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Save the process state in an incremental checkpoint.
// 
// Arguments:
// 	ofd --- fd to which the checkpoint has to be written out.
// 
// Results:
//      Returns 0 if a checkpoint has to be written; 
//              1 if the process state is restored from a checkpoint. 
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

int IncrCkpt::TakeCkpt(int ofd)
{
  stack_t signalStack;
  struct timeval endTime, startTime;
  double timeSpent;
  FullCkpt fullCkpt;

  if(COLLECTING_STATS) {
    gettimeofday(&startTime, NULL);
  }

  // Record the pc, stack pointer, and other registers.  If sigsetjmp
  // returns 0, then, it means that the env variables have been saved.
  if (sigsetjmp(this->env, 0) != 0) { 
    std::cout << "Incr's jump back is done..." << std::endl;
    // If control enters here, then, it is because of a longjmp
    // disable the temporary stack
    signalStack.ss_flags = SS_DISABLE;
    if (sigaltstack(&signalStack, (stack_t *) NULL) < 0) {
      std::cout << "error disabling alt stack: " << errno << std::endl;
      _exit(0);
    }

    if(COLLECTING_STATS) {
      gettimeofday(&endTime, NULL);
      Timer::ComputeTimeDiff(&timeSpent, _restoreStartTime, endTime);
      Stats::Update(EGIDA_RECOVERY_STATE_RESTORE_STAT, 0, timeSpent);
      std::cout << "Incr's State Restore: " << timeSpent << std::endl;
      std::cout.flush();
    }

    ReInitialize();
    Egida::RestoreDone(_savedArgs);
    return 1;
  }
  else {
    if (ckptCounter == 1) {
      if (fullCkpt.TakeCkpt(ofd) == 1) {
	// this means that the process was restored using the full
	// checkpoint. 
	std::cout << "Incr's after full calling restore done" << std::endl;
	ReInitialize();
	Egida::RestoreDone(_savedArgs);
	return 1;
      }
    }
    else {
      if(HASH_AND_SIGN_CKPT || PARTIAL_HASH_AND_SIGN_CKPT) {
	Security::HashInit();
	this->WriteCkpt(ofd);
	char sigFile[EGIDA_FILENAME_LEN];
	sprintf(sigFile, "%s.%d.hash", this->ckptFileName, ckptCounter);
	Security::SignAndRecordHash(sigFile);
      }
      else{
	this->WriteCkpt(ofd);
      }
    }
    fsync(ofd);
    close(ofd);

    if(COLLECTING_STATS) {
      gettimeofday(&endTime, NULL);
      Timer::ComputeTimeDiff(&timeSpent, startTime, endTime);
      Stats::Update(EGIDA_INCR_CKPT_STAT, 0, timeSpent);
    }
    return 0;
  }
}

// /////////////////////////////////////////////////////////////////
//
// Purpose:
// 	Writes out an incremental checkpoint to a file.
// 
// Arguments:
// 	ofd: File descriptor to which the checkpoint has to be written 
// 	   to.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void IncrCkpt::WriteCkpt(int ofd)
{
  prpageheader_t pageHeader;
  prasmap_t pageMap;
  int map;
  int i, rval, page, numPages, segmentType;
  int startPage, numPagesInSequence;
  int totalPagesWritten = 0;
  unsigned char *pageInfo, *pageInfoStart;
  struct stat statBuffer;
  prmap_t *memMap;
  int numSegs;
  unsigned long long bytesToGo, offset;
  unsigned char buf[BUF_SIZE];

  // This call determines where the base and size of the stack, heap, 
  // and global data area segments are located.
  this->IdentifySegs(&memMap, &numSegs);
  delete [] memMap;

  // This is the header for the checkpoint file
  i = EGIDA_CKPT_INCR_MAGIC_COOKIE;
  WRITE(ofd, &i, sizeof(unsigned int), SEGMENT_TAG, BOTH_CKPT_MARKER);
  WRITE(ofd, &this->heapBase, sizeof(unsigned long), EGIDA_HEAP_SEG, BOTH_CKPT_MARKER);
  WRITE(ofd, &this->heapSize, sizeof(unsigned long), EGIDA_HEAP_SEG, BOTH_CKPT_MARKER);
  SeekToPageBoundary(ofd);
  
  // Get information about all the pages in a process address space.
  while (1) {
    // do an fstat to figure out the size
    if (fstat(this->pageDataFd, &statBuffer) != 0) {
      std::cout << "fstat failed: " << errno << std::endl;
      exit(0);
    }

    pageInfo = new unsigned char [statBuffer.st_size];
    numPages = statBuffer.st_size;
    
    // CRITICAL POINT: Since we just did a new, see if anything changed.
    // do an fstat again to figure out the size
    if (fstat(this->pageDataFd, &statBuffer) != 0) {
      std::cout << "fstat failed: " << errno << std::endl;
      exit(0);
    }
    if (statBuffer.st_size == numPages)
      break;
    else
      delete [] pageInfo;
  }

  if ((rval = read(this->pageDataFd, pageInfo, statBuffer.st_size)) !=
      statBuffer.st_size) {
    std::cout << "rval: " << rval << " read on page data fd failed!: ";
    std::cout << errno << std::endl;
    exit(0);
  }
  // Keep a pointer to the start of the buffer, so that it can be
  // handed back to delete.  This method updates pageInfo (see below)
  pageInfoStart = pageInfo;

  // read the page header
  memcpy(&pageHeader, pageInfo, sizeof(prpageheader_t));
  pageInfo += sizeof(prpageheader_t);

  // format: <asmap> <per page info>
  for (map = 0; map < pageHeader.pr_nmap; map++) {
    // read the pr asmap
    memcpy(&pageMap, pageInfo, sizeof(prasmap_t));
    pageInfo += sizeof(prasmap_t);
    this->ClassifySegment((unsigned long) pageMap.pr_vaddr,
			  pageMap.pr_npage * pageMap.pr_pagesize,
			  &segmentType);
    if (segmentType) {
      // This is a segment that has to be saved.  Save only the
      // modified pages
      for (numPages = page = 0; page < pageMap.pr_npage; page++) 
	if (pageInfo[page] & PG_MODIFIED)
	  numPages++;

      // write all the information about this segment
      WRITE(ofd, &segmentType, sizeof(int), SEGMENT_TAG, INCR_CKPT_MARKER);
      WRITE(ofd, &pageMap, sizeof(prasmap_t), segmentType, INCR_CKPT_MARKER);
      // this many modified pages
      WRITE(ofd, &numPages, sizeof(int), segmentType, INCR_CKPT_MARKER);
      WRITE(ofd, pageInfo, pageMap.pr_npage, segmentType, INCR_CKPT_MARKER);
      SeekToPageBoundary(ofd);

      page = 0;
      startPage = -1;
      numPagesInSequence = 0;

      // batch the modified pages and write them out
      while (page < pageMap.pr_npage) {
	if (pageInfo[page] & PG_MODIFIED) {
	  numPagesInSequence++;

	  if (startPage < 0)
	    startPage = page;
        }
	// Write out pages if:
	//   # of modified pages exceeds 250 (1MB in size)
	//   pageInfo[page] is the first unmodified page and there are
	//     modified pages that haven't yet been written out
	//
	if ((numPagesInSequence > 250) ||
	    ((!(pageInfo[page] & PG_MODIFIED)) && (numPagesInSequence > 0))) {

	  //memory changes between write and hash so capture it first.
	  offset = pageMap.pr_vaddr + (startPage * pageMap.pr_pagesize);
	  bytesToGo = numPagesInSequence * pageMap.pr_pagesize;
	  
	  while (1) {
	    if(bytesToGo > BUF_SIZE) {
	      memcpy(buf, (void *) offset, BUF_SIZE);
	      WRITE(ofd, buf, BUF_SIZE, segmentType, INCR_CKPT_MARKER);
	      offset += BUF_SIZE;
	      bytesToGo -= BUF_SIZE;
	    }
	    else {
	      if(bytesToGo > 0) {
	  	memcpy(buf, (void *) offset, bytesToGo);
	  	WRITE(ofd, buf, bytesToGo, segmentType, INCR_CKPT_MARKER);
	      }
	      break;
	    }
	   }

	  totalPagesWritten += numPagesInSequence;
	  numPagesInSequence = 0;
	  startPage = -1;
	  // pause for a sec.
	  fsync(ofd);
	}
	page++;
      }
      // Done with the while loop;  write out the remaining pages
      if (numPagesInSequence > 0) {
	totalPagesWritten += numPagesInSequence;

	//memory changes between write and hash so capture it first.
	offset = pageMap.pr_vaddr + (startPage * pageMap.pr_pagesize);
	bytesToGo = numPagesInSequence * pageMap.pr_pagesize;
	
	while (1) {
	  if(bytesToGo > BUF_SIZE) {
	    memcpy(buf, (void *) offset, BUF_SIZE);
	    WRITE(ofd, buf, BUF_SIZE, segmentType, INCR_CKPT_MARKER);
	    offset += BUF_SIZE;
	    bytesToGo -= BUF_SIZE;
	  }
	  else {
	    if(bytesToGo > 0) {
	      memcpy(buf, (void *) offset, bytesToGo);
	      WRITE(ofd, buf, bytesToGo, segmentType, INCR_CKPT_MARKER);
	    }
	    break;
	  }
	}
      }
    }
    // This piece is solaris 2.7 & 2.8 specific.  The information about the
    // modified pages is aligned at 8-byte boundaries.  Hence, update
    // the buffer pointer to point to the next set of modified pages.
    pageInfo += pageMap.pr_npage;
    if (((long) pageInfo) % 8)
      pageInfo += (8 - (((long) pageInfo) % 8));
  }
  delete [] pageInfoStart;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Restore state from an incremental checkpoint
// 
// Arguments:
// 	ifd --- file descriptor of the checkpoint file.
//      saveArg --- is an argument that has to be handed back to the
//         Event handler module after the process state is restored from
//         the checkpoint.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	Global variables are restored from the checkpoint.
// 
// /////////////////////////////////////////////////////////////////

void IncrCkpt::RestoreCkpt(const char *fileName, int saveArg)
{
  char lastIncrFile[EGIDA_FILENAME_LEN];
  char baseName[EGIDA_FILENAME_LEN], *p;
  char prefix[EGIDA_FILENAME_LEN], *q;
  char masterCkptFile[EGIDA_FILENAME_LEN];
  char incrCkptFile[EGIDA_FILENAME_LEN];
  char sigFile[EGIDA_FILENAME_LEN];
  FullCkpt fullCkpt;
  IncrCkpt tempCkptImpl;
  int cookie, ifd, incrFd;
  unsigned long base, size;
  unsigned long currentHeapSize;
  struct timeval startTime;
  int i, j, lastIncr = -1;
  long pageSize = sysconf(_SC_PAGESIZE);


  if(COLLECTING_STATS) {
    gettimeofday(&startTime, NULL);
  }

  strcpy(baseName, fileName);
  // The variable fileName may be on the heap.  That is trouble coz we 
  // are restoring the heap and the value will disappear
  strcpy(lastIncrFile, fileName);
  // checkpoint files have the format: <baseName>.<procId>.<#>  Given
  // this format, the process state has to be first restored using
  // <baseName>.<procId>.1 which is the "master checkpoint" file
  // followed by the incremental ones.  So, create the master name
  p = rindex(baseName, '.');
  assert(p != NULL);
  *p = '\0';  // truncate baseName at the last "."
  sprintf(masterCkptFile, "%s.1", baseName);

  //need to check that the masterCkptFile is uncorrupted
  if(HASH_AND_SIGN_CKPT || PARTIAL_HASH_AND_SIGN_CKPT) {
    sprintf(sigFile, "%s.hash", masterCkptFile);

    bool match = Security::ReadAndVerifySignature(masterCkptFile, true, sigFile);

    if(match){
      std::cout << "Master file uncorrupted...continue roll forward" 
		<< std::endl;
    }
    else {
      std::cout << "Master file CORRUPTED! Abort roll forward" 
		<< std::endl;
      //exit(0);
    } 
  } 

  if ((ifd = open(masterCkptFile, O_RDONLY, S_IRUSR | S_IWUSR)) < 0) {
    std::cout << "Unable to open master file:" << masterCkptFile << std::endl;
    assert(0);
    exit(0);
  }

  fullCkpt.RestoreHeapDataSegs(ifd);
  lastIncr = -1;
  for (i = 2; lastIncr <= 0; i++) {
    sprintf(incrCkptFile, "%s.%d", baseName, i);
    std::cout << "opening incrCkpt: " << incrCkptFile << std::endl;
    if (strcmp(incrCkptFile, lastIncrFile) == 0) {
      std::cout << "last increment: " << i << std::endl;
      lastIncr = i;
    }

    //need to check that the incremental checkpoint files are uncorrupted
    if(HASH_AND_SIGN_CKPT || PARTIAL_HASH_AND_SIGN_CKPT) {
      sprintf(sigFile, "%s.hash", incrCkptFile);
      
      bool match = Security::ReadAndVerifySignature(incrCkptFile, false, sigFile);
      
      if(match){
	std::cout << "Incr file uncorrupted...continue roll forward" 
		  << std::endl;
      } 
      else {
	std::cout << "Incr file CORRUPTED! Abort roll forward" 
		  << std::endl;
	//exit(0);
      } 
    } 

    if ((incrFd = open(incrCkptFile, O_RDONLY, S_IRUSR | S_IWUSR)) < 0) {
      std::cout << "Unable to open incr file:" << incrCkptFile << std::endl;
      assert(0);
      exit(0);
    }

    //we need to read over the cookie 
    READ(incrFd, (char *) &cookie, sizeof(unsigned int), SEGMENT_TAG, BOTH_CKPT_MARKER);
    // here is the heap info
    READ(incrFd, (char *) &base, sizeof(unsigned long), EGIDA_HEAP_SEG, BOTH_CKPT_MARKER);
    READ(incrFd, (char *) &size, sizeof(unsigned long), EGIDA_HEAP_SEG, BOTH_CKPT_MARKER);

    //add some space for reading in page info
    size = ((size / pageSize) + 10) * pageSize;

    //find out the current heap size to 
    currentHeapSize = _ckptImpl->GetHeapSize();

    //check to see if we need to adjust the heap 
    // We only grow the heap when we need to...
    // otherwise we shrink the heap by the appropriate amount.
    if (currentHeapSize < size) {
      std::cout << "Growing the heap by : " << 
	(size - currentHeapSize) << std::endl;
      if (sbrk((size - currentHeapSize) * sizeof(char)) == NULL) {
	std::cout << "trouble with sbrk:" << errno << std::endl;
	exit(0);
      }
    }
    else {
      //currentHeapSize is an unsigned long so need to put it
      // in a signed long first. Then figure out the size to shrink by
      long shrinkSize = currentHeapSize;
      shrinkSize = size - shrinkSize;
      std::cout << "Shrank the heap by : " << shrinkSize
		<< std::endl;
      
      sbrk(shrinkSize * sizeof(char));
    }

    //now that the heap is the correct size, we restore the parts
    tempCkptImpl.RestoreSegment(incrFd, EGIDA_HEAP_SEG);
    tempCkptImpl.RestoreSegment(incrFd, EGIDA_DATA_SEG);

    // This is a heap variable.  Set it after everything is restored
    _ckptImpl->SetHeapSize(size);    
    close(incrFd);
  }
  // the variable startTime is on stack; _restoreStartTime is in the
  // global data area.  Since, we have restored the global segment, at 
  // this point, it is safe to copy over the startTime value to the
  // global variable.
  if(COLLECTING_STATS) {
    memcpy(&_restoreStartTime, &startTime, sizeof(struct timeval));
  }

  _lastIncrCtr = lastIncr;
  _restoreFd = ifd;
  _ckptImpl->RestoreStackPreamble();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Restore a segment from an incremental checkpoint.
// Caution: Inside the method, DON'T USE variables stored in the
// segment that is being restored.  This is because when the segment
// is restored, those variables WILL get corrupted.
// 
// Arguments:
// 	ifd --- a stack variable that stores the file descriptor of
// 	    the checkpoint file to which the process state is rolled back to.
//      segType --- is one of HEAP, DATA, STACK
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	Global values are set from the checkpoint file
// 
// /////////////////////////////////////////////////////////////////
void IncrCkpt::RestoreSegment(int ifd, int segType)
{
  prasmap_t pageMap;
  unsigned char pageStatusInfo[8192];
  int pageStatusInfoBufSize = 8192;
  int segmentType;
  int i, j, rval, numRead, numPages, totalRead;
  int startPage = -1, numInSeq = 0;
  int lastPageInfoReadPos, currentPos;
  
  lseek(ifd, sysconf(_SC_PAGESIZE), SEEK_SET);
  while (1) {
    // for the format of the segment header information---look in
    // WriteCkpt method of IncrCkpt object.
    if (READ(ifd, &segmentType, sizeof(int), SEGMENT_TAG, INCR_CKPT_MARKER) != sizeof(int))
      break;
    if (READ(ifd, &pageMap, sizeof(prasmap_t), segmentType, INCR_CKPT_MARKER) != sizeof(prasmap_t))
      break;
    if (READ(ifd, &numPages, sizeof(int), segmentType, INCR_CKPT_MARKER) != sizeof(int))
      break;
    // Skip past the segments that don't match what is asked for.
    if ((segmentType & segType) == 0) {
      // skip the information about what pages have been modified.
      lseek(ifd, pageMap.pr_npage, SEEK_CUR);
      SeekToPageBoundary(ifd);
      lseek(ifd, numPages * pageMap.pr_pagesize, SEEK_CUR);
      continue;
    }
    // Since the size of the pageStatusInfo buffer is dynamic, can't
    // allocate it on the heap: we get core-dumps.  So, allocate it on 
    // the stack and read accordingly.

    // figure out the position
    lastPageInfoReadPos = lseek(ifd, 0, SEEK_CUR);
    // push the file pointer to where the data pages are
    lseek(ifd, pageMap.pr_npage, SEEK_CUR);
    SeekToPageBoundary(ifd);

    // We are at the segment we need to be...
    totalRead = 0;
    for (i = 0; i < pageMap.pr_npage; i += pageStatusInfoBufSize) {
      if ((pageMap.pr_npage - i) > pageStatusInfoBufSize)
	numRead = pageStatusInfoBufSize;
      else
	numRead = pageMap.pr_npage - i;

      currentPos = lseek(ifd, 0, SEEK_CUR);
      // move the pointer back
      lseek(ifd, lastPageInfoReadPos, SEEK_SET);
      // read in a bunch of stuff
      READ(ifd, pageStatusInfo, numRead, segmentType, INCR_CKPT_MARKER);
      // figure out the position now...
      lastPageInfoReadPos = lseek(ifd, 0, SEEK_CUR);

      // move the pointer forward
      lseek(ifd, currentPos, SEEK_SET);
      startPage = -1;
      numInSeq = 0;
      for (j = 0; j < numRead; j++) {
	if (!(pageStatusInfo[j] & PG_MODIFIED)) {
	  if (numInSeq > 0) {
	    assert(startPage >= 0);
	    // read the page back---simple indexing to figure out where
	    // the page belongs in virtual memory.  

	    //need to read back in the same way we wrote out (encryption/decryption)
	    unsigned long offset = 0;
	    long bytesToGo = numInSeq * pageMap.pr_pagesize;
	  
	    while (1) {
	      if(bytesToGo > BUF_SIZE) {
		READ(ifd, (caddr_t) (((unsigned long) pageMap.pr_vaddr) + 
				     ((i + startPage) * pageMap.pr_pagesize) + offset), 
		     BUF_SIZE, segmentType, INCR_CKPT_MARKER);
		offset += BUF_SIZE;
		bytesToGo -= BUF_SIZE;
	      }
	      else {
		if(bytesToGo > 0) {
		READ(ifd, (caddr_t) (((unsigned long) pageMap.pr_vaddr) + 
				     ((i + startPage) * pageMap.pr_pagesize) + offset), 
		     bytesToGo, segmentType, INCR_CKPT_MARKER);
		}
		break;
	      }
	    }
	    totalRead += numInSeq;	    
	  }
	  startPage = -1;
	  numInSeq = 0;
	  continue;
	}
	// The page is a modified page
	if (startPage < 0) {
	  // reset the start point
	  startPage = j;
	}
	// bunch the stuff
	numInSeq++;
      }
      if (numInSeq > 0) {
	assert(startPage >= 0);
	// read a set of pages back---simple indexing to figure out where
	// the page belongs in virtual memory. 

	//need to read back in the same way we wrote out (encryption/decryption)
	unsigned long offset = 0;
	long bytesToGo = numInSeq * pageMap.pr_pagesize;
	
	while (1) {
	  if(bytesToGo > BUF_SIZE) {
	    READ(ifd, (caddr_t) (((unsigned long) pageMap.pr_vaddr) + 
				 ((i + startPage) * pageMap.pr_pagesize) + offset), 
		 BUF_SIZE, segmentType, INCR_CKPT_MARKER);
	    offset += BUF_SIZE;
	    bytesToGo -= BUF_SIZE;
	  }
	  else {
	    if(bytesToGo > 0) {
	      READ(ifd, (caddr_t) (((unsigned long) pageMap.pr_vaddr) + 
				   ((i + startPage) * pageMap.pr_pagesize) + offset), 
		   bytesToGo, segmentType, INCR_CKPT_MARKER);
	    }
	    break;
	  }
	}	
	totalRead += numInSeq;
      }
    }
    assert(totalRead == numPages);
  }
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Restore the stack from the master checkpoint file and then
// 	read in the increments.
// 
// Arguments:
// 	ifd --- file descriptor of the master checkpoint file
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	Restores the stack
// 
// /////////////////////////////////////////////////////////////////

void IncrCkpt::RestoreStackSegment(int ifd)
{
  int i;
  int lastIncr, incrFd;
  char incrCkptFile[EGIDA_FILENAME_LEN];
  FullCkpt fullCkpt;

  std::cout << "In incr About to restore master ckpt stack" << std::endl;
  fullCkpt.RestoreSegment(ifd, EGIDA_STACK_SEG);
  std::cout << "done with master's stack" << std::endl;
  // now do the increments
  for (i = 2; i <= _lastIncrCtr; i++) {
    sprintf(incrCkptFile, "%s.%d", _ckptImpl->ckptFileName, i);
    std::cout << "Incr Opening file: " << incrCkptFile << std::endl;
    if ((incrFd = open(incrCkptFile, O_RDONLY, S_IRUSR | S_IWUSR)) < 0) {
      std::cout << "Unable to open incr file:" << incrCkptFile << std::endl;
      assert(0);
      exit(0);
    }
    RestoreSegment(incrFd, EGIDA_STACK_SEG);
  }
}





// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Reads in a full ckpt file and hashes the information
//      for checking whether tampering has occurred.
// 
// Arguments:
// 	fd: File descriptor of the checkpoint to be checked 
// 
// Results:
// 	hash string is modified
// 
// Side Effects:
// 	hash string is modified
// 
// /////////////////////////////////////////////////////////////////

void FullCkpt::ReadCkptFileandHash(char * ckptFile) 
{
  int segType, cookie;
  long base, size;
  unsigned long bytesToGo = 0;
  unsigned char dump[BUF_SIZE];
  prmap_t memMap;


  //HashInit done in calling function
  int cfd = open(ckptFile, O_RDONLY, S_IRUSR, S_IWUSR);

  READ(cfd, &cookie, sizeof(unsigned int), SEGMENT_TAG, BOTH_CKPT_MARKER);
  hash(&cookie, sizeof(unsigned int), SEGMENT_TAG);
  READ(cfd, &base, sizeof(unsigned long), EGIDA_HEAP_SEG, BOTH_CKPT_MARKER);
  hash(&base, sizeof(unsigned long), EGIDA_HEAP_SEG);
  READ(cfd, &size, sizeof(unsigned long), EGIDA_HEAP_SEG, BOTH_CKPT_MARKER);
  hash(&size, sizeof(unsigned long), EGIDA_HEAP_SEG);

  SeekToPageBoundary(cfd);
 
  while (1) {
    if(READ(cfd, &segType, sizeof(int), SEGMENT_TAG, FULL_CKPT_MARKER) 
       != sizeof(int))
      break;
    hash(&segType, sizeof(int), SEGMENT_TAG);
    READ(cfd, &memMap, sizeof(prmap_t), segType, FULL_CKPT_MARKER);
    hash(&memMap, sizeof(prmap_t), segType);
    
    SeekToPageBoundary(cfd);
    
    bytesToGo = memMap.pr_size;
    while(1) {
      if(bytesToGo >= BUF_SIZE) {
	READ(cfd, dump, BUF_SIZE, segType, FULL_CKPT_MARKER);
	hash(dump, BUF_SIZE, segType);
	bytesToGo -= BUF_SIZE;
      }
      else {
	if(bytesToGo > 0) {
	  READ(cfd, dump, bytesToGo, segType, FULL_CKPT_MARKER);
	  hash(dump, bytesToGo, segType);
	}
	break;
      }
      
    }
      
    //SeekToPageBoundary(cfd); 
  }
  
  //HashFinal done in calling function.
  close(cfd);
}







// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Reads in a full ckpt file and hashes the information
//      for checking whether tampering has occurred.
// 
// Arguments:
// 	fd: File descriptor of the checkpoint to be checked 
// 
// Results:
// 	hash string is modified
// 
// Side Effects:
// 	hash string is modified
// 
// /////////////////////////////////////////////////////////////////

void IncrCkpt::ReadCkptFileandHash(char * ckptFile)
{
  prasmap_t pageMap;
  long bytesToGo;
  unsigned int cookie;
  unsigned long base, size;
  int segmentType, numPages;
  unsigned char pageInfo[BUF_SIZE];

  //hash init done previously
  int cfd = open(ckptFile, O_RDONLY, S_IRUSR, S_IWUSR);

  READ(cfd, &cookie, sizeof(unsigned int), SEGMENT_TAG, BOTH_CKPT_MARKER);
  hash(&cookie, sizeof(unsigned int), SEGMENT_TAG);
  READ(cfd, &base, sizeof(unsigned long), EGIDA_HEAP_SEG, BOTH_CKPT_MARKER);
  hash(&base, sizeof(unsigned long), EGIDA_HEAP_SEG);
  READ(cfd, &size, sizeof(unsigned long), EGIDA_HEAP_SEG, BOTH_CKPT_MARKER);
  hash(&size, sizeof(unsigned long), EGIDA_HEAP_SEG);

  SeekToPageBoundary(cfd); 
  
  while(1) { 

    if(READ(cfd, &segmentType, sizeof(int), SEGMENT_TAG, INCR_CKPT_MARKER)
       != sizeof(int)) 
      break; 
    hash(&segmentType, sizeof(int), SEGMENT_TAG);

    READ(cfd, &pageMap, sizeof(prasmap_t), segmentType, INCR_CKPT_MARKER);
    hash(&pageMap, sizeof(prasmap_t), segmentType);

    READ(cfd, &numPages, sizeof(int), segmentType, INCR_CKPT_MARKER);
    hash(&numPages, sizeof(int), segmentType);

    //get the information about the pages
    bytesToGo = pageMap.pr_npage;
    while(1) {
      if(bytesToGo >= BUF_SIZE) {
	READ(cfd, pageInfo, BUF_SIZE, segmentType, INCR_CKPT_MARKER);
	hash(pageInfo, BUF_SIZE, segmentType);
	bytesToGo -= BUF_SIZE;
      }
      else {
	if(bytesToGo > 0) {
	  READ(cfd, pageInfo, bytesToGo, segmentType, INCR_CKPT_MARKER);
	  hash(pageInfo, bytesToGo, segmentType);
	}
	break;
      }
    }

    SeekToPageBoundary(cfd);
    
    //get the actual memory dumps
    bytesToGo = numPages * pageMap.pr_pagesize;
    while(1) {
      if(bytesToGo >= BUF_SIZE) {
	READ(cfd, pageInfo, BUF_SIZE, segmentType, INCR_CKPT_MARKER);
	hash(pageInfo, BUF_SIZE, segmentType);
	bytesToGo -= BUF_SIZE;
      }
      else {
	if(bytesToGo > 0) {
	  READ(cfd, pageInfo, bytesToGo, segmentType, INCR_CKPT_MARKER);
	  hash(pageInfo, bytesToGo, segmentType);
	}
	break;
      }
    }

    //SeekToPageBoundary(cfd);
  }

  //HashFinal done in calling function
  close(cfd); 
}

