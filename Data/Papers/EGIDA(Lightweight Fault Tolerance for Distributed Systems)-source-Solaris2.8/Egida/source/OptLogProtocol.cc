// OptLogProtocol.cc -- 
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
// $Log: OptLogProtocol.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:17  ravshank
// Start of Spring 2001
//
// Revision 1.9  2000/10/12 19:50:57  phoebe
// Optimistic is still not working for more than one failure, but the incarnation number is now working correctly, and on the second failure it hangs in exactly the same spot every time. Also...optimistic is now rolling back a checkpoint file instead of doing the exec-ing that it was doing before. Additionally, during some of the debugging process, checkpoints are now shrinking heap sizes correctly (we thought they were doing it before, but they weren't.)
//
// Revision 1.8  2000/10/03 22:56:24  phoebe
// Optimistic will now reliably restart once. Still fails multiple sequential failures.
//
// Revision 1.7  2000/09/29 00:20:13  phoebe
// Optimistic will now recover from the first failure...but not multiple sequential failures.
//
// Revision 1.6  2000/09/27 22:03:10  phoebe
// In CkptImpl changed the growing of the heap from a strict monotonically increasing function (using the check that we only grow if size is less than what is needed) to one that can shrink. The reason we can do this is sbrk will take as an argument a negative value, where as malloc cannot.
//
// Revision 1.5  2000/06/26 21:31:16  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.4  2000/06/26 19:09:54  phoebe
// Removed all wrapper methods out of Egida_Internal.cc and renamed calls in code to directly call the Egida::Method that would have been called by the Egida_Method call.
//
// Revision 1.3  2000/06/23 02:47:44  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.2  2000/06/22 23:49:00  phoebe
// Changed some names: Egida_Msg_Queue is now MsgQueue and Egida_Msg is now Message. Also, changed the MsgQueue's in Egida_Object.H to be MsgQueue*'s so that it is consistent with all the other data members. One more thing...changed PbLog (and subclasses) to not require the CkptProtocol * for the object (so not a data member and not part of the Initialize method) since PbLog doesn't use this data member (it's used in PbCkpt).
//
// Revision 1.1.1.1  2000/03/06 20:00:22  phoebe
// Sriram's original code with no modifications
//
// $Id: OptLogProtocol.cc,v 1.1.1.1 2001/02/12 00:00:17 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Wed May  5 16:36:20 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu Aug 26 09:43:09 1999
// Update Count    : 77
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Implementation of Damani and Garg's protocol from their
// 	ICDCS'96 paper.

#include <assert.h>
#include <iostream>
#include <strstream>

#include "Egida_Object.H"
#include "OptLogProtocol.H"

void PbVectorClock::Initialize(MsgQueue *q,
			       DetLog *detl, EventLog *sl, EventLog *dl)
{
  PbLog::Initialize(q, detl, sl, dl);
  this->rolledback = false;
}


void PbVectorClock::GetPiggyback(int dest, char **pb, int *pbSize)
{
  std::ostrstream os;

  os << this->ftvc << std::ends;
  *pb = os.str();
  *pbSize = os.pcount();
}

bool PbVectorClock::ProcessPiggyback(int source, int ssn, char *pb,
				      int pbSize)
{
  std::istrstream is(pb, pbSize);
  VectorClock msgVC;

  is >> msgVC;

  if (!this->ObsoleteMsgVC(msgVC)) {

    // Wrong comment mostly
    // The updates were called so far before the logging of the delivered
    // message. I think they should be called after the messages are logged in
    // logDeliveredMessage(). So, now am moving out the updates to a diff
    // function

    this->UpdateVC(msgVC);
    this->UpdateHistory(msgVC);
    return true;
  }
  //got obsolete message
  return false;
}

void PbVectorClock::PreCkptActions()
{
  int i;
  History_ListIterator e;
  HistoryEntry *h;

  this->lastCkptVC = this->ftvc;
  for (i = 0; i < this->numProcs; i++) {
    for (e = this->history[i].begin(); e != this->history[i].end();
	 ++e) {
      h = *e;
      this->lastCkptHistory[i].push_back(new HistoryEntry(*h));
    }
  }
}


void PbVectorClock::CleanUpCkptFiles(char * ckptFileName)
{
  //need to find recovery line and then remove appropriate
  //  older ckpt files.
}


// Need to garbage collect the logs on disk...
void PbVectorClock::PostCkptActions(const char *ckptFileName, 
				     int stableEventId)
{
  int i;
  std::ofstream ofs;
  char fileName[EGIDA_FILENAME_LEN];

  // Looks like nobody is using the following 4 lines
#if 0
  this->stableState[this->id] = this->lastCkptVC[this->id];
  this->ckptNameVC_List.push_back(new
				  CkptNameVCEntry(this->lastCkptVC, 
						  ckptFileName));
#endif // if 0

  sprintf(fileName, "%s/ckpt.history.%d", EGIDA_LOGS_DIR, this->id);
  ofs.open(fileName, std::ios::app);

  ofs << ckptFileName << std::endl;
  for (i = 0; i < this->numProcs; i++) {
    this->WriteFreeHistoryList(ofs, this->lastCkptHistory[i]);
    this->lastCkptHistory[i].clear();
  }
  ofs.flush();
  ofs.close();
}

