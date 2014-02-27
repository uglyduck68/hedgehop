// EventStore.cc -- 
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
// $Log: EventStore.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:18  ravshank
// Start of Spring 2001
//
// Revision 1.21  2000/11/21 22:27:16  phoebe
// GarbageCollect in the SentStore is now working async. We changed the logic slightly so that all files are cleaned by one process and we clean when we've heard 3 responses (not necessarily all from different processes...this is ok we think.) Also...our favorite core dump on TakeCkpt (the memcpy one) has crept back in the picture. <grrrr>
//
// Revision 1.20  2000/11/15 22:12:30  phoebe
// Sanity check.
//
// Revision 1.19  2000/11/10 15:48:53  phoebe
// Checkpoint memory leak is now solved, and so is the memcpy core dump on some checkpoints.
//
// Revision 1.18  2000/10/20 19:28:47  phoebe
// SentLog class is now integrated and works so protocols using the sentLog to store information will now restart on flushing.
//
// Revision 1.17  2000/10/17 15:02:31  phoebe
// Stable code checkin. RBP is extremely stable except if you kill the master and slave at exactly the same time....it will hang in ReplayDeliver. SBP cannot support concurrent failures due to the lost control messages or hanging in ReplayDeliver. Causal can do +concurrent+ failures as long as control messages are not lost....so the restart must be staggered. Causal seems to suffer the same RBP problem with a master/slave pair, but unsure if this is the problem or if I didn't set numfailures=2...think the later would fix this. All the sentLog protocols (SBP and Causal) suffer from processes dumping core during WriteCkpt if they have been running for a long time since we are not flushing volatile memory at the moment. Should go away with the proper sentLog class fix.
//
// Revision 1.16  2000/09/27 22:03:07  phoebe
// In CkptImpl changed the growing of the heap from a strict monotonically increasing function (using the check that we only grow if size is less than what is needed) to one that can shrink. The reason we can do this is sbrk will take as an argument a negative value, where as malloc cannot.
//
// Revision 1.15  2000/08/17 21:11:19  phoebe
// Optimistic protocol is now running to completion, but it's still not totally proper in that it still will only recover if we avoid the flush race condition.
//
// Revision 1.14  2000/08/09 15:32:52  phoebe
// Changed the buffer size in CkptImpl.cc to be a #define instead of being hardwired to 4096. Also made fix in DetStore.cc and EventStore.cc that will allow both writing dets one at at time and in lists to be viable when hashing is turned on. Before this would have caused problems.
//
// Revision 1.13  2000/08/08 20:57:16  phoebe
// Cleaned up code, and now the never checkpointing again after a fail error is fixed.
//
// Revision 1.12  2000/08/08 14:28:56  phoebe
// Can now restart multiple times and kill the master process for Receiver Based Pessimistic logging. Same thing for Sender Based, but with sender based since the recovery logs must be in volatile memory, it will eventually run out of RAM and won't be able to continue or restart (obviously). This is a protocol design bug that will be fixed, but the restart is stable. Also able to restart from an incremental checkpoint (tested with RBP). These restart tests were done without any security turned on.
//
// Revision 1.11  2000/07/13 16:47:45  phoebe
// Established that the changes I made to EventStore.cc are not the causes of the failing to restart multiple times or the failing to restart from an incremetal checkpoint. So I got rid of the commented out code from the file.
//
// Revision 1.10  2000/06/27 13:23:06  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.9  2000/06/23 16:35:34  phoebe
// Cleaning out un-needed data members in classes.
//
// Revision 1.8  2000/06/23 02:47:39  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.7  2000/06/22 20:59:05  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.6  2000/06/02 22:43:05  phoebe
// Added Encryption and Hash and Sign handling to PurgeDetsOnDisk subroutine in DetStore.cc but when testing on cg.B.4 with SBP logging it ran out of memory (the famous p4_shmalloc error)...so need to figure out where the leak is.
//
// Revision 1.5  2000/06/02 19:55:08  phoebe
// The code now compiles with the Encryption and the Hash and Sign functionality added to EventStore's PurgeOnDisk subroutine. Still need to test that it will run, and need to add same functionality to DetStore.cc
//
// Revision 1.4  2000/06/02 05:47:26  phoebe
// Hash and Sign of EventInfo working and it will restart and check fine. I think the modification I made to EventInfo for Reads (it's commented as a change in the code...I used << and >> instead of the commented out code) is preventing restart. Need to make sure I understand what is going on with that later.
//
// Revision 1.3  2000/06/02 04:13:16  phoebe
// Encryption of EventInfo now working.
//
// Revision 1.2  2000/03/07 16:58:36  phoebe
// Got optimistic logging to restart, although I really don't understand what it is doing since it seems to be rolling back all processes. To get optimistic logging to restart I had to catch a ofs==NULL error in EventStore.cc
//
// Revision 1.1.1.1  2000/03/06 20:00:20  phoebe
// Sriram's original code with no modifications
//
// $Id: EventStore.cc,v 1.1.1.1 2001/02/12 00:00:18 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu May  6 23:28:34 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu Aug 26 10:40:51 1999
// Update Count    : 212
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <assert.h>
#include <errno.h>
#include <iostream>
#include <strstream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "EventInfo.H"
#include "EventStore.H"
#include "Globals.H"

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Constructor for the event store object.
// 
// Arguments:
//      The two have the usual meaning.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
EventStore::EventStore(int self, int numP)
{
  this->id = self;
  this->numProcs = numP;
  this->LogStableCallback = NULL;
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Method for logging event info to storage.
// 
// Arguments:
// 	d --- pointer to the event info that has to be added.  After
// 	this method call, the caller SHOULD NOT refer to d.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void NullEventStore::Write(EventInfo *eInfo)
{
  // since there is nothing to log, just free the stuff.
  delete eInfo;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve a previously logged event info.  This is needed for
// 	causal protocols which log sent messages and retrieve a
// 	message header as part of ack processing.
// 
// Arguments:
// 	<source, sourceEventId> --- event for which info has to be
// 	    read
//      otherProc --- other process involved in the event
//      eInfo --- output parameter
// 
// Results:
// 	eInfo --- resulting pointer to event info.  The caller of this 
// 	method SHOULD NOT delete eInfo.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void NullEventStore::TryRetrieve(int source, int sourceEventId, 
				 int otherProc, EventInfo **eInfo)

{
  *eInfo = NULL;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve data corresponding to the events that have to be
// 	replayed. 
// 
// Arguments:
// 	source --- id of the process which created the eInfo's that
// 	   have to be read back.
//      startEventId --- retrieve data d from stable store such that 
//         d.eventId >= startEventId
//      lastEventIds --- output parameter
// 
// Results:
// 	  lastEventIds --- a vector in which lastEventIds[i] is the id of the
// 	   last message m retrieved from stable storage, where m is a
// 	   message that process i sent to this process 
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void NullEventStore::Read(int source, int startEventId,
			  int *lastEventIds)
{
  memset(lastEventIds, 0, EGIDA_MAX_PROCS * sizeof(int));
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve the data corresponding to a determinant which has to
// 	be replayed.
// 
// Arguments:
// 	source --- process that created the eInfo 
//      sourceEventId --- event id corresponding to the data that has
//             be read back.
//      otherProc --- other process involved in the event.
//      eInfo --- output parameter
//
// Results:
// 	eInfo --- is a pointer to the matching event info that has
// 	been retrieved.  The caller SHOULD NOT free eInfo.  The only
// 	exception to this requirement is that, after this method call, 
// 	the caller SHOULD CALL RemovePtr() method exported by this object.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void NullEventStore::Read(int source, int sourceEventId,
			  int otherProc, EventInfo **eInfo)
{
  *eInfo = NULL;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve data logged on behalf of otherProc.  Needed when
// 	Egida is helping otherProc's recovery.  For instance, if the
// 	event store is keeping a log of sent messages, this call
// 	retrieves all the messages sent by source to otherProc.
// 
// Arguments:
// 	otherProc --- process for whom data has been logged.
//      source --- process that created the eventInfo
//      startEventId --- retrieve beginning from this event id of
//                       source
//      retrieve_List --- output parameter
// 
// Results:
// 	retrieve_List --- list of retrieved event info.  The caller
// 	SHOULD NOT delete the elements of the list.  The caller is
// 	only allowed to call retrieve_List.erase() on the elements of
// 	the list.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void NullEventStore::Read(int otherProc, int source, int startEventId,
			  EventInfo_List *retrieve_List)
{

}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve event info. for replay phase of recovery.
// 
// Arguments:
//      source --- retrieve event info created by process source
// 	startEventId --- retrieve event info d such that
//           (d.source = source) && (d.eventId >= startEventId)
//      lastEventIds --- output parameter and is a vector size EGIDA_MAX_PROCS
//      retrieve_List --- output parameter
// 
// Results:
// 	lastEventIds --- lastEventIds[i] is the index of the last
// 	    message process i sent to procId that is available from
// 	    storage.
//      retrieve_List --- since nothing is logged, this is list is unaffected.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void NullEventStore::Read(int source, int startEventId,
			  int *lastEventIds, EventInfo_List *retrieve_List)
{
  memset(lastEventIds, 0, EGIDA_MAX_PROCS * sizeof(int));
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Remove any pointer's to eInfo from the event store.
// 
// Arguments:
// 	eInfo --- object to which any pointers are in the event store
// 	have to be removed.
// 
// Results:
// 	NULL
// 
// Side Effects:
// 	NULL
// 
// /////////////////////////////////////////////////////////////////
void NullEventStore::RemovePtr(EventInfo *eInfo)
{
  
}

int NullEventStore::WriteEvInfoList(int source, EventInfo_List &el)
{
#if cvr
  if(el.size() <= 0)
    return -1;

  EventInfo * eInfo = el.back();
  return eInfo->sourceEventId;
#endif

  //  std::cout << "In NULL :: WriteEvInfoList" << std::endl;
  return 0;
}
