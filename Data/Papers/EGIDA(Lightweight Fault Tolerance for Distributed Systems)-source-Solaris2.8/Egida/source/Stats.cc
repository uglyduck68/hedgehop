// Stats.cc -- 
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
// $Log: Stats.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:16  ravshank
// Start of Spring 2001
//
// Revision 1.3  2000/11/21 22:27:21  phoebe
// GarbageCollect in the SentStore is now working async. We changed the logic slightly so that all files are cleaned by one process and we clean when we've heard 3 responses (not necessarily all from different processes...this is ok we think.) Also...our favorite core dump on TakeCkpt (the memcpy one) has crept back in the picture. <grrrr>
//
// Revision 1.2  2000/06/27 20:15:53  phoebe
// Cleaned up Makefiles. Made DebugTrace into a proper class. Fixed the communication tracking part of Stats.cc.
//
// Revision 1.1  2000/06/27 13:23:16  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.12  2000/06/22 22:39:55  phoebe
// Changed Stats namespace to a proper class with it's global varialbes now private, and split the public and private functions appropriately.
//
// Revision 1.11  2000/06/22 22:23:06  phoebe
// Changed the Timer namespace to a proper class. Put all the global timers into Timer class as private data members.
//
// Revision 1.10  2000/06/22 20:59:03  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.9  2000/06/02 05:47:24  phoebe
// Hash and Sign of EventInfo working and it will restart and check fine. I think the modification I made to EventInfo for Reads (it's commented as a change in the code...I used << and >> instead of the commented out code) is preventing restart. Need to make sure I understand what is going on with that later.
//
// Revision 1.8  2000/06/02 04:13:16  phoebe
// Encryption of EventInfo now working.
//
// Revision 1.7  2000/06/01 23:08:46  phoebe
// Reconfigured the Egida_Object_Init.cc file under the direction of Lorenzo so that the protocol inits make sense.
//
// Revision 1.6  2000/04/28 20:08:18  phoebe
// Got Async Checkpoints to return micro-measurements.
//
// Revision 1.5  2000/04/20 20:57:57  phoebe
// Integrated Stats to track hash and sign functions.
//
// Revision 1.4  2000/04/17 21:11:58  phoebe
// Pretty-printed Statistics going to file to be more readable. Seems that Incremental checkpoint count always includes the full checkpoint because of the weird interdependence between Incr and Full ckpt class. Other than that all of the stats now make more sense.
//
// Revision 1.3  2000/04/17 16:55:09  phoebe
// Rearranged Stats functions to do both Pre and Post Init (in init.cc) and now checkpoint encryption is working. Right now have Sriram's init file for optimistic which will only run for the short programs...this time it ran to completion on cg but it will not run to completion for sp.
//
// Revision 1.2  2000/04/14 16:34:43  phoebe
// Put in more stats to track encryption/decryption times. Also modified Communication.cc to have a cleaner interface for Message encryption/decryption so it would be easier to track with Stats...meaning I added a wrapper function call. Stats::Init is being done in Egida_PostInit which means the first checkpoint is being missed.
//
// Revision 1.1.1.1  2000/03/06 20:00:20  phoebe
// Sriram's original code with no modifications
//
// $Id: Stats.cc,v 1.1.1.1 2001/02/12 00:00:16 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Tue May  4 11:07:25 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Jul 26 23:36:31 1999
// Update Count    : 21
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <fstream>
#include <iostream>
#include <strings.h>
#include <unistd.h>
#include <string>
#include <sys/utsname.h>

#include "Stats.H"
#include "Timer.H"