void PbVectorClock::PreReplayActions(int startEsn, bool rb)
{
  // This is necessary because the timer can wake up right in the middle of
  // the roll forward and this can happen because the disableTimer flag is
  // set to false initially and all the other protocols expect it to be
  // set to false except Optimistic
  Egida::DisableTimer();

  this->rolledback = rb;
  // read the tokens
  ReadTokens();
  // Compute the recoverable state
  ComputeRecoverableState(startEsn);
  RecallIncarnationNumber();
  if (!this->rolledback) {
    AddToken(this->id, this->recoverableState[this->id]);
  }
}

void PbVectorClock::RecallIncarnationNumber()
{
  std::ifstream ifs;
  char fileName[EGIDA_FILENAME_LEN];
  int epoch = 0;

  sprintf(fileName, "%s/epoch.number.%d", EGIDA_LOGS_DIR, this->id);
  ifs.open(fileName, std::ios::in);
  ifs >> epoch;
  ifs.close();

  this->ftvc[this->id].incarnation = epoch;
  this->recoverableState[this->id].incarnation = epoch;
}

void PbVectorClock::RecordIncarnationNumber()
{
  std::ofstream ofs;
  char fileName[EGIDA_FILENAME_LEN];

  sprintf(fileName, "%s/epoch.number.%d", EGIDA_LOGS_DIR, this->id);
  ofs.open(fileName, std::ios::out);
  ofs << this->ftvc[this->id].incarnation;
  ofs.close();
}

void PbVectorClock::PostReplayActions()
{
  if (!this->rolledback) {
    this->ftvc[this->id].incarnation++;
    RecordIncarnationNumber();
    this->ftvc[this->id].stateInterval = 0;
    std::cout << this->id << "updated vc: " << this->ftvc[this->id] << std::endl;
  }

  this->rolledback = false;

  // log all messages from here onwards
  memset(this->avoidLoggingMsg, 0, EGIDA_MAX_PROCS * sizeof(int));
  memset(this->lastAckRecd, 0, EGIDA_MAX_PROCS * sizeof(int));
  std::cout << Egida::GetMyId() << ": Done with PostReplayActions" << std::endl;
}

bool PbVectorClock::NeedToDetectOrphans()
{
  // If this process is about to rollback, then,
  // there is no need to do orphan detection.
  // Only a failed process needs to detect orphans.
  if (this->rolledback) {
    return false;
  }
  return true;
}

void PbVectorClock::AddToken(int recoveringProc, 
			      const VCComponent &lc)
{
  HistoryEntry *h;
  History_ListIterator e;
  char fileName[EGIDA_FILENAME_LEN];
  std::ofstream tokenLogFs;

  // check if we already have this token.
  for (e = this->history[recoveringProc].begin(); 
       e != this->history[recoveringProc].end(); ++e) {
    h = *e;
    if ((h->token) && (h->comp == lc))
      // duplicate
      return;
  }

  h = new HistoryEntry(1, lc);
  this->history[recoveringProc].push_back(h);

  std::cout << "adding token: " << recoveringProc << ' ' << *h << std::endl;
  
  // The token has to be synchronously logged to stable storage;
  sprintf(fileName, "%s/tokenLog.%d", EGIDA_LOGS_DIR, this->id);
  tokenLogFs.open(fileName, std::ios::app);
  tokenLogFs << recoveringProc << ' ' << *h << std::endl;
  tokenLogFs.flush();
  tokenLogFs.close();

}

void PbVectorClock::ReadTokens()
{
  char fileName[EGIDA_FILENAME_LEN];
  std::ifstream tokenLogFs;
  HistoryEntry h, *h1;
  History_ListIterator e;
  int procId;
  bool found;

  // read the tokens back...
  sprintf(fileName, "%s/tokenLog.%d", EGIDA_LOGS_DIR, this->id);
  tokenLogFs.open(fileName, std::ios::in);
  if (tokenLogFs.is_open())
    while (1) {
      tokenLogFs >> procId;
      if ((tokenLogFs.fail() ) || (tokenLogFs.eof()))
	break;
      tokenLogFs >> h;
      found = false;
      for (e = this->history[procId].begin(); e !=
	     this->history[procId].end(); ++e){
	h1 = *e;
	if ((h1->token) && (h1->comp == h.comp)) {
	  found = true;
	  break;
	}
      }
      if (!found) {
	this->history[procId].push_back(new HistoryEntry(h));
      }
    }
  tokenLogFs.close();
}

