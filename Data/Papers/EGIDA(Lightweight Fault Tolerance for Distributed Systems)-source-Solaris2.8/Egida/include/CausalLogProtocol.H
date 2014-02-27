// CausalLogProtocol.H -- 
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
// $Log: CausalLogProtocol.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:12  ravshank
// Start of Spring 2001
//
// Revision 1.2  2000/06/27 13:22:26  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.1.1.1  2000/03/06 20:00:13  phoebe
// Sriram's original code with no modifications
//
// $Id: CausalLogProtocol.H,v 1.1.1.1 2001/02/12 00:00:12 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Wed May  5 23:45:06 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Aug 16 14:32:23 1999
// Update Count    : 22
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Implements Pi_Det logging protocol from Lorenzo's dissertation

#if defined(__cplusplus) && !defined(_CAUSAL_LOG_PROTOCOL_H)
#define _CAUSAL_LOG_PROTOCOL_H

#include <string.h>

#include "Globals.H"
#include "DetLog.H"
#include "LogProtocol.H"

class PbCausal : public PbLog {
public:
  PbCausal() { 
    int i;
    
    this->lc = 0;
    for (i = 0; i < EGIDA_MAX_PROCS; i++)
      memset(this->depMatrix[i], 0, EGIDA_MAX_PROCS * sizeof(int));
  };
  ~PbCausal() { };

  PbCausal(int self, int numP, int numF) :
    PbLog(self, numP, numF) {

    int i;

    this->lc = 0;
    for (i = 0; i < EGIDA_MAX_PROCS; i++)
      memset(this->depMatrix[i], 0, EGIDA_MAX_PROCS * sizeof(int));

  };

  void GetPiggyback(int dest, char **pb, int *pbSize);
  bool ProcessPiggyback(int source, int ssn, char *pb, int pbSize); 

  void ProcessMsg(int source, int tag, char *msg, int msgSize);
  void ProcessAck(int source, int ssn);
  void PreReplayActions(int startEsn, bool rb);
  void SendLastControlMessages();
  
protected:
  // logical clock
  int lc;
  int depMatrix[EGIDA_MAX_PROCS][EGIDA_MAX_PROCS];

  void UpdateDepMatrix(int source, int *wdv);
  void ComputeStable(void);
  void SortDecOrder(int *array, int size);
  void SendAck(int source, int ssn);
};

#endif
