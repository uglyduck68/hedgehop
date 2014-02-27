// Globals.H -- 
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
// $Log: Globals.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:13  ravshank
// Start of Spring 2001
//
// Revision 1.4  2000/11/28 17:26:31  phoebe
// Found what is hopefully the last of the memcpy core dumps and fixed it. Was connected with the numSegs variable (it was being set imporperly). Also restructured some of the stats to get a more accurate picture of where time is being spent. In addition, the SentStore is now doing all flushing and garbageCollecting with threads. Need to change the checkpoint to get rid of threads before saving state.
//
// Revision 1.3  2000/11/21 22:27:11  phoebe
// GarbageCollect in the SentStore is now working async. We changed the logic slightly so that all files are cleaned by one process and we clean when we've heard 3 responses (not necessarily all from different processes...this is ok we think.) Also...our favorite core dump on TakeCkpt (the memcpy one) has crept back in the picture. <grrrr>
//
// Revision 1.2  2000/09/29 00:20:10  phoebe
// Optimistic will now recover from the first failure...but not multiple sequential failures.
//
// Revision 1.1  2000/06/27 13:22:39  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.11  2000/06/26 14:55:58  phoebe
// More slight changes. Cleaned up Init.cc by moving path definitions to Egida_Globals.H. There are also some other small changes that I can't remember at the moment.
//
// Revision 1.10  2000/06/23 03:04:48  phoebe
// Changed the isInitialized data member in Egida_Object to a true boolean instead of the int that it used to be.
//
// Revision 1.9  2000/06/02 05:47:22  phoebe
// Hash and Sign of EventInfo working and it will restart and check fine. I think the modification I made to EventInfo for Reads (it's commented as a change in the code...I used << and >> instead of the commented out code) is preventing restart. Need to make sure I understand what is going on with that later.
//
// Revision 1.8  2000/06/02 04:13:11  phoebe
// Encryption of EventInfo now working.
//
// Revision 1.7  2000/06/01 23:08:44  phoebe
// Reconfigured the Egida_Object_Init.cc file under the direction of Lorenzo so that the protocol inits make sense.
//
// Revision 1.6  2000/04/28 20:08:14  phoebe
// Got Async Checkpoints to return micro-measurements.
//
// Revision 1.5  2000/04/20 20:57:56  phoebe
// Integrated Stats to track hash and sign functions.
//
// Revision 1.4  2000/04/17 16:55:04  phoebe
// Rearranged Stats functions to do both Pre and Post Init (in init.cc) and now checkpoint encryption is working. Right now have Sriram's init file for optimistic which will only run for the short programs...this time it ran to completion on cg but it will not run to completion for sp.
//
// Revision 1.3  2000/04/14 16:34:40  phoebe
// Put in more stats to track encryption/decryption times. Also modified Communication.cc to have a cleaner interface for Message encryption/decryption so it would be easier to track with Stats...meaning I added a wrapper function call. Stats::Init is being done in Egida_PostInit which means the first checkpoint is being missed.
//
// Revision 1.2  2000/03/29 15:58:39  phoebe
// Added the functionality to just encrypt Egida messages and not Application messages.
//
// Revision 1.1.1.1  2000/03/06 20:00:14  phoebe
// Sriram's original code with no modifications
//
// $Id: Globals.H,v 1.1.1.1 2001/02/12 00:00:13 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu Apr 29 23:51:45 1999
// Last Modified By: Sriram Rao
// Last Modified On: Sun Aug  8 00:50:52 1999
// Update Count    : 65
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|


#if defined(__cplusplus) && !defined(_EGIDA_GLOBALS_H)
#define _EGIDA_GLOBALS_H

#include <signal.h>

const int EGIDA_FILENAME_LEN = 256;

