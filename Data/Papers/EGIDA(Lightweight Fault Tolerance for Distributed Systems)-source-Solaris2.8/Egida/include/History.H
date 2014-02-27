// History.H -- 
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
// $Log: History.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:14  ravshank
// Start of Spring 2001
//
// Revision 1.2  2000/06/27 13:22:40  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.1.1.1  2000/03/06 20:00:15  phoebe
// Sriram's original code with no modifications
//
// $Id: History.H,v 1.1.1.1 2001/02/12 00:00:14 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Tue Oct 13 11:08:51 1998
// Last Modified By: Sriram Rao
// Last Modified On: Tue May 18 18:23:06 1999
// Update Count    : 10
// Status          : Unknown, Use with caution!
// PURPOSE
// 	This is the module for the history mechanism from Damani and
// 	Garg's ICDCS'96 paper.  For details, read that paper.

#if defined(__cplusplus) && !defined(_HISTORY_H)
#define _HISTORY_H

#include <iostream>
#include <iterator>
#include <list>

#include "VectorClock.H"

class HistoryEntry {
public:
  HistoryEntry() {
    this->token = 0;  // assume that it is a message;
  };

  HistoryEntry(int t, const VCComponent &c) {
    this->token = t;
    this->comp = c;
  };

  HistoryEntry(const HistoryEntry &h) {
    this->token = h.token;
    this->comp = h.comp;
  };

  friend std::ostream & operator << (std::ostream &os, const HistoryEntry &h) {
    os << h.token << ' ' << h.comp << ' ';
    return os;
  };

  friend std::istream & operator >> (std::istream &is, HistoryEntry &h) {
    is >> h.token;
    is >> h.comp;
    return is;
  };

  int token;  // if set it is a token; otherwise, it is a message.
  VCComponent comp;
};

typedef std::list<HistoryEntry*> History_List;
typedef std::list<HistoryEntry*>::iterator History_ListIterator;
typedef std::list<HistoryEntry*>::const_iterator History_ListConstIterator;
#endif