void PbVectorClock::ComputeRecoverableState(int startEsn)
{
  int lastEsn;
  Determinant *matchingDet, *lastReplayedDet = NULL;
  EventInfo *eInfo, *lastReplayedMsg = NULL;
  char *pbLog;
  int pbLogSize;
  VectorClock restoredVC, msgVC;
  
  lastEsn = startEsn;
  restoredVC = this->ftvc;
  while (1) {
    if (!this->detLog->GetNextDet(this->id, lastEsn, &matchingDet))
      break;
    this->deliveredLog->Retrieve(this->id, matchingDet->d_esn,
				 matchingDet->source, &eInfo);
    if (eInfo == NULL) {
      // We have a determinant, but not the corresponding message.
      // Hence, throw away that determinant.
      this->detLog->Purge(this->id, matchingDet->d_esn);
      break;
    }

    Egida::FetchPiggybackLog(eInfo->pb, &pbLog, &pbLogSize);
    {
      std::istrstream is(pbLog, pbLogSize);

      is >> msgVC;
      if (!this->ObsoleteMsgVC(msgVC)) {
	this->UpdateVC(msgVC);
	lastReplayedDet = matchingDet;
	lastReplayedMsg = eInfo;
      }
      else
	break;
    }
    lastEsn = matchingDet->d_esn + 1;
  }

  if (lastReplayedDet) {
    this->deliveredLog->Purge(this->id, lastReplayedDet->d_esn + 1);
    this->detLog->Purge(this->id, lastReplayedDet->d_esn + 1);
  }
  this->recoverableState = this->ftvc;
  this->ftvc = restoredVC;
}

void PbVectorClock::GetRecoverableState(VCComponent *lc) const
{
  *lc = this->recoverableState[this->id];
}


void PbVectorClock::ProcessFailureAnnouncement(int recoveringProc, 
						const VCComponent &lc)
{
  this->AddToken(recoveringProc, lc);
}

bool PbVectorClock::IsDeliverable(int source, int ssn, char *pb, int
				  pbSize)
{
  std::istrstream is(pb, pbSize);
  VectorClock msgVC;

  is >> msgVC;

  // don't deliver obsolete messages
  return (!this->ObsoleteMsgVC(msgVC));
}

bool PbVectorClock::IsOrphan(int recoveringProc, 
			      const VCComponent &lc)
{
  History_ListIterator e;
  HistoryEntry *h;
  
  // although doing a plain comparison of lc's will work, the paper by 
  // damani recommends that the history mechanism be used.  the
  // problem is that a failure annoucncement message may show up
  // BEFORE a message containing the updated lc shows up.
  
  for (e = this->history[recoveringProc].begin(); 
       e != this->history[recoveringProc].end(); ++e) {
    h = *e;
    if ((!h->token) && (h->comp.incarnation == lc.incarnation) &&
	(h->comp.stateInterval > lc.stateInterval)) {
      // !token means a message.  the last message we have delivered
      // has a timestamp *later* than the recovered state of
      // source.  Hence, we are an orphan.
      this->ComputeRollbackFile(recoveringProc, lc);
      return true;
    }
  }
  return false;
}

void PbVectorClock::ComputeRollbackFile(int recoveringProc, 
					 const VCComponent &lc)
{
  char ckptHistoryFile[EGIDA_FILENAME_LEN];
  char newCkptHistoryFile[EGIDA_FILENAME_LEN];
  char ckptFilename[EGIDA_FILENAME_LEN];
  int i;
  History_List historyList;
  History_ListIterator e;
  HistoryEntry *h;
  std::ifstream ifs;
  std::ofstream ofs;

  // although doing a plain comparison of lc's will work, the paper by 
  // damani recommends that the history mechanism be used.  the
  // problem is that a failure annoucncement message may show up
  // BEFORE a message containing the updated lc shows up.

  sprintf(ckptHistoryFile, "%s/ckpt.history.%d", EGIDA_LOGS_DIR,
	  this->id);
  ifs.open(ckptHistoryFile, std::ios::in);
  assert(ifs.is_open());
  while (1) {
    ifs >> ckptFilename;
    if ((ifs.fail()) || (ifs.eof()))
      break;
    for (i = 0; i < this->numProcs; i++) {
      if (i == recoveringProc)
	this->ReadHistoryList(ifs, historyList);
      else
	this->SkipHistoryList(ifs);
    }
    if (this->CkptConsistentWithState(historyList, lc)) { 
      strcpy(this->rollbackFilename, ckptFilename);
      for (e = historyList.begin(); e != historyList.end(); ++e) {
	h = *e;
	delete h;
      }
      historyList.clear();
    }
    else {
      for (e = historyList.begin(); e != historyList.end(); ++e) {
	h = *e;
	delete h;
      }
      historyList.clear();
      break;
    }
  }
  ifs.close();

  // Now, need to truncate the ckpt history information---that is,
  // need to discard all the history stuff about obsolete checkpoints.
  sprintf(newCkptHistoryFile, "%s/tmp.ckpt.history.%d", EGIDA_LOGS_DIR,
	  this->id);
  ifs.open(ckptHistoryFile, std::ios::in);
  ofs.open(newCkptHistoryFile, std::ios::out);
  assert(ofs.is_open());
  while (1) {
    ifs >> ckptFilename;
    ofs << ckptFilename << std::endl;
    for (i = 0; i < this->numProcs; i++) {
      this->ReadHistoryList(ifs, historyList);
      this->WriteFreeHistoryList(ofs, historyList);
    }
    if (strcmp(ckptFilename, this->rollbackFilename) == 0)
      break;
  }
  ifs.close();
  ofs.flush();
  ofs.close();
  rename(newCkptHistoryFile, ckptHistoryFile);
}

