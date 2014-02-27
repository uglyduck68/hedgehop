// EventLog.cc -- 
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
// $Log: EventLog.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:18  ravshank
// Start of Spring 2001
//
// Revision 1.7  2000/11/21 22:27:15  phoebe
// GarbageCollect in the SentStore is now working async. We changed the logic slightly so that all files are cleaned by one process and we clean when we've heard 3 responses (not necessarily all from different processes...this is ok we think.) Also...our favorite core dump on TakeCkpt (the memcpy one) has crept back in the picture. <grrrr>
//
// Revision 1.6  2000/11/10 15:48:53  phoebe
// Checkpoint memory leak is now solved, and so is the memcpy core dump on some checkpoints.
//
// Revision 1.5  2000/10/20 19:28:46  phoebe
// SentLog class is now integrated and works so protocols using the sentLog to store information will now restart on flushing.
//
// Revision 1.4  2000/10/17 15:02:30  phoebe
// Stable code checkin. RBP is extremely stable except if you kill the master and slave at exactly the same time....it will hang in ReplayDeliver. SBP cannot support concurrent failures due to the lost control messages or hanging in ReplayDeliver. Causal can do +concurrent+ failures as long as control messages are not lost....so the restart must be staggered. Causal seems to suffer the same RBP problem with a master/slave pair, but unsure if this is the problem or if I didn't set numfailures=2...think the later would fix this. All the sentLog protocols (SBP and Causal) suffer from processes dumping core during WriteCkpt if they have been running for a long time since we are not flushing volatile memory at the moment. Should go away with the proper sentLog class fix.
//
// Revision 1.3  2000/06/26 21:31:11  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.2  2000/06/23 16:35:33  phoebe
// Cleaning out un-needed data members in classes.
//
// Revision 1.1.1.1  2000/03/06 20:00:20  phoebe
// Sriram's original code with no modifications
//
// $Id: EventLog.cc,v 1.1.1.1 2001/02/12 00:00:18 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu May  6 23:19:05 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Jul 12 15:25:23 1999
// Update Count    : 53
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Event log---similar to determinant log

#include <assert.h>
#include "DeliveredStore.H"
#include "EventLog.H"
#include "SentStore.H"

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Constructor for a event log object.  Same old
// 	story---code doesn't compile if this method is in the header.
// 
// Arguments:
// 	self, numP --- usual args: id of this process and # of
//  	    processes in the system
//      eventStoreType --- one of Null, Volatile Store, Stable Store.
//      stableEventStoreType --- meaningful only if eventStoreType is Stable.
//      flushPolicy --- policy for flushing: INDEPENDENT or
//          COORDINATED
//      flushPolicyMsgTag --- tag that the flush policy object should
//          use for sending messages.
//      flushFreq --- freq. of asking event store to flush its
//          contents to stable storage.  If this is -1, data is never
//          flushed.
//      schedType --- PERIODIC or RANDOM
//
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

