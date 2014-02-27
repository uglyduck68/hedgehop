// Egida_AppLoop.cc -- 
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
// $Log: Egida_AppLoop.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:18  ravshank
// Start of Spring 2001
//
// Revision 1.15  2000/11/10 15:48:50  phoebe
// Checkpoint memory leak is now solved, and so is the memcpy core dump on some checkpoints.
//
// Revision 1.14  2000/09/27 22:03:05  phoebe
// In CkptImpl changed the growing of the heap from a strict monotonically increasing function (using the check that we only grow if size is less than what is needed) to one that can shrink. The reason we can do this is sbrk will take as an argument a negative value, where as malloc cannot.
//
// Revision 1.13  2000/08/17 21:11:18  phoebe
// Optimistic protocol is now running to completion, but it's still not totally proper in that it still will only recover if we avoid the flush race condition.
//
// Revision 1.12  2000/06/27 13:23:00  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.11  2000/06/26 21:31:07  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.10  2000/06/26 16:56:54  phoebe
// Made all the Egida_Object methods and members static. Also moved GetMyId and GetNumProcs out of Egida_Internal and into Egida_Object.
//
// Revision 1.9  2000/06/26 14:56:01  phoebe
// More slight changes. Cleaned up Init.cc by moving path definitions to Egida_Globals.H. There are also some other small changes that I can't remember at the moment.
//
// Revision 1.8  2000/06/23 00:18:08  phoebe
// Made namespace Egida_FailDetect into proper class called FailDetect.
//
// Revision 1.7  2000/06/22 22:23:04  phoebe
// Changed the Timer namespace to a proper class. Put all the global timers into Timer class as private data members.
//
// Revision 1.6  2000/06/22 20:58:59  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.5  2000/06/22 16:18:07  phoebe
// In Egida_Object_Init.cc make sure the new for the NullOrphanDetection had the () at the end of the method. Also, turned on the Loop Counters in Egida_AppLoop.cc file.
//
// Revision 1.4  2000/04/17 21:11:57  phoebe
// Pretty-printed Statistics going to file to be more readable. Seems that Incremental checkpoint count always includes the full checkpoint because of the weird interdependence between Incr and Full ckpt class. Other than that all of the stats now make more sense.
//
// Revision 1.3  2000/04/17 16:55:08  phoebe
// Rearranged Stats functions to do both Pre and Post Init (in init.cc) and now checkpoint encryption is working. Right now have Sriram's init file for optimistic which will only run for the short programs...this time it ran to completion on cg but it will not run to completion for sp.
//
// Revision 1.2  2000/04/11 19:49:35  phoebe
// pound defined the loop iteration print statement off.
//
// Revision 1.1.1.1  2000/03/06 20:00:18  phoebe
// Sriram's original code with no modifications
//
// $Id: Egida_AppLoop.cc,v 1.1.1.1 2001/02/12 00:00:18 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun Aug 15 16:12:54 1999
// Last Modified By: Sriram Rao
// Last Modified On: Fri Aug 20 16:26:05 1999
// Update Count    : 26
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Methods to track loops executed by applications.

#include <stdlib.h>
#include <unistd.h>

#include "Egida_API.h"

#include "Communication.H"
#include "Egida_Object.H"
#include "FailDetect.H"
#include "Stats.H"
#include "Timer.H"

//global variables
static int  _numLoopIterationsDone = 0;
extern int _failureIteration, _numFailures;


#define TURN_LOOP_COUNTERS_ON 1

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	For applications that are structured using loops, this
// 	function is used to track when a new iteration starts.  The
// 	function with the _ is used for name resolution when programs
// 	are compiled with f77.
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

void egida_apploopstart_ ( )
{
  Egida_AppLoopStart();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	For applications structured using loops, this function tracks
// 	when a new loop iteration starts.  This function can be used
// 	to crash the application process after completion of a
// 	pre-determined number of iterations.
// 
// Arguments:
// 	NONE
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	Updates the global variable _numLoopIterationsDone.
//      When logs are to be written out after completion of a
//      pre-determined loop iterations, then, this function calls
//      WriteOutLogs().
// 
// /////////////////////////////////////////////////////////////////

void Egida_AppLoopStart(void)
{
  double timeSpent = 0.0;
  int needToFail = 0;
  int myId;
  struct timeval startTime, endTime;
  

  Timer::BlockTimerInterrupt();

#if 0
  if (_numLoopIterationsDone == 0) {
    // do this only for cg, mg
    Egida::TakeCkpt();
    Stats::Reset();
    _numLoopIterationsDone++;
    return;
  }
#endif

  _numLoopIterationsDone++;

  myId = Egida::GetMyId();


#if TURN_LOOP_COUNTERS_ON
  timeSpent = Timer::CurrentElapsedTime();
  printf("\n %d loop #: %d, timeSpent = %lf \n",
	 myId, _numLoopIterationsDone - 1, timeSpent);
  fflush(stdout);
#endif


  if ((1 <= myId) && (myId <= _numFailures))
    needToFail = 1;

  if (_numLoopIterationsDone == _failureIteration) {
    if (_numFailures > 0)
      Egida::DisableTimer();

    if (needToFail) {
      Egida::InternallyFail();

      // If control reaches here, then, the process has crashed once
      // and has recovered to the same point at which a failure
      // occurred.
      
      Timer::RollForwardEnd();
      timeSpent = Timer::RollForwardTimeSpent();
      Stats::Update(EGIDA_RECOVERY_ROLL_FORWARD_STAT, 0, timeSpent);
      Stats::Dump();
    }
    else if (Egida::FailedOnce()) {
      Stats::Dump();
    }
  }

  if ((_failureIteration >= 0) &&
      (_numLoopIterationsDone > _failureIteration)) {
    printf("\n recovery is done.  terminating... \n");
    fflush(stdout);

    FailDetect::Terminate();

    // clean out the sockets for 15 seconds---in case other processes 
    // haven't terminated
    gettimeofday(&startTime, NULL);
    while (1) {
      Communication::DrainMsgs();
      gettimeofday(&endTime, NULL);
      Timer::ComputeTimeDiff(&timeSpent, startTime, endTime);
      if (timeSpent > 15.0)
	break;
    }
    // exit so that we can kill others too...
    _exit(0);
  }

  Timer::UnblockTimerInterrupt();
}

