// LogMeta.H -- 
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
// $Log: LogMeta.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:15  ravshank
// Start of Spring 2001
//
// Revision 1.3  2000/10/17 15:02:26  phoebe
// Stable code checkin. RBP is extremely stable except if you kill the master and slave at exactly the same time....it will hang in ReplayDeliver. SBP cannot support concurrent failures due to the lost control messages or hanging in ReplayDeliver. Causal can do +concurrent+ failures as long as control messages are not lost....so the restart must be staggered. Causal seems to suffer the same RBP problem with a master/slave pair, but unsure if this is the problem or if I didn't set numfailures=2...think the later would fix this. All the sentLog protocols (SBP and Causal) suffer from processes dumping core during WriteCkpt if they have been running for a long time since we are not flushing volatile memory at the moment. Should go away with the proper sentLog class fix.
//
// Revision 1.2  2000/06/27 13:22:42  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.1.1.1  2000/03/06 20:00:15  phoebe
// Sriram's original code with no modifications
//
// $Id: LogMeta.H,v 1.1.1.1 2001/02/12 00:00:15 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sat Aug 29 23:33:24 1998
// Last Modified By: Sriram Rao
// Last Modified On: Thu May  6 18:01:09 1999
// Update Count    : 7
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_LOG_META_H)
#define _LOG_META_H

#include <iterator>
#include <list>

class LogMetaEntry {
public:
  LogMetaEntry() {
    this->logCounter = 0;
    for (int i = 0; i < EGIDA_MAX_PROCS; i++) 
      this->logStartEsn[i] = this->logEndEsn[i] = -1;
  };

  LogMetaEntry(const LogMetaEntry &m) {
    this->logCounter = m.logCounter;
    memcpy(this->logStartEsn, m.logStartEsn, EGIDA_MAX_PROCS * sizeof(int));
    memcpy(this->logEndEsn, m.logEndEsn, EGIDA_MAX_PROCS * sizeof(int));
  };

  ~LogMetaEntry() {  };

  LogMetaEntry& operator = (const LogMetaEntry &m) {
    if (this != &m) {
      this->logCounter = m.logCounter;
      memcpy(this->logStartEsn, m.logStartEsn, EGIDA_MAX_PROCS * sizeof(int));
      memcpy(this->logEndEsn, m.logEndEsn, EGIDA_MAX_PROCS * sizeof(int));
    }
    return *this;
  };

  void Clear(void) {
    for (int i = 0; i < EGIDA_MAX_PROCS; i++) 
      this->logStartEsn[i] = this->logEndEsn[i] = -1;
  };

   // Update logStartEsn and logEndEsn as necessary
  void UpdateLogEsn(int id, int esn) {
    if (logStartEsn[id] < 0)
      logStartEsn[id] = esn;
    if (esn > logEndEsn[id])
      logEndEsn[id] = esn;
  }

  int logCounter;
  int logStartEsn[EGIDA_MAX_PROCS], logEndEsn[EGIDA_MAX_PROCS];
};

typedef std::list<LogMetaEntry*> LogMetaEntry_List;
typedef std::list<LogMetaEntry*>::iterator LogMetaEntry_ListIterator;

#endif

