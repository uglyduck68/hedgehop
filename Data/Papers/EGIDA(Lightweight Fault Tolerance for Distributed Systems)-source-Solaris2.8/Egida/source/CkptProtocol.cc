// CkptProtocol.cc -- 
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
// $Log: CkptProtocol.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:15  ravshank
// Start of Spring 2001
//
// Revision 1.7  2000/06/30 21:22:42  phoebe
// Sanity check before leaving for vacation.
//
// Revision 1.6  2000/06/27 13:22:57  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.5  2000/06/26 21:31:04  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.4  2000/06/26 19:09:50  phoebe
// Removed all wrapper methods out of Egida_Internal.cc and renamed calls in code to directly call the Egida::Method that would have been called by the Egida_Method call.
//
// Revision 1.3  2000/06/23 02:47:30  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.2  2000/06/22 20:58:56  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.1.1.1  2000/03/06 20:00:17  phoebe
// Sriram's original code with no modifications
//
// $Id: CkptProtocol.cc,v 1.1.1.1 2001/02/12 00:00:15 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu Apr 29 18:05:46 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Aug 16 14:42:56 1999
// Update Count    : 75
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <iostream>

#include "CkptProtocol.H"
#include "Egida_Object.H"
#include "Stats.H"
#include "Timer.H"

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Constructor for the checkpoint protocol object.  If I put the
// 	constructor in the header file, for some reason, code doesn't
// 	compile. 
// 
// Arguments:
// 	freq -- if periodic checkpointing, freq of taking checkpoints
//           -- if random checkpointing, mean of the exp. distribution
//      schedType -- periodic or random
//      The other two, the usual meaning.
//
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

CkptProtocol::CkptProtocol(int self, int numP, int freq, 
			   FlushScheduler::FlushSchedulerType schedType) 
{
  this->id = self;
  this->numProcs = numP;
  this->forcedCkpt = 0;
  this->avoidThreshold = 0;
  if (schedType == FlushScheduler::EGIDA_PERIODIC_FLUSH) {
    this->flushScheduler = new PeriodicFlushScheduler(freq);
  }
  else if (schedType == FlushScheduler::EGIDA_RANDOM_FLUSH) {
    this->flushScheduler = new RandomFlushScheduler(freq);
  }
  else {
    std::cout << "unknown checkpoint scheduler!" << std::endl;
    _exit(0);
  }
  memset(this->rollbackFile, 0, EGIDA_FILENAME_LEN);
  this->howToCkpt = NULL;
  this->pbLog = NULL;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Initialize the pbLog and howToCkpt fields of the
// 	CkptProtocol object.
// 
// Arguments:
// 	Obvious meaning.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void CkptProtocol::Initialize(PbLog *lp, HowToCkpt *hc)
{
  this->pbLog = lp;
  this->howToCkpt = hc;
}

void CkptProtocol::Terminate()
{

}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
//      Perform protocol specific actions and then write out a checkpoint 
// 
// Arguments:
// 	forced --- if set, then the checkpoint is a forced checkpoints 
// 	(ala CIC protocols)
// 
// Results:
//      Uses howToCkpt module to write out a checkpoint.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void CkptProtocol::TakeCkpt(int forced)
{
  struct timeval endTime;
  double timeSpent;
  int statLabel;

  if(COLLECTING_STATS) {
    gettimeofday(&this->lastCkptTime, NULL);
  }

  this->forcedCkpt = forced;

  if (this->forcedCkpt)
    statLabel = EGIDA_FORCED_CKPT_STAT;
  else
    statLabel = EGIDA_INDEP_CKPT_STAT;
  
  Egida::PreCkptActions();
  this->howToCkpt->TakeCkpt();

  if(COLLECTING_STATS) {
    gettimeofday(&endTime, NULL);
    Timer::ComputeTimeDiff(&timeSpent, this->lastCkptTime, endTime);
    Stats::Update(statLabel, 0, timeSpent);    
  }

  if (statLabel == EGIDA_INDEP_CKPT_STAT)
    this->flushScheduler->ScheduleFlush();
  this->forcedCkpt = 0;
}

void CkptProtocol::CkptDone()
{

}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Takes a checkpoint if a need exists (for example, if
// 	time-driven checkpointing is used, then, take a checkpoint if
// 	sufficient time has elapsed since the last checkpoint).
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

void CkptProtocol::TimerExpired()
{
  if (this->NeedToCkpt()) {
    this->TakeCkpt();
  }
}

void CkptProtocol::PrepareForCrash()
{

}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Determine whether a checkpoint has to be taken now.
// 
// Arguments:
// 	NONE
// 
// Results:
// 	Returns 1 if the scheduler determines that it is time to take
// 	a checkpoint; 0 otherwise.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

int CkptProtocol::NeedToCkpt(void)
{
  struct timeval timeNow;
  double timeElapsed;

  //this is not a stat taking gettimeofday...used for threshold check
  gettimeofday(&timeNow, NULL);
  Timer::ComputeTimeDiff(&timeElapsed, this->lastCkptTime, timeNow);

  // Avoid an independent checkpoint if a checkpoint has been taken in 
  // the last avoidThreshold sec.
  if (this->avoidThreshold > 0) 
    if ((timeElapsed - (double) this->avoidThreshold) < -5.0) {
      //not taking checkpoint because inside threshold
      return 0;
    }

  if (this->flushScheduler->NeedToFlush()) {
    return 1;
  }
  return 0;
}



// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Process messages sent by the checkpointing protocol.
// 
// Arguments:
// 	source --- id of the process that sent the message
//      tag --- message tag that was set by the sender
//      msg, msgSize --- obvious meaning.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void CkptProtocol::ProcessMsg(int source, int tag, char *msg, int msgSize)
{

}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Obtain the name of the checkpoint file to rollback to.
// 
// Arguments:
// 	fileName --- the name of the checkpoint file to rollback to
// 
// Results:
// 	Returns in fileName the checkpoint file to rollback to
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void CkptProtocol::GetRollbackFile(char *fileName)
{
  strcpy(fileName, this->rollbackFile);
}
