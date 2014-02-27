// Determinant.H -- 
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
// $Log: Determinant.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:13  ravshank
// Start of Spring 2001
//
// Revision 1.3  2000/11/15 22:12:23  phoebe
// Sanity check.
//
// Revision 1.2  2000/06/27 13:22:30  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.1.1.1  2000/03/06 20:00:14  phoebe
// Sriram's original code with no modifications
//
// $Id: Determinant.H,v 1.1.1.1 2001/02/12 00:00:13 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu May  6 13:33:35 1999
// Last Modified By: Sriram Rao
// Last Modified On: Thu May 27 17:59:56 1999
// Update Count    : 16
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_DETERMINANT_H)
#define _DETERMINANT_H

#include <assert.h>
#include <iostream>
#include <iterator>
#include <list>
#include <string.h>

#include "Globals.H"

class Determinant {
public:
  Determinant() {
    this->source = this->dest = -1;
    this->s_esn = this->d_esn = -1;
    this->eventSpecific = NULL;
    this->eventSpecificSize = 0;
    memset(this->loggedAt, 0, EGIDA_MAX_PROCS * sizeof(int));
  }
  ~Determinant() {
    delete [] this->eventSpecific;
    this->eventSpecific = NULL;
    this->eventSpecificSize = 0;
  };
  Determinant(int s, int sendSeq, int d, int recvSeq,
	      const char *eventSp, int eventSpSz) {
    this->source = s;
    this->dest = d;
    this->s_esn = sendSeq;
    this->d_esn = recvSeq;
    if (eventSpSz > 0) {
      this->eventSpecific = new char [eventSpSz];
      memcpy(this->eventSpecific, eventSp, eventSpSz);
    }
    else
      this->eventSpecific = NULL;
    this->eventSpecificSize = eventSpSz;
    memset(this->loggedAt, 0, EGIDA_MAX_PROCS * sizeof(int));
    this->loggedAt[d] = 1;
  };
  Determinant(const Determinant& d) {
    this->source = d.source;
    this->dest = d.dest;
    this->s_esn = d.s_esn;
    this->d_esn = d.d_esn;
    if (d.eventSpecificSize > 0) {
      this->eventSpecific = new char [d.eventSpecificSize];
      memcpy(this->eventSpecific, d.eventSpecific,
	     d.eventSpecificSize);
    }
    else
      this->eventSpecific = NULL;
    this->eventSpecificSize = d.eventSpecificSize;

    memcpy(this->loggedAt, d.loggedAt, EGIDA_MAX_PROCS * sizeof(int));
  };
  Determinant& operator = (const Determinant &d) {
    if (this != &d) {
      this->source = d.source;
      this->dest = d.dest;
      this->s_esn = d.s_esn;
      this->d_esn = d.d_esn;

      delete [] this->eventSpecific;
      if (d.eventSpecificSize > 0) {
	this->eventSpecific = new char [d.eventSpecificSize];
	memcpy(this->eventSpecific, d.eventSpecific,
	       d.eventSpecificSize);
      }
      else
	this->eventSpecific = NULL;

      this->eventSpecificSize = d.eventSpecificSize;

      memcpy(this->loggedAt, d.loggedAt, EGIDA_MAX_PROCS * sizeof(int));
    }
    return *this;
  };

  void UpdateLoggedAt(int proc) {
    assert ((0 <= proc) && (proc < EGIDA_MAX_PROCS));

    this->loggedAt[proc] = 1;
  };
  int IsLoggedAt(int proc) const {
    assert ((0 <= proc) && (proc < EGIDA_MAX_PROCS));
    return this->loggedAt[proc];
  };

  // It is the caller's responsibility to ensure that the size of the
  // buffer passed in is = this->eventSpecificSize
  void GetEventSpecific(char *result) const {
    memcpy(result, this->eventSpecific, this->eventSpecificSize);
  };

  int NumLoggedAt() const {
    int i, count = 0;

    for (i = 0; i < EGIDA_MAX_PROCS; i++)
      if (this->loggedAt[i])
	count++;

    return count;
  };

  friend std::ostream & operator << (std::ostream &os, const Determinant &d) {
    os << d.source << ' ';
    os << d.s_esn << ' ';
    os << d.dest << ' ';
    os << d.d_esn << ' ';
    os << d.eventSpecificSize << ' ';
    if (d.eventSpecificSize > 0) {
      os.write(d.eventSpecific, d.eventSpecificSize);
      os << ' ';
    }
    
    return os;
  };
  friend std::istream & operator >> (std::istream &is, Determinant &d) {

    d.Clear();

    is >> d.source;
    if (is.eof())
      return is;
    is >> d.s_esn;
    if (is.eof())
      return is;
    is >> d.dest;
    if (is.eof())
      return is;
    is >> d.d_esn;
    is >> d.eventSpecificSize;
    // skip over the ' ' after the eventSpecific size
    is.get();
    if (d.eventSpecificSize > 0) {
      d.eventSpecific = new char [d.eventSpecificSize];
      is.read(d.eventSpecific, d.eventSpecificSize);
    }
    return is;
  };
  void Clear(void) {
    this->source = this->dest = -1;
    this->s_esn = this->d_esn = -1;
    if((eventSpecificSize > 0) && (eventSpecific != NULL))
      delete [] this->eventSpecific;
    this->eventSpecific = NULL;
    this->eventSpecificSize = 0;
    memset(this->loggedAt, 0, EGIDA_MAX_PROCS * sizeof(int));    
  };

  int source, dest;
  int s_esn, d_esn;
  // whatever is put here is not interpreted
  char *eventSpecific;
  int eventSpecificSize;
  int loggedAt[EGIDA_MAX_PROCS];
};

typedef std::list<Determinant*> Determinant_List;
typedef std::list<Determinant*>::iterator Determinant_ListIterator;
typedef std::list<Determinant*>::const_iterator Determinant_ListConstIterator;

#endif
