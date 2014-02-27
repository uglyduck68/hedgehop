// Init.cc -- 
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
// $Log: Init.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:16  ravshank
// Start of Spring 2001
//
// Revision 1.21  2000/11/01 16:35:30  phoebe
// Working on getting security to work again with the redesigned system. Message encryption, either full or only egida messages, is working now.
//
// Revision 1.20  2000/10/31 00:22:48  phoebe
// SBP now works with flushing and garbage collection. Before the file out pointers were not being managed properly so after a garbagecollect they were pointing to a non-existant file. So the point of all of this is we have a working SentStore.cc file.
//
// Revision 1.19  2000/10/12 19:50:57  phoebe
// Optimistic is still not working for more than one failure, but the incarnation number is now working correctly, and on the second failure it hangs in exactly the same spot every time. Also...optimistic is now rolling back a checkpoint file instead of doing the exec-ing that it was doing before. Additionally, during some of the debugging process, checkpoints are now shrinking heap sizes correctly (we thought they were doing it before, but they weren't.)
//
// Revision 1.18  2000/08/08 14:28:58  phoebe
// Can now restart multiple times and kill the master process for Receiver Based Pessimistic logging. Same thing for Sender Based, but with sender based since the recovery logs must be in volatile memory, it will eventually run out of RAM and won't be able to continue or restart (obviously). This is a protocol design bug that will be fixed, but the restart is stable. Also able to restart from an incremental checkpoint (tested with RBP). These restart tests were done without any security turned on.
//
// Revision 1.17  2000/06/27 13:23:10  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.16  2000/06/26 21:31:14  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.15  2000/06/26 16:57:00  phoebe
// Made all the Egida_Object methods and members static. Also moved GetMyId and GetNumProcs out of Egida_Internal and into Egida_Object.
//
// Revision 1.14  2000/06/26 14:56:05  phoebe
// More slight changes. Cleaned up Init.cc by moving path definitions to Egida_Globals.H. There are also some other small changes that I can't remember at the moment.
//
// Revision 1.13  2000/06/23 19:11:02  phoebe
// Moved all the egida object initialization from Init.cc into ProtocolPreInit and ProtocolPostInit methods.
//
// Revision 1.12  2000/06/23 18:48:09  phoebe
// Made Egida_Object_Init.cc a method of the Egida class. It's now called ProtocolSpecificInit.
//
// Revision 1.11  2000/06/23 15:13:52  phoebe
// Changed Egida_GetMyId() to use the egida object id instead of always polling p4. It will still poll p4 when egida is not initialized.
//
// Revision 1.10  2000/06/23 03:04:52  phoebe
// Changed the isInitialized data member in Egida_Object to a true boolean instead of the int that it used to be.
//
// Revision 1.9  2000/06/23 02:47:42  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.8  2000/06/23 00:18:11  phoebe
// Made namespace Egida_FailDetect into proper class called FailDetect.
//
// Revision 1.7  2000/06/23 00:01:06  phoebe
// Another name change...HandleMsgPoll and NullHandleMsgPoll are now MsgPoll and NullMsgPoll.
//
// Revision 1.6  2000/06/22 23:48:58  phoebe
// Changed some names: Egida_Msg_Queue is now MsgQueue and Egida_Msg is now Message. Also, changed the MsgQueue's in Egida_Object.H to be MsgQueue*'s so that it is consistent with all the other data members. One more thing...changed PbLog (and subclasses) to not require the CkptProtocol * for the object (so not a data member and not part of the Initialize method) since PbLog doesn't use this data member (it's used in PbCkpt).
//
// Revision 1.5  2000/06/22 22:23:07  phoebe
// Changed the Timer namespace to a proper class. Put all the global timers into Timer class as private data members.
//
// Revision 1.4  2000/06/22 20:59:07  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.3  2000/04/17 16:55:10  phoebe
// Rearranged Stats functions to do both Pre and Post Init (in init.cc) and now checkpoint encryption is working. Right now have Sriram's init file for optimistic which will only run for the short programs...this time it ran to completion on cg but it will not run to completion for sp.
//
// Revision 1.2  2000/03/07 00:10:45  phoebe
// Channel Encryption now working. Init now does Security::Init and Security::Reinit. Communication.cc modified to call security functions (obviously). Tested with normal run and restart of Egida_Object_Init-default.cc.
//
// $Id: Init.cc,v 1.1.1.1 2001/02/12 00:00:16 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun Apr 25 16:13:30 1999
// Last Modified By: Phoebe Weidmann
// Last Modified On: Thu Dec  9 10:36:05 CST 1999
// Update Count    : 192
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Functions to initialize and terminate Egida.

#include <iostream>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/utsname.h>

#include "Egida_API.h"

#include "DebugTrace.H"
#include "Egida_Object.H"
#include "EventHandler.H"
#include "FailDetect.H"
#include "PbCkpt.H"
#include "Security.H"
#include "Stats.H"
#include "Timer.H"