//static data members for Stats
EgidaStat_t Stats::egidaStatInfo;
EgidaCommunicationProfile Stats::egidaSendInfo;
EgidaCommunicationProfile Stats::egidaReceiveInfo;

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Initialize data structures for gathering statistics of a
// 	process execution.
// 
// Arguments:
//      All of them have obvious meanings; 
//        id -- is the id of this process in 0 to numProcs - 1.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	Updates egidaStatInfo and egidaSendInfo variables.
// 
// /////////////////////////////////////////////////////////////////
void Stats::PreInit()
{
  memset(&egidaStatInfo, 0, sizeof(EgidaStat_t));

  InitInfo(EGIDA_SEND_STAT, "Send");
  InitInfo(EGIDA_RECV_STAT, "Recv");
  InitInfo(EGIDA_BROADCAST_STAT, "Broadcast");
  InitInfo(EGIDA_MSGS_AVAIL_STAT, "Msgs Avail");
  InitInfo(EGIDA_LOG_DELIVERED_MSG_STAT, "Log Delivered Msg");

  InitInfo(EGIDA_CKPT_TIME_STAT, "Checkpoint time");
  InitInfo(EGIDA_CKPT_SIZE_STAT, "Checkpoint Size");
  InitInfo(EGIDA_FULL_CKPT_STAT, "Full Checkpoint");
  InitInfo(EGIDA_INCR_CKPT_STAT, "Incremental Checkpoint");
  InitInfo(EGIDA_FORCED_CKPT_STAT, "Forced Checkpoint");
  InitInfo(EGIDA_INDEP_CKPT_STAT, "Independent Checkpoint");

  InitInfo(EGIDA_LOG_FLUSH_STAT, "Log Flush");
  InitInfo(EGIDA_LOG_GARBAGE_COLLECT_STAT, "Log GarbageCollect");
  InitInfo(EGIDA_LOG_WRITE_STAT, "Log Write");

  InitInfo(EGIDA_EVENT_INFO_WRITE_STAT, "EventInfo Write");
  InitInfo(EGIDA_DET_WRITE_STAT, "Determinant Write");


  InitInfo(EGIDA_RECOVERY_STATE_RESTORE_STAT, "Recovery Restore");
  InitInfo(EGIDA_RECOVERY_LOG_ACQUIRE_STAT, "Recovery Log Acquire");
  InitInfo(EGIDA_RECOVERY_PRE_ROLL_FORWARD_STAT, "Pre-Roll Forward");
  InitInfo(EGIDA_RECOVERY_ROLL_FORWARD_STAT, "Roll Forward");
  InitInfo(EGIDA_RECOVERY_LOG_REPLAY_STAT, "Log Replay");
  InitInfo(EGIDA_RECOVERY_REPLAY_DELIVER_STAT, "Replay Deliver");
  InitInfo(EGIDA_RECOVERY_PB_PROC_STAT, "Process Piggyback");
  InitInfo(EGIDA_RECOVERY_DETSTORE_MISS_STAT, "DetStore Miss");
  InitInfo(EGIDA_RECOVERY_POLL_REPLAY_STAT, "Poll Replay");
  InitInfo(EGIDA_RECOVERY_ROLL_BACK_OVERHEAD_STAT, "Restore done->p4 Recovery done");
  InitInfo(EGIDA_RECOVERY_DETLOG_RETRIEVE_STAT, "DetLog Retrieve");

  InitInfo(EGIDA_GET_PIGGYBACK_STAT, "Get PiggyBack");
  InitInfo(EGIDA_LOG_SENT_MSG_STAT, "Log Sent Msg");
  InitInfo(EGIDA_POLL_RECORD_STAT, "MsgPoll Record");

  InitInfo(EGIDA_MSG_ENCRYPTION_STAT, "Message Encryption");
  InitInfo(EGIDA_MSG_DECRYPTION_STAT, "Message Decryption");
  InitInfo(EGIDA_CKPT_ENCRYPTION_STAT, "Checkpoint Encryption");
  InitInfo(EGIDA_CKPT_DECRYPTION_STAT, "Checkpoint Decryption");
  InitInfo(EGIDA_DETERMINANT_ENCRYPTION_STAT, "Determinant Encryption");
  InitInfo(EGIDA_DETERMINANT_DECRYPTION_STAT, "Determinant Decryption");
  InitInfo(EGIDA_EVENT_INFO_ENCRYPTION_STAT, "EventInfo Encryption");
  InitInfo(EGIDA_EVENT_INFO_DECRYPTION_STAT, "EventInfo Decryption");

  InitInfo(EGIDA_CKPT_HASH_STAT, "Checkpoint Hash");
  InitInfo(EGIDA_CKPT_CHECK_HASH_STAT, "Checkpoint Check Hash");
  InitInfo(EGIDA_DETERMINANT_HASH_STAT, "Determinant Hash");
  InitInfo(EGIDA_DETERMINANT_CHECK_HASH_STAT, "Determinant Check Hash");
  InitInfo(EGIDA_EVENT_INFO_HASH_STAT, "EventInfo Hash");
  InitInfo(EGIDA_EVENT_INFO_CHECK_HASH_STAT, "EventInfo Check Hash");
}