// defined relative to the directory in which the application process
// is running.
const char EGIDA_RESULTS_DIR[] = "Results";
const char EGIDA_CKPT_DIR[] = "CheckpointFiles";
const char EGIDA_DIST_DIR[] = "/home/ravshank/EGIDA/exp_distribution";
const char EGIDA_LOGS_DIR[] = "/export/suburbia/ravshank";
// This contains the path from which the executable is started thru mpirun.
const char EGIDA_APPL_BIN_DIR[] = "/export/suburbia/ravshank";

const int EGIDA_CKPT_FULL_MAGIC_COOKIE = 0x01234;
const int EGIDA_CKPT_INCR_MAGIC_COOKIE = 0x05678;

const int EGIDA_ACK = 1;
const int EGIDA_HELP_RECOVERY = 2;
const int EGIDA_FAILURE_ANNOUNCEMENT_MSG = 3;
const int EGIDA_COLLECT_RECOVERY_MSG = 4;
const int EGIDA_RECOVERY_REPLAY_MSG = 5;
const int EGIDA_RECOVERY_RESPONSE_BEGIN = 6;
const int EGIDA_RECOVERY_RESPONSE_END = 7;
const int EGIDA_RECOVERY_COMPLETE = 8;
const int EGIDA_STATE_RECORDED_CHECKPOINT = 9;
const int EGIDA_CHECKPOINT_MSG = 10;

const int EGIDA_GARBAGE_COLLECT_MSG = 12;
const int EGIDA_CKPT_PROTOCOL_MSG = 13;
const int EGIDA_LOG_PROTOCOL_MSG = 14;
const int EGIDA_RECOVERY_MSG = 15;
const int EGIDA_ORPHAN_DETECTION_MSG = 16;
// for collecting lost messages
const int EGIDA_COLLECT_LOST_MSG = 17;
const int EGIDA_DET_LOG_MSG = 18;
const int EGIDA_DELIVERED_LOG_MSG = 19;
const int EGIDA_SENT_LOG_MSG = 20;

// These two are needed when a leader-based protocol is used for
// collecting the messages needed for crash recovery.
const int EGIDA_RECOVERY_NOTIFICATION = 21;
const int EGIDA_RECOVERY_NOTIFICATION_END = 22;

// These two are needed for co-ordinated flushes
const int EGIDA_COORD_FLUSH_REQ = 23;
const int EGIDA_COORD_FLUSH_ACK = 24;

const int EGIDA_GET_LAST_CONTROL_MSG = 25;
const int EGIDA_RESP_LAST_CONTROL_MSG = 26;

const int EGIDA_MAX_TAG = 27;

#define EGIDA_TAG_SEND_APPLICATION_MESSAGE(x) (x + 32)
#define EGIDA_TAG_RECV_APPLICATION_MESSAGE(x) (x - 32)

// Keep 48 bytes for Egida's header
const int EGIDA_FIXED_HEADER = 48; 
const int EGIDA_FIXED_HEADER_DEST = 0;
const int EGIDA_FIXED_HEADER_SOURCE = 4;
const int EGIDA_FIXED_HEADER_SSN = 8;
const int EGIDA_FIXED_HEADER_TAG = 12;
const int EGIDA_FIXED_HEADER_CKPT_SIZE = 20;
const int EGIDA_FIXED_HEADER_CKPT_START = 24;
const int EGIDA_FIXED_HEADER_LOG_SIZE = 28;
const int EGIDA_FIXED_HEADER_LOG_START = 32;

// Messages tags for comm. with the failure detector
const int EGIDA_FAIL_DETECT_DIE_MSG = 1;
const int EGIDA_FAIL_DETECT_CKPT_FILE_MSG = 2;
const int EGIDA_FAIL_DETECT_ROLLBACK_MSG = 3;

//General Egida constants
const int EGIDA_MAX_PROCS = 16;
const int EGIDA_MAX_APPL_MSGS = 65536;

//Stack signals
const int EGIDA_TIMER_SIGNAL = SIGALRM;
const int EGIDA_ROLLBACK_SIGNAL = SIGUSR2;
const int EGIDA_READ_STACK_SIGNAL = SIGUSR2;

