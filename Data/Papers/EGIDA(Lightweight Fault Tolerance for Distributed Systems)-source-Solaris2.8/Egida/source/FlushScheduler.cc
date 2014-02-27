// FlushScheduler.cc -- 
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
// $Log: FlushScheduler.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:16  ravshank
// Start of Spring 2001
//
// Revision 1.5  2000/06/26 21:31:13  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.4  2000/06/26 16:56:59  phoebe
// Made all the Egida_Object methods and members static. Also moved GetMyId and GetNumProcs out of Egida_Internal and into Egida_Object.
//
// Revision 1.3  2000/06/23 02:47:41  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.2  2000/06/22 20:59:06  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.1.1.1  2000/03/06 20:00:21  phoebe
// Sriram's original code with no modifications
//
// $Id: FlushScheduler.cc,v 1.1.1.1 2001/02/12 00:00:16 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Tue May  4 23:23:18 1999
// Last Modified By: Sriram Rao
// Last Modified On: Sat Jul 17 17:05:54 1999
// Update Count    : 51
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include "Egida_Object.H"
#include "FlushScheduler.H"
#include "Timer.H"

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Determine if a flush to storage has to be done now.
// 
// Arguments:
// 	NONE
// 
// Results:
// 	Returns 1 if a flush to storage has to be done now
//              0 otherwise
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

int FlushScheduler::NeedToFlush()
{
  struct timeval timeNow;
  double timeElapsed = 0.0;
  int timeRemaining;

  if (this->timeToNextFlush < 0) {
    // if timeToNextFlush < 0, then, we don't want to take any
    // flushes from here onwards
    return 0;
  }

  gettimeofday(&timeNow, NULL);
  Timer::ComputeTimeDiff(&timeElapsed, this->lastFlushTime, timeNow);

  //need to flush?
  if ((timeElapsed - this->timeToNextFlush) > -1.5) {
    gettimeofday(&(this->lastFlushTime), NULL);
    return 1;
  }
  else {
    // for whatever reason, we got reminded much before our requested
    // time.  just to be safe, throw in yet another request...
    // timeRemaining = this->timeToNextFlush - timeElapsed;
    //    assert(timeRemaining > 0);
    //    Timer::SetTimer(timeRemaining);
    return 0;
  }

  return 0;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Schedule the next flush to storage by asking the Timer to
// 	generate an interrupt this->freq seconds from now.
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

void PeriodicFlushScheduler::ScheduleFlush() 
{
  if (this->frequency < 0) {
    this->timeToNextFlush = -1;
    return;
  }
  gettimeofday(&(this->lastFlushTime), NULL);
  Timer::SetTimer(this->frequency);
  this->timeToNextFlush = this->frequency;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Modify the frequency with which flushes are scheduled.
// 
// Arguments:
// 	freq --- desired flush frequency.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void PeriodicFlushScheduler::SetFlushFreq(int freq)
{
  this->frequency = freq;
  this->ScheduleFlush();
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Constructor for the random flush scheduler object.  If I
// 	put this code in the .H file, code doesn't compile!
// 
// Arguments:
// 	freq --- mean of the exponential distribution
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

RandomFlushScheduler::RandomFlushScheduler(int freq) :
  FlushScheduler(freq) 
{
  char distFileName[EGIDA_FILENAME_LEN];
  
  if (freq < 0) 
    return;

  sprintf(distFileName, "%s/expDist.ckpt.%d.%d", EGIDA_DIST_DIR, 
	  freq, Egida::GetMyId());
  this->ifs.open(distFileName);
  if (!this->ifs) {
    std::cout << "Unable to open file: " << distFileName <<
      std::endl;
    assert(0);
  }
  this->timeToNextFlush = -1;
  // see the comment in schedule flush
  // this->ScheduleFlush();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Schedule the next flush by asking the Timer to generate
//      an interrupt.  Use the exponential distribution file to figure
//      out how many seconds have to elapse for the next timer interrupt.
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

void RandomFlushScheduler::ScheduleFlush() 
{
  int nextVal;

  if (this->frequency < 0)
    return;

  this->ifs >> nextVal;
  if ((this->ifs.eof()) || (this->ifs.fail())) {
    std::cout << "No distribution value for setting next flush!"
	      << std::endl;
    assert(0);
  }
  // by doing this, we maybe throwing away a flush scheduled BEFORE nextVal!
  Timer::SetTimer(nextVal);
  this->timeToNextFlush = nextVal;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Modify the frequency with which flushes are scheduled.
// 
// Arguments:
// 	freq --- desired flush frequency.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void RandomFlushScheduler::SetFlushFreq(int freq)
{
  char distFileName[EGIDA_FILENAME_LEN];

  this->frequency = freq;
  
  if (this->ifs.is_open()) {
    this->ifs.close();
  }
    
  sprintf(distFileName, "%s/expDist.ckpt.%d.%d", EGIDA_DIST_DIR, 
	  freq, Egida::GetMyId());
  this->ifs.open(distFileName);
  if (!this->ifs) {
    std::cout << "Unable to open file: " << distFileName <<
      std::endl;
    assert(0);
  }
  this->ScheduleFlush();
}
