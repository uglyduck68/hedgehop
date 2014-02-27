// RollbackActions.H -- 
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
// $Log: Rollback.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:14  ravshank
// Start of Spring 2001
//
// Revision 1.2  2000/06/27 13:22:51  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.1.1.1  2000/03/06 20:00:16  phoebe
// Sriram's original code with no modifications
//
// $Id: Rollback.H,v 1.1.1.1 2001/02/12 00:00:14 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Tue May 18 14:08:18 1999
// Last Modified By: Sriram Rao
// Last Modified On: Sun Aug 15 18:07:44 1999
// Update Count    : 5
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_ROLLBACK_H)
#define _ROLLBACK_H

#include "DetLog.H"
#include "EventLog.H"

class RollbackActions {
public:
  RollbackActions() {
    this->detLog = NULL;
    this->eventLog = NULL;
  };

  ~RollbackActions() { };

  RollbackActions(DetLog *dl, EventLog *el) {
    this->detLog = dl;
    this->eventLog = el;
  };

  virtual void RbActions(void) { };

protected:
  DetLog *detLog;
  EventLog *eventLog;
};



class FlushOnRollback : public RollbackActions {
public:
  FlushOnRollback () { };

  ~FlushOnRollback () { };

  FlushOnRollback(DetLog *dl, EventLog *el) : RollbackActions(dl, el) { };

  void RbActions(void) {
    this->detLog->Flush();
    this->eventLog->Flush();
  };
};
#endif
