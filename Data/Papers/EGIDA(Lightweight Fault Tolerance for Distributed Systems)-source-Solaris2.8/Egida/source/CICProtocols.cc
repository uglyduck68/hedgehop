// CICProtocols.cc -- 
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
// $Log: CICProtocols.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:15  ravshank
// Start of Spring 2001
//
// Revision 1.3  2000/06/26 21:31:01  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.2  2000/06/23 02:47:27  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.1.1.1  2000/03/06 20:00:16  phoebe
// Sriram's original code with no modifications
//
// $Id: CICProtocols.cc,v 1.1.1.1 2001/02/12 00:00:15 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Fri Dec 11 15:15:18 1998
// Last Modified By: Sriram Rao
// Last Modified On: Sun Aug 15 19:34:21 1999
// Update Count    : 52
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <strstream>

#include "PbCkpt.H"

// Netzer Protocol code is from Figure 10 of the paper:
// Communication-Based Prevention of Useless Checkpoints in
// Distributed Computations
// Authors of the paper: Helary, Mostefaoui, Netzer, Raynal

void PbHMNR::PreCkptActions()
{
  int i;

  for (i = 0; i < this->numProcs; i++) {
    this->sentTo[i] = false;
    if (i != this->id)
      this->taken[i] = this->greater[i] = true;
  }
  this->logicalClock++;
  // In the paper, this is done after the checkpoint is taken.  Since
  // the protocol requires that checkpointing be synchronous, it
  // doesn't matter if this is done here; if do the optimistic version
  // of the protocol from our FTCS99 paper, in which we use
  // asynchronous checkpointing and assume that checkpoint costs zero
  // time, then this update has to happen here---PostCkptActions
  // are called only AFTER the checkpoint is written out to disk.
  this->ckptVector[this->id]++;
}

void PbHMNR::GetPiggyback(int dest, char **header, 
					 int *hSize)
{
  std::ostrstream os;
  int i;

  this->sentTo[dest] = true;
  os << this->logicalClock << ' ';
  for (i = 0; i < this->numProcs; i++) {
    os << this->greater[i] << ' ';
    os << this->taken[i] << ' ';
    os << this->ckptVector[i] << ' ';
  }
  os << std::ends;
  *header = os.str();
  *hSize = os.pcount();
}

void PbHMNR::ProcessPiggyback(int source, const char *header, int hSize)
{
  std::istrstream is(header, hSize);
  int messageLC, messageCkptVector[EGIDA_MAX_PROCS];
  bool messageGreater[EGIDA_MAX_PROCS], messageTaken[EGIDA_MAX_PROCS];
  int i, prevent;

  is >> messageLC;
  for (i = 0; i < this->numProcs; i++) {
    is >> messageGreater[i];
    is >> messageTaken[i];
    is >> messageCkptVector[i];
  }

  if ((messageCkptVector[this->id] == this->ckptVector[this->id]) &&
      (messageTaken[this->id])) {
    this->forcedCkpt = 1;
    this->ckptProtocol->TakeCkpt(1);
  }
  else if (messageLC > this->logicalClock) {
    for (i = 0; i < this->numProcs; i++) 
      if (this->sentTo[i] && messageGreater[i]) {
	this->forcedCkpt = 1;
	this->ckptProtocol->TakeCkpt(1);
	break;
      }
  }
  if (messageLC > this->logicalClock) {
    this->logicalClock = messageLC;
    this->greater[this->id] = false;
    for (i = 0; i < this->numProcs; i++)
      if (i != this->id)
	this->greater[i] = messageGreater[i];
  }
  else if (messageLC == this->logicalClock) {
    for (i = 0; i < this->numProcs; i++)
      this->greater[i] = this->greater[i] && messageGreater[i];
  }
  for (i = 0; i < this->numProcs; i++) {
    if (i == this->id)
      continue;
    if (messageCkptVector[i] > this->ckptVector[i]) {
      this->ckptVector[i] = messageCkptVector[i];
      this->taken[i] = messageTaken[i];
    }
    else if (messageCkptVector[i] == this->ckptVector[i]) 
      this->taken[i] = messageTaken[i] || this->taken[i];
  }
}