void Stats::PostInit(const char *progName, int ckptFreq, 
		 int ckptAvoidThreshold, 
		 int numFailures, int failureIter,
		 int self, int numP)
{
  char *p;

  p = rindex(progName, '/');
  p++;
  if (p) {
    sprintf(egidaStatInfo.outputFileName, "%s/%s.%d",
	    EGIDA_RESULTS_DIR, p, self);
  }
  else {
    sprintf(egidaStatInfo.outputFileName, "%s/%s.%d",
	    EGIDA_RESULTS_DIR, progName, self);
  }
  sprintf(egidaStatInfo.asyncOutputFileName, "%s.async",
	  egidaStatInfo.outputFileName);

  std::cout << "outputFileName: " << egidaStatInfo.outputFileName << std::endl;


  egidaStatInfo.id = self;
  egidaStatInfo.numProcs = numP;
  egidaStatInfo.ckptFreq = ckptFreq;
  egidaStatInfo.ckptAvoidThreshold = ckptAvoidThreshold;
  egidaStatInfo.numFailures = numFailures;
  egidaStatInfo.failureIteration = failureIter;

  InitCommProfiles(self, numP);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Initialize the statistics information for one type of statistic.
// 
// Arguments:
// 	statType --- identifies the specific statistic that is
// 	       initialized
//      info --- character string that has to be printed whenever this 
//             field is printed.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	Updates egidaStatInfo.statistics[]
// 
// /////////////////////////////////////////////////////////////////

void Stats::InitInfo(int statType, const char *info)
{
  if (statType < EGIDA_MAX_STAT) {
    sprintf(egidaStatInfo.statistics[statType].infoString, "%s", info);
    egidaStatInfo.statistics[statType].count = 0;
    egidaStatInfo.statistics[statType].totalKb = 0.0;
    egidaStatInfo.statistics[statType].timeSpent = 0.0;
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Update statistics
// 
// Arguments:
// 	statType --- field to be updated
//      size --- is a value in bytes
//      timeSpent --- is a value in seconds
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	Updates egidaStatInfo.statistics[]
// 
// /////////////////////////////////////////////////////////////////

void Stats::Update(int statType, long size, double timeSpent)
{
  if (statType < EGIDA_MAX_STAT) {
    egidaStatInfo.statistics[statType].count++;

    egidaStatInfo.statistics[statType].totalKb += (((double) size) /
						    1024.0);
    egidaStatInfo.statistics[statType].timeSpent += timeSpent;
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Collect message send/receive statistics
// 
// Arguments:
// 	statType --- one of EGIDA_SEND_STAT/EGIDA_RECV_STAT
//      pid --- process with which the communication occurred
//      size --- a value in bytes
//      timeSpent --- a value in seconds
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	Updates egidaStatInfo.msgStat[][]
// 
// /////////////////////////////////////////////////////////////////

void Stats::UpdateMsgStat(int statType, int pid, int size)
{
  if (statType == EGIDA_SEND_STAT) {
    egidaSendInfo.info[pid].count++;
    egidaSendInfo.info[pid].msgSize += (((double) size) / 1024.0);
  }
  else if(statType == EGIDA_RECV_STAT) {
    egidaReceiveInfo.info[pid].count++;
    egidaReceiveInfo.info[pid].msgSize += (((double) size) / 1024.0);
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Dump the statistics
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

void Stats::Dump(void)
{
  int count;
  double ckptSize, totalSize;
  struct timeval endTime;
  double timeSpent;
  char ckptFileName[256];
  FILE *fp, *ckptFile;
  struct utsname machineName;
  int i;

  timeSpent = Timer::AppTimeSpent();

  ReIntegrateAsyncDump();

  fp = fopen(egidaStatInfo.outputFileName, "a");
  
  uname(&machineName);
  fprintf(fp, "\n---------------------");

  fprintf(fp, "\n Machine name = %s", machineName.nodename);

  fprintf(fp, "\n Failure Iteration = %d",
	  egidaStatInfo.failureIteration);
  fprintf(fp, "\n Number of failures = %d", egidaStatInfo.numFailures);

  fprintf(fp, "\n Checkpoint Freq = %d", egidaStatInfo.ckptFreq);
  fprintf(fp, "\n Checkpoint Avoid Threshold = %d", egidaStatInfo.ckptAvoidThreshold);
  fprintf(fp, "\n Total Execution time: %.3lf (sec)", timeSpent);
  for (i = 0; i < EGIDA_MAX_STAT; i++) {
    if (egidaStatInfo.statistics[i].count > 0) {
      fprintf(fp, "\n %s:",
	      egidaStatInfo.statistics[i].infoString);
      fprintf(fp, " count = %d", 
	      egidaStatInfo.statistics[i].count);
      fprintf(fp, "  data = %.3lf (kb)",
	      (double) egidaStatInfo.statistics[i].totalKb);
      fprintf(fp, "  time = %.3lf (s)",
	      (double) egidaStatInfo.statistics[i].timeSpent);
      fprintf(fp, "\n \t Averages: data/count = %.3lf (kb)",
	      (double) egidaStatInfo.statistics[i].totalKb /
	      (double) egidaStatInfo.statistics[i].count);
      fprintf(fp, "  time/count = %.3lf (s)",
	      (double) egidaStatInfo.statistics[i].timeSpent /
	      (double) egidaStatInfo.statistics[i].count); 
      fprintf(fp, "\n \t Application averages: count/sec %.3lf (/s)",
	      (double) egidaStatInfo.statistics[i].count / 
	      (double) timeSpent);
      fprintf(fp, "  data/sec = %.3lf (kb/s)",
	      (double) egidaStatInfo.statistics[i].totalKb/
	      (double) timeSpent);
    }
  }

  count = 0;
  totalSize = 0.0;
  sprintf(ckptFileName, "%s.ckptSize", egidaStatInfo.outputFileName);
  if ((ckptFile = fopen(ckptFileName, "r")) != NULL) 
    while (1) {
      ckptSize = 0.0;
      fscanf(ckptFile, "%lf", &ckptSize);
      if (feof(ckptFile))
	break;
      totalSize += ckptSize;
      count++;
    }
  fclose(ckptFile);
  unlink(ckptFileName);
  if (count > 0) {
    fprintf(fp, "\n Avg. Checkpoint Size: %.3lf \n", totalSize / count);
  }
  fflush(fp);
  fclose(fp);

  DumpCommProfiles();

}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Dump the statistics gotten during an async checkpoint
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

void Stats::AsyncDump(void)
{
  FILE *fp = fopen(egidaStatInfo.asyncOutputFileName, "a");

  if (egidaStatInfo.statistics[EGIDA_FULL_CKPT_STAT].count > 0) {
    fprintf(fp, "%d %d %lf %lf \n",
	    EGIDA_FULL_CKPT_STAT, 
	    egidaStatInfo.statistics[EGIDA_FULL_CKPT_STAT].count, 
	    egidaStatInfo.statistics[EGIDA_FULL_CKPT_STAT].totalKb, 
	    egidaStatInfo.statistics[EGIDA_FULL_CKPT_STAT].timeSpent); 
  }
  if (egidaStatInfo.statistics[EGIDA_INCR_CKPT_STAT].count > 0) {
    fprintf(fp, "%d %d %lf %lf \n",
	    EGIDA_INCR_CKPT_STAT, 
	    egidaStatInfo.statistics[EGIDA_INCR_CKPT_STAT].count, 
	    egidaStatInfo.statistics[EGIDA_INCR_CKPT_STAT].totalKb, 
	    egidaStatInfo.statistics[EGIDA_INCR_CKPT_STAT].timeSpent); 
  }
  

  for (int i = SECURITY_BEGIN_STAT; i < EGIDA_MAX_STAT; i++) {
    if (egidaStatInfo.statistics[i].count > 0) {
      fprintf(fp, "%d %d %lf %lf \n",
	      i, egidaStatInfo.statistics[i].count, 
	      egidaStatInfo.statistics[i].totalKb, 
	      egidaStatInfo.statistics[i].timeSpent); 
    }
  }
  fflush(fp);
  fclose(fp);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Add in the statistics gotten during an async checkpoint
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

void Stats::ReIntegrateAsyncDump(void)
{
  int statNum, count;
  double totalKb, timeSpent;
  FILE *fp = fopen(egidaStatInfo.asyncOutputFileName, "r");

  if (fp == NULL)
    return;  //no asynch checkpoints were taken

  while(fscanf(fp, "%d%d%lf%lf",
	       &statNum, &count, &totalKb, &timeSpent) == 4) {
    egidaStatInfo.statistics[statNum].count += count;
    egidaStatInfo.statistics[statNum].totalKb += totalKb;
    egidaStatInfo.statistics[statNum].timeSpent += timeSpent;
  }
  fclose(fp);
  unlink(egidaStatInfo.asyncOutputFileName);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Initialize send profile
// 
// Arguments:
// 	self --- id of this process in 0 to numP - 1
//      numP --- # of processes in the application
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	Updates egidaSendInfo
// 
// /////////////////////////////////////////////////////////////////

void Stats::InitCommProfiles(int self, int numP)
{
  egidaSendInfo.id = self;
  egidaSendInfo.numProcess = numP;
  for (int i = 0; i < EGIDA_MAX_PROCS; i++) {
    egidaSendInfo.info[i].count = 0;
    egidaSendInfo.info[i].msgSize = 0.0;
  }

  egidaReceiveInfo.id = self;
  egidaReceiveInfo.numProcess = numP;
  for (int j = 0; j < EGIDA_MAX_PROCS; j++) {
    egidaReceiveInfo.info[j].count = 0;
    egidaReceiveInfo.info[j].msgSize = 0.0;
  }
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Dump the message send profile of the process
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


void Stats::DumpCommProfiles()
{
  char fileName[256];
  std::ofstream ofs;
  
  sprintf(fileName, "%s/commPatterns.%d", EGIDA_LOGS_DIR,
	  egidaSendInfo.id);

  ofs.open(fileName, std::ios::app);
  ofs << "----------------------" << std::endl;
  for (int i = 0; i < egidaSendInfo.numProcess; i++) {
    if (egidaSendInfo.info[i].count > 0)
      ofs << "sent to " << i << ": " << egidaSendInfo.info[i].count << 
	" times with avg msgSize = "  << egidaSendInfo.info[i].msgSize /
	egidaSendInfo.info[i].count << " (kb)" << std::endl;
  }

  ofs << std::endl;

  for (int j = 0; j < egidaReceiveInfo.numProcess; j++) {
    if (egidaReceiveInfo.info[j].count > 0)
      ofs << "received from " << j << ": " << egidaReceiveInfo.info[j].count << 
	" times with avg msgSize = "  << egidaReceiveInfo.info[j].msgSize /
	egidaReceiveInfo.info[j].count << " (kb)" << std::endl;
  }

  ofs.flush();
  ofs.close();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Record the send profile --- process to which a message is sent 
// 	and the size of the message.
// 
// Arguments:
// 	dest --- process to which the message is sent
//      msgSize --- size of the sent message
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	Updates egidaSendInfo
// 
// /////////////////////////////////////////////////////////////////

void Stats::UpdateSendProfile(int dest, int msgSize)
{
  egidaSendInfo.info[dest].count++;
  egidaSendInfo.info[dest].msgSize += (msgSize / (1024.0 * 1024.0));
}

void Stats::ResetCommunicationCounts()
{
  InitInfo(EGIDA_SEND_STAT, "Send");
  InitInfo(EGIDA_RECV_STAT, "Recv");
  InitInfo(EGIDA_BROADCAST_STAT, "Broadcast");
  InitInfo(EGIDA_MSGS_AVAIL_STAT, "Msgs Avail");
}
