// OptLogProtocol.H -- 
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
// $Log: OptLogProtocol.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:14  ravshank
// Start of Spring 2001
//
// Revision 1.5  2000/10/12 19:50:50  phoebe
// Optimistic is still not working for more than one failure, but the incarnation number is now working correctly, and on the second failure it hangs in exactly the same spot every time. Also...optimistic is now rolling back a checkpoint file instead of doing the exec-ing that it was doing before. Additionally, during some of the debugging process, checkpoints are now shrinking heap sizes correctly (we thought they were doing it before, but they weren't.)
//
// Revision 1.4  2000/09/27 22:03:02  phoebe
// In CkptImpl changed the growing of the heap from a strict monotonically increasing function (using the check that we only grow if size is less than what is needed) to one that can shrink. The reason we can do this is sbrk will take as an argument a negative value, where as malloc cannot.
//
// Revision 1.3  2000/06/27 13:22:47  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.2  2000/06/22 23:48:54  phoebe
// Changed some names: Egida_Msg_Queue is now MsgQueue and Egida_Msg is now Message. Also, changed the MsgQueue's in Egida_Object.H to be MsgQueue*'s so that it is consistent with all the other data members. One more thing...changed PbLog (and subclasses) to not require the CkptProtocol * for the object (so not a data member and not part of the Initialize method) since PbLog doesn't use this data member (it's used in PbCkpt).
//
// Revision 1.1.1.1  2000/03/06 20:00:15  phoebe
// Sriram's original code with no modifications
//
// $Id: OptLogProtocol.H,v 1.1.1.1 2001/02/12 00:00:14 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Wed May  5 16:37:06 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Aug 16 14:32:52 1999
// Update Count    : 43
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_OPT_LOG_PROTOCOL_H)
#define _OPT_LOG_PROTOCOL_H

#include <list>
#include <iterator>

#include "History.H"
#include "LogProtocol.H"
#include "VectorClock.H"

struct CkptNameVCEntry {
  CkptNameVCEntry() {
    this->ckptFileName = NULL;
  };

  ~CkptNameVCEntry() {
    delete [] this->ckptFileName;
  };

  CkptNameVCEntry(const VectorClock &v, const char *fileName) {
    int length = strlen(fileName);

    this->vc = v;
    this->ckptFileName = new char [length + 2];
    this->ckptFileName[length + 1] = '\0';
    memcpy(this->ckptFileName, fileName, length * sizeof(char));
  };

  VectorClock vc;
  char *ckptFileName;
};

typedef std::list<CkptNameVCEntry*> CkptNameVC_List;
typedef std::list<CkptNameVCEntry*>::iterator CkptNameVC_ListIterator;



class PbVectorClock : public PbLog {
public:
  PbVectorClock() { };

  PbVectorClock(int self, int numP, int numF) : 
    PbLog(self, numP, numF) { };

  void Initialize(MsgQueue *q,
		  DetLog *detl, EventLog *sl, EventLog *dl);

  void GetPiggyback(int dest, char **pb, int *pbSize);
  bool ProcessPiggyback(int source, int ssn, char *pb, int pbSize);
  bool IsDeliverable(int source, int ssn, char *pb, int pbSize);

  void ProcessMsg(int source, int tag, char *msg, int msgSize) { };
  void PreCkptActions(void);
  void PostCkptActions(const char *ckptFileName, int stableEventId);
  void CleanUpCkptFiles(char * ckptFileName);
  
  // These two are needed for recovery
  virtual void PreReplayActions(int startEsn, bool rb);
  virtual void PostReplayActions(void);
  virtual bool NeedToDetectOrphans(void);

  void ProcessFailureAnnouncement(int recoveringProc, const VCComponent &lc);
  bool IsOrphan(int recoveringProc, const VCComponent &lc);
  bool GetRollbackFile(char *fileName);
  
  // compute the recoverable state of this process
  void GetRecoverableState(VCComponent *lc) const;

  // In optimistic logging, HAVE to log all sent messages---can't tell 
  // when some message will be discarded by the receiver as obsolete.
  void UpdateAvoidLoggingMsg(int source, int ssn) { };
  
  void TimerExpired(void);

  void SendLastControlMessages();

private:
  // set if this process became an orphan and had to be rolled back.
  bool rolledback;

  VectorClock ftvc;
  // This records the vector clock of the process at the time of the last
  // checkpoint. 
  VectorClock lastCkptVC;
  // the stableState[i] is the logical clock of process i
  // corresponding to its last checkpoint
  VectorClock stableState;
  // This records the vc corresponding to the state to which this
  // process can be restored after a crash
  VectorClock recoverableState;

  History_List history[EGIDA_MAX_PROCS];
  // This records the dependency of this process on the remaining
  // processes at the time of the last checkpoint
  History_List lastCkptHistory[EGIDA_MAX_PROCS];
  // For each checkpoint taken by a process, this list contains the
  // file name and the vector clock of the process at the time of the
  // checkpoint.  This list is used to allow a process to determine
  // when the recovery line has moved forward and checkpoints can be
  // thrown away.
  CkptNameVC_List ckptNameVC_List;

  bool ObsoleteMsgVC(const VectorClock &msgVC);
  void UpdateVC(const VectorClock &msgVC);
  void UpdateHistory(const VectorClock &msgVC);
  void WriteFreeHistoryList(std::ofstream &ofs, 
			    History_List &hl);
  void ComputeRollbackFile(int recoveringProc, const VCComponent &lc);
  void ReadHistoryList(std::ifstream &ifs, History_List &hl);
  void SkipHistoryList(std::ifstream &ifs);

  void AddToken(int recoveringProc, const VCComponent &lc);
  void ReadTokens(void);
  void ComputeRecoverableState(int startEsn);

  void RecordIncarnationNumber(void);
  void RecallIncarnationNumber(void);

  bool CkptConsistentWithState(const History_List &hl, const VCComponent &lc);
};

#endif
