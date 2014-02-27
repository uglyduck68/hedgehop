// PbCkpt.H -- 
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
// $Log: PbCkpt.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:14  ravshank
// Start of Spring 2001
//
// Revision 1.2  2000/06/27 13:22:50  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.1.1.1  2000/03/06 20:00:16  phoebe
// Sriram's original code with no modifications
//
// $Id: PbCkpt.H,v 1.1.1.1 2001/02/12 00:00:14 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun Aug 15 19:00:20 1999
// Last Modified By: Sriram Rao
// Last Modified On: Sun Aug 15 19:33:05 1999
// Update Count    : 10
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Piggybacking done by checkpoint protocols

#if defined(__cplusplus) && !defined(_PB_CKPT_H)
#define _PB_CKPT_H

#include "Globals.H"
#include "CkptProtocol.H"

class PbCkpt {
public:
  PbCkpt() {
    memset(this->ckptVector, 0, EGIDA_MAX_PROCS * sizeof(int));
    this->ckptProtocol = NULL;
    this->id = -1;
    this->numProcs = 0;
  };

  PbCkpt(int self, int numP, CkptProtocol *c) {
    memset(this->ckptVector, 0, EGIDA_MAX_PROCS * sizeof(int));
    this->ckptProtocol = c;
    this->id = self;
    this->numProcs = numP;
  }

  virtual void GetPiggyback(int dest, char **pb, int *pbSize) {
    *pb = NULL;
    *pbSize = 0;
  };

  virtual void ProcessPiggyback(int source, const char *pb, int
				pbSize) {  };

  virtual void PreCkptActions(void) { };
  virtual void PostCkptActions(const char *ckptFileName) { };

protected:
  int  id;
  int  numProcs; 
  int  forcedCkpt;
  CkptProtocol *ckptProtocol;
  int ckptVector[EGIDA_MAX_PROCS];
};



class PbHMNR : public PbCkpt {
public:
  PbHMNR() {
    this->logicalClock = 0;
    for (int i = 0; i < EGIDA_MAX_PROCS; i++)
      this->taken[i] = this->greater[i] = this->sentTo[i] = false;
  };

  PbHMNR(int self, int numP, CkptProtocol *c) :
    PbCkpt(self, numP, c) {
    this->logicalClock = 0;
    for (int i = 0; i < EGIDA_MAX_PROCS; i++)
      this->taken[i] = this->greater[i] = this->sentTo[i] = false;
  };

  void PreCkptActions(void);
  void GetPiggyback(int dest, char **pb, int *pbSize);
  void ProcessPiggyback(int source, const char *pb, int pbSize);

private:
  int logicalClock;
  bool taken[EGIDA_MAX_PROCS], greater[EGIDA_MAX_PROCS];
  bool sentTo[EGIDA_MAX_PROCS];
};



class PbBCS : public PbCkpt {
public:
  PbBCS() {
    this->logicalClock = 0;
  };

  PbBCS(int self, int numP, CkptProtocol *c) :
    PbCkpt(self, numP, c) {
    this->logicalClock = 0;
  };

  void PreCkptActions(void);
  void GetPiggyback(int dest, char **pb, int *pbSize);
  void ProcessPiggyback(int source, const char *pb, int pbSize);

private:
  int logicalClock;
};




class PbBQC : public PbCkpt {
public:
  PbBQC() {
    this->afterFirstSend = false;
    memset(this->vectorClock, 0, EGIDA_MAX_PROCS * sizeof(int));
    for (int i = 0; i < EGIDA_MAX_PROCS; i++) {
      this->immPred[i] = -1;
      for (int j = 0; j < EGIDA_MAX_PROCS; j++) {
	this->pred[i][j] = -1;
      }
    }
  };

  PbBQC(int self, int numP, CkptProtocol *c) :
    PbCkpt(self, numP, c) {
    this->afterFirstSend = false;
    memset(this->vectorClock, 0, EGIDA_MAX_PROCS * sizeof(int));
    this->vectorClock[self] = 1;
    for (int i = 0; i < EGIDA_MAX_PROCS; i++) {
      this->immPred[i] = -1;
      for (int j = 0; j < EGIDA_MAX_PROCS; j++) {
	this->pred[i][j] = -1;
      }
    }
  };

  void PreCkptActions(void);
  void GetPiggyback(int dest, char **pb, int *pbSize);
  void ProcessPiggyback(int source, const char *pb, int pbSize);

private:
  bool afterFirstSend;
  int vectorClock[EGIDA_MAX_PROCS];
  int immPred[EGIDA_MAX_PROCS], pred[EGIDA_MAX_PROCS][EGIDA_MAX_PROCS];
};
#endif
