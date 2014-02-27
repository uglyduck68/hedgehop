// CkptProtocol.H -- 
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
// $Log: CkptProtocol.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:12  ravshank
// Start of Spring 2001
//
// Revision 1.3  2000/07/11 22:20:00  phoebe
// Did several things: Streamlined DebugTrace so that Egida_Object's RestoreDone didnt' need to call it (got rid of a small memory leak by doing this.) It's less efficient, but then debugging code shouldn't be in the release copy anyway. Two...moved the -recover string to the proper place in the failuredetector so that on a subsequent restart (multiple restarts of one process) it will correctly identify which checkpoint it should be rolling back to. Third...moved growing of the heap in CkptImpl to the RestoreHeapData segs for FullCkpt and put it in the RestoreCkpt for Incremental (in the loop). This is in hopes of being able to restart from in incremental checkpoint. At the moment still can't restart multilple times and can't restart from an incremental checkpoint.
//
// Revision 1.2  2000/06/27 13:22:28  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.1.1.1  2000/03/06 20:00:13  phoebe
// Sriram's original code with no modifications
//
// $Id: CkptProtocol.H,v 1.1.1.1 2001/02/12 00:00:12 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu Apr 29 18:06:01 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Aug 16 14:35:13 1999
// Update Count    : 66
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_CKPT_PROTOCOL_H)
#define _CKPT_PROTOCOL_H

#include <stdlib.h>
#include <unistd.h>

#include "FlushScheduler.H"
#include "Globals.H"
#include "HowToCkpt.H"
#include "LogProtocol.H"


class CkptProtocol {
public:
  CkptProtocol() {
    this->id = -1;
    this->numProcs = 0;
    this->forcedCkpt = 0;
    this->avoidThreshold = 0.0;
    this->flushScheduler = NULL;
    this->howToCkpt = NULL;
    this->pbLog = NULL;
    memset(this->rollbackFile, 0, EGIDA_FILENAME_LEN);
  };

  ~CkptProtocol() { 
    delete this->flushScheduler;
  };

  // If I write the constructor code here, can't compile!
  CkptProtocol(int self, int numP, int freq, 
	       FlushScheduler::FlushSchedulerType schedType);

  void SetAvoidThreshold(int a) {
    this->avoidThreshold = a;
  };

  virtual void Initialize(PbLog * lp, HowToCkpt * hc);
  void Terminate(void);

  void TimerExpired(void);
  void TakeCkpt(int forced = 0);
  void CkptDone(void);

  virtual void ProcessMsg(int source, int tag, char *msg, int msgSize);
  void GetRollbackFile(char *fileName);

  virtual void PrepareForCrash(void);

protected:
  int  id;
  int  numProcs;
  int forcedCkpt;
  // For CIC protocols, this parameter is used to determine if a scheduled
  // independent checkpoint has to be taken.  Due to forced
  // checkpoints, in our FTCS'99 paper, we introduced the notion of
  // smart checkpointing---a process avoids an independent checkpoint
  // if it has taken a forced/independent checkpoint in the last
  // avoidThreshold seconds.
  int avoidThreshold;
  struct timeval lastCkptTime;

  char rollbackFile[EGIDA_FILENAME_LEN];

  FlushScheduler * flushScheduler;
  HowToCkpt * howToCkpt;
  PbLog * pbLog;

  virtual int NeedToCkpt(void);
};

#endif