//Checkpoint Segment Types
const int EGIDA_OTHER_SEG = 0x0;
const int EGIDA_DATA_SEG = 0x1;
const int EGIDA_HEAP_SEG = 0x2;
const int EGIDA_STACK_SEG = 0x4;


//BELOW for Statistics------

// For EventHandler
const int EGIDA_SEND_STAT = 0;
const int EGIDA_RECV_STAT = 1;
const int EGIDA_BROADCAST_STAT = 2;
const int EGIDA_MSGS_AVAIL_STAT = 3;
const int EGIDA_LOG_DELIVERED_MSG_STAT = 4;

// For Checkpointing
const int EGIDA_CKPT_TIME_STAT = 5;
const int EGIDA_CKPT_SIZE_STAT = 6;
const int EGIDA_FULL_CKPT_STAT = 7;
const int EGIDA_INCR_CKPT_STAT = 8;
const int EGIDA_FORCED_CKPT_STAT = 9;
const int EGIDA_INDEP_CKPT_STAT = 10;

//For Log Management
const int EGIDA_LOG_FLUSH_STAT = 11;
const int EGIDA_LOG_GARBAGE_COLLECT_STAT = 12;
const int EGIDA_LOG_WRITE_STAT = 13;

//For EventInfo / Determinants
const int EGIDA_EVENT_INFO_WRITE_STAT = 14;
const int EGIDA_DET_WRITE_STAT = 15;

// For Recovery
const int EGIDA_RECOVERY_STATE_RESTORE_STAT = 16;
const int EGIDA_RECOVERY_LOG_ACQUIRE_STAT = 17;
const int EGIDA_RECOVERY_PRE_ROLL_FORWARD_STAT = 18;
const int EGIDA_RECOVERY_ROLL_FORWARD_STAT = 19;
const int EGIDA_RECOVERY_LOG_REPLAY_STAT = 20;
const int EGIDA_RECOVERY_REPLAY_DELIVER_STAT = 21;
const int EGIDA_RECOVERY_PB_PROC_STAT = 22;
const int EGIDA_RECOVERY_DETSTORE_MISS_STAT = 23;
const int EGIDA_RECOVERY_POLL_REPLAY_STAT = 24;
const int EGIDA_RECOVERY_ROLL_BACK_OVERHEAD_STAT = 25;
const int EGIDA_RECOVERY_DETLOG_RETRIEVE_STAT = 26; 
//For other Egida events
const int EGIDA_GET_PIGGYBACK_STAT = 27;
const int EGIDA_LOG_SENT_MSG_STAT = 28;
const int EGIDA_POLL_RECORD_STAT = 29;

//For Encryption
const int EGIDA_MSG_ENCRYPTION_STAT = 30;
const int EGIDA_MSG_DECRYPTION_STAT = 31;
const int EGIDA_CKPT_ENCRYPTION_STAT = 32;
const int EGIDA_CKPT_DECRYPTION_STAT = 33;
const int EGIDA_DETERMINANT_ENCRYPTION_STAT = 34;
const int EGIDA_DETERMINANT_DECRYPTION_STAT = 35;
const int EGIDA_EVENT_INFO_ENCRYPTION_STAT = 36;
const int EGIDA_EVENT_INFO_DECRYPTION_STAT = 37;

//For Hash and Sign
const int EGIDA_CKPT_HASH_STAT = 38;
const int EGIDA_CKPT_CHECK_HASH_STAT = 39;
const int EGIDA_DETERMINANT_HASH_STAT = 40;
const int EGIDA_DETERMINANT_CHECK_HASH_STAT = 41;
const int EGIDA_EVENT_INFO_HASH_STAT = 42;
const int EGIDA_EVENT_INFO_CHECK_HASH_STAT = 43;

const int SECURITY_BEGIN_STAT = 30; 
const int EGIDA_MAX_STAT = 43;

#endif