// The code for Simoncini's protocol is from the paper by Briatico,
// Ciufolleti, and Simoncini.  Reference is in our FTCS'99
// paper---Analysis of Communication-induced checkpointing.
void PbBCS::PreCkptActions(void)
{
  this->logicalClock++;
}

void PbBCS::GetPiggyback(int dest, char **header, 
					    int *hSize)
{
  std::ostrstream os;
  
  // send out the interval
  // os << this->ckptNo << ' ';
  os << this->logicalClock << ' ' << std::ends;
  *header = os.str();
  *hSize = os.pcount();
  
}

void PbBCS::ProcessPiggyback(int source, const char
						*header, int hSize)
{
  std::istrstream is(header, hSize);
  int messageLC = -1, senderInterval;
  
  // do the interval processing just before delivering the message
  // is >> senderInterval;

  is >> messageLC;

  if (messageLC > this->logicalClock) {
    this->forcedCkpt = 1;
    // cout << this->id << " taking a forced checkpoint" << endl;
    this->ckptProtocol->TakeCkpt(1);
    this->logicalClock = messageLC;
  }
  //  this->RecordCkptGraphDepInfo(source, senderInterval);
}

// Baldoni's protocol is from his SRDS'98 paper.
void PbBQC::PreCkptActions()
{
  // In the paper by Baldoni, this has to be done after the checkpoint 
  // is written out.  The protocol requires synchronous checkpointing
  // and hence, it doesn't matter if this code is executed here; if we 
  // use the optimistic version of his protocol, in which we use
  // asynchronous checkpointing and assume that checkpointing takes
  // zero time, then we have to execute this code here.  The methods
  // PostCkptActions gets called AFTER the checkpoint is written 
  // out to stable storage.
  int j;

  for (j = 0; j < this->numProcs; j++) {
    this->pred[this->id][j] = 
      this->pred[this->id][j] > this->immPred[j] ? 
      this->pred[this->id][j] :  this->immPred[j];
    this->immPred[j] = -1;
  }
  this->vectorClock[this->id]++;
  this->afterFirstSend = false;
}

void PbBQC::GetPiggyback(int dest, char **header, int
					  *hSize)
{
  std::ostrstream os;
  int i, j;

  for (i = 0; i < this->numProcs; i++) {
    os << this->vectorClock[i] << ' ';
    for (j = 0; j < this->numProcs; j++)
      os << this->pred[i][j] << ' ';
  }
  os << std::ends;

  *header = os.str();
  *hSize = os.pcount();
  this->afterFirstSend = true;
}

void PbBQC::ProcessPiggyback(int source, const char
			     *header, int hSize)
{
  int i, j, takeForcedCkpt = 0, maxVC;
  std::istrstream is(header, hSize);
  int messageVC[EGIDA_MAX_PROCS];
  int messagePred[EGIDA_MAX_PROCS][EGIDA_MAX_PROCS];

  for (i = 0; i < this->numProcs; i++) {
    is >> messageVC[i];
    for (j = 0; j < this->numProcs; j++)
      is >> messagePred[i][j];
  }

  if (this->afterFirstSend) {
    for (i = 0; i < this->numProcs; i++) {
      if (messageVC[i] > this->vectorClock[i]) {
	for (j = 0; j < this->numProcs; j++) {
	  maxVC = this->vectorClock[j] > messageVC[j] ?
	    this->vectorClock[j] : messageVC[j];
	  if (messagePred[i][j] + 1 > maxVC) {
	    takeForcedCkpt = 1;
	    break;
	  }
	}
      }
      if (takeForcedCkpt)
	break;
    }
    if (takeForcedCkpt) {
      this->forcedCkpt = 1;
      this->ckptProtocol->TakeCkpt(1);
    }
  }

  for (i = 0; i < this->numProcs; i++) {
    this->vectorClock[i] = this->vectorClock[i] > messageVC[i] ?
      this->vectorClock[i] : messageVC[i];
    for (j = 0; j < this->numProcs; j++) 
      this->pred[i][j] = this->pred[i][j] > messagePred[i][j] ?
	this->pred[i][j] : messagePred[i][j];
  }
  this->immPred[source] = this->immPred[source] > messageVC[source] ?
    this->immPred[source] : messageVC[source];

}
