// HowToCkpt.H -- 
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
// $Log: HowToCkpt.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:14  ravshank
// Start of Spring 2001
//
// Revision 1.6  2000/11/21 22:27:12  phoebe
// GarbageCollect in the SentStore is now working async. We changed the logic slightly so that all files are cleaned by one process and we clean when we've heard 3 responses (not necessarily all from different processes...this is ok we think.) Also...our favorite core dump on TakeCkpt (the memcpy one) has crept back in the picture. <grrrr>
//
// Revision 1.5  2000/10/12 19:50:50  phoebe
// Optimistic is still not working for more than one failure, but the incarnation number is now working correctly, and on the second failure it hangs in exactly the same spot every time. Also...optimistic is now rolling back a checkpoint file instead of doing the exec-ing that it was doing before. Additionally, during some of the debugging process, checkpoints are now shrinking heap sizes correctly (we thought they were doing it before, but they weren't.)
//
// Revision 1.4  2000/09/27 22:03:00  phoebe
// In CkptImpl changed the growing of the heap from a strict monotonically increasing function (using the check that we only grow if size is less than what is needed) to one that can shrink. The reason we can do this is sbrk will take as an argument a negative value, where as malloc cannot.
//
// Revision 1.3  2000/06/30 19:41:34  phoebe
// Commented out actions in PostCkptActions (Egida class) and can now restart Asynch checkpoint. However, this is still not a correct implementation because it will never clean up det logs.
//
// Revision 1.2  2000/06/27 13:22:41  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.1.1.1  2000/03/06 20:00:15  phoebe
// Sriram's original code with no modifications
//
// $Id: HowToCkpt.H,v 1.1.1.1 2001/02/12 00:00:14 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Mon May  3 10:01:59 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu Jul  1 22:02:35 1999
// Update Count    : 32
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_HOW_TO_CKPT_H)
#define _HOW_TO_CKPT_H

#include <iterator>
#include <list>

class HowToCkpt;

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "CkptImpl.H"

class HowToCkpt {
public:
  HowToCkpt() {
    this->id = -1;
    this->ckptImpl = NULL;
  };

  ~HowToCkpt() {
    this->ckptImpl = NULL;
  };

  HowToCkpt(int self, CkptImpl *c) {
    this->id = self;
    this->ckptImpl = c;
  };

  HowToCkpt(int self, CkptImpl::CkptImplType implType, const char *progName);

  void Initialize(int self, CkptImpl *c);
  void Terminate(void);

  virtual void TimerExpired(void) = 0;
  virtual void TakeCkpt(void) = 0;
  void RestoreCkpt(const char *fileName, bool rollback);
  void GarbageCollect(void);
  bool OkToRemoveCkptFiles(void);

protected:
  int id;
  CkptImpl *ckptImpl;
  CkptImpl::CkptImplType type;
};



class SyncCkpt : public HowToCkpt {
public:
  SyncCkpt() { };

  ~SyncCkpt() { };

  SyncCkpt(int self, CkptImpl *c) : HowToCkpt(self, c) { };

  SyncCkpt(int self, CkptImpl::CkptImplType implType, const char *progName) 
    : HowToCkpt(self, implType, progName) 
    { };

  void TakeCkpt();
  void TimerExpired(void) { };
};


// A struct that stores a mapping between a childPid and
// the file to which the child is writing out the checkpoint
struct AsyncCkptChildInfo {
public:
  AsyncCkptChildInfo() {
    this->childPid = -1;
    this->ckptFileName[0] = '\0';
  };

  AsyncCkptChildInfo(int c, char *f) {
    this->childPid = c;
    strcpy(ckptFileName, f);
  };

  int childPid;
  char ckptFileName[EGIDA_FILENAME_LEN];
};

typedef std::list<AsyncCkptChildInfo*> ChildInfo_List;
typedef std::list<AsyncCkptChildInfo*>::iterator ChildInfo_ListIterator;



class AsyncCkpt : public HowToCkpt {
public:
  AsyncCkpt() {};

  ~AsyncCkpt() { 
    int childStatus;
    // wait for all the child process to finish
    // waitpid(-1, &childStatus, 0);
  };

  AsyncCkpt(int self, CkptImpl *c) : HowToCkpt(self, c) { };

  AsyncCkpt(int self, CkptImpl::CkptImplType implType, const char *progName) 
    : HowToCkpt(self, implType, progName) 
    { };

  void TakeCkpt(void);
  void TimerExpired(void);

private:
  ChildInfo_List childInfo_List;

  void CkptDone(const char *ckptFileName);
  bool RemoveChildInfo(int childPid, char *ckptFileName);
};

#endif