EventLog::EventLog(int self, int numP, 
		   EventStore::EventStoreType eventStoreType,
		   EventStore::EventStoreType stableEventStoreType,
		   FlushPolicy::FlushPolicyType flushPolicyType,
		   int flushPolicyMsgTag,
		   int flushFreq, 
		   FlushScheduler::FlushSchedulerType schedType)
{
  switch(flushPolicyMsgTag) {
  case EGIDA_DELIVERED_LOG_MSG:
    switch(eventStoreType) {
    case EventStore::EGIDA_NULL_STORE:
      this->eventStore = new NullEventStore(self, numP);
      break;
    case EventStore::EGIDA_VOLATILE_STORE:
      this->eventStore = new VolatileDeliveredStore(self, numP, stableEventStoreType);
      break;
    case EventStore::EGIDA_STABLE_STORE:
      this->eventStore = new StableDeliveredStore(self, numP);
      break;
    default:
      assert(0);
      break;
    }
    break;
  case EGIDA_SENT_LOG_MSG:
    switch(eventStoreType) {
    case EventStore::EGIDA_NULL_STORE:
      this->eventStore = new NullEventStore(self, numP);
      break;
    case EventStore::EGIDA_VOLATILE_STORE:
      this->eventStore = new VolatileSentStore(self, numP, stableEventStoreType);
      break;
    case EventStore::EGIDA_STABLE_STORE:
      this->eventStore = new StableSentStore(self, numP);
      break;
    default:
      assert(0);
      break;
    }
    break;
  default:
    assert(0);
    break;
  }

  switch(flushPolicyType) {
  case FlushPolicy::EGIDA_INDEP_FLUSH:
    this->flushPolicy = new IndepFlushPolicy(schedType, flushFreq);
    break;
  case FlushPolicy::EGIDA_COORD_FLUSH:
    this->flushPolicy = new CoordFlushPolicy(schedType, flushFreq);
    break;
  default:
    assert(0);
    break;
  }
  this->flushPolicy->SetFlushPolicyMsgTag(flushPolicyMsgTag);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Log an event info to storage.
// 
// Arguments:
// 	e --- pointer to a determinant structure.
//           The caller of this method SHOULD NOT keep a reference to
//           d after this method call.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void EventLog::Log(EventInfo *e)
{
  this->eventStore->Write(e);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Flush the contents of the event log to stable storage.
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
void EventLog::Flush()
{
  this->eventStore->Flush();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Fetch the eventInfo that matches procId, eventId
// 
// Arguments:
// 	<source, sourceEventId> --- event for which info has to be
// 	    read
//      otherProc --- other process involved in the event
//      eInfo --- output parameter
//
// Results:
// 	eInfo --- resulting pointer to event info.  The caller of this 
// 	   method SHOULD NOT delete eInfo.  It is possible that eInfo
// 	   may be NULL.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void EventLog::TryRetrieve(int source, int sourceEventId, 
			   int otherProc, EventInfo **eInfo)
{
  this->eventStore->TryRetrieve(source, sourceEventId, otherProc, eInfo);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Garbage collect event info from the eventStore.
// 
// Arguments:
// 	source, eventId: Discard event info created by source
// 	(info->source = source) and info->eventId < eventId.
//      Note that info->otherProc can be any other process.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void EventLog::GarbageCollect(int source, int eventId)
{
  this->eventStore->GarbageCollect(source, eventId);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Garbage collect event info from the eventStore.
// 
// Arguments:
// 	source, eventId: Discard event info created by source
// 	(info->source = source) and (info->eventId < eventId) and
//      (info->otherProc = otherProc).
//      otherProc is the other process involved in the event
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void EventLog::GarbageCollect(int source, int eventId, int otherProc)
{
  this->eventStore->GarbageCollect(source, eventId, otherProc);
}
// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Throw away determinants from the detStore.
// 
// Arguments:
// 	source, eventId: Discard eventInfo with e->source == source such that
// 	               e->sourceEventId >= eventId.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void EventLog::Purge(int source, int eventId)
{
  this->eventStore->Purge(source, eventId);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Front-end for eventStore's ckptDone method.
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

void EventLog::CkptDone()
{
  this->eventStore->CkptDone();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Change the default file name for the log file on a file system
// 
// Arguments:
// 	baseName --- base file name for the log on a file system
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void EventLog::SetLogFileName(const char *baseName)
{
  this->eventStore->SetLogFileName(baseName);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Set a callback function that has to be invoked whenever the
// 	log is written out to stable storage.
// 
// Arguments:
// 	stableCallback --- function to callback whenever the contents
// 	of the event log are flushed to stable storage.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void EventLog::SetLogStableCallback(void (*stableCallback)(int, int, 
							   int, int))
{
  this->eventStore->SetLogStableCallback(stableCallback);
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Set the frequency with which data in volatile log is flushed
// 	to stable storage.
// 
// Arguments:
// 	freq --- flush frequency in seconds.  If it is < 0, then, data 
// 	is never flushed out.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////
void EventLog::SetFlushFreq(int freq)
{
  this->flushPolicy->SetFlushFreq(freq);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Periodically flush the contents of volatile event store to
// 	stable storage.
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
void EventLog::TimerExpired()
{
  if (flushPolicy->NeedToFlush()) {
    eventStore->Flush();
    flushPolicy->ScheduleFlush();
  }
}

bool EventLog::NeedToFlush()
{
  if(flushPolicy->NeedToFlush())
    {
      flushPolicy->ScheduleFlush();
      return true;
    }
  return false;
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve data corresponding to the events that have to be
// 	replayed. 
// 
// Arguments:
// 	self --- id of this process
//      startEventId --- retrieve data d such that 
//         d.eventId >= startEventId
//      eventIds --- output parameter
// 
// Results:
//      If EventLog is a log delivered messages, then
// 	  eventIds --- a vector in which eventIds[i] is the id of the
// 	   last message m retrieved from stable storage, where m is a
// 	   message that process i sent to this process 
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void EventLog::Retrieve(int self, int startEventId, 
			int *eventIds)
{
  this->eventStore->Read(self, startEventId, eventIds);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve data corresponding to the event that has to be
// 	replayed. 
// 
// Arguments:
// 	self --- id of this process
//      eventId --- retrieve data d such that 
//           d.sourceEventId = eventId
//      otherProc --- other process that is involved in the event
//      eInfo --- output parameter
// 
// Results:
//      Returns a pointer to the matching event info in eInfo.  The
//      caller of this method SHOULD NOT free eInfo.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void EventLog::Retrieve(int self, int eventId,
			int otherProc, EventInfo **eInfo)
{
  this->eventStore->Read(self, eventId, otherProc, eInfo);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Retrieve eventInfo logged on behalf of recovering process.
// 
// Arguments:
// 	self --- id of this process
//      startEventId --- retrieve all event info (e.g., messages), e, such that
//           e.source = self, e.otherProc = recoveringProc and
//           e.sourceEventId >= startEventId
//      eInfo_List --- output parameter
//
// Results:
// 	eInfo_List --- a list of event info needed for the recovery of 
// 	the recoveringProc.  The caller of this method SHOULD ONLY
// 	call eInfo_List->clear(); the caller SHOULD NOT call delete on 
// 	any of the items in the list.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void EventLog::Retrieve(int self, int startEventId, int recoveringProc,
			EventInfo_List *eInfo_List)
{
  this->eventStore->Read(recoveringProc, self, startEventId, eInfo_List);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Remove any pointer's to eInfo from the event log.  This method 
// 	is used during replay---the message to be replayed is
// 	retrieved from the log and the pointer to that message (in the 
// 	log) is removed by this method call.  This is needed due to
// 	garbage collection---if the event log throws a message away,
// 	we don't want any other object in Egida to keep a pointer to
// 	the discarded message.  By removing the pointer to eInfo from
// 	the event log, it is now the responsibility of the caller to
// 	free the storage allocated for eInfo.
// 
// Arguments:
// 	eInfo --- object to which any pointers are in the event log
// 	have to be removed.
// 
// Results:
// 	NULL
// 
// Side Effects:
// 	NULL
// 
// /////////////////////////////////////////////////////////////////

void EventLog::RemovePtr(EventInfo *eInfo)
{
  this->eventStore->RemovePtr(eInfo);
}
// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Front-end for calling eventStore's RestartingFromCkpt method.
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
void EventLog::RestartingFromCkpt()
{
  this->eventStore->RestartingFromCkpt();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Front-end for calling eventStore's ReplayDone method.
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
void EventLog::ReplayDone()
{
  this->eventStore->ReplayDone();
}

// /////////////////////////////////////////////////////////////////
// // 
// Purpose:
// 	Handle messages sent by the flush policy object.
// 
// Arguments:
// 	source --- process that sent the message
//      tag --- better be EVENT_LOG_MSG
//      msg --- containes one of FLUSH_REQ or a FLUSH_ACK
//      msgSize --- size of the message.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void EventLog::ProcessMsg(int source, int tag, const char *msg, int msgSize)
{
  
  if (this->flushPolicy->ProcessMsg(source, msg, msgSize)) 
    this->eventStore->Flush();
}
