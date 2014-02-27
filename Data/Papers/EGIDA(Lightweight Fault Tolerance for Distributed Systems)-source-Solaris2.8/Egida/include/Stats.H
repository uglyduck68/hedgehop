// Stats.H -- 
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
// $Log: Stats.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:13  ravshank
// Start of Spring 2001
//
// Revision 1.2  2000/06/27 20:15:47  phoebe
// Cleaned up Makefiles. Made DebugTrace into a proper class. Fixed the communication tracking part of Stats.cc.
//
// Revision 1.1  2000/06/27 13:22:54  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.6  2000/06/23 02:47:24  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.5  2000/06/22 22:39:54  phoebe
// Changed Stats namespace to a proper class with it's global varialbes now private, and split the public and private functions appropriately.
//
// Revision 1.4  2000/06/22 22:23:01  phoebe
// Changed the Timer namespace to a proper class. Put all the global timers into Timer class as private data members.
//
// Revision 1.3  2000/04/28 20:08:15  phoebe
// Got Async Checkpoints to return micro-measurements.
//
// Revision 1.2  2000/04/17 16:55:05  phoebe
// Rearranged Stats functions to do both Pre and Post Init (in init.cc) and now checkpoint encryption is working. Right now have Sriram's init file for optimistic which will only run for the short programs...this time it ran to completion on cg but it will not run to completion for sp.
//
// Revision 1.1.1.1  2000/03/06 20:00:14  phoebe
// Sriram's original code with no modifications
//
// $Id: Stats.H,v 1.1.1.1 2001/02/12 00:00:13 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu Apr 29 23:52:58 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Jul 26 23:36:54 1999
// Update Count    : 7
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_STATS_H)
#define _STATS_H

#include <sys/types.h>
#include <sys/time.h>

#include "Globals.H"

//---------------------------
//  make 0 when stats are not wanted, otherwise set to 1
#define COLLECTING_STATS 1

//---------------------------


typedef struct statInfo_t {
  int count;
  double totalKb;
  double timeSpent;
  char infoString[64];
} StatInfo_t;

typedef struct egidaStat_t {
  int id;
  int numProcs;
  int ckptFreq;
  int ckptAvoidThreshold;
  int numFailures;
  int failureIteration;
  StatInfo_t statistics[EGIDA_MAX_STAT];
  char outputFileName[256];  
  char asyncOutputFileName[256];  
} EgidaStat_t;

struct EgidaCommunicationProfileInfo {
  int count;
  double msgSize;
};

struct EgidaCommunicationProfile {
  int id;
  int numProcess;
  struct EgidaCommunicationProfileInfo info[EGIDA_MAX_PROCS];
};



class Stats {
public:

  static void PreInit(void);
  static void PostInit(const char *progName, int ckptFreq, 
		       int ckptAvoidThreshold, 
		       int numFailures, int failureIter,
		       int id, int numProcs);
  static void Update(int statType, long size, double timeSpent);
  static void UpdateMsgStat(int statType, int pid, int size);
  static void Dump(void);
  static void AsyncDump(void);
  static void UpdateSendProfile(int dest, int msgSize);
  static void ResetCommunicationCounts(void);

private:

  //data members for Stats
  static EgidaStat_t egidaStatInfo;
  static EgidaCommunicationProfile egidaSendInfo;
  static EgidaCommunicationProfile egidaReceiveInfo;


  static void ReIntegrateAsyncDump(void);

  static void InitInfo(int statType, const char *info);

  static void InitCommProfiles(int self, int numP);
  static void DumpCommProfiles(void);
};


#endif
