// VectorClock.H -- 
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
// $Log: VectorClock.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:15  ravshank
// Start of Spring 2001
//
// Revision 1.2  2000/06/27 13:22:55  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.1.1.1  2000/03/06 20:00:16  phoebe
// Sriram's original code with no modifications
//
// $Id: VectorClock.H,v 1.1.1.1 2001/02/12 00:00:15 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Wed May  5 16:30:56 1999
// Last Modified By: Sriram Rao
// Last Modified On: Wed May  5 23:33:38 1999
// Update Count    : 12
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Implements a vector clock with an incarnation # and a state
// 	interval for a given incarnation.

#if defined(__cplusplus) && !defined(_VECTOR_CLOCK_H)
#define _VECTOR_CLOCK_H

#include <iostream>
#include "Globals.H"

class VCComponent {
public:
  VCComponent() {
    this->incarnation = this->stateInterval = 0;
  };

  friend std::ostream & operator << (std::ostream &os, const VCComponent &c) {
    os << c.incarnation << ' ' << c.stateInterval << ' ';
    return os;
  };

  friend std::istream & operator >> (std::istream &is, VCComponent &c) {
    is >> c.incarnation;
    is >> c.stateInterval;
    return is;
  };

  VCComponent& operator = (const VCComponent &c) {
    if (this != &c) {
      this->incarnation = c.incarnation;
      this->stateInterval = c.stateInterval;
    }
    return *this;
  };

  friend bool operator > (const VCComponent &v1, const VCComponent &v2) 
    {
      if (v1.incarnation == v2.incarnation) {
	if (v1.stateInterval > v2.stateInterval)
	  return 1;
	else
	  return 0;
      }
      else if (v1.incarnation > v2.incarnation)
	return 1;
      else 
	return 0;
    };

  friend bool operator == (const VCComponent &v1, const VCComponent &v2) 
    {
      return ((v1.incarnation == v2.incarnation) && 
	      (v1.stateInterval == v2.stateInterval));
    };

  int incarnation;
  int stateInterval;

};


  
          
class VectorClock {
public:
  VectorClock() { 
   int i;
  
   for (i = 0; i < EGIDA_MAX_PROCS; i++)
     this->vectorClock[i].incarnation =
       this->vectorClock[i].stateInterval = 0;
  };

  ~VectorClock() { };

  VectorClock& operator = (const VectorClock &vc) {
    int i;
    if (this != &vc) {
      for (i = 0; i < EGIDA_MAX_PROCS; i++)
	this->vectorClock[i] = vc.vectorClock[i];
    }
    return *this;
  };

  VCComponent& operator[](int index) {
    assert((0 <= index) && (index < EGIDA_MAX_PROCS));
    return this->vectorClock[index];
  };

  const VCComponent& operator[](int index) const {
    assert((0 <= index) && (index < EGIDA_MAX_PROCS));
    return this->vectorClock[index];
  };

  friend std::ostream & operator << (std::ostream &os, const VectorClock &vc) {
    int i;

    for (i = 0; i < EGIDA_MAX_PROCS; i++)
      os << vc.vectorClock[i];
    return os;
  };

  friend std::istream & operator >> (std::istream &is, VectorClock &vc) {
    int i;

    for (i = 0; i < EGIDA_MAX_PROCS; i++)
      is >> vc.vectorClock[i];
    return is;
  };

  VCComponent vectorClock[EGIDA_MAX_PROCS];
};

#endif