bool PbVectorClock::GetRollbackFile(char *fileName)
{
  strcpy(fileName, this->rollbackFilename);
  return true;
}

void PbVectorClock::WriteFreeHistoryList(std::ofstream &ofs, 
					  History_List &hl)
{
  History_ListIterator e;
  HistoryEntry *h;

  ofs << hl.size() << ' ';
  for (e = hl.begin(); e != hl.end(); ++e) {
    h = *e;
    ofs << *h;
    delete h;
  }
  hl.clear();

  ofs << std::endl;
}

void PbVectorClock::ReadHistoryList(std::ifstream &ifs, 
				     History_List &hl)
{
  int count, numRead = 0;
  HistoryEntry h;

  ifs >> count;
  while (numRead < count) {
    ifs >> h;
    hl.push_back(new HistoryEntry(h));
    numRead++;
  }
}

void PbVectorClock::SkipHistoryList(std::ifstream &ifs)
{
  int count, numRead = 0;
  HistoryEntry h;

  ifs >> count;
  while (numRead < count) {
    ifs >> h;
    numRead++;
  }
}

bool PbVectorClock::CkptConsistentWithState(const History_List &hl,
					     const VCComponent &lc)
{
  History_ListConstIterator e;
  HistoryEntry *h;

  for (e = hl.begin(); e != hl.end(); ++e) {
    h = *e;
    // remember ">" is an overloaded operator for HistoryEntry
    if ((!(h->token)) && (h->comp > lc))
      // we delivered a message which has a later timestamp than the
      // recovered state.
      return false;
  }
  // either no record for lc.version exists in the
  // checkpoint or one exists and the message delivered was
  // consistent with lc.stateInterval
  return true;
}

bool PbVectorClock::ObsoleteMsgVC(const VectorClock &msgVC)
{
  int i;
  History_ListIterator e;
  HistoryEntry *h;
  
  for (i = 0; i < this->numProcs; i++) {
    for (e = this->history[i].begin(); e != this->history[i].end(); ++e) 
      {
	h = *e;
	if ((h->token) && (h->comp.incarnation == msgVC[i].incarnation) &&
	    (msgVC[i].stateInterval > h->comp.stateInterval)) {
	  return true;
	}
      }
  }
  return false;
}

void PbVectorClock::UpdateVC(const VectorClock &msgVC)
{
  int i;
  
  this->ftvc[this->id].stateInterval++;
  // the following does a component wise maximum for VectorClock.
  for (i = 0; i < this->numProcs; i++)
    this->ftvc[i] = this->ftvc[i] > msgVC[i] ? this->ftvc[i] : msgVC[i];
}

void PbVectorClock::UpdateHistory(const VectorClock &msgVC)
{
  int i;
  bool found;
  History_ListIterator e;
  HistoryEntry *h;

  for (i = 0; i < this->numProcs; i++) {
    found = false;
    for (e = this->history[i].begin(); e != this->history[i].end();
	 ++e) {
      h = *e;
      if ((!h->token) && (h->comp.incarnation == msgVC[i].incarnation) &&
	  (h->comp.stateInterval <= msgVC[i].stateInterval)) {
	// !token means a message.  the last message we got had an
	// earlier timestamp.  since this message will be delivered,
	// update the timestamp to reflect this new value.
	found = true;
	h->comp.stateInterval = msgVC[i].stateInterval;
	break;
      }
    }
    if (!found) {
      // create a new entry.
      h = new HistoryEntry(0, msgVC[i]);
      this->history[i].push_back(h);
    }
  }
}  

void PbVectorClock::TimerExpired()
{

}

void PbVectorClock::SendLastControlMessages() {
      for (int index = 0; index < numProcs; index++)
	Egida::ProcessGetLastControlMsgReq(index);
}
