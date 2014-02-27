// CausalLogProtocol.cc -- 
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
// $Log: CausalLogProtocol.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:18  ravshank
// Start of Spring 2001
//
// Revision 1.6  2000/10/17 15:02:27  phoebe
// Stable code checkin. RBP is extremely stable except if you kill the master and slave at exactly the same time....it will hang in ReplayDeliver. SBP cannot support concurrent failures due to the lost control messages or hanging in ReplayDeliver. Causal can do +concurrent+ failures as long as control messages are not lost....so the restart must be staggered. Causal seems to suffer the same RBP problem with a master/slave pair, but unsure if this is the problem or if I didn't set numfailures=2...think the later would fix this. All the sentLog protocols (SBP and Causal) suffer from processes dumping core during WriteCkpt if they have been running for a long time since we are not flushing volatile memory at the moment. Should go away with the proper sentLog class fix.
//
// Revision 1.5  2000/10/12 22:23:55  phoebe
// Causal logging seems to work for multiple failures (not concurrent) without a flush of the logs.
//
// Revision 1.4  2000/06/26 21:31:02  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.3  2000/06/26 19:09:49  phoebe
// Removed all wrapper methods out of Egida_Internal.cc and renamed calls in code to directly call the Egida::Method that would have been called by the Egida_Method call.
//
// Revision 1.2  2000/06/23 02:47:28  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.1.1.1  2000/03/06 20:00:16  phoebe
// Sriram's original code with no modifications
//
// $Id: CausalLogProtocol.cc,v 1.1.1.1 2001/02/12 00:00:18 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Wed May  5 23:46:50 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Aug 16 14:33:33 1999
// Update Count    : 33
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <iostream>
#include <strstream>

#include "CausalLogProtocol.H"
#include "Egida_Object.H"

void PbCausal::GetPiggyback(int dest, char **pb, int *pbSize)
{
  std::ostrstream os;

  this->detLog->RetrieveNonstable(dest, (const int *)
				  this->depMatrix[dest], os);

  *pb = os.str();
  *pbSize = os.pcount();
}

bool PbCausal::ProcessPiggyback(int source, int ssn, 
					 char *pb, int pbSize)
{
  int wdv[EGIDA_MAX_PROCS];

  this->lc++;
  this->depMatrix[this->id][this->id] = this->lc;

  memset(wdv, 0, EGIDA_MAX_PROCS * sizeof(int));
  this->detLog->Log(source, pb, pbSize, wdv);
  UpdateDepMatrix(source, wdv);
  ComputeStable();
  SendAck(source, ssn);
  return true;
}

void PbCausal::SendAck(int source, int ssn)
{
  std::ostrstream os;

  this->lastAckSent[source] = ssn;

  os << EGIDA_ACK << ' ' << ssn << std::ends;
 
  Egida::SendControlMsg(source, EGIDA_LOG_PROTOCOL_MSG, os.str(),
		       os.pcount());
  // unfreeze the buffer so that it will get freed
  os.rdbuf()->freeze(false);

}

void PbCausal::ProcessMsg(int source, int tag, char *msg, 
				   int msgSize)
{
  std::istrstream is(msg, msgSize);
  int msgType, ssn;
  int vector[EGIDA_MAX_PROCS]; 

  is >> msgType;
  assert(msgType == EGIDA_ACK);
  is >> ssn;
  for(int i = 0; i < EGIDA_MAX_PROCS; i++)
    is >> vector[i];
  ProcessAck(source, ssn);
}

void PbCausal::ProcessAck(int source, int ssn)
{
  int i, pbLogSize;
  EventInfo *eInfo = NULL;
  char *pbLog = NULL;
  int psn[EGIDA_MAX_PROCS];

  if (this->lastAckRecd[source] > ssn)
    return;

  this->lastAckRecd[source] = ssn;

  this->sentLog->TryRetrieve(this->id, ssn, source, &eInfo);
  if (eInfo != NULL) {
    Egida::FetchPiggybackLog(eInfo->pb, &pbLog, &pbLogSize);
    this->detLog->RetrieveDetIds(pbLog, pbLogSize, psn);
    this->detLog->UpdateLoggedAt(source, psn);
    for (i = 0; i < this->numProcs; i++)
      this->depMatrix[source][i] = this->depMatrix[source][i] > psn[i] ?
        this->depMatrix[source][i] : psn[i];
    ComputeStable();
  }

}


void PbCausal::UpdateDepMatrix(int source, int *wdv)
{
  for (int i = 0; i < this->numProcs; i++) {
    this->depMatrix[source][i] = this->depMatrix[source][i] > wdv[i] ?
      this->depMatrix[source][i] : wdv[i];
    this->depMatrix[this->id][i] = this->depMatrix[this->id][i] > wdv[i] ?
      this->depMatrix[this->id][i] : wdv[i];
    this->depMatrix[i][i] = this->depMatrix[i][i] > wdv[i] ?
      this->depMatrix[i][i] : wdv[i];
  }
}


void PbCausal::ComputeStable()
{
  int stable[EGIDA_MAX_PROCS], temp[EGIDA_MAX_PROCS];

  memset(stable, 0, this->numProcs * sizeof(int));

  for (int i = 0; i < this->numProcs; i++) {
    // copy over the ith column
    for (int j = 0; j < this->numProcs; j++) 
      temp[j] = this->depMatrix[j][i];
    // sort it in decreasing order

    SortDecOrder(temp, this->numProcs);

    // take the f+1 largest entry. Since, we are counting from 0,
    // the index uses the f-th value.
    stable[i] = temp[this->numFailures];
  }

  this->detLog->MarkStable(stable);
}

void PbCausal::SortDecOrder(int *array, int size)
{
  int temp;

  for (int i = size - 1; i > 0; i--) 
    for (int j = 0; j < i; j++) 
      if (array[j] < array[j + 1]) {
        temp = array[j + 1];
        array[j + 1] = array[j];
        array[j] = temp;
      }
}

void PbCausal::PreReplayActions(int startEsn, bool rb)
{
  Egida::DisableTimer();
  ComputeStable();
  // claim that the entire det log is stable
  //  this->detLog->MarkLogStable();
}

void PbCausal::SendLastControlMessages() {
}