//input parameters
int _numFailures = 0;  //used in Egida_AppLoop.cc
int _failureIteration = -1; //used in Egida_AppLoop.cc
static int _flushLogIteration = -1;
static int _flushLogFreq = -1; //means never flush
static int _ckptFreq = 300; //value in seconds
static int _ckptAvoidThreshold = 0;


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Check if the command-line argument specifies that  the process state
// 	has to be rolled back to a previous checkpoint; in that case,
// 	use the checkpoint module to do the appropriate rollback.
// 
// Arguments:
// 	Command-line argc, argv
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void Egida_PreInit(int *argc, char ***argv)
{
  int i, fd, failureDetPort = -1;
  int incrEnd = -1;
  //  bool rollback = false;
  bool failed = false;
  char *p, *masterCheckpointFile = NULL;

  // so that std::cout will work with stdio
  std::cout.sync_with_stdio();

  for (i = 0; i < *argc; i++) {
    if (strncmp((*(argv))[i], "-recover", strlen("-recover")) == 0) {
      //this process actually failed as opposed to being rolled back
      p = rindex((*(argv))[i], '=');
      p++; /* start at the file name */
      masterCheckpointFile = p;
      std::cout << "argv[i]: " << (*(argv))[i] << std::endl;
      failed = true;
    }

    else if (strncmp((*(argv))[i], "-incrEnd", strlen("-incrEnd"))
	     == 0) {
      // this argument is needed by the checkpoint restore function
      p = rindex((*(argv))[i], '=');
      p++; /* start at the file name */
      incrEnd = atoi(p);
    }
  }

  if (masterCheckpointFile) {
    Security::ReInit();

    // if i don't do this here, the thing hangs...
    Communication::Reconnect();
    // so that libc corresponding fork is mapped back in
    if ((i = fork()) == 0) {
      std::cout << "fork in child succeeded... " << std::endl;
      _exit(0);
    }
    else {
      // wait for the forked child to terminate
      waitpid(i, &fd, 0);
    }

    std::cout << "restarting from checkpoint file: " <<
      masterCheckpointFile << std::endl;

    EventHandler::Failure(masterCheckpointFile, !failed);
    /* we will never get back here */
  }
  else {
    Security::Init();
  }

  if(COLLECTING_STATS) {
    Stats::PreInit();
  }
  
  Timer::AppStart();
  
  // THIS HAS TO BE DONE HERE!!!
  FailDetect::Setup_FailureDetector(**argv);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Initialize Egida variables.
// 
// Arguments:
// 	Command-line argc, argv
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	Uses a p4-function to eliminate command-line arguments that
// 	were consumed by this function.
// 
// /////////////////////////////////////////////////////////////////

void Egida_PostInit(int *argc, char ***argv)
{
  int i;
  char **str;
  char *p;
  int myId, numProcs;
  struct timeval endTime;
  double timeSpent;

  for (i = 0; i < *argc; i++) {
    str = (*argv) + i;
    std::cout << "input argument: " << *str << std::endl;
    if (!(str && *str))
      continue;
    if (strncmp(*str, "-numFailures", strlen("-numFailures")) == 0) {
      p = rindex(*str, '=');
      p++; /* start at the file name */
      _numFailures = atoi(p);
      std::cout << "numFailures: " << _numFailures << std::endl;
      *str = 0;
    }
    else if (strncmp(*str, "-failureIteration",
		     strlen("-failureIteration")) == 0) {
      p = rindex(*str, '=');
      p++; /* start at the freq # */
      _failureIteration = atoi(p);
      *str = 0;
    }
    else if (strncmp(*str, "-flushLogIteration",
		     strlen("-flushLogIteration")) == 0) {
      p = rindex(*str, '=');
      p++; /* start at the freq # */
      _flushLogIteration = atoi(p);
      *str = 0;
    }
    else if (strncmp(*str, "-flushLogFreq",
		     strlen("-flushLogFreq")) == 0) {
      p = rindex(*str, '=');
      p++; /* start at the freq # */
      _flushLogFreq = atoi(p);
      *str = 0;
    }
    else if (strncmp(*str, "-ckptFreq",
		     strlen("-ckptFreq")) == 0) {
      p = rindex(*str, '=');
      p++; /* start at the freq # */
      _ckptFreq = atoi(p);
      *str = 0;
    }
    else if (strncmp(*str, "-ckptAvoidThreshold",
		     strlen("-ckptAvoidThreshold")) == 0) {
      p = rindex(*str, '=');
      p++; /* start at the threshold value */
      _ckptAvoidThreshold = atoi(p);
      *str = 0;
    }
  }
  MPID_ArgSqueeze(argc, *argv);

  Timer::BlockTimerInterrupt();

  myId = Communication::GetProcessId();
  numProcs = Communication::GetNumberOfProcesses();

  if(COLLECTING_STATS) {
    Stats::PostInit(*argv[0], _ckptFreq, _ckptAvoidThreshold, 
		    _numFailures, _failureIteration, myId, numProcs);  
  }

  Timer::Initialize();
  Communication::Initialize();
  DebugTrace::Initialize(myId);

  Egida::ProtocolPreInit(myId, numProcs, *argv[0]);
  Egida::ProtocolSpecificInit(_flushLogFreq, _ckptFreq, _numFailures);
  Egida::ProtocolPostInit(_ckptAvoidThreshold);

  Timer::UnblockTimerInterrupt();

  Egida::TakeCkpt();

  if (Egida::FailedOnce()) {
    // the only way control executes inside here is if the state is
    // reset from a checkpoint
    Timer::RollForwardStart();
  }

  std::cout << "Protocol init done for process " << myId << std::endl;
  std::cout.flush();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Cleanup all Egida data structures when the application
// 	terminates.
// 
// Arguments:
// 	NONE
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	Turns off any pending SIGALRM's.
// 
// /////////////////////////////////////////////////////////////////


void Egida_Terminate()
{
  if (!Egida::IsInitialized())
    // We were never initialized.  So, just return
    return;

  // cancel any pending alarms
  Timer::Terminate();

  //stop the application timer BEFORE calling Stats::Dump()
  Timer::AppEnd();

  if(COLLECTING_STATS) {
    Stats::Dump();
  }

  FailDetect::Terminate();

  // This is a problem with volatile memory based stuff
  Communication::DrainMsgs();
  sleep(5);
  Communication::DrainMsgs();  
  Communication::Terminate();

  Security::Terminate();

  Egida::Terminate();

  std::cout << "Egida has terminated on process " << Egida::GetMyId() << std::endl;

}








