// CkptImpl.H -- 
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
// $Log: CkptImpl.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:12  ravshank
// Start of Spring 2001
//
// Revision 1.8  2000/11/01 23:24:26  phoebe
// Hash and sign of checkpoints is working. Also as checkpoints are cleaned up, so are the signed hashes corresponding to the checkpoints (this was not done earlier.)
//
// Revision 1.7  2000/06/27 13:22:27  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.6  2000/06/23 16:35:19  phoebe
// Cleaning out un-needed data members in classes.
//
// Revision 1.5  2000/06/23 15:53:40  phoebe
// Cleaned up the CkptImpl class a bit.
//
// Revision 1.4  2000/06/23 15:01:43  phoebe
// Took the FullCkpt data member out of IncrCkpt class. It was never instantiated and just used a a variable, so I put the variable in the methods it was needed, but took it out of the class.
//
// Revision 1.3  2000/03/16 17:17:58  phoebe
// Re-integrated the hash and sign functions into CkptImpl and Security files. Did not turn on any of the hooks for these functions. Just put the code in and made sure that things were still going to run.
//
// Revision 1.2  2000/03/07 00:11:16  phoebe
// Channel Encryption now working. Init now does Security::Init and Security::Reinit. Communication.cc modified to call security functions (obviously). Tested with normal run and restart of Egida_Object_Init-default.cc.
//
// $Id: CkptImpl.H,v 1.1.1.1 2001/02/12 00:00:12 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun May  2 14:35:41 1999
// Last Modified By: Phoebe Weidmann
// Last Modified On: Fri Nov 19 12:02:14 CST 1999
// Update Count    : 70
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_CKPT_IMPL_H)
#define _CKPT_IMPL_H

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <procfs.h>
#include <setjmp.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/fault.h>
#include <sys/mman.h>
#include <sys/stack.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/utsname.h>
#include <sys/types.h>

#include "Globals.H"

class CkptImpl {
public:
  enum CkptImplType {EGIDA_FULL_CKPT, EGIDA_INCR_CKPT};

  CkptImpl() { 
    //static members are already set and these are the one's we are 
    //  worried about on the creation of an object.
  };

  ~CkptImpl() { 
  };

  void Initialize(int self);
  void ReInitialize(void);
  
  // called when the application is about to exit
  void Terminate(void);

  void SetupCkpt(int *ofd, char *resultFileName);

  unsigned long GetHeapSize(void) const {
    return this->heapSize;
  };
  void SetHeapSize(int size) {
    this->heapSize = size;
  };

  void IncrementCkptCounter(void) {
    this->ckptCounter++;
  };

  void SetLongJmpBuf(sigjmp_buf b) {
    memcpy(this->env, b, sizeof(sigjmp_buf));
  };

  void JumpBack() {
    siglongjmp(this->env, 1);
  };

  virtual int TakeCkpt(int ofd) = 0;
  // depending on the cookie info present in the file, this method
  // will call IncrCkpt's Restore or FullCkpt's Restore
  void RestoreCkptFile(const char *fileName, int rollback);
  virtual void RestoreCkpt(const char *fileName, int rollback) = 0;
  void RestoreStackPreamble(void);
  friend void RestoreStack(int code);

protected:
  // used for the file descriptor for the /proc/<pid>/pd file
  int pageDataFd;
  sigjmp_buf env;
  stack_t altStack;
  unsigned long stackBase, dataBase, heapBase;
  int stackSize, dataSize, heapSize;
  // keeps track of the total number of checkpoints taken.
  static int ckptCounter;
  // this is the base name of a checkpoint file.
  static char ckptFileName[EGIDA_FILENAME_LEN];

  virtual void RestoreSegment(int ifd, int segType) = 0;
  virtual void RestoreStackSegment(int ifd) = 0;

  void IdentifySegs(prmap_t **result, int *numSegs);
  void ClassifySegment(unsigned long vaddr, int segSize, int *segmentType) const;

  static void SeekToPageBoundary(int fd);
};



class FullCkpt : public CkptImpl {
public:
  FullCkpt() { };
  virtual int TakeCkpt(int ofd);
  virtual void RestoreCkpt(const char *fileName, int saveArg);

  //function used to verify signature
  virtual void ReadCkptFileandHash(char * ckptFile);

  friend class IncrCkpt;  

private:
  void RestoreHeapDataSegs(int ifd);
  void WriteCkpt(int ofd);
  void RestoreSegment(int ifd, int segType);
  void RestoreStackSegment(int ifd);
};

class IncrCkpt : public CkptImpl {
public:
  IncrCkpt() { };
  virtual int TakeCkpt(int ofd);
  virtual void RestoreCkpt(const char *fileName, int saveArg);
  
  //function used to verify signature
  virtual void ReadCkptFileandHash(char * ckptFile);

private:
  void WriteCkpt(int ofd);
  void RestoreSegment(int ifd, int segType);
  void RestoreStackSegment(int ifd);
};

#endif
